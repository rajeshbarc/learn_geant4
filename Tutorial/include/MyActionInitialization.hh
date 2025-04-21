#ifndef MyActionInitialization_HH
#define MyActionInitialization_HH
#include "G4VUserActionInitialization.hh"

#include "MyPrimaryGenerator.hh"

class MyActionInitialization: public G4VUserActionInitialization
{
public: 
MyActionInitialization();
virtual ~MyActionInitialization();
virtual void BuildForMaster() const;
virtual void Build() const;   
};
#endif