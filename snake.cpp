#include "snake.h"
#include "point.h"
#include "tools.h"
#include<iostream>

using namespace std;

snake::snake()
{
	bodysize = 2;
	currentDirection = direction::right;
	head.set(10, 20);
	body[0].set(10, 19);
	body[1].set(10, 18);
	blank.set(10, 17);
}

void snake::print()
{
	gotoij(head.i, head.j);
	cout << "O";
	for (int i = 0; i < bodysize; i++)
	{
		gotoij(body[i].i, body[i].j);
		cout << "o";
	}
	gotoij(blank.i, blank.j);
	cout << " ";
}

void snake::follow()
{
	blank.set(body[bodysize - 1].i, body[bodysize - 1].j);
	for (int i = 1; i < bodysize; i++)
	{
		body[i].set(body[i - 1].i, body[i - 1].j);
	}
	body[0].set(head.i, head.j);
}

void snake::move()
{
	follow();
	switch (currentDirection)
	{
		case 0: //up
			head.i--;
			break;
		case 1: //down
			head.i++;
		case 2: //left
			head.j--;
		case 3: //right
			head.j++;
	}
}

void snake::turn(direction dir)
{
	
}