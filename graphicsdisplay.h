#ifndef GRAPHICSDISPLAY_H
#define GRAPHICSDISPLAY_H
#include <iostream>
#include <vector>
#include "window.h"

class GraphicsDisplay{
	int row;
	int col;
  Xwindow xw;
 public:
  GraphicsDisplay(int row, int col);
  void drarstring(int x, int y, std::string msg, int colour );
  void notify(int i,int j,char whoNotified);
  void fillRectangle(int x, int y, int width, int height, int colour);
};
#endif
