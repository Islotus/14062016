 ///
 /// @file    input_output_stream_overloading.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-15 05:44:10
 ///

//>>和<<运算符只能重载为友元函数形式
//对操作符<<的重载
//friend ostream& operator <<(ostream& os, Complex& C1)
//{
//	os << C1._real << "+i*" << C1._imag << endl;
//	return os;
//}
//
//对操作符>>的重载
//friend istream& operator >>(istream& is, Complex& C1)
//{
//	is >> C1._real
//	while(is.get() != '*')
//	cin >> C1._imag;
//	return is;
//}

#include <iostream>
#include <fstream> 
using namespace std;

//解决VC6.0中友元方式重载运算符时，无法访问类私有成员和出现内部编译错误的方法：
//	在类定义之前将类和友元操作符函数的原型提前声明一下。

class Complex;
ostream& operator <<(ostream& os, Complex& C1);  //对操作符<< 的重载
istream& operator >>(istream& is, Complex& C1);

class Complex
{
public:
	Complex(double r = 0.0, double i = 0.0)  //constructor
	:_real(r)
	,_imag(i)
	{
		cout << "constructor called" << endl;
	}
	friend ostream& operator <<(ostream&, Complex&);  //declare friend function
	friend istream& operator >>(istream&, Complex&);

private:
	double _imag;  //imaginary part
	double _real;  //real part
};

ostream& operator <<(ostream& os, Complex& C1)  //<< operator overloading
{
	os << C1._real << "+i*" << C1._imag << endl;
	return os;
}

istream& operator >>(istream& is, Complex& C1)  //>> operator overloading
{
	is >> C1._real;
	while(is.get() != '*')
	{
	}
	is >> C1._imag;
	return is;
}

int main()
{
	Complex c1(2.5, 3.1);
	cin >> c1;
	cout << c1;
	return 0;
}
