#include <iostream>
#include <vector>

using namespace std;

class Student{
protected:
    string name;
    int rollNum;
    
    vector<int> marks ;
    
    public: 
         Student(string name, int rollNum, vector<int> marks):name(name),rollNum(rollNum),marks(marks){}
         int getRollNum(){
             return rollNum;
         }
             
             
             virtual void display()=0;
             virtual string getType()=0;
             virtual~ Student() {}
         
};
         
 class UgStudent:public Student{
     
     public:
           UgStudent(string name, int rollNum, vector<int> marks):Student(name, rollNum, marks){}
           
           void display() override {
               
               cout <<"name[UG]"<<name<< "rollNum"<<rollNum<<"marks"<<endl;
               for(auto m : marks){
                   cout<<m<<endl;
               }
           }
           
           string getType() override {
               return "UG";
           }
           
     
 };
 
 class PgStudent :public Student{
     public:
         PgStudent(string name, int rollNum, vector<int> marks):Student(name, rollNum, marks){
             
         }
         
         void display() override {
             cout << "name[PG]" << name<<"role number"<<rollNum<<"marks"<<endl;
             for(auto m : marks){
                 cout<<m<<endl;
             }
         }
         
          string getType() override {
             return "PG";
         }
 };
 
 class AppManager{
     
     static AppManager* instance;
     
     vector<Student*> studentList;
     private:
            AppManager(){}
     
     public: 
            static AppManager* getInstance(){
                if(instance == nullptr){
                    instance=new AppManager();
                }
                return instance;
            }
            
            void addDetails(Student* s){
                
                studentList.push_back(s);
                
            }
            void showAll(){
                cout<<"student details:";
                
                for(Student* s: studentList)
                s-> display();
            }
            void searchByRollNumber(int roll) {
    bool found = false;
    for (Student* s : studentList) {
     
        if (s->getRollNum() == roll) {
            cout << "\n Student Found:\n";
            s->display();
            found = true;
            break;
        }
    }
    if (!found) {
        cout << " Student with Roll No. " << roll << " not found.\n";
    }
}

            
            
     
 };
 
 AppManager* AppManager:: instance=nullptr;
 
 
 void showMenu(){
    cout << "\n_____ Student Menu _____\n";
    cout << "1. Add UG Student\n";
    cout << "2. Add PG Student\n";
    cout << "3. Show All Students\n";
    cout << "4. Search by Roll Number\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

 
 vector <int> inputmarks(int count){
     
     cout<<"enter:" <<"marks:"<<endl;
     
     vector<int> marks;
     for(int i =0; i< count; ++i){
     
     int m;
     cin>>m;
     marks.push_back(m);
     }
     return marks;
 }
 int main(){
     AppManager* app = AppManager::getInstance();
     
     int choice;
     
     do{
         showMenu();
         cin>>choice;
         switch(choice){
             case 1:{
                 string name;
                 int roll;
                 cout<<"enter student name"<<endl;
                 cin>> name;
                 cout<<"enter roll number"<<endl;
                 cin>>roll;
                 

                vector<int> marks=inputmarks(3);
                app ->addDetails(new UgStudent(name,roll, marks));
                cout<<"added succsessfully"<<endl;
                break;
                 
             }
             case 2:{
                 string name;
                 int roll;
                 cout<<"enter student name"<< endl;
                 cin>> name;
                 cout<<"enter a rollnumber"<<endl;
                 cin>>roll;
                 
                 vector<int> marks=inputmarks(3);
                 app-> addDetails(new PgStudent(name, roll, marks));
                                 cout<<"added succsessfully"<<endl;

                 break;
                 
             }
             
             case 3:
                 app-> showAll();
                 break;
                 case 4: {
    int roll;
    cout << "Enter Roll Number to search: ";
    cin >> roll;
    cin.ignore();
    app->searchByRollNumber(roll);
    break;
}

           case 5:
           cout<<"exit";
           break;
           default:
             cout<<"invalid options" <<endl;
         }
         
         
     }while(choice !=5);
     return 0;
 }
