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
  _TotProssArm2 = 0;
  _ProssItersArm2 = 1;
  _AvgProssArm2 = 0;

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
  int CurrNumOnConv = _Conveyor->GetItemsConv();
  //Check if there is items available to process
  if(CurrNumOnConv > 0)
  {
    //Calculate current number of items processed
    if( CurrNumOnConv >= _MaxProssArm2 )
    {
      _CurProssArm2 = _MaxProssArm2;
    }
    else{
      _CurProssArm2 = CurrNumOnConv;
    }

    //Process Items
    _Conveyor->RemoveItems(_MaxProssArm2);

    //Report on items just processed
    std::cout << "Items processed Arm 2: " << _CurProssArm2 << std::endl;
  }
}

//---------------------------------------------------------------
void ProcessingRobot2nd::Report()
{
    //Calculate  and report stats for reporting: Arm 2
    _TotProssArm2 = _TotProssArm2 + _CurProssArm2;
    std::cout << "Total items processed Arm 2: " << _TotProssArm2 << std::endl;

    //Report utilisation stats
    _AvgProssArm2 = (_TotProssArm2/_ProssItersArm2*100)/_MaxProssArm2;
    std::cout << "Average utilisation of processing robot Arm 2: "
      << std::setprecision(4)<< _AvgProssArm2 << "%" << std::endl;
    _ProssItersArm2++;
}
