#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void login();
void registration();
void forgot();

int main() {
    int c;
    cout << "\t\t\t______________________________________________\n\n\n";
    cout << "\t\t\t         Welcome to the login page            \n\n\n";
    cout << "\t\t\t_____________________Menu______________________\n\n\n";
    cout << "\t| Press 1 to LOGIN                     |" << endl;
    cout << "\t| Press 2 to REGISTER                  |" << endl;
    cout << "\t| Press 3 if you forgot your PASSWORD  |" << endl;
    cout << "\t| Press 4 to EXIT                      |" << endl;
    cout << "\n\t\t\t Please enter your choice: ";
    cin >> c;
    cout << endl;

    switch (c) {
    case 1:
        login();
        break;
    case 2:
        registration();
        break;
    case 3:
        forgot();
        break;
    case 4:
        cout << "\t\t\t Thank you! \n\n";
        exit(0);  // Exit the program
    default:
        system("cls");
        cout << "\t\t\t Please select from the options given above \n" << endl;
        main();
    }
}

void login() {
    int count = 0;
    string userId, password, id, pass;
    system("cls");
    cout << "\t\t\t Please enter the username and password : " << endl;
    cout << "\t\t\t USERNAME : ";
    cin >> userId;
    cout << "\t\t\t PASSWORD : ";
    cin >> password;

    ifstream input("records.txt");
    while (input >> id >> pass) {
        if (id == userId && pass == password) {
            count = 1;
            break;  // Exit loop once credentials are found
        }
    }
    input.close();

    if (count == 1) {
        system("cls");
        cout << userId << "\n Your Login is Successful \n Thank you for logging in! " << endl;
        main();
    } else {
        system("cls");
        cout << "\n LOGIN ERROR \n Please check your username and password" << endl;
        main();
    }
}

void registration() {
    string ruserId, rpassword;
    system("cls");
    cout << "\t\t\t Enter the username: ";
    cin >> ruserId;
    cout << "\t\t\t Enter the password: ";
    cin >> rpassword;

    ofstream f1("records.txt", ios::app);
    f1 << ruserId << " " << rpassword << endl;
    system("cls");

    cout << "\n\t\t\t Registration is Successful! \n";
    main();
}

void forgot() {
    int option;
    system("cls");
    cout << "\t\t\t You forgot the password? No worries!" << endl;
    cout << "Press 1 to search your id by username" << endl;
    cout << "Press 2 to go back to the main menu" << endl;
    cout << "\t\t\t Enter your choice: ";
    cin >> option;

    switch (option) {
    case 1: {
        int count = 0;
        string suserId, sId, spass;
        cout << "\t\t\t Enter the username which you remember: ";
        cin >> suserId;

        ifstream f2("records.txt");
        while (f2 >> sId >> spass) {
            if (sId == suserId) {
                count = 1;
                break;
            }
        }
        f2.close();

        if (count == 1) {
            cout << "\n\n Your account is found! " << endl;
            cout << "\n\n Your password is: " << spass << endl;
            main();
        } else {
            cout << "\n\t Sorry! Your account is not found! \n";
            main();
        }
        break;
    }

    case 2:
        main();
        break;

    default:
        cout << "\t\t\t Wrong choice! Please try again " << endl;
        forgot();
        break;
    }
}
