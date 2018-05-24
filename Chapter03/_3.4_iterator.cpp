#include <iostream>
#include <vector>
#include <cctype>
using namespace std;
int main()
{
    vector<string> v={"ab","c","d"};
    auto a=v.begin();
    auto b=v.end();

    cout<<*a<<endl;
    cout<<a->size()<<endl;

    for(auto i:v)
    {
        for(auto j=i.begin();j!=i.end();j++)
            *j=toupper(*j);
        cout<<i<<endl;
    }

    vector<string>::iterator it;
    vector<string>::const_iterator cit=v.cbegin();

    v={"019","025","038","066","071","084","121","365","422","550"};
    string s="365";
    auto left=v.cbegin(),right=v.cend();
    auto mid=v.cbegin()+(right-left)/2;
    while(mid!=v.cend() && *mid!=s )
    {
        if(*mid>s)
            right=mid;
        else
            left=mid+1;
        mid=left+(right-left)/2;    //注意，不能用(left+right)/2
    }
    if(mid!=v.cend())
        cout<<mid-v.cbegin()<<endl;

    return 0;
}
