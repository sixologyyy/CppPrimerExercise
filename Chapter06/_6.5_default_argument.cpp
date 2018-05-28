#include <iostream>
using namespace std;

string matrix(int height,int width,char background);
string matrix(int height,int width,char background='#');         //可以赋予参数默认值，默认值右边的参数必须全都有默认值
//string matrix(int height,int width,char background='*');       //错误，一个作用域内，一个参数只能被赋予一次默认值
string matrix(int = 5,int = 8,char);                                          //给其他没有默认值的参数添加默认值时，右边的参数必须已经有默认值了

string matrix(int height,int width,char background)
{
    string s;
    for(int i=0;i<height;++i)
    {
        for(int j=0;j<width;++j)
            s+=background;
        s+='\n';
    }
    return s;
}
int main()
{
    cout<<matrix()<<endl;     //5,8,'#'
    cout<<matrix(1)<<endl;   //1,8,'#'
    cout<<matrix(2,3)<<endl;   //2,3,'#'
    cout<<matrix(4,4,'*')<<endl;   //4,4,'*'
}
