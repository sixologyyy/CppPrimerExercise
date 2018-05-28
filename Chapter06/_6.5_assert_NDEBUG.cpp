#include <iostream>
//#define NDEBUG    //cassert之前定义可以让assert不起作用
#include <cassert>
using namespace std;

int main()
{
    int i;
    cout<<"输入正整数"<<endl;
    cin>>i;

    //assert(i>0);    //仅示例，assert应该用于辅助调试，验证那些“不可能”出现的情况，而不应该用于真正的逻辑和错误检查

    #ifndef NDEBUG
    if(i<0)
    {
        cerr<<"error:    "<<__FILE__<<endl
        <<"    in function:    "<<__func__<<endl
        <<"    at line:    "<<__LINE__<<endl
        <<"    compiled on:    "<<__DATE__<<endl
        <<"at:    "<<__TIME__<<endl
        <<"整数不应该为负"<<endl;
    }
    #endif // NDEBUG

}
