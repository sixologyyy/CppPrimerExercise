#include <string>
#include <vector>
#include <fstream>
using namespace std;

//读取一个文件，每一行存在vector中
void ReadFileLineToVec(const string& fileName, vector<string>& vec)
{
	ifstream infile(fileName);
	if (infile)
	{
		string buf;
		while (getline(infile, buf))
			vec.push_back(buf);
	}
}

//读取一个文件，每个单词存在vector中
void ReadFileWordToVec(const string& fileName, vector<string>& vec)
{
	ifstream infile(fileName);
	if (infile)
	{
		string buf;
		while (infile >> buf)
			vec.push_back(buf);
	}
}

int main()
{
	ofstream outfile("file1");                                                         //隐含以输出模式打开，并截断文件
	ofstream outfile("file1",ofstream::out);                                    //隐含地截断文件
	ofstream outfile("file1", ofstream::out | ofstream::trunc);         //显式截断

	ofstream outfile("file1", ofstream::app);                                  //必须显式指定app模式才能变为追加模式，保留之前内容
	ofstream outfile("file1", ofstream::out | ofstream::app);          //上一行隐含了输出模式

	outfile.close();
}