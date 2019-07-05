// ExceptionHanding.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "CException.h"
using namespace std;
// C++ 异常处理模型（关键字: try、catch、throw）:
/*
	try(试图):		试图进行 可能引发错误 的操作
	catch(捕获):		捕获被抛出的异常，只能 捕获对应参数类型 的异常
	throw(抛出):		抛出异常(某个类型的错误，这个数据类型可以为 内置类型 与 自定义类型)

// 作用:
    int Division(int a, int b)
	{
		if(b == 0)
		{
			return ?;
			// 这个时候你不知道返回一个什么好，如 -1 也可能为 a 与 b的商 
		// 但如果用 throw 抛出一个异常就可以实现，程序也不会因此出错，也能让用户识别到错误
		}
	}
// 操作:
	在调用时，使用 try{ }  在 { } 里进行调用，try 是程序编译器试着去运行 { } 里的代码，在调用的过程中，如遇到某些条件，运行到 throw 语句
	会自动的识别 异常的数据类型，然后在调用它的程序块里找 try{}，如果没有，会继续返回找 try{}，找到后，会自动与 try{} 后的
	有着相同类型异常数据 的 catch 进行匹配 从而调用 匹配到的 catch(){} 语句，如果没有 匹配到 相应数据类型的 catch(){} 就会调用系统的 一场函数(报错)
	   注: thorw 抛出的异常数据类型 一定要与 catch() 捕获的类型一样，才能完成匹配

// catch( ) { }  （ ）里可以是内置类型数据，也可以是 自定义类型数据（同理 throw 后也 可以是内置类型数据，也可以是 自定义类型数据）
	 catch(int err){}		   捕获 int 类型的异常数据
	 catch(const char* p){}  捕获 const char* 类型的异常数据
	 catch(...){}		   捕获 所以 类型的异常数据

// 注: 被抛出的异常如果没有被捕获，会自动调用系统的 捕获函数(报错)  
		析构函数里一般不抛出异常
*/

int Division(int a, int b)
{
	int err = 1;
	if (b == 0)
	{
		throw "b 不能为 0！！！";   // 抛出了 char* 类型的异常  
	/*  运行到第一句 throw 时，会直接跳转到 与异常数据类型相应的 catch 里，不会执行到 后面的 throw，
		因此，写了多个 throw 也没用(即使第一个 throw 匹配不到相应的 catch 也不会运行后面的 throw)
		throw err;		// 抛出了 int 类型的异常 
		throw 0.5;		// 抛出了 double 类型的异常 
	*/
		// 不需要在写 return; 语句
	}
	return a / b;
}

int main()
{
	try  // 试图去进行 { } 里的操作
	{
		int c = Division(10, 0);
	}

	catch (const char* p)   // 捕获 char* 类型的 异常数据
	{
		cout << p << endl;
	}
	catch (int print)	// 捕获 int 类型的异常数据
	{
		cout << print << endl;
	}
	catch (...)	  // 可以 捕获所有类型 的异常数据，后面不能再有 任何类型的 catch 了
	{
		cout << "有错误" << endl;
	}
	
// 	测试 CException.h
	cException exception1;
	for (int i = 0; i < exception1.m_size; ++i)
	{
		cout << exception1.m_errInfo[i] << endl;
	}
	
   system("pause");
    return 0;
}

