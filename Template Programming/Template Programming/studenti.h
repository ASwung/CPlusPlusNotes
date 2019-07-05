// studenti.h -- defining a Student class using private inheritance
#ifndef STUDENTC_H_
#define STUDENTC_H_
					/* is-a 关系 实现学生分数录入情况   is-a 表示私有继承的方式 多重继承，子类中不创建成员 抽象化 不易理解 */
#include <iostream>
#include <valarray>
#include <string>   
class Student : private std::string, private std::valarray<double>
{   

/*  using 声明修改访问权限 (只适用于继承)
	public: 
		using std::valarray<double>::min;
		using std::valarray<double>::min;
		using std::valarray<double>::size;
		using std::valarray<double>::sum;
		
	// 因为 valarray<double> 是私有继承，所以 valarray<double>类中的 方法为私有的
		可通过此方式，在子类外调用 valarray<double> 的这些方法   注： using 声明只是用函数名，没有圆括号、返回类型什么的

		另一种在类外调用基类方法的方式：在子类定义一个使用基类方法的函数，在类外通过对象来调用这个函数，相当于间接的调用了
		基类的方法
*/
private:
    typedef std::valarray<double> ArrayDb;
    // private method for scores output
    std::ostream & arr_out(std::ostream & os) const;
public:
    Student() : std::string("Null Student"), ArrayDb() {}
    explicit Student(const std::string & s)
            : std::string(s), ArrayDb() {}
    explicit Student(int n) : std::string("Nully"), ArrayDb(n) {}
    Student(const std::string & s, int n)
            : std::string(s), ArrayDb(n) {}
    Student(const std::string & s, const ArrayDb & a)
            : std::string(s), ArrayDb(a) {}
    Student(const char * str, const double * pd, int n)
            : std::string(str), ArrayDb(pd, n) {}
    ~Student() {}
    double Average() const;
    double & operator[](int i);
    double operator[](int i) const;
    const std::string & Name() const;
// friends
    // input
    friend std::istream & operator>>(std::istream & is,
                                     Student & stu);  // 1 word
    friend std::istream & getline(std::istream & is,
                                  Student & stu);     // 1 line
    // output
    friend std::ostream & operator<<(std::ostream & os,
                                     const Student & stu);
};
//白班： 15 17 21 22 29
//夜班: 10 14 24 28
#endif
