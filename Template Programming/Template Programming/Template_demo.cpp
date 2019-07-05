// Template_demo.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<string>

using namespace std;

/*
//������������������ֵ
void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

//�����뽻�������ַ�����ֵ��
void swap(string& s1, string& s2)
{
    string ss = s1;
    s1 = s2;
    s2 = ss;
}
*/

//��������double������ ����������������...
//ÿ����ʵ��һ������������ --- ��Щ����������ʵ�ֵķ�ʽ����һ����
//----�� ��Ч

//---�� ʹ��ģ����ʵ���������
template<typename T>  //��������ĺ�������һ��ģ�庯���� T �����Ǵ�������
                      //T ��Ϊģ�����
        //��Щ�Ƚ��ϵĽ̲ģ�д���� template<class T> ....
        //��������ʹ��class �ķ�ʽ��typename ���±�׼��class ��ģ�嶨��ʱ�����ض����÷�
void swap(T &a, T &b)
{
    //д��������һ����ֻ�Ǳ�������ʹ�� T ���滻
    // --> T ��һ����������������
    // --> ���õ�ʱ�������ʲô���ͣ����Զ�����һ����Ӧ���͵ĺ����������ǵ���
    cout << "MySwap ..." << endl;
    T tmp = a;
    a = b;
    b = tmp;
}

//��������Ǵ�������������ж�������ǿ���ʹ�ö��T
template <typename T1, typename T2>
void PrintKeyValue(T1 &key, T2 &value)
{
    cout << "K-V: " << key << " -> " << value << endl;
}



class AAA{
private:
    int x;
    int y;
public:
    AAA() :x(0), y(0){}
    AAA(int a, int b) :x(a), y(b){}
    friend ostream& operator << (ostream& os, const AAA &A)
    {
        os << "(" << A.x << "," << A.y << ")";

        return os;
    }
};

void TestTemplate()
{
    int a = 10;
    int b = 20;

    //��std::swap��: �����غ����ĵ��ò���ȷ	
    // std ��������ռ��У�Ҳ������ swap ���������������Ѿ�ʹ����std ��������ռ�
    // --������ swap ���������壺����swap����֪��������һ��
    // --> ��ô�����
    //    --> ���������򣡣���
    //       --> ʹ�� std �����swap    --�� std::swap
    //       --> ʹ�� �ļ��ж����swap  --�� ::swap
    std::swap(a, b);
    cout << "(a, b) = (" << a << "," << b << ")" << endl << endl;

    ::swap(a, b); //�����Լ������swap
    cout << "(a, b) = (" << a << "," << b << ")" << endl << endl;

    string s1("ABCD");
    string s2("1234");
    ::swap<string>(s1, s2); //������ʾָ�� string ���ͣ�Ҳ����ʡ��
    cout << "(s1,s2) = (" << s1 << "," << s2 << ")" << endl << endl;

    AAA A1;
    AAA A2(1, 2);
    ::swap(A1, A2);
    //cout << A1;  --> cout ������������غ���(<<) ����� os����, A1 ��Ӧ��������� A����
    cout << "A1:" << A1 << endl;
    cout << "A2:" << A2 << endl << endl;

    //���� ��� swap ���ǳ�֮Ϊ ģ�庯�� (����ģ��)
    //--��ģ�庯������һ�������ĺ������޷����� .o �ļ�
    //    һ������������ռ�ö��ռ䣬��ȷ����
    // --�����ǵ���ģ�庯����ʱ�� ---�� �����������ƥ�䣬�Զ�����һ�����ڵľ��庯��
    //     ���þ��庯�����������ǵ�����
}

//�����࣬ͬ���ģ�����Ҳ����д��ģ�����ʽ (�ڲ��ı������ʹ���)
template <typename T1, typename T2>
class BBB
{
private:
    T1 x;
    T2 y;
public:
    BBB(T1 a, T2 b) :x(a), y(b){  }

    //���� �������� << 
    //���� << �Ķ����� os ��������Ҫ���� BBB ��˽�г�Ա
    // --�� ���ԣ�������Ҫʹ�� friend
    friend ostream& operator << (ostream &os, const BBB B)
    {
        os << "Class 0:";
        os << "(" << B.x << "," << B.y << ")";
        return os;
    }
};

void TestBBB()
{
    //error C2955: ��BBB��: ʹ�� �� ģ�� ��Ҫ ģ�� �����б�
    //���ﲻ��ʹ�� BBB �����ɶ���
    //  Ϊʲô�� --��BBB ��һ����ģ�壬���Ǿ�����࣬ ���ܹ����ɶ���
    //  --> ��Ҫʹ��ģ������б�����һ��������
    //     --��ģ�庯������ǰ�������������֪�ģ�������Զ��Ƶ������ɺ���(����ʡ��ģ�����)
    //     --��ģ���� ���ɶ����ʱ���������ָ�������࣬����֪��Ҫ�����ĸ����캯��
    //BBB<int, int>   -->ָ�������б� template<typename T1, typename T2> ����
    //                   T1 �� int�� T2 Ҳ�� int
    // ---�� ���� BBB<int, int> ����һ��������� ��ͨ��ģ���������ɵģ�
    //       ͨ��ָ�� ģ����� --������һ��������
    //���ǿ��������ָ�� T1,T2 ������ʲô�������ͣ�
    //   ָ����ͬ�Ĳ������ͣ��ͻ����ɲ�ͬ�� ������
    BBB<int, int>    B1(1, 2);     //ʹ�� BBB<int, int> �࣬���� B1����
    BBB<int, string> B2(3, "ABC");

    //���� B1, B2 �ı��������ǲ�һ���ģ�����������������
    cout << "B1:" << B1 << endl;
    cout << "B2:" << B2 << endl;

}


