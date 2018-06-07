#include <vector>
#include <iostream>
using namespace std;
int main()
{
	vector<int> a(1);

	cout << "size: " << a.size() << "   capacity: " << a.capacity() << endl;
	a.push_back(1);
	cout << "size: " << a.size() << "   capacity: " << a.capacity() << endl;
	a.push_back(1);
	cout << "size: " << a.size() << "   capacity: " << a.capacity() << endl;
	a.push_back(1);
	cout << "size: " << a.size() << "   capacity: " << a.capacity() << endl;
	a.push_back(1);
	cout << "size: " << a.size() << "   capacity: " << a.capacity() << endl;
	a.push_back(1);
	cout << "size: " << a.size() << "   capacity: " << a.capacity() << endl;

	a.reserve(10);
	cout << "size: " << a.size() << "   capacity: " << a.capacity() << endl;
	//reserve()不会缩小vector的容量，resize()可能会减少元素数量，但也不会缩小容量
	a.reserve(3);
	cout << "size: " << a.size() << "   capacity: " << a.capacity() << endl;

	//shrink_to_fit()不保证退还内存
	a.shrink_to_fit();
	cout << "size: " << a.size() << "   capacity: " << a.capacity() << endl;
}