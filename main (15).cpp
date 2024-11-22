#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

// Define a struct to represent products
struct Product {
    string code;
    string name;
    double price;
};

// Create a vector to store products
vector<Product> products;

void displayProducts() {
    cout << "Item code | Name     | Price(Rs.)\n";
    for (int i = 0; i < products.size(); ++i) {
        cout << products[i].code << "       | " << products[i].name << "      | " << products[i].price << " \n";
    }
}

void addProduct(const string& code, const string& name, double price) {
    Product product;
    product.code = code;
    product.name = name;
    product.price = price;
    products.push_back(product);
    
}

void manage() {
    while (true) {
        cout << "Manage Products\n";
        cout << "[1] Add Product\n";
        cout << "[2] Display Products\n";
        cout << "[3] Back to Main Menu\n"; // Added "Back" option
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                {
                    string code, name;
                    double price;
                    cout << "Enter product code: ";
                    cin >> code;
                    cout << "Enter product name: ";
                    cin.ignore(); // Ignore the newline character
                    getline(cin, name);
                    cout << "Enter product price: ";
                    cin >> price;
                    addProduct(code, name, price);
                }
                break;
            case 2:
                displayProducts();
                break;
            case 3:
                return; // Return to the main menu
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
}

void bookshopDetails() {
    cout << "\t\t >Book shop Name:  GENIUS BOOKS " << endl;
    cout << "\t\t >Book shop email address:genius@sl.com" << endl;
    cout << "\t\t >Book shop address: No.77, Cross Rd,Kadana  " << endl;
    cout << "\t\t >Book shop Contact number: +94 112 090909 " << endl;
}

void buyProduct() {
    int choice;
    int quantity;
    double totalCost = 0.0;

    cout << " Buy your Products here !\n";
    cout << " \n";
    displayProducts();
    cout << "Enter the item code to buy (or 0 to finish): ";
    
    while (true) {
        cin >> choice;
        
        if (choice == 0) {
            break;
        }

        if (choice < 1 || choice > products.size()) {
            cout << "Invalid item code. Please enter a valid item code: ";
            continue;
        }

        cout << "Enter the quantity to buy: ";
        cin >> quantity;

        if (quantity <= 0) {
            cout << "Invalid quantity. Please enter a positive quantity: ";
            continue;
        }

        double itemPrice = products[choice - 1].price;
        totalCost += itemPrice * quantity;

        cout << "Added " << quantity << " " << products[choice - 1].name << "(s) to your cart.\n";
        cout << "Enter the item code to buy more (or 0 to finish): ";
    }

    cout << "\t\t Total cost of your purchase: Rs. " << totalCost << endl;
    cout <<"\t\tThank you ! have a nice day :) \n";
    cout <<"\t Returning to customer interface...\n";
}

void customer() {
    int choice;
    while (true) { // Loop until a valid choice is made
        cout << "\t \n";
        cout << "\t\t Customer Section\n";
        cout << "\t \n";
        cout << "\t[1] Buy \n";
        cout << "        \n";
        cout << "\t[2] Bookshop details \n";
        cout << "        \n";
        cout << "\t[3] Back \n";
        cout << "        \n";
        cout << "\t Enter your choice : ";
        cin >> choice;

        switch (choice) {
            case 1:
                buyProduct();
                break;
            case 2:
                bookshopDetails();
                break;
            case 3:
                return; // Return to the previous menu
            default:
                cout << "\t Invalid choice! Please try again. \n";
        }
    }
}

void login() {
    int choice;
    string username;
    string password;

    while (true) { // Loop until a valid choice is made
        cout << "\t\t\t\t|||||||||||||||||||||||||||||||||||||||\n";
        cout << "\t\t\t\t                                        \n";
        cout << "\t\t\t\t       WELCOME TO GENIUS BOOKS :       \n";
        cout << "\t\t\t\t        WhimsyWords Book Nook          \n";
        cout << "\t\t\t\t                                        \n";
        cout << "\t\t\t\t||||||||||||||||||||||||||||||||||||||||\n";
        cout << "\t\t\t\t                                        \n";
        cout << "\t >>Please select your role \n";
        cout << "\t\t\t\t                                        \n";
        cout << "\t\t\t\t > [1] Administrator <\n";
        cout << "\t\t\t\t                                        \n";
        cout << "\t\t\t\t > [2] Customer      <\n";
        cout << "\t\t\t\t                                        \n";
        cout << "\t\t\t\t > [3] Exit          <\n";
        cout << "\t\t\t\t                                        \n";

        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\t >>LOGIN <<\n";
                cout << "\t\t Username : ";
                cin >> username;
                cout << "\t\t Password : ";
                cin >> password;

                if (username == "admin" && password == "123") {
                    manage();
                } else {
                    cout << " Invalid username/password!" << endl;
                }

                break;
            case 2:
                customer();
                break;
            case 3:
                exit(0);
            default:
                cout << "\t Invalid choice! Please try again. \n";
        }
    }
}

int main() {
	addProduct("001", "Highlighter", 75.0);
    addProduct("002", "Notebook", 120.0);
    addProduct("003", "Marker", 60.0);
    addProduct("004", "singal rule book 80 pages", 150.0);
    addProduct("005", "Stapler", 80.0);
    login();
    return 0;

}