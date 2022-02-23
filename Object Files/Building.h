#ifndef BUILDING_H
#define BUILDING_H
#include <iostream>
#include "GameObject.h"
using namespace std;

class Building:public GameObject
{          
private:
    unsigned int student_count;
public:
    void AddOneStudent();
    void RemoveOneStudent();
    void ShowStatus();
    bool ShouldBeVisible();
    Building();
    Building(char, int, Point2D);
    unsigned int getStudent_count();
};

#endif
