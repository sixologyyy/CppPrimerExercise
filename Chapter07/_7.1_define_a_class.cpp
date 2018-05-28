#include <iostream>
#include <string>
using namespace std;

class SalesData
{
public:
	string isbn() const { return bookNo; }
	SalesData& combine(const SalesData&);     //在当前对象上面增加另一个对象的值
	double avgPrice() const;

	string bookNo;
	unsigned unitsSold = 0;
	double revenue = 0.0;
};

SalesData add(const SalesData&, const SalesData&);    //返回相加的副本，而不改变输入的内容
ostream& print(ostream&, const SalesData&);
istream& read(istream&, SalesData&);

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
	;
}