 ///
 /// @file    object_creation1.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-13 22:26:59
 ///
//对象创建要注意的问题：object creation
//1.先定义，后实例化  first，definition，then,instantiation
//
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class point;  //声明 declaration
//point ptA;  //Error，类对象的创建必须在类定义之后，因为该语句需要调用构造函数
point* pB = NULL;  //RIGHT
//point* pC = new point();  //Error,因为new语句会调用构造函数

class point
{
private:
	int _x;
	int _y;
public:
	point(int ix = 0, int iy = 0)
	:_x(ix)
	,_y(iy)
	{
		cout << "constructor called" << endl;
	}
};

int main()
{
	return 0;
}
