#include <iostream>
#include "G4RunManager.hh"
#include "G4MTRunManager.hh"
#include "G4UImanager.hh"
#include "G4VisManager.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"

#include "MyPhysicsList.hh"
#include "MyDetectorConstruction.hh"

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
    G4VisManager *visManager = new G4VisExecutive;
    visManager->Initialise();
    G4UImanager * uiManagr = G4UImanager::GetUIpointer();
    ui->SessionStart();
    return 1;
}
