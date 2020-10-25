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
#include "ProcessingRobot2nd.h"
#include "OverflowBin.h"


int main()
{
    //std::shared_ptr<Speaker>(new EnglishSpeaker())
    Conveyor myConveyor;
    LoadingRobot myLoader;
    ProcessingRobot myProcessor;
    ProcessingRobot2nd myProcessor2nd;
    OverflowBin myOverflowBin;

    myConveyor.Init();
    myLoader.Init( &myConveyor );
    myProcessor.Init(&myConveyor, &myLoader);
    myProcessor2nd.Init(&myConveyor, &myLoader);
    myOverflowBin.Init(&myConveyor, &myLoader);

   while(1)
    {
        myLoader.AddItems();
        myConveyor.Report();

        myProcessor.ProcessItems( );
        myConveyor.Report();
        myProcessor.Report( );

        myProcessor2nd.ProcessItems();
        myConveyor.Report();
        myProcessor2nd.Report();

        myOverflowBin.OverflowItemAddRemove();
        myOverflowBin.Report();
    }
}
