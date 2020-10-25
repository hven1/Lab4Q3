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
void ProcessingRobot::Init( Conveyor* WhichConveyor )
{
    _Conveyor = WhichConveyor;
    _MaxNumItemsProcessedArm1 = 5;
    _TotalNumItemsProcessedArm1 = 0;
    _NumProcessingIterationsArm1 = 1;
    _RunAverageNumItemsProcessedArm1 = 0;
    _MaxNumItemsProcessedArm2 = 1;
    _TotalNumItemsProcessedArm2 = 0;
    _NumProcessingIterationsArm2 = 1;
    _RunAverageNumItemsProcessedArm2 = 0;
}

//---------------------------------------------------------------
// First arm of Processing Robot
void ProcessingRobot::ProcessItemsArm1(int _CurrentNumItemsOnConveyor)
{
  //Check if there is items available to process
  if(_CurrentNumItemsOnConveyor > 0)
  {
    //Calculate current number of items processed
    if( _CurrentNumItemsOnConveyor>=_MaxNumItemsProcessedArm1 )
    {
      _CurrentNumItemsProcessedArm1= _MaxNumItemsProcessedArm1;
    }
    else{
      _CurrentNumItemsProcessedArm1 =_CurrentNumItemsOnConveyor;
    }

    //Process Items
    _Conveyor->RemoveItems( _MaxNumItemsProcessedArm1 );

    //Report on items just processed
    std::cout << "Items processed Arm 1: " << _CurrentNumItemsProcessedArm1 << std::endl;
  }
}

//Second arm of Processing Robot
void ProcessingRobot::ProcessItemsArm2(int _CurrentNumItemsOnConveyor)
{
  //Check if there is items available to process
  if(_CurrentNumItemsOnConveyor > 0)
  {
    //Calculate current number of items processed
    if( _CurrentNumItemsOnConveyor>=_MaxNumItemsProcessedArm2 )
    {
      _CurrentNumItemsProcessedArm2= _MaxNumItemsProcessedArm2;
    }
    else{
      _CurrentNumItemsProcessedArm2 =_CurrentNumItemsOnConveyor;
    }

    //Process Items
    _Conveyor->RemoveItems( _MaxNumItemsProcessedArm2 );

    //Report on items just processed
    std::cout << "Items processed Arm 2: " << _CurrentNumItemsProcessedArm2 << std::endl;
  }
}

//---------------------------------------------------------------
void ProcessingRobot::Report(int _CurrentNumItemsOnConveyor, int NumberOfProcessingArm)
{
  //Select the Processing Robot Arm 1 that is being reported
  if(NumberOfProcessingArm == 1)
  {
    //Recalculate average if their was items processed
    if(_CurrentNumItemsOnConveyor>0)
    {
      //Calculate and report stats for reporting: Arm 1
      _TotalNumItemsProcessedArm1 = _TotalNumItemsProcessedArm1 + _CurrentNumItemsProcessedArm1;
      _RunAverageNumItemsProcessedArm1 = (_TotalNumItemsProcessedArm1/_NumProcessingIterationsArm1*100)/_MaxNumItemsProcessedArm1;

      std::cout << "Total items processed Arm 1: " << _TotalNumItemsProcessedArm1 << std::endl;
    }

    //Report utilisation stats
    std::cout << "Average utilisation of processing robot Arm 1: " << _RunAverageNumItemsProcessedArm1 << std::setprecision(4) <<"%" << std::endl;
    _NumProcessingIterationsArm1++;
  }

  //Select the Processing Robot Arm 2 that is being reported
  if(NumberOfProcessingArm == 2)
  {
    //Recalculate average if their was items processed
    if(_CurrentNumItemsOnConveyor>0)
    {
      //Calculate  and report stats for reporting: Arm 2
      _TotalNumItemsProcessedArm2 = _TotalNumItemsProcessedArm2 + _CurrentNumItemsProcessedArm2;
      _RunAverageNumItemsProcessedArm2 = (_TotalNumItemsProcessedArm2/_NumProcessingIterationsArm2*100)/_MaxNumItemsProcessedArm2;

      std::cout << "Total items processed Arm 2: " << _TotalNumItemsProcessedArm2 << std::endl;
    }

    //Report utilisation stats
    std::cout << "Average utilisation of processing robot Arm 2: " << _RunAverageNumItemsProcessedArm2 << std::setprecision(4) << "%" << std::endl;
    _NumProcessingIterationsArm2++;
  }
}
