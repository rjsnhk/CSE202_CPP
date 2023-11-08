#include <iostream>

class Account {
public:
    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
    virtual void displayBalance() = 0;
};

class SavingsAccount : public Account {
private:
    double balance;
public:
    SavingsAccount() {
        balance = 0;
    }
    void deposit(double amount) {
        balance += amount;
        std::cout << "Amount deposited: " << amount << std::endl;
    }
    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            std::cout << "Amount withdrawn: " << amount << std::endl;
        } else {
            std::cout << "Insufficient funds. Withdrawal canceled." << std::endl;
        }
    }
    void displayBalance() {
        std::cout << "Savings Account Balance: " << balance << std::endl;
    }
};

class CheckingAccount : public Account {
private:
    double balance;
public:
    CheckingAccount() {
        balance = 0;
    }
    void deposit(double amount) {
        balance += amount;
        std::cout << "Amount deposited: " << amount << std::endl;
    }
    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            std::cout << "Amount withdrawn: " << amount << std::endl;
        } else {
            std::cout << "Insufficient funds. Withdrawal canceled." << std::endl;
        }
    }
    void displayBalance() {
        std::cout << "Checking Account Balance: " << balance << std::endl;
    }
};

int main() {
    Account* account = new SavingsAccount(); // Change to CheckingAccount if desired

    int choice;
    double amount;

    while (true) {
        // std::cout << "Enter choice (1: Deposit, 2: Withdraw, 3: Display Balance, 0: Exit): ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                // std::cout << "Enter amount to deposit: ";
                std::cin >> amount;
                account->deposit(amount);
                break;
            case 2:
                // std::cout << "Enter amount to withdraw: ";
                std::cin >> amount;
                account->withdraw(amount);
                break;
            case 3:
                account->displayBalance();
                break;
            case 0:
                std::cout << "Exiting the program. Goodbye!" << std::endl;
                delete account;
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
}
