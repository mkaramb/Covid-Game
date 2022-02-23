#include <iostream>
#include "GameCommand.h"
#include "Model.h"

using namespace std;

int main()
{
    cout << "EC327: Introduction to Software Engineering" << endl;
    cout << "Fall 2021" << endl;
    cout << "Max Karambelas PA3" << endl;
    Model m;
    View v = View();
    Point2D p1;
    GameCommand c;
    int idNum, studID, doctID, clasID, aNum, vNum;
    v.Plot(m.GetClassRoomPtr(1));
    while(true)
    {
        //bool valid = true;
        char command;
        m.Display(v);
        cout << endl;
        cout << "Commands:" << endl;
        cout << "m (ID X Y): command Student ID to move to location (x, y)" << endl;
        cout << "d (ID1 ID2): command Student ID1 to start heading to DoctorsOffice ID2" << endl;
        cout << "c (ID1 ID2): command Student ID1 to start heading towards ClassRoom ID2" << endl;
        cout << "s (ID1): command Student ID to stop doing whatever it is doing" << endl;
        cout << "v (ID1 vaccine_amount): command Student ID1 to buy vaccine_amount of vaccine at a DoctorOffice" << endl;
        cout << "a (ID1 assignment_amount): command Student ID1 to complete assignment_amount of training units at a ClassRoom" << endl;
        cout << "g: advance one-time step by updating each object once" << endl;
        cout << "r: adcance one-time step and update each object" << endl;
        cout << "q to quit the program" << endl;
        cout << endl;
        cout << "Enter a command: ";

    cin >> command;

    switch(command)
    {
      case 'm':
      {
          cin >> idNum >> p1.x >> p1.y;
          c.DoMoveCommand(m, idNum, p1);
          break;
      }
      case 'd':
      {
          cin >> studID >> doctID;
          c.DoMoveToDoctorCommand(m, studID, doctID);
          break;
      }
      case 'c':
      {
          cin >> studID >> clasID;
          c.DoMoveToClassCommand(m, studID, clasID);
          break;
      }
      case 's':
      {
          cin >> studID;
          c.DoStopCommand(m, studID);
          break;
      }
      case 'v':
      {
          cin >> studID >> vNum;
          c.DoLearningCommand(m, studID, vNum);
          break;
      }
      case 'a':
      {
          cin >> studID >> aNum;
          c.DoLearningCommand(m, studID, aNum);
          break;
      }
      case 'g':
      {
          c.DoGoCommand(m, v);
          break;
      }
      case 'r':
      {
          c.DoRunCommand(m, v);
          break;
      }
        case 'q':
      {
          return 0;
          break;
      }
    }
    }
}


