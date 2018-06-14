#include <iostream>
#include <algorithm>
#include <string>
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
	string s("Frst,Middle,Last");
	string s1(s), s2(s);

	string::iterator it;
	string::reverse_iterator rit;

	sort(s1.begin(), s1.end());
	//给sor()传递反向迭代器可以反向排序
	sort(s2.rbegin(), s2.rend());

	print(s1);
	print(s2);

	it = find(s.begin(), s.end(), ',');         //第一个逗号
	rit= find(s.rbegin(), s.rend(), ',');       //最后一个逗号

	cout << string(s.begin(), it) << endl;   //打印第一个逗号前的内容
	//反向迭代器的操作都是反向进行的
	cout << string(s.rbegin(), rit) << endl;   //打印最后一个逗号后的内容（反向输出）

	//如果想通过反向迭代器得到最后一个逗号，并正向输出最后一个单词，可以用base()成员函数
	// reverse_iterator的 base() 成员函数返回对应的普通迭代器
	//注意，两个迭代器不指向同一个元素，而是相邻的，此处 rit 指向 ','，而 rit.base() 指向 'L'
	cout << string(rit.base(), s.end()) << endl;


}