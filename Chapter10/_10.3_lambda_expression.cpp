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

//lambda表达式
//    [ 捕获列表 ] ( 参数 ) ->返回类型 { 函数体 }
//    参数和返回类型可省略，捕获和函数体不能省略

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

	stable_sort(v2.begin(), v2.end(),
		[](const string& s1, const string& s2) {return s1.size() < s2.size(); });
	cout << "sorted v2 : ";
	for (auto i : v2)
		cout << i << " ";
	cout << endl;

}