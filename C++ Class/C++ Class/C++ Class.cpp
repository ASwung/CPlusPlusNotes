// C++ Class.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include"cPeople.h"		
using namespace std;
int main()
{
	cPeople people1;//���캯��������Ķ��󴴽������죩ʱ���Զ�����
	people1.walk();
	cPeople people2;
	{
		cPeople people3(10, "��", "С��");		// ��������ʱ���Զ�������������
	}
	cPeople* cpeople4 = new cPeople(12, "Ů", "����");   // ����������� �ڴ� ֻ���Լ��ֶ��ͷ� 
	delete cpeople4;		// �ֶ��ͷ��ڴ�ʱ��Ҳ���Զ�������������
	cpeople4 = NULL;

	cPeople cpeople5(1, "pp", "dfdf");
	cpeople5.sum = 1000;		// static ֵ�ǿɸĵģ���ʹ cpeople5 ����������٣��� sum ��ֵ��Ȼ����
	cout << cpeople5.sum << endl;

	cPeople::sleep();  // ����  ��ľ�̬��Ա�����ķ�������������������˵���������ʣ�

// ����ģʽ���õķ��� 
	//	cCar car ;    // ��Ϊ���캯��Ϊ private������ֻ��ʹ�õ���ģʽ������һ������ 
	cCar* pCar1 = cCar::GetInstance();		// �����Ϳ��Ի��һ������ ��̬�� class ����� 

	cCar* pCar2 = cCar::GetInstance();		// pCar1 == pCar2   ��Ϊ �� GetInstance() ������ֻ������һ��  static cCar* pCar = new cCar;
	system("pause");
    return 0;
}

