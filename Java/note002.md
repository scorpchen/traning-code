```
import java.util.Scanner;

public class note002
{
    // 定义函数
    public static boolean isPrime( int i )          // 函数头
    {                                               // 函数体
        boolean isPrime = true;
        for ( int k = 2; k < i; k++ ){
            if ( i % k == 0 ){
                isPrime = false;
                break;
            }
        }
        return isPrime;
    }
    // 函数的参数传的是值，而不是变量本身

    public static void main( String[] args )
    {
        
        Scanner in = new Scanner( System.in );
        int m = in.nextInt();
        int n = in.nextInt();
        if ( m == 1 ) m = 2;
        int cnt = 0;
        int sum = 0;
        for ( int i = m; i <= n; i++ ){
            if ( isPrime(i) ){
                cnt++;
                sum += i;
            }
        }
        System.out.println("在"+m+"和"+n+"之间有"+cnt+"个素数，总和为"+sum);
    }
}

// 成员变量初始化会默认零值
 
// 私有是针对类，而不是针对对象
// private、public用来修饰成员变量，成员函数
// 不加修饰的成员函数和成员变量属于frendly类，包内可见

// 编译单元内可有多个类，但是只能有一个public类

// 静态变量（static）可以用类的名字访问，而其他变量只能通过对象名访问
// static修饰的变量叫做类变量
// static中可以访问static的成员变量
// static只在类被装载的时候初始化，创建对象的时候不初始化

```