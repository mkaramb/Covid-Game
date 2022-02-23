#ifndef GAMECOMMAND_H
#define GAMECOMMAND_H
#include "Model.h"

class GameCommand
{
public:
    void DoMoveCommand(Model&, int, Point2D);
    void DoMoveToDoctorCommand(Model&, int, int);
    void DoMoveToClassCommand(Model&, int, int);
    void DoStopCommand(Model&, int);
    void DoLearningCommand(Model&, int, unsigned int);
    void DoRecoverInOfficeCommand(Model&, int, unsigned int);
    void DoGoCommand(Model&, View&);
    void DoRunCommand(Model&, View&);
};

#endif 
