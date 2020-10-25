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

  _NumInOflowBin = 0;
  _RecMaxOflowBin = 0;

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
  int CurrNumOnConv = _Conveyor->GetItemsConv();

  //Remove itsms if the conveyor is overloaded
  if ( CurrNumOnConv > 50 )
  {
    _Conveyor->RemoveItems(_OverflowAddRemoveRate);
    _NumInOflowBin = _NumInOflowBin + _OverflowAddRemoveRate;

  }

  //Add items if their is enough spacew on the conveyor and items
  //available in the bin
  else if( (CurrNumOnConv < 10) && (_NumInOflowBin>0) ) {
    _Conveyor->AddItems(_OverflowAddRemoveRate);
    _NumInOflowBin = _NumInOflowBin - _OverflowAddRemoveRate;

  }

  //Record the max amount of items in the present bin
  else if(_NumInOflowBin > _RecMaxOflowBin)
  {
    _RecMaxOflowBin = _NumInOflowBin;
  }
}


//---------------------------------------------------------------
//Report the overflow bin statistics
void OverflowBin::Report()
{
    std::cout << "Items in OverflowBin: " << _NumInOflowBin << std::endl;
    std::cout << "Recorded max items in OverflowBin: " << _RecMaxOflowBin
      << "\n" << std::endl;
}
