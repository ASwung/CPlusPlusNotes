#pragma once
#include "stdafx.h"
using namespace std;
class cAnimal
{
public:
	cAnimal();
	virtual ~cAnimal();

	virtual void walk() = 0;  // ���麯�� ������ʵ������������ɣ�
	/*virtual void walk()
	{
		cout << "������·" << endl;
	}*/
};

class cBird:public cAnimal
{
public:
	cBird();
	~cBird();
	void walk()
	{
		cout << "�ҷ�����" << endl;
	}
};

class cDog :public cAnimal
{
public:
	cDog();
	~cDog();
	void walk()
	{
		cout << "����ֻ����" << endl;
	}
};

class cSnake :public cAnimal
{
public:
	cSnake();
	~cSnake();
	void walk()
	{
		cout << "��������" << endl;
	}
};

