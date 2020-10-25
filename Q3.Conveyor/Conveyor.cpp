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
Conveyor::Conveyor(): _NumOnConv(0)
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
void Conveyor::AddItems(int n)
{
    _NumOnConv += n;

    //Report overflow if conveyor exceeds max capacity
    if (_NumOnConv > _MaxOnConv)
    {
      std::cout << "Conveyor Overload by " << _NumOnConv
        << " items on the conveyor - Max Allowed " << _MaxOnConv <<std::endl;
      exit(0);
    }
}

//---------------------------------------------------------------
//Remove items from conveyor
void Conveyor::RemoveItems( int n )
{
    // Note that we cannot have a negative number of items on belt
    _NumOnConv = std::max(0, _NumOnConv-n);
}

//---------------------------------------------------------------
//Report the amount of items on conveyor
void Conveyor::Report()
{
    std::cout << "Items on conveyor: " << _NumOnConv << std::endl;
}
