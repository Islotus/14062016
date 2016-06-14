 ///
 /// @file    common_function_operator_overloading.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-14 05:50:01
 ///

//普通函数形式的运算符重载
//common function 又叫free function ，operator overloading
//普通函数形式的运算符重载，要求待操作的属性必须是public类型的

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class Complex  //define class Complex
{
	public:
		Complex(double r = 0.0, double i = 0.0)  //constructor，band default parameter
		:_real(r)
		,_imag(i)
		{
			cout << "Complex constructor called" << endl;

		}
		void disp() const  //member function
		{
			cout << _real << " + " << "i*" << _imag << endl;
		}
	
	public:
		double _real;  //real part
		double _imag;  //imaginary part
};

Complex operator + (const Complex& obj1, const Complex& obj2)  //operator + realization
{
	cout << "operator+ function called " << endl;
	return Complex(obj1._real + obj2._real, obj1._imag + obj2._imag);
}

int main()
{
	Complex cx1(1.0, 2.0);
	cx1.disp();
	Complex cx2(3.0, 4.0);
	cx2.disp();
	Complex cxRes;
	cxRes = cx1 + cx2;  //相当于cx1.operator+(cx2);
	cxRes.disp();

	return 0;
}
