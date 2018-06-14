#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
using namespace std;

//lambda表达式
//    [ 捕获列表 ] ( 参数 ) ->返回类型 { 函数体 }
//    参数和返回类型可省略，捕获和函数体不能省略

void shortWords(vector<string>& words, vector<string>::size_type sz);
void shortWordsToOstream(vector<string>& words, vector<string>::size_type sz,
												ostream& os = cout, char c = ' ');


bool checkLength(const string& s1, string::size_type sz)
{
	return s1.size() > sz;
}

//例子
//输入一个单词序列，去除重复，按照长度排序，相同长度按字典序排序，最后输出长度小于sz的单词
//因为要用find_if定位到words中特定长度的位置，所以第三个参数要给定参数sz，但无法传入两个参数的函数，利用lambda表达式可以实现
void shortWords(vector<string>& words, vector<string>::size_type sz)
{
	//排序后去重
	sort(words.begin(), words.end());
	auto it = unique(words.begin(), words.end());
	words.erase(it, words.end());

	//按照长度排序，相同长度按字典序排序
	//输入参数是两个string，返回bool（省略）
	stable_sort(words.begin(), words.end(),
						[](const string& s1, const string& s2) 
							{ return s1.size() < s2.size(); });
	
	//获取一个迭代器，指向第一个长度小于sz的string
	//find_if()返回第一个谓词为true的迭代器
	//捕获函数biggies()的局部变量sz，在lambda表达式内使用
	it = find_if(words.begin(), words.end(),
						[sz](const string& s1)
							{ return s1.size() > sz; });

	//长度小于sz的个数
	auto count = it - words.begin();
	cout << count << " word(s) of length " << sz << " or shorter " << endl;

	//打印长度小于sz的单词
	for_each(words.begin(), it,
					[](const string& s1)
						{ cout << s1 << " "; });
	cout << endl;

}

//引用捕获的例子
//让shortWords接受一个ostream引用，和一个字符作为分隔符
void shortWordsToOstream(vector<string>& words, vector<string>::size_type sz,
												ostream& os, char c)
{
	sort(words.begin(), words.end());
	auto it = unique(words.begin(), words.end());
	words.erase(it, words.end());
	stable_sort(words.begin(), words.end(),
						[](const string& s1, const string& s2)
							{ return s1.size() < s2.size(); });
	it = find_if(words.begin(), words.end(),
						[sz](const string& s1)
							{ return s1.size() > sz; });

	//输出部分改为打印到os

	//长度小于sz的个数
	auto count = it - words.begin();
	os << count << " word(s) of length " << sz << " or shorter \n";

	//因为不能拷贝ostream，所以必须用引用捕获
	for_each(words.begin(), it,
					[&os,c](const string& s1)
						{ os << s1 << c; });
	os << '\n';
}

//还可以用bind()实现
//形式为  auto newCallable = bind(callable , args )
void shortWordsBindFunc(vector<string>& words, vector<string>::size_type sz)
{
	sort(words.begin(), words.end());
	auto it = unique(words.begin(), words.end());
	words.erase(it, words.end());
	stable_sort(words.begin(), words.end(),
						[](const string& s1, const string& s2)
							{ return s1.size() < s2.size(); });

	//获取一个迭代器，指向第一个长度小于sz的string
	//用bind()实现
	//bind(callable , args ) 表示args是callable的参数列表，赋给callable后返回一个新函数
	//placeholders::_n 是占位符，指代新函数的第n个参数
	//下面的例子表示把checksz的第一个参数（agrs中用_1指代），和sz，作为 checkLength的参数，调用checksz(const string& s)，等价于checkLength(s,sz)
	auto checksz = bind(checkLength, placeholders::_1, sz);
	it = find_if(words.begin(), words.end(), checksz);
	//bind()不仅可以改变原函数的参数个数，还可以改变参数顺序，如
	// auto g = bind(f, a, b, _2, c, _1);
	//表示调用 g(X, Y) 等价于 调用 f(a, b, Y, c, X);
	//如果要传递引用参数的话，使用 ref(i)，如
	//bind(print, ref(os), _1, ' ');


	auto count = it - words.begin();
	cout << count << " word(s) of length " << sz << " or shorter " << endl;
	for_each(words.begin(), it,
					[](const string& s1)
						{ cout << s1 << " "; });
	cout << endl;
}

int main()
{
	vector<string> v{ "the","quick","red","fox","jumps","over","the","slow","red","turtle" };

	shortWords(v, 3);
	shortWords(v, 4);
	shortWords(v, 5);
	shortWords(v, 6);

	cout << "\nOstream version:\n";
	shortWords(v, 3);
	shortWords(v, 4);
	shortWords(v, 5);
	shortWords(v, 6);
	cout << endl;

	cout << "\nBind version:\n";
	shortWords(v, 3);
	shortWords(v, 4);
	shortWords(v, 5);
	shortWords(v, 6);
	cout << endl;

}

//捕获的时机
void f1()
{
	int v1 = 42;
	auto f = [v1] {return v1; };

	v1 = 0;
	auto j = f();
	//j的值为42，而不是0，因为捕获是在lambda表达式创建的时候拷贝，不是在调用时
}

void f2()
{
	int v1 = 42;
	auto f = [&v1] {return v1; };

	v1 = 0;
	auto j = f();
	//j的值为0，因为捕获的是引用，不是拷贝
}

//指定返回类型
void f3()
{
	vector<int> n{ 1,2,3,4,5,6,7,8 };
	//transform第三个参数为输出位置，可以为原来的容器，第四个参数是谓词
	transform(n.begin(), n.end(), n.begin(), 
						[](int i)->int 
							{ if (i % 2) return -i; else return i; });
}
