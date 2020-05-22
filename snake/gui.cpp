#include <stdio.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <signal.h>
#include <fstream>
#include <unistd.h>

#include "gui.h"

#include "game.h"

using namespace std::placeholders;

static void sizechange(int y) {
    View::get()->Draw();
}

void Gui::sizeofwin()
{
    sf::Vector2u size = window.getSize();
//    ioctl(1, TIOCGWINSZ, &size);
//    x = 101;
//    y = 101;
    x = size.x / CELL_SIZE;
    y = size.y / CELL_SIZE;

}


Gui::Gui() { //*******

    window.create(sf::VideoMode(1920,1080), "Snake");
    sizeofwin();

//    font.loadFromFile("fonts/CyrilicOld.TTF");
//    text.setFont(font);
//    text.setCharacterSize(40);


    t_bort.loadFromFile("./images/bort.jpg");
    bort.setTexture(t_bort);

    t_ground.loadFromFile("./images/grass.png");
    ground.setTexture(t_ground);


    t_head.loadFromFile("./images/head.png");
    head.setTexture(t_head);

    t_head_l.loadFromFile("./images/head_l.png");
    head_l.setTexture(t_head_l);

    t_body.loadFromFile("./images/body.png");
    body.setTexture(t_body);

    t_mush.loadFromFile("./images/mush.png");
    mush.setTexture(t_mush);

    t_head_h.loadFromFile("./images/HH.png");
    head_h.setTexture(t_head_h);

    t_head_l_h.loadFromFile("./images/HL.png");
    head_l_h.setTexture(t_head_l_h);

    t_body_h.loadFromFile("./images/HB.png");
    body_h.setTexture(t_body_h);

    t_head_2.loadFromFile("./images/head2.png");
    head_2.setTexture(t_head_2);

    t_head_l_2.loadFromFile("./images/head_l2.png");
    head_l_2.setTexture(t_head_l_2);

    t_body_2.loadFromFile("./images/body2.png");
    body_2.setTexture(t_body_2);
}


Gui::~Gui() {
    window.clear();
    printf("Hvatit gamat, idi botay!\n");
}


void Gui::Draw() { //**** some changes
    sizeofwin();

    window.clear();

    for(int i = 0; i < y; i++)
        for(int j = 0; j < x; j ++) {
            ground.setPosition(j * CELL_SIZE, i * CELL_SIZE);
            window.draw(ground);
        }
//    text.setFillColor(sf::Color::Black);
//    text.setString("Score : ");
//    text.setPosition(0,0);

    Xline(0);
    Xline(miny() - 1);

    Yline(0);
    Yline(minx() - 1);

    //Gotoxy(minx()/2, miny()/2);

    game->paint(std::bind(&View::snakepainter, this, _1, _2), std::bind(&View::rabbitpainter, this, _1));

    fflush(stdout);
}

void Gui::snakepainter(Coord c, Dir d) {  //*****
    switch (d) {
        case DOWN: {
            head_h.setTextureRect(sf::IntRect(0, 0, 30, 30));
            head_h.setPosition(c.first * CELL_SIZE, c.second * CELL_SIZE);
            window.draw(head_h);
//            return;
            break;
        }

        case UP: {
            head_h.setTextureRect(sf::IntRect(0, 30, 30, -30));
            head_h.setPosition(c.first * CELL_SIZE, c.second * CELL_SIZE);
            window.draw(head_h);
//            return;
            break;
        }

        case LEFT: {
            head_l_h.setTextureRect(sf::IntRect(0, 0, 30, 30));
            head_l_h.setPosition(c.first * CELL_SIZE, c.second * CELL_SIZE);
            window.draw(head_l_h);
//            return;
            break;
        }


        case RIGHT: {
            head_l_h.setTextureRect(sf::IntRect(30, 0, -30, 30));
            head_l_h.setPosition(c.first * CELL_SIZE, c.second * CELL_SIZE);
            window.draw(head_l_h);
//            return;
            break;
        }

        default: {
            body_h.setPosition(c.first * CELL_SIZE, c.second * CELL_SIZE);
            window.draw(body_h);
//            return;
            break;
        }

    }

}

void Gui::rabbitpainter(Coord c) { //*****
    mush.setPosition(c.first * CELL_SIZE, c.second * CELL_SIZE);
    window.draw(mush);
}


void Gui::Xline(int y) {

    for (int i = 0; i < minx(); i ++) {
        bort.setPosition(i * CELL_SIZE, y * CELL_SIZE);
        window.draw(bort);
        //printf("#");
    }
}

void Gui::Yline(int x) {

    for (int i = 1; i <= miny(); i ++) {
        bort.setPosition(x * CELL_SIZE, i * CELL_SIZE);
        window.draw(bort);
    }
}

void Gui::Run() {
    //printf("Hello, world. Snake\n");
    char c;
    Draw();

    struct pollfd arr;
    struct timespec start_time, finish_time, worktime;


    //int x = View::get()->x;

    while(window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                window.close();
        }

        arr.fd = 0 ;
        arr.events = POLLIN;

        clock_gettime(CLOCK_REALTIME,  &start_time);
        int n = poll(&arr, 1, (int)ontime_deligater.front().first);
        clock_gettime(CLOCK_REALTIME,  &finish_time);

        if(n == 1) {
            //printf("onkey\n");
            read(arr.fd, &c, 1);
            //Gotoxy(minx()/2, miny()/2);
            if(c == 'q')    return;

            onkey_delegater->onkey(c);
        }

        worktime.tv_sec = finish_time.tv_sec - start_time.tv_sec;
        worktime.tv_nsec = finish_time.tv_nsec - start_time.tv_nsec;
        int d = (int)(worktime.tv_sec * 1000) + (int)(worktime.tv_nsec / 1000000);
        //ontime_deligater.front().first -= d;

        //printf("time = %d\n", ontime_deligater.first);
        //int i;
        //scanf("%d", &i);


        for(int i = 0; i < ontime_deligater.size(); i ++) {
            std::pair<long, timeoutable> a = ontime_deligater.front();
            ontime_deligater.pop_front();
            a.first -= d;
            ontime_deligater.push_back(a);
        }

        for(int i = 0; i < ontime_deligater.size(); i ++) {
            std::pair<long, timeoutable> a = ontime_deligater.front();
            ontime_deligater.pop_front();

            if(a.first <= 0) {
                a.second();
            }

            else ontime_deligater.push_back(a);
        }

        //        int x, y;

        /*if(ontime_deligater.front().first == 500)
         {
         */
        Draw();
        window.display();
    }

}


int Gui::minx() {
    return x;
}


int Gui::miny() {
    return y;
}