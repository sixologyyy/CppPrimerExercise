#include <iostream>
using namespace std;

using arrT = int[10];     //别名

int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
int b[10] = { -1,-2,-3,-4,-5,-6,-7,-8,-9,-10 };
int c[10] = { 11,12,13,14,15,16,17,18,19,20 };
int def[10] = { 0 };

int ( *fun1(char ch) ) [10]     //返回数组指针
{
	int (*parr)[10];
	if (ch=='a')
	{
		parr = &a;
	}
	else if (ch == 'b')
	{
		parr = &b;
	}
	else if (ch == 'c')
	{
		parr = &c;
	}
	else
	{
		parr = &def;
	}
	return parr;
}

arrT* fun2(char ch)     //用别名替代复杂写法
{
	int(*parr)[10];
	if (ch == 'a')
	{
		parr = &a;
	}
	else if (ch == 'b')
	{
		parr = &b;
	}
	else if (ch == 'c')
	{
		parr = &c;
	}
	else
	{
		parr = &def;
	}
	return parr;
}

auto fun3(char ch) -> int(*) [10]     //c++11 尾置返回类型
{
	int(*parr)[10];
	if (ch == 'a')
	{
		parr = &a;
	}
	else if (ch == 'b')
	{
		parr = &b;
	}
	else if (ch == 'c')
	{
		parr = &c;
	}
	else
	{
		parr = &def;
	}
	return parr;
}

decltype(def)* fun4(char ch)      //已知返回类型，用decltype推断。若不加*则返回的是数组，编译报错
{
	int(*parr)[10];
	if (ch == 'a')
	{
		parr = &a;
	}
	else if (ch == 'b')
	{
		parr = &b;
	}
	else if (ch == 'c')
	{
		parr = &c;
	}
	else
	{
		parr = &def;
	}
	return parr;
}

int main()
{
	cout << (*fun1('a'))[1] << endl;
	cout << (*fun2('b'))[2] << endl;
	cout << (*fun3('c'))[3] << endl;
	cout << (*fun4('~'))[4] << endl;
}