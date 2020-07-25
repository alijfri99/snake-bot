#include<iostream>
#include<Windows.h>
#include "tools.h"
#include "snake.h"
#include "aStar.h"
#include "node.h"

using namespace std;

int main()
{
	hideCursor();
	displayMap();
	snake s;
	//s.print();
	vector<string> v;
	v = aStar(s);
	while (true)
	{
		if (GetKeyState('F'))
			break;
	}
	while (true)
	{
		if (v.empty())
		{
			s.increaseSize();
			v = aStar(s);
		}
		else
		{
			string temp = v.back();
			v.pop_back();
			interpretmove(temp, s);
		}
		s.move();
		s.print();
		if (gameover(s))
			break;
		Sleep(100);
	}
	/*while (!v.empty())
	{
		string s = v.back();
		v.pop_back();
		cout << s << endl;
	}*/
	/*vector<int> a(5);
	a[0] = 55;
	cout << a[0] << endl;
	cin.get();*/
}