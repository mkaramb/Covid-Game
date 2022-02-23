#ifndef DOCTORSOFFICE_H
#define DOCTORSOFFICE_H
#include<iostream>
#include "ClassRoom.h"
using namespace std;

enum DoctorsOfficeStates
{
    VACCINE_AVAILABLE = 0,
    NO_VACCINE_AVAILABLE = 1
};

class DoctorsOffice:public Building
{          
private:
    unsigned int vaccine_capacity;
    unsigned int num_vaccine_remaining;
    double dollar_cost_per_vaccine;
public:
    bool HasVaccine();
    unsigned int GetNumVaccineRemaining();
    bool CanAffordVaccine(unsigned int, double );
    double GetDollarCost(unsigned int);
    unsigned int DistributeVaccine(unsigned int);
    bool Update();
    void ShowStatus();
    unsigned int Getnum_vaccine_remaining();
    DoctorsOffice(int, double, unsigned int, Point2D);
    DoctorsOffice();
    ~DoctorsOffice();
};

#endif
