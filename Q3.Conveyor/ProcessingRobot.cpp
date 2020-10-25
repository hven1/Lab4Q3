// ProcessingRobot.cpp
//
// Implementation file for a robot that processes items off a conveyor belt
// Initial revision: Donald G Dansereau
// Completed by: Hendrik Venter

#include "ProcessingRobot.h"

#include <iostream>
#include <iomanip>
#include <cstdlib>      // rand
#include <algorithm>    // std::max
#include <math.h>

//---------------------------------------------------------------
//Initialises Conveyor
ProcessingRobot::ProcessingRobot(Conveyor* WhichConveyor)
{
  _Conveyor = WhichConveyor;

  _TotalNumItemsProcessedArm1 = 0;
  _NumProcessingIterationsArm1 = 1;
  _RunAverageNumItemsProcessedArm1 = 0;

  std::cout << "[ProcessingRobot 1 CTor] " << std::endl;
}

//---------------------------------------------------------------
//Destruct Conveyor
ProcessingRobot::~ProcessingRobot()
{
  std::cout << "[ProcessingRobot 1 DTor] " << std::endl;
}

//---------------------------------------------------------------
// First arm of Processing Robot
void ProcessingRobot::ProcessItems()
{
  int CurrentNumItemsOnConveyor = _Conveyor->GetNumOfItemsOnConveyor();

  //Check if there is items available to process
  if(CurrentNumItemsOnConveyor > 0)
  {
    //Calculate current number of items processed
    if( CurrentNumItemsOnConveyor>=_MaxNumItemsProcessedArm1 )
    {
      _CurrentNumItemsProcessedArm1= _MaxNumItemsProcessedArm1;
    }
    else{
      _CurrentNumItemsProcessedArm1 =CurrentNumItemsOnConveyor;
    }

    //Process Items
    _Conveyor->RemoveItems( _MaxNumItemsProcessedArm1 );

    //Report on items just processed
    std::cout << "Items processed Arm 1: " << _CurrentNumItemsProcessedArm1 << std::endl;
  }
}

//---------------------------------------------------------------
void ProcessingRobot::Report()
{
    //Calculate and report stats for reporting: Arm 1
    _TotalNumItemsProcessedArm1 += _CurrentNumItemsProcessedArm1;
    std::cout << "Total items processed Arm 1: " << std::setprecision(4) << _TotalNumItemsProcessedArm1 << std::endl;

    //Report utilisation stats
    _RunAverageNumItemsProcessedArm1 = (_TotalNumItemsProcessedArm1/_NumProcessingIterationsArm1*100)/_MaxNumItemsProcessedArm1;
    std::cout << "Average utilisation of processing robot Arm 1: " << std::setprecision(3) << _RunAverageNumItemsProcessedArm1 <<"%" << std::endl;
    _NumProcessingIterationsArm1++;
}
