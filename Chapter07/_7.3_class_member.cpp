#include <string>
#include <vector>
#include <iostream>
class Screen
{
public:
	typedef std::string::size_type pos;    //���ͳ�Ա��Ҫ��ʹ��ǰ���壬��ͨ��Ա�򲻱�

	Screen() = default;
	Screen(pos ht, pos wd) :
		height(ht), width(wd), contents(ht*wd, ' ') {}
	Screen(pos ht,pos wd,char c):
		height(ht),width(wd),contents(ht*wd,c) {}

	//��ȡ��괦���ַ������ڲ�����ĺ�������ʽinline
	char get() const              
		{ return contents[cursor]; }
	//��ʽ����inline��get�����ذ汾
	inline char get(pos ht, pos wd) const;
	//���ù������λ�õ���ֵ
	Screen& set(char);
	Screen& set(pos, pos, char);
	//�ƶ���꣬������֮�����ʱ����Ϊ����
	Screen& move(pos r, pos c); 
	//������ʾ�������г����ͷǳ����汾���ǳ����汾��Ϊ����ʽ����
	//���÷ǳ����汾ʱ��display��ʽ�ش���thisָ���doDisplay��������ʽ�ذ�ָ��ǳ�����ָ��ת��Ϊָ������ָ��
	Screen& display(std::ostream& os)
		{ doDisplay(os); return *this; }
	const Screen& display(std::ostream& os) const        //ע�⣬��һ��const�������������أ���Ϊ���з���ֵ��ͬ
		{ doDisplay(os); return *this; }
	//��¼��Ա���������õĴ���
	void someMember() const;      

private:
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;

	mutable size_t accessCtr;      //mutable��ʹ��const���󡢷�������Ҳ�ǿɱ��

	//������ʾ
	void doDisplay(std::ostream& os) const { os << contents; }
};

//����׷��Screen
class WindowMgr
{
//Ĭ������°���һ����׼�ߴ�Ŀհ�Screen
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
	std::cout << std::endl;

}