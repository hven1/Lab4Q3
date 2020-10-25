// Conveyor.h
//
// Header file for a simulated conveyor belt
// Initial revision: Donald G Dansereau, 2019
// Completed by: Hendrik Venter

#ifndef _CONVEYOR_H
#define _CONVEYOR_H

//---------------------------------------------------------------
// Simulate a conveyor belt. This version just counts how many
// objects are on the belt, and accepts requests to add and remove
// objects.
class Conveyor
{
    public:
      Conveyor();
      ~Conveyor();

      void AddItems( int n );
      void RemoveItems( int n );
      void Report();

      int GetNumOfItemsOnConveyor( )
      {
        return _NumItemsOnConveyor;
      }

    private:
      int _NumItemsOnConveyor;
      int _MaxNumItemsOnConveyor;
};



#endif
