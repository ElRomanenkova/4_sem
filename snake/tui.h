#include <termios.h>
#include <vector>
#include <sys/ioctl.h>

#include "ui.h"

class Tty : public Ui {
public:
    Tty();
    ~Tty();

    void run();

    //void run(Game&);
    //void quit();

    int winx() const { return coor_x; }
    int winy() const { return coor_y; }

    //void set_on_key(event_fn fn); // already realised?...
    //void set_on_timer(int t, timer_fn fn);  // already realised?...

    void snake_painter(const Coord& s, const Dir& d); //const Segment&
    void rabbit_painter(const Coord&);  //const Rabbit&
    void game_painter(int brand, int score);

    void draw();
//private:
    void cls();

    void putc(int x, int y, char c);

    void hline(int x, int y, int len); // horizontal line
    void vline(int x, int y, int len); // vertical line

    void set_color(int color);
    void go_to_coor(int x, int y); //
    //bool read_event(); // read key
//  terminal
    //void init_tty(int echo);
    //void fini_tty();
    void winch(); //window change
    //static void handler(int a = 0);
private:
    bool running;
    struct termios ttys;
    struct winsize ws;
    //Game* game;

    //std::vector<event_fn> events;
    //std::vector<std::pair<int, timer_fn>> timers;
};
