// OperatorOverloading.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "cArrayInt.h"
using namespace std;
// 操作符重载: 关键字(operator)  自定义 自定义类型(类) 的操作符
/*
	1.重载后的运算符必须至少有一个操作数是 自定义的类型（防止用户为标准类型重载运算符）
	2.不能违反运算符原来的句法规则，以及不能改变优先级
	3.不能创建新的运算符
	4.( sizeof\.\.*\::\?:\typeid\const_cast\dynamic_cast\reinterpret_cast\static_cast )  这些运算符不能被重载
	5.( =\()\[]\-> ) 这些运算符只能通过 成员函数 来重载
*/

// 友元函数: 关键字（friend）
/*
	1.只能声明在类里，但不属于类，被调用时不能用对象来调用(没有 this 指针)
	2.可以访问类的 私有以及保护 成员  (访问类内部成员时，不能直接访问，只能通过参数的对象 来访问)
	3.实现了外部函数对类中数据的共享
	4.破坏了 C++ 封装的特性(属于类的拓展)

	声明时加上 friend 关键字  定义不需要加 也不需要加 类:: 限定符 因为它不属于类
	用处: 如果要为类重载运算符，并且 第一个操作符是非类的类型，可以使用友元函数来反向重载操作符
	（第一个操作数为 类的类型，用成员函数方式 实现   第一个参数为 非类类型，用非成员函数方式 实现   因此 两种调用方式都可使用）
*/

 // 友元类:  类是类的朋友 
/*
	1.一个类是另一个类的友元，那么这个类就可以访问另一个类中的 私有与保护 成员
*/

// 内联函数: 关键字( inline ) 不调用函数，与宏类似  直接替换代码 (提升效率)
/*
	1.内联函数 是一种请求，特定情况下(代码复杂、有循环、递归、switch) 编译器不会把它当成内联函数
	2.写上 inline 也不一定是 内联函数  
	3.防止代码膨胀
    4.用在 操作比较频繁、代码简单 这类的函数
	5.定义写在类声明里 的成员函数 其实就是内联函数
*/

// 转换构造函数：可以通过一个参数来构造一个对象，从 其他类型 转换到 本类型
// 隐式构造函数转换: 给操作符重载函数里的形参定义成 const 的引用类型 或者 const 的对象
// 显示构造函数转换: 在转换构造函数前加上 explicit 关键字，传递形参给操作符重载函数时，
//					cInt(value) 这样的形式传递，使它能真正的构造一个对象
// 转换函数: 通过本类型 转换到 其它类型
// 强制转换: 内存拷贝

// 成员函数中操作符重载，第一个操作数 是对象的引用

// 友元函数用于操作符重载的作用: 第一个操作数不是自定义的类型， 加 const 的引用
// 不能实现 = 操作符 友元函数 重载

// 本类型转换成其它类型，转换函数: operator int()  不只限于内置类型  operator cTest()
/***************************************************************************************************
不需要改变左值以及或换操作数这些情况，一般用友元函数实现
允许编译器在参数不匹配的情况下，进行隐式转换第一个参数
***************************************************************************************************/
class cTest;   // 预声明，在 cInt 类里声明友元类时，让编译器知道 cTest 是一个类
class cInt
{
public:
	cInt() {}
    cInt(int value)	  // 隐式转换构造函数 (只能用于只有一个参数的时候，有两个参数时，给第二个参数提供默认值 也可以进行转换)
	{
		this->m_Value = value;
	}
/*
	explicit cInt(int value)     // 显示转换构造函数
	{
		this->m_value = value;
	}

	定义成显式转换构造函数后，就不能 cInt obj; obj = 55; 这样去构造一个对象了 这属于隐式转换，
	而声明成 explicit 后就关闭了隐式转换  应该这样: cInt obj;  obj = cInt(55);  相当于 obj = (cInt)55;  显式转换就是强制转换
	定义成 显式转换的构造函数后 必须强制转换（ cInt(value)、(cInt)value ）才能做的操作是:
	1. 将内置类型值 赋给 类对象
	2. 将内置类型值 传递给 接收类类型的函数参数
	3. 函数返回值值类型为 类类型 但需要 返回内置类型时
*/
	/*cInt(cInt& obj)    // 复制构造函数
	{
		cInt* pTemp = new cInt;
		memcpy(pTemp, &obj, sizeof(cInt) * 1);
	}*/
	~cInt() {}
	/*
		运算符重载的使用方式：
		1.带参数：  则运算符用于 连接 调用者 和 参数
		2.不带参数: 则运算符放在调用者的 前面
	*/
	// + 运算-------------------------------------------------------------------------------------------
/*
	cInt operator +(cInt& obj)
	{
		return cInt(this->m_Value + obj.m_Value);
	}
*/
	 // 友元函数  实现 + 运算的操作符重载 (与上面的 + 运算是一样的，但同时写出来，调用时会自动调用上面的)
	friend cInt operator +(const cInt& obj1, const cInt& obj2)   // 对象 + 对象  int + 对象   对象 + int 
	{  // 友元函数实现操作符重载  
	
	/*				注: 
		不能返回引用类型，因为返回的是 两个类数据成员相加后的结果的类 C++ 机制会自动创建一个临时变量类
		来保存他们计算后的结果，临时变量的引用 不可采取，所以 直接返回 类(会自动构造一个临时的，然后析构)
		准确的来说 他们是没有 this 指针  不是通过对象来调用的，所以参数也应该是 两个操作数都要写上

		使用友元函数重载操作符，能实现 内置类型与自定义类型 的运算，在形参为 引用的对象时，需要加上 const
		才能 让内置类型 通过转换构造函数 自动转换成 自定义类型，实现运算， 形参为 对象而不是对象的引用 不需
		加 const 也能实现 内置类型 转换成 自定义类型，做成友元函数的目的是，使两个操作数都能加上 const，
		适用于 左、右操作数 需要转换 自定义类型的情况 
	*/
		return (cInt)(obj1.m_Value + obj2.m_Value);  // 这里与 隐式的 operator typeName() 有二义性
	}

