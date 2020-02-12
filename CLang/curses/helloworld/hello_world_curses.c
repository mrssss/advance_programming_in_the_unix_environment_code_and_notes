#include <curses.h>

int main(){
    initscr();
    box(stdscr, ACS_VLINE, ACS_HLINE);
    move(LINES/2, COLS/2);
    waddstr(stdscr, "Hello, world!");
    printw("\n");
    move(1, 1);
    printw("ACS_ULCORNER: ");
    addch(ACS_ULCORNER);
    addch('\n');

    move(2, 1);
    printw("ACS_LLCORNER: ");
    addch(ACS_LLCORNER);
    addch('\n');
    
    move(3, 1);
    printw("ACS_URCORNER: ");
    addch(ACS_URCORNER);
    addch('\n');

    move(4, 1);
    printw("ACS_LRCORNER: ");
    addch(ACS_LRCORNER);
    addch('\n');

    move(5, 1);
    printw("ACS_LTEE: ");
    addch(ACS_LTEE);
    addch('\n');

    move(6, 1);
    printw("ACS_RTEE: ");
    addch(ACS_RTEE);
    addch('\n');

    move(7, 1);
    printw("ACS_BTEE: ");
    addch(ACS_BTEE);
    addch('\n');

    move(8, 1);
    printw("ACS_TTEE: ");
    addch(ACS_TTEE);
    addch('\n');

    move(9, 1);
    printw("ACS_PLUS: ");
    addch(ACS_PLUS);
    addch('\n');

    move(10, 1);
    printw("ACS_VLINE: ");
    addch(ACS_VLINE);
    addch('\n');

    move(11, 1);
    printw("ACS_HLINE: ");
    addch(ACS_HLINE);
    addch('\n');

    move(12, 1);
    printw("ACS_S1: ");
    addch(ACS_S1);
    addch('\n');

    move(13, 1);
    printw("ACS_S9: ");
    addch(ACS_S9);
    addch('\n');

    move(14, 1);
    printw("ACS_DIAMOND: ");
    addch(ACS_DIAMOND);
    addch('\n');

    move(15, 1);
    printw("ACS_CKBOARD: ");
    addch(ACS_CKBOARD);
    addch('\n');

    move(16, 1);
    printw("ACS_DEGREE: ");
    addch(ACS_DEGREE);
    addch('\n');

    move(17, 1);
    printw("ACS_PLMINUS: ");
    addch(ACS_PLMINUS);
    addch('\n');

    move(18, 1);
    printw("ACS_BULLET: ");
    addch(ACS_BULLET);
    addch('\n');

    refresh();
    getch();
    endwin();
    printf("Exit\n");
    return 0;
}
