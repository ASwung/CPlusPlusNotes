//// TemplateProgramming.cpp: 定义控制台应用程序的入口点。
////
//
#include "stdafx.h"
//#include <valarray>
//#include "studentc.h"
//using namespace std;
//
//
//// 模板函数: 
///*
//	template<模板参数列表> 函数定义  ( template<typename type> ReturnType FuncName(parameter) )
//	是一个静态绑定，在编译阶段就确定了		 一类函数的集合，只是一个函数的模型，调用时必须确定类型
//	typename: 关键字  在 模板参数列表 里使用   定义类型(自定义) 作为 函数的形参类型
//*/
//class cInt
//{
//public:
//	cInt()
//	{
//		m_value = 0;
//	}
//	cInt(int value)
//	{
//		m_value = value;
//	}
//	~cInt(){}
//	int GetValue()
//	{
//		return m_value;
//	}
//	/*template<typename W>bool operator (const cInt& obj)
//	{
//
//	}*/
//	bool operator >(const cInt& obj)
//	{
//		 return m_value > obj.m_value;
//	}
//
//	bool operator <( const cInt& obj)
//	{
//		return m_value < obj.m_value;
//	}
//	bool operator ==(const cInt& obj)
//	{
//		return this->m_value == obj.m_value;
//	}
//	int m_value;
//};
//
//
//// 普通模板
///*
//	template<typename Y,int B = 0>		对 B 指定了类型 （B 不是类型了，是 int 类型的 常量）
//	调用的方法(不能再给 B 传递类型了）:
//	   int result = compare<cInt,10>(cInt(30), cInt(20));
//	  给 B 传递一个常量，int array[B];  可以用来创建数组等等   (也可以给 B 一个默认值，调用时不传也行)
//
//		// 给模板参数  默认类型 或 默认值  如果后续还有模板参数 就一定要给到最后一个(与函数默认值一样)
//
//    template<class Y ,class B = int>   也可以用 class   与 typename 的作用是一样的
//    调用 模板参数 的方法(需要给两个类型，让编译器能识别 B  Y与B都是类型 ):
//		int result = compare<cInt,int>(cInt(30), cInt(20));
//					给 B 传递一个 具体的类型 int  也可以给一个 默认的类型
//*/
//
//// 模板参数特例化(函数)
///*
//	template<typename T> int Func(T& a,T& b){}    // 普通模板  适用于所有类型的函数参数
//	template<> int Func(int& a,int& b){}  // 模板函数特例化   
//	// 相当于把 int 类型的模板函数拿出来 单独做处理   只能对 int 类型的形参做处理

