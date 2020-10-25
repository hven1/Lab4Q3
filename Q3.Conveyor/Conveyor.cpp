// Conveyor.cpp
//
// Implementation file for a simulated conveyor belt
// Initial revision: Donald G Dansereau, 2019
// Completed by: Hendrik Venter

#include <iostream>
#include <algorithm>

#include "Conveyor.h"

//---------------------------------------------------------------
//Initialises Conveyor
Conveyor::Conveyor(): _NumItemsOnConveyor(0), _MaxNumItemsOnConveyor(75)
{
  std::cout << "[Conveyor CTor] " << std::endl;
}

//---------------------------------------------------------------
//Destruct Conveyor
Conveyor::~Conveyor()
{
  std::cout << "[Conveyor DTor] " << std::endl;

}

//---------------------------------------------------------------
//Add items to Conveyor
void Conveyor::AddItems( int n )
{
    _NumItemsOnConveyor += n;

    //Report overflow if conveyor exceeds max capacity
    if (_NumItemsOnConveyor > _MaxNumItemsOnConveyor)
    {
      std::cout << "Conveyor Overload by " << _NumItemsOnConveyor << " items on the conveyor - Max Allowed " << _MaxNumItemsOnConveyor <<std::endl;
      exit(0);
    }
}

//---------------------------------------------------------------
//Remove items from conveyor
void Conveyor::RemoveItems( int n )
{
    // Note that we cannot have a negative number of items on belt
    _NumItemsOnConveyor = std::max(0, _NumItemsOnConveyor-n);
}

//---------------------------------------------------------------
//Report the amount of items on conveyor
void Conveyor::Report()
{
    std::cout << "Items on conveyor: " << _NumItemsOnConveyor << std::endl;
}
