// Conveyor.h
//
// Header file for a simulated conveyor belt
// Initial revision: Donald G Dansereau, 2019
// Completed by: Hendrik Venter

#ifndef _CONVEYOR_H
#define _CONVEYOR_H

#include <iostream>
#include <algorithm>
#include <cassert>

//---------------------------------------------------------------
// Simulate a conveyor belt. This version just counts how many
// objects are on the belt, and accepts requests to add and remove
// objects.
class Conveyor
{
    public:
      Conveyor();
      ~Conveyor();
      void AddItems(int n);
      void RemoveItems(int n);
      void Report();
      int GetItemsConv()
      {
        return _NumOnConv;
      }

    private:
      int _NumOnConv;
      const int _MaxOnConv = 75;
};

#endif //_CONVEYOR_H
