 ///
 /// @file    function_call_operator_overloading.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-15 02:00:05
 ///

//函数调用运算符重载 function call operator overloading
//函数调用运算符重载，只能重载为成员函数形式。其形式为：返回值类型 operator ()(arg1,arg2,...)
//参数个数可以有多个，没有限制。
//一个类如果重载了函数调用operator()，就可以将该类对象作为一个函数使用，这样的类对象也称为函数对象。
//函数也是一种对象，这是泛型思考问题的方式。

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class Demo  //define class Demo,  demo:演示，展示
{
public:
	double operator ()(double x, double y)  //重载函数调用运算符(),两个double型参数
	{
		return x > y ? x : y;  //返回两个参数中较大的一个
	}
	double operator ()(double x, double y, double z)  //重载函数调用运算符(),3个double型参数
	{
		return (x + y) * z;  //
	}
};

int main()
{
	Demo de;  //declare object of class Demo
	cout << de(2.5, 0.2) << endl;  //可以将对象像函数一样使用
	cout << de(1.2, 1.5, 7.0) << endl;
	return 0;
}

