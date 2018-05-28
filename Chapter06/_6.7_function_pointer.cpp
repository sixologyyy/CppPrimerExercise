#include <iostream>
#include <string>
using namespace std;

//某个函数
bool lengthCmp(const string& s1,const string& s2)
{
    return s1.size()>=s2.size()?true:false;
}

//函数指针
bool (*pLenCmp)(const string& ,const string& );      //未初始化

//函数指针作为形参
void useLongger(const string& ,const string& , bool (*pLenCmp)(const string& ,const string& ));     //形参看起来是函数，实际上当成指针使用，两者等价
void useLongger(const string& ,const string& , bool pLenCmp(const string& ,const string& ));

//给函数指针类型取别名
typedef bool lc(const string& ,const string& );       //别名，lc是函数类型
using lc1=bool(const string& ,const string& );       //与上面等价
typedef decltype(lengthCmp) lc2;                          //注意，decltype不会自动转换，也是函数类型

typedef bool (*plc)(const string& ,const string& );       //类型别名，plc是函数指针
using plc1=bool (*)(const string& ,const string& );      //与上面等价，注意写法
typedef decltype(lengthCmp)* plc2;                            //decltype后面加*，显示声明函数指针

//用类型别名重新声明函数
void useLongger(const string& ,const string& , lc);      //同理，六者等价
void useLongger(const string& ,const string& , lc1);
void useLongger(const string& ,const string& , lc2);
void useLongger(const string& ,const string& , plc);
void useLongger(const string& ,const string& , plc1);
void useLongger(const string& ,const string& , plc2);

//返回指向函数的指针
//从里向外读，fun的参数是(int* ,int )，fun前面的*说明返回一个指针，该指针有参数说明是函数指针，函数参数是(const string& ,const string& )，返回bool
//即fun返回函数指针 bool (*)(const string& ,const string& )
bool (*fun(int* ,int ))(const string& ,const string& );
//decltype写法
decltype(pLenCmp) fun(int* ,int );
decltype(lengthCmp)* fun(int* ,int );     //不会自动转换成指针，注意加上*
//尾置返回类型的写法
auto fun(int* ,int ) -> bool (*)(const string& ,const string& );
//别名写法
//lc fun(int* ,int );    //错误，必须把返回类型写成指针形式，编译器不会自动转换，该写法返回了一个函数，是不允许的
lc* fun(int* ,int );      //六者等价
lc1* fun(int* ,int );
lc2* fun(int* ,int );
plc fun(int*,int );
plc1 fun(int* ,int );
plc2 fun(int* ,int );


//useLongger()的定义
void useLongger(const string& s1,const string& s2, bool pLenCmp(const string& s1,const string& s2))
{
    cout<<"useLonger"<<endl;
}

//fun()的定义
plc fun(int* n,int m)
{
    cout<<"fun: ";
    return &lengthCmp;
}
int main()
{
    pLenCmp=lengthCmp;      //编译器自动把函数名转换为指针，两者等价
    pLenCmp=&lengthCmp;

    cout<<pLenCmp("abcde","a")<<endl;       //同理，三者等价
    cout<<(*pLenCmp)("abcde","a")<<endl;
    cout<<lengthCmp("abcde","a")<<endl;
    cout<<endl;

    useLongger("","",lengthCmp);      //同理，三者等价
    useLongger("","",pLenCmp);
    useLongger("","",*pLenCmp);
    cout<<endl;

    pLenCmp=fun((int*)0,0);
    cout<<pLenCmp("a","abc")<<endl;
    cout<<fun((int*)0,0)("abc","")<<endl;
    cout<<endl;

}
