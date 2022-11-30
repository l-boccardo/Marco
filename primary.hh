#ifndef PRIMARY_HH
#define PRIMARY_HH

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"
#include "globals.hh"
#include "G4GeneralParticleSource.hh"

class G4GeneralParticleSource;
class G4Event;
class G4Box;

class MyPrimaryGeneratorAction: public G4VUserPrimaryGeneratorAction
{
public:
  MyPrimaryGeneratorAction();
  virtual ~MyPrimaryGeneratorAction();

   virtual void GeneratePrimaries(G4Event*);

  //const G4GeneralParticleSource* GetParticleGun() const { return fParticleGun; }
  
  private:
    G4GeneralParticleSource*  fParticleGun; // pointer a to G4 gun class
};

#endif
