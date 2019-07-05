// C++ Class.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"cPeople.h"		
using namespace std;
int main()
{
	cPeople people1;//构造函数会在类的对象创建（构造）时候自动调用
	people1.walk();
	cPeople people2;
	{
		cPeople people3(10, "男", "小芳");		// 出作用域时会自动调用析构函数
	}
	cPeople* cpeople4 = new cPeople(12, "女", "丽萨");   // 在这里申请的 内存 只能自己手动释放 
	delete cpeople4;		// 手动释放内存时，也会自动调用析构函数
	cpeople4 = NULL;

	cPeople cpeople5(1, "pp", "dfdf");
	cpeople5.sum = 1000;		// static 值是可改的，即使 cpeople5 这个对象销毁，而 sum 的值依然存在
	cout << cpeople5.sum << endl;

	cPeople::sleep();  // 调用  类的静态成员函数的方法（用类名与作用域说明符来访问）

// 单例模式调用的方法 
	//	cCar car ;    // 因为构造函数为 private，所以只能使用单例模式来创建一个对象 
	cCar* pCar1 = cCar::GetInstance();		// 这样就可以获得一个具有 静态的 class 类对象 

	cCar* pCar2 = cCar::GetInstance();		// pCar1 == pCar2   因为 在 GetInstance() 函数里只会声明一次  static cCar* pCar = new cCar;
	system("pause");
    return 0;
}

