#include <iostream>
#include <string>
using namespace std;

class Account
{
public:
    void caculate() { amount+=amount*interestRate; }
    //static只能出现在类内声明处
    static double rate() { return interestRate; }
    static void rate(double);

private:
    string owner;
    double amount;
    static double interestRate;
    static double initRate();
};

//必须在类外部定义和初始化每个静态成员，且每个成员只能定义一次
double Account::interestRate=initRate();

void Account::rate(double newRate)
{
    interestRate=newRate;
}

double Account::initRate()
{
    return 0.15;
}

int main()
{
    double r;
    r=Account::rate();    //作用域运算符访问静态成员

    Account ac1;
    Account* ac2=&ac1;
    //通过对象或者指针访问静态成员
    r=ac1.rate();
    cout<<r<<endl;
    r=ac2->rate();
    cout<<r<<endl;

    ac1.rate(0.2);
    cout<<ac1.rate()<<endl;
}
