#include <iostream>
using namespace std;
class BankAccount {
private:
    double balance;
public:
    BankAccount() {
        balance = 0.0;
    }
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
        }
    }
    double getBalance() {
        return balance;
    }
};
int main() {
    BankAccount account;
    account.deposit(100.0);
    cout << "Balance after deposit: $" << account.getBalance() << endl;
    account.withdraw(30.0);
    cout << "Balance after withdrawal: $" << account.getBalance() << endl;
    account.withdraw(80.0);
    cout << "Balance after attempted over-withdrawal: $" << account.getBalance() << endl;
    return 0;
}