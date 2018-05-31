#include <iostream>
#include <string>

using namespace std;

istream& func(istream &is)
{
	int buf;
	while (is >> buf)
		cout << buf << ends;     //ends插入一个空字符并刷新缓冲区
	cout << "iostate: " << is.rdstate() << endl;
	cout << flush;                  //flush刷新缓冲区，不附加内容
	is.clear();
	return is;
}

int main()
{
	istream& is = func(std::cin);
	cout << "iostate: " << is.rdstate() << endl;
	return 0;

}
