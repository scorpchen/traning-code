```
import java.util.Scanner;

public class note001
{
    public static main( String[] args )
    {
        // 输出
        System.out.println("print");

        // 输入

        Scanner in = new Scanner( system.in );

        // 定义常量
        final int amount = 100;

        // 两个整数除法依旧是整数

        // 数据类型：int， double

        // 优先级：正常

        // 强制类型转换：（int）4.6     和c一样

        // 注释同c

        // 关系运算同c，关键字 true，false

        // 整数和浮点数可以比较相等，浮点数之间比较相等： abs(a - b) < 0.0000001

        // for循环
        for (int i = 0; i < 100; i++){
            ;
        }

        // 创建数组，数组大小固定，默认零值
        // <类型>[]<名称> = new <类型>[大小]
        int[] numbers = new int[100];
        numbers[0] = 8;

        // 数组初始化
        int[] scores = {1, 2, 3, 4, 5, 6};
        // 数组长度
        System.out.println(scores.length);
        // 遍历数组
        for ( int i = 0; i < scores.length; i++ ){
            ;
        }
        // 枚举
        for ( int i: scores ){
            ;
        }

        // 数组变量只是一个引用或指针，本身不保存指针
        // 数组赋值
        int[] a = {1, 2, 3, 4, 5};
        int[] b = a;
        // 赋值后，b和a所指向的数组是同一个，a == b 为 true
        int[] c = {1, 2, 3, 4, 5};
        // 此时，c == a 为false
        //因此拷贝数组只能遍历一个一个的赋值

        // 二维数组
        int[][] a = new int[3][5];
        // 遍历
        for ( int i = 0; i < a.length; i++ ){
            for ( int j = 0; j < a[i].length; j++ ){
                ;
            }
        }
        // 初始化
        int[][] a = {
            {1, 2, 3, 4},
            {5, 6, 7}
        };

        // 字符类型
        // Java使用Unicode编码
        char c = 'a';
        char ch = '汉';
        System.out.println(ch);
        System.out.println('D' - 'A');
        System.out.println((int)'A');
        System.out.println('\u0041');

        // 逃逸字符（转义字符）
        // 包裹类型，每种基础类型都有对应的包裹类型
        // 基础类型 --  包裹类型
        // boolean  --  Boolean
        // char     --  Character
        // int      --  Integer
        // double   --  Double
        // 包裹类型可以得到类型信息，如：Integer.Max_Value
        // . 运算符
        // Character.isDigit('9') 为 true

        // math类
        Math.abs(-12);   // 求绝对值
        Math.round(10.645);  // 四舍五入
        Math.random();  // 0到1间随机数
        Math.pow(2, 3.5);   // 求幂

        // 字符串变量
        String s = new String("a string");
        // String 是一个类，String的变量是对象的管理者（指针或引用）而非所有者
        // 初始化
        String s = "hello";
        // 字符串可用 ' + ' 连接，当连接的一个是字符串另一个不是时，强制将另一个变成字符串
        // 输入字符串
        in.next(); // 读入一个单词，空格分隔
        in.nextLine(); // 读入一整行，回车分隔
        // 用 ' == ' 比较两个字符串时，比较的是两个字符串变量是否指向了同一个字符串
        // 比较两个字符串的内容：
        String input = reader.getInput();
        if ( input.equals("bye")){
            ;
        }
        // 比较两个字符串的大小：
        System.out.println("abc".compareTo("abd"));
        // 获得String的常数
        String name = "Hellola";
        name.length();  // 值为7
        // 访问String里的字符
        name.charAt(2); // 值为'l'
        // 遍历字符串的每一个字符
        for ( int i = 0; i < name.length(); i++ )
        {
            System.out.println(name.charAt(i));
        }

        // 子串
        name.substring(2);  // 值为"llola"
        name.substring(2, 4);   // 值为"ll"

        // 查找字符
        name.indexOf('o');  // 值为4
        name.indexOf("ola");    // 值为4
        name.indexOf('l', 4);   // 从第4号开始找'l', 值为5

        // 一些常用操作，一下所有函数所作的修改不会修改字符串本身
        String s = "string";
        s.startsWith(t);    // 返回是否以t开头
        s.endsWith(t);      // 返回是否以t结尾
        s.trim();           // 删掉首位空格
        s.replace(c1, c2);  // 将c1换成c2
        s.toLowerCase();    // 将所有大写换成小写
        s.toUpperCase();    // 将所有小写换成大写
    }
}
```