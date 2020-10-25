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
      OverflowBin(Conveyor* WhichConveyor);
      ~OverflowBin();
      void OverflowItemAddRemove();
      void Report();
    private:
      Conveyor* _Conveyor;
      const int _OverflowAddRemoveRate = 1;
      int _NumInOflowBin;
      int _RecMaxOflowBin;
};

#endif //_OVERFLOWBIN_H
