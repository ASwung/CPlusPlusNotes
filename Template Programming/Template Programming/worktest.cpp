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
    Singer s_temp;		// �����Լ�����

    Worker * pw[LIM] = {&bob, &bev, &w_temp, &s_temp};
	// �ø����ָ������ �����������ָ��   �൱��һ�����߰��������ÿ�����߶������Լ��ķ��� ���Ӧ���±�ƥ����Ե��ø��ֹ��ߣ�
	// �����������ǵķ���
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
