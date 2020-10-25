// main.cpp
//
// Main file for simulated conveyor belt
// Initial revision: Donald G Dansereau, 2019
// Completed by: Hendrik Venter

#include <iostream>
#include <cstdlib>      // rand
#include <algorithm>    // std::max

#include "Conveyor.h"
#include "LoadingRobot.h"
#include "ProcessingRobot.h"
#include "OverflowBin.h"


int main()
{
    Conveyor myConveyor;
    LoadingRobot myLoader;
    ProcessingRobot myProcessor;
    OverflowBin myOverflowBin;

    myConveyor.Init();
    myLoader.Init( &myConveyor );
    myProcessor.Init( &myConveyor );
    myOverflowBin.Init( &myConveyor );

   while( 1 )
    {
        myLoader.AddItems();
        myConveyor.Report();

        int _CurrentNumItemsOnConveyor = myConveyor.GetNumOfItemsOnConveyor();
        myProcessor.ProcessItemsArm1(_CurrentNumItemsOnConveyor);
        myConveyor.Report();
        myProcessor.Report(_CurrentNumItemsOnConveyor, 1);

        _CurrentNumItemsOnConveyor = myConveyor.GetNumOfItemsOnConveyor();
        myProcessor.ProcessItemsArm2(_CurrentNumItemsOnConveyor);
        myConveyor.Report();
        myProcessor.Report(_CurrentNumItemsOnConveyor, 2);

        myOverflowBin.OverflowItemAddRemove(_CurrentNumItemsOnConveyor);
        myOverflowBin.Report();
    }
}
