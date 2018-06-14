#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool isShorter(const string& s1, const string& s2)
{
	return s1.size() < s2.size();
}

bool shorterThan4(const string& s1)
{
	return s1.size() < 4;
}

int main()
{
	vector<string> v{ "the","quick","red","fox","jumps","over","the","slow","red","turtle" };

	//排序后去重
	sort(v.begin(), v.end());
	auto it = unique(v.begin(), v.end());
	v.erase(it, v.end());

	cout << "v : ";
	for (auto i : v)
		cout << i << " ";
	cout << endl;

	vector<string> v2(v), v3(v), v4(v);
	//按照长度排序，第三个参数称为谓词，是可调用的表达式，返回一个条件
	sort(v2.begin(), v2.end(), isShorter);
	cout << "sort : ";
	for (auto i : v2)
		cout << i << " ";
	cout << endl;
	//稳定排序，在此例中相同长度的字符串排序前后的相对顺序不变，所以保证了先按长度排序，长度相同时按字典序牌
	stable_sort(v3.begin(), v3.end(), isShorter);
	cout << "stable sort : ";
	for (auto i : v3)
		cout << i << " ";
	cout << endl;

	//partition()，谓词判断为true的排在前面，返回指向前半部分的尾后迭代器
	it = partition(v4.begin(), v4.end(), shorterThan4);
	cout << "length <4 in v4 : ";
	for (auto i = v4.begin(); i != it; ++i)
		cout << *i << " ";
	cout << endl;
	cout << "length >=4 in v4 : ";
	for (auto i = it; i != v4.end(); ++i)
		cout << *i << " ";
	cout << endl;

	//find_if()，返回第一个使谓词为true的迭代器
	it = find_if(v.begin(), v.end(), shorterThan4);
	cout << "first string shorter than 4 words at v : " << it - v.begin() << endl;

}