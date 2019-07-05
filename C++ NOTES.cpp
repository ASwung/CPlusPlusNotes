// lesson3first.cpp : �������̨Ӧ�ó������ڵ㡣
//
								/* C++ NOTES */ 
#include "stdafx.h"   // ��׼Ӧ�ó����ܵ���չ 
#include<iostream>	  // C++����������������ü� .h 
#include <stdio.h>
using namespace std;	// ʹ�������ռ�: std  ��ֹ���� 
// С֪ʶ��
// using �� typedef: 
	using HONDA = int;
	typedef int honda;
	cout << "using:" << sizeof(HONDA) << "\ttypedef:" << sizeof(honda) << endl;
	// (using newtype = type)  ==  (typedef type newtype);

// auto ������ 
	double i1 = 5.7, i2 = 6.4;
	auto i3 = i1 + i2;		// ���� i3 ������ȡ���ڣ�i1 + i2) ���������
	cout << "i3 = " << i3 << "\tauto:" << sizeof(i3) << endl;

// decltype ����������ͣ� 
	int i = 5;
	decltype(i) j = 8;	// ������һ������ j��ʹ���������� i һ��

// C++ ���õ�����ת����ʽ��
	char letter = 'a';
	printf("%p\n", &letter);		// C �������ַ���ַ
	cout << static_cast<void*>(&letter) << endl;	// static_cast<TYPE>(argument) C++ ��������ת��
	// &letter �� char*��C++ ���� char* �ǵ����ַ�������ģ��� letter ���ַ���û�� '\0'������ֱ��ȡ��ַ�����������
	
// ���ַ���ת��Ϊ������_ttoi(); 
	int num = _ttoi(argv[0]);  // _ttoi() ת���ַ���Ϊ������������Ӧ�� wchar_t* ���͵� 
	
// �����ռ䣺
namespace Aswung			// ������һ����Ϊ Aswung �������ռ䡣������ֹ������ʹ��ʱ��ӣ� using namespace Aswung;
{
	struct stuStudentInfo
	{
		char stuName[20];
		int Age;
		void stuPrintAge()
		{
			cout << "stuName:" << this->stuName << "\tAge = " << this->Age << endl;
		}
	};
} 
	
// ���ú��������ȼ���
  // ���ֵ��÷�ʽ��
{
	swap(a, b);   // ���ȵ��ñ��ļ������ swap()��������ļ���û�У�����������ռ����
	::swap(a, b);	   // ���ñ��ļ���� swap()
	std::swap(a, b);  // ���� std �����ռ��е� swap()

	Func(argument1, argument2);    // ���ȵ�����ͨ��������û����ͨ�����������ģ�庯��
	Func<type>(argument1, argument2);  // ֻ�ܵ���ģ�庯��
}
	
// ���ã�
void swap(int& a, int &b)	
{
	int temp = a;
	a = b;
	b = temp;
}

	int &pp = num1;     // num1 �� pp ���ã� num1 == pp
	pp = num2;			// num2 �ֱ� pp ���ã� num1 == num2 == pp;
	pp = 4;				// �ָı� pp ��ֵ�� num1 == pp, num2 ����
	pp = 5;				// �ٴθı� pp ��ֵ��num1 == pp��	������ñ�����ֻ��ı��һ�������õı�����ֵ��
	
	// ���õ��ص㣺
	// 1.������һ�������ı�������ַ��ֵ�������һ��
	// 2.��������ʱ�����ʼ���������ñ��������ñ�������Ҫһ��
	// 3.��ʽ��int b = 0; int& a = b;
	// 4.��ָ������,�����ú�ı����ٴ����ã����޸� ��һ�� �����õı�����ֵ��
	
// �����ã�
 int a = 1;
 const int &aa = a;
 // aa = 10;	 	// ��Ϊ aa ��������� �����ã����Բ���ͨ�������� aa ���ı� ����ֵ 
 a = 10; 			// ��Ҫ�ı�����ֵ��ֻ���� �������� �����õı��� ���ı� 

// �������أ�
void func(int a)
{
	
}
void func(int a,int b)
{
	
} 
	// �������ص�������
	// 1.�������뺯���������Ϳ���һ��
	// 2.���������������ߺ�����������һ��Ҫ��һ��  ��C������û�к������أ� 
	    // �� C �б��뺯��ʱ�����ܻ����ɣ�   func		  func 	�������� 
		// ���� C++ �б��뺯��ʱ�����ܻ����ɣ�	func_int    	func_int_int 	���Կ���
		
