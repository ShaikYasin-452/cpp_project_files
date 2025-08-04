#include<iostream>
#include<memory>
using namespace std;

class singleton{

    private:
            static shared_ptr<singleton> instance;

            singleton(){
                cout<<"constructor called"<<endl;
            }

            
                    singleton(const singleton& other)=delete;
                    /// @brief 
                 singleton& operator=(const singleton& other)=delete;


               public:
                       static shared_ptr<singleton> getInstance(){
                        if(instance==nullptr){
                            instance= shared_ptr<singleton>(new singleton());
                        }
                        return instance;
                       }      
                       void show(){
                        cout<<"caling from singleton";
                       }


          
};

 shared_ptr<singleton> singleton :: instance=nullptr;

int main(){
    shared_ptr<singleton> obj1=singleton::getInstance();
    obj1->show();
}