/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：mutable.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年10月28日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>

struct STU {
	mutable int x;
	int y;
};

int main()
{
	const STU stu = {1,2};
	stu.x = 10;

	cout << stu.x << endl;
	return 0;
}
