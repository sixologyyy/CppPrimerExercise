#include <iostream>
#include <vector>
#include <string>
#include <iterator>
using namespace std;
int main()
{
	int aa[5] = { 9,8,7,6,5 };
	int a[3][5] = { 1,2,3,4,5  ,6,7,8,9,0  ,2,4,6,8,0 };
	int b[2][3][4] = { 0 };

	//范围for访问二维数组
	for (auto &row : a)               //数组名可以范围for
	{
		for (auto &col : row)
			cout << col;
		cout << endl;
	}
	cout << endl;
	//for (auto row : a)                 //错误，如果不用引用，编译器会把数组名自动转换为指针，指针是没有begin和end的，不能范围for
		//for (auto col : row)

	for (auto p = begin(a); p != end(a); ++p)     //int (*p)[5]
	{
		for (auto q = begin(*p); q != end(*p); ++q)   //int *q
			cout << *q;
		cout << endl;
	}
	cout << endl;

	//用指针数组访问二维数组。同样的，指针不能范围for
	int *parr[3];
	parr[0] = a[0];
	parr[1] = aa;
	parr[2] = b[1][2];
	for (int i = 0; i < 3; ++i)
	{
		cout << parr[i][0] << parr[i][1] << parr[i][2];
		cout << endl;
	}	
	cout << endl;

	//数组指针
	int(*pa)[5] = &aa;     //数组指针指向数组，所以要取数组的地址，数组地址&aa与数组首元素地址（即数组名）数值相等，但是意义不同，比如解引用的时候
	cout << "pa = " << pa << endl;                //pa=&aa=&&aa[0]
	cout << "*pa = " << *pa << endl;             //*pa=aa=&aa[0]
	cout << "**pa = " << **pa << endl;          //**pa=a[0]
	cout << endl;

	//int **pp=a;             //错误，a是int *[5]，不能转换为int **
	pa = a;     //pa指向a[3][5]的第一行
	cout << "pa = " << pa << endl;                //pa=a=&a[0]
	cout << "*pa = " << *pa << endl;             //*pa=*a=a[0]=&a[0][0]
	cout << "**pa = " << **pa << endl;          //**pa=**a=*a[0]=a[0][0]
	cout << endl;

	cout << "pa+1 = " << pa + 1 << endl;         //pa+1=&a[1]=a的地址+20
	cout << "*pa+1 = " << *pa + 1 << endl;         //*pa+1=&a[0][0]+1=&a[0][1]=a的地址+4
	cout << "*(pa+1) = " << *(pa+1) << endl;          //*(pa+1)=*&a[1]=&a[1][0]=a的地址+20
	cout << "**(pa+1) = " << **(pa + 1) << endl;          //**(pa+1)=**&a[1]=a[1][0]
	cout << "*(*pa+1) = " << *(*pa + 1) << endl;          //*(*pa+1)=*(&a[0][0]+1)=*&a[0][1]=a[0][1]
		

	return 0;
}