// ProcessingRobot.h
//
// Header file for a robot that processes items off a conveyor belt
// Initial revision: Donald G Dansereau, 2019
// Completed by: Hendrik Venter

#ifndef _PROCESSINGROBOT_H
#define _PROCESSINGROBOT_H

#include "Conveyor.h"
#include "LoadingRobot.h"

//-------------------------------------------------------------------
// Simulate a processing robot that removes items from a conveyor belt.
// Note that Init sets a pointer to the conveyor the robot will use.
class ProcessingRobot
{
    public:
      ProcessingRobot(Conveyor* WhichConveyor);
      ~ProcessingRobot();
      void ProcessItems();
      void Report();

    private:
      Conveyor* _Conveyor;
      const double _MaxProssArm1 = 5;
      double _CurProssArm1;
      double _TotProssArm1;
      double _AvgProssArm1;
      double _ProssItersArm1;
};

#endif //_PROCESSINGROBOT_H
