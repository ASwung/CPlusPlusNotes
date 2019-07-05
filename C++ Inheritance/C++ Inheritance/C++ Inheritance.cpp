// C++ Inheritance.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <tchar.h>
#include <Windows.h>
using namespace std;

class cpeople
{
public:
	cpeople()
	{
		cout << "cpeople()构造函数" << endl;
	}
	cpeople(int value)
	{
		m_value = value;
		cout << "cpeople(int value)构造函数" << endl;
	}
	virtual ~cpeople()	 // 使能通过父类来析构 所有类对象
	{
		cout << "cpeople()析构函数" << endl;
	}
	void p_eat()
	{
		cout << "cpeople public.eat()" << endl;
	}
	virtual void work()		// 设为了虚函数
	{
		cout << "cpeople::work()" << endl;
	}
	int age;
private:
	char p_name[5];
	void p_love()
	{
		cout << "cpeople.private.love()" << endl;
	}
protected:
	int p_age;
	int m_value;
	void p_walk()
	{
		cout << "cpeople.protected.walk()" << endl;
	}
};

class cworker :public cpeople			// 单个继承
{
public:
	cworker()
	{
		cout << "cworker()构造函数" << endl;
	}
	cworker(int value) :cpeople(value)
	{		// 这样写可以 当构造子类对象时，先构造父类，可以让父类使用 带参的 构造函数构造(前提是要有 带参的父类构造函数)
			// 如果没有这样写 没有加上 :cpeople(value) 会默认调用 父类的无参构造函数  目的是为了 防止重复包含或定义(只限于 windows 平台) 
		m_value = value;
		cout << "cworker(int value)构造函数" << endl;
	}
	~cworker()
	{
		cout << "cworker()析构函数" << endl;
	}
	void w_eat()
	{
		cout << "cworker.public.w_eat()" << endl;
	}
	void work()
	{
		cout << "cworker::work()" << endl;
	}
private:
	char w_name[5];
	void w_love()
	{
		cout << "cworker.private.w_love()" << endl;
	}
protected:
	int w_age;
	void w_walk()
	{
		cout << "cworker.protected.w_walk()" << endl;
	}
};

class cstudent :protected cworker		// 多重继承
{
public:
	cstudent()
	{
		cout << "cstudent()构造函数" << endl;
	}
	~cstudent()
	{
		cout << "~cstudent()析构函数" << endl;
	}

	void s_eat()
	{
		cout << "cstudent.public.s_eat()" << endl;
	}

private:
	char s_name[5];
	void s_love()
	{
		cout << "cstudent.private.s_love()" << endl;
	}
protected:
	int s_age;
	void s_walk()
	{
		cout << "cstudent.protected.s_walk()" << endl;
	}
};



class cMan
{
public:
	cMan()
	{
		cout << "In cMan class" << endl;
	}
	~cMan()
	{

	}
	int cMan_age;
private:
	int cMan_money;
};

class cManagement :public cpeople, private cMan	// 多继承
{
public:
	cManagement()
	{
		cout << "In cManagement class" << endl;
	}
	int manage_money;
};

/* 继承方式：
class ClassName : 继承类型(公有继承(public)、私有继承(private)、保护继承(protected)) 父类名称
{					// 如是 多继承，需再在 父类名称后写上 另一个继承类的类型与名称

};		*/

