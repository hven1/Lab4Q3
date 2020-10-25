// OverflowBin.h
//
// Header file for the overflow bin
// Completed by: Hendrik Venter

#ifndef _OVERFLOWBIN_H
#define _OVERFLOWBIN_H

#include "Conveyor.h"
#include "ProcessingRobot.h"
#include "LoadingRobot.h"


//-------------------------------------------------------------------
// Acts as a buffer in the case of heavy utlisation of conveyor
class OverflowBin
{
    public:
        void Init(Conveyor* WhichConveyor, LoadingRobot* WhichLoadingRobot);
        void OverflowItemAddRemove();
        void Report();
    private:
        Conveyor* _Conveyor;
        LoadingRobot* _LoadingRobot;

        int _OverflowAddRemoveRate;
        int _NumItemsOverflowBin;
        int _RecordedMaxOverflowBin;
};


#endif
