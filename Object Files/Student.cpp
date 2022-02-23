#include <iostream>
#include "Student.h"
#include <cmath>
using namespace std;

Student::Student():GameObject('S')
{
    speed = 5;
    state = STOPPED;
    is_at_doctor = false;
    is_in_class = false;
    antibodies = 20;
    credits = 0;
    vaccines_to_buy = 0;
    assignments_to_buy = 0;
    current_office = NULL;
    current_class = NULL;
    cout << "Student default constructed." << endl;
}

Student::~Student()
{
    cout << "Student destructed" << endl;
}

Student::Student(char in_code):GameObject('S')
{
    speed = 5;
    cout << "Student constructed." << endl;
    state = STOPPED;
    is_at_doctor = false;
    is_in_class = false;
    antibodies = 20;
    credits = 0;
    assignments_to_buy = 0;
    vaccines_to_buy = 0;
    current_office = NULL;
    current_class = NULL;

}

Student::Student(string in_name, int in_id, char in_code, unsigned int in_speed, Point2D in_loc):GameObject(in_loc, in_id, in_code)
{
    speed = in_speed;
    name = in_name;
    state = 0;
    antibodies = 20;
    credits = 0;
    assignments_to_buy = 0;
    vaccines_to_buy = 0;
    current_office = NULL;
    current_class = NULL;
    cout << "Student constructed." << endl;
}


void Student::StartMoving(Point2D dest)
{
    SetupDestination(dest);
    state = MOVING;
    if(location == dest)
    {
        cout << " " << display_code << id_num << "I'm already there. See?" << endl;
        if(location == current_office -> GetLocation())
        {
            current_office -> RemoveOneStudent();
        }
        if (location == current_class -> GetLocation())
        {
            current_class -> AddOneStudent();
        }
        
    }

    if(state == INFECTED)
    {
         cout << " " << display_code << id_num << "I'm infected. I may move but you cannot see me." << endl;

    }
    else
    {
        cout << " " << display_code << id_num << " On my way" << endl;
    }
}

void Student::StartMovingToClass(ClassRoom* classr)
{
    
     SetupDestination(classr -> GetLocation());
     state = MOVING_TO_CLASS;
    if(state == INFECTED)
    {
        cout << " " << display_code << id_num << "I'm infected. I may move but you cannot see me." << endl;
    }
    cout << " " << display_code << id_num << " On my way to class" << classr -> GetId() << endl;
    if(state == IN_CLASS)
    {
        cout << " " << display_code << id_num << "I'm already at the classroom!" << endl;
    }
}

void Student::StartMovingToDoctor(DoctorsOffice* office)
{
    
    SetupDestination(office -> GetLocation());
    state = MOVING_TO_DOCTOR;

    if(state == INFECTED)
    {
        cout << " " << display_code << id_num << "I'm infected so I should have gone to the doctor's."  << endl;
    }
    cout  << " " << display_code << id_num << "On my way to doctor’s " << office -> GetId();
    if(state == AT_DOCTORS)
    {
        cout << " " << display_code << id_num << " I am already at the the Doctor’s!." << endl;
    }
    

}

void Student::StartLearning(unsigned int num_assignments)
{
    if(state == INFECTED)
    {
        cout << " " << display_code << id_num << "  I am infected so no more school for me..." << endl;
    }
    
    if(state != IN_CLASS || state != STUDYING_IN_CLASS)
    {
        cout << " " << display_code << id_num << " I can only learn in a ClassRoom!" << endl;
    }

    if(dollars < current_class -> GetDollarCost(num_assignments))
    {
        cout << " " << display_code << id_num << " Not enough money for school" << endl;

    }
    if(current_class -> passed() == true)
    {
        cout << ": Cannot lean! This Class has no more assignments!" << endl;
    }
    else
    {
        state = STUDYING_IN_CLASS;
        assignments_to_buy = num_assignments;
    }
}

void Student::StartRecoveringAntibodies(unsigned int num_vaccines)
{
    if(dollars < current_office -> GetDollarCost(num_vaccines))
    {
        cout << " " << display_code << id_num << "Not enough money to recover antibodies." << endl;
    }

    if(current_office -> GetNumVaccineRemaining() == 0)
    {
        cout << " " << display_code << id_num << "Cannot recover! No vaccine remaining in this Doctor’s Office " << endl;
    }
        
    if(state != AT_DOCTORS)
    {
        cout << " " << display_code << id_num << " I can only recover antibodies at a Doctor’s Office!" << endl;
    }
    else
    {
        state = RECOVERING_ANTIBODIES;
        vaccines_to_buy = num_vaccines;
    }
}

void Student::Stop()
{
    state = STOPPED;
    cout << " " << display_code << id_num << " Stopping..";
}

bool Student::IsInfected()
{
    if(antibodies == 0)
    {
        return true;
    }
    return false;
}

