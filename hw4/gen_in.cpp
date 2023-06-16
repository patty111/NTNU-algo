#include <iostream>
#include <random>

using namespace std;

int main() {
    int n = 100;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 10000000);

    for (int i = 1; i <= n; i++) {
        cout << dis(gen) << " ";
    }
    dis = uniform_int_distribution<>(1, 100000);
    cout << endl;

    for (int i = 1; i <= n; i++) {
        cout << dis(gen) << " ";
    }
    cout << endl;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                cout << "0 ";
            } else {
                cout << dis(gen) << " ";
            }
        }
        cout << endl;
    }

    return 0;
}