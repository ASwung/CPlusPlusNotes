#include "stdafx.h"			/* class 2(.cpp) */ 
using namespace std;

cPeople::cPeople()    // ���캯�������ʽ�� ���� :: ���캯�� (�޷���ֵ)
{
	cout << "������һ��people" << endl;
	m_name = NULL;    // ����Ϊ NULL ��������ʱ�ᱨ��
	m_age = 20;
}

/* ���캯����ʼ���б�
cPeople::cPeople()��m_age(0),m_name(NULL)  // ���ڼ򵥵ĸ�ֵ����
{
cout << "������һ��people" << endl;
}	*/

cPeople::cPeople(int age, char* sex, char* name)  // ���صĹ��캯��
{
	cout << " ������һ����������people" << endl;
	m_age = age;
	if (sex != NULL)
	{
		strcpy(m_sex, sex);
		cout << "people�������ǣ�" << m_age << endl;
		cout << "people���Ա��ǣ�" << m_sex << endl;
	}
	else
	{
		cout << "������Ա����" << endl;
	}
	if (name != NULL)
	{
		m_name = new char[strlen(name) + 1];
		strcpy(m_name, name);
		cout << "people�������ǣ�" << m_name << endl;
	}
	else
	{
		cout << "�������������" << endl;
		m_name = NULL;
	}
}

cPeople::~cPeople()		//�������� ��Ķ�������ʱ�Զ����ã��ڴ������
{
	if (m_name != NULL)
	{
		cout << m_name << "dead" << endl;
		delete m_name;
		m_name = NULL;
	}
}
void cPeople::walk()		// �� cPeople:: ������������� cPeople ���������ģ�:: ��������˵����
{
	cout << "��·" << endl;
	this->m_name = NULL;
	// this ������ǵ������������Ա�����Ķ���ĵ�ַ Ҳ���� people1 �ĵ�ַ  ��Ϊ�� people1 ���õ���� work() ��Ա����
	// this ָ��ֻ�ܳ����ڳ�Ա������ (ֻ�ܳ����ڷǾ�̬��Ա������) 
}

int cPeople::GetCount() const   // ������ const ��Ա������ ���÷� const �ĳ�Ա���������Ե��÷� const ��Ա������,�����ڳ�����Ա������Ҳ�����޸��κ����ݳ�Ա 
{
	this->GetAge();
	return 0;
}
void cPeople::sleep()	// ���� ��ľ�̬��Ա�����ķ���(����Ҫ�� static �ؼ��֣���������������˵����������)
{
	drink();
	cout << "static sleep()�� sum =  " << sum << endl;	// ֻ�ܷ��� static ��Ա���� �� static ��Ա����
}
int cPeople::sum = 10;  // Ψһ�� ��ľ�̬��Ա������ֵ �ķ���(����Ҫ�� static �ؼ��֣���������������˵����������)
						// ���� ����:: ��̬������ 

const int cPeople::total = 0;  // ��ʼ����̬������Ա���� 