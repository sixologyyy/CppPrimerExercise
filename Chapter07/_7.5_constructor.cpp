#include <iostream>
#include <string>
using namespace std;

class SalesData
{
    friend istream& read(istream&, SalesData&);
    friend ostream& print(ostream& os, const SalesData& item);

public:
    SalesData(const string& s, unsigned n, double p):
        bookNo(s),unitsSold(n),revenue(p*n) {}

    //委托构造函数
    SalesData(): SalesData("",0,0) {}
    SalesData(const string& s): SalesData(s,0,0) {}
    //上述构造函数提供了string到SalesData的隐式转换
    //给单参数的构造函数加上explicit，可以阻止隐式转换，如
    //explicit SalesData(const string& s): SalesData(s,0,0) {}

    //阻止了istream到SalesData的转换
    //explicit只能出现在类内声明处
    explicit SalesData(istream& is): SalesData()
                                        { read(is,*this); }

	string isbn() const { return bookNo; }

private:
	string bookNo;
	unsigned unitsSold = 0;
	double revenue = 0.0;

	double avgPrice() const;
};

istream& read(istream& is, SalesData& item)
{
	double price = 0;
	is >> item.bookNo >> item.unitsSold >> price;
	item.revenue = price*item.unitsSold;
	return is;
}

ostream& print(ostream& os, const SalesData& item)
{
	os << item.isbn() << " " << item.unitsSold << " "
		<< item.revenue << " " << item.avgPrice();
	return os;
}

double SalesData::avgPrice() const
{
	if (unitsSold)
		return revenue / unitsSold;
	else
		return 0;
}

//Debug是字面值常量类
//需要满足
//1. 是聚合类，且所数据成员都是字面值常量
//2. 不是聚合类，但满足
//    2.1 数据成员都是字面值常量
//    2.2 至少含有一个constexpr构造函数
//    2.3 类内初始值是常量表达式，类类型的成员初始值是它的constexpr构造函数
//    2.4 必须使用析构函数的默认定义
class Debug
{
public:
    constexpr Debug(bool b=true): io(b), hw(b), other(b) {}
    constexpr Debug(bool h, bool i, bool o): io(i), hw(h), other(o) {}

    constexpr bool any() { return io || hw || other; }
    void setIo(bool b) { io=b; }
    void setHw(bool b) { hw=b; }
    void setOth(bool b) { other=b; }

private:
    bool io;          //io错误
    bool hw;        //硬件错误
    bool other;    //其他错误
};

int main()
{
    SalesData aSale(cin);
    print(cout,aSale)<<endl;

    string aBook="0-1111";
    //含有一个参数的构造函数，提供了从该参数向该类的隐式转换方法
    //如SalesData(string)，提供了string到SaleData的隐式转换，下面的赋值是合法的
    aSale=aBook;
    print(cout,aSale)<<endl;
    //两步及以上的自动转换是不允许的
    //aSale="0-1111";      //错误

    //给单参数的构造函数加上explicit，可以阻止上述隐式转换
    //被explicit修饰的构造函数只能用来直接初始化或者强制转换，不能隐式转换
    aSale=SalesData(cin);
    aSale=static_cast<SalesData>(cin);

}
