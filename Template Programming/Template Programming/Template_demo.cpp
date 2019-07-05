// Template_demo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>

using namespace std;

/*
//交换两个整数变量的值
void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

//我们想交换两个字符串的值？
void swap(string& s1, string& s2)
{
    string ss = s1;
    s1 = s2;
    s2 = ss;
}
*/

//交换两个double变量？ 交换两个其他对象？...
//每个都实现一个交换函数？ --- 这些交换函数，实现的方式都是一样的
//----》 低效

//---》 使用模板来实现这个函数
template<typename T>  //声明下面的函数，是一个模板函数， T 是我们待定类型
                      //T 成为模板参数
        //有些比较老的教材，写的是 template<class T> ....
        //不建议大家使用class 的方式：typename 是新标准，class 在模板定义时候，有特定的用法
void swap(T &a, T &b)
{
    //写法和上面一样，只是变量类型使用 T 来替换
    // --> T 是一个待定的数据类型
    // --> 调用的时候，入参是什么类型，则自动生成一个对应类型的函数，给我们调用
    cout << "MySwap ..." << endl;
    T tmp = a;
    a = b;
    b = tmp;
}

//如果，我们待定的入参类型有多个，我们可以使用多个T
template <typename T1, typename T2>
void PrintKeyValue(T1 &key, T2 &value)
{
    cout << "K-V: " << key << " -> " << value << endl;
}



class AAA{
private:
    int x;
    int y;
public:
    AAA() :x(0), y(0){}
    AAA(int a, int b) :x(a), y(b){}
    friend ostream& operator << (ostream& os, const AAA &A)
    {
        os << "(" << A.x << "," << A.y << ")";

        return os;
    }
};

void TestTemplate()
{
    int a = 10;
    int b = 20;

    //“std::swap”: 对重载函数的调用不明确	
    // std 这个命名空间中，也定义了 swap 函数，而且我们已经使用了std 这个命名空间
    // --》调用 swap 产生了歧义：两个swap，不知道调用哪一个
    // --> 怎么解决？
    //    --> 声明作用域！！！
    //       --> 使用 std 里面的swap    --》 std::swap
    //       --> 使用 文件中定义的swap  --》 ::swap
    std::swap(a, b);
    cout << "(a, b) = (" << a << "," << b << ")" << endl << endl;

    ::swap(a, b); //调用自己定义的swap
    cout << "(a, b) = (" << a << "," << b << ")" << endl << endl;

    string s1("ABCD");
    string s2("1234");
    ::swap<string>(s1, s2); //可以显示指定 string 类型，也可以省略
    cout << "(s1,s2) = (" << s1 << "," << s2 << ")" << endl << endl;

    AAA A1;
    AAA A2(1, 2);
    ::swap(A1, A2);
    //cout << A1;  --> cout 对于运算符重载函数(<<) 里面的 os参数, A1 对应这个函数的 A参数
    cout << "A1:" << A1 << endl;
    cout << "A2:" << A2 << endl << endl;

    //这里 这个 swap 我们称之为 模板函数 (函数模板)
    //--》模板函数不是一个正常的函数，无法生成 .o 文件
    //    一个正常函数，占用多大空间，是确定的
    // --》我们调用模板函数的时候 ---》 根据入参类型匹配，自动生成一个对于的具体函数
    //     调用具体函数来处理我们的数据
}

//对于类，同样的，我们也可以写成模板的形式 (内部的变量类型待定)
template <typename T1, typename T2>
class BBB
{
private:
    T1 x;
    T2 y;
public:
    BBB(T1 a, T2 b) :x(a), y(b){  }

    //重载 输出运算符 << 
    //调用 << 的对象是 os 对象，它需要访问 BBB 的私有成员
    // --》 所以，这里需要使用 friend
    friend ostream& operator << (ostream &os, const BBB B)
    {
        os << "Class 0:";
        os << "(" << B.x << "," << B.y << ")";
        return os;
    }
};

void TestBBB()
{
    //error C2955: “BBB”: 使用 类 模板 需要 模板 参数列表
    //这里不能使用 BBB 来生成对象
    //  为什么？ --》BBB 是一个类模板，不是具体的类， 不能够生成对象
    //  --> 需要使用模板参数列表，生成一个具体类
    //     --》模板函数调用前，入参类型是已知的，程序会自动推导，生成函数(可以省略模板参数)
    //     --》模板类 生成对象的时候，如果，不指定具体类，程序不知到要调用哪个构造函数
    //BBB<int, int>   -->指定参数列表 template<typename T1, typename T2> 里面
    //                   T1 是 int， T2 也是 int
    // ---》 这里 BBB<int, int> 就是一个具体的类 （通过模板类来生成的）
    //       通过指定 模板参数 --》生成一个具体类
    //我们可以随意的指定 T1,T2 具体是什么参数类型，
    //   指定不同的参数类型，就会生成不同的 具体类
    BBB<int, int>    B1(1, 2);     //使用 BBB<int, int> 类，构造 B1对象
    BBB<int, string> B2(3, "ABC");

    //这里 B1, B2 的变量类型是不一样的！！！！！！！！！
    cout << "B1:" << B1 << endl;
    cout << "B2:" << B2 << endl;

}


