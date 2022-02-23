#include <iostream>
#include "DoctorsOffice.h"
using namespace std;

DoctorsOffice::DoctorsOffice():Building()
{
    vaccine_capacity = 100;
    num_vaccine_remaining = vaccine_capacity;
    dollar_cost_per_vaccine = 5;
    display_code = 'D';
    state= VACCINE_AVAILABLE;
    cout << "DoctorsOffice default constructed" << endl;
}

DoctorsOffice::DoctorsOffice(int in_id, double vaccine_cost,  unsigned int vaccine_cap, Point2D in_loc):Building('D', in_id, in_loc)
{
    id_num = in_id;
    location = in_loc;
    display_code = 'D';
    dollar_cost_per_vaccine = vaccine_cost;
    vaccine_capacity = vaccine_cap;
    num_vaccine_remaining = vaccine_capacity;
    cout << "DoctorsOfffice constructed" << endl;
    state = VACCINE_AVAILABLE;
}

DoctorsOffice::~DoctorsOffice()
{
    cout << "DoctorsOffice destructed" << endl;
}

bool DoctorsOffice::HasVaccine()
{
    if(num_vaccine_remaining>=1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

unsigned int DoctorsOffice::GetNumVaccineRemaining()
{
    return num_vaccine_remaining;
}

bool DoctorsOffice::CanAffordVaccine(unsigned int vaccine, double budget)
{
    if(budget > (vaccine * dollar_cost_per_vaccine))
    {
        return true;
    }
    else
    {
        return false;
    }
}

double DoctorsOffice::GetDollarCost(unsigned int vaccine)
{
    return vaccine * dollar_cost_per_vaccine;
}
    
unsigned int DoctorsOffice::DistributeVaccine(unsigned int vaccine_needed)
{
    if(num_vaccine_remaining >= vaccine_needed)
    {
        num_vaccine_remaining = num_vaccine_remaining - vaccine_needed;
        return vaccine_needed;
    }
    if(num_vaccine_remaining < vaccine_needed)
    {
        return num_vaccine_remaining;
        num_vaccine_remaining = 0;
    }
    else
    {
        return false;
    }
}
    
bool DoctorsOffice::Update()
{
    if(state == VACCINE_AVAILABLE && num_vaccine_remaining == 0)
    {
        state = NO_VACCINE_AVAILABLE;
        display_code = 'd';
        cout << "DoctorsOffice " << id_num;
        cout <<" has ran out of vaccine." << endl;
        return true;
    }
    else
    {
        return false;
    }
}
    
void DoctorsOffice::ShowStatus()
    {
        cout << "DoctorsOffice Status: " << endl;
        Building::ShowStatus();
        cout << " Dollars per vaccine: " << dollar_cost_per_vaccine;
        cout<<endl;
        cout << "has " << num_vaccine_remaining << "vaccine(s) remaining. " << endl;
    }

unsigned int DoctorsOffice::Getnum_vaccine_remaining()
{
    return num_vaccine_remaining;
}











