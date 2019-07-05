// worker0.h  -- working classes
#ifndef WORKER0_H_
#define WORKER0_H_
/* ���� --> ���� --> ���� <-- ���� <-- ����  (����Ϊͬһ��) 
	���������:
	һ�����ĸ��࣬�����ĸ���Ĺ�ͬ���Է���������������ϰ���Ϊ�����࣬���������Ա���̳��������й�ͬ�����������֤��(�����ϰ�������)��
	����Ա�з���ȵ�����(���ڷ���Ա��)��������ɤ���ĵȼ�����(���ڸ�����)��Ȼ����ÿ������ʵ�ֶ������Լ���Ա�����ķ����������ϰ��������
	���������֤�ŵĹ��졢���롢���������Ա����ķ���ȵ����������(��Ӧ�ȵ�������������������)�����������ɤ���ȼ����������(Ҳ����
	�ȵ������������������������������Լ����������������) ����������ĳ�Ա������Ϊ�麯����������̳��Լ�ʵ��

	���ڹ��캯����������ֻ��ʵ�ֶ��Լ����Ա����Ĺ��캯����������Ĺ��캯�������Ȱ�ͨ���βεõ���ֵ�����������࣬���������Լ�

	��������������ֻ������������������ ��Ϊ���麯������ȥ�����������в���Ҫ��������
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
