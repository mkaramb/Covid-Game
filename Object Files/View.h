#ifndef VIEW_H
#define VIEW_H
#include "Student.h"
#include <iostream>
using namespace std;

const int view_maxsize = 20;

class View
{
private:
    int size;
    double scale;
    Point2D origin;
    char grid[view_maxsize][view_maxsize][2];
    bool GetSubscripts(int &, int &, Point2D);
public:
    void DrawSelf(char*);
    View();
    void Clear();
    void Plot(GameObject*);
    void Draw();
};

#endif
