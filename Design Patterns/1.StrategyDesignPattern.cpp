#include <bits/stdc++.h>
using namespace std;

//Strategy Interface for walk
class WalkableRobot{
    public:
        virtual void walk()=0; // pure virtual function
        virtual ~WalkableRobot(){} // virtual destructor
};

//concrete startegies for walk
class NormalWalk: public WalkableRobot{
    public:
        void walk() override{
            cout<<"Normal walking"<<endl;
        }
};
class NoWalk: public WalkableRobot{
    public:
        void walk() override{
            cout<<"No walking"<<endl;
        }
};

//--strategy interface for talk--
class TalkableRobot{
    public:
        virtual void talk()=0; // pure virtual function
        virtual ~TalkableRobot(){} // virtual destructor
};
//concrete strategies for talk
class NormalTalk: public TalkableRobot{
    public:
        void talk() override{
            cout<<"Normal talking"<<endl;
        }
};
class NoTalk: public TalkableRobot{
    public:
        void talk() override{
            cout<<"No talking"<<endl;
        }
};

//--strategy interface for fly--
class FlyableRobot{
    public:
        virtual void fly()=0; // pure virtual function
        virtual ~FlyableRobot(){} // virtual destructor
};
//concrete strategies for fly
class NormalFly: public FlyableRobot{
    public:
        void fly() override{
            cout<<"Normal flying"<<endl;
        }
};
class NoFly: public FlyableRobot{
    public:
        void fly() override{
            cout<<"No flying"<<endl;
        }
};

//Robot class
class Robot{
    private:
        WalkableRobot* walkableRobot;
        TalkableRobot* talkableRobot;
        FlyableRobot* flyableRobot;
    public:
        Robot(WalkableRobot* walk, TalkableRobot* talk, FlyableRobot* fly){
            this->walkableRobot=walk;
            this->talkableRobot=talk;
            this->flyableRobot=fly;
        }
        void walk(){
            walkableRobot->walk();
        }
        void talk(){
            talkableRobot->talk();
        }
        void fly(){
            flyableRobot->fly();
        }
        virtual void projection()=0; //abstract method fro sub class
};

//--concrete robot types--
class CompanionRobot: public Robot{
    public:
        CompanionRobot(WalkableRobot* walk, TalkableRobot* talk, FlyableRobot* fly):Robot(walk,talk,fly){}
        void projection() override{
            cout<<"Companion robot projection"<<endl;
        }
};
class WorkerRobot: public Robot{
    public:
        WorkerRobot(WalkableRobot* walk, TalkableRobot* talk, FlyableRobot* fly):Robot(walk,talk,fly){}
        void projection() override{
            cout<<"Worker robot projection"<<endl;
        }
};

int main(){
    Robot* companionRobot = new CompanionRobot(new NormalWalk(), new NormalTalk(), new NoFly());
    companionRobot->walk();
    companionRobot->talk();
    companionRobot->fly();
    companionRobot->projection();
    cout<<"------------------------"<<endl;
    Robot* workerRobot = new WorkerRobot(new NoWalk(), new NoTalk(), new NormalFly());
    workerRobot->walk();
    workerRobot->talk();
    workerRobot->fly();
    workerRobot->projection();
    cout<<"------------------------"<<endl;
}