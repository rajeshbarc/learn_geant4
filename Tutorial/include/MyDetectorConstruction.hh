#ifndef MyDetectorConstruction_HH
#define MyDetectorConstruction_HH
#include "G4VUserDetectorConstruction.hh"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4VPhysicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4Material.hh"
#include "G4NistManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4UnitsTable.hh"

class MyDetectorConstruction : public G4VUserDetectorConstruction
{
    public:
    MyDetectorConstruction();
    virtual ~MyDetectorConstruction();
    virtual G4VPhysicalVolume *Construct();
};

#endif