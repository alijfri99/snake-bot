#include<iostream>
#include<Windows.h>
#include "tools.h"
#include "snake.h"
#include "bfs.h"

using namespace std;

int main()
{
	/*hideCursor();
	displayMap();
	snake s;
	s.print();
	while (true)
	{
		if (GetKeyState('F'))
			break;
	}
	while (true)
	{
		s.move();
		s.print();
		if (GetAsyncKeyState('W'))
			s.turn(direction::up);
		if (GetAsyncKeyState('S'))
			s.turn(direction::down);
		if (GetAsyncKeyState('A'))
			s.turn(direction::left);
		if (GetAsyncKeyState('D'))
			s.turn(direction::right);
		if (gameover(s))
			break;
		Sleep(100);
	}*/
	snake s;
	vector<string> v = bfs(s);
	while (!v.empty())
	{
		string s = v.back();
		v.pop_back();
		cout << s << endl;
	}
	cin.get();
}