bool Student::ShouldBeVisible()
{
    if(IsInfected() == false)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Student::ShowStatus()
{
    cout << " " << name << "status: " << endl;
    GameObject::ShowStatus();
    cout << state << endl;
    cout << "Antibodies " <<  antibodies << endl;
    cout << "Dollars " << dollars << endl;
    cout << "Credits " << credits << endl;
    if(state == STOPPED)
    {
        cout << "stopped" << endl;
    }
    if(state == MOVING)
    {
        cout << "moving at a speed of " << speed << " to destination <X, Y> ateach step of " << delta << endl;
    }
    if(state == MOVING_TO_CLASS)
    {
        cout << "heading to Classroom" << current_class << "at a speed of" << speed << " at each step of " << delta << endl;
    }
    if(state == MOVING_TO_DOCTOR)
    {
        cout << " heading to Doctor’s Office " << current_office << " at a speed of " << speed << " at each step of " << delta << endl;
    }
    if(state == IN_CLASS)
    {
        cout << "inside Classroom " << current_class << endl;
    }
    if(state == AT_DOCTORS)
    {
        cout << "inside Doctor’s Office " << current_office << endl;
    }
    if(state == STUDYING_IN_CLASS)
    {
        cout << "studying in Classroom " << current_class << endl;
    }
    if(state == RECOVERING_ANTIBODIES)
    {
        cout << " recovering antibodies in Doctor’s Office " << current_office << endl;
    }
}

bool Student::Update()
{
    unsigned int totalnum;
    int totvaccines;
    if(antibodies == 0)
    {
        state = INFECTED;
        cout << name << "is out of antibodies" << endl;
    }
    else
    {
        return false;
    }
    switch(state)
    {
    case STOPPED:
            return false;
            break;
    case MOVING:
            UpdateLocation();
            if(UpdateLocation() == true)
            {
                state = STOPPED;
                return true;
            }
            else
            {
                state = MOVING;
                return false;
            }
            break;
    case MOVING_TO_CLASS:
            UpdateLocation();
            if(UpdateLocation() == true)
            {
                state = IN_CLASS;
                return true;
            }
            else
            {
                state = MOVING_TO_CLASS;
                return false;
            }
            break;
    case MOVING_TO_DOCTOR:
            UpdateLocation();
            if(UpdateLocation() == true)
            {
                state = AT_DOCTORS;
                return true;
            }
            else
            {
                state = MOVING_TO_DOCTOR;
                return false;
            }
            break;
    case IN_CLASS:
            return false;
            break;
    case AT_DOCTORS:
            return false;
            break;
    case STUDYING_IN_CLASS:
            totalnum = current_class -> GetNumAssignmentsRemaining();
            state = STUDYING_IN_CLASS;
            cout << " " << display_code << "Started to learn at the ClassRoom " << current_class -> GetId() << "with" << assignments_to_buy << "assignments";
            credits = current_class -> Getcreditsperassignments()* assignments_to_buy;
            totalnum = current_class -> GetNumAssignmentsRemaining() - assignments_to_buy;
            antibodies -= current_class -> GetAntibodyCost(assignments_to_buy);
            dollars -= current_class -> GetDollarCost(assignments_to_buy);
            credits += current_class -> TrainStudents(assignments_to_buy);
            cout << "** " << name << " completed " << assignments_to_buy << " assignment(s)!**" << endl;
            cout << "** " << name << " gained " << credits << " credit(s)!**" << endl;
            state = IN_CLASS;
            return true;
            break;
     case RECOVERING_ANTIBODIES:
            cout << " " << display_code << id_num << " Started recovering" << vaccines_to_buy << " vaccines at Doctor's Office" << current_office ->  GetId() << endl;
            totvaccines = current_office -> GetNumVaccineRemaining() - vaccines_to_buy;
            antibodies += current_office -> DistributeVaccine(vaccines_to_buy);
            dollars -= current_office -> GetDollarCost(vaccines_to_buy);
            cout << "** " << name << "recovered " << antibodies << "antibodies! " << endl;
            cout << "** " << name << "bought " << vaccines_to_buy << "vaccine(s)! " << endl;
            state = AT_DOCTORS;
            return true;
            break;
    default:
            return false;
            break;
    }
}


bool Student::UpdateLocation()
{
   if(fabs((destination - location).x) <= fabs(destination.x) && fabs((destination - location).y) <= fabs(destination.y))
   
   {
       location = destination;
       cout << "arrived" << endl;
       return true;
   }
   else
   {
       location = location + delta;
       cout << "moved" << endl;
       return false;
   }
}

void Student::SetupDestination(Point2D dest)
{
    destination = dest;
    destination.y = dest.y;
    destination.x = dest.x;
    delta = (destination - location) * (speed / GetDistanceBetween(destination, location));
}

static double GetRandomAmountOfDollars()
{
    return rand() % 3;
}




