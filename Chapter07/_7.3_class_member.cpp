#include <string>
#include <vector>
#include <iostream>
class Screen
{
public:
	typedef std::string::size_type pos;    //类型成员需要在使用前定义，普通成员则不必

	Screen() = default;
	Screen(pos ht, pos wd) :
		height(ht), width(wd), contents(ht*wd, ' ') {}
	Screen(pos ht,pos wd,char c):
		height(ht),width(wd),contents(ht*wd,c) {}

	//读取光标处的字符，类内部定义的函数是隐式inline
	char get() const              
		{ return contents[cursor]; }
	//显式声明inline，get的重载版本
	inline char get(pos ht, pos wd) const;
	//设置光标所在位置的新值
	Screen& set(char);
	Screen& set(pos, pos, char);
	//移动光标，可以在之后定义的时候设为内联
	Screen& move(pos r, pos c); 
	//调用显示函数，有常量和非常量版本，非常量版本是为了链式操作
	//调用非常量版本时，display隐式地传递this指针给doDisplay，后者隐式地把指向非常量的指针转换为指向常量的指针
	Screen& display(std::ostream& os)
		{ doDisplay(os); return *this; }
	const Screen& display(std::ostream& os) const        //注意，第一个const并不能区分重载，因为仅有返回值不同
		{ doDisplay(os); return *this; }
	//记录成员函数被调用的次数
	void someMember() const;      

private:
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;

	mutable size_t accessCtr;      //mutable即使在const对象、方法中中也是可变的

	//负责显示
	void doDisplay(std::ostream& os) const { os << contents; }
};

//用于追踪Screen
class WindowMgr
{
//默认情况下包含一个标准尺寸的空白Screen
private:
	std::vector<Screen> screens{ Screen(24,80,' ') };
};

inline Screen& Screen::move(pos r, pos c)
{
	pos row = r*width;
	cursor = row + c;
	return *this;
}

inline char Screen::get(pos r, pos c) const
{
	pos row = r*width;
	return contents[row + c];
}

inline Screen& Screen::set(char c)
{
	contents[cursor] = c;
	return *this;
}

inline Screen& Screen::set(pos row, pos col, char ch)
{
	contents[row*width + col] = ch;
	return *this;
}

void Screen::someMember() const
{
	++accessCtr;
}

int main()
{
	Screen myScreen(5,10,'_');
	const Screen cScreen(5, 3,'*');

	char ch = myScreen.get();
	ch = myScreen.get(0, 0);

	myScreen.move(4, 0).set('#');
	myScreen.display(std::cout);
	std::cout << std::endl;

	cScreen.display(std::cout);
	std::cout << std::endl;;

}
