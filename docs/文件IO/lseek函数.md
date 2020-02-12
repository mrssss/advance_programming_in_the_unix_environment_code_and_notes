# lseek函数
---

每个打开的文件都有一个与其相关联的“当前文件偏移量”。

对于文件的操作都从偏移量的位置开始。

## c语言函数原型

```c
#include <unistd.h>

off_t lseek(int filedes, off_t offset, int whence);
// 返回值：若成功，则返回新的文件偏移量；若出错，则返回-1
```

offset的含义与whence有关

whence取值：
* SEEK_SET：将该文件的偏移量设置为距文件开始处offset个字节
* SEEK_CUR：将该文件的偏移值设置为其当前值加offset，offset可为正或负
* SEEK_END：将该文件的偏移值设置为文件长度加offset，offset可为正或负