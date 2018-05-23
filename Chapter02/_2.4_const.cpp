#include <iostream>
using namespace std;
int main()
{
	int i = 5;
	const int j = 10;

	int &ri = i;
	//int &ri2 = 5;    //错误，引用不能绑定右值
	int *pi = &i;
	int *&rp = pi;

	const int a = i;
	const int b = 3.14;    //强制类型转换

	//const引用
	const int &c = i;
	const int &d = j;
	const int &ee = 3.14;  //强制类型转换
	int &e = i;
	//int &f = j;    //错误，int& 不能绑定const int，有修改常量的企图

	//const指针
	const int *g = &i;
	const int *h = &j;
	const int *const k = &j;
	int *l = &i;
	//int *m = &j;   //错误，int* 不能指向const int，有修改常量的企图
	const int *n;
	//int *const o;   //错误，指针常量必须设初值，指向常量的指针不必

	//顶层、底层const
	int ii = 0;
	const int ai = 0;     //顶层，对象本身不能修改
	int *const p1 = &ii;  //顶层

	const int *p2;       //底层，指向的对象不能修改
	const int &bi = ai;  //底层

	const int *const p3 = &ii;  //左边底层，右边顶层

	int jj = ai;   //顶层可以被非const拷贝
	
	//int &ci = ai;   //错误，底层不能被非const拷贝，有修改的企图
	p2 = &ai;     //底层只能拷给底层
	p2 = &ii;
	p2 = p3;   //p3的顶层可以被拷贝，同时p2、p3都有底层属性;


	return 0;
}