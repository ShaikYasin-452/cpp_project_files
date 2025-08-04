#include <iostream>
#include <string>
#include <vector>

using namespace std;
// This program prints all fruits starting with 'A' and the alphabet in reverse order
int main() {
    // Print all 'A' fruits from a list of fruit strings
    vector<string> fruits = {"Apple", "Banana", "Avocado", "Grape", "Apricot"};
    for (const auto& fruit : fruits) {
        if (!fruit.empty() && (fruit[0] == 'A' || fruit[0] == 'a')) {
            cout << fruit << " ";
        }
    }
    cout << endl;

    for (char c = 'Z'; c >= 'A'; --c) {
        cout << c << " ";
    }
    cout << endl;
    return 0;
}
