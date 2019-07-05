// smrtptrs.cpp -- using three kinds of smart pointers
#include "stdafx.h"
#include <memory>    /* ��������ָ��ģ����: auto_ptr��unique_ptr��shared_ptr Ҫʹ�� ��Ҫ�������ͷ�ļ� */
// #include <Boost>

using namespace std;       // ����������ָ�붼�� C++11 ����
class Report
{
private:
    std::string str;
public:
    Report(const std::string s) : str(s) { std::cout << "Object created!\n"; }
    ~Report() { std::cout << "Object deleted!\n"; }
    void comment() const { std::cout << str << "\n"; }
	friend ostream& operator <<(ostream &os, Report& ps)
	{
		os << ps.str;
		return os;
	}
	auto_ptr<Report> demo(const Report& ps)   // ��ͨ��������������� ����ָ�븳ֵ ɥʧ����Ȩ������
	{
		auto_ptr<Report> temp(new Report(ps));
		return temp;   // ��Ϊ ���������ٵĶ��� ����Ȩû����
	}
};

int main()
{
	{
		std::auto_ptr<Report> ps(new Report("using auto_ptr"));  // ����ָ��Ĺ��췽ʽ ����Ҫ new ��,����ᱻ delete ����
		ps->comment();   // use -> to invoke a member function (ʹ�� -> ���õ��Ǳ�ָ��Ķ���ĳ�Ա��ʹ�� . ���õ��� auto_ptr<type> �Լ��ĳ�Ա)
//   auto_ptr<Report> pReport = ps;   // ��ʹ ps ʧȥ����Ȩ( auto_ptr(����ʱ����)��unique_ptr(���ϸ񣬱���ʱ����) ������)

// ��������Ȩɥʧ��һ���ð취��
		auto_ptr<Report> pReport = ps->demo(*ps);
		cout << *ps << '\t' << *pReport << endl;   // ���õ� << ���������

// auto_ptr<type> ģ���������һЩ��Ա������
		if (pReport.get())  // �пա��ж� pReport ָ��Ķ���ָ���Ƿ�Ϊ ��( get() ��ñ�ָ��Ķ����ָ�� )
		{
			pReport.release();  // �ͷ� ����ָ�� �� ��ָ��Ķ���� �� (�������Ҫ�Լ� delete)
			pReport.reset(new Report("kkkk"));   // ��� ֮ǰָ��Ķ���ָ�����󶨣����°���һ������ָ��
		}
	}
// ��Ҫʹ�ö��ָ��ͬһ�������ָ�� ѡ�� shared_ptr��Ҳ��ʹ�� Boost ���µ� shared_ptr��
	{
        std::shared_ptr<Report> ps (new Report("using shared_ptr"));
        ps->comment();
    }
// ʹ�� new ���� new[] �������ڴ�ʱ��ʹ�� (Ҳ��ʹ�� Boost ���µ� scoped_ptr)  �Ƽ�ʹ��
    {
        std::unique_ptr<Report> ps (new Report("using unique_ptr"));
	//	scoped_ptr<Report> sp(new Report("scoped_ptr"));   // Boost ���µ�
		unique_ptr<Report> ps2;
	//	ps2 = ps;    // ���������Ϊ����ʹ ps ɥʧ����Ȩ 
		ps2 = ps->demo(*ps);

	//	ps2 = move(ps);    // ͨ�� std::move() ������ ps �ƶ����� ps2   ps Ϊ��(���ٸ�ֵ)
		cout << *ps2 << endl;


        ps2->comment();
    }
	system("pause");
    return 0;
}
