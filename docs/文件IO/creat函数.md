# creat函数
---

创建一个新的文件，如果文件存在，只读打开并截短长度为0

**注意creat没有e，不是create**

## c语言函数原型

```c
#include <fcntl.h>

int creat(const char *pathname, mode_t mode);
// 返回值，若成功则返回为只写打开的文件描述符，若出错则返回-1
```

这个函数等价于

```c
open(pathname, O_WRONLY | O_CREAT | O_TRUNC, mode);
```

## go语言函数原型

```go
package os

func Create(name string) (file *File, err error)
```

Create采用模式0666（任何人都可读写，不可执行）创建一个名为name的文件，如果文件已存在会截断它（为空文件）。如果成功，返回的文件对象可用于I/O；对应的文件描述符具有O_RDWR模式。如果出错，错误底层类型是*PathError。

如果不想使用默认的模式，可以使用os.OpenFile