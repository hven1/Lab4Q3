// ProcessingRobot.cpp
//
// Implementation file for a robot that processes items off a conveyor belt
// Initial revision: Donald G Dansereau
// Completed by: Hendrik Venter

#include "ProcessingRobot.h"

//---------------------------------------------------------------
//Initialises Conveyor
ProcessingRobot::ProcessingRobot(Conveyor* WhichConveyor)
{
  assert(WhichConveyor != NULL);
  _Conveyor = WhichConveyor;

  _TotProssArm1 = 0;
  _ProssItersArm1 = 1;
  _AvgProssArm1 = 0;

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
  int CurrNumOnConv = _Conveyor->GetItemsConv();
  assert(CurrNumOnConv >=0);

  //Check if there is items available to process
  if(CurrNumOnConv > 0)
  {
    //Calculate current number of items processed
    if(CurrNumOnConv >= _MaxProssArm1 )
    {
      _CurProssArm1 = _MaxProssArm1;
    }

    else
    {
      _CurProssArm1 = CurrNumOnConv;
    }

    //Process Items
    _Conveyor->RemoveItems(_MaxProssArm1 );

    //Report on items just processed
    std::cout << "Items processed Arm 1: " << _CurProssArm1 << std::endl;
  }
}

//---------------------------------------------------------------
//Reporting function for the first processing arm
void ProcessingRobot::Report()
{
    //Calculate and report stats for reporting: Arm 1
    _TotProssArm1 += _CurProssArm1;
    std::cout << "Total items processed Arm 1: " << std::setprecision(4)
      << _TotProssArm1 << std::endl;

    //Report utilisation stats
    _AvgProssArm1 = (_TotProssArm1/_ProssItersArm1*100)/_MaxProssArm1;
    std::cout << "Average utilisation of processing robot Arm 1: "
      << std::setprecision(3) << _AvgProssArm1 <<"%" << std::endl;
    _ProssItersArm1++;
}
