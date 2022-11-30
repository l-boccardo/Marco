#ifndef EVENT_HH
#define EVENT_HH

#include "G4UserEventAction.hh"
#include "G4Event.hh"

#include "g4root.hh"

#include "run.hh"
#include <vector>

using namespace std;

class MyEventAction : public G4UserEventAction
{
public:
  MyEventAction(MyRunAction*);
  ~MyEventAction();
  
  virtual void BeginOfEventAction(const G4Event*);
  virtual void EndOfEventAction(const G4Event*);
  
  void AddEdep(G4double edep, G4int i) { fEdep[i] += edep; }
  void AddPosIn(G4double x,G4int i, G4int ID,G4int ev){

    G4AnalysisManager *man = G4AnalysisManager::Instance();
    man->FillNtupleDColumn(5*i+1,0,x);
    man->FillNtupleIColumn(5*i+1,1,ID);
    man->FillNtupleIColumn(5*i+1,2,ev);
    man->AddNtupleRow(5*i+1);
    
    
    
  }
  void AddPosOut(G4double x, G4int i,G4int ID,G4int ev){
    G4AnalysisManager *man = G4AnalysisManager::Instance();
    man->FillNtupleDColumn(5*i+2,0,x);
    man->FillNtupleIColumn(5*i+2,1,ID);
    man->FillNtupleIColumn(5*i+2,2,ev);
    man->AddNtupleRow(5*i+2);
    




  }
  void AddEnIn(G4double x, int i,G4int ID,G4int ev){
    G4AnalysisManager *man = G4AnalysisManager::Instance();
    man->FillNtupleDColumn(5*i+3,0,x);
    man->FillNtupleIColumn(5*i+3,1,ID);
    man->FillNtupleIColumn(5*i+3,2,ev);
    man->AddNtupleRow(5*i+3);


  }
  void AddEnOut(G4double x, int i,G4int ID,G4int ev){

    G4AnalysisManager *man = G4AnalysisManager::Instance();
    man->FillNtupleDColumn(5*i+4,0,x);
    man->FillNtupleIColumn(5*i+4,1,ID);
    man->FillNtupleIColumn(5*i+4,2,ev);
    man->AddNtupleRow(5*i+4);
    }
  
private:
  vector<G4double> fEdep{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  vector<vector<G4double>> xin{{0.},{0.},{0.},{0.},{0.},{0.},{0.},{0.},{0.},{0.},{0.},{0.},{0.},{0.},{0.},{0.},{0.},{0.}};
  vector<vector<G4double>> ein{{0.},{0.},{0.},{0.},{0.},{0.},{0.},{0.},{0.},{0.},{0.},{0.},{0.},{0.},{0.},{0.},{0.},{0.}};
  vector<vector<G4double>> eout{{0.},{0.},{0.},{0.},{0.},{0.},{0.},{0.},{0.},{0.},{0.},{0.},{0.},{0.},{0.},{0.},{0.},{0.}};
  vector<vector<G4double>> xout{{0.},{0.},{0.},{0.},{0.},{0.},{0.},{0.},{0.},{0.},{0.},{0.},{0.},{0.},{0.},{0.},{0.},{0.}};
  

};


#endif