	// - 运算 （一元）----------------------------------------------------------------------
	cInt operator -()const       // -obj;
	{
		return cInt(-m_Value);
	}
	// 友元函数实现 - 运算符(一元)
/*
	friend cInt operator -(cInt &obj)
	{
		return cInt(-obj.m_Value);
	}
*/

	// - 运算 （二元） -----------------------------------------------------------------------------
/*
	cInt operator -(cInt &obj)const   // 对象 - 对象
	{
		return cInt(m_Value - obj.m_Value);
	}
	cInt operator -(int n)const		  // 对象 - int 
	{
		return cInt(m_Value - n);
	}
	friend cInt operator -(int n, cInt &obj)	// int - 对象
	{
		return -(obj - n);    // 调用 上面的 operator -(int n)const   实用
	}

	这些 能被 友元函数重载的 - 操作符 所取代  因为 带有 const 引用的形参 的友元函数 能自动将内置类型 转化为 自定义类型
	所以只需重载 下面一种能取代 上面的这三种情况:  对象 - 对象    对象 - int    int - 对象
	但如程序需要经常将 内置类型 转换为 自定义类型 使用上面的 能显示转换的 函数更适合  执行速度快一点
	注:   这些重载的 函数 能与 下面的友元函数重载的 - 操作符 函数  能同时存在   并且在运行时 会默认调用 上面的
*/
	friend cInt operator -(const cInt& obj1, const cInt& obj2)
	{
		return cInt(obj1.m_Value - obj2.m_Value);  // 这里与 隐式的 operator typeName() 有二义性
	}

	// * 运算 -----------------------------------------------------------------------------------------------------
	friend cInt operator *(const cInt& obj1, const cInt& obj2)
	{
		return cInt(obj1.m_Value*obj2.m_Value);
	}

	// / 运算 -------------------------------------------------------------------------------------------------------
	friend cInt operator /(const cInt& obj1, const cInt& obj2)
	{
		if (obj1.m_Value == 0 || obj2.m_Value == 0)   // 分子、分母 都不能为 0
		{
			return cInt(0);
		}
		return cInt(obj1.m_Value / obj2.m_Value);
	}

	// % 运算 --------------------------------------------------------------------------------------------------------
	friend cInt operator %(const cInt& obj1, const cInt& obj2)
	{
		if (obj2.m_Value == 0)   // 被取余数不能为 0
		{
			return cInt(0);
		}
		return cInt(obj1.m_Value % obj2.m_Value);
	}
// ------------------------------------------------------------------------------------------------------------------------
	// 实现 = 重载 （不能使用友元函数 实现   编译器报错） 类里没有 动态申请内存的类型，就不需要 实现  可直接赋值 ------------
	
	cInt& operator =(cInt& result)
	{
	this->m_Value = result.m_Value;
	return *this;
	}


	// 前置 ++ （不带参的为前置 ++）--------------------------------------------------------------------
/*
	cInt operator ++()
	{
		this->m_Value++;
		return *this;
	}
*/
	// 友元函数 实现 前置 ++ 重载
	friend cInt operator ++(cInt& obj)
	{
		/*cInt cIntTemp;
		cIntTemp.m_Value = ++obj.m_Value;
		return cIntTemp;*/
		return cInt(++obj.m_Value);
	}