template <typename T>
const T& Max(const T& a, const T& b)
{
    return a > b ? a : b;
}

template<>  //声明这是一个模板函数  
            //--》称之为 偏特化： 模板函数的特殊情况特殊处理
            //-->调用模板函数的时候，优先调用更加匹配的函数
const string& Max(const string& a, const string& b)
{
    return a.length() > b.length() ? a : b;
}

void TestMax()
{
    //error C2440: “return”: 无法从“const int”转换为“int &”
    //调用Max(10,20)的时候，入参赋值  const int& a = 10, const int& b = 10
    //   -->引用是不能直接赋值的  (只能用变量进行赋值[别名])
    //cout << "Max(10, 20): "<< Max(10, 20) << endl;
    int x = 10;
    int y = 20;
    cout << "Max(10, 20): " << Max(x, y) << endl;

    double d1 = 1.1;
    double d2 = 1.2;
    cout << "Max(1.1, 1.2): " << Max(d1, d2) << endl;

    string s1 = "ABCD";
    string s2 = "Abc";
    cout << "Max(\"ABCD\", \"Abc\"): " << Max(s1, s2) << endl;

    //--> 字符串比较大小：逐个字符比较 ASCII 码，遇到第一对不相等的字符
    //    返回这一对字符的比较结果 （也叫字典比较）
    
    //新的问题：如果我们比较字符串的时候，想 对长度进行比较 ？
    //           Max(s1, s2)  返回 长的字符串
    //---》 使用函数的偏特化，特殊的模板参数特殊处理
}

//同样的，我们也可以对模板类进行偏特化. 比如 CCC, 有两个模板参数 T1，T2
template <typename T1, typename T2>
class CCC
{
private:
    T1 x;
    T2 y;
public:
    CCC(T1 a, T2 b) :x(a), y(b){}

    //重载 输出运算符 << 
    //调用 << 的对象是 os 对象，它需要访问 BBB 的私有成员
    // --》 所以，这里需要使用 friend
    friend ostream& operator << (ostream &os, const CCC C)
    {
        os << "Class 0-";
        os << "(" << C.x << "," << C.y << ")";
        return os;
    }
};

//偏特化1： 第二个模板参数是 int 的情况
//          只能从后面开始，类似于定义 函数入参的默认值
template<typename T>
class CCC<T, int>       //声明偏特化的类型 : 声明偏特化的时候，把偏特化的那个类型，放到 <> 后面部分
{
private:
    T     x;
    int   y;
public:
    CCC(T a, int b) :x(a), y(b){}
    friend ostream& operator << (ostream &os, const CCC &C)
    {
        os << "Class 1-";
        os << "(" << C.x << ", " << C.y << ")";
        return os;
    }
};

//偏特化2：两个模板参数，参数类型一样
template<typename T>
class CCC<T, T>   // <T, T> 声明这个特化，两个T类型一样
{
private:
    T x;
    T y;
public:
    CCC(T a, T b) :x(a), y(b){}
    friend ostream& operator << (ostream &os, const CCC &C)
    {
        os << "Class 2-";
        os << "(" << C.x << ", " << C.y << ")";
        return os;
    }
};

//偏特化3：更加具体的偏特化--两个 模板类型都是 int
template<>
class CCC<int, int>
{
private:
    int x;
    int y;
public:
    CCC(int a, int b) :x(a), y(b){}
    friend ostream& operator << (ostream &os, const CCC &C)
    {
        os << "Class 3-";
        os << "(" << C.x << ", " << C.y << ")";
        return os;
    }
};

void TestSpecial()
{
    CCC<int, string>     C1(123, "ABC"); //没有偏特化
    CCC<string, int>     C2("Hello", 12);  //第二个是 int 的偏特化
    CCC<double, double>  C3(1.1, 2.2);        //两个类型一样的偏特化
    CCC<string, string>  C4("Hello", "World"); //两个类型一样的偏特化

    //error C2752 : “CCC<int, int>” : 多个部分专用化与模板参数列表匹配
    CCC<int, int>        C5(1, 2); //既匹配 CCC<T,int> 也匹配 CCC<T,T>
                                   //有歧义，编译器无法区分
    //--->解决办法，定义一个更加具体的 偏特化 CCC<int, int>
    // 偏特化的优先级：越具体的，优先级越高
 
    cout << "C1:" << C1 << endl;
    cout << "C2:" << C2 << endl;
    cout << "C3:" << C3 << endl;
    cout << "C4:" << C4 << endl;
    cout << "C5:" << C5 << endl;

}

int _tmain(int argc, _TCHAR* argv[])
{
    //TestTemplate();

    //TestBBB();

    //TestMax();

    TestSpecial();

    system("pause");
	return 0;
}

