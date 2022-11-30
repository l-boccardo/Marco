#include "stepping.hh"
#include "construction.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"
#include "G4RunManager.hh"
using namespace std;

MySteppingAction::MySteppingAction(MyEventAction *eventAction)
{
    fEventAction = eventAction;
   

}

MySteppingAction::~MySteppingAction()
{}

void MySteppingAction::UserSteppingAction(const G4Step *step)
{   
  G4LogicalVolume *volume = step->GetPreStepPoint()->GetTouchableHandle()->GetVolume()->GetLogicalVolume();
    
  const MyDetectorConstruction *detectorConstruction = static_cast<const MyDetectorConstruction*> (G4RunManager::GetRunManager()->GetUserDetectorConstruction());
    
  G4LogicalVolume *fScoringVolume1 = detectorConstruction->GetScoringVolume1();
  G4LogicalVolume *fScoringVolume2 = detectorConstruction->GetScoringVolume2();
  G4LogicalVolume *fScoringVolume3 = detectorConstruction->GetScoringVolume3();
  G4LogicalVolume *fScoringVolume4 = detectorConstruction->GetScoringVolume4();
  G4LogicalVolume *fScoringVolume5 = detectorConstruction->GetScoringVolume5();
  
  
  G4double mass1 = fScoringVolume1->GetMass();
  G4double mass4 = fScoringVolume4->GetMass();
  G4double mass5 = fScoringVolume5->GetMass();

  
  vector<string> particlename = {"pi0", "e+", "e-", "kaon0L", "mu-", "mu+", "anti_neutron", "neutron","pi-","pi+", "anti_proton", "proton", "gamma", "kaon0S", "anti_kaon0", "kaon0", "kaon-", "kaon+"};
  G4ParticleDefinition *particle = step->GetTrack()->GetDefinition();
  string part = particle->GetParticleName();
  

    if(volume == fScoringVolume2)
      {
	for(int i = 0;i<particlename.size();i++)
	  {
	    if (particlename[i]==part)
	      { if(step->IsFirstStepInVolume())
		  {
		    G4double energy = step->GetTrack()->GetTotalEnergy();
		    energy = energy*MeV;
		    G4ThreeVector vect = step->GetTrack()->GetPosition();
		    G4int id = step ->GetTrack()->GetTrackID();
		    G4double pos = vect.z();
		    pos=pos*mm;
		    G4int ev = G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();
		    fEventAction->AddPosIn(pos,i,id,ev);
		    fEventAction->AddEnIn(energy,i,id,ev);
		   
		  }
		
	      }



	  }

	  
	  
	return;	 
      }


    if(volume == fScoringVolume3)
      {
	  
	  
	for(int i = 0;i<particlename.size();i++)
	  {
	    if (particlename[i]==part)
	      {
		if(step->IsFirstStepInVolume())
		  {
		    G4double energy = step->GetTrack()->GetTotalEnergy();
		    energy = energy*MeV;
		    G4ThreeVector vect = step->GetTrack()->GetPosition();
		    G4double pos = vect.z();
		    pos=pos*mm;
		    G4int id = step ->GetTrack()->GetTrackID();
		    G4int ev = G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();
		    fEventAction->AddPosOut(pos,i,id,ev);
		    //	G4cout << pos << " " << particlename[i]<< G4endl;
		    fEventAction->AddEnOut(energy,i,id,ev);
		   
		  }
	      }
	  }
	return;
      }
    
  

  

    if(volume == fScoringVolume1){
      

      G4double edep = step->GetTotalEnergyDeposit();
      edep = edep/joule;
      // G4double dose=edep/mass1;
      //dose = dose/CLHEP::gray;
      for(int i=0;i<particlename.size();i++){
	  
	if(particlename[i]==part){
	  fEventAction->AddEdep(edep,i);
	  
	}
      }
      
    }


    if(volume == fScoringVolume4){
      

      G4double edep = step->GetTotalEnergyDeposit();
      edep = edep/joule;
      G4double dose=edep/mass4;
      dose = dose/CLHEP::gray;
      for(int i=0;i<particlename.size();i++){
	  
	if(particlename[i]==part){
	  fEventAction->AddEdep(edep,i);
	  
	}
      }
      
    }

     if(volume == fScoringVolume5){
      

      G4double edep = step->GetTotalEnergyDeposit();
      edep = edep/joule;
      G4double dose=edep/mass5;
      dose = dose/CLHEP::gray;
      for(int i=0;i<particlename.size();i++){
	  
	if(particlename[i]==part){
	  fEventAction->AddEdep(edep,i);
	  
	}
      }
      
    }




  return;
}

