#include "construction.hh"
#include "detector.hh"
#include <fstream>
#include "G4SubtractionSolid.hh"
#include "G4IntersectionSolid.hh"

using namespace std;



//1

MyDetectorConstruction::MyDetectorConstruction()
{}

MyDetectorConstruction::~MyDetectorConstruction()
{}

//2
G4VPhysicalVolume *MyDetectorConstruction::Construct()
{
  // ----------------------------------------------- MATERIALS -------------------------------------------------------------

  G4NistManager *nist = G4NistManager::Instance();
  
  //world
  G4Material *worldMat = nist->FindOrBuildMaterial("G4_AIR");
  //vacuum

  G4double densvac = CLHEP::universe_mean_density;
  G4Material *vacuum = new G4Material("vacuum", densvac, 2);
  vacuum->AddElement(nist->FindOrBuildElement("N"),.7);
  vacuum->AddElement(nist->FindOrBuildElement("O"),.3);

  //tracker
 
  G4Material *Sil = nist->FindOrBuildMaterial("G4_Si");
  

  

  //calorimeter
  G4Material *CsIdop = new G4Material("CsIdop",4.51*g/cm3,3);
  CsIdop->AddElement(nist->FindOrBuildElement("Cs"),0.4998);
  CsIdop->AddElement(nist->FindOrBuildElement("I"),0.4998);
  CsIdop->AddElement(nist->FindOrBuildElement("Tl"),0.04*perCent);

  //Magnet
  //superconductor
  G4Element *Cu = nist->FindOrBuildElement("Cu");
  G4Element *Nb = nist->FindOrBuildElement("Nb");
  G4Element *Ti = nist->FindOrBuildElement("Ti");
  G4Material *NbTi = new G4Material("NbTi",8.96*g/cm3,2);
  NbTi->AddElement(Nb,0.5);
  NbTi->AddElement(Ti,0.5);
  G4Material *Cop = new G4Material("Cop", 8.96*g/cm3,2);
  Cop->AddElement(Cu,0.89);
  Cop->AddMaterial(NbTi,0.11);
  



  
  G4Element *Al = nist->FindOrBuildElement("Al");
  G4Material *Alu = nist->FindOrBuildMaterial("G4_STAINLESS-STEEL");
  G4Element *Zn = nist->FindOrBuildElement("Zn");
  
  //Insulant fiber glass (type E) (TEMPORARY)
  
  G4Material *SiO2 = new G4Material ("SiO2", 2.65*g/cm3,2);
  SiO2->AddElement(nist->FindOrBuildElement("Si"),1);  
  SiO2->AddElement(nist->FindOrBuildElement("O"),2);  

  G4Material *Al2O3 = new G4Material ("Al2O3",3.95*g/cm3,2);
  Al2O3->AddElement(nist->FindOrBuildElement("Al"),2);  
  Al2O3->AddElement(nist->FindOrBuildElement("O"),3);

  G4Material *TiO2 = new G4Material ("TiO2",4.23*g/cm3,2);
  TiO2->AddElement(nist->FindOrBuildElement("Ti"),1);  
  TiO2->AddElement(nist->FindOrBuildElement("O"),2); 

  G4Material *B2O3 = new G4Material ("B2O3",2.55*g/cm3,2);
  B2O3->AddElement(nist->FindOrBuildElement("B"),2);  
  B2O3->AddElement(nist->FindOrBuildElement("O"),3); 
  
  G4Material *CaO = new G4Material ("CaO",3.34*g/cm3,2);
  CaO->AddElement(nist->FindOrBuildElement("Ca"),1);  
  CaO->AddElement(nist->FindOrBuildElement("O"),1);

  G4Material *MgO = new G4Material ("MgO",3.58*g/cm3,2);
  MgO->AddElement(nist->FindOrBuildElement("Mg"),1);  
  MgO->AddElement(nist->FindOrBuildElement("O"),1);

  G4Material *Na2O = new G4Material ("Na2O",2.27*g/cm3,2);
  Na2O->AddElement(nist->FindOrBuildElement("Na"),2);  
  Na2O->AddElement(nist->FindOrBuildElement("O"),1); 

  G4Material *K2O = new G4Material ("K2O",2.32*g/cm3,2);
  K2O->AddElement(nist->FindOrBuildElement("K"),2);  
  K2O->AddElement(nist->FindOrBuildElement("O"),1);


  G4Material *resin = new G4Material ("resin",2.6*g/cm3 ,8);
  resin->AddMaterial(SiO2,55*perCent);
  resin->AddMaterial(Al2O3, 14*perCent);
  resin->AddMaterial(TiO2, 0.2*perCent);
  resin->AddMaterial(B2O3, 7*perCent);
  resin->AddMaterial(CaO, 22*perCent);
  resin->AddMaterial(MgO,1*perCent);
  resin->AddMaterial(Na2O, 0.5*perCent);
  resin->AddMaterial(K2O, 0.3*perCent);
  
  //G4Material *resin = nist->FindOrBuildMaterial("G4_Pyrex_Glass");

  //BRASS CYLINDER

  G4Material *brass = nist->FindOrBuildMaterial("G4_BRASS");

  G4Material *mylar = nist->FindOrBuildMaterial("G4_MYLAR");





  /* ---------------------------------------------------------------------------------------------------------------------------------------*/








  /* -------------------------------------------------------SOLID VOLUMES--------------------------------------------------------------------------------*/

  //WORLD

  G4Box *solidWorld = new G4Box ("solidWorld", 10.*m,10.*m,10.*m);

  //BEAM

  G4VSolid *solidBeam = new G4Tubs ("solidBeam",0, 100.*mm,2.*m,0.*deg,360.*deg);
  
   //TRACKER
  G4VSolid *solidTracker = new G4Tubs ("solidTracker",100.*mm, 900.*mm,2*m,0.*deg,360.*deg);


  //CALORIMETER
  G4VSolid *solidCalorimeter = new G4Tubs ("solidCalorimeter",900.*mm, 1420.*mm,2.*m,0.*deg,360.*deg);
  
   //MAGNET

  G4double length = -1746*mm;

  G4VSolid *solidIntCryostat = new G4Tubs ("solidIntCryostat",1420.*mm,1481.5*mm,1920.*mm,0.*deg,360.*deg);
  G4VSolid *solidIntMylar = new G4Tubs ("solidIntMylar",1481.5*mm,1506.5*mm,1920.*mm,0.*deg,360.*deg);
  G4VSolid *solidExtInsulation = new G4Tubs ("solidExtInsulation",1506.5*mm,1509.5*mm,1746.*mm,0.*deg,360.*deg);
  G4double sweep = 1589.75*mm;

  G4VSolid* subtractIntInsulation1 = new G4Tubs("solidIntInsulation1", 1509.5*mm, 1515.1*mm,12.4/2*mm,0.*deg,360.*deg);
  G4VSolid *solidConductor1 = new G4Tubs("solidConductor1",1510*mm,1514.6*mm,11.4/2*mm,0.*deg,360.*deg);
  G4SubtractionSolid *subsolidIntInsulation1 = new G4SubtractionSolid("solidIntInsulation1", subtractIntInsulation1, solidConductor1);
  G4VSolid *solidIntInsulation1 = subsolidIntInsulation1->Clone();
  
  
  

  //MECHANICAL CYLINDER

  G4VSolid *solidCylinder = new G4Tubs("solidCylinder",1543.1*mm,1573.1*mm,1920.*mm,0.*deg,360.*deg);
  G4VSolid *solidExtMylar = new G4Tubs ("solidExtMylar",1573.1*mm,1598.1*mm,1920.*mm,0.*deg,360.*deg);

 
  G4VSolid *solidExtCryostat = new G4Tubs ("solidExtCryostat",1598.1*mm,1659.6*mm,1920.*mm,0.*deg,360.*deg);
  
 

  /*-----------------------------------------------------------LOGICAL VOLUMES--------------------------------------------*/
  G4double alpha = 1;

  //WORLD
  
  G4LogicalVolume *logicWorld = new G4LogicalVolume (solidWorld, worldMat, "logicWorld");
  
  //BEAM

  G4LogicalVolume *logicBeam = new G4LogicalVolume (solidBeam, vacuum, "logicBeam");
  G4VisAttributes* BeamVisAtt = new G4VisAttributes( G4Colour(0,1,1,alpha) );
  BeamVisAtt -> SetForceWireframe( true );
  BeamVisAtt -> SetForceSolid( true );
  logicBeam-> SetVisAttributes( BeamVisAtt );

  



  
  //TRACKER
  
  G4LogicalVolume *logicTracker = new G4LogicalVolume (solidTracker, Sil, "logicTracker");
  G4VisAttributes* TrackerVisAtt = new G4VisAttributes( G4Colour(4,1,2,alpha) );
  TrackerVisAtt -> SetForceWireframe( true );
  TrackerVisAtt -> SetForceSolid( true );
  logicTracker-> SetVisAttributes( TrackerVisAtt );
  
  //CALORIMETER
  G4LogicalVolume *logicCalorimeter = new G4LogicalVolume (solidCalorimeter, CsIdop, "logicCalorimeter");
  G4VisAttributes* CalorimeterVisAtt = new G4VisAttributes( G4Colour(1,0,0,alpha) );
  CalorimeterVisAtt -> SetForceWireframe( true );
  CalorimeterVisAtt -> SetForceSolid( true );
  logicCalorimeter-> SetVisAttributes( CalorimeterVisAtt );

 
  
  //MAGNET
  G4LogicalVolume *logicIntCryostat = new G4LogicalVolume (solidIntCryostat,Alu, "logicIntCryostat");
  G4VisAttributes* IntCryostatVisAtt = new G4VisAttributes( G4Colour(0,1,0,alpha) );
  IntCryostatVisAtt -> SetForceWireframe( true );
  IntCryostatVisAtt -> SetForceSolid( true );
  logicIntCryostat-> SetVisAttributes(IntCryostatVisAtt );

  G4LogicalVolume *logicIntMylar = new G4LogicalVolume (solidIntMylar, mylar, "logicIntMylar");
  G4LogicalVolume *logicExtMylar = new G4LogicalVolume (solidExtMylar, mylar, "logicExtMylar");
  
  G4VisAttributes* IntMylarVisAtt = new G4VisAttributes( G4Colour(0,1,0.3,alpha) );
  IntMylarVisAtt -> SetForceWireframe( true );
  IntMylarVisAtt -> SetForceSolid( true );
  logicIntMylar-> SetVisAttributes(IntMylarVisAtt );

  G4VisAttributes* ExtMylarVisAtt = new G4VisAttributes( G4Colour(0,1,0.3,alpha) );
  ExtMylarVisAtt -> SetForceWireframe( true );
  ExtMylarVisAtt -> SetForceSolid( true );
  logicExtMylar-> SetVisAttributes(ExtMylarVisAtt );

  

  G4LogicalVolume *logicExtInsulation = new G4LogicalVolume (solidExtInsulation, resin, "logicExtInsulation");
  G4VisAttributes* ExtInsulationVisAtt = new G4VisAttributes( G4Colour(1,0,1,alpha) );
  ExtInsulationVisAtt -> SetForceWireframe( true );
  ExtInsulationVisAtt -> SetForceSolid( true );
  logicExtInsulation-> SetVisAttributes( ExtInsulationVisAtt );


 
 					   


  



  G4LogicalVolume *logicConductor1 = new G4LogicalVolume(solidConductor1, Cop, "logicConductor1");
  G4VisAttributes* condTubeVisAtt = new G4VisAttributes( G4Colour(1,0,0,alpha));
  condTubeVisAtt -> SetForceWireframe( true );
  condTubeVisAtt -> SetForceSolid( true );
  logicConductor1-> SetVisAttributes( condTubeVisAtt );

  
  G4LogicalVolume *logicIntInsulation1 = new G4LogicalVolume(solidIntInsulation1,resin, "logicIntInsulation1");
  G4VisAttributes *IntInsulation1VisAtt = new G4VisAttributes(G4Colour(0,1,0,alpha));
  IntInsulation1VisAtt->SetForceWireframe(true);
  IntInsulation1VisAtt->SetForceSolid(true);
  logicIntInsulation1->SetVisAttributes(IntInsulation1VisAtt);
  
  
  G4LogicalVolume *logicCylinder = new G4LogicalVolume(solidCylinder,brass,"logicCylinder");
  G4VisAttributes *CylinderVisAtt = new G4VisAttributes(G4Colour(0,0,1,alpha));
  CylinderVisAtt->SetForceWireframe(true);
  CylinderVisAtt->SetForceSolid(true);
  logicCylinder->SetVisAttributes(CylinderVisAtt);



  G4LogicalVolume *logicExtCryostat = new G4LogicalVolume (solidExtCryostat,Alu, "logicExtCryostat");
  G4VisAttributes* ExtCryostatVisAtt = new G4VisAttributes( G4Colour(0,1,0,alpha) );
  ExtCryostatVisAtt -> SetForceWireframe( true );
  ExtCryostatVisAtt -> SetForceSolid( true );
  logicExtCryostat-> SetVisAttributes(ExtCryostatVisAtt );


  /*---------------------------------------------------------PHYSICAL VOLUMES----------------------------------------------------------*/

  //WORLD

  G4ThreeVector place (0.,0.,0.);
  

  G4VPhysicalVolume *physWorld = new G4PVPlacement (0, place,logicWorld,"physWorld",0,false,0,true);
   G4VPhysicalVolume *physBeam = new G4PVPlacement (0, place,logicBeam,"physBeam",logicTracker,false,0,true);
  
  G4VPhysicalVolume *physTracker = new G4PVPlacement (0, place,logicTracker,"physTracker",logicCalorimeter,false,0,true);
  G4VPhysicalVolume *physCalorimeter = new G4PVPlacement (0,place,logicCalorimeter,"physCalorimeter",logicIntCryostat,false,0,true);
  G4VPhysicalVolume *physIntCryostat = new G4PVPlacement (0, place,logicIntCryostat,"physIntCryostat",logicWorld,false,0,true);
  G4VPhysicalVolume *physIntMylar = new G4PVPlacement (0, place,logicIntMylar,"physIntMylar",logicIntCryostat,false,0,true);
  G4VPhysicalVolume *physExtInsulation = new G4PVPlacement (0, place,logicExtInsulation,"physExtInsulation",logicWorld,false,0,true);
  
  
  for(G4int j=0;j<6;j++)
    {
      for(G4int i = 0; i<281;i++){
	G4ThreeVector placeCond = place + G4ThreeVector(0.,5.6*j,length+12.4*i*mm);
	G4ThreeVector placeIns = place + G4ThreeVector(0.,5.6*j,length+12.4*i*mm);
	
	G4VPhysicalVolume *physConductor1 = new G4PVPlacement (0, placeCond, logicConductor1, "physConductor1", logicWorld,false,0,true);
	G4VPhysicalVolume *physIntInsulation1 = new G4PVPlacement(0, placeIns, logicIntInsulation1, "physIntInsulation1", logicWorld,false,0,true);
      }
    }

  G4VPhysicalVolume *physCylinder = new G4PVPlacement(0,place,logicCylinder, "physCylinder",logicWorld,false,0,true);

  G4VPhysicalVolume *physExtCryostat = new G4PVPlacement (0, place,logicExtCryostat,"physExtCryostat",logicWorld,false,0,true);
  G4VPhysicalVolume *physExtMylar = new G4PVPlacement (0, place,logicIntMylar,"physIntMylar",logicWorld,false,0,true);
    
   fScoringVolume1 = logicIntInsulation1;
   fScoringVolume2 = logicIntCryostat;
   fScoringVolume3 = logicExtCryostat;
   fScoringVolume4 = logicExtInsulation;
   fScoringVolume5 = logicConductor1;

   ofstream ifile;
   ifile.open("magnet.dat");

   /*  G4double rhoCalInt = logicIntCryostat->GetMaterial()->GetDensity();
   G4double ZCalInt = logicIntCryostat->GetMaterial()->GetZ();
   G4double ACalInt = logicIntCryostat->GetMaterial()->GetA();
   G4double volCalInt = logicIntCryostat->GetSolid()->GetCubicVolume();
   G4double mCalInt = volCalInt*rhoCalInt*gram;

   ifile << mCalInt << " " << ACalInt << " " << ZCalInt << G4endl;


   G4double rhoMylarInt = logicIntMylar->GetMaterial()->GetDensity();
   G4double ZMylarInt = logicIntMylar->GetMaterial()->GetZ();
   G4double AMylarInt = logicIntMylar->GetMaterial()->GetA();
   G4double volMylarInt = logicIntMylar->GetSolid()->GetCubicVolume();
   G4double mMylarInt = volMylarInt*rhoMylarInt*g;

   ifile << mMylarInt << " " << AMylarInt << " " << ZMylarInt << G4endl;*/


   G4double rhoInsExt = logicExtInsulation->GetMaterial()->GetDensity();
   G4double volInsExt = logicExtInsulation->GetSolid()->GetCubicVolume();
   G4double mInsExt = volInsExt*rhoInsExt;

   ifile << mInsExt/gram << " " << volInsExt/centimeter3 << endl;


   G4double rhoInsInt = logicIntInsulation1->GetMaterial()->GetDensity();
   G4double volInsInt = logicIntInsulation1->GetSolid()->GetCubicVolume();
   G4double mInsInt = volInsInt*rhoInsInt;

   ifile << mInsInt/gram << " " << volInsInt/centimeter3 << G4endl;


   G4double rhoCond = logicConductor1->GetMaterial()->GetDensity();
   G4double volCond = logicConductor1->GetSolid()->GetCubicVolume();
   G4double mCond = volCond*rhoCond;
   

   ifile << mCond/gram << " " << volCond/centimeter3 << G4endl;

   /* G4double rhoCy = logicCylinder->GetMaterial()->GetDensity();
   G4double ZCy = logicCylinder->GetMaterial()->GetZ();
   G4double ACy = logicCylinder->GetMaterial()->GetA();
   G4double volCy = logicCylinder->GetSolid()->GetCubicVolume();
   G4double mCy = volCy*rhoCy*gram;
   

   ifile << mCy << " " << ACy << " " << ZCy << G4endl;*/

   



   
   
  
  return physWorld;
}

/*void MyDetectorConstruction::ConstructSD(){
 
  MySensitiveDetector *sensDet = new MySensitiveDetector("SensitiveDetector");
  G4SDManager* SDMan = G4SDManager::GetSDMpointer();
  SDMan->AddNewDetector(sensDet);
  logicIntCryostat->SetSensitiveDetector(sensDet);
 logicExtCryostat->SetSensitiveDetector(sensDet);
 
 }*/



G4double MyDetectorConstruction::GetDose() const{
  
  G4double dose = fDeposit/fScoringVolume1->GetMass();


  return dose;
}
