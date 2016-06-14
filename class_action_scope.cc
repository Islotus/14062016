 ///
 /// @file    class_action_scope.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-13 18:12:28
 ///
//class action scope  类作用域 
#include <iostream>
using namespace std;

int _x = 100;  //定义性声明 defining declaration
int _z = 200;  //defining declaration

class Example  //Example
{
	int _x;  //默认的private的成员列表 /default private member list
	int _y;
public:
	Example(int xp = 0, int yp = 0)  //构造函数
	{
		_x = xp;
		_y = yp;
	}
	void print(int x)  //成员函数print，形参为x  //member function,parameter is x
	{
		cout << "传递来的参数：" << _x << endl;  //形参x覆盖掉了成员_x和全局变量_x
		cout << "成员_x:" << (this ->_x) << ",成员y:" << _y << endl;  //此处的_y指的是成员_y，如果要访问成员_x，可使用指针this
		cout << "除了this指针外，还可以使用类名::的形式：" << endl;
		cout << "成员_x: " << Example::_x <<",成员_y：" << _y << endl;  //或使用类名加作用域限定符的形式指明要访问成员_x
		cout << "全局_x: " << (::_x) << endl;  //访问全局变量_x
		cout << "全局_z: " << _z << endl;  //没有形参、数据成员对全局变量_z构成屏蔽，直接访问_z即可 

	}
};

int main()
{
	Example ex1;  //声明一个Example类的对象ex1
	ex1.print(5);  //invoking member function print()
	return 0;
}
 
