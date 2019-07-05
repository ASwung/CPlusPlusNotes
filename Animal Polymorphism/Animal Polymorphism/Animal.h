#pragma once
#include "stdafx.h"
using namespace std;
class cAnimal
{
public:
	cAnimal();
	virtual ~cAnimal();

	virtual void walk() = 0;  // 纯虚函数 （它的实现在子类中完成）
	/*virtual void walk()
	{
		cout << "我在走路" << endl;
	}*/
};

class cBird:public cAnimal
{
public:
	cBird();
	~cBird();
	void walk()
	{
		cout << "我飞着走" << endl;
	}
};

class cDog :public cAnimal
{
public:
	cDog();
	~cDog();
	void walk()
	{
		cout << "我四只脚走" << endl;
	}
};

class cSnake :public cAnimal
{
public:
	cSnake();
	~cSnake();
	void walk()
	{
		cout << "我溜着走" << endl;
	}
};

