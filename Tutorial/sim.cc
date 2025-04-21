#include <iostream>
#include "G4RunManager.hh"
#include "G4MTRunManager.hh"
#include "G4UImanager.hh"
#include "G4VisManager.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"

#include "MyPhysicsList.hh"
#include "MyDetectorConstruction.hh"
#include "MyActionInitialization.hh"


int main(int argc, char** argv){

    G4UIExecutive *ui = new G4UIExecutive(argc, argv);
    #ifdef G4MULTITHREADED
    G4MTRunManager *runManager = new G4MTRunManager;
    #else
    G4RunManager *runManager = new G4RunManager;
    #endif
    // Physcis list
    runManager->SetUserInitialization(new MyPhysicsList);
    // Detector Construction
    runManager->SetUserInitialization(new MyDetectorConstruction);
    // Action Initialization
    runManager->SetUserInitialization(new MyActionInitialization);
    G4VisManager *visManager = new G4VisExecutive;
    visManager->Initialise();
    G4UImanager * uiManager = G4UImanager::GetUIpointer();
    uiManager->ApplyCommand("/control/execute vis.mac");
    ui->SessionStart();
    return 1;
}
