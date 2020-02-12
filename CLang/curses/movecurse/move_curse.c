#include <curses.h>

int main(){
    initscr();
    noecho();
    // 允许输入键盘上的功能键
    keypad(stdscr, true);
    int key;
    int y=0, x=0;
    while((key = getch()) != 'q'){
        getyx(stdscr, y, x);
        if(key==KEY_UP){
            key = 'w';
        }else if(key==KEY_LEFT){
            key = 'a';
        }else if(key==KEY_DOWN){
            key = 's';
        }else if(key==KEY_RIGHT){
            key = 'd';
        }
        switch(key){
            case 'w':
                if(y==0){
                    y = LINES-1;
                }else{
                    y--;
                }
                break;
            case 'a':
                if(x==0){
                    x = COLS-1;
                }else{
                    x--;
                }
                break;
            case 's':
                if(y==LINES-1){
                    y = 0;
                }else{
                    y++;
                }
                break;
            case 'd':
                if(x==COLS-1){
                    x = 0;
                }else{
                    x++;
                }
            break;
        }
        move(y, x);
    }
    endwin();
    return 0;
}