//// randwalk.cpp -- using the Vector class
//// compile with the vect.cpp file'
///*
//	�����·���⣺
//	���� �Զ���ľ��� �� ���� ͨ������ķ��� ��������Ҫ���ٲ������ߵ��յ� (���Ϊ��ȷ��ֵ)
//	�ó� ��ֱ��������յ�� x��yֵ   ������� ���� �� ����  
//	�����ߵ� ���� �� �ߵ��ܾ��� �ó�ƽ��ÿ���ߵľ���
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
//    unsigned long steps = 0;    // �ܵĲ���
//    double target;			// �ܵľ���
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
//            step.reset(dstep, direction, Vector::POL);   // �������õĲ��� �� ����ĽǶ� �õ� ��Ӧ�Ļ��� �� ���ߵĳ���
//            result = result + step;
//            steps++;
//        }
//        cout << "After " << steps << " steps, the subject "
//            "has the following location:\n";
//        cout << result << endl;				// ֱ������ x��y ֱ�Ǳߵĳ���
//        result.polar_mode();
//        cout << " or\n" << result << endl;   // ������ ���ȡ�����
//        cout << "Average outward distance per step = "
//            << result.magval()/steps << endl;   // �����ܹ��ߵľ��� ���� �ܵĲ��� �õ�ƽ��ÿ���ߵĳ���
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
