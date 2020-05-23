#pragma once

#include <stdio.h>

#include "ui.h"
#include "game.h"

#include <termios.h>

#include <SFML/Graphics.hpp>

const int CELL_SIZE = 30;


class Gui : public View {
public:
    Gui();
    ~Gui();

    sf::RenderWindow window;
//    Keypressable * onkey_delegater;

    void snakepainter(Coord c, Dir d);
    void rabbitpainter(Coord c);

    void Draw();
    void Run();
//    void Cls();
//    void Gotoxy(int r, int c);

    void sizeofwin();
    void getkey(long time);

    void Xline(int y);
    void Yline(int x);

private:

    sf::Texture t_ground;
    sf::Texture t_bort;
    sf::Texture t_body;
    sf::Texture t_head;
    sf::Texture t_mush;
    sf::Texture t_head_l;

    sf::Sprite ground;
    sf::Sprite bort;
    sf::Sprite body;
    sf::Sprite head;
    sf::Sprite mush;
    sf::Sprite head_l;
};