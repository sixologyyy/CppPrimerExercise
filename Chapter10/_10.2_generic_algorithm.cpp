#include <algorithm>
#include <vector>
#include <iterator>
#include <iostream>
using namespace std;

int main()
{
    int a[10]{3,8,4,6,9,7,1,2,5,0},*pa;
    vector<int> v{3,8,4,6,9,7,1,2,5,0};
    vector<string> v2{"hello ","my ","name ","is ","sxy."};

    //find()
    auto it=find(v.begin(),v.end(),1);
    pa=find(begin(a),end(a),1);
    if(it==v.end())
        cout<<"not found"<<endl;
    else
        cout<<"found at index : "<<it-v.begin()<<endl;
    if(pa==end(a))
        cout<<"not found"<<endl;
    else
        cout<<"found at index : "<<pa-a<<endl;

    //count()
    cout<<"count of 0 in v : "<<count(v.begin(),v.end(),0)<<endl;

    //accumulate()
    int sum=accumulate(v.begin(),v.end(),0);
    cout<<"sum : "<<sum<<endl;
    //accumulate可以累加任何定义了+运算的元素
    string s=accumulate(v2.begin(),v2.end(),string(""));
    cout<<s<<endl;

    //equal()
    //第三个参数表示第二个容器的首元素迭代器，两个容器类型可以不同
    //因为第二个容器只用单个迭代器表示，所以第二个容器的长度一定不能小于第一个容器
    if(equal(v.begin(),v.end(),a))
        cout<<"v's value equal a's"<<endl;

    //fill()
    fill(a,a+10,0);
    cout<<"count of 0 in a : "<<count(a,a+10,0)<<endl;
    fill_n(a,5,1);
    cout<<"count of 1 in a : "<<count(a,a+10,1)<<endl;

    //back_inserter()
    vector<int> v3;
    vector<int> v4;
    fill_n(back_inserter(v3),5,0);
    fill_n(back_inserter(v3),6,1);
    fill_n(back_inserter(v3),3,2);
    cout<<"count of 0,1,2 in v3 : "<<count(v3.begin(),v3.end(),0)<<","<<count(v3.begin(),v3.end(),1)<<","<<count(v3.begin(),v3.end(),2)<<endl;

    //copy
    copy(v.begin(),v.end(),v3.begin());
    cout<<"v3 : ";
    for(auto i:v3)
        cout<<i<<" ";
    cout<<endl;

    //replace()
    //把范围内的值为第三个参数的替代为第四个参数
    replace(v3.begin(),v3.end(),1,-1);
    cout<<"v3 : ";
    for(auto i:v3)
        cout<<i<<" ";
    cout<<endl;
    //替换后存在第三个参数指代的容器里
    replace_copy(v3.begin(),v3.end(),back_inserter(v4),-1,11);
    cout<<"v4 : ";
    for(auto i:v4)
        cout<<i<<" ";
    cout<<endl;

    //sort()
    sort(v3.begin(),v3.end());
    cout<<"v3 : ";
    for(auto i:v3)
        cout<<i<<" ";
    cout<<endl;

    //unique()
    //只能对排序完毕的序列操作，返回不重复区域的尾后迭代器
    it=unique(v3.begin(),v3.end());
    v3.erase(it,v3.end());
    cout<<"unique v3 : ";
    for(auto i:v3)
        cout<<i<<" ";
    cout<<endl;
}
