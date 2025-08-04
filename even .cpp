//give an ex of all opps concepts of C++
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 1. Encapsulation: Wrapping data and methods in a class
class Car {
protected:
    int id;
    string name;
    string model;
public:
    Car(int id, string name, string model) : id(id), name(name), model(model) {}
    virtual void display() {
        cout << "Car: " << id << ", " << name << ", " << model << endl;
    }
    virtual ~Car() {}
};

// 2. Inheritance: Sweden inherits from Car
class Sweden : public Car {
    int milage;
public:
    Sweden(int id, string name, string model, int milage)
        : Car(id, name, model), milage(milage) {}
    void display() override {
        cout << "Sweden Car: " << id << ", " << name << ", " << model << ", Milage: " << milage << endl;
    }
};

// 3. Polymorphism: Using base class pointer to call derived class method
// 4. Abstraction: CarApp hides implementation details
class CarApp {
    static CarApp* instance;
    vector<Car*> carList;
    CarApp() {}
public:
    static CarApp* getInstance() {
        if (instance == nullptr) {
            instance = new CarApp();
        }
        return instance;
    }
    void addSweden() {
        int id;
        string name, model;
        int mil;
        cout << "Enter Sweden car id, name, model and milage:" << endl;
        cin >> id >> name >> model >> mil;
        carList.push_back(new Sweden(id, name, model, mil));
    }
    void showCars() {
        for (auto car : carList) {
            car->display();
        }
    }
    ~CarApp() {
        for (auto car : carList) delete car;
    }
};

CarApp* CarApp::instance = nullptr;

int main() {
    CarApp* app = CarApp::getInstance();
    app->addSweden();
    app->showCars();
    return 0;
}
1