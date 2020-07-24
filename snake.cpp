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
	generateFruit();
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
	gotoij(fruit.i, fruit.j);
	cout << "$";
}

void snake::follow()
{
	blank.set(body[bodysize - 1].i, body[bodysize - 1].j);
	for (int i = bodysize-1; i > 0; i--)
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
			break;
		case 2: //left
			head.j--;
			break;
		case 3: //right
			head.j++;
			break;
	}
	if (head.i == fruit.i&&head.j == fruit.j)
		generateFruit();
}

void snake::turn(direction dir)
{
	switch (dir)
	{
		case 0: //up
			if (currentDirection != direction::down)
				currentDirection = dir;
			break;
		case 1: //down
			if (currentDirection != direction::up)
				currentDirection = dir;
			break;
		case 2: //left
			if (currentDirection != direction::right)
				currentDirection = dir;
			break;
		case 3: //right
			if (currentDirection != direction::left)
				currentDirection = dir;
			break;
	}
}

void snake::generateFruit()
{
	while (true)
	{
		int tempi = rand() % 18;
		int tempj = rand() % 38;
		bool result = true;
		if (tempi == head.i&&tempj == head.j)
			continue;
		for (int i = 0; i < bodysize; i++)
		{
			if (tempi == body[i].i&&tempj == body[i].j)
			{
				result = false;
				break;
			}
		}
		if (result == true)
		{
			fruit.set(tempi, tempj);
			return;
		}
	}
}