////模板函数的调用方式： Func(argument1, argument2);    // 优先调用普通函数，如没有普通函数，则调用模板函数
////					 Func<type>(argument1, argument2);  // 只能调用模板函数 （优先调用模板函数特例化）
//*/
//template<typename T>
//void Func(T a, T b)
//{
//	cout << "普通函数模板" << endl;
//}
//template<>							// 这两个函数 一起存在 才是函数模板特例化 （函数名、函数参数需一样）
//void Func(int a,int b)
//{
//	cout << "函数模板特例化" << endl;
//}
//// 函数模板实现 compare() 函数 适用于任何类型的 判断大小
//template<typename Y, class B> // 一般分两行写，Y 类型的作用域仅限于这一个函数    <> 里可以有多个参数	 
//int compare(Y& a, Y& b)
//{
//	B temp = 20;    // B 为 int 类型
//	a.m_value -= temp;
//	if (a == b)
//	{
//		return 0;
//	}
//	return a > b ? 1 : -1;
//}
////  int compare(int a,int b) 和 int compare(cInt a,cInt b) 这两个函数的实现类似
///*   因此 可以用 C++ 的模板函数 来实现 把这两个函数做成一个模型 减少代码量 并且 简洁更清晰 
//	int compare(int a, int b)
//	{
//		if (a == b)
//		{
//			return 0;
//		}
//		return a>b?1:-1
//	}
//	int compare(cInt a, cInt b)
//	{
//		if (a.GetValue() == b.GetValue())
//		{
//			return 0;
//		}
//		return a.GetValue() > b.GetValue() ? 1 : -1;
//	}
//*/
//
//
//// 模板类:   必须要把 声明 与 定义(实现) 放在同一个文件  （不能放在 .h 和 .cpp 里）
///*
//	template<模板参数列表> 类定义  ( template<typename type> class ClassName{}; )
//	是一个静态绑定，在编译阶段就确定了		 无数个类的集合，只是一个类的模型，并不是具体的 类
//	typename: 关键字  在 模板参数列表 里使用   定义类型(自定义) 作为 类里的数据成员 的类型
//	  不可以 直接对 模板类进行重命名  在模板类前加 typedef，结束加 名字，错误，因为 模板参数的类型 不确定
//*/
//// typedef   不可以直接 重命名 
//template<typename T,class D = double,typename C = char,typename B = bool,int A = 5>
//class cTest																// 类模板特例化  A为 int 的常量
//{
//public:
//	cTest() {}
//	cTest(T value)
//	{
//		m_cTestValue = value;
//	}
//	~cTest(){}
//	// 实现一个类里有 多种类型的数据成员
//	T m_cTestValue;  
//	D m_cDTestValue;
//	C m_cCTestValue;
//	B m_cBTestValue;
//// 可以在调用时 自定义 类里数据成员的类型，也就是 使用一个模板类可以 创建多个 不同数据成员类型的 类
//}/* TEST_TYPE 不可以直接重命名 */;
//
//// 对模板类重命名的两种方式:
//typedef cTest<int, double, char, bool>TEST_TYPE; // 使用 typedef 对已经确定了类型的 cTest 类重命名为 TEST_TYPE
//using TEST_INT = cTest<char>;    // 使用 using 对已经确定了类型的 cTest 类重命名为 TEST_INT
//
//
//// 模板类继承
//class cTestChild: public cTest<int>   // 普通类 继承模板类
//{
//public:
//	cTestChild(){}
//	~cTestChild(){}
//
//	int cTestChildValue;
//};
//
//template<typename V = int>		// 模板类 继承 模板类
//class cTestStudent: public cTest<int>
//{
//public:
//	cTestStudent(){}
//	~cTestStudent(){}
//
//	V cTestStudentValue;
//};
//
//// 模板类特例化
///*
//	template<typename T> class cException{};   // 普通模板类
//	template<> class cException<int>{};   // 模板类特例化  只对 int 类型的类 做操作 注: 类名必须一样
//
//	cException<float> obj1;		// 调用 普通模板类 创建obj1  因为 给定的类型为 float 类型
//	cException<int> obj2;		// 调用 模板类特例化 创建obj2  因为 给定的类型为 int 类型
//*/
//
//template<typename T>
//class cException
//{
//public:
//	cException(){}
//	~cException(){}
//	void func()
//	{
//		cout << "普通模板类" << endl;
//	}
//	T m_value;
//};
//template<>						// 这两个类 一起存在 才是模板类特例化 (类名必须一样)
//class cException<int> // 只创建 int 类型数据成员 的类  也就是 cException<int> obj2;  这样才会调用 
//{
//public:
//	cException(){}
//	~cException(){}
//	void func()
//	{
//		cout << "模板类特例化" << endl;
//	}
//	int m_value;
//};
//
//int main()
//{
//
//	//// 调用 模板函数
//	//int result = compare<cInt,int>(cInt(30), cInt(20));  // 比较 cInt 类型的值，需重载 >、<、== 操作符
//	//					// 加上类型，指明模板函数里的类型
//
//	//// 调用 模板类
//	//cTest<int> obj1;    // 使用模板类 创建了一个 数据成员为 int 类型的 cTest 类
//	//obj1.m_cTestValue = 10;   // 给 int 类型的 m_cTestValue 赋值为 10
//
//	//cTest<char> obj2('A');   // 使用模板类 创建了一个 数据成员为 char 类型的 cTest 类，并赋值其成员为 'A'
//	//char ch = obj2.m_cTestValue;   
//
//	//cTest<cInt> obj3;	// 根据模板类 创建了一个数据成员为 cInt 类型的 cTest 类 obj3
//	//obj3.m_cTestValue.m_value = 55;   // obj3.m_cTestValue 为  cInt 类型
//
//	//TEST_TYPE obj4(12);   // 使用重命名为 TEST_TYPE 类型  创建了一个 数据成员类型为 int 的值为 12
//
//	//TEST_INT obj5('S');	  // 使用重命名为 TEST_INT 类型  创建了一个 数据成员类型为 char 的值为 'S'
//
//	//cTestChild obj6;	 // 继承了模板类
//	//obj6.cTestChildValue = obj6.m_cTestValue; // 继承模板类 通过 模板类的值 进行 赋值（在构造函数进行）
//
//	//cTestStudent<> obj7;	 // 模板类 继承 模板类
//	//obj7.cTestStudentValue = obj7.m_cTestValue;  // 通过 父模板类成员 进行赋值(在构造函数进行)
//
//	//// 调用 普通模板函数 与 模板函数特例化
//	//Func(0.5, 0.5);
//	//Func(1, 2);     // 传入 int 类型的参数  自动调用 模板函数特例化
//
//	//// 调用 普通模板类 与 模板类特例化
//	//cException<char> obj8;
//	//obj8.func();
//	//cException<int> obj9;   // 传入 int 类型  自动调用 模板类特例化
//	//obj9.func();
//
//	system("pause");
//	return 0;
//}
//
