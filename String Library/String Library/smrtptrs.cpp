// smrtptrs.cpp -- using three kinds of smart pointers
#include "stdafx.h"
#include <memory>    /* 三个智能指针模板类: auto_ptr、unique_ptr、shared_ptr 要使用 需要包含这个头文件 */
// #include <Boost>

using namespace std;       // 这三个智能指针都被 C++11 摒弃
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
	auto_ptr<Report> demo(const Report& ps)   // 可通过这个函数来避免 智能指针赋值 丧失所有权的问题
	{
		auto_ptr<Report> temp(new Report(ps));
		return temp;   // 因为 即将被销毁的对象 所有权没问题
	}
};

int main()
{
	{
		std::auto_ptr<Report> ps(new Report("using auto_ptr"));  // 智能指针的构造方式 必须要 new 的,否则会被 delete 两次
		ps->comment();   // use -> to invoke a member function (使用 -> 调用的是被指向的对象的成员，使用 . 调用的是 auto_ptr<type> 自己的成员)
//   auto_ptr<Report> pReport = ps;   // 会使 ps 失去所有权( auto_ptr(运行时崩溃)、unique_ptr(更严格，编译时崩溃) 会这样)

// 避免所有权丧失的一个好办法：
		auto_ptr<Report> pReport = ps->demo(*ps);
		cout << *ps << '\t' << *pReport << endl;   // 调用的 << 重载运算符

// auto_ptr<type> 模板里的其它一些成员函数：
		if (pReport.get())  // 判空。判断 pReport 指向的对象指针是否为 空( get() 获得被指向的对象的指针 )
		{
			pReport.release();  // 释放 智能指针 与 被指向的对象的 绑定 (解除后，需要自己 delete)
			pReport.reset(new Report("kkkk"));   // 会把 之前指向的对象指针解除绑定，重新绑定另一个对象指针
		}
	}
// 需要使用多个指向同一个对象的指针 选择 shared_ptr（也可使用 Boost 库下的 shared_ptr）
	{
        std::shared_ptr<Report> ps (new Report("using shared_ptr"));
        ps->comment();
    }
// 使用 new 或者 new[] 来分配内存时可使用 (也可使用 Boost 库下的 scoped_ptr)  推荐使用
    {
        std::unique_ptr<Report> ps (new Report("using unique_ptr"));
	//	scoped_ptr<Report> sp(new Report("scoped_ptr"));   // Boost 库下的
		unique_ptr<Report> ps2;
	//	ps2 = ps;    // 编译错误，因为它会使 ps 丧失所有权 
		ps2 = ps->demo(*ps);

	//	ps2 = move(ps);    // 通过 std::move() 函数把 ps 移动到了 ps2   ps 为空(可再赋值)
		cout << *ps2 << endl;


        ps2->comment();
    }
	system("pause");
    return 0;
}
