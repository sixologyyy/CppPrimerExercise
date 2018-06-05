#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <string>
#include <array>

#include <iostream>

using namespace std;

int main()
{
	//类型成员
	vector<int>::size_type i1;                  //无符号整型，能保存此容器可能的最大的大小
	vector<int>::difference_type i2;        //有符号整型，保存两个迭代器之间的距离
	vector<int>::value_type i3;               //元素类型
	vector<int>::reference i4=i3;           //元素的引用类型
	vector<int>::const_reference i5=i4;

	vector<int> v1{ 1,2,3,4,5 };
	const vector<int> v2{ 1,2,3,4,6 };

	auto it1 = v1.begin();                      // vector<int>::iterator
	auto it2 = v1.cbegin(), it3 = v2.begin(), it4 = v2.cbegin();      // vector<int>::const_iterator


	//构造函数
	char c1[] = { 'a','\0' };
	char c2[] = { 'a','b','\0' };
	char c3[] = { 'a','b','c','\0' };
	char c4[] = { 'a','b','c','d','\0' };

	list<char*> l1;
	list<char*> l2(l1);
	list<char*> l3 = l2;
	list<char*> l4{ c1,c2,c3,c4 };
	list<char*> l5 = { c1,c2,c3,c4 };
	list<char*> l6(l5.begin(), l5.end());
	list<char*> l7(5);
	list<char*> l8(5, c4);

	//如果构造函数用迭代器范围做参数，则可以接受其他容器的迭代器，只要元素可以转换，指向的类型也可以不同
	deque<string> d1(l5.begin(), l5.end());      //把list里面的char*给deque的string


	//array
	array<int, 10> a1{1,1,1,1,1,1,1,1,1,1};    //array必须指定大小
	array<int, 10> a2;
	a2 = a1;                 //array支持赋值


	//赋值和swap
	l1 = { c4,c3,c2,c1 };
	l1.swap(l4);
	swap(l1, l3);

	d1.assign({ "1","2","3" });
	d1.assign(10, "bs");
	//assign的迭代器参数同样支持不同类型的元素
	d1.assign(l1.begin(), l1.end());     //把list里的char*赋给deque里的string


	//比较
	v1 = { 1,2,3,4,5 };
	deque<int> d2 = { 1,2,3 };
	deque<int> d3 = { 1,2,3,4,7 };
	//通过构造函数构造临时量来比较不同容器的元素
	cout << (vector<int>(d2.begin(), d2.end()) < v1 ? "true" : "false") << endl;
	cout << (vector<int>(d3.begin(), d3.end()) < v1 ? "true" : "false") << endl;

}

