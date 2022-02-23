#include "GameCommand.h"
#include <iostream>
#include <cmath>
using namespace std;

void GameCommand::DoMoveCommand(Model& model, int student_id, Point2D p1)
{
    for(int i = 0; i < 2; i++)
    {
        if((model.GetStudentPtr(student_id) -> GetId()) == student_id)
        {
            cout << "Moving " << model.GetStudentPtr(student_id) -> GetId() << " to " << p1 << endl;
            model.GetStudentPtr(student_id) -> StartMoving(p1);
        }
        else
        {
            cout << "Error: Please enter a valid command!" << endl;
        }
    }
}

void GameCommand::DoMoveToDoctorCommand(Model& model, int student_id, int office_id)
{
    if(!cin.fail())
    {
        cout << "Moving " << model.GetStudentPtr(student_id) -> GetId() << " to doctor's office " << model.GetDoctorsOfficePtr(office_id) -> GetId() << endl;
        model.GetStudentPtr(student_id) -> StartMovingToDoctor(model.GetDoctorsOfficePtr(office_id));
    }
    else
    {
        cout << "Error: Please enter a valid command!" << endl;
    }
}

void GameCommand::DoMoveToClassCommand(Model& model, int student_id, int class_id)
{
    if(!cin.fail())
    {
        cout << "Moving " << model.GetStudentPtr(student_id) -> GetId() << " to doctor's office " << model.GetClassRoomPtr(class_id) -> GetId() << endl;
        model.GetStudentPtr(student_id) -> StartMovingToClass(model.GetClassRoomPtr(class_id));
    }
    else
    {
        cout << "Error: Please enter a valid command!" << endl;
    }
}

void GameCommand::DoStopCommand(Model& model, int student_id)
{
    if(!cin.fail())
    {
        cout << "Stopping " << model.GetStudentPtr(student_id) -> GetId() << endl;
        model.GetStudentPtr(student_id) -> Stop();
    }
    else
    {
        cout << "Error: Please enter a valid command!" << endl;
    }
}

void GameCommand::DoLearningCommand(Model& model, int student_id, unsigned int assignments)
{
    if(!cin.fail())
    {
        cout << "Teaching " << model.GetStudentPtr(student_id) -> GetId() << endl;
        model.GetStudentPtr(student_id) -> StartLearning(assignments);
    }
    else
    {
        cout << "Error: Please enter a valid command!" << endl;
    }
}

void GameCommand::DoRecoverInOfficeCommand(Model& model, int student_id, unsigned int vaccine_needs)
{
    if(!cin.fail())
    {
        cout << "Recovering " << model.GetStudentPtr(student_id) -> GetId() << "'s antibodies" << endl;
        model.GetStudentPtr(student_id) -> StartRecoveringAntibodies(vaccine_needs);
    }
    else
    {
        cout << "Error: Please enter a valid command!" << endl;
    }
}

void GameCommand::DoGoCommand(Model& model, View& view)
{
    cout << "Advancing one tick." << endl;
}

void GameCommand::DoRunCommand(Model& model, View& view)
{
    int count = 0;
    cout << "Advancing to next event." << endl;
    while(count < 5)
    {
        if(model.Update() == true)
        {
            break;
        }
        count++;
    }
}
