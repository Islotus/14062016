 ///
 /// @file    frie_class.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-14 04:26:43
 ///

//友元类 friend class


#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

class CLine;  //declare clss CLine

class CPoint  //define class CPoint
{

friend class CLine;  //友元类的声明，位置同样不受限制
public:
	CPoint(int i = 0, int j = 0)  //构造函数，带缺省参数值
	:_x(i)
	,_y(j)
	{
		cout << "class CPoint constructor called " << endl;
	}
	void disp() const  //member function，output information about point
	{
		cout << "(" << _x
			 << "," << _y
			 << ")";
	}

private:
	int _x;
	int _y;
};

class CLine  //类CLine的定义，其中所有的函数都是CPoint类的友元函数
{
public:
	float dis(const CPoint& p1,const CPoint& p2)  //可以访问p1和p2的private成员
	{
		return sqrt((p1._x - p2._x)*(p1._x - p2._x)
				  + (p1._y - p2._y)*(p1._y - p2._y));
	}
	void Set(CPoint* p1, int a, int b)  //可访问p1和p2的private成员
	{
		p1 -> _x = a;
		p1 -> _y = b;
	}

};

int main()
{
	CLine cz1;  //declare object of class CLine
	CPoint p1(1, 2);  //declare p1 object of class CPoint
	CPoint p2(4, 5);  //declare p2 object of class CPoint

	p1.disp();  //output information of p1 object
	cout << "and";  
	p2.disp();  //output information of p2 object
	cout << "distance = " << cz1.dis(p1,p2) << endl;  //call member function of cz1, compute distance
	cout << "distance = " << cz1.dis(CPoint(1, 2), CPoint(4, 5)) << endl;

	cz1.Set(&p1, 3, 4);  //调用cz1的成员函数Set改写p1中的private成员_x和_y
	p1.disp();  //after change,output infor of p1

	cout << endl;
	return 0;
}
