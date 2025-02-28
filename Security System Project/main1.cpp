#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    int a;
    string text, old, password1, password2, pass, name, password0, age, user, word;
    bool userFound = false;

    cout << "   Security System " << endl;

    cout << "__________________________________" << endl;
    cout << "|           1. Register          |" << endl;
    cout << "|           2. Login             |" << endl;
    cout << "|           3. Change Password   |" << endl;
    cout << "|           4. End Program       |" << endl;
    cout << "__________________________________" << endl << endl;

    do {
        cout << endl << endl;
        cout << "Enter your choice: ";
        cin >> a;
        switch (a) {
            case 1: {
                cout << "____________________________" << endl << endl;
                cout << "|----------Register---------|" << endl;
                cout << "|___________________________|" << endl << endl;
                cout << " Please enter username: ";
                cin >> name;
                cout << " Please enter the password: ";
                cin >> password0;
                cout << " Please enter your age: ";
                cin >> age;

                ofstream of1("file.txt", ios::app);  // Open file in append mode
                if (of1.is_open()) {
                    of1 << name << "\n";
                    of1 << password0 << "\n";
                    of1 << age << "\n";
                    of1.close();
                    cout << "Registration successful" << endl;
                } else {
                    cout << "Error opening file!" << endl;
                }
                break;
            }
            case 2: {
                cout << "____________________________" << endl << endl;
                cout << "|----------Login------------|" << endl;
                cout << "|___________________________|" << endl << endl;

                ifstream if2("file.txt");
                cout << "Please enter the username: ";
                cin >> user;
                cout << "Please enter the password: ";
                cin >> pass;

                userFound = false;
                if (if2.is_open()) {
                    while (getline(if2, text)) {
                        if (text == user) {
                            getline(if2, text); // Read password
                            if (text == pass) {
                                getline(if2, text); // Read age
                                cout << "Login successful..." << endl;
                                cout << "Details: " << endl;
                                cout << "Username: " << user << endl;
                                cout << "Password: " << pass << endl;
                                cout << "Age: " << text << endl;
                                userFound = true;
                                break;
                            }
                        }
                    }
                    if (!userFound) {
                        cout << "Incorrect Credentials" << endl;
                    }
                    if2.close();
                } else {
                    cout << "Error opening file!" << endl;
                }
                break;
            }
            case 3: {
                cout << "---------Change Password----------" << endl;
                ifstream if0("file.txt");
                ofstream of1("temp.txt");  // Temporary file to store updated credentials
                cout << "Enter your username: ";
                cin >> user;
                cout << "Enter the old password: ";
                cin >> old;

                userFound = false;
                if (if0.is_open() && of1.is_open()) {
                    while (getline(if0, text)) {
                        if (text == user) {
                            of1 << text << "\n"; // Write username to temp file
                            getline(if0, text); // Read the password
                            if (text == old) {
                                cout << "Enter your new password: ";
                                cin >> password1;
                                cout << "Enter your new password again: ";
                                cin >> password2;

                                if (password1 == password2) {
                                    of1 << password1 << "\n"; // Write new password
                                    getline(if0, text); // Read age
                                    of1 << text << "\n"; // Write age
                                    cout << "Password changed successfully" << endl;
                                } else {
                                    of1 << old << "\n"; // Keep old password
                                    getline(if0, text); // Read age
                                    of1 << text << "\n"; // Write age
                                    cout << "Passwords do not match" << endl;
                                }
                                userFound = true;
                            } else {
                                of1 << text << "\n"; // Write old password back if incorrect
                                getline(if0, text); // Read age
                                of1 << text << "\n"; // Write age
                            }
                        } else {
                            of1 << text << "\n"; // Copy other user data to temp file
                        }
                    }
                    if0.close();
                    of1.close();

                    remove("file.txt"); // Remove old file
                    rename("temp.txt", "file.txt"); // Rename temp file to original file

                    if (!userFound) {
                        cout << "Username or password is incorrect" << endl;
                    }
                } else {
                    cout << "Error opening file!" << endl;
                }
                break;
            }
            case 4: {
                cout << "_______Thank you!_____________" << endl;
                break;
            }
            default: {
                cout << "Invalid choice! Please try again." << endl;
                break;
            }
        }
    } while (a != 4);

    return 0;
}
