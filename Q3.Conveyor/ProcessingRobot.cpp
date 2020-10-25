// ProcessingRobot.cpp
//
// Implementation file for a robot that processes items off a conveyor belt
// Initial revision: Donald G Dansereau
// Completed by: Hendrik Venter

#include <iostream>
#include <iomanip>
#include <cstdlib>      // rand
#include <algorithm>    // std::max
#include <math.h>
#include "ProcessingRobot.h"

//---------------------------------------------------------------
//Initialises the Processing Robot
void ProcessingRobot::Init(Conveyor* WhichConveyor, LoadingRobot* WhichLoadingRobot)
{
  _Conveyor = WhichConveyor;
  _LoadingRobot = WhichLoadingRobot;

  _MaxNumItemsProcessedArm1 = 5;
  _TotalNumItemsProcessedArm1 = 0;
  _NumProcessingIterationsArm1 = 1;
  _RunAverageNumItemsProcessedArm1 = 0;
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
    int CurrentNumItemsOnConveyor = _Conveyor->GetNumOfItemsOnConveyor();
    //Recalculate average if their was items processed
    if(CurrentNumItemsOnConveyor>0)
    {
      //Calculate and report stats for reporting: Arm 1
      _TotalNumItemsProcessedArm1 = _TotalNumItemsProcessedArm1 + _CurrentNumItemsProcessedArm1;
      _RunAverageNumItemsProcessedArm1 = (_TotalNumItemsProcessedArm1/_NumProcessingIterationsArm1*100)/_MaxNumItemsProcessedArm1;

      std::cout << "Total items processed Arm 1: " << _TotalNumItemsProcessedArm1 << std::endl;
    }

    //Report utilisation stats
    std::cout << "Average utilisation of processing robot Arm 1: " << _RunAverageNumItemsProcessedArm1 << std::setprecision(4) <<"%" << std::endl;
}
