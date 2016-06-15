 ///
 /// @file    subscript_operator_overloading.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-15 04:23:03
 ///

//下标运算符 subscript operator overloading
//下标运算符是个二元运算符，C++编译器将表达式sz[x];解释为sz.operator [](z);
//一般情况下，下标运算符的重载函数原型如下：
//放回类型& operator [](参数类型)
//下标运算符的重载函数只能有一个参数，不过该参数没有类型限制，任何类型都可以，
//如果类中未重载下标运算符，编译器将会给出下标运算符的缺省定义，此时，参数必须是int
//型，并且要声明数组名才能使用下标变量，


#include <iostream>
#include <string.h>
using std::cin;
using std::cout;
using std::endl;

class CharSZ  //define class Charsz
{
public:
	CharSZ(int size)  //constructor
	:_iLen(size)
	{
		_pBuf = new char[_iLen];  //开辟一块动态内存，字符数组
		cout << "constructor called" << endl;
	}
	~CharSZ()  //destructor
	{
		delete _pBuf;  //释放申请的动态内存
	}
	int GetLen()  //读取private成员_iLen的值
	{
		return _iLen;
	}
	char& operator [](int i);  //以成员函数形式重载下标运算符
		//subscript operator overloading, member function

private:  //private member list
	int _iLen;
	char* _pBuf;
};

char& CharSZ::operator [](int i)  //realize subscript operator overloading
{
	static char szNull = '\0';
	if(i < _iLen && i >= 0)  //如果参数i在有效范围内
	{
		return _pBuf[i];  //返回字符数组的第i+1个元素  //就可以对这个字符进行操作了
	}else {
		cout << "下标越界" << endl;  //参数i不合法
		return szNull;  //输出空字符.不能直接return '\0'；
	}
}

int main()
{
	const char* sz = "hello, world!";
	CharSZ de(strlen(sz) + 1);  //对象de 中申请的动态内存大小为n，可以存放n-1个有效字符（除开'\0'）

	//将sz的内容复制给de
	int i;
	for(i = 0; i < (strlen(sz)); ++i)
	{
		de[i] = sz[i];
	}

	//逐个输出de的值
	for(i = 0; i < de.GetLen(); ++i)
	{
		cout << de[i];
	}
	cout << endl;

	return 0;
}
