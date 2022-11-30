#include "run.hh"
#include "construction.hh"
#include "detector.hh"
#include <fstream>

using namespace std;

MyRunAction::MyRunAction()
{
    G4AnalysisManager *man = G4AnalysisManager::Instance();
    vector<string> particlename = {"pi0", "e+", "e-", "kaon0L", "mu-", "mu+", "anti_neutron", "neutron","pi-","pi+", "anti_proton", "proton", "gamma", "kaon0S", "anti_kaon0", "kaon0", "kaon-", "kaon+"};

    for(int i=0;i<particlename.size();i++){
      string sc = "Scoring"+particlename[i];
      const char *namescore = sc.c_str(); 

    man->CreateNtuple(namescore, namescore);
    man->CreateNtupleDColumn("fEdep");
    man->FinishNtuple(5*i);

    string coin = particlename[i]+"In X";
    const char *namecountin = coin.c_str();

    man->CreateNtuple(namecountin, namecountin);
    man->CreateNtupleDColumn("inx");
    man->CreateNtupleIColumn("inxID");
    man->CreateNtupleIColumn("inxev");
    man->FinishNtuple(5*i+1);

     string coout = particlename[i]+"Out X";
     const char *namecountout = coout.c_str();

    man->CreateNtuple(namecountout, namecountout);
    man->CreateNtupleDColumn("outx");
    man->CreateNtupleIColumn("outxID");
    man->CreateNtupleIColumn("outxev");
    man->FinishNtuple(5*i+2);

    string ein = particlename[i]+"In E";
     const char *enin = ein.c_str();

    man->CreateNtuple(enin, enin);
    man->CreateNtupleDColumn("inen");
    man->CreateNtupleIColumn("inenID");
    man->CreateNtupleIColumn("inenev");
    man->FinishNtuple(5*i+3);

    string eout = particlename[i]+"Out E";
     const char *enout = eout.c_str();

    man->CreateNtuple(enout, enout);
    man->CreateNtupleDColumn("outen");
    man->CreateNtupleIColumn("outenID");
    man->CreateNtupleIColumn("outenev");
    man->FinishNtuple(5*i+4);

    
    }
    
    
   
}

MyRunAction::~MyRunAction()
{}

void MyRunAction::BeginOfRunAction(const G4Run* run)
{
    G4AnalysisManager *man = G4AnalysisManager::Instance();

        
    G4int runID = run->GetRunID();

    std::stringstream strRunID;
    strRunID << runID;
    man->OpenFile("output"+strRunID.str()+".root");
    
    
    


}

void MyRunAction::EndOfRunAction(const G4Run*)
{
  G4AnalysisManager *man = G4AnalysisManager::Instance();
    man->Write();
    man->CloseFile();

    
}

