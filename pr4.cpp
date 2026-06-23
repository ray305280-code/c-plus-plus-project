#include <iostream>
using namespace std;

class BankAccount
{
    int accountNumber;
    string accountHolderName;
private:
    double balance;

public:
    BankAccount(int no, string name, double bal)
    {
        accountNumber = no;
        accountHolderName = name;
        balance = bal;
    }

    void deposit(double amt) { balance += amt; }

    void withdraw(double amt)
    {
        if (amt <= balance)
            balance -= amt;
        else
            cout << "Insufficient Balance!\n";
    }

    double getBalance() { return balance; }

     void calculateInterest()
    {
        cout << "No Interest Calculation\n";
    }

     void displayAccountInfo()
    {
        cout << "\nA/C No: " << accountNumber
             << "\nName: " << accountHolderName
             << "\nBalance: " << balance << endl;
    }
};

class SavingsAccount : public BankAccount
{
    double interestRate;

public:
    SavingsAccount(int no, string name, double bal, double rate)
        : BankAccount(no, name, bal)
    {
        interestRate = rate;
    }

    void calculateInterest()
    {
        cout << "Savings Interest: "
             << getBalance() * interestRate / 100 << endl;
    }
};

class FixedDepositAccount : public BankAccount
{
    int term;

public:
    FixedDepositAccount(int no, string name, double bal, int t)
        : BankAccount(no, name, bal)
    {
        term = t;
    }

    void calculateInterest()
    {
        cout << "FD Interest: "
             << getBalance() * 0.08 * term / 12 << endl;
    }
};

int main()
{
    BankAccount *acc;

    SavingsAccount s(101, "Rahul", 10000, 5);
    FixedDepositAccount f(102, "Priya", 20000, 12);

    int ch;
    cout << "1. Savings Account\n2. Fixed Deposit Account\nChoose: ";
    cin >> ch;

    if (ch == 1)
        acc = &s;
    else
        acc = &f;

    acc->displayAccountInfo();

    double amt;
    cout << "\nEnter Deposit Amount: ";
    cin >> amt;
    acc->deposit(amt);

    cout << "Enter Withdraw Amount: ";
    cin >> amt;
    acc->withdraw(amt);

    acc->displayAccountInfo();
    acc->calculateInterest();
}

/*output
1. Savings Account
2. Fixed Deposit Account
Choose: 2

A/C No: 102
Name: Priya
Balance: 20000

Enter Deposit Amount: 100000
Enter Withdraw Amount: 5000

A/C No: 102
Name: Priya
Balance: 115000
FD Interest: 9200
*/
