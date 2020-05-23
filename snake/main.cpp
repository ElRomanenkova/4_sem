/*
#include <iostream>
#include <memory>
#include <cstdio>

#include "ui.h"
//#include "snake.h"
#include "control.h"

int main() {

    std::unique_ptr<Ui> v(Ui::get("tty"));
    if (!v) {
        fprintf(stderr, "Cannot init UI\n");
        return 0;
    }

    Game * g ;
    Human h(g);
    Robot s1(g), s2(g), s3(g);

    v->run(g);
}
*/
//#pragma once
#include <stdio.h>
#include <memory>

#include "ui.h"
#include "game.h"
#include "control.h"
#include "human.h"
#include "tui.h"
#include "AI.h"


int main() {
    srand(time(nullptr));

    std::unique_ptr<View> v(View::get());
    if (!v) {
        fprintf(stderr, "Cannot init View\n");
        return 0;
    }

//    View * v = View::get();
    Game * g = Game::get();

    Snake * s = new Snake();
    Human h(s);
    Snake * s2 = new Snake();
    AI ai(s2);

    g->add(s);
    g->add(s2);

    v->set_model(g);
    v->Draw();
    v->Run();
//    v->~View();

    return 0;
}