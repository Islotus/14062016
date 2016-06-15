 ///
 /// @file    assignment_operator_overloading.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-15 01:17:17
 ///

//assignment operator overloading,
//赋值运算符重载，如果没有，执行时会出错

#include <iostream>
#include <string.h>
using std::cin;
using std::cout;
using std::endl;

class computer
{
public:
	computer()  //default parameter constructor
	{  //recommend to use initialization list
		this->_brand = NULL;
		this->_price = 0;
		cout << "default constructor called" << endl;
	}
	computer(const char* sz, float p)  //band 2 parameter constructor
	{	//recommend to use initialization list
		this->_brand = new char[strlen(sz) + 1];
		strcpy(_brand, sz);
		_price = p;
		cout << "band 2 parameter constructor called" << endl;
	}
	computer(const computer& cp)  //copy constructor 
	{
		this->_brand = new char[strlen(cp._brand) + 1];
		strcpy(this->_brand, cp._brand);
		this->_price = cp._price;
		cout << "copy constructor called" << endl;
	}

#if 0
	//如果我们没有重载=，则系统会隐式的重载成如下形式
	computer operator =(const computer& cp)
	{
		this->_price = cp._price;
		this->_brand = cp._brand;
		cout << "system default assignment operator overloading function called" << endl;
		return (*this);
	}
#endif
#if 1
	//应该使用下述函数取代上述系统隐式的定义
	computer& operator =(const computer& cp)  
		//member function mode assignment operator overloading
	{
		if(this == &cp)  //首先判断是否是自赋值
			return (*this);
		this->_price = cp._price;
		delete [] this->_brand;  //prevent memory leak
		this->_brand = new char[strlen(cp._brand) + 1];  //为this->_brand重新开辟空间
		if(this->_brand != NULL)  //如果开辟成功
		{
			strcpy(this->_brand, cp._brand);  //copy string
		}
		cout << "assignment operator overloading function called" << endl;
		return (*this);  //返回当前对象的引用，为的是实现链式赋值
	}
#endif
	~computer()  //destructor，释放动态内存，delete [] NULL不会出错
	{
		delete [] this->_brand;  //recommend:this->_brand = NULL;
		cout << "destructor called" << endl;
	}
	void print() const  //member function, output class computer
	{
		cout << "brand: " << this->_brand << endl;
		cout << "price: " << this->_price << endl;
	}

private:
	char* _brand;  
	float _price;
};
 
int main()
{
	computer com1("Dell",200);  //call band-parameter constructor, declare object com1
	computer com2 = com1;  //call copy constructor

	if(true)
	{
		computer com3;  //call non-parameter constructor
		com3 = com1;  //assignment operator overloading 
	}

	return 0;
}

