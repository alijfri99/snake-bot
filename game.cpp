#include<iostream>
#include<Windows.h>
#include "tools.h"
#include "snake.h"
#include "aStar.h"

using namespace std;

int main()
{
	hideCursor();
	displayMap();
	snake s;
	s.print();
	vector<string> v;
	aStar(s, v);
	while (true)
	{
		if (s.head.i == s.fruit.i&&s.head.j == s.fruit.j)
			s.increaseSize();
		if (v.empty())
		{
			s.print();
			aStar(s, v);
		}
		else
		{
			string temp = v.back();
			v.pop_back();
			interpretmove(temp, s);
			s.move();
			s.print();
		}
		if (gameover(s))
			break;
		Sleep(100);
	}
}