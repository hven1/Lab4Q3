// OverflowBin.cpp
//
// Implementation file for a overflow bin that adds and removes items from the conveyor to avoid overloading.
// Completed by: Hendrik Venter


#include <stdlib.h>      // rand
#include <iostream>
#include <algorithm>    // std::max
#include <math.h>

#include "OverflowBin.h"

#include "Conveyor.h"
#include "ProcessingRobot.h"
#include "LoadingRobot.h"

//---------------------------------------------------------------
//Initialises Conveyor
OverflowBin::OverflowBin(Conveyor* WhichConveyor)
{
  _Conveyor = WhichConveyor;

  _OverflowAddRemoveRate = 1;
  _NumItemsOverflowBin = 0;
  _RecordedMaxOverflowBin = 0;

  std::cout << "[OverflowBin CTor] \n" << std::endl;
}

//---------------------------------------------------------------
//Destruct Conveyor
OverflowBin::~OverflowBin()
{
  std::cout << "[OverflowBin DTor] " << std::endl;
}

//---------------------------------------------------------------
//This overflowbin function adds or removes items from the conveyor
void OverflowBin::OverflowItemAddRemove()
{
  int CurrentNumItemsOnConveyor = _Conveyor->GetNumOfItemsOnConveyor();

  //Remove itsms if the conveyor is overloaded
  if ( CurrentNumItemsOnConveyor > 50 )
  {
    _Conveyor->RemoveItems( _OverflowAddRemoveRate);
    _NumItemsOverflowBin = _NumItemsOverflowBin + _OverflowAddRemoveRate;

  }

  //Add items if their is enough spacew on the conveyor and items available in the bin
  else if( (CurrentNumItemsOnConveyor < 10) && (_NumItemsOverflowBin>0) ) {
    _Conveyor->AddItems( _OverflowAddRemoveRate);
    _NumItemsOverflowBin = _NumItemsOverflowBin - _OverflowAddRemoveRate;

  }

  //Record the max amount of items in the present bin
  else if(_NumItemsOverflowBin > _RecordedMaxOverflowBin)
  {
    _RecordedMaxOverflowBin = _NumItemsOverflowBin;
  }
}


//---------------------------------------------------------------
//Report the overflow bin statistics
void OverflowBin::Report()
{
    std::cout << "Items in OverflowBin: " << _NumItemsOverflowBin << std::endl;
    std::cout << "Recorded max items in OverflowBin: " << _RecordedMaxOverflowBin << "\n" << std::endl;
}