template <typename T>
const T& Max(const T& a, const T& b)
{
    return a > b ? a : b;
}

template<>  //��������һ��ģ�庯��  
            //--����֮Ϊ ƫ�ػ��� ģ�庯��������������⴦��
            //-->����ģ�庯����ʱ�����ȵ��ø���ƥ��ĺ���
const string& Max(const string& a, const string& b)
{
    return a.length() > b.length() ? a : b;
}

void TestMax()
{
    //error C2440: ��return��: �޷��ӡ�const int��ת��Ϊ��int &��
    //����Max(10,20)��ʱ����θ�ֵ  const int& a = 10, const int& b = 10
    //   -->�����ǲ���ֱ�Ӹ�ֵ��  (ֻ���ñ������и�ֵ[����])
    //cout << "Max(10, 20): "<< Max(10, 20) << endl;
    int x = 10;
    int y = 20;
    cout << "Max(10, 20): " << Max(x, y) << endl;

    double d1 = 1.1;
    double d2 = 1.2;
    cout << "Max(1.1, 1.2): " << Max(d1, d2) << endl;

    string s1 = "ABCD";
    string s2 = "Abc";
    cout << "Max(\"ABCD\", \"Abc\"): " << Max(s1, s2) << endl;

    //--> �ַ����Ƚϴ�С������ַ��Ƚ� ASCII �룬������һ�Բ���ȵ��ַ�
    //    ������һ���ַ��ıȽϽ�� ��Ҳ���ֵ�Ƚϣ�
    
    //�µ����⣺������ǱȽ��ַ�����ʱ���� �Գ��Ƚ��бȽ� ��
    //           Max(s1, s2)  ���� �����ַ���
    //---�� ʹ�ú�����ƫ�ػ��������ģ��������⴦��
}

//ͬ���ģ�����Ҳ���Զ�ģ�������ƫ�ػ�. ���� CCC, ������ģ����� T1��T2
template <typename T1, typename T2>
class CCC
{
private:
    T1 x;
    T2 y;
public:
    CCC(T1 a, T2 b) :x(a), y(b){}

    //���� �������� << 
    //���� << �Ķ����� os ��������Ҫ���� BBB ��˽�г�Ա
    // --�� ���ԣ�������Ҫʹ�� friend
    friend ostream& operator << (ostream &os, const CCC C)
    {
        os << "Class 0-";
        os << "(" << C.x << "," << C.y << ")";
        return os;
    }
};

//ƫ�ػ�1�� �ڶ���ģ������� int �����
//          ֻ�ܴӺ��濪ʼ�������ڶ��� ������ε�Ĭ��ֵ
template<typename T>
class CCC<T, int>       //����ƫ�ػ������� : ����ƫ�ػ���ʱ�򣬰�ƫ�ػ����Ǹ����ͣ��ŵ� <> ���沿��
{
private:
    T     x;
    int   y;
public:
    CCC(T a, int b) :x(a), y(b){}
    friend ostream& operator << (ostream &os, const CCC &C)
    {
        os << "Class 1-";
        os << "(" << C.x << ", " << C.y << ")";
        return os;
    }
};

//ƫ�ػ�2������ģ���������������һ��
template<typename T>
class CCC<T, T>   // <T, T> ��������ػ�������T����һ��
{
private:
    T x;
    T y;
public:
    CCC(T a, T b) :x(a), y(b){}
    friend ostream& operator << (ostream &os, const CCC &C)
    {
        os << "Class 2-";
        os << "(" << C.x << ", " << C.y << ")";
        return os;
    }
};

//ƫ�ػ�3�����Ӿ����ƫ�ػ�--���� ģ�����Ͷ��� int
template<>
class CCC<int, int>
{
private:
    int x;
    int y;
public:
    CCC(int a, int b) :x(a), y(b){}
    friend ostream& operator << (ostream &os, const CCC &C)
    {
        os << "Class 3-";
        os << "(" << C.x << ", " << C.y << ")";
        return os;
    }
};

void TestSpecial()
{
    CCC<int, string>     C1(123, "ABC"); //û��ƫ�ػ�
    CCC<string, int>     C2("Hello", 12);  //�ڶ����� int ��ƫ�ػ�
    CCC<double, double>  C3(1.1, 2.2);        //��������һ����ƫ�ػ�
    CCC<string, string>  C4("Hello", "World"); //��������һ����ƫ�ػ�

    //error C2752 : ��CCC<int, int>�� : �������ר�û���ģ������б�ƥ��
    CCC<int, int>        C5(1, 2); //��ƥ�� CCC<T,int> Ҳƥ�� CCC<T,T>
                                   //�����壬�������޷�����
    //--->����취������һ�����Ӿ���� ƫ�ػ� CCC<int, int>
    // ƫ�ػ������ȼ���Խ����ģ����ȼ�Խ��
 
    cout << "C1:" << C1 << endl;
    cout << "C2:" << C2 << endl;
    cout << "C3:" << C3 << endl;
    cout << "C4:" << C4 << endl;
    cout << "C5:" << C5 << endl;

}

int _tmain(int argc, _TCHAR* argv[])
{
    //TestTemplate();

    //TestBBB();

    //TestMax();

    TestSpecial();

    system("pause");
	return 0;
}

