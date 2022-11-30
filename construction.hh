#ifndef COSTRUCTION_HH
#define CONSTRUCTION_HH


#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4PVPlacement.hh"
#include"G4NistManager.hh"
#include "G4Material.hh"
#include "G4Torus.hh"
#include "G4VisAttributes.hh"
#include "G4SDManager.hh"
#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"
#include "detector.hh"
#include "G4ThreeVector.hh"



class MyDetectorConstruction : public G4VUserDetectorConstruction
{
public:
  MyDetectorConstruction();
  ~MyDetectorConstruction();

  virtual G4VPhysicalVolume *Construct();

  G4LogicalVolume* GetScoringVolume1() const { return fScoringVolume1; }
  G4LogicalVolume* GetScoringVolume2() const { return fScoringVolume2; }
  G4LogicalVolume* GetScoringVolume3() const { return fScoringVolume3; }
  G4LogicalVolume* GetScoringVolume4() const { return fScoringVolume4; }
  G4LogicalVolume* GetScoringVolume5() const { return fScoringVolume5; }
  void UpdateDeposit(G4double);
  G4double GetDose() const;
  void ConstructSD();
  G4LogicalVolume* fIntCryostat() const{return logicIntCryostat;}
  G4LogicalVolume* fExtCryostat() const{return logicExtCryostat;}

  private:
  G4LogicalVolume *logicExtInsulation;
  G4LogicalVolume *logicTracker;
  G4LogicalVolume *logicBeam;
  G4LogicalVolume *logicCalorimeter;
  G4LogicalVolume *logicIntCryostat;
  G4LogicalVolume *logicExtCryostat;
  G4double fDeposit;
  G4LogicalVolume*  fScoringVolume1;
  G4LogicalVolume*  fScoringVolume2;
  G4LogicalVolume*  fScoringVolume3;
  G4LogicalVolume*  fScoringVolume4;
  G4LogicalVolume*  fScoringVolume5;
  
};



#endif
