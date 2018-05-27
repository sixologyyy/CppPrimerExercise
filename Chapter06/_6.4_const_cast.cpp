#include <iostream>
#include <string>
using namespace std;

const string& shorterString(const string& s1, const string& s2)
{
	return s1.size() <= s2.size() ? s1 : s2;
}

string& shorterString(string& s1, string& s2)      //当实参不是常量时，希望返回值也不是常量的引用，通过const_cast和处理常量的函数来间接实现
{
	auto& stemp = shorterString(const_cast<const string&>(s1), const_cast<const string&>(s2));
	return const_cast<string&>(stemp);
}

int main()
{
	//shorterString("av", "bs").push_back('0');      //错误，返回的是const引用，不能调用非const成员函数
	cout << shorterString("av", "bs") << endl;

	string s1 = "wsxedc", s2 = "1qaz";
	string &s3 = shorterString(s1, s2);
	s3 += "2wsx";
	cout << s2 << " " << s3 << endl;
}