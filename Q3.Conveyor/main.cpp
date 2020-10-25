// main.cpp
//
// Main file for simulated conveyor belt
// Initial revision: Donald G Dansereau, 2019
// Completed by: Hendrik Venter

#include <iostream>
#include <cstdlib>      // rand
#include <algorithm>    // std::max
#include <memory>

#include "Conveyor.h"
#include "LoadingRobot.h"
#include "ProcessingRobot.h"
#include "ProcessingRobot2nd.h"
#include "OverflowBin.h"
#include <time.h>

int main()
{
  //Use current time as seed for rand()
  std::srand(time(0));

  //Construct all items required for program
  Conveyor* myConveyor = new Conveyor();
  LoadingRobot* myLoader = new LoadingRobot(myConveyor);
  ProcessingRobot* myProcessor = new ProcessingRobot(myConveyor);
  ProcessingRobot2nd* myProcessor2nd = new ProcessingRobot2nd(myConveyor);
  OverflowBin* myOverflowBin = new OverflowBin(myConveyor);

 //while(1)
 for(int i=0; i<2; i++)
  {
      myLoader->AddItems();
      myConveyor->Report();

      myProcessor->ProcessItems( );
      myConveyor->Report();
      myProcessor->Report( );

      myProcessor2nd->ProcessItems();
      myConveyor->Report();
      myProcessor2nd->Report();

      myOverflowBin->OverflowItemAddRemove();
      myOverflowBin->Report();
  }

  //Destruct all items required for program
  delete myConveyor;
  delete myLoader;
  delete myProcessor;
  delete myProcessor2nd;
  delete myOverflowBin;
}
