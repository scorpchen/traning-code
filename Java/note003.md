##　容器类
`ArrayList<Stirng> notes = new ArrayList<String>;`
两个类型：容器的类型，元素的类型
```
// 容器可以直接用println输出：
ArrayList<String> a = new ArrayList<String>();
System.out.println(a);

// HashSet也可以：
HashSet<Sting> s = new HashSet<Stirng>();
System.out.println(s);

// 二者的区别在于：set是集合，不能有重复的元素

// 可以这样输出的原因在于，类中实现了一个函数：
public String toString(){ return ""+i; }

```
## for-each循环
```
// for-each循环：
int[] a = new int[10];
for( int k : a ){
    System.out.println(k);
}
// for-each循环针对一般数组和对象数组有所区别，无法修改一般数组本身，而可以修改对象数组本身的内容

// 可以用于类容器：
ArrayList<Stirng> a = new ArrayList<String>();
for ( String s : a ){
    System.out.println(s);
}
```

## Hash表
```
import java.util.HashMap;

public class Coin{
    private HashMap<Integer, String> coinnames = new HashMap<Integer, String>();

    public Coin(){
        coinnames.put(1, "penny");
        coinnames.put(10, "dime");
        coinnames.put(25, "quarter");
        coinnames.put(50, "half-dolar");
        coinnames.put(50, "pring"); // 同一个键只能对应一个值，当出现重复时，保留最后一个

        // 遍历：
        for ( Integer k : coinnames.keySet() ){
            String s = coinnames.get(k);
            System.out.println(s);
        }
    }

    public String getName(int amount){
        return coinnames.get(amount);
    }

    public static void main(Stirng[] args){
        // TODO 

    }
}
```