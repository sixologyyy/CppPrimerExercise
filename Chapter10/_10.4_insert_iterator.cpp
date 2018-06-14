#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <iterator>

using namespace std;

template<typename Sequence>
void print(Sequence const& seq)
{
	for (const auto& i : seq)
		cout << i << " ";
	cout << endl;
}

int main()
{
	std::vector<int> vec{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	// inserter
	// 每次在指向的元素之前插入内容，插入后仍然指向原来的元素
	list<int> lst1{ -1,-2,-3 };
	insert_iterator < list<int >> it1 = inserter(lst1, ++lst1.begin());
	copy(vec.cbegin(), vec.cend(), it1);
	print(lst1);

	// back_inserter
	// 每次调用push_back()
	list<int> lst2{ -1,-2,-3 };
	back_insert_iterator < list<int >> it2 = back_inserter(lst2);
	copy(vec.cbegin(), vec.cend(), it2);
	print(lst2);

	// front_inserter
	// 每次调用push_front()
	// 对于空容器，可以达到倒序插入的效果
	list<int> lst3{ -1,-2,-3 };
	front_insert_iterator<list<int>> it3 = front_inserter(lst3);
	copy(vec.cbegin(), vec.cend(), it3);
	print(lst3);

	return 0;
}