 ///
 /// @file    new_delete_operator_overloading.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-15 05:03:50
 ///

//new 和 delete 运算符重载
//new和delete只能重载为类的静态运算符。而且重载时，无论是否显示指定static关键字，
//编译器都认为是静态的运算符重载函数

//重载new是，必须返回一个void*类型的指针，它可以带多个参数，但第1个参数必须是size_t类型，该类型的值由系统确定
//重载delete时必须返回void类型，它可以带有多个参数，第一个参数必须是要释放的内存的地址void*,如果有第二个参数，
//它必须为size_t类型

#include <iostream>
#include <string.h>

using namespace std;
#if 0
using std::cin;
using std::cout;
using std::endl;
#endif

class CStudent
{
public:
	static void* operator new(size_t nSize)
	{
		cout << "new operator called, size = " << nSize << endl;
		void* _pRet = new char[nSize];
		return _pRet;
	}
	static void operator delete(void* pVoid)
	{
		cout << "delete operator called." << endl;
		delete []pVoid;
	}

public:
	int _ild;
	char _szName[10];
};

int main()
{
	CStudent* pStu = new CStudent();

	pStu->_ild = 101;
	strcpy(pStu->_szName,"Tony");

	delete pStu;
	return 0;
}

