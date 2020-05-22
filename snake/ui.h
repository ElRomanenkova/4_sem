/*
//#ifndef SNAKE_UI_H
//#define SNAKE_UI_H
#pragma once

#include "game.h"

//#include "AI.h"

#include <poll.h>
#include <time.h>

using timeontable = std::function<void()>;

class AI {};

class Ui {  //interface class
public:
    //using event_fn = std::function<void(int)>;
    //using timer_fn = std::function<void(void)>;

    enum {
        KEY_UP = 1000,
        KEY_DOWN,
        KEY_RIGHT,
        KEY_LEFT,
    };

    virtual ~Ui() = 0;

    std::list <std::pair < long, timeontable>> ontime_deligater;
    static Ui * get(const char * item = NULL);

    virtual void run() = 0;

    virtual int winx() const = 0;
    virtual int winy() const = 0;

    Key * onkey_delegater;
    AI * AI_deligater;

    void setonAI(AI * ai) {
        AI_deligater = ai;
    }

    void set_on_key(Key* key) {
        onkey_delegater = key;
    }

    void set_on_timer(struct timespec timeout, timeontable t) {
        std::pair <long , timeontable> n;

        n.first = timeout.tv_nsec / 1000000 + timeout.tv_sec * 1000;
        n.second = t;

        //if(ontime_deligater.front().first >= n.first) ontime_deligater.push_front(n);
        ontime_deligater.push_back(n);
    }

    virtual void snake_painter(const Coord& s, const Dir& d) = 0;
    virtual void rabbit_painter(const Coord&) = 0;
    virtual void game_painter(int, int) = 0;

    virtual void draw() = 0;

    virtual void winch() = 0;

    Game* game;

    void set_model(Game* g) {
        game = g;
    }

protected:
    Ui() = default;
    int x;
    int y;

private:
    static Ui* instance;
};

//#endif //SNAKE_UI_H
*/
#pragma once

#include "keypressable.h"
#include "game.h"
#include "AI.h"

#include <poll.h>
#include <time.h>
#include <functional>

using timeoutable = std::function<void()>;

//class AI {};

class View {
public:
    Keypressable * onkey_delegater;
    std::list <std::pair < long, timeoutable>> ontime_deligater;
    AI * AI_deligater;

    Game * game;

    static View * inst;

    static View * get();

    virtual void snakepainter(Coord c, Dir d) = 0;
    virtual void rabbitpainter(Coord c) = 0;

    void setonkey(Keypressable * key)
    {
        onkey_delegater = key;
    }

    void setontimer(struct timespec timeout, timeoutable t)
    {
        std::pair <long , timeoutable> n;

        n.first = timeout.tv_nsec / 1000000 + timeout.tv_sec * 1000;
        n.second = t;

        //if(ontime_deligater.front().first >= n.first) ontime_deligater.push_front(n);
        ontime_deligater.push_back(n);
    }

    void setonAI(AI * ai)
    {
        AI_deligater = ai;
    }

    void set_model(Game * g) {
        game = g;
    }

    void virtual Draw() = 0;
    void virtual Run() = 0;

    virtual ~View() = 0;

    int x, y;
};