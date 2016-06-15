 ///
 /// @file    friend_func_operator_overloading.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-14 22:22:23
 ///

//以友元函数形式的运算符重载 friend function mode operator overloading

#include <iostream>
using std::cin;
using std::cout;
using std::endl;


class Complex  //define class Complex
{
public:
	Complex(double r = 0.0, double i = 0.0)  //constructor, band default parameter
	{    //recommend to use initialization list 
		this->_real = r;
		this->_imag = i;
	}	
friend Complex operator +(const Complex &, const Complex &);
			//friend function,addition operator overloading
	friend Complex operator -(const Complex&, const Complex&);
			//friend function, subtraction operator overloading
	friend Complex operator -(const Complex&);
			//friend function, negation operator overloading
	friend Complex operator *(const Complex&, const Complex&);
			//friend function, multiplication operator overloading
	friend Complex operator /(const Complex&, const Complex&);
			//friend function, devision operator overloading
	friend Complex& operator ++(Complex&);
			//friend function, prifix increment operator overloading
	friend Complex operator ++(Complex&,int);
			//friend function, postfix increment operator overloading
	
	void disp() const  //member function,output class Camplex
	{
		cout << this->_real << " + " << "i" << this->_imag << endl;
	}

private:
		double _real;
		double _imag;  //private member,represent real part and imaginary part
};

Complex operator +(const Complex & C1, const Complex & C2)  
		//realize addition operator overloading, friend function
{
	return Complex(C1._real + C2._real, C1._imag + C2._imag);
}
Complex operator -(const Complex& C1, const Complex& C2)
		//realize subtraction operator overloading, frient function
{
	return Complex(C1._real - C2._real, C1._imag - C2._imag);
}
Complex operator -(const Complex& C1)
		//realize negation operator overloading, friend function
{
	return Complex(-C1._real, -C1._imag);
}
Complex operator *(const Complex& C1, const Complex& C2)
		//realize multiplication operator voerloading, friend function
{
	return Complex(C1._real * C2._real - C1._imag * C2._imag, C1._real * C2._imag + C1._imag * C2._real);
}
Complex operator /(const Complex& C1, const Complex& C2)
		//realize division operator overloading, friend function
{
	return Complex((C1._real * C2._real + C1._imag + C2._imag)/(C2._real * C2._real + C2._imag * C2._imag),
			(C1._imag * C2._real - C1._real * C2._imag)/(C2._real * C2._real + C2._imag * C2._imag));
}

Complex& operator ++(Complex& C1)
		//realize prefix increment operator overloading, friend function
{
	cout << "prefix increment operator ++" << endl;
	C1._real += 1;
	C1._imag += 1;
	return C1;
}
Complex operator ++(Complex& C1,int)
		//realize postfix increment operator overloading, friend function
{
	cout << "postfix increment operator ++ " << endl;
	Complex ctemp = C1;
	++C1;
	return ctemp;
}

int main()
{
	Complex cx1(1.0, 2.0);
	Complex cx2(3.0, 4.0);
	Complex cxRes;
	cout<<"cx1: " << endl;
	cx1.disp();
	cout << "cx2: " << endl;
	cx2.disp();

	cxRes = cx1 - cx2;  //相当于operator -(cx1, cx2)
	cout << "cxRes = cx1 - cx2" << endl;
	cxRes.disp();

	cxRes = -cx1;  //相当于operator -(cx1)
	cout << "cxRex = -cx1" << endl;
	cxRes.disp();

	cxRes = cx1 + cx2;  //相当于operator +(cx1,cx2)
	cout << "cxRes = cx1 + cx2" << endl;
	cxRes.disp();

	cxRes = cx1 * cx2;  //相当于operator *(cx1, cx2)
	cout << "cxRes = cx1 * cx2" << endl;
	cxRes.disp();

	cxRes = cx1 / cx2;  //相当于operator /(cx1, cx2)
	cout << "cxRes = cx1 / cx2" << endl;
	cxRes.disp();

	Complex cx3(1.0, 1.0);
	Complex cx4(5.0, 5.0);

	cxRes = ++cx3;  //operator++(cx3)
	cout << "cxRes = ++ cx3" << endl;
	cout << "cxRes: " << endl;
	cxRes.disp();
	cout << "cx3: " << endl;
	cx3.disp();

	cxRes = cx4++;  //相当于operator ++（cx4,0)
	cout << "cxRes = cx4++" << endl;
	cout << "cxRes: " << endl;
	cxRes.disp();
	cout << "cx4: " << endl;
	cx4.disp();

	//注意下述语句在友元函数形式和成员函数形式的对比
	cxRes = cx1 + 5;  //相当于operator +（cx1, 5)
	cout << "cxRes = cx1 + 5" << endl;
	cxRes.disp();

	cxRes = 5 + cx1;  //相当于operator +(5, cx1)
	cout << "cxRes = 5 + cx1" << endl;
	cxRes.disp();
	return 0;


}
 
