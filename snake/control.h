#pragma once

#include <stdio.h>
#include "game.h"

class Snake;

class Control {
public:
    Control(Snake * s);
    ~Control();

    Snake * snake;
};
