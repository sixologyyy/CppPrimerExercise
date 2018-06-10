#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main()
{
	deque<int> d{ 1,2,3,4,5 };

	stack<int> s(d);         //用deque构造
	queue<int> q;
	priority_queue<int, vector<int>> pq;       //第二个参数可以指定底层容器

	stack<int>::container_type t1;                    //stack默认底层容器是deque
	queue<int> ::container_type t2;                 //queue默认底层容器是deque
	priority_queue<int>::container_type t3;      //priority_queue默认底层容器是vector

	s.push(10);
	cout << s.top() << endl;
	s.pop();
	s.pop();
	s.pop();
	cout << s.top() << endl;

	//注意queue没有top，priority_queue没有front()、back()
	for (int i = 0; i <= 10; i++)
		q.push(i);
	q.pop();
	cout << q.front()<<" "<<q.back() << endl;

	pq.push(3);
	pq.push(1);
	pq.push(8);
	pq.push(6);
	pq.push(7);
	pq.push(4);
	pq.pop();
	cout << pq.top() << endl;
}