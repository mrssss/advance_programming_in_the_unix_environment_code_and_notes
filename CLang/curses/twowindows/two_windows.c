#include <curses.h>

int main(){
    initscr();
    WINDOW *win = newwin(LINES-1, COLS/2, 0, 0);
    box(win, ACS_HLINE, ACS_VLINE);
    refresh();
    getch();
    endwin();   
    return 0;
}