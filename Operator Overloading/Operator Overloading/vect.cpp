//// vect.cpp -- methods for the Vector class
#include "stdafx.h"
//#include <cmath>
//#include "vect.h"   // includes <iostream>
//using std::sqrt;
//using std::sin;
//using std::cos;
//using std::tan;
//using std::atan;
//using std::atan2;
//using std::cout;
//
///*
//	sin(angle) �Ա߱�б��  angleΪ�Ƕȣ��ó� angle ������ֵ     ԭ��: double sin(double _X);
//	cos(angle) �ڱ߱�б��  angleΪ�Ƕȣ��ó� angle ������ֵ     ԭ��: double cos(double _X);
//	tan(angle) �Ա߱��ڱ�  angleΪ�Ƕȣ��ó� angle ������ֵ     ԭ��: double tan(double _X);
//	atan(angle) �Ա߱��ڱ�  angleΪ�Ƕȣ��ó� angle �ķ�����ֵ     ԭ��: double sin(double _X);
//	atan2(angle) �Ա߱��ڱ�  angleΪ�Ƕȣ��ó� angle ������ֵ     ԭ��: double atan2(double _Y, double _X);
//
//		tan(angle) = sin(angle) / cos(angle)   ���� = ���� / ����
//	0��ʼ�����ձ��غϣ���������Ϊ��1,0��	  ��sin0��=0��cos0��=1��tan0��=0
//	90����ձ��뵥λԲ�Ľ�������Ϊ��0,1��	  ��sin90��=1��cos90��=0��tan90��û����
//	180��ǵ��ձ��뵥λԲ��������Ϊ��-1,0��	  ��sin180��=0��cos180��=-1��tan180��=0
//
//	�Ƕ�ת���� ��/180���Ƕ� == ����
//	���ȱ�Ƕ� 180/�С����� == �Ƕ�
//*/
//namespace VECTOR
//{
//	
//    // compute degrees in one radian
//    const double Rad_to_deg = 45.0 / atan(1.0);   // atan(1.0)*180/PI == �Ƕ�    Rad_to_deg == 180/PI  ����ֵ ����ת��Ϊ�Ƕ�
//
//    // should be about 57.2957795130823
//
//    // private methods
//    // calculates magnitude from x and y
//    void Vector::set_mag()
//    {
//        mag = sqrt(x * x + y * y);
//    }
//
//    void Vector::set_ang()
//    {
//        if (x == 0.0 && y == 0.0)
//            ang = 0.0;
//        else
//            ang = atan2(y, x);  // atan2(y,x)�����y/x�ķ�����  ����ֵΪ[ -pi,+pi ]֮���ֵ
//    }
//
//    // set x from polar coordinate
//    void Vector::set_x()
//    {
//        x = mag * cos(ang);  // ͨ�� ����ֵ������ֵ���� �� ����õ��ĽǶ� ����� x��y ������
//    }
//
//    // set y from polar coordinate
//    void Vector::set_y()
//    {
//        y = mag * sin(ang);
//    }
//
//    // public methods
//    Vector::Vector()             // default constructor
//    {
//        x = y = mag = ang = 0.0;
//        mode = RECT;
//    }
//
//    // construct vector from rectangular coordinates if form is r
//    // (the default) or else from polar coordinates if form is p
//    Vector::Vector(double n1, double n2, Mode form)
//    {
//        mode = form;
//        if (form == RECT)
//         {
//             x = n1;
//             y = n2;
//             set_mag();
//             set_ang();
//        }
//        else if (form == POL)
//        {
//             mag = n1;
//             ang = n2 / Rad_to_deg;   // �õ�����
//             set_x();
//             set_y();
//        }
//        else
//        {
//             cout << "Incorrect 3rd argument to Vector() -- ";
//             cout << "vector set to 0\n";
//             x = y = mag = ang = 0.0;
//             mode = RECT;
//        }
//    }
//
//    // reset vector from rectangular coordinates if form is
//    // RECT (the default) or else from polar coordinates if
//    // form is POL
//    void Vector:: reset(double n1, double n2, Mode form)
//    {
//        mode = form;
//        if (form == RECT)
//         {
//             x = n1;
//             y = n2;
//             set_mag();
//             set_ang();
//        }
//        else if (form == POL)
//        {
//             mag = n1;
//             ang = n2 / Rad_to_deg;
//             set_x();
//             set_y();
//        }
//        else
//        {
//             cout << "Incorrect 3rd argument to Vector() -- ";
//             cout << "vector set to 0\n";
//             x = y = mag = ang = 0.0;
//             mode = RECT;
//        }
//    }
//
//    Vector::~Vector()    // destructor
//    {
//    }
//
//    void Vector::polar_mode()    // set to polar mode
//    {
//        mode = POL;
//    }
//
//    void Vector::rect_mode()     // set to rectangular mode
//    {
//        mode = RECT;
//    }
//
//    // operator overloading
//    // add two Vectors
//    Vector Vector::operator+(const Vector & b) const
//    {
//        return Vector(x + b.x, y + b.y);
//    }
//
//    // subtract Vector b from a
//    Vector Vector::operator-(const Vector & b) const
//    {
//        return Vector(x - b.x, y - b.y);
//    }
//
//    // reverse sign of Vector
//    Vector Vector::operator-() const
//    {
//        return Vector(-x, -y);
//    }
//
//    // multiply vector by n
//    Vector Vector::operator*(double n) const
//    {
//        return Vector(n * x, n * y);
//    }
//
//    // friend methods
//    // multiply n by Vector a
//    Vector operator*(double n, const Vector & a)
//    {
//        return a * n;
//    }
//
//    // display rectangular coordinates if mode is RECT,
//    // else display polar coordinates if mode is POL
//    std::ostream & operator<<(std::ostream & os, const Vector & v)
//    {
//        if (v.mode == Vector::RECT)
//             os << "(x,y) = (" << v.x << ", " << v.y << ")";
//        else if (v.mode == Vector::POL)
//        {
//             os << "(m,a) = (" << v.mag << ", "
//                 << v.ang * Rad_to_deg << ")";
//        }
//        else
//             os << "Vector object mode is invalid";
//        return os; 
//    }
//
//}  // end namespace VECTOR
