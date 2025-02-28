#include <iostream>
#include <fstream>
#include <vector>
#include <limits>

using namespace std;

class Shopping {
private:
    int pcode;
    float price;
    float dis;
    string pname;

public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void Remove();
    void list();
    void receipt();
};

// Main Menu
void Shopping::menu() {
    int choice;
    string email;
    string password;

    while (true) {
        cout << "\t\t\t\t_________________________________\n";
        cout << "\t\t\t\t                                 \n";
        cout << "\t\t\t\t      Supermarket Main Menu      \n";
        cout << "\t\t\t\t                                 \n";
        cout << "\t\t\t\t_________________________________\n";

        cout << "\t\t\t\t| 1) Administrator        |\n";
        cout << "\t\t\t\t| 2) Buyer                |\n";
        cout << "\t\t\t\t| 3) EXIT                 |\n";
        cout << "\t\t\t\t Please select: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\t\t\t Please Login\n";
                cout << "\t\t\t Enter Email: ";
                cin >> email;
                cout << "\t\t\t Enter Password: ";
                cin >> password;

                if (email == "admin@email.com" && password == "admin123") {
                    administrator();
                } else {
                    cout << "\t\t\t Invalid email/password\n";
                }
                break;

            case 2:
                buyer();
                break;

            case 3:
                exit(0);

            default:
                cout << "\t\t\t Invalid choice. Try again.\n";
        }
    }
}

// Administrator Menu
void Shopping::administrator() {
    int choice;
    while (true) {
        cout << "\n\n\t\t\t Administrator Menu";
        cout << "\n\t\t\t 1) Add the product";
        cout << "\n\t\t\t 2) Modify the product";
        cout << "\n\t\t\t 3) Delete the product";
        cout << "\n\t\t\t 4) Back to main menu";

        cout << "\n\n\t Please enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                add();
                break;
            case 2:
                edit();
                break;
            case 3:
                Remove();
                break;
            case 4:
                return;
            default:
                cout << "\t\t Invalid Choice!";
        }
    }
}

// Buyer Menu
void Shopping::buyer() {
    int choice;
    while (true) {
        cout << "\t\t\t Buyer Menu";
        cout << "\n\t\t\t 1) Buy product";
        cout << "\n\t\t\t 2) Go back";
        cout << "\n\n\t Please enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                receipt();
                break;
            case 2:
                return;
            default:
                cout << "\t\t Invalid Choice!";
        }
    }
}

