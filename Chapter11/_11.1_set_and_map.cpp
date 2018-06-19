#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;

int main()
{
	map<string, int> wordCount;
	set<string> exclude{"The","But","And","Or","An","A",
									"the","but","and","or","an","a"};

	string word;
	while (cin >> word)
	{
		if(exclude.find(word)==exclude.end())
			++wordCount[word];
	}
	for (auto i : wordCount)
		cout << "word " << '\"' << i.first << '\"' << " occurs " << i.second << " times" << endl;
}