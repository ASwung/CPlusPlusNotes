// lesson3first.cpp : 定义控制台应用程序的入口点。
//
								/* C++ NOTES */ 
#include "stdafx.h"   // 标准应用程序框架的拓展 
#include<iostream>	  // C++的输入输出流，不用加 .h 
#include <stdio.h>
using namespace std;	// 使用命名空间: std  防止重名 
// 小知识：
// using 与 typedef: 
	using HONDA = int;
	typedef int honda;
	cout << "using:" << sizeof(HONDA) << "\ttypedef:" << sizeof(honda) << endl;
	// (using newtype = type)  ==  (typedef type newtype);

// auto 变量： 
	double i1 = 5.7, i2 = 6.4;
	auto i3 = i1 + i2;		// 变量 i3 的类型取决于（i1 + i2) 结果的类型
	cout << "i3 = " << i3 << "\tauto:" << sizeof(i3) << endl;

// decltype 定义变量类型： 
	int i = 5;
	decltype(i) j = 8;	// 定义了一个变量 j，使它的类型与 i 一样

// C++ 常用的类型转换方式：
	char letter = 'a';
	printf("%p\n", &letter);		// C 风格输出字符地址
	cout << static_cast<void*>(&letter) << endl;	// static_cast<TYPE>(argument) C++ 常用类型转换
	// &letter 是 char*，C++ 处理 char* 是当成字符串处理的，而 letter 是字符，没有 '\0'，所以直接取地址输出的是乱码
	
// 把字符串转换为整数：_ttoi(); 
	int num = _ttoi(argv[0]);  // _ttoi() 转换字符串为整数，但参数应是 wchar_t* 类型的 
	
// 命名空间：
namespace Aswung			// 定义了一个名为 Aswung 的命名空间。。。防止重名，使用时添加： using namespace Aswung;
{
	struct stuStudentInfo
	{
		char stuName[20];
		int Age;
		void stuPrintAge()
		{
			cout << "stuName:" << this->stuName << "\tAge = " << this->Age << endl;
		}
	};
} 
	
// 调用函数的优先级：
  // 三种调用方式：
{
	swap(a, b);   // 优先调用本文件定义的 swap()，如果本文件中没有，则调用命名空间里的
	::swap(a, b);	   // 调用本文件里的 swap()
	std::swap(a, b);  // 调用 std 命名空间中的 swap()

	Func(argument1, argument2);    // 优先调用普通函数，如没有普通函数，则调用模板函数
	Func<type>(argument1, argument2);  // 只能调用模板函数
}
	
// 引用：
void swap(int& a, int &b)	
{
	int temp = a;
	a = b;
	b = temp;
}

	int &pp = num1;     // num1 被 pp 引用； num1 == pp
	pp = num2;			// num2 又被 pp 引用； num1 == num2 == pp;
	pp = 4;				// 又改变 pp 的值； num1 == pp, num2 不变
	pp = 5;				// 再次改变 pp 的值；num1 == pp；	多次引用变量，只会改变第一个被引用的变量的值；
	
	// 引用的特点：
	// 1.引用是一个变量的别名，地址、值都与变量一样
	// 2.定义引用时必须初始化，被引用变量与引用变量类型要一致
	// 3.格式：int b = 0; int& a = b;
	// 4.与指针类似,被引用后的变量再次引用，会修改 第一个 被引用的变量的值；
	
// 常引用：
 int a = 1;
 const int &aa = a;
 // aa = 10;	 	// 因为 aa 这个引用是 常引用，所以不能通过常引用 aa 来改变 它的值 
 a = 10; 			// 想要改变它的值，只有用 被常引用 所引用的变量 来改变 

// 函数重载：
void func(int a)
{
	
}
void func(int a,int b)
{
	
} 
	// 函数重载的条件：
	// 1.函数名与函数返回类型可以一样
	// 2.函数参数个数或者函数参数类型一定要不一样  （C语言里没有函数重载） 
	    // 在 C 中编译函数时，可能会编译成：   func		  func 	所以重名 
		// 而在 C++ 中编译函数时，可能会编译成：	func_int    	func_int_int 	所以可用
		
