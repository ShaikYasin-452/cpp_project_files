#include <iostream>
#include<vector>
using namespace std;
class Car{
    protected:
              int id;
              string name;
              string model;
              
              
              public:
                      Car(int id, string name, string model){
                          this->id=id;
                          this->name=name;
                          this->model=model;
                  
                    }
                            
                    virtual void display()const=0;
                    
                    int getId(){
                        return id;
        }
                            virtual ~Car() {}

};


class Sweden: public Car{
    int mil;
    
          public:
                Sweden(int id, string name, string model, int mil):Car(id,name,model),mil(mil){}
          
          
                 void display() const override{
                     cout<<"Car id:"<<id<<endl;
                     
                     cout<<"car name:" << name<<"model :"<< model<< "milege"<<mil<< "km/h"<<endl;
                     
                     
                 }
    
};

class Suv: public Car{
    bool fourWhwll;
    
          public: Suv(int id, string name, string model, bool fourWhwll):Car(id,name,model),fourWhwll(fourWhwll){}
          
          
                 void display() const override{
                     cout<<"Car id:"<<id<<endl;
                     
                     cout<<"car name:"<< name<< "model:"<< model<<"4wl"<<(fourWhwll? "Yes":"No")<<endl;
                 }
};

class CarApp{
    private:
           static CarApp* instance;
           
          vector<Car*> carList ;
          
         CarApp(){}
         
         public:
                 static CarApp* getInstance(){
                     if(instance==nullptr){
                         instance= new CarApp();
                     }
                     return instance;
                 }
                 
                 void addSwden(){
                     int id, mil;
                     string name, model;
                     cout<<"enter car id"<<endl;
                     cin>>id;
                     cout<<"enter car name"<<endl;
                     cin>>name;
                     cout<<"enter car model "<<endl;
                     cin>>model;
                     cout<<"enter car milage"<<endl;
                     cin>>mil;
                     
                     carList.push_back(new Sweden(id, name, model,mil));
                     
                     
                 }
                 
                 void addSuv(){
                     int id;
                     string name, model;
                     bool fourWhwll;
                     
                     cout<<"enter car id"<<endl;
                     cin>>id;
                     cout<<"enter car name"<<endl;
                     cin>>name;
                     cout<<"enter car model:"<<endl;
                     cin>>model;
                    char choice;
cout << "Is it 4-wheel drive? (y/n): ";
cin >> choice;
fourWhwll = (choice == 'y' || choice == 'Y');

carList.push_back(new Suv(id, name, model, fourWhwll));

                 }
                 
                 void showAllCars(){
                     if(carList.empty()){
                         cout<<"no cars is found"<<endl;
                         return;
                         
                     }
                     
                     for(Car* cars : carList)
                         cars->display();
                     
                 }
                 
                 ~CarApp(){
                     for(Car* cars: carList )
                     delete cars;
                 }
    
};
CarApp* CarApp::instance = nullptr;


      void showMenu(){
          cout<<"_____Welcome to smart car management____"<<endl;
          cout<<"1. add Sweden car details"<<endl;
          cout<<"2. add suv car details"<<endl;
          cout<<"3.show all car details"<<endl;
          cout<<"4.exit"<<endl;
          cout<<"enter your option:"<<endl;
      }
int main(){
    CarApp* app= CarApp::getInstance();
    int choice;
    
    do{
        
        showMenu();
        cin>>choice;
        switch(choice){
            case 1: app->addSwden();
            break;
            case 2: app->addSuv();
            break;
            case 3: app->showAllCars();
            break;
            case 4:
              cout<<"exit"<<endl;
              break;
              
              default:
               cout<<"invalid option"<<endl;
            
        }
        
    }while(choice!=4);
    return 0;
    
    
    
}