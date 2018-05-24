#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<string> v1;
    vector<string> v2(10);
    vector<string> v3(3,"sxy");
    vector<string> v4(v3);
    vector<string> v5=v3;
    vector<string> v6{"a","b","cd"};
    vector<string> v7={"ab","c","d"};
    for(auto i:v3)
        cout<<i<<endl;
    for(auto i:v6)
        cout<<i<<endl;
    for(auto i:v7)
        cout<<i<<endl;
    v7={"1","2","3","4"};

    return 0;
}
