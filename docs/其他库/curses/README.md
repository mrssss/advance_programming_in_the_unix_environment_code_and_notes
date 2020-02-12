# curses
---

curses库是一个针对类UNIX系统的终端控制库。为构建text user interface（TUI）应用程序提供界面功能。
curses库为屏幕控制和操作提供了一个简单的高层接口。对用户来说，它屏蔽了终端的复杂性和多样性。
使用curses库处理时，实际上用户处理的是一个逻辑终端。

## 概述

curses库可以让程序员不用考虑使用的是什么类型的终端的情况下，直接写基于text的应用程序。

它提供了一个窗口映射到终端屏幕的抽象。每个窗口可以使用一个字符的矩阵来表示。程序员首先设置想要的窗口样式，然后再告诉curses库，让它更新屏幕。curses库会决定更新最少的必要内容到屏幕上去。

curses包包含的几个库的内容：

| 库名 | 头文件 | 描述 |
| --- | --- | --- |
| curses | curses.h | 最早的curses包只包含这一部分，主要控制屏幕的输入和输出，光标的操作，窗口的创建和操作等 |
| panel | panel.h | 类似于窗口堆栈，不同的窗口可以存放于其中，并且可以在其中进行移动 |
| menu | menu.h | 主要包括创建菜单并且与之交互的函数，主要用来接受用户的选择 |
| form | form.h | 包括创建表单以及与之进行交互的函数，主要用来接受用户数据输入 |

## 使用

0. 安装curses库`apt-get install libncurses5-dev`
1. `#include <curses.h>`
2. 编译时应加上链接语句`-lcurses`, `gcc temp.c -o temp -lcurses`
3. 常用函数：
    * initscr()：初始化curses库和tty（在开始curses编程之前，必须使用这个函数来开启curses模式）
    * endwin()：关闭curses并重置tty（curses编程时最后调用的一个函数）
    * move(y, x)：将游标移动值x，y的位置
    * getyx(win, y, x)：得到目前游标的位置
    * clear() and erase()：将整个屏幕清楚
    * echochar(ch)：显示某个字元
    * addch(ch)：在当前位置画字符ch
    * mvaddch(y, x, ch)：在（x，y）上显示某个字元，相当于move；addch
    * addstr(str)：在当前位置画字符str
    * mvaddstr(y, x, str)：在（x，y）位置上显示一串字符串，相当于move；addstr
    * printw(format, str)：类似printf，以一定的格式输出至屏幕
    * mvprintw(y, x, format, str)：在（x，y）上做printw工作；相当于move；printw
    * getch()：从键盘读取一个字元，返回的是整数值
    * getstr()：从键盘读取一串字元
    * scanw(format, &arg1, &arg2...)：如同scanf，从键盘读取一串字元
    * beep()：发出一声beeeeee声
    * box(win,ch1, ch2)：自动画方框
    * refresh()：使屏幕按照你的意图显示。比较工作屏幕和真实屏幕的差异，然后refresh通过终端驱动送出那些能使真实屏幕于工作屏幕一致的字符和控制码
    * standout()：启动standout模式（一般使屏幕发色）
    * standend()：关闭standout模式