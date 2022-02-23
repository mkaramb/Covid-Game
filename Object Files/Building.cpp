#include <iostream>
#include "Building.h"
using namespace std;

Building::Building():GameObject('B')  
{
    display_code ='B';
    cout << "Building default constructed" << endl;
    student_count = 0;
}

Building::Building(char in_code, int in_id, Point2D in_loc):GameObject(in_loc, in_id, in_code)
{
    id_num = in_id;
    location = in_loc;
    display_code = in_code;
    student_count = 0;
    cout << "Building constructed" << endl;
}

void Building::AddOneStudent()
{
    student_count = student_count + 1;
}

void Building::RemoveOneStudent()
{
    student_count = student_count - 1;
}

void Building::ShowStatus()
{
    cout << "(" << display_code << id_num << ")" << " located at " << location << endl;
    if(student_count == 1)
    {
        cout << " " << student_count << " students is in this building" << endl;
    }
    else
    {
        cout << " " << student_count << " students are in this building" << endl;
    }
}

bool Building::ShouldBeVisible()
{
    return true;
}

unsigned int Building::getStudent_count()
{
    return student_count;
}
