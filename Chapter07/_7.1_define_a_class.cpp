#include <iostream>
#include <string>
using namespace std;

class SalesData
{
public:
    SalesData()=default;       //合成的默认构造函数
    SalesData(const string& s):bookNo(s) {}        //用初始化列表赋值
    SalesData(const string& s, unsigned n, double p):
        bookNo(s),unitsSold(n),revenue(p*n) {}
    SalesData(istream&);

	string isbn() const { return bookNo; }
	SalesData& combine(const SalesData&);     //在当前对象上面增加另一个对象的值
	double avgPrice() const;

	string bookNo;
	unsigned unitsSold = 0;
	double revenue = 0.0;
};

SalesData add(const SalesData&, const SalesData&);    //返回相加的副本，而不改变输入的内容
ostream& print(ostream&, const SalesData&);          //读取isbn、售出本数、单价
istream& read(istream&, SalesData&);                      //输出isbn、售出本书、收入、平均售价

SalesData::SalesData(istream& is)
{
    read(is,*this);
}

double SalesData::avgPrice() const
{
	if (unitsSold)
		return revenue / unitsSold;
	else
		return 0;
}

SalesData& SalesData::combine(const SalesData& rhs)
{
	unitsSold += rhs.unitsSold;
	revenue += rhs.revenue;
	return *this;
}

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

SalesData add(const SalesData& lhs, const SalesData& rhs)
{
	SalesData sum = lhs;
	sum.combine(rhs);
	return sum;
}

int main()
{
	SalesData total;
	//持续读取交易，合并结果，其中同一本书的交易是连续的
	if(read(cin,total))
    {
        SalesData trans;
        while(read(cin,trans))
        {
            if(total.isbn()==trans.isbn())
                total.combine(trans);
            else
            {
                print(cout,total)<<endl;
                total=trans;
            }
        }
        print(cout,total)<<endl;
    }
    else
    {
        cerr<<"No data"<<endl;
    }
}
