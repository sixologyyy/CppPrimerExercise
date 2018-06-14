#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <iterator>

using namespace std;

template<typename Sequence>
void print(Sequence const& seq)
{
	for (const auto& i : seq)
		cout << i << " ";
	cout << endl;
}

int main()
{
	vector<int> v1;

	//istream_iterator
	istream_iterator<int> inIter1(cin);         //从cin读取int的迭代器
	istream_iterator<int> inEOF1;               //空的迭代器，可以当做尾后迭代器使用
	while (inIter1 != inEOF1)
		v1.push_back(*inIter1++);                   //获取当前输入，并递增

	//直接用迭代器范围构造
	istream_iterator<int> inIter2(cin);         //从cin读取int的迭代器
	istream_iterator<int> inEOF2;               //空的迭代器，可以当做尾后迭代器使用
	vector<int> v2(inIter2, inEOF2);
	
	//ostream_iterator
	ostream_iterator<int> outIter(cout, " ");    //第二个参数是一个c风格字符串，输出每个元素之后都会输出此字符串
	for (auto o : v1)
		*outIter++ = o;     //也可以写成 outIter=o;
	cout << endl;

	//直接调用copy()
	copy(v1.begin(), v1.end(), outIter);
	cout << endl;

}