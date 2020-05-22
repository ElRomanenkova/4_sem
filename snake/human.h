#pragma once

#include <stdio.h>
#include "control.h"
#include "keypressable.h"


class Human : public Control, public Keypressable {
public:
    Human(Snake * s);
    ~Human();
    bool onkey(char key);
//    void onkey(char key);
};