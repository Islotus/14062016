 ///
 /// @file    pointer_operator_overloading.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-15 06:32:49
 ///

//-> 操作符重载

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class CData  
{
public:
	int GetLen()
	{
		return 5;
	}
};

class CDataPtr
{
public:
	CDataPtr()
	{
		_m_pData = new CData;
	}
	~CDataPtr()
	{
		delete _m_pData;
	}

	CData* operator ->()
	{
		cout << "-> 操作符重载函数被调用。" << endl;
		return _m_pData;
	}

//public:
	private:
	 CData* _m_pData;

};

int main()
{
	CDataPtr p;
	cout << p->GetLen() << endl;  //等价于下面1句
	cout << (p.operator ->())->GetLen() << endl;

//	p._m_pData->GetLen();

	return 0;
}
