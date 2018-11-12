#include <iostream>
#include "graphicsdisplay.h"
#include "subject.h"
#include"board.h"
using namespace std;

GraphicsDisplay::GraphicsDisplay(int row, int col):
	row{ row }, col{ col }, xw{ (col) * 20,(row+7) * 20 } {
  xw.fillRectangle(0, 0, (col) *100, (row+7) *100, Xwindow::Black);
}

void GraphicsDisplay::notify(int i,int j,char whoNotified) {
	char info = whoNotified;
	int cellSize = 20;
	if (info == ' ') {
		xw.fillRectangle((j)* cellSize,(17-i)* cellSize, cellSize, cellSize,0);
	}
	else if(info=='J'){
    xw.fillRectangle((j) * cellSize, (17-i) * cellSize, cellSize, cellSize, 2);
  }
	else if (info == 'L') {
		xw.fillRectangle((j) * cellSize, (17 - i) * cellSize, cellSize, cellSize, 3);
	}
	else if(info=='S')
	{
		xw.fillRectangle((j) * cellSize, (17 - i) * cellSize, cellSize, cellSize,4);
	}
	else if(info=='Z'){
		xw.fillRectangle((j) * cellSize, (17 - i) * cellSize, cellSize, cellSize,5);
	}
	else if (info == 'I') {
		xw.fillRectangle((j) * cellSize, (17 - i) * cellSize, cellSize, cellSize, 6);
	}
	else if (info == 'O') {
		xw.fillRectangle((j) * cellSize, (17 - i) * cellSize, cellSize, cellSize, 7);
	}
	else if (info == 'T') {
		xw.fillRectangle((j) * cellSize, (17 - i) * cellSize, cellSize, cellSize, 8);
	}
	else if(info=='*'){
		xw.fillRectangle((j) * cellSize, (17 - i) * cellSize, cellSize, cellSize, 9);
	}
	else {
		xw.fillRectangle((j)* cellSize, (17 - i) * cellSize, cellSize, cellSize, 1);
	}
}

void GraphicsDisplay::drarstring(int x, int y, std::string msg, int colour ) {
	this->xw.drawString(x, y, msg, colour);
}

void GraphicsDisplay::fillRectangle(int x, int y, int width, int height, int colour) {
	this->xw.fillRectangle( x,  y,  width,  height,  colour);
}
