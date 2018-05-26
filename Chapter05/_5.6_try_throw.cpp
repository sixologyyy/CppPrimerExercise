#include <iostream>
#include <stdexcept>
using namespace std;
int main()
{
	
	int a, b;

	while (1)
	{
		try
		{
			cout << "输入被除数和除数" << endl;
			cin >> a >> b;

			if (b!=0)
			{
				cout << a << "/" << b << "=" << a / b << endl;
				break;
			}
			else
			{
				//cerr << "两个数不相等" << endl;
				throw runtime_error("除数不能为0");
			}

		}
		catch (runtime_error err)
		{
			cout << err.what() << endl
				<< "try again y/n?";
			char c;
			cin >> c;
			if (!cin || c == 'n')
				break;
		}
	}



}