// ProcessingRobot.h
//
// Header file for a robot that processes items off a conveyor belt
// Initial revision: Donald G Dansereau, 2019
// Completed by: Hendrik Venter

#ifndef _PROCESSINGROBOT2ND_H
#define _PROCESSINGROBOT2ND_H

#include "Conveyor.h"
#include "LoadingRobot.h"

//-------------------------------------------------------------------
// Simulate a processing robot that removes items from a conveyor belt.
// Note that Init sets a pointer to the conveyor the robot will use.
class ProcessingRobot2nd
{
    public:
        void Init(Conveyor* WhichConveyor, LoadingRobot* WhichLoadingRobot);
        void ProcessItems();
        void Report();

    private:
        Conveyor* _Conveyor;
        LoadingRobot* _LoadingRobot;

        double _MaxNumItemsProcessedArm2;
        double _CurrentNumItemsProcessedArm2;
        double _TotalNumItemsProcessedArm2;
        double _RunAverageNumItemsProcessedArm2;
        double _NumProcessingIterationsArm2;
};

#endif
