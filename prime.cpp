// This program checks for prime numbers
#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

vector<int> generatePrimes(int limit) {
    vector<int> primes;
    for (int i = 2; i <= limit; i++) {
        if (isPrime(i)) {
            primes.push_back(i);
        }
    }
    return primes;
}
//hi all
int main() {
    int limit;
    cout << "Enter the upper limit to generate primes: ";
    cin >> limit;

    vector<int> primes = generatePrimes(limit);

    cout << "Prime numbers up to " << limit << " are:\n";
    for (int p : primes) {
        cout << p << " ";
    }
    cout << endl;

    return 0;
}
   