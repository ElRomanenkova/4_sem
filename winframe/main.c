#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <signal.h>

struct winsize argp;

void draw(int row, int col) {
    //move to the next line, clear the winspace
    printf("\ec");

    //draw top line
    for (int i = 1; i <= col; i++) {
        printf("\e[1;%dHX", i);
    }
    //draw left line
    for (int i = 2; i <= row; i++) {
        printf("\e[%d;1HX", i);
    }
    //draw right line
    for (int i = 2; i <= row; i++) {
        printf("\e[%d;%dHX", i, col);
    }
    //draw bottom line
    for (int i = 1; i <= col; i++) {
        printf("\e[%d;%dHX", row, i);
    }

    printf("\e[1m\e[%d;%dH\e[37mE\e[37mT\e[37mE\e[37mR\e[37mN\e[37mA\e[37mL "
           "\e[31mY\e[33mO\e[32mU\e[36mT\e[34mH\e[35m!", row/2+1, col/2-6);

    //move to the right bottom corner
    printf("\e[%d;%dH", row, col);
    fflush(stdout);
}

void handler() {
    ioctl(0, TIOCGWINSZ, &argp);
    draw(argp.ws_row, argp.ws_col);
}

void term_handler() {
    printf("\ec");
    exit(0);
}

int main() {
    signal(SIGWINCH, handler);
    signal(SIGINT, term_handler);

    ioctl(0, TIOCGWINSZ, &argp);
    draw(argp.ws_row, argp.ws_col);

    while(1);
}