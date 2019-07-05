//// randwalk.cpp -- using the Vector class
//// compile with the vect.cpp file'
///*
//	醉鬼走路问题：
//	根据 自定义的距离 与 步长 通过随机的方向 来计算需要多少步才能走到终点 (结果为不确定值)
//	得出 其直角坐标的终点的 x、y值   极坐标的 长度 与 方向  
//	根据走的 步数 与 走的总距离 得出平均每步走的距离
//*/
#include "stdafx.h"
//#include <iostream>
//#include <cstdlib>      // rand(), srand() prototypes
//#include <ctime>        // time() prototype
//#include "vect.h"
//int main()
//{
//    using namespace std;
//    using VECTOR::Vector;
//    srand((unsigned int)time(0));     // seed random-number generator
//    double direction;
//    Vector step;
//    Vector result(0.0, 0.0);
//    unsigned long steps = 0;    // 总的步数
//    double target;			// 总的距离
//    double dstep;
//	double value = sin(45);
//    cout << "Enter target distance (q to quit): ";
//    while (cin >> target)
//    {
//        cout << "Enter step length: ";
//        if (!(cin >> dstep))
//            break;
//
//        while (result.magval() < target)
//        {
//            direction = rand() % 360;
//            step.reset(dstep, direction, Vector::POL);   // 根据设置的步长 与 随机的角度 得到 对应的弧度 与 行走的长度
//            result = result + step;
//            steps++;
//        }
//        cout << "After " << steps << " steps, the subject "
//            "has the following location:\n";
//        cout << result << endl;				// 直角坐标 x、y 直角边的长度
//        result.polar_mode();
//        cout << " or\n" << result << endl;   // 极坐标 长度、方向
//        cout << "Average outward distance per step = "
//            << result.magval()/steps << endl;   // 根据总共走的距离 除以 总的步数 得到平均每步走的长度
//        steps = 0;
//        result.reset(0.0, 0.0);
//        cout << "Enter target distance (q to quit): ";
//    }
//    cout << "Bye!\n";
///* keep window open
//    cin.clear();
//    while (cin.get() != '\n')
//        continue;
//    cin.get();
//*/
//    return 0; 
//}
