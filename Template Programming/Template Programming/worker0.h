// worker0.h  -- working classes
#ifndef WORKER0_H_
#define WORKER0_H_
/* 子类 --> 父类 --> 祖先 <-- 父类 <-- 子类  (子类为同一个) 
	这个类的设计:
	一共有四个类，把这四个类的共同属性放在祖先类里，比如上班族为祖先类，歌手与服务员都继承自它，有共同的名字与身份证号(放在上班族类里)，
	服务员有服务度的属性(放在服务员类)，歌手有嗓音的等级属性(放在歌手类)，然后在每个类里实现对他们自己成员操作的方法，比如上班族类里的
	姓名与身份证号的构造、输入、输出，服务员类里的服务度的设置与输出(但应先调用祖先类的输入与输出)，歌手类里的嗓音等级设置与输出(也必须
	先调用祖先类里的输入与输出，再来对自己的类属性输入输出) 把祖先类里的成员函数设为虚函数，让子类继承以及实现

	关于构造函数，祖先类只需实现对自己类成员构造的构造函数，而子类的构造函数，需先把通过形参得到的值来构造祖先类，再来构造自己

	关于析构函数，只需把祖先类的析构函数 设为纯虚函数，再去析构，子类中不需要析构函数
*/
#include <string>

class Worker    // an abstract base class
{
private:
    std::string fullname;
    long id;
public:
    Worker() : fullname("no one"), id(0L) {}
	Worker(const std::string & s, long n)
            : fullname(s), id(n) {}
    virtual ~Worker() = 0;   // pure virtual destructor
    virtual void Set();
    virtual void Show() const;
};

class Waiter : virtual public Worker
{
private:
    int panache;
public:
    Waiter() : Worker(), panache(0) {}
    Waiter(const std::string & s, long n, int p = 0)
            : Worker(s, n), panache(p) {}
    /*Waiter(const Worker & wk, int p = 0)
            : Worker(wk), panache(p) {}*/
    void Set();
    void Show() const;
};

class Singer :  public virtual Worker
{
protected:
    enum {other, alto, contralto, soprano,
                    bass, baritone, tenor};
    enum {Vtypes = 7};
private:
    static char *pv[Vtypes];    // string equivs of voice types
    int voice;
public:
    Singer() : Worker(), voice(other) {}
    Singer(const std::string & s, long n, int v = other)
            : Worker(s, n), voice(v) {}
 /*   Singer(const Worker & wk, int v = other)
            : Worker(wk), voice(v) {}*/
    void Set();
    void Show() const;
};

class SingingWaiter: public Singer,public Waiter
{
public:
	SingingWaiter(){}
	SingingWaiter(const std::string& str,long id,int v,int p):Worker(str,id),Waiter(str,id,p),Singer(str,id,v){}

	~SingingWaiter();

private:

};

SingingWaiter::SingingWaiter()
{
}

SingingWaiter::~SingingWaiter()
{
}
#endif
