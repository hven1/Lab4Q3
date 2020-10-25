// ProcessingRobot.h
//
// Header file for a robot that processes items off a conveyor belt
// Initial revision: Donald G Dansereau, 2019
// Completed by: Hendrik Venter

#ifndef _PROCESSINGROBOT2ND_H
#define _PROCESSINGROBOT2ND_H

#include "Conveyor.h"
#include "LoadingRobot.h"

#include <iostream>
#include <iomanip>
#include <cstdlib>      // rand
#include <algorithm>    // std::max
#include <math.h>
#include <cassert>

//-------------------------------------------------------------------
// Simulate a processing robot that removes items from a conveyor belt.
// Note that Init sets a pointer to the conveyor the robot will use.
class ProcessingRobot2nd
{
    public:
      ProcessingRobot2nd(Conveyor* WhichConveyor);
      ~ProcessingRobot2nd();
      void ProcessItems();
      void Report();

    private:
      Conveyor* _Conveyor;
      const double _MaxProssArm2 = 1;
      double _CurProssArm2;
      double _TotProssArm2;
      double _AvgProssArm2;
      double _ProssItersArm2;
};

#endif //_PROCESSINGROBOT2ND_H
