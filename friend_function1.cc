 ///
 /// @file    friend_function1.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-13 22:42:37
 ///

//将一个外部函数申明为类的友元函数
#include <cmath>  //使用计算平方根的函数sqrt要用到的头文件
#include <iostream>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class Point  //class definition
{
private:
	int _x;
	int _y;
	friend float dis(Point& p1, Point& p2);  //友元函数的声明（declaration），声明位置没有关系
//	可以使public，也可以是private
public:
	Point(int i = 0, int j = 0)  //constructor，brand default parameter
	:_x(i)
	,_y(j)
	{
		cout << "constructor called " << endl;
	}
	void disp() const  //member function
	{
		cout << "(" << _x << "," << _y << ")";
	}

};
float dis(Point& p1, Point& p2)  //friend function realization
{
	//友元函数可以访问累的private成员
	float d = sqrt((p1._x - p2._x)*(p1._x - p2._x) + (p1._y - p2._y)*(p1._y - p2._y));
	return d;
}

int main()
{
	Point p1(1, 2);
	Point p2(4, 5);  //声明两个Point类的对象p1和p2
	p1.disp();  //显示点p1的信息

	cout << "与";
	p2.disp();  //显示点p2的信息

	cout << "距离 = " << dis(p1, p2) << endl;  //利用友元函数计算两点距离

	return 0;

}
