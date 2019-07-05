#include "stdafx.h"
#include "VirtualInheritance.h"
using namespace std;
cPerson::~cPerson()
{
	cout << "~cPerson()" << endl;
}
// cPerson:
void cPerson::eat()
{
	cout << "cPerson::eat()" << endl;
}
void cPerson::walk()
{
	cout << "cPerson::walk()" << endl;
}
void cPerson::Get()
{
	getline(cin, m_strName);
	cout << "Please enter person ID:\n";
	cin >> m_id;
	while (cin.get() != '\n')
	{

	}
}
void cPerson::Data()
{
	cout << "Name: " << m_strName << endl;
	cout << "Employee: " << m_id << endl;
}

// cWorker:
void cWorker::eat()
{
	cout << "cWorker::eat()" << endl;
}
void cWorker::walk()
{
	cout << "cWorker::walk()" << endl;
}
void cWorker::Set()
{
	cout << "Please enter worker name:\n";
	cPerson::Get();
	this->Get();
}
void cWorker::Get()
{
	cout << "Please enter worker workAge:\n";
	cin >> m_workAge;
	while (cin.get()!='\n')
	{

	}
}
void cWorker::Data()
{
	cout << "workAge: " << m_workAge << endl;
}
void cWorker::Show()
{
	cPerson::Data();
	this->Data();
}
void cWorker::programming()
{
	cout << "cWorker::programming()" << endl;
}

// cChildren:
void cChildren::eat()
{
	cout << "cChildren::eat()" << endl;
}
void cChildren::walk()
{
	cout << "cChildren::walk()" << endl;
}
void cChildren::Set()
{
	cout << "Please enter children name:\n";
	cPerson::Get();
	this->Get();
}
void cChildren::Get()
{
	cout << "Please enter children studyAge:\n";
	cin >> m_studyAge;
	while (cin.get() != '\n')
	{

	}
}
void cChildren::Data()
{
	cout << "studyAge: " << m_studyAge << endl;
}
void cChildren::Show()
{
	cPerson::Data();
	this->Data();
}
void cChildren::study()
{
	cout << "cChildren::study()" << endl;
}

// cChildLabourer:
void cChildLabourer::eat()
{
	cout << "cChildLabourer::eat()" << endl;
}
void cChildLabourer::walk()
{
	cout << "cChildLabourer::walk()" << endl;
}
void cChildLabourer::Set()
{
	cout << "Please enter childLabourer name:\n";
	cPerson::Get();
	cWorker::Get();
	cChildren::Get();
	this->Get();
}
void cChildLabourer::Get()
{
	cout << "Please enter childLabourer minorAge:\n";
	cin >> m_minor;
	while (cin.get() != '\n')
	{

	}
}
void cChildLabourer::Data()
{
	cout << "minorAge: " << m_minor << endl;
}
void cChildLabourer::Show()
{
	cPerson::Data();
	cWorker::Data();
	cChildren::Data();
	this->Data();
}
void cChildLabourer::tireWorking()
{
	cout << "cChildLabourer::tireWorking()" << endl;
}