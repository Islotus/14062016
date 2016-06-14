 ///
 /// @file    innnerclass.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-13 19:29:49
 ///

//类定义的作用域与可见域
//class defination action scope and visibility scope

//类中类
#include <iostream>
using namespace std;

class line  //line class defination
{
public:
	class point  //point类定义在line类内，且为public属性，外部可以访问
	{
	private:  //point 类内私有成员列表
		int _x;
		int _y;
	public:
		point(int xp = 0, int yp = 0)  //point类构造函数，带缺省参数值
		{
			_x = xp;
			_y = yp;
			cout << "point 类构造函数被调用" << endl;
		}
		void printpoint() const;  //point 类成员函数原型，外部实现
	};
private:
	point p1, p2;  //line 内两个point对象成员
public:
	line(int x1, int y1, int x2, int y2)  //构造函数，初始化表
	:p1(x1, y1)
	,p2(x2, y2)
	{
		cout << "line 类构造函数别调用" << endl;
	}
	void printline() const  //输出提示信息
	{
		p1.printpoint();  //调用对象成员的公共接口
		cout << "------>";
		p2.printpoint();  //调用对象成员的公共接口
		cout << endl;
	}
};

void line::point::printpoint() const  //point类中函数printpoint()的实现，注意双重作用域限定符
{
	cout << "(" << _x << "," << _y << ")";
}

int main()
{
	line line1(1, 2, 3, 4);  //调用line类构造函数，声明一个line类的对象line1
	line1.printline();  //输出提示信息

	line::point pt(1, 3);  //以line::point 访问point类定义，声明一个point类的对象pt
	pt.printpoint();  //输出提示信息

	cout << endl;  //为整齐美观，换行 line feed
	
	return 0;
}

