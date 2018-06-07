#include <vector>
#include <forward_list>
#include <string>

#include <iostream>

using namespace std;

int main()
{
	//forward_list的特殊操作
	forward_list<string> f{ "ab","cd","efg","h","ijk" };
	forward_list<string>::iterator it;
	vector<string> vv{ "3","4","5" };
	it = f.before_begin();                                   //首前迭代器

	it = f.insert_after(it, "0");                             //在迭代器之前插入，返回指向最后插入的元素的迭代器，注意参数不能是尾后迭代器
	it = f.insert_after(it, 2,"12");                        //插入n个元素
	it = f.insert_after(it, vv.begin(), vv.end());    //插入迭代器指定的范围
	it = f.insert_after(it, { "678","90" });             //插入花括号列表

	it = f.emplace_after(it, "-1");                       //用构造函数插入

  	it = f.erase_after(it);                                    //删除迭代器之后的元素，返回被删除元素之后的迭代器，注意参数不能是尾元素和尾后
	it = f.erase_after(it, f.end());                        //删除b之后，直到e(不含)的元素

	for (auto i : f)
		cout << i << " ";
	cout << endl;

	//在forward_list中添加或删除元素时，一般要关注当前待处理的元素和他的前驱
	forward_list<int> f2{ 0,1,2,3,4,5,6,7,8,9 };
	forward_list<int>::iterator curr = f2.begin(), pre = f2.before_begin();      //保存当前节点和前驱
	while (curr != f2.end())
	{
		if (*curr % 2 == 0)
			curr = f2.erase_after(pre);       //通过前驱节点删除当前节点，前驱变为被删除元素后面的节点
		else
		{
			pre = curr;
			curr++;
		}
	}
	for (auto i : f2)
		cout << i << " ";
	cout << endl;

}

