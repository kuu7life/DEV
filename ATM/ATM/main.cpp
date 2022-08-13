//
//  main.cpp
//  ATM
//
//  Created by Kutman Amangeldiev on 8/13/22.
//

#include <iostream>
using namespace std;

void showMenu(){
    cout << endl << "************* MENU ***************" << endl;
    cout << "1. Check balance" << endl;
    cout << "2. Deposit" << endl;
    cout << "3. Withdraw" << endl;
    cout << "0. Exit" << endl;
    cout << "***********************************" << endl << endl;
}

int main(int argc, const char * argv[]) {
    int option;
    double balance = 500.0;
    
    showMenu();
    do {
        cout << "Please choose an option: ";
        cin >> option;
        
        switch (option) {
            case 1:
                cout << "Balance is " << balance << "$" << endl;
                break;
            case 2:
                cout << "Deposit amount: ";
                int deposit;
                cin >> deposit;
                balance += deposit;
                break;
            case 3:
                cout << "Withdraw amount: ";
                double withdraw;
                cin >> withdraw;
                if (withdraw <= balance){
                    balance -= withdraw;
                } else {
                    cout << "Sorry not enough balance" << endl;
                }
                break;
            default:
                cout << "Invalid option\n";
                break;
        }
    } while (option != 0);
    return 0;
}
