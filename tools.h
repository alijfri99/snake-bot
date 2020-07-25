#ifndef HEADER_H
#define HEADER_H
#include "snake.h"

void gotoij(int i, int j);
void hideCursor();
void displayMap();
bool gameover(const snake &s);
void interpretmove(std::string input, snake &s);

#endif
