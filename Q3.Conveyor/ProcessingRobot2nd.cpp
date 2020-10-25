// ProcessingRobot.cpp
//
// Implementation file for a robot that processes items off a conveyor belt
// Initial revision: Donald G Dansereau
// Completed by: Hendrik Venter

#include "ProcessingRobot2nd.h"

#include <iostream>
#include <iomanip>
#include <cstdlib>      // rand
#include <algorithm>    // std::max
#include <math.h>

//---------------------------------------------------------------
//Initialises Conveyor
ProcessingRobot2nd::ProcessingRobot2nd(Conveyor* WhichConveyor)
{
  _Conveyor = WhichConveyor;
  _MaxNumItemsProcessedArm2 = 1;
  _TotalNumItemsProcessedArm2 = 0;
  _NumProcessingIterationsArm2 = 1;
  _RunAverageNumItemsProcessedArm2 = 0;

  std::cout << "[ProcessingRobot 2 CTor] " << std::endl;
}

//---------------------------------------------------------------
//Destruct Conveyor
ProcessingRobot2nd::~ProcessingRobot2nd()
{
  std::cout << "[ProcessingRobot 2 DTor] " << std::endl;
}

//---------------------------------------------------------------
//Second arm of Processing Robot
void ProcessingRobot2nd::ProcessItems( )
{
  int CurrentNumItemsOnConveyor = _Conveyor->GetNumOfItemsOnConveyor();
  //Check if there is items available to process
  if(CurrentNumItemsOnConveyor > 0)
  {
    //Calculate current number of items processed
    if( CurrentNumItemsOnConveyor >= _MaxNumItemsProcessedArm2 )
    {
      _CurrentNumItemsProcessedArm2 = _MaxNumItemsProcessedArm2;
    }
    else{
      _CurrentNumItemsProcessedArm2 = CurrentNumItemsOnConveyor;
    }

    //Process Items
    _Conveyor->RemoveItems( _MaxNumItemsProcessedArm2 );

    //Report on items just processed
    std::cout << "Items processed Arm 2: " << _CurrentNumItemsProcessedArm2 << std::endl;
  }
}

//---------------------------------------------------------------
void ProcessingRobot2nd::Report()
{
    //Calculate  and report stats for reporting: Arm 2
    _TotalNumItemsProcessedArm2 = _TotalNumItemsProcessedArm2 + _CurrentNumItemsProcessedArm2;
    std::cout << "Total items processed Arm 2: " << _TotalNumItemsProcessedArm2 << std::endl;

    //Report utilisation stats
    _RunAverageNumItemsProcessedArm2 = (_TotalNumItemsProcessedArm2/_NumProcessingIterationsArm2*100)/_MaxNumItemsProcessedArm2;
    std::cout << "Average utilisation of processing robot Arm 2: " << std::setprecision(4)<< _RunAverageNumItemsProcessedArm2 << "%" << std::endl;
    _NumProcessingIterationsArm2++;
}
