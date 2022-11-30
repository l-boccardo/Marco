#include "physics.hh"

MyPhysicsList::MyPhysicsList()
{
  RegisterPhysics (new G4EmStandardPhysics());
  RegisterPhysics (new G4OpticalPhysics());
  RegisterPhysics(new G4DecayPhysics());
  RegisterPhysics(new G4RadioactiveDecayPhysics());
  RegisterPhysics( new G4HadronPhysicsFTFP_BERT_HP());
  RegisterPhysics( new G4HadronElasticPhysicsHP());
  RegisterPhysics( new G4HadronPhysicsFTFP_BERT_HP());
  RegisterPhysics( new G4IonPhysics());
  RegisterPhysics( new G4StoppingPhysics());
}

MyPhysicsList::~MyPhysicsList()
{}
