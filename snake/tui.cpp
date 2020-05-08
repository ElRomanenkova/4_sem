#include "tui.h"

#include <cstdio>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <signal.h>

Tty::Tty() {
    //init_tty(0);
    //winch();
    setvbuf(stdout, NULL, _IONBF, 0);
}

Tty::~Tty() {
    cls();
    //fini_tty();
    setvbuf(stdout, NULL, _IOLBF, 0);
    printf("bye!\n");
}

void Tty::cls() {
    printf("\e[H\e[J\e[m");
}

void Tty::go_to_coor(int x, int y) {
    //printf("\e[%d;%dH", ws.ws_row - y, x + 1);
}

void Tty::set_color(int c) {
    printf("\e[%dm", c ? c+30 : 0);
}
