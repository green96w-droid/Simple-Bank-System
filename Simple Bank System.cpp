#include <iostream>
using namespace std;

// تعريف الكلاس (الفئة)
class BankAccount {
private:
    double balance; // الرصيد

public:
    // Constructor: يبدأ الرصيد من 0
    BankAccount() {
        balance = 0;
    }

    // دالة لإيداع المال
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "✅ Deposit successful! New balance: " << balance << " USD" << endl;
        } else {
            cout << "❌ Invalid deposit amount!" << endl;
        }
    }

    // دالة لسحب المال
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "✅ Withdrawal successful! Remaining balance: " << balance << " USD" << endl;
        } else if (amount > balance) {
            cout << "⚠️ Insufficient balance!" << endl;
        } else {
            cout << "❌ Invalid withdrawal amount!" << endl;
        }
    }

    // دالة لعرض الرصيد الحالي
    void display() {
        cout << "💰 Current balance: " << balance << " USD" << endl;
    }
};

// الدالة الرئيسية
int main() {
    BankAccount myAccount;
    int choice;
    double amount;

    cout << "🏦 Welcome to Simple Bank System!" << endl;

    do {
        cout << "\nChoose an option:\n";
        cout << "1. Deposit money\n";
        cout << "2. Withdraw money\n";
        cout << "3. Show balance\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter amount to deposit: ";
            cin >> amount;
            myAccount.deposit(amount);
            break;

        case 2:
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            myAccount.withdraw(amount);
            break;

        case 3:
            myAccount.display();
            break;

        case 4:
            cout << "👋 Thank you for using Simple Bank!" << endl;
            break;

        default:
            cout << "❌ Invalid choice, please try again." << endl;
        }

    } while (choice != 4);

    return 0;
}