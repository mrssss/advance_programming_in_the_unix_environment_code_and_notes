# curses库I/O处理
---

## 常量定义

OK：curses函数运行成功的返回值，系统定义为0
ERR：curses函数运行发生错误的返回值，系统定义为-1
TRUE：布尔值，表示为真，系统定义为1
FALSE：布尔值，表示为假，系统定义为0

## 标准屏幕与当前屏幕
如果程序中使用了curses库，在程序初始化的时候，系统将自动产生两个默认屏幕：
* 标准屏幕：stdscr，代表终端的整个屏幕区域
* 当前屏幕：curscr

因为终端的刷新频率比较慢，curses库对终端屏幕刷新做了优化。  
在curses库中对标准屏幕的更新不会立即反映到屏幕上，  
而是必须等调用了函数refresh()或者函数wrefresh()之后，  
改变的效果才会在屏幕上真正的显示出来。

当前屏幕是能够看到的屏幕。  
如果对当前屏幕进行更改，还没调用刷新函数，  
那么标准屏幕即是当前屏幕已经进行了更新但还没调用refresh()函数  
即没有显示出来的屏幕，它仅是一个虚拟屏幕。

## 终端模式
### ECHO模式
回显模式

`curses.h`

| 函数名 | 描述 |
| --- | --- |
| int echo() | 输入字符回显（默认） |
| int noecho() | 输入字符不回显 |

### CBREAK模式
立即输入模式

`curses.h`

| 函数名 | 描述 |
| --- | --- |
| int cbreak() | 除了DELETE或者CTRL这种特殊字符，所有输入的字符都被立即读取出来 |
| int nocbreak() | 只有遇到回车才算输入完成 |

### NEWLINE模式
回车对应新行（`\n`）

| 函数名 | 描述 |
| --- | --- |
| int nl() | 回车对应新行 |
| int nonl() | 输入回车不换行 |

### keypad模式
功能键模式。功能键打开，上下左右和F1等这些功能键会被转换成curses内部定义的一些特殊键。

```c
int keypad(win, buf)
/*
 * WINDOW *win;     设置功能键模式的窗口
 * int buf;         TRUE：开启；FALSE：关闭
 */
```

### RAW模式
原始模式，与CBREAK模式类似，用户的输入会立即被接受，但是某些中断字符、转义字符以及挂起和流控制字符将不再起作用，取而代之的是产生一个相应的信号。

```c
raw()
noraw()
```

## 字符及字符串操作
### 输出操作

| 函数名 | 描述 |
| --- | --- |
| int addch(char ch) | 当前位置添加一个字符 |
| int addstr(char *str) | 当前位置添加一个字符串 |
| `int printw(fmt[, arg...])` | 与printf类似，格式化输出字符串 |

### 输入操作

| 函数名 | 描述 |
| --- | --- |
| int getch() | 从终端键盘读入一个字符 |
| int getstr(char * str) | 从终端键盘接受字符串，并且显示在指定的位置上，以`\n`结尾 |
| `int scanw(fmt[, argptr...])`| 与scanf类似，格式化读入字符串 |

### 插入操作

| 函数名 | 描述 |
| --- | --- |
| int insch(ch) | 在当前位置左边插入字符，位置不改变 |
| int insertln() | 插入一空白行 |

b       当前位置：(0, 0)  
^

插入字符a后  
ab      当前位置：(0, 0)  
^

### 删除操作

| 函数名 | 描述 |
| --- | --- |
| int delch() | 删除当前位置字符 |
| int deleteln() | 删除一行 |

## 字符属性

* A_NORMAL: 标准的显示模式
* A_BLINK：闪烁属性
* A_BOLD：加粗属性
* A_DIM：半透明属性
* A_REVERSE：反显属性
* A_STANDOUT：高亮度显示属性
* A_UNDERLINE：加下划线
* A_ALTCHARSET：可代替字符集
* COLOR_PAIR(n)：字符的背景和前景属性

| 函数名 | 描述 |
| --- | --- |
| int attron(chtype attrs) | 设置之后输出的所有属性 |
| int attrset(chtype attrs) | 设置所有属性 |
| int attroff(chtype attrs) | 关闭属性 |
| int standout() | 高亮显示 |
| int standend() | 关闭高亮 |

### 设置字符颜色属性
1. 初始化颜色：`start_color()`将终端颜色恢复到打开时候的状态，一般在`initscr()`之后就调用这个函数
2. 初始化color_pair：`init_pair(index, front_color, back_color)`
3. 设置颜色属性：`attron(COLOR_PAIR(index))`

更改颜色表属性：
`init_color(color, r, g, b)`

`init_color(COLOR_BLUE, 0, 700, 1000)`




