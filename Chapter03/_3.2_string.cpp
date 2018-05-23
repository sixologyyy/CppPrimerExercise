#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s1;
	string s2 = "hello";
	string s3("world");
	string s4 = s2;
	string s5(s3);
	string s6(10, 'c');
	string s7 = string("fuc");

	auto t = s2.size();  //size_t类型

	s4 = s2 + s3;
	s5 = s2 + "sxy" + '!';
	s6 = "sxy" + s3;
	//s7 = "sxy" + "yyy" + s3;    //错误，"sxy" + "yyy"两侧都没有string对象
	s7 = "sxy" + s2 + "yyy" + "zzz" + "!!!";   //正确，每次调用加号时，两边至少有一个string

	//用范围for循环遍历string
	for (auto c : s7)
		if (c != 'y')
			cout << c;
	cout << endl;

	for (auto &c : s7)
		if (c == 'y')
			c -= 32;
	cout << s7 << endl;

	return 0;
}