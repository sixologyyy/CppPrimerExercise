#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;

//存储人名和若干个电话号码
struct PersonInfo
{
	string name;
	vector<string> phoneNumbers;
};

vector<string> ValidHead{ "13","15","17","18" };

bool valid(const string& num)
{
	if (num.size() != 11)
		return false;
	//检查num的开头是不是指定开头
	vector<string>::iterator it = find(ValidHead.begin(), ValidHead.end(), num.substr(0, 2));
	if (it == ValidHead.end())
		return false;
	else
		return true;
}

string format(const string& num)
{
	return string(num).insert(3,1,'-').insert(8,1,'-');
}

int main()
{
	string line, word;
	vector<PersonInfo> people;

	while (getline(cin, line))
	{
		PersonInfo info;
		//用istringstream处理一行的数据，包含人名和数量不同的电话号码
		istringstream record(line);
		record >> info.name;
		while (record >> word)
			info.phoneNumbers.push_back(word);
		people.push_back(info);
	}

	for (const auto& entry : people)   //遍历people
	{
		ostringstream formatted, badNums;                 //formatted存入格式化的电话号码，badNums存非法号码
		for (const auto& nums : entry.phoneNumbers)    //遍历一个人的电话号码
		{
			if (!valid(nums))
			{
				badNums << " " << nums;
			}
			else
			{
				formatted << " " << format(nums);
			}
		}
		//所有号码都有效的人才输出格式化号码，否则输出错误号码
		if (badNums.str().empty())
			cout << entry.name << " "
			<< formatted.str() << endl;
		else
			cerr << "input error: " << entry.name
			<< "\ninvalid number(s):" << badNums.str() << endl;
	}
}