// LoadingRobot.cpp
//
// Implementation file for a robot that can load items onto a conveyor belt
// Initial revision: Donald G Dansereau, 2019
// Completed by: Hendrik Venter


#include <stdlib.h>

#include "LoadingRobot.h"
#include "Conveyor.h"


//---------------------------------------------------------------
//Initialises the loading robot
void LoadingRobot::Init( Conveyor* WhichConveyor )
{
    _Conveyor = WhichConveyor;
}

//---------------------------------------------------------------
//Let the robot load items onto the conveyor
void LoadingRobot::AddItems()
{
    _Conveyor->AddItems( rand() % 10 );
}
