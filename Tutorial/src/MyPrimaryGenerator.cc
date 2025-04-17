#include "MyPrimaryGenerator.hh"
MyPrimaryGenerator::MyPrimaryGenerator()
{
fParticleGun = new G4ParticleGun(1);
//Particle position
G4double x =0.0 *m;
G4double y =0.0 *m;
G4double z =0.0 *m;
G4ThreeVector pos(x,y,z);
G4double px =0.0 *m;
G4double py =0.0 *m;
G4double pz =0.0 *m;
G4ThreeVector mom(px,py,pz);

G4ParticleTable *particleTable = G4ParticleTable::GetParticleTable();
G4ParticleDefinition *particle = particleTable->FindParticle("e+");
fParticleGun->SetParticlePosition(pos);
fParticleGun->SetParticleMomentum(mom);
fParticleGun->SetParticleEnergy(1.*GeV);
fParticleGun->SetParticleDefinition(particle);

}
MyPrimaryGenerator::~MyPrimaryGenerator()
{
    delete fParticleGun;
}
void MyPrimaryGenerator::GeneratePrimaries(G4Event *anEvent)
{
 fParticleGun->GeneratePrimaryVertex(anEvent);

}