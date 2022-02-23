#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include "DoctorsOffice.h"
#include <cmath>
using namespace std;

enum StudentStates 
{
    STOPPED = 0,
    MOVING = 1,
    INFECTED = 2,
    AT_DOCTORS = 3,
    IN_CLASS = 4,
    MOVING_TO_DOCTOR = 5,
    MOVING_TO_CLASS = 6,
    STUDYING_IN_CLASS = 7,
    RECOVERING_ANTIBODIES = 8
};

class Student:public GameObject
{          
 private:
    double speed;
    bool is_at_doctor;
    bool is_in_class;
    unsigned int antibodies;
    unsigned int credits;
    double dollars; 
    unsigned int assignments_to_buy;
    unsigned int vaccines_to_buy;
    string name;
    DoctorsOffice* current_office;
    ClassRoom* current_class;
    Point2D destination;
    Vector2D delta;
public:
    Student();
    virtual ~Student();
    Student (char);
    Student(string, int, char, unsigned int, Point2D);
    void StartMoving(Point2D);
    void StartMovingToClass(ClassRoom*);
    void StartMovingToDoctor(DoctorsOffice*);
    void StartLearning(unsigned int);
    void StartRecoveringAntibodies(unsigned int);
    void Stop();
    bool IsInfected();
    bool ShouldBeVisible();
    void ShowStatus();
    bool Update();
protected: 
    bool UpdateLocation();
    void SetupDestination(Point2D);
};
static double GetRandomAmountOfDollars();
#endif


