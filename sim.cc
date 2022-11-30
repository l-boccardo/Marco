#include <iostream>
#include "G4RunManager.hh"
#include "G4MTRunManager.hh"
#include "G4UImanager.hh"
#include "G4VisManager.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"
#include "G4GeneralParticleSource.hh"

#include "construction.hh"
#include "physics.hh"
#include "action.hh"
#include "event.hh"
#include "primary.hh"
#include "run.hh"
#include "stepping.hh"
int main(int argc, char** argv)
{
  G4UIExecutive *ui = 0;


  G4MTRunManager *runManager = new G4MTRunManager();
  runManager->SetNumberOfThreads(40);
  


  runManager->SetUserInitialization(new MyDetectorConstruction());
  runManager->SetUserInitialization(new MyPhysicsList());
  runManager->SetUserInitialization(new MyActionInitialization());
 

  
  if(argc == 1)
    {
  ui = new G4UIExecutive(argc, argv); //user interface
    }
  G4VisManager *visManager = new G4VisExecutive();
  visManager->Initialize();
  G4UImanager *UImanager = G4UImanager::GetUIpointer();

   if(ui)
    {
        UImanager->ApplyCommand("/control/execute vis.mac");
        ui->SessionStart();
    }
    else
    {
        G4String command = "/control/execute ";
        G4String fileName = argv[1];
        UImanager->ApplyCommand(command+fileName);
    }

    
 
  
  
  return 0;
}
