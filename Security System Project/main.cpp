#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    int a;
    string text, old, password1, password2, pass, name, password0, age, user, word;
    string creds[2], cp[2];

    cout << "   Security System " << endl;

    cout <<  "__________________________________" << endl;
    cout << "|           1. Register            |" << endl;
    cout << "|           2. Login               |" << endl;
    cout << "|           3. Change Password     |" << endl;
    cout << "|           4. End Program         |" << endl;
    cout <<  "__________________________________" << endl<<endl;

    do{
        cout << endl << endl;
        cout << "Enter your choice: ";
        cin >> a;
        switch(a)
        {
            case 1: {
                cout << "____________________________" << endl<<endl;
                cout << "|----------Register---------|" <<endl;
                cout << "|___________________________|" <<endl<<endl;
                cout << " Please enter username: " ;
                cin >> name;
                cout << " Please enter the password: ";
                cin >> password0;
                cout << " Please enter your age: " ;
                cin >> age;

                ofstream of1;
                of1.open("file.txt");
                if(of1.is_open()){
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
                int i = 0;
                cout << "____________________________" << endl<<endl;
                cout << "|----------Login------------|" << endl;
                cout << "|___________________________|" <<endl<<endl;

                ifstream if2("file.txt");
                cout << "Please enter the username: ";
                cin >> user;
                cout << "Please enter the password: ";
                cin >> pass;

                if(if2.is_open()){
                    while(getline(if2, text) && i < 2){
                        creds[i] = text;
                        i++;
                    }
                    if(user == creds[0] && pass == creds[1]){
                        cout << "Login successful..." << endl;
                        cout << "Details: " << endl;
                        cout << "Username: " << creds[0] << endl;
                        cout << "Password: " << creds[1] << endl;
                        getline(if2, text);
                        cout << "Age: " << text << endl;
                    } else {
                        cout << "Incorrect Credentials" << endl;
                    }
                    if2.close();
                } else {
                    cout << "Error opening file!" << endl;
                }
                break;
            }
            case 3: {
                int i = 0;
                cout << "---------Change Password----------" << endl;
                ifstream if0("file.txt");
                cout << "Enter the old password: " ;
                cin >> old;

                if(if0.is_open()){
                    while(getline(if0, text) && i < 2){
                        cp[i] = text;
                        i++;
                    }
                    if0.close();

                    if(old == cp[1]){
                        cout << "Enter your new password: ";
                        cin >> password1;
                        cout << "Enter your new password again: ";
                        cin >> password2;

                        if(password1 == password2){
                            ofstream of1("file.txt");
                            if(of1.is_open()){
                                of1 << cp[0] << "\n";
                                of1 << password1 << "\n";
                                of1 << cp[2] << "\n";
                                of1.close();
                                cout << "Password changed successfully" << endl;
                            } else {
                                cout << "Error opening file!" << endl;
                            }
                        } else {
                            cout << "Passwords do not match" << endl;
                        }
                    } else {
                        cout << "Old password is incorrect" << endl;
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
    } while(a != 4);

    return 0;
}
