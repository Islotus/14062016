 ///
 /// @file    block_scope.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-13 22:07:10
 ///

//块作用域 block scope

#include <iostream>
using namespace std;

int main()
{
	void Work(int, int);  //Work函数原型声明
	Work(5, 6);  //Work function called;
	return 0;

}

void Work(int a, int b)
{
	class point  //类定义在函数内，在函数外无法使用point创建对象
	{
	private:
		int _x;
		int _y;
	public:
		point(int xp = 0, int yp = 0)
		{
			_x = xp;
			_y = yp;
			cout << "constructor called" << endl;
		}
		void print() const
		{
			cout << _x << "," << _y << endl;
		}
	};
	
	point pt(a, b);  //函数内，创建point类的对象pt
	pt.print();  //输出提示信息
}
