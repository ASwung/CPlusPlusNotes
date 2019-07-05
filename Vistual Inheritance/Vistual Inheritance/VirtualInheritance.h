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

	virtual void Set() = 0;   // �ⲿ�ӿ� �������� Get()�ڲ��ӿ�  ������ cPerson �� name �� ID
	virtual void Show() = 0;	  // �ⲿ�ӿ� �������� Data()�ڲ��ӿ�  ����� cPerson �� name �� ID

protected:
	virtual void Data();	// �ڲ��ӿ�  ������� cPerson �� name �� ID (Э�� Show() ���������)
	virtual void Get();		// �ڲ��ӿ�	 �������� cPerson �� name �� ID (Э�� Set() ����������)

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
	// ��̳���Ĺ��캯����ʽ���ȹ��������࣬�ٹ��츸�࣬�ٹ����Լ����ڷ���̳�����Ϊ�Ƿ�
	
	/*cChildLabourer(const string& str,long id,int workAge,int studyAge,int minor = 12):cWorker(str, id, 4),
	cChildren(str, id, 10), m_minor(minor) {}   */
	// ����̳��������Ĺ��췽��������ֱ�ӹ��������࣬���ȹ��츸�࣬��ͨ�����๹��������
	
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

