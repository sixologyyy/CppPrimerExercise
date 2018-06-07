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
	vector<int> v1{ 0,1,2,3,4,5,6 };
	list<char> v2{ 41,42,43,44 };
	vector<int>::iterator it1,it2;

	//插入
	it1 = v1.insert(v1.begin() + 1, 11);           // insert成功后返回插入的第一个新元素的迭代器
	it1 = v1.insert(it1, { 21,22,23 });               // 可以插入{}包含的元素列表
	it1 = v1.insert(v1.end(), 3, 31);                // 插入n个值为t的元素
	it2 = v1.insert(it1, {});                             // 插入失败则返回第一个参数
	if (it1==it2)
		cout << "insert failed" << endl;
	v1.insert(v1.end(), v2.begin(), v2.end());   //插入别的容器中的元素

	for (auto i : v1)
		cout << i << " ";
	cout << endl;

	vector<vector<string>> v3{ {"a"},{"b"},{"c"} };
	//emplace_front，emplace，emplace_back 和 push_front，insert，push_back对应，但参数是传递给构造函数的，构造一个对象后插入
	v3.emplace(v3.begin(), 2, "sb");          //v3里的元素是vector<string>，给它的构造函数传递一个(n,t)的参数，构造一个含有n个t对象的vector<string>，再插入v3
	v3.insert(v3.begin(), vector<string>(2, "sbsb"));        //和上面同样的效果，但是会创建临时对象


	//访问
	v3.at(1);     //和[]一样，at()可以随机访问元素，如果下标越界，at会抛出异常


	//删除
	v3.erase(v3.begin());       //返回删除元素之后的迭代器，注意参数不能用尾后迭代器
	v3.erase(v3.begin(), v3.end());     //第二个参数可以是尾后迭代器（它指向的元素不删除）
	v3.clear();         //与上一行等价


	//调整大小
	v3.resize(5);                //多出来的元素默认初始化
	v3.resize(6, { "n" });      //多出来的元素用第二个参数初始化
	v3.resize(3, { "z" });      //缩小容器，删除多余的，此时第二个参数没用

}

