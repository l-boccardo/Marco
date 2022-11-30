#ifndef STEPPING_HH
#define STEPPING_HH

#include "G4UserSteppingAction.hh"
#include "G4Step.hh"
#include "G4Gamma.hh"
#include "G4Electron.hh"
#include "detector.hh"

#include "event.hh"

class MySteppingAction : public G4UserSteppingAction
{
public:
  MySteppingAction(MyEventAction* eventAction);
  ~MySteppingAction();
  //  static MySteppingAction* Instance();
  virtual void UserSteppingAction(const G4Step*);
  // G4LogicalVolume* GetVolume() const { return fVolume; }
  G4double ReturnDose();
  
private:
  MyEventAction *fEventAction;
  G4double stepEdep;
 
};

#endif
