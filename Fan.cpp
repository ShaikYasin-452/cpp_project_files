#include<iostream>
using namespace std;
#include<memory>

class HVACControl{

    public:
    virtual void render()=0;
    virtual void updateSettings()=0;

};

class TempContrlScrenn{
public:
    int temp;
     string name;
             public:
                   TempContrlScrenn(int temp, string name){
                    this->temp=temp;
                    this->name=name;
                   }

                   void setTemp(int t){
                 temp=t;
                   }
            void showTemp(){
                cout<<"[TemparatureControllScreen] "<<"fan name:"<<name<<"   temparature:"<<temp<<endl;
            }

           

};

class FanSpeedCon{
   public:  
    int level;
    string mode;

     public:
           FanSpeedCon(int level, string mode){
            this->level=level;
            this->mode=mode;
           }

           void display(){
            cout<<"[FanSpeedControllScreen]"<<"fan level:"<<level<<" fan mode:"<<mode<<endl;
           }

};

class ModeControlScr{
    public:
       int choice;
       string mode;
public:
       void show(){
        cout<<"[ModeControlScrenn]Ac/Heater/Auto:"<<endl;
        cin>>choice;
        cout<<"mode:"<<choice;
       }

};


class ClimateControlManger{

    private:
             static  ClimateControlManger* instance;


            ClimateControlManger(){}


            ClimateControlManger(const ClimateControlManger& other)=delete;
             ClimateControlManger& operator=(const ClimateControlManger& other)=delete;

    public:
           static ClimateControlManger* getInstance(){
            if(instance==nullptr){
                instance= new ClimateControlManger();
            }
            return instance;
           }

        




};
void showMenu(){

    cout<<"___welcome to fan management:__"<<endl;
    cout<<"1. Add fan "<<endl;
    cout<<"2.view Fan history"<<endl;
    cout<<"3.exit "<<endl;
    cout<<"enter your option:";
}

int main(){


  // ClimateControlManger* app=ClimateControlManger::getInstance();
  showMenu();
     TempContrlScrenn t(20,"tata");
     t.showTemp();
      FanSpeedCon f(2,"normal");
      f.display();
     ModeControlScr m;
     m.show();
}