// ����ȱʡֵ��		 
int sum(int a=5,int b=1)	// �����ô˺���ʱ�����û�и��������߸��Ĳ������������ָ��˺����β�ȱʡֵʱ��Ĭ�ϴ˲���Ϊ������ȱʡֵ	 
{
	return a + b;
 } 
 double sum(double a,double b)
 {
 	return a + b;
 }
 	 // �ص㣺
	 // 1.��ȫ���βεĸ�������ȱʡֵ��Ч��������������жϣ�������Ӧ��
	 // 2.�ں����β��У���������ȱʡֵʱ������ǰһ������ȱʡֵ������滹�в���������ҲҪ������Ĳ���ȱʡֵ 
 
// new �� delete:
    int *p = new int;			// ������ һ �� int ���ڴ�ռ�� p 
	int *pp = new int[10];		// ������ ʮ �� int ���ڴ�ռ�� pp 
	delete p;			 	// �ͷ� 1 �� int �ķ�ʽ 
	delete []pp; 			// �ͷ� int���� �ķ�ʽ 
	/* ���ڶ�̬�ڴ����鿴�ڴ�ʱ��
	 1.�����������ʱ(��: int��double��char��float),�ڷ����ڴ����ʼ��ַ ��ǰ 16 ���ֽ� ���¼��������͵ĸ���
	 ����(��ʼ��ַ)0x00fffe - 16 == 0x00ffee     Ҳ������ 0x00ffee ~ 0x00fff1 �� 4 ���ֽ��л��� ��������͵ĸ�����ֵ
	 
	 2.�����Զ�������ʱ(�磺struct��class), �ڷ����ڴ����ʼ��ַ ��ǰ 4 ���ֽ� ���¼��������͵ĸ��� 
	 ����(��ʼ��ַ)0x00fffe - 4 == 0x00fffa      Ҳ������ 0x00fffa ~ 0x00fffd �� 4 ���ֽ��л��� ��������͵ĸ�����ֵ  */ 
							
// C��C++ ���� const ������
	const int a = 10;			// ����
	int *p = (int*)(&a);	
		// ��Ϊ const int* ���Ͳ������ڳ�ʼ�� int* ���ͣ�����Ҫǿ������ת������Ҳ����������int *p = static_cast<int*>(&a);
		
	*p = 3;						// ��ָ���� a ��ָ�� p ���¸�ֵ
	cout << "a=" << a << "\t*p=" << *p << endl;    
	// ���¸�ֵ��� a ��Ȼû�䣬��ָ�� a ��*p�ı��ˣ�������Ϊ C++ ����ڴ��ص����ƣ���������� a �����ں��滻
	
	int	b = *p;
	cout << "b=" << b << "\ta=" << a << "\t*p=" << *p << endl;  // b == *p�� a ��Ȼ����10��  ����� C ��,a �ᱻ�ı� 
	
// �� C ���Ե���ʽ���룺
extern "C"		// ������������ﶼ���� C ���Եķ�ʽ����� (���ַ�ʽ�� C �в�����) 
{
	
} 


// ����ģʽ��  һ����ֻ�ܴ���һ������ 
/* cCar* car1;
   cCar* c_p = NULL;  */
class cCar{
	cCar()
	{
		m_value = 55;
	}
				
	~cCar()		// �ù��캯������������Ĭ��Ϊ private 
	{
		
	}		
	int m_value;	
public:
	static cCar* GetInstance();		// ��̬��Ա���� ʵ�ֵ���ģʽ
	 // (��Ϊ �� static ��Ա�������ʱ���Ҫ���󣬶����캯��˽���ˣ��޷����ⲿ������������ֻ���� static ��Ա����) 
}; 
 int main()		// ����ģʽ���õķ��� 
 {
 //	cCar car ;    // ��Ϊ���캯��Ϊ private������ֻ��ʹ�õ���ģʽ������һ������ 
 	cCar* pCar1 = cCar::GetInstance();		// �����Ϳ��Ի��һ������ ��̬�� class ����� 
 
	cCar* pCar2 = cCar::GetInstance();		// pCar1 == pCar2   ��Ϊ �� GetInstance() ������ֻ������һ��
	
	delete pCar1;
	return 0; 
 }
 cCar* cCar::GetInstance()
	{
		static cCar* pCar = new cCar;    // ֻ�ܱ�����һ�Σ������� static �ͻᱻ new ��� 
		return pCar;
		// ����ģʽ��һ�ַ�ʽ��
	/*	if(c_p == NULL)
		{
			c_p = new cCar;
		}
		return c_p;   */
	}

