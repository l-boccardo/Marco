#include "primary.hh"

#include "G4LogicalVolumeStore.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4RunManager.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"
#include "G4UImanager.hh"
#include "G4GeneralParticleSource.hh"
#include <fstream>
#include "G4ParticleMomentum.hh"
#include <vector>
#include <map>

MyPrimaryGeneratorAction::MyPrimaryGeneratorAction()
: G4VUserPrimaryGeneratorAction(),
  fParticleGun(0)
  
{
  
  fParticleGun = new G4GeneralParticleSource();
  
}



MyPrimaryGeneratorAction::~MyPrimaryGeneratorAction()
{
  delete fParticleGun;
}



void MyPrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
  fParticleGun->GeneratePrimaryVertex(anEvent);
}
