#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    const char *cp="a char array for testing...";
    string s0("a string with no useful information");

    //构造string的其他方法
    string s1(cp,10);             //拷贝字符数组cp中的前n个
    string s2(s0,10);             //从string的第pos个位置到最后，pos不能越界
    string s3(s0,6,8);             //从string的第pos个位置开始，拷贝n个，pos不能越界，n可以超过长度（但是没用
    string s4=s0.substr(15,10);    //从pos开始，长度n的子串，pos不能越界，n可超过长度

    cout<<"s1 : "<<s1<<endl;
    cout<<"s2 : "<<s2<<endl;
    cout<<"s3 : "<<s3<<endl;
    cout<<"s4 : "<<s4<<endl;

    //修改string的其他方法
    //注：append、assign、insert、replace参数形式非常多，参见p323-324
    s0.erase(0,30);                        //erase除了接受迭代器参数外，还可以接受下标数字，还可以指定个数
    cout<<"s0 : "<<s0<<endl;     //()ation，()表示改变的部分

    //insert也可以接受下标数字，此版本返回指向s的引用（迭代器版本返回迭代器
    s0.insert(s0.size(),5,'.');
    cout<<"s0 : "<<s0<<endl;      //ation(.....)
    //还可以接受string或字符数组参数
    s0.insert(0,s1);
    cout<<"s0 : "<<s0<<endl;      //(a char arr)ation.....
    //插入字符数组的前n个
    s0.insert(0,cp,2);
    cout<<"s0 : "<<s0<<endl;      //(a )a char arration.....
    //插入从string的pos开始的n个字符
    s0.insert(0,s1,2,5);
    cout<<"s0 : "<<s0<<endl;      //(char )a a char arration.....
    //参数变成字符数组，同上
    s0.insert(0,cp,2,5);
    cout<<"s0 : "<<s0<<endl;      //(char )char a a char arration.....

    s0.assign(cp,10);                     //将cp的前n个赋给s0
    cout<<"s0 : "<<s0<<endl;

    s0.append("!!!!");                    //插入结尾
    cout<<"s0 : "<<s0<<endl;

    s0.replace(2,4,"string");           //把pos开始的n个字符替换
    cout<<"s0 : "<<s0<<endl;

    //搜索string
    //参数可以是(char,pos)，(string,pos)，(char*,pos)，(char*,pos,n)，pos表示查找开始的尾置，默认为0
    s0="a sentence with several words such as apple , bear , cake and dad... i can't list all the words because there are too many words";
    //查找的都是s中的尾置
    //首次出现的位置
    auto p=s0.find("word");
    cout<<p<<endl;
    //最后一次出现的位置
    p=s0.rfind("word");
    cout<<p<<endl;
    //参数中任一字符首次出现的位置
    p=s0.find_first_of("word");
    cout<<p<<endl;
    //参数中任一字符最后出现的位置
    p=s0.find_last_of("word");
    cout<<p<<endl;
    //第一个不在参数中的字符
    p=s0.find_first_not_of("abcdefghijklmnopqrstuvwxyz");
    cout<<p<<endl;
    //最后一个不 在参数中的字符
    p=s0.find_last_not_of("abcdefghijklmnopqrstuvwxyz");
    cout<<p<<endl;

    p=0;
    cout<<"\nfound \"word\" at index : ";
    while((p=s0.find("word",p))!=string::npos)
    {
        cout<<p<<" ";
        ++p;        //不++会死循环
    }
    cout<<endl;
}
