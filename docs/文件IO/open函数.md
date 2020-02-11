# open函数
---

打开文件

## c语言函数原型

```c
#include <fcntl.h>

int open(const char *pathname, int oflag, ... /* mode_t mode */);   
// 返回值：若成功则返回文件描述符；若出错则返回-1
```

* pathname: 要打开或创建文件的名字
* oflag：函数的多个选项,多个常量可以使用或操作构成这个参数
    * O_RDONLY：只读打开
    * O_WRONLY：只写打开
    * RDWR：读、写打开
    * O_APPEND：每次写时都追加到文件的尾端
    * O_CREAT：若此文件不存在，则创建它。使用此选项时，需要第三个参数mode，用其指定该新文件的访问权限位
    * O_EXCL：如果同时指定了O_CREAT，而文件已经存在，则会出错。用此可以测试一个文件是否存在；如果不存在，则创建此文件
    * O_TRUNC：如果文件存在，而且为只写或读写成功打开，则将其长度截短为0
    * O_NOCTTY：如果pathname指的是终端设备，则不将该设备分配作为此进程的控制终端
    * O_NONBLOCK：如果pathname指的是一个FIFO、一个块特殊文件或一个字符特殊文件，则此选项为文件的本次打开操作和后续的I/O操作设置为非阻塞模式
    * O_DSYNC：使每次write等待物理I/O操作完成，但是如果写操作并不影响读取刚写入的数据，则不等待文件属性被更新
    * O_RSYNC：使每一个以文件描述符作为参数的read操作等待，直至任何对文件同一部分进行的未决写操作都完成
    * O_SYNC：使每次write都等到物理I/O操作完成，包括由write操作引起的文件属性更新所需的I/O



## go语言函数原型

```go
package os

func Open(name string) (file *File, err error)

func OpenFile(name string, flag int, perm FileMode) (file *File, err error)
```

go语言是一个面向对象的语言，所以对Open的返回结果进行了封装，不是使用文件描述符，而是直接返回一个文件对象。对文件的操作可以用这个文件对象的方法来进行。

如果想要获取文件对象的文件描述符可以用下面这个方法：

```go
package os

func (f *File) Fd() uintptr
// Fd返回与文件f对应的整数类型的Unix文件描述符。
```

Open打开一个文件用于读取。如果操作成功，返回的文件对象的方法可用于读取数据；对应的文件描述符具有O_RDONLY模式。如果出错，错误底层类型是*PathError。

OpenFile是一个更一般性的文件打开函数，大多数调用者都应用Open或Create代替本函数。它会使用指定的选项（如O_RDONLY等）、指定的模式（如0666等）打开指定名称的文件。如果操作成功，返回的文件对象可用于I/O。如果出错，错误底层类型是*PathError。

