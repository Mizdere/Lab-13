
// Last Modified Date: 5/15/2024

#include <iostream>
using namespace std;

class SavingsAccount {
private:
    int dollars;
    int cents;

    void normalize() {
        if (cents >= 100) {
            dollars += cents / 100;
            cents = cents % 100;
        }
    }

public:
    // Default constructor
    SavingsAccount() : dollars(0), cents(0) {}

    // Parameterized constructor
    SavingsAccount(int initialDollars, int initialCents) : dollars(initialDollars), cents(initialCents) {
        normalize();
    }

    void makeDeposit(int depositDollars, int depositCents) {
        dollars += depositDollars;
        cents += depositCents;
        normalize();
    }

    void makeWithdrawal(int withdrawalDollars, int withdrawalCents) {
        dollars -= withdrawalDollars;
        cents -= withdrawalCents;
        while (cents < 0) {
            dollars--;
            cents += 100;
        }
    }

    void showBalance() const {
        cout << "Dollars = " << dollars << " Cents = " << cents << endl;
    }
};

int main() {
    int initialDollars, initialCents;
    cout << "Please input the initial dollars for bank1: ";
    cin >> initialDollars;
    cout << "Please input the initial cents for bank1: ";
    cin >> initialCents;

    SavingsAccount bank1(initialDollars, initialCents);
    SavingsAccount bank2;  // Default constructor

    // Function to handle deposits and withdrawals for a bank account
    auto handleAccountTransactions = [](SavingsAccount& account) {
        char choice;
        int dollars, cents;

        // Deposits
        do {
            cout << "Would you like to make a deposit? Y or y for yes, n for no: ";
            cin >> choice;
            if (choice == 'Y' || choice == 'y') {
                cout << "Please input the dollars to be deposited: ";
                cin >> dollars;
                cout << "Please input the cents to be deposited: ";
                cin >> cents;
                account.makeDeposit(dollars, cents);
            }
        } while (choice != 'n' && choice != 'N');

        // Withdrawals
        do {
            cout << "Would you like to make a withdrawal? Y or y for yes, n for no: ";
            cin >> choice;
            if (choice == 'Y' || choice == 'y') {
                cout << "Please input the dollars to be withdrawn: ";
                cin >> dollars;
                cout << "Please input the cents to be withdrawn: ";
                cin >> cents;
                account.makeWithdrawal(dollars, cents);
            }
        } while (choice != 'n' && choice != 'N');

        account.showBalance();
    };

    // Handling transactions for bank1
    cout << "Transactions for bank1:" << endl;
    handleAccountTransactions(bank1);

    // Handling transactions for bank2
    cout << "Transactions for bank2 (default values):" << endl;
    handleAccountTransactions(bank2);

    return 0;
}
