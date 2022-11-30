#include "event.hh"
#include "G4UnitsTable.hh"
#include "run.hh"
#include "G4SystemOfUnits.hh"
#include <iostream>
#include <vector>
#include <fstream>
#include "detector.hh"

using namespace std;

MyEventAction::MyEventAction(MyRunAction*)
{}

MyEventAction::~MyEventAction()
{}

void MyEventAction::BeginOfEventAction(const G4Event*)
{}




void MyEventAction::EndOfEventAction(const G4Event*)
{
 
  vector<string> particlename = {"pi0", "e+", "e-", "kaon0L", "mu-", "mu+", "anti_neutron", "neutron","pi-","pi+", "anti_proton", "proton", "gamma", "kaon0S", "anti_kaon0", "kaon0", "kaon-", "kaon+"};
  
  G4AnalysisManager *man = G4AnalysisManager::Instance();

  for(int i = 0; i< fEdep.size();i++){
  
    man->FillNtupleDColumn(5*i, 0, fEdep[i]);
    
    man->AddNtupleRow(5*i);
  }
  
    

  
  


}

