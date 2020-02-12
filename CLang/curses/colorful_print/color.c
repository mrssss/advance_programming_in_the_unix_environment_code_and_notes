#include <curses.h>

int main(){
    initscr();
    printw("non attr\n");
    attron(A_BLINK);
    printw("blink\n");
    attrset(0);
    attron(A_BOLD);
    printw("bold\n");
    attrset(0);
    attron(A_DIM);
    printw("dim\n");
    attrset(0);
    attron(A_REVERSE);
    printw("reverse\n");
    attrset(0);
    attron(A_UNDERLINE);
    printw("underline\n");
    attrset(0);

    start_color();
    init_pair(1, 4, 0);
    init_pair(2, 6, 0);
    attron(COLOR_PAIR(1));
    printw("color 1, 4, 3\n");
    attrset(0);
    attron(COLOR_PAIR(2));
    printw("color 2, 6, 5\n");
    attrset(0);
    standout();
    printw("standout\n");
    getch();
    endwin();
}