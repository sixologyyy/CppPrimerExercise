#include <iostream>
using namespace std;
int main()
{

	//typedef
	typedef char *pchar;   //pchar的基本数据类型是指针
	const pchar p = new char('3');   //p是常量指针，不是指向指针的常量，不应该简单地把typedef展开来阅读（即const char *p）
	char *q = "hello";
	//p = q;     //错误，不能给常量赋值
	*p = '*';    //正确，说明指向的不是常量
	const pchar *pc;     //pc是指向 常量指针(const pchar) 的指针

	//auto
	int a = 3;
	double b = 3.14;
	auto c = a + b;   //double c
	auto aa = a, *pa = &a;
	//auto d = a, e = b;    //错误，前后类型不一致

	int &ra = a;
	auto f = a;    //int f，对于引用，推断的类型跟随引用的本体
	
	const int ca = a, &cr = ca;
	auto g = ca;   //int g，忽略顶层const
	auto h = cr;   //int h，忽略引用和顶层const

	auto i = &a;   //int *i
	auto j = &ca;  //const int *j，保留底层const

	const auto k = ca;   //const int k，保留顶层const需要显式声明

	auto &l = a;
	auto &m = ca;   //const int &m，保留底层const
	//auto &n = 42;   //错误，引用不能绑右值

	//decltype
	const int n = 0, &cn = n, *pn = &n;
	decltype(n) x = 0;     //const int x，包含顶层const属性
	decltype(cn) y = x;    //const int &y，包含引用和顶层const属性

	decltype(cn + 0) z;    //int z，因为括号里是表达式（右值），结果为int
	constexpr int ce = n + 0;
	decltype(ce) z1 = 0;;   //const int z1，因为ce是一个常量表达式

	int r = 0, &rr = r, *pr = &r;
	int *const cpr = &r;
	decltype(*pr) w1 = r;   //int &w1，因为*pr表达式的结果是一个左值，返回引用类型
	decltype(*pn) w2=n;   //const int &w2，返回引用类型，且保留const
	decltype(cpr) w3 = &r;  //int *const w3
	decltype(cpr + 0) w4;    //int *w4

	decltype(r) u1=r;       //int u1;
	decltype((r)) u2= r;   //int &u2，注意，变量加括号得到的一定是引用，因为变量加括号变成了左值，比如(r) = 5是合理的
	decltype(rr) u3 = r;   //int &u3，不加括号的变量取决于变量自身是不是引用
	decltype(r = 5) u4 = r;   //int &u4，r=5的类型是 int &


	return 0;
}