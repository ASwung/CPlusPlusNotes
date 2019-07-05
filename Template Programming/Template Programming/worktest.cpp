// worktest.cpp -- test worker class hierarchy
#include "stdafx.h"
#include <iostream>
#include "worker0.h"
const int LIM = 4;
int main()
{
    Waiter bob("Bob Apple", 314L, 5);
    Singer bev("Beverly Hills", 522L, 3);
    Waiter w_temp;
    Singer s_temp;		// 用于自己设置

    Worker * pw[LIM] = {&bob, &bev, &w_temp, &s_temp};
	// 用父类的指针数组 保存多个子类的指针   相当于一个工具包，里面的每个工具都有它自己的方法 与对应的下标匹配可以调用各种工具，
	// 进而调用他们的方法
    int i;
    for (i = 2; i < LIM; i++)
        pw[i]->Set();
    for (i = 0; i < LIM; i++)
    {
        pw[i]->Show();
        std::cout << std::endl;
    }
    // std::cin.get();
	system("pause");
    return 0;
}
