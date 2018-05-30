#include <string>
#include <vector>
#include <iostream>
class Screen
{
public:
	typedef std::string::size_type pos;    //类型成员需要在使用前定义，普通成员则不必

        //友元类的成员可以访问此类的所有成员
	friend class WindowMgr;
	//或者仅声明其他类中的友元函数，但是此前必须有WindowMgr类的定义，其中clear()又用到了Screen类
	//所以要，先定义WindowMgr类，在里面声明Screen类，随后声明clear()函数，再定义Screen类，在里面声明WMgr::clear()友元，最后定义clear()，此时才可以使用Screen的成员
	//friend void WindowMgr::clear(screenIndex);

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
	void doDisplay(std::ostream& os) const { os << contents; }     //要声明为const成员，否则常量版本不能调用
};

//窗口类，用于追踪Screen
class WindowMgr
{
private:
    //默认情况下包含一个标准尺寸的空白Screen
	std::vector<Screen> screens{ Screen(24,80,' ') };

public:
    //窗口中每个屏幕的编号
    using screenIndex=std::vector<Screen>::size_type;
    //按照编号将指定creen置为空白
    void clear(screenIndex);
    //向窗口添加屏幕，返回屏幕编号
    screenIndex addScreen(const Screen&);
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

void WindowMgr::clear(screenIndex i)
{
    Screen& s=screens[i];
    s.contents=std::string(s.height*s.width,' ');
}

WindowMgr::screenIndex WindowMgr::addScreen(const Screen& s)     //返回类型如果是某个类的成员，需要指明，因为它在函数名之前，此时并没有进入类的作用域
{
    screens.push_back(s);
    return screens.size()-1;
}

int main()
{
	Screen myScreen(5,10,'_');
	const Screen cScreen(5, 3,'*');

	char ch = myScreen.get();
	ch = myScreen.get(0, 0);

	myScreen.move(4, 0).set('#');
	myScreen.display(std::cout).move(4, 1).set('*');
	std::cout << std::endl;
	myScreen.display(std::cout);
        std::cout << std::endl;

	cScreen.display(std::cout);
	std::cout << std::endl;

}
