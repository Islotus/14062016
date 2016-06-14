 ///
 /// @file    friend_function2.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-14 03:34:00
 ///

//友元之成员函数
//将Line类的成员函数dis()作为Point类的友元函数
#include <iostream>
#include <cmath>  //使用计算平方根的函数sqrt要用到的头文件

using std::cin;
using std::cout;
using std::endl;

class Point;  //declaration Point class

class Line  //definition Line class
{
public:
	 float dis(const Point & p1, const Point & p2);	//友元函数的原型，作为Line类的成员函数
};

class Point  //definition class Point
{
friend float Line::dis(const Point & p1, const Point & p2);  //友元的声明
public:
	Point(int i = 0, int j = 0)  //class Point's constructor,band default parameter
	:_x(i)
	,_y(j)
	{
		cout << "Point class constructor called" << endl;
	}
	void disp() const  //member function，output information about Point
	{
		cout << "(" << _x
			 << "," << _y
			 << ")";
	}

private:  //private data member
	int _x;
	int _y;
};

 //Line类内成员函数dis的实现，作为Point类的友元函数
float Line::dis(const Point & p1, const Point & p2)
{
	float d = sqrt((p1._x - p2._x)*(p1._x - p2._x)
			+ (p1._y - p2._y)*(p1._y - p2._y));
	//可访问Point类对象的private成员
	return d;
}

int main()  //这次不创建两个Point 对象，直接由Point类来计算距离
{
	Line line1;  //声明一个Line类的对象line1
//	Point p1(1, 2);
//	Point p2(4, 5);  //声明两个Point类对象pt1,和pt2

//	p1.disp();  //输出点p1的信息
//	cout << "与";
//	p2.disp();  //输出点p2的信息

	cout << " 的距离 = " << line1.dis(Point(1, 2), Point(4, 5)) << endl;
	//通过调用line1的成员函数dis计算两个点间距离
	
	return 0;
}