// 函数缺省值：		 
int sum(int a=5,int b=1)	// 当调用此函数时，如果没有给参数或者给的参数不够，而又给了函数形参缺省值时，默认此参数为给定的缺省值	 
{
	return a + b;
 } 
 double sum(double a,double b)
 {
 	return a + b;
 }
 	 // 特点：
	 // 1.给全了形参的个数，则缺省值无效，否则从左至右判断，参数对应，
	 // 2.在函数形参中，给定函数缺省值时，给了前一个参数缺省值，如后面还有参数，必须也要给后面的参数缺省值 
 
// new 与 delete:
    int *p = new int;			// 申请了 一 个 int 的内存空间给 p 
	int *pp = new int[10];		// 申请了 十 个 int 的内存空间给 pp 
	delete p;			 	// 释放 1 个 int 的方式 
	delete []pp; 			// 释放 int数组 的方式 
	/* 关于动态内存分配查看内存时：
	 1.申请基础类型时(如: int、double、char、float),在分配内存的起始地址 的前 16 个字节 会记录分配的类型的个数
	 例：(起始地址)0x00fffe - 16 == 0x00ffee     也就是在 0x00ffee ~ 0x00fff1 这 4 个字节中会有 分配的类型的个数的值
	 
	 2.申请自定义类型时(如：struct、class), 在分配内存的起始地址 的前 4 个字节 会记录分配的类型的个数 
	 例：(起始地址)0x00fffe - 4 == 0x00fffa      也就是在 0x00fffa ~ 0x00fffd 这 4 个字节中会有 分配的类型的个数的值  */ 
							
// C与C++ 关于 const 的区别：
	const int a = 10;			// 常量
	int *p = (int*)(&a);	
		// 因为 const int* 类型不能用于初始化 int* 类型，所以要强制类型转换，但也不能这样：int *p = static_cast<int*>(&a);
		
	*p = 3;						// 把指向常量 a 的指针 p 重新赋值
	cout << "a=" << a << "\t*p=" << *p << endl;    
	// 重新赋值后的 a 依然没变，但指向 a 的*p改变了，这是因为 C++ 里的内存重叠机制，这里输出的 a 类似于宏替换
	
	int	b = *p;
	cout << "b=" << b << "\ta=" << a << "\t*p=" << *p << endl;  // b == *p， a 依然等于10，  如果在 C 中,a 会被改变 
	
// 以 C 语言的形式编译：
extern "C"		// 在这个作用域里都是用 C 语言的方式编译的 (这种方式在 C 中不可用) 
{
	
} 


// 单例模式：  一个类只能创建一个对象 
/* cCar* car1;
   cCar* c_p = NULL;  */
class cCar{
	cCar()
	{
		m_value = 55;
	}
				
	~cCar()		// 让构造函数与析构函数默认为 private 
	{
		
	}		
	int m_value;	
public:
	static cCar* GetInstance();		// 静态成员函数 实现单例模式
	 // (因为 非 static 成员函数访问必须要对象，而构造函数私有了，无法再外部创建对象，所以只好用 static 成员函数) 
}; 
 int main()		// 单例模式调用的方法 
 {
 //	cCar car ;    // 因为构造函数为 private，所以只能使用单例模式来创建一个对象 
 	cCar* pCar1 = cCar::GetInstance();		// 这样就可以获得一个具有 静态的 class 类对象 
 
	cCar* pCar2 = cCar::GetInstance();		// pCar1 == pCar2   因为 在 GetInstance() 函数里只会声明一次
	
	delete pCar1;
	return 0; 
 }
 cCar* cCar::GetInstance()
	{
		static cCar* pCar = new cCar;    // 只能被声明一次，而不加 static 就会被 new 多次 
		return pCar;
		// 单例模式另一种方式：
	/*	if(c_p == NULL)
		{
			c_p = new cCar;
		}
		return c_p;   */
	}

