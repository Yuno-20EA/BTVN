#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int MAX = 100;

class Bank_Account {
private:
    string AccountNumber;
    string BankName;
    string AccountType;
    double Balance;
public:
    void input() {
        cout << "Enter Account Number: "; cin >> AccountNumber;
        cin.ignore();
        cout << "Enter Bank Name: "; getline(cin, BankName);
        cout << "Enter Account Type: "; getline(cin, AccountType);

        do {
            cout << "Enter Account Balance: ";
            cin >> Balance;
            if (Balance < 0) cout << "Error. Invalid Data. PLS try again!\n";
        } while (Balance < 0);
    }

    void display() const {
        cout << " | " << left << setw(14) << AccountNumber
             << " | " << setw(20) << BankName
             << " | " << setw(14) << AccountType
             << " | " << setw(14) << fixed << setprecision(0) << Balance << " |" << endl;
    }

    string getAccountNumber() const { return AccountNumber; }
    double getBalance() const { return Balance; }
};

class BankManager {
private:
    Bank_Account danh_sach[MAX];
    int count;

public:
    BankManager() { count = 0; }

    void printHeader() {
        cout << "+" << string(70, '-') << "+" << endl;
        cout << " | " << left << setw(14) << "Account Num" << " | " << setw(20) << "Bank Name"
             << " | " << setw(14) << "Account Type" << " | " << setw(14) << "Balance (VND)" << " |" << endl;
        cout << "+" << string(70, '-') << "+" << endl;
    }

    void printFooter() { cout << "+" << string(70, '-') << "+" << endl; }

    void addBank_Account() {
        if (count >= MAX) {
            cout << "List is full!\n";
            return;
        }
        danh_sach[count].input();
        count++;
        cout << "Your account has been successfully created!\n";
    }

    void displayAll() {
        if (count == 0) {
            cout << "Empty List. Pls fill in this list!\n";
            return;
        }
        printHeader();
        for (int i = 0; i < count; i++) {
            danh_sach[i].display();
        }
        printFooter();
    }

    void searchAccount() {
        if (count == 0) return;
        string h;
        cout << "Enter an account number to search: "; cin >> h;
        bool found = false;
        for (int i = 0; i < count; i++) {
            if (danh_sach[i].getAccountNumber() == h) {
                printHeader();
                danh_sach[i].display();
                printFooter();
                found = true;
                break;
            }
        }
        if (!found) cout << "No bank account with number " << h << " found.\n";
    }

    // CHỨC NĂNG CẬP NHẬT TÀI KHOẢN
    void updateAccount() {
        if (count == 0) {
            cout << "List is empty!\n";
            return;
        }
        string targetID;
        cout << "Enter Account Number to update: "; cin >> targetID;

        bool found = false;
        for (int i = 0; i < count; i++) {
            if (danh_sach[i].getAccountNumber() == targetID) {
                cout << "\nAccount found! Please enter new information:\n";
                danh_sach[i].input(); // Nhập lại thông tin mới đè lên vị trí cũ
                cout << "Update successful!\n";
                found = true;
                break;
            }
        }
        if (!found) cout << "Account number not found!\n";
    }

    void findMaxMin() {
        if (count == 0) return;
        int maxIdx = 0, minIdx = 0;
        for (int i = 1; i < count; i++) {
            if (danh_sach[i].getBalance() > danh_sach[maxIdx].getBalance()) maxIdx = i;
            if (danh_sach[i].getBalance() < danh_sach[minIdx].getBalance()) minIdx = i;
        }
        cout << "\n1. The highest balance account:\n";
        printHeader(); danh_sach[maxIdx].display(); printFooter();
        cout << "\n2. The minimum balance account:\n";
        printHeader(); danh_sach[minIdx].display(); printFooter();
    }
};

int main() {
    BankManager manager;
    int choice;
    do {
        cout << "\n========= Banking Management System (ARRAY) =========" << endl;
        cout << "1. Create A New Account." << endl;
        cout << "2. List Accounts." << endl;
        cout << "3. Account Number Search." << endl;
        cout << "4. Minimum and Maximum Balance." << endl;
        cout << "5. Update Account Information." << endl; // Thêm menu 5
        cout << "0. Exit." << endl;
        cout << "Please enter your selection: ";
        cin >> choice;

        switch (choice) {
            case 1: manager.addBank_Account(); break;
            case 2: manager.displayAll(); break;
            case 3: manager.searchAccount(); break;
            case 4: manager.findMaxMin(); break;
            case 5: manager.updateAccount(); break; // Gọi hàm cập nhật
            case 0: cout << "EXIT...!\n"; break;
            default: cout << "Not a valid choice!\n";
        }
    } while (choice != 0);
    return 0;
}