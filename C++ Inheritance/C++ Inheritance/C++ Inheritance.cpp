// C++ Inheritance.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <tchar.h>
#include <Windows.h>
using namespace std;

class cpeople
{
public:
	cpeople()
	{
		cout << "cpeople()���캯��" << endl;
	}
	cpeople(int value)
	{
		m_value = value;
		cout << "cpeople(int value)���캯��" << endl;
	}
	virtual ~cpeople()	 // ʹ��ͨ������������ ���������
	{
		cout << "cpeople()��������" << endl;
	}
	void p_eat()
	{
		cout << "cpeople public.eat()" << endl;
	}
	virtual void work()		// ��Ϊ���麯��
	{
		cout << "cpeople::work()" << endl;
	}
	int age;
private:
	char p_name[5];
	void p_love()
	{
		cout << "cpeople.private.love()" << endl;
	}
protected:
	int p_age;
	int m_value;
	void p_walk()
	{
		cout << "cpeople.protected.walk()" << endl;
	}
};

class cworker :public cpeople			// �����̳�
{
public:
	cworker()
	{
		cout << "cworker()���캯��" << endl;
	}
	cworker(int value) :cpeople(value)
	{		// ����д���� �������������ʱ���ȹ��츸�࣬�����ø���ʹ�� ���ε� ���캯������(ǰ����Ҫ�� ���εĸ��๹�캯��)
			// ���û������д û�м��� :cpeople(value) ��Ĭ�ϵ��� ������޲ι��캯��  Ŀ����Ϊ�� ��ֹ�ظ���������(ֻ���� windows ƽ̨) 
		m_value = value;
		cout << "cworker(int value)���캯��" << endl;
	}
	~cworker()
	{
		cout << "cworker()��������" << endl;
	}
	void w_eat()
	{
		cout << "cworker.public.w_eat()" << endl;
	}
	void work()
	{
		cout << "cworker::work()" << endl;
	}
private:
	char w_name[5];
	void w_love()
	{
		cout << "cworker.private.w_love()" << endl;
	}
protected:
	int w_age;
	void w_walk()
	{
		cout << "cworker.protected.w_walk()" << endl;
	}
};

class cstudent :protected cworker		// ���ؼ̳�
{
public:
	cstudent()
	{
		cout << "cstudent()���캯��" << endl;
	}
	~cstudent()
	{
		cout << "~cstudent()��������" << endl;
	}

	void s_eat()
	{
		cout << "cstudent.public.s_eat()" << endl;
	}

private:
	char s_name[5];
	void s_love()
	{
		cout << "cstudent.private.s_love()" << endl;
	}
protected:
	int s_age;
	void s_walk()
	{
		cout << "cstudent.protected.s_walk()" << endl;
	}
};



class cMan
{
public:
	cMan()
	{
		cout << "In cMan class" << endl;
	}
	~cMan()
	{

	}
	int cMan_age;
private:
	int cMan_money;
};

class cManagement :public cpeople, private cMan	// ��̳�
{
public:
	cManagement()
	{
		cout << "In cManagement class" << endl;
	}
	int manage_money;
};

/* �̳з�ʽ��
class ClassName : �̳�����(���м̳�(public)��˽�м̳�(private)�������̳�(protected)) ��������
{					// ���� ��̳У������� �������ƺ�д�� ��һ���̳��������������

};		*/

