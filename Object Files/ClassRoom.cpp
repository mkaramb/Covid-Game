#include <iostream>
#include "ClassRoom.h"  
using namespace std;

ClassRoom::ClassRoom(unsigned int max_assign, unsigned int antibody_cost, double dollar_cost, unsigned int crd_per_assign, int in_id, Point2D in_loc):Building('C', in_id, in_loc)
{
    max_number_of_assignments = max_assign;
    antibody_cost_per_assignment = antibody_cost;
    credits_per_assignment = crd_per_assign;
    dollar_cost_per_assignment = dollar_cost;
    cout << "ClassRoom constructed" << endl;
}

ClassRoom::~ClassRoom()
{
    cout << "ClassRoom destructed" << endl;
}

ClassRoom::ClassRoom():Building()
{
    display_code = 'c';
    state = NOT_PASSED;
    max_number_of_assignments = 10;
    num_assignments_remaining = max_number_of_assignments;
    antibody_cost_per_assignment = 1;
    dollar_cost_per_assignment = 1.0;
    credits_per_assignment = 2.0;
    cout << "ClassRoom default constructed" << endl;
}

double ClassRoom::GetDollarCost(unsigned int unit_qty)
{
    return dollar_cost_per_assignment * unit_qty;
}

unsigned int ClassRoom::GetAntibodyCost(unsigned int unit_qty)
{
    return unit_qty * antibody_cost_per_assignment;
}
    
unsigned int ClassRoom::GetNumAssignmentsRemaining()
{
    return num_assignments_remaining;
}
    
bool ClassRoom::IsAbleToLearn(unsigned int unit_qty, double budget, unsigned int antibodies)
{
    if(budget>=(unit_qty *dollar_cost_per_assignment) && antibodies>= (unit_qty* antibody_cost_per_assignment))
    {
        return true;
    }
    else
    {
        return false;
    }
}

unsigned int ClassRoom::TrainStudents(unsigned int assignment_units)
{
    if(num_assignments_remaining >= assignment_units)
    {
        num_assignments_remaining -= assignment_units;
        return assignment_units * credits_per_assignment;
    }
    else
    {
        assignment_units = num_assignments_remaining;
        num_assignments_remaining -= assignment_units;
        return assignment_units * credits_per_assignment;
    }
}
     
bool ClassRoom::Update()
{
    if(state == NOT_PASSED && num_assignments_remaining == 0)
    {
        state = PASSED;
        display_code = 'c';
        cout << " " << display_code << id_num << " has been passed" << endl;
        return true;
    }
    else
    {
        return false;
    }
}

bool ClassRoom::passed()
{
    if(num_assignments_remaining == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void ClassRoom::ShowStatus()
{
    cout << "ClassRoomStatus: ";
    Building::ShowStatus();
    cout << endl;
    cout << "Max number of assignments: " << max_number_of_assignments << endl;
    cout << "Antibody cost per assignment: " << antibody_cost_per_assignment << endl;
    cout << "Dollar per assignment: "<<dollar_cost_per_assignment << endl;
    cout << "Credits per assignment:  "<<credits_per_assignment << endl;
    cout << " " << num_assignments_remaining << "assigment(s) are remaining for this classroom" << endl;
}

unsigned int ClassRoom::Getcreditsperassignments()
{
    return credits_per_assignment;
}

