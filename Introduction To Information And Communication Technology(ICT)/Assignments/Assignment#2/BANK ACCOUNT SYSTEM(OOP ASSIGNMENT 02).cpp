//YASH-RAJ(24k-0737)
#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountNumber;  
    double balance;        

public:
   
    BankAccount(string accNum) {
        accountNumber = accNum;
        balance = 0;
    }

   
    void deposit(double amount) {
        if (amount > 0) {
            balance = balance + amount;
            cout << "Deposited: " << amount << endl;
        } else {
            cout << "Invalid amount for deposit!" << endl;
        }
    }

  
    void withdraw(double amount) {
        if (amount <= balance) {
            balance = balance - amount;
            cout << "Withdrawn: " << amount << endl;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }

   
    void checkBalance() {
        cout << "Current balance: " << balance << endl;
    }
};

int main() {
   
    BankAccount account("123456");

    //hardcoded to check the working and accuracy of code(24k-0737)
    account.deposit(1000);
    account.checkBalance();  

    account.withdraw(500);  
    account.checkBalance();  

    account.withdraw(600);  
    account.checkBalance();  

    return 0;
}