	// 后置 ++ （带参数的为 后置 ++，）-----------------------------------------------------------
/*	
	cInt operator ++(int value)
		{
			this->m_Value++;
			return *this;
		}
*/
	// 友元函数 实现 后置 ++ 重载
	friend cInt operator ++(cInt& obj,int value)
	{
		cInt cIntTemp;
		cIntTemp.m_Value = obj.m_Value;
		obj.m_Value++;
		return cIntTemp;
	}

	// 前置 - -    ------------------------------------------------------------------------------------------------------
	cInt operator --()
	{ 
		return cInt(--this->m_Value);
	}
	//friend cInt operator --(cInt& obj)
	//{
	//	return cInt(--obj.m_Value);
	//}

	// 后置 - -    ------------------------------------------------------------------------------------------------------
	cInt operator --(int value)   // 后置 - -  operator - -(int) 的形参必须是 int 类型  但不会用到
	{
		cInt temp;
		temp.m_Value = this->m_Value;  // 先保存原来的值 用于返回   再把当前的值 - - 
		this->m_Value--;
		return temp;
	}

	// 实现 += 重载 -------------------------------------------------------------------------------------------------
	cInt& operator += (const cInt& obj)  // 如要改变第一个操作数的值 就使用 成员函数 的方法实现
	{
		this->m_Value += obj.m_Value;
		return *this;
	}

	// 友元函数 实现 += 重载  (这种情况下，一般使用 成员函数的方法来实现，因为它有改变操作数的值)
/*
	friend cInt& operator +=(cInt& obj1, const cInt& obj2)
	{
		obj1.m_Value += obj2.m_Value;
		return obj1;
	}
*/

	// > 运算 --------------------------------------------------------------------------------------------------------
	friend bool operator >(const cInt& obj1,const cInt& obj2)
	{
		if (obj1.m_Value > obj2.m_Value)
		{
			return true;
		}
		return false;
	}

	// < 运算 ---------------------------------------------------------------------------------------------------------
	friend bool operator <(const cInt& obj1, const cInt& obj2)
	{
		if (obj1.m_Value < obj2.m_Value)
		{
			return true;
		}
		return false;
	}

	// == 运算 --------------------------------------------------------------------------------------------------------
	friend bool operator ==(const cInt& obj1, const cInt& obj2)
	{
		if (obj1.m_Value == obj2.m_Value)
		{
			return true;
		}
		return false;
	}

	// != 运算 --------------------------------------------------------------------------------------------------------
	friend bool operator !=(const cInt& obj1, const cInt& obj2)
	{
		if (obj1.m_Value != obj2.m_Value)
		{
			return true;
		}
		return false;
	}

	// 重载 自定义类型转换为 内置类型 (输出时可输出一个类: cout << cInt << endl;) -----------------------------------
// 转换函数  (一般用 显示转换)
	explicit operator int()const   // 返回值就为 int 类型  （会与 operator +() 二义性，声明为 explicit 后就没有）
	{
		return m_Value;
	}
	/*
		1.转换函数必须是 类方法
		2.转换函数不能指定返回类型
		3.转换函数不能有参数

		也可以这样实现，不需要转换函数，使用类方法：
		int cInt_to_int()
		{
			return this->m_Value;
		}
	*/

	// 重载 自定义类型转换为 其它类型  --------------------------------------------------------------------------
/*
	explicit operator cTest()const
	{
		cTest cTestTemp;
		cTestTemp.m_cTestValue = m_Value;
		return cTestTemp;
		// return cTest(m_Value);
	}
*/

	// 实现 << 重载 （ << 的返回值是 cout，而 cout 的类型是 ostream 类，所以返回类型应是 ostream 引用 来实现后面的输出）
	friend ostream& operator <<(ostream& os, cInt& obj)  // 因为 ostream 作为第一个操作数的类型，所以只能使用 友元函数 来实现重载
	{
		os << obj.m_Value;
		return os;
	}

	// 实现 >> 重载 (>> 的返回值是 cin，而 cin 的类型是 istream 类，所以返回类型应是 istream 引用)
	friend istream& operator >>(istream& is, cInt& obj)
	{
		is >> obj.m_Value;
		return is;
	}
	
	int m_Value;
	double m_doubleValue;
/*
	void FuncInt(cTest* obj) // 测试友元函数 访问 友元类的私有成员
	{
	// this->m_testValue = obj->m_cTestPrivateValue;   // 访问 cTest 类的 私有成员
	}
*/
private:
	int m_testValue;
protected:
	int m_testValue1;

