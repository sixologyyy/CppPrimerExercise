#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <utility>
using namespace std;

struct A
{
	int n;
	char c;
};

bool compare(const A& x1, const A& x2)
{
	return x1.c < x2.c;
}

//pair
pair<string, int> process(vector<string>& v)
{
	if (!v.empty())
		return make_pair(v.back(), v.back().size());
	else
		return pair<string, int>();
}

int main()
{
	vector<int> v{ 0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9 };

	set<int> s(v.begin(), v.end());
	multiset<int> ms(v.begin(), v.end());

	cout << s.size() << " " << ms.size() << endl;

	A x1{ 1,'n' }, x2{ 4,'c' }, x3{ 3,'d' }, x4{ 7,'a' };
	vector<A> v1{ x1,x2,x3,x4 };

	//对于自定义类型的set，要给定比较函数，即在<>中指出【函数指针的类型】，并向构造函数传递一个函数指针
	typedef bool(*pCmpType)(const A& x1, const A& x2);        //<>中必须是函数指针类型，所以要typedef，否则只是个指针
	pCmpType pCmp = &compare;
	multiset<A, pCmpType> ms1(pCmp);                            //空容器，只给了比较函数
	// ms1(pCmp) 也可以是 ms1(compare) 或者 ms1(&compare)
	//回顾关于函数指针的知识，上面的定义语句还可以等价为
	//multiset<A, bool(*)(const A& x1, const A& x2)> ms1(compare);
	//multiset<A, decltype(compare)*> ms1(compare);       //decltype返回的类型要加*
	ms1.insert(x1);
	ms1.insert(x2);
	ms1.insert(x3);
	
	//有初值的容器，第三个参数是比较函数
	multiset<A, decltype(compare)*> ms2(v1.begin(),v1.end(),compare);
	ms2.insert(x1);
	ms2.insert(x2);

	//pair
	vector<string> vv{ "abc","de","fg","h","ijk" };
	auto p = process(vv);
	cout << p.first << " " << p.second << endl;

	return 0;

}