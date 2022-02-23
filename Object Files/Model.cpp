#include <iostream>
#include <cmath>
#include "Model.h"

using namespace std;

Model::Model()
{
    time = 0;
    num_objects = 6;
    num_students = 2;
    num_offices = 2;
    num_classes = 2;
    Point2D p1(5, 1);
    Student* ptrp1 = new Student("Homer", 1, 'S', 2, p1);
    student_ptrs[0] = ptrp1;
    object_ptrs[0] = ptrp1;
    Point2D p2(10, 1);
    Student* ptrp2 = new Student("Marge", 2, '5', 2, p1);
    student_ptrs[1] = ptrp2;
    object_ptrs[1] = ptrp2;
    Point2D p3(1, 20);
    DoctorsOffice* ptrp3 = new DoctorsOffice(1, 1, 100, p3);
    office_ptrs[0] = ptrp3;
    object_ptrs[2] = ptrp3;
    Point2D p4(10, 1);
    DoctorsOffice* ptrp4 = new DoctorsOffice(2, 2, 100, p4);
    office_ptrs[1] = ptrp4;
    object_ptrs[3] = ptrp4;
    Point2D p5(0, 0);
    ClassRoom* ptrp5 = new ClassRoom(20, 5, 7.5, 4, 1, p5);
    class_ptrs[0] = ptrp5;
    object_ptrs[4] = ptrp5;
    Point2D p6(5, 5);
    ClassRoom* ptrp6 = new ClassRoom(20, 5, 7.5, 4, 2, p6);
    class_ptrs[1] = ptrp6;
    object_ptrs[5] = ptrp6;
    cout << "Model default constructed" << endl;
}

Model::~Model()
{
    for(int i = 0; i < num_objects; i++)
    {
        delete object_ptrs[i];
    }
    cout << "Model destructed" << endl;
}

Student* Model::GetStudentPtr(int id)
{
    for(int i = 0; i < num_students; i++)
    {
        if(student_ptrs[i] -> GetId() == id)
        {
            return student_ptrs[i];
        }
    }
    return 0;
}

DoctorsOffice* Model::GetDoctorsOfficePtr(int id)
{
    for(int i = 0; i < num_offices; i++)
    {
        if(office_ptrs[i] -> GetId() == id)
        {
            return office_ptrs[i];
        }
    }
    return 0;
}

ClassRoom* Model::GetClassRoomPtr(int id)
{
    for(int i = 0; i < num_classes; i++)
    {
        if(class_ptrs[i] -> GetId() == id)
        {
            return class_ptrs[i];
        }
    }
    return 0;
}

bool Model::Update()
{
    time++;
    int classes_passed = 0;
    int students_infected = 0;
    if(classes_passed != num_classes)
    {
        for(int i = 0; i < num_classes; i++)
        {
            if(class_ptrs[i] -> GetState() == PASSED)
            {
                classes_passed++;
            }
        }
    }
    bool event = false;
    if(classes_passed == num_classes)
    {
        cout << "GAME OVER: You win! All assignments done!" << endl;
        exit(0);
    }
    if(students_infected == num_students)
    {
        cout << "GAME OVER: You lose! All of your Students are infected!" << endl;
        exit(0);
    }
    for(int i = 0; i < num_objects; i++)
    {
        bool temp = object_ptrs[i] -> Update();
        if(temp)
        {
            event = temp;
        }
    }
    return true;
}

void Model::ShowStatus()
{
    cout << time << endl;
    for(int i = 0; i < num_objects; i++)
    {
        object_ptrs[i] -> ShowStatus();
    }
}

void Model::Display(View& view)
{
    cout << "Time: "<< time << endl;
    view.Clear();
    for(int i = 0; i < num_objects; i++)
    {
        if(object_ptrs[i] -> ShouldBeVisible())
        {
            object_ptrs[i] -> ShowStatus();
        }
        view.Plot(object_ptrs[i]);
    }
    view.Draw();
}