	friend cTest;   // 声明 cTest 是 cInt 的友元类，即在 cTest 类中可以访问 cInt 类的 私有与保护 成员
};

class cTest
{
public:
	cTest(){}
	~cTest(){}
	void FuncTest(cInt& obj)
	{
		this->m_cTestPrivateValue = obj.m_testValue;   // 可以访问 cInt 类的 私有以及保护 成员
	}
	friend cInt; // 互为友元 声明 cInt 是 cTest 的友元类，即在 cInt 类中可以访问 cTest 类的 私有与保护 成员
	int m_cTestValue;
private:
	int m_cTestPrivateValue;
};

inline int Max(int a, int b)   // 内联函数
{
	if (a > b)
	{
		return a;
	}
	return b;
}
int main()
{
	
	cInt object1(100);
	cInt object2(200);
// 转换函数  (本类型 转换到 内置类型)
	int temp = (int)object1;   // 通过转换函数 operator int() 将 object1 转换为 int 后赋值给 temp;  

// + 运算
	//cInt result1 = object1.operator+(object2);  调用友元函数时不能这样写，因为不能通过对象来调用它
	 cInt result1 = object1 + object2; //  这两种写法是相等的
	cout << "result1 = " << result1.m_Value << endl;

	cInt result2 = result1+ 10;  // 通过 const 引用的对象 自动调用 转换构造函数，来实现运算
								  //	cInt result4 = result3 + cInt(10);  // 调用显示转换构造函数的写法
	cInt result3 = 12 + result2;
	// 通过友元函数，使 左操作数类型为 const 的引用，自动调用 转换构造函数，实现运算

// - 运算
	cInt obj(5);
	obj = -obj;    // 一元

	cInt obj2(3);
	cInt obj3 = obj - obj2;    // 对象 - 对象

	obj3 = obj2 - 1;
	obj3 = 10 - obj2;		// int - 对象    对象 - int 

// * 运算
	result1 = result2 * 5;
	result2 = 6 * result1;
	result3 = result1 * result2;

// / 运算
	result1 = result2 / 5;
	result2 = 6 / result1;
	result3 = result1 / result2;

// % 运算
	result1 = result2 % 5;
	result2 = 6 % result1;
	result3 = result1 % result2;

// = 运算 (类里 没有 内存分配的值时 不需要重载)
	cInt result5(15);
	cInt result6 = result5;

// += 运算
	result6 += result5;
	result6 += 5;

// 前置 ++
	cInt result4 = ++object1;
	cout << "result2 = " << result4.m_Value << endl;

// 后置 ++ 
	result5 = object2++;	
	cout << "result3 = " << result5.m_Value << endl;

// 前置 --
	result5 = --result4;

// 后置 --
	result5 = result4--;

// > 、< 、== 、!= 运算
	bool judge = result3 > result2;
	judge = result4 < result2;
	judge = result1 == result2;
	judge = result3 != result2;

// <<、>> 运算
	cin >> result6;
	cout << result6 <<"\tdsfd"<<"\t"<< 10 << endl;  // operator int()  把一个自定义的类型转换成 int 输出
	// 先运行 operator <<() 输出 result6，返回值为 ostream 引用 类型的 cout，再运行 cout << "dsfd" 依次输出
	int c = Max(10, 9);

	cArrayInt arrayint(10);  // 通过自定义的 int 数组类，创建了一个 int [10] 的数组
	int a = arrayint[5];   // 通过 operator []() 实现自定义的数组类 赋值 与 取值
	arrayint[3] = 6;
	arrayint.Resize(7);  // 通过 Resize() 函数能改变 arrayint 数组的大小，可变数组
	
	arrayint.Insert(arrayint->GetSize());		// 通过数组大小插入元素
	arrayint.Sort(true);   // 从小到大排序
	arrayint.Print();		// 通过数组大小打印元素
	cout << endl;

	arrayint.Sort(false);	 // 从大到小排序
	arrayint.Print();
	
	arrayint[6] = 1000556;
	cout << "\narrayint[16] = " << arrayint[6] << endl;

	cArrayInt arrayint1(arrayint);		// 通过一个对象创建一个对象
	cArrayInt arrayint2 = arrayint1;  // 与上面的一样 调用的是 复制构造函数
	cArrayInt arrayint3(5);
	arrayint3 = arrayint2;   // 把 arrayint2 的前五个值赋值给了 arrayint3
	arrayint3->Print();


	system("pause");
	return 0;
}