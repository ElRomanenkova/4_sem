#include <cstring>

#include "ui.h"
#include "tui.h"
#include "keypressable.h"
#include "game.h"
#include "gui.h"

View * View::inst;

View * View::get() {
//    if (!instance) {
//        if (strcmp(what, "tty") == 0)
//            instance = new Tty();
//        //if (strcmp(what, "sdl") == 0)
//        //instance = new Sdl();
//    }
//    return instance;

    if(inst != nullptr)    return inst;

    inst = new Gui;
    return inst;
}

View::~View() {
//    instance = nullptr;
//    delete[instance];
}