int _tmain(int argc, _TCHAR* argv[])
{
	cworker* worker = NULL;
	worker->w_eat();			// 即使类没有被构造出来，也能被调用，因为普通成员函数 是通过调用者的类型 来调用的

	cworker* worker1 = new cworker;
	worker1->age = 100;
	cpeople* people1 = worker1;
	cout << "worker1->age:" << worker1->age << "\t" << "people1->age:" << people1->age << endl;  // worker1->age == people1->age 调用的是同一个成员

	worker1->work();  // worker1->work() == people1->work() 调用的同一个成员函数
	people1->work();  // 此时为什么 不是通过调用者的类型 来调用成员函数的？  因为 父类里 那个与子类相同的成员函数 被设为了虚函数
							// 但如果是 people1 指向了 cpeople 的对象，就会调用到 cpeople 里的 work() 
	delete people1;

	// 通过父类来析构，只会析构父类，而子类会泄露，如想完全析构，需把父类析构函数 定义为虚函数
/*cpeople people;
cworker work;
cstudent student;
people = work;		// 可以 子类转换成父类，不用强制转换，但必须是 public 继承的
//	work = (cworker)people;   不可以父类转换成子类，强制转换都不行

		// 先创建父类，再创建子类，先释放子类，再释放父类（类似递归的顺序）
		// 继承类:   称为子类 或者 派生类
		// 被继承类: 称为父类 或者 基类

		// 单一继承：一个类只共享了另一个类的数据和行为
		// cworker类 只继承了 cpeople类 属于单个继承;		子类 --> 父类（cworker --> cpeople）
		// B类 --> A类 <-- C类				 子类 --> 父类 <-- 子类

		// 多重继承：A类 --> B类 --> C类;		子类 --> 子类 --> 父类(cstudent --> cworker --> cpeople)
		cstudent student1;

		// 多继承：一个类共享了多个类的数据和行为（一个子类继承多个父类）
		// B类 <-- A类 --> C类              父类 <-- 子类 --> 父类 (cpeople <-- cManagement --> cMan)

		// 菱形继承：
		// D类 --> B类 --> A类 <-- C类 <-- D类      子类 --> 父类 --> 祖先 <-- 父类 <-- 子类  (子类为同一个)

		cManagement manage;  */

		/****************************************************************************************/
		/*  1.私有成员不能被继承																	*/
		/*	2.公有继承 public：在父类中是什么类型在子类中就是什么类型（访问类型不变）				    */
		/*	3.私有继承 private：不管在父类中是什么类型，在子类中都变成私有（所有成员都变私有）			*/
		/*	4.保护继承 protected：不管在父类中是什么类型，在子类中都变成了保护（所有成员都变保护)		*/
		/****************************************************************************************/


		// 谁创建，谁初始化
		// 谁申请，谁释放


	/*
				动态绑定 和 静态绑定 是相对于函数而言的
		静态绑定：在编译阶段确定调用函数的绑定称为静态绑定 （在对象中，普通成员函数是不占内存的，而成员变量是占内存的）

		普通成员函数被存储在的另一片空间里，不需通过对象也可以调用（即使对象没有被真正构造出来） cpeople* people = NULL; people->p_eat(); 是可以的

		 普通成员函数是通过 调用者的类型 来调用的，如果一个子类的对象被父类所指向，用父类来调用成员函数，只会调用到父类里的成员函数，要想调用子类里的，
		 就需要把父类里那个与子类相同函数名的成员函数 在函数类型前 加上 virtual 使之成为 虚函数，就可以实现多态

		 拥有虚函数的类 的每一个子类与这个父类相同函数名 都能被父类所调用 （有虚函数的类 仅对 它的子类有效）

		动态绑定：在运行时确定调用函数的绑定称为动态绑定 （虚函数: 函数声明时，在前面加上 virtual）

		一个类里如果定义成了虚函数，那么在这个类的对象里 会有一个专门用来 存虚函数的指针( _vfptr )，这个指针指向的另一片空间，一片专门存储虚函数地址的空间

		虚函数是占内存的  也就是 声明虚函数后，被调用时，不是在普通成员函数那片内存里被调用，而是在 存虚函数的那片内存里来调用 被声明虚函数的类里 会有一个
		隐藏的指向虚函数表(存储虚函数的内存)的指针 成员

		多态： 相同的 自定义的 数据类型的指针(或引用) 有不同的形态 （用同一个类的指针来调用同一个函数，有着不一样的实现）

		多态的应用: 用父类指针变量 保存子类对象 的地址，再用父类指针 调用虚函数
	在实现多态时，防止删除一个 new 出来的子类对象时 未调用子类的析构函数
	 （因为应用多态时，是使用父类来调用子类的函数，操作完成后，想要释放父类以及子类的内存时，通过父类来释放
		需要把父类的析构函数 定义为虚函数，才能释放所有的类对象，否则只能释放父类的对象）

*/
	system("pause");
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
