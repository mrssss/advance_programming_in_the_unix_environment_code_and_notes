#include <curses.h>

int main(){
    initscr();
    insch('a');
    insch('b');
    insch('c');
    refresh();
    getch();
    delch();
    delch();
    delch();
    refresh();
    getch();
    endwin();
}