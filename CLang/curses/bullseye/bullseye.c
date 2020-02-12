#include <curses.h>
#include <stdlib.h>
#include <unistd.h>

static void finish(int sig);

int main(int argc, char ** argv){
    initscr();      // 初始化curses包
    keypad(stdscr, TRUE);       // 允许键盘映射
    (void)nonl();
    (void)cbreak();
    (void)noecho();
    // 判断是否支持彩色
    if(has_colors()){
        start_color();
        // 初始化颜色配对表
        init_pair(0, COLOR_BLACK, COLOR_BLACK);
        init_pair(1, COLOR_GREEN, COLOR_BLACK);
        init_pair(2, COLOR_RED, COLOR_BLACK);
        init_pair(3, COLOR_CYAN, COLOR_BLACK);
        init_pair(4, COLOR_WHITE, COLOR_BLACK);
        init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
        init_pair(6, COLOR_BLUE, COLOR_BLACK);
        init_pair(7, COLOR_YELLOW, COLOR_BLACK);
    }
    attron(A_BLINK|COLOR_PAIR(2));
    move(LINES/2+1, COLS-4);
    addstr("Eye");
    refresh();
    sleep(2);

    move(LINES/2-3, COLS/2-3);
    addstr("Bulls");
    refresh();
    sleep(2);

    finish(0);
}

static void finish(int sig){
    endwin();
    exit(0);
}