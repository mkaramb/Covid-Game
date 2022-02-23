#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <iostream>
#include "Point2D.h"
using namespace std;

class GameObject
{       
protected:
    Point2D location;
    int id_num;
    char display_code;
    char state;
public:
    GameObject(char);
    virtual ~GameObject();
    GameObject(Point2D, int, char);
    Point2D GetLocation();
    int GetId();
    char GetState();
    void DrawSelf(char*);
    virtual bool Update() = 0;
    virtual void ShowStatus();
    virtual bool ShouldBeVisible() = 0;
};

#endif
