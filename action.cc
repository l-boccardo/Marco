#include "action.hh"

MyActionInitialization::MyActionInitialization()
{}

MyActionInitialization::~MyActionInitialization()
{}



void MyActionInitialization::Build() const
{
    MyPrimaryGeneratorAction *generator = new MyPrimaryGeneratorAction();
    SetUserAction(generator);
    
    MyRunAction *runAction = new MyRunAction();
    SetUserAction(runAction);
    
    MyEventAction *eventAction = new MyEventAction(runAction);
    SetUserAction(eventAction);
    
    MySteppingAction *steppingAction = new MySteppingAction(eventAction);
    SetUserAction(steppingAction);
}

void MyActionInitialization::BuildForMaster() const
{

   MyRunAction *runAction = new MyRunAction();
    SetUserAction(runAction);
    
}
