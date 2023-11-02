#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <cctype> // For character type checking
using namespace std;

// Define a data structure to store user information
struct User {
    string username;
    string password;
};

// Create a map to store user data (username -> User)
map<string, User> users;

// Function to check if a password meets strength criteria
bool isStrongPassword(const string& password) {
    if (password.length() < 8) {
        return false; // Require a minimum length of 8 characters
    }

    bool hasUpperCase = false;
    bool hasLowerCase = false;
    bool hasDigit = false;
    bool hasSpecialChar = false;

    for (char c : password) {
        if (isupper(c)) {
            hasUpperCase = true;
        } else if (islower(c)) {
            hasLowerCase = true;
        } else if (isdigit(c)) {
            hasDigit = true;
        } else if (ispunct(c)) {
            hasSpecialChar = true;
        }
    }

    // Require at least one of each type of character
    return hasUpperCase && hasLowerCase && hasDigit && hasSpecialChar;
}

// Function to create a new account with a strong password requirement
void createAccount() {
    User newUser;
    string username, password;
    cout << "Enter a username: ";
    cin >> username;

    // Check if the username already exists
    if (users.find(username) != users.end()) {
        cout << "Username already exists. Please choose a different one." << endl;
        return;
    }

    do {
        cout << " (at least 8 characters with uppercase, lowercase, digit, and special character)";
        cout << "Enter a strong password: ";
        cin >> password;
    } while (!isStrongPassword(password));

    newUser.username = username;
    newUser.password = password;
    users[username] = newUser;
    cout << "Account created successfully." << endl;

    // Save the user data to a text file
    ofstream file("users.txt", ios::app);
    file << username << " " << password << endl;
    file.close();
}

// Function to load user data from a text file
void loadUserData() {
    ifstream file("users.txt");
    if (file.is_open()) {
        while (!file.eof()) {
            User user;
            file >> user.username >> user.password;
            users[user.username] = user;
        }
        file.close();
    }
}

// Function to log in
bool login() {
    string username, password;
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

    if (users.find(username) != users.end() && users[username].password == password) {
        cout << "Login successful." << endl;
        return true;
    } else {
        cout << "Login failed. Please check your username and password." << endl;
        return false;
    }
}

// Function to log out (simply returning to the main menu)
void logout() {
    cout << "Logged out." << endl;
}

int main() {
    // Load user data from the text file at the beginning of the program
    loadUserData();

    while (true) {
        cout << "1. Create Account\n2. Login\n3. Exit\nChoose an option: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                if (login()) {
                    // If login is successful, enter the user menu
                    while (true) {
                        cout << "1. View Todo List\n2. Edit Todo List\n3. Logout\nChoose an option: ";
                        cin >> choice;

                        switch (choice) {
                            case 1:
                                cout << "Viewing Todo List..." << endl;
                                break;
                            case 2:
                                cout << "Editing Todo List..." << endl;
                                break;
                            case 3:
                                logout();
                                return 0;
                            default:
                                cout << "Invalid choice. Please select a valid option." << endl;
                        }

                        if (choice == 3) {
                            break;
                        }
                    }
                }
                break;
            case 3:
                return 0; // Exit the program
            default:
                cout << "Invalid choice. Please select a valid option." << endl;
        }
    }

    return 0;
}
