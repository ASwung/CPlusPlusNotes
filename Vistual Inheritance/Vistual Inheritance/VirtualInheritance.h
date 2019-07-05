#ifndef VIRTUALINHERITANCE_H_
#define VIRTUALINHERITANCE_H_


#include "stdafx.h"
using namespace std;

class cPerson
{
public:
	cPerson() :m_strName() {}
	cPerson(const string& str,long id):m_strName(str),m_id(id){}
	virtual  ~cPerson() = 0;
	virtual void eat();
	virtual void walk();

	virtual void Set() = 0;   // 外部接口 用来调用 Get()内部接口  来设置 cPerson 的 name 与 ID
	virtual void Show() = 0;	  // 外部接口 用来调用 Data()内部接口  来输出 cPerson 的 name 与 ID

protected:
	virtual void Data();	// 内部接口  用来输出 cPerson 的 name 与 ID (协助 Show() 以输出数据)
	virtual void Get();		// 内部接口	 用来输入 cPerson 的 name 与 ID (协助 Set() 以输入数据)

private:
	string m_strName;
	long m_id;
};


class cWorker:public virtual cPerson
{
public:
	cWorker():cPerson(){}
	cWorker(const string& str,long id,int workAge = 0):cPerson(str,id),m_workAge(workAge){}
	
	virtual void eat();
	virtual void walk();

	virtual void Set();
	virtual void Show();
protected:
	virtual void Data();
	virtual void Get();

	void programming();
	//virtual void Data();
private:
	int m_workAge;
};

class cChildren:virtual public cPerson
{
public:
	cChildren() {}
	cChildren(const string& str, long id,int studyAge = 6):cPerson(str,id),m_studyAge(studyAge){}

	virtual void eat();
	virtual void walk();

	virtual void Set();    
	virtual void Show();
protected:
	virtual void Data();
	virtual void Get();

	void study();
	//virtual void Data();
private:
	int m_studyAge;
};

class cChildLabourer:public cWorker,public cChildren
{
public:
	cChildLabourer():cWorker(),cChildren(){}
	cChildLabourer(const string& str,long id,int workAge,int studyAge,int minor = 12):cPerson(str,id),cWorker(str,id,4),
																					  cChildren(str,id,10),m_minor(minor){} 
	// 虚继承类的构造函数方式，先构造祖先类，再构造父类，再构造自己，在非虚继承类中为非法
	
	/*cChildLabourer(const string& str,long id,int workAge,int studyAge,int minor = 12):cWorker(str, id, 4),
	cChildren(str, id, 10), m_minor(minor) {}   */
	// 非虚继承是这样的构造方法，不能直接构造祖先类，需先构造父类，再通过父类构造祖先类
	
	virtual void eat();
	virtual void walk();

	virtual void Set();
	virtual void Show();
protected:
	virtual void Data();
	virtual void Get();

	void tireWorking();
//	virtual void Data();
private:
	int m_minor;
};


#endif // !VIRTUALINHERITANCE_H_