int _tmain(int argc, _TCHAR* argv[])
{
	cworker* worker = NULL;
	worker->w_eat();			// ��ʹ��û�б����������Ҳ�ܱ����ã���Ϊ��ͨ��Ա���� ��ͨ�������ߵ����� �����õ�

	cworker* worker1 = new cworker;
	worker1->age = 100;
	cpeople* people1 = worker1;
	cout << "worker1->age:" << worker1->age << "\t" << "people1->age:" << people1->age << endl;  // worker1->age == people1->age ���õ���ͬһ����Ա

	worker1->work();  // worker1->work() == people1->work() ���õ�ͬһ����Ա����
	people1->work();  // ��ʱΪʲô ����ͨ�������ߵ����� �����ó�Ա�����ģ�  ��Ϊ ������ �Ǹ���������ͬ�ĳ�Ա���� ����Ϊ���麯��
							// ������� people1 ָ���� cpeople �Ķ��󣬾ͻ���õ� cpeople ��� work() 
	delete people1;

	// ͨ��������������ֻ���������࣬�������й¶��������ȫ��������Ѹ����������� ����Ϊ�麯��
/*cpeople people;
cworker work;
cstudent student;
people = work;		// ���� ����ת���ɸ��࣬����ǿ��ת������������ public �̳е�
//	work = (cworker)people;   �����Ը���ת�������࣬ǿ��ת��������

		// �ȴ������࣬�ٴ������࣬���ͷ����࣬���ͷŸ��ࣨ���Ƶݹ��˳��
		// �̳���:   ��Ϊ���� ���� ������
		// ���̳���: ��Ϊ���� ���� ����

		// ��һ�̳У�һ����ֻ��������һ��������ݺ���Ϊ
		// cworker�� ֻ�̳��� cpeople�� ���ڵ����̳�;		���� --> ���ࣨcworker --> cpeople��
		// B�� --> A�� <-- C��				 ���� --> ���� <-- ����

		// ���ؼ̳У�A�� --> B�� --> C��;		���� --> ���� --> ����(cstudent --> cworker --> cpeople)
		cstudent student1;

		// ��̳У�һ���๲���˶��������ݺ���Ϊ��һ������̳ж�����ࣩ
		// B�� <-- A�� --> C��              ���� <-- ���� --> ���� (cpeople <-- cManagement --> cMan)

		// ���μ̳У�
		// D�� --> B�� --> A�� <-- C�� <-- D��      ���� --> ���� --> ���� <-- ���� <-- ����  (����Ϊͬһ��)

		cManagement manage;  */

		/****************************************************************************************/
		/*  1.˽�г�Ա���ܱ��̳�																	*/
		/*	2.���м̳� public���ڸ�������ʲô�����������о���ʲô���ͣ��������Ͳ��䣩				    */
		/*	3.˽�м̳� private�������ڸ�������ʲô���ͣ��������ж����˽�У����г�Ա����˽�У�			*/
		/*	4.�����̳� protected�������ڸ�������ʲô���ͣ��������ж�����˱��������г�Ա���䱣��)		*/
		/****************************************************************************************/


		// ˭������˭��ʼ��
		// ˭���룬˭�ͷ�


	/*
				��̬�� �� ��̬�� ������ں������Ե�
		��̬�󶨣��ڱ���׶�ȷ�����ú����İ󶨳�Ϊ��̬�� ���ڶ����У���ͨ��Ա�����ǲ�ռ�ڴ�ģ�����Ա������ռ�ڴ�ģ�

		��ͨ��Ա�������洢�ڵ���һƬ�ռ������ͨ������Ҳ���Ե��ã���ʹ����û�б�������������� cpeople* people = NULL; people->p_eat(); �ǿ��Ե�

		 ��ͨ��Ա������ͨ�� �����ߵ����� �����õģ����һ������Ķ��󱻸�����ָ���ø��������ó�Ա������ֻ����õ�������ĳ�Ա������Ҫ�����������ģ�
		 ����Ҫ�Ѹ������Ǹ���������ͬ�������ĳ�Ա���� �ں�������ǰ ���� virtual ʹ֮��Ϊ �麯�����Ϳ���ʵ�ֶ�̬

		 ӵ���麯������ ��ÿһ�����������������ͬ������ ���ܱ����������� �����麯������ ���� ����������Ч��

		��̬�󶨣�������ʱȷ�����ú����İ󶨳�Ϊ��̬�� ���麯��: ��������ʱ����ǰ����� virtual��

		һ�����������������麯������ô�������Ķ����� ����һ��ר������ ���麯����ָ��( _vfptr )�����ָ��ָ�����һƬ�ռ䣬һƬר�Ŵ洢�麯����ַ�Ŀռ�

		�麯����ռ�ڴ��  Ҳ���� �����麯���󣬱�����ʱ����������ͨ��Ա������Ƭ�ڴ��ﱻ���ã������� ���麯������Ƭ�ڴ��������� �������麯�������� ����һ��
		���ص�ָ���麯����(�洢�麯�����ڴ�)��ָ�� ��Ա

		��̬�� ��ͬ�� �Զ���� �������͵�ָ��(������) �в�ͬ����̬ ����ͬһ�����ָ��������ͬһ�����������Ų�һ����ʵ�֣�

		��̬��Ӧ��: �ø���ָ����� ����������� �ĵ�ַ�����ø���ָ�� �����麯��
	��ʵ�ֶ�̬ʱ����ֹɾ��һ�� new �������������ʱ δ�����������������
	 ����ΪӦ�ö�̬ʱ����ʹ�ø�������������ĺ�����������ɺ���Ҫ�ͷŸ����Լ�������ڴ�ʱ��ͨ���������ͷ�
		��Ҫ�Ѹ������������ ����Ϊ�麯���������ͷ����е�����󣬷���ֻ���ͷŸ���Ķ���

*/
	system("pause");
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
