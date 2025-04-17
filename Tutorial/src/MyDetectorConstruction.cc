#include "MyDetectorConstruction.hh"

MyDetectorConstruction::MyDetectorConstruction()
{

}
MyDetectorConstruction::~MyDetectorConstruction()
{

}

G4VPhysicalVolume *MyDetectorConstruction::Construct()
{

    G4bool checkOverlaps = true;
    G4NistManager *nist = G4NistManager::Instance();
    G4Material *wordMat = nist->FindOrBuildMaterial("G4_AIR");
    G4double xWorld = 1. * m;
    G4double yWorld = 1.*m;
    G4double zWorld = 1.*m;
    G4Box *solidWord = new G4Box("solidWorld",0.5*xWorld, 0.5*yWorld, 0.5*zWorld);
    G4LogicalVolume *logicWorld = new G4LogicalVolume(solidWord, wordMat,"logicalWorld");
    G4VPhysicalVolume *physWorld = new G4PVPlacement(0, G4ThreeVector(0.0, 0.0, 0.0), logicWorld,"physWorld", 0, false, 0, checkOverlaps);
    return physWorld;

}

