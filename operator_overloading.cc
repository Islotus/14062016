 ///
 /// @file    operator_overloading.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-14 05:21:10
 ///

//运算符重载的必要性

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
		cout << "constructor called" << endl;
	}
	void disp() const  //member function，output complex
	{
		if(this -> _real > 0)
		{
			if(this -> _imag > 0)
			{
				cout << this -> _real << " + " << this -> _imag << "i" << endl;
			}else if(this -> _imag < 0)
			{
				cout << this -> _real << " - " << (this ->_imag)*(-1) << "i" << endl;
			}else if(this -> _imag ==0)
			{
				cout << this -> _real << endl;
			}
		}else if(this -> _real < 0)
		{
			if(this -> _imag > 0)
			{
				cout << " - " << (this -> _real)*(-1) << " + " << this -> _imag << "i" << endl;
			}else if(this -> _imag < 0)
			{
				cout << " - " << (this -> _real)*(-1) << " - " << (this ->_imag)*(-1) << "i" << endl;
			}else if(this -> _imag ==0)
			{
				cout << " - " << (this -> _real)*(-1) << endl;
			}

		}else if(this -> _real == 0)
		{
			if(this -> _imag > 0)
			{
				cout << " + " << this -> _imag << "i" << endl;
			}else if(this -> _imag < 0)
			{
				cout << " - " << (this ->_imag)*(-1) << "i" << endl;
			}else if(this -> _imag ==0)
			{
				cout << " 0 " << endl;
			}
		}
	}
private:
	double _real;
	double _imag;//private member,分别代表着实部和虚部（real part / imaginary part）
};

int main()
{
	Complex cx1(1.0, 2.0);
	Complex cx2(3.0, 4.0);
//	Complex cxRes = cx1 + cx2;  //错误

	return 0;

}

