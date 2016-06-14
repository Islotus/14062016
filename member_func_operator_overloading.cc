 ///
 /// @file    member_func_operator_overloading.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-14 06:41:24
 ///

//成员函数形式的运算符重载
//member function mode operator overloading

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class Complex  //difine class Complex
{
public:
	Complex(double r = 0.0, double i = 0.0)  //constructor,band default parameter
	:_real(r)
	,_imag(i)
	{
//		cout << "class Complex constructor called" << endl;
	}
	Complex & operator +=(const Complex &); 
			//member function form addition and assignment operator overloading +=
	Complex operator +(const Complex &);  
			//member function form addition operator overloading +
	Complex operator -(const Complex &);  
			//member function form decrement operator overloading -
	Complex operator -();
			//member function form negation operator overloading -
	Complex operator *(const Complex &);
			//member function form multiplicative operator overloading *
	Complex operator /(const Complex &);
			//member function form division operator overloading /
	
	Complex & operator ++();
			//member function form prefix increment operator overloading ++
	Complex operator ++(int);
			//member function form postfix increment operator overloading ++
	void disp() const  //member function,output Complex
	{
		cout << _real << " + " << "i*" << _imag << endl;
	}

private:
	double _real;  //private member,real part
	double _imag;  //private member, imaginary part
};

Complex & Complex::operator +=(const Complex& CC)  //realize addition and assignment operator overloading
{
	this->_real += CC._real;
	this->_imag += CC._imag;
	return (*this);
}
Complex Complex::operator +(const Complex& CC)  //realize addition opetator overloading
{
	return Complex(this->_real + CC._real, this->_imag + CC._imag); 
}
Complex Complex::operator -(const Complex& CC)  //realize subtraction operator overloading
{
	return Complex(this->_real - CC._real, this->_imag - CC._imag);
}
Complex Complex::operator *(const Complex& CC)  //realize multiplicative operator overloading
{
	return Complex(this->_real * CC._real - this->_imag * CC._imag,
					this->_real * CC._imag + this->_imag * CC._real);
}
Complex Complex::operator /(const Complex& CC)  //realize division operator overloading
{
	return Complex((this->_real * CC._real + this->_imag * CC._imag)/(CC._real * CC._real + CC._imag * CC._imag),
					(this->_imag * CC._real - this->_real * CC._imag)/(CC._real * CC._real + CC._imag * CC._imag));
}
Complex Complex::operator -()  //realize negation operator overloading
{
	return Complex(-this->_real, -this->_imag);
}
#if 0
Complex & Complex::operator -()  //realize negation operator overloading
{
	this->_real = this->_real * (-1);
	this->_imag = this->_imag * (-1);
	return (*this);
}
#endif 
Complex & Complex::operator ++()  //realize prifix increment operator overloading
{
	cout << "prifix increment(++) operator overloading" << endl;
	++ this->_real;
	++ this->_imag;
	return (*this);
}
Complex Complex::operator ++(int)  //realize postfix increment operator overloading
{
	cout << "postfix increment(++) operator overloading" << endl;
	Complex cTemp = (*this);  //最终返回的是原来的值，因此需要先保存原来的值
	++(*this);  //返回后原来的值需要加1
	return cTemp;
}

int main()
{
	Complex cx1(1.0, 2.0);
	cout << "cx1: " << endl;
	cx1.disp();
	Complex cx2(3.0, 4.0);
	cout << "cx2: " << endl;
	cx2.disp();
	Complex cxRes;

	cxRes += cx2;  //相当于cxRes.operator +=(cx2)
	cout << "cxRes += cx2" << endl;
	cxRes.disp();

	cxRes = cx1 + cx2;  //相当于cx1.operator +(cx2)
	cout << "cxRes = cx1 + cx2" << endl;
	cxRes.disp();

	cxRes = cx1 - cx2;  //相当于cx1.operator -(cx2)
	cout << "cxRes = cx1 - cx2" << endl;
	cxRes.disp();

	cxRes = cx1 * cx2;  //相当于cx1.operator *(cx2)
	cout << "cxRes = cx1 * cx2" << endl;
	cxRes.disp();

	cxRes = cx1 / cx2;  //相当于cx1.operator /(cx2)
	cout << "cxRes = cx1 / cx2" << endl;
	cxRes.disp();

	cxRes = -cx1;  //相当于cx1.operator -()
	cout << "cxRes = -cx1" << endl;
	cxRes.disp();

	cout << endl;

	Complex cx3(1.0, 1.0);
	cout << "cx3: " << endl;
	cx3.disp();
	Complex cx4(5.0, 5.0);
	cout << "cx4 :" << endl;
	cx4.disp();

	cxRes = ++cx3;  //相当于cx3.operator ++()
	cout << "cxRes = ++cx3 " << endl;
	cxRes.disp();
	cout << "cx3: " << endl;
	cx3.disp();

	cout << endl;

	cxRes = cx4++;  //相当于cx4.operator ++(0)
	cout << "cxRes = cx4++" << endl;
	cxRes.disp();
	cout << "cx4: " << endl;
	cx4.disp();

	cout << endl;

	//注意下述语句在友元函数形式和成员函数形式中的对比。
	cxRes = cx1 + 5;  //相当于cx1.operator + (5) 或cx1.operator +(complex(5))
	cxRes.disp();

//	cxRes = 5 + cx1;  //错误。相当于5.operator +(cx1)
//	cxRes.disp();

	return 0;
}


