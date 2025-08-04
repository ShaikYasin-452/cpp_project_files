#include <iostream>
#include <map>
#include <list>
#include <memory>
#include <iomanip>
using namespace std;

class IVehicleFuelApp {
public:
    virtual void selectMode() = 0;
    virtual void calculateFuel() = 0;
    virtual void viewHistory() = 0;
    virtual void showMenu() = 0;

    virtual ~IVehicleFuelApp() {}
};

class FuelCalculator : public IVehicleFuelApp {
private:
    string currentMode = "City";

    map<string, double> fuelEfficiency = {
        {"Eco", 20.0},
        {"Sport", 10.0},
        {"City", 15.0}
    };

    struct Record {
        string mode;
        double distance;
        double fuelUsed;
    };

    list<Record> history;

    FuelCalculator() {} 

    static shared_ptr<FuelCalculator> instance;

public:
    FuelCalculator(const FuelCalculator&) = delete;
    FuelCalculator& operator=(const FuelCalculator&) = delete;

    static shared_ptr<FuelCalculator> getInstance() {
        if (!instance)
            instance = shared_ptr<FuelCalculator>(new FuelCalculator());
        return instance;
    }

    void selectMode() override {
        cout << "Enter mode (Eco/Sport/City): ";
        string mode;
        cin >> mode;

        if (fuelEfficiency.find(mode) == fuelEfficiency.end()) {
            throw runtime_error("Invalid mode selected.");
        }

        currentMode = mode;
        cout << "Mode changed to: " << currentMode << endl;
    }

    void calculateFuel() override {
        cout << "Enter distance (km): ";
        double distance;
        cin >> distance;

        if (cin.fail() || distance <= 0) {
            cin.clear();
            cin.ignore(1000, '\n');
            throw invalid_argument("Invalid distance entered.");
        }

        double efficiency = fuelEfficiency[currentMode];
        double fuelUsed = distance / efficiency;

        cout << fixed << setprecision(2);
        cout << "Fuel used in " << currentMode << " mode: " << fuelUsed << " Liters" << endl;

        history.push_back({currentMode, distance, fuelUsed});
    }

    void viewHistory() override {
        if (history.empty()) {
            cout << "No history available.\n";
            return;
        }

        cout << "\n--- Fuel Consumption History ---\n";
        for (auto& record : history) {
            cout << "Mode: " << record.mode
                 << ", Distance: " << record.distance
                 << ", Fuel: " << fixed << setprecision(2) << record.fuelUsed << " L\n";
        }
    }

    void showMenu() override {
        cout << "\n--- Vehicle Fuel Calculator --- Current Mode: " << currentMode << "\n";
        cout << "1. Select Mode\n";
        cout << "2. Calculate Fuel\n";
        cout << "3. View History\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
    }
};

shared_ptr<FuelCalculator> FuelCalculator::instance = nullptr;

int main() {
    shared_ptr<IVehicleFuelApp> app = FuelCalculator::getInstance();  
    int choice;

    do {
        app->showMenu();
        cin >> choice;

        try {
            switch (choice) {
                case 1: app->selectMode(); break;
                case 2: app->calculateFuel(); break;
                case 3: app->viewHistory(); break;
                case 4: cout << "Exiting program.\n"; break;
                default: cout << "Invalid option.\n";
            }
        } catch (const exception& ex) {
            cout << "Error: " << ex.what() << endl;
        }

    } while (choice != 4);

    return 0;
}