// Add New Product
void Shopping::add() {
    fstream data;
    int c;
    float p, d;
    string n;
    bool duplicate = false;

    cout << "\n\n\t\t Add New Product";
    cout << "\n\t Product Code: ";
    while (!(cin >> pcode)) {
        cout << "Invalid input! Enter a valid product code: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "\n\t Product Name: ";
    cin >> pname;
    cout << "\n\t Price: ";
    while (!(cin >> price)) {
        cout << "Invalid input! Enter a valid price: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "\n\t Discount: ";
    while (!(cin >> dis)) {
        cout << "Invalid input! Enter a valid discount: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Check for duplicate product codes
    data.open("database.txt", ios::in);
    if (data) {
        while (data >> c >> n >> p >> d) {
            if (c == pcode) {
                duplicate = true;
                break;
            }
        }
        data.close();
    }

    if (duplicate) {
        cout << "\n\t Product code already exists!";
    } else {
        // Append new product
        data.open("database.txt", ios::app);
        data << pcode << " " << pname << " " << price << " " << dis << endl;
        data.close();
        cout << "\n\t Product added successfully!";
    }
}

// Edit Product
void Shopping::edit() {
    fstream data, data1;
    int pkey;
    bool found = false;

    cout << "\n\n\t\t Modify Product";
    cout << "\n\t Enter Product Code to Edit: ";
    cin >> pkey;

    data.open("database.txt", ios::in);
    if (!data) {
        cout << "\n\t File doesn't exist!";
        return;
    }

    data1.open("database_tmp.txt", ios::out);
    while (data >> pcode >> pname >> price >> dis) {
        if (pcode == pkey) {
            cout << "\n\t New Product Code: ";
            cin >> pcode;
            cout << "\n\t New Product Name: ";
            cin >> pname;
            cout << "\n\t New Price: ";
            cin >> price;
            cout << "\n\t New Discount: ";
            cin >> dis;
            found = true;
        }
        data1 << pcode << " " << pname << " " << price << " " << dis << endl;
    }
    data.close();
    data1.close();

    remove("database.txt");
    rename("database_tmp.txt", "database.txt");

    if (found) {
        cout << "\n\t Product updated successfully!";
    } else {
        cout << "\n\t Product not found!";
    }
}

// Remove Product
void Shopping::Remove() {
    fstream data, data1;
    int pkey;
    bool found = false;

    cout << "\n\n\t\t Delete Product";
    cout << "\n\t Enter Product Code: ";
    cin >> pkey;

    data.open("database.txt", ios::in);
    if (!data) {
        cout << "\n\t File doesn't exist!";
        return;
    }

    data1.open("database_tmp.txt", ios::out);
    while (data >> pcode >> pname >> price >> dis) {
        if (pcode == pkey) {
            cout << "\n\t Product deleted!";
            found = true;
        } else {
            data1 << pcode << " " << pname << " " << price << " " << dis << endl;
        }
    }
    data.close();
    data1.close();

    remove("database.txt");
    rename("database_tmp.txt", "database.txt");

    if (!found) {
        cout << "\n\t Product not found!";
    }
}

// List All Products
void Shopping::list() {
    fstream data;
    data.open("database.txt", ios::in);
    if (!data) {
        cout << "\n\t File doesn't exist!";
        return;
    }

    cout << "\n\n|______________________________________________";
    cout << "\n Product Code\t\tName\t\tPrice\n";
    cout << "______________________________________________\n";

    while (data >> pcode >> pname >> price >> dis) {
        cout << pcode << "\t\t" << pname << "\t\t" << price << endl;
    }
    data.close();
}

// Generate Receipt
void Shopping::receipt() {
    fstream data;
    vector<int> arrc, arrq;  // Store product codes and quantities dynamically
    char choice;
    float amount = 0, discount = 0, total = 0;
    int c;

    cout << "\n\n\t\t\t RECEIPT";
    data.open("database.txt", ios::in);
    if (!data) {
        cout << "\n\t Database is empty!";
        return;
    }

    list();  // Show list of products

    do {
        int productCode, quantity;
        cout << "\n Enter Product Code: ";
        while (!(cin >> productCode)) {
            cout << "Invalid input! Enter a valid product code: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "\n Enter Quantity: ";
        while (!(cin >> quantity)) {
            cout << "Invalid input! Enter a valid quantity: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        arrc.push_back(productCode);
        arrq.push_back(quantity);

        cout << "\n Do you want to buy another product? (y/n): ";
        cin >> choice;

    } while (choice == 'y');

    cout << "\n\n\t\t\t_____________RECEIPT_____________";
    cout << "\n Product Code\tProduct Name\tQuantity\tPrice\tAmount\tAmount after Discount\n";

    for (int i = 0; i < arrc.size(); i++) {
        data.clear();  // Clear EOF flag to re-read the file
        data.seekg(0); // Reset file pointer to beginning
        while (data >> pcode >> pname >> price >> dis) {
            if (pcode == arrc[i]) {
                amount = price * arrq[i];
                discount = amount - (amount * dis / 100);
                total += discount;
                cout << "\n" << pcode << "\t" << pname << "\t" << arrq[i] << "\t" << price << "\t" << amount << "\t" << discount;
            }
        }
    }

    cout << "\n\n Total Amount: " << total;
    data.close();
}

// Main Function
int main() {
    Shopping s;
    s.menu();
    return 0;
}
