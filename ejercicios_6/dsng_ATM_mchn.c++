#include <iostream>
#include <vector>
using namespace std;
class ATM {
private:
    vector<long long> notes;
    vector<int> values = {20, 50, 100, 200, 500};
public:
    ATM(){
        notes = vector<long long>(5, 0);
    }
    void deposit(vector<int> banknotesCount) {
        for (int i = 0; i < 5; i++) {
            notes[i] += banknotesCount[i];
        }
    }
    vector<int> withdraw(int amount) {
        vector<int> result(5, 0);
        vector<long long> temp = notes;
        for (int i = 4; i >= 0; i--) {
            int count = min(notes[i], (long long)(amount / values[i]));
            result[i] = count;
            amount -= count * values[i];
        }
        if (amount != 0) {
            return {-1};
        }
        for (int i = 0; i < 5; i++) {
            notes[i] -= result[i];
        }
        return result;
    }
};
int main() {
    ATM atm;
    atm.deposit({0, 0, 1, 2, 1});
    vector<int> result = atm.withdraw(600);
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}