#include "stdafx.h"			/* class 2(.cpp) */ 
using namespace std;

cPeople::cPeople()    // 构造函数定义格式： 类名 :: 构造函数 (无返回值)
{
	cout << "创建了一个people" << endl;
	m_name = NULL;    // 需置为 NULL 否则被析构时会报错
	m_age = 20;
}

/* 构造函数初始化列表：
cPeople::cPeople()：m_age(0),m_name(NULL)  // 用于简单的赋值操作
{
cout << "创建了一个people" << endl;
}	*/

cPeople::cPeople(int age, char* sex, char* name)  // 重载的构造函数
{
	cout << " 创建了一个带参数的people" << endl;
	m_age = age;
	if (sex != NULL)
	{
		strcpy(m_sex, sex);
		cout << "people的年龄是：" << m_age << endl;
		cout << "people的性别是：" << m_sex << endl;
	}
	else
	{
		cout << "输入的性别错误！" << endl;
	}
	if (name != NULL)
	{
		m_name = new char[strlen(name) + 1];
		strcpy(m_name, name);
		cout << "people的姓名是：" << m_name << endl;
	}
	else
	{
		cout << "输入的姓名错误！" << endl;
		m_name = NULL;
	}
}

cPeople::~cPeople()		//析构函数 类的对象销毁时自动调用；内存的清理
{
	if (m_name != NULL)
	{
		cout << m_name << "dead" << endl;
		delete m_name;
		m_name = NULL;
	}
}
void cPeople::walk()		// 加 cPeople:: 代表这个函数是 cPeople 这个类里面的，:: 是作用域说明符
{
	cout << "走路" << endl;
	this->m_name = NULL;
	// this 保存的是调用它的这个成员函数的对象的地址 也就是 people1 的地址  因为是 people1 调用的这个 work() 成员函数
	// this 指针只能出现在成员函数中 (只能出现在非静态成员函数中) 
}

int cPeople::GetCount() const   // 不能在 const 成员函数里 调用非 const 的成员函数（可以调用非 const 成员变量）,并且在常量成员函数里也不能修改任何数据成员 
{
	this->GetAge();
	return 0;
}
void cPeople::sleep()	// 定义 类的静态成员函数的方法(不需要加 static 关键字，用类名与作用域说明符来访问)
{
	drink();
	cout << "static sleep()中 sum =  " << sum << endl;	// 只能访问 static 成员变量 与 static 成员函数
}
int cPeople::sum = 10;  // 唯一对 类的静态成员变量赋值 的方法(不需要加 static 关键字，用类名与作用域说明符来访问)
						// 类型 类名:: 静态变量名 

const int cPeople::total = 0;  // 初始化静态常量成员变量 