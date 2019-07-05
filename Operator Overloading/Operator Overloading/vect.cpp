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
//	sin(angle) 对边比斜边  angle为角度，得出 angle 的正弦值     原型: double sin(double _X);
//	cos(angle) 邻边比斜边  angle为角度，得出 angle 的余弦值     原型: double cos(double _X);
//	tan(angle) 对边比邻边  angle为角度，得出 angle 的正切值     原型: double tan(double _X);
//	atan(angle) 对边比邻边  angle为角度，得出 angle 的反正切值     原型: double sin(double _X);
//	atan2(angle) 对边比邻边  angle为角度，得出 angle 的正弦值     原型: double atan2(double _Y, double _X);
//
//		tan(angle) = sin(angle) / cos(angle)   正切 = 正弦 / 余弦
//	0度始边与终边重合，交点坐标为（1,0）	  则sin0°=0，cos0°=1，tan0°=0
//	90°的终边与单位圆的交点坐标为（0,1）	  则sin90°=1，cos90°=0，tan90°没意义
//	180°角的终边与单位圆交点坐标为（-1,0）	  则sin180°=0，cos180°=-1，tan180°=0
//
//	角度转弧度 π/180×角度 == 弧度
//	弧度变角度 180/π×弧度 == 角度
//*/
//namespace VECTOR
//{
//	
//    // compute degrees in one radian
//    const double Rad_to_deg = 45.0 / atan(1.0);   // atan(1.0)*180/PI == 角度    Rad_to_deg == 180/PI  返回值 弧度转化为角度
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
//            ang = atan2(y, x);  // atan2(y,x)求的是y/x的反正切  返回值为[ -pi,+pi ]之间的值
//    }
//
//    // set x from polar coordinate
//    void Vector::set_x()
//    {
//        x = mag * cos(ang);  // 通过 正弦值、余弦值定理 与 随机得到的角度 来求得 x、y 的坐标
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
//             ang = n2 / Rad_to_deg;   // 得到弧度
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
