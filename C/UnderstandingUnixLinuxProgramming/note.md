# 第二章： who

## 使用open、read和close函数：

---


<table >
    <th colspan="3">open</th>
    <tr>
        <td>目标 &emsp;&emsp;</td>
        <td colspan="2">打开一个文件</td>
    </tr>
    <tr>
        <td>头文件</td>
        <td colspan="2">#include <fcntl.h></td>
    </tr>
    <tr>
        <td>函数原型</td>
        <td colspan="2">int fd = open(char * name, int how) </td>
    </tr>
    <tr>
        <td rowspan="2">参数</td>
        <td>name</td>
        <td>文件名</td>
    </tr>
    <tr>
        <td>how</td>
        <td>O_RDONLY, O_WRONLY, O_RDWR</td>
    </tr>
    <tr>
        <td rowspan="2">返回值</td>
        <td>-1</td>
        <td>遇到错误</td>
    </tr>
    <tr>
        <td>int</td>
        <td>成功返回</td>
    </tr>
    
</table>



<table >
    <th colspan="3">read</th>
    <tr>
        <td>目标 &emsp;&emsp;</td>
        <td colspan="2">把数据读取到缓冲区</td>
    </tr>
    <tr>
        <td>头文件</td>
        <td colspan="2">#include <unistd.h></td>
    </tr>
    <tr>
        <td>函数原型</td>
        <td colspan="2">ssize_t numread = read(int fd, void * buf, size_t qty) </td>
    </tr>
    <tr>
        <td rowspan="3">参数</td>
        <td>fd</td>
        <td>文件描述符</td>
    </tr>
    <tr>
        <td>buf</td>
        <td>用来存放数据的目的缓冲区</td>
    </tr>
    <tr>
        <td>qty</td>
        <td>要读取的字节数</td>
    </tr>
    <tr>
        <td rowspan="2">返回值</td>
        <td>-1</td>
        <td>遇到错误</td>
    </tr>
    <tr>
        <td>numread</td>
        <td>成功返回</td>
    </tr>
       
</table>


<table >
    <th colspan="3">write</th>
    <tr>
        <td>目标 &emsp;&emsp;</td>
        <td colspan="2">将内存中的数据读写入文件</td>
    </tr>
    <tr>
        <td>头文件</td>
        <td colspan="2">#include <unistd.h></td>
    </tr>
    <tr>
        <td>函数原型</td>
        <td colspan="2">ssize_t result = write(int fd, void * buf, size_t amt) </td>
    </tr>
    <tr>
        <td rowspan="3">参数</td>
        <td>fd</td>
        <td>文件描述符</td>
    </tr>
    <tr>
        <td>buf</td>
        <td>内存数据</td>
    </tr>
    <tr>
        <td>amt</td>
        <td>要写的字节数</td>
    </tr>
    <tr>
        <td rowspan="2">返回值</td>
        <td>-1</td>
        <td>遇到错误</td>
    </tr>
    <tr>
        <td>num written</td>
        <td>成功返回</td>
    </tr>
       
</table>




<table >
    <th colspan="3">close</th>
    <tr>
        <td>目标 &emsp;&emsp;</td>
        <td colspan="2">关闭一个文件</td>
    </tr>
    <tr>
        <td>头文件</td>
        <td colspan="2">#include <unistd.h></td>
    </tr>
    <tr>
        <td>函数原型</td>
        <td colspan="2">int result = close(int fd) </td>
    </tr>
    <tr>
        <td rowspan>参数</td>
        <td>fd</td>
        <td>文件描述符</td>
    </tr>
    <tr>
        <td rowspan="2">返回值</td>
        <td>-1</td>
        <td>遇到错误</td>
    </tr>
    <tr>
        <td>0</td>
        <td>成功关闭</td>
    </tr>
    
</table>

