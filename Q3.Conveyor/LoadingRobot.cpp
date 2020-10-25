// LoadingRobot.cpp
//
// Implementation file for a robot that can load items onto a conveyor belt
// Initial revision: Donald G Dansereau, 2019
// Completed by: Hendrik Venter

#include "LoadingRobot.h"

//---------------------------------------------------------------
//Initialises Conveyor
LoadingRobot::LoadingRobot(Conveyor* WhichConveyor)
{
  assert(WhichConveyor != NULL);
  _Conveyor = WhichConveyor;

  std::cout << "[LoadingRobot CTor] " << std::endl;
}

//---------------------------------------------------------------
//Destruct Conveyor
LoadingRobot::~LoadingRobot()
{
  std::cout << "[LoadingRobot DTor] " << std::endl;
}

//---------------------------------------------------------------
//Let the robot load items onto the conveyor
void LoadingRobot::AddItems()
{
    _Conveyor->AddItems(rand() % 10);
}
