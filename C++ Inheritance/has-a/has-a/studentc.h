// studentc.h -- defining a Student class using containment
#ifndef STUDENTC_H_
#define STUDENTC_H_
						/* has-a 关系实现学生成绩录入情况 在类里包含其他类，易于理解，便于实现    has-a 包含 */

#include <iostream>
#include <string>   
#include <valarray>
class Student
{
private:
	typedef std::valarray<double> ArrayDb;
	std::string name;       // contained object
	ArrayDb scores;         // contained object
	// private method for scores output
	std::ostream & arr_out(std::ostream & os) const;
public:
	Student() : name("Null Student"), scores() {}
	explicit Student(const std::string & s)
		: name(s), scores() {}
	explicit Student(int n) : name("Nully"), scores(n) {}
	Student(const std::string & s, int n)
		: name(s), scores(n) {}
	Student(const std::string & s, const ArrayDb & a)
		: name(s), scores(a) {}
	Student(const char * str, const double * pd, int n)
		:scores(pd, n), name(str) {}   // 构造类对象时，如有继承，先构建继承对象的所有成员  再构造初始化列表里的成员
		// 如是其它类成员，用类名::访问	 初始化列表里的构造顺序: 根据成员声明时的顺序来初始化，而不是根据初始化列表里的顺序
	~Student() {}
	double Average() const;
	const std::string & Name() const;
	double & operator[](int i);
	double operator[](int i) const;
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

#endif
