#include "stdafx.h"
#include "Animal.h"


cAnimal::cAnimal()
{
	cout << "Animal::Animal()构造函数" << endl;
}


cAnimal::~cAnimal()
{
	cout << "Animal::~Animal()析构函数" << endl;
}


cBird::cBird()
{
	cout << "Bird::Bird()构造函数" << endl;
}

cBird::~cBird()
{
	cout << "Bird::~Bird()析构函数" << endl;
}


cDog::cDog()
{
	cout << "Dog::Dog()构造函数" << endl;
}

cDog::~cDog()
{
	cout << "Dog::~Dog()析构函数" << endl;
}


cSnake::cSnake()
{
	cout << "Snake::Snake()构造函数" << endl;
}

cSnake::~cSnake()
{
	cout << "Snake::~Snake()析构函数" << endl;
}