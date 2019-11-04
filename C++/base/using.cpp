/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：using.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年10月28日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>

int a = 10;

void func()
{
	cout << "func()\n";
}

namespace tt{
	int a;
	void func(){
		cout << "tt::func()\n";
	}
}
/*using tt::a;error---与global a产生冲突*/
int main()
{
	cout << a << endl;
	func();
	
	cout << "-------tt-------\n";
#if 0
	tt::a = 12;
	cout << tt::a << endl;
	tt::func();
#else
	using tt::func;
	using tt::a;
	cout << a << endl;
	func();
#endif
	cout << "--------global--------\n";
	cout << ::a << endl;
	::func();

	return 0;
}
