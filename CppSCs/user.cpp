#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <cctype> // For character type checking

// Define a data structure to store user information
struct User {
    std::string username;
    std::string password;
};

// Create a map to store user data (username -> User)
std::map<std::string, User> users;

// Function to check if a password meets strength criteria
bool isStrongPassword(const std::string& password) {
    if (password.length() < 8) {
        return false; // Require a minimum length of 8 characters
    }

    bool hasUpperCase = false;
    bool hasLowerCase = false;
    bool hasDigit = false;
    bool hasSpecialChar = false;

    for (char c : password) {
        if (std::isupper(c)) {
            hasUpperCase = true;
        } else if (std::islower(c)) {
            hasLowerCase = true;
        } else if (std::isdigit(c)) {
            hasDigit = true;
        } else if (std::ispunct(c)) {
            hasSpecialChar = true;
        }
    }

    // Require at least one of each type of character
    return hasUpperCase && hasLowerCase && hasDigit && hasSpecialChar;
}

// Function to create a new account with a strong password requirement
void createAccount() {
    User newUser;
    std::string username, password;
    std::cout << "Enter a username: ";
    std::cin >> username;

    // Check if the username already exists
    if (users.find(username) != users.end()) {
        std::cout << "Username already exists. Please choose a different one." << std::endl;
        return;
    }

    do {
        std::cout << "Enter a strong password (at least 8 characters with uppercase, lowercase, digit, and special character): ";
        std::cin >> password;
    } while (!isStrongPassword(password));

    newUser.username = username;
    newUser.password = password;
    users[username] = newUser;
    std::cout << "Account created successfully." << std::endl;

    // Save the user data to a text file
    std::ofstream file("users.txt", std::ios::app);
    file << username << " " << password << std::endl;
    file.close();
}

// Function to load user data from a text file
void loadUserData() {
    std::ifstream file("users.txt");
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
    std::string username, password;
    std::cout << "Enter your username: ";
    std::cin >> username;
    std::cout << "Enter your password: ";
    std::cin >> password;

    if (users.find(username) != users.end() && users[username].password == password) {
        std::cout << "Login successful." << std::endl;
        return true;
    } else {
        std::cout << "Login failed. Please check your username and password." << std::endl;
        return false;
    }
}

// Function to log out (simply returning to the main menu)
void logout() {
    std::cout << "Logged out." << std::endl;
}

int main() {
    // Load user data from the text file at the beginning of the program
    loadUserData();

    while (true) {
        std::cout << "1. Create Account\n2. Login\n3. Exit\nChoose an option: ";
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                if (login()) {
                    // If login is successful, enter the user menu
                    while (true) {
                        std::cout << "1. View Profile\n2. Edit Profile\n3. Logout\nChoose an option: ";
                        std::cin >> choice;

                        switch (choice) {
                            case 1:
                                std::cout << "Viewing profile..." << std::endl;
                                break;
                            case 2:
                                std::cout << "Editing profile..." << std::endl;
                                break;
                            case 3:
                                logout();
                                return 0;
                            default:
                                std::cout << "Invalid choice. Please select a valid option." << std::endl;
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
                std::cout << "Invalid choice. Please select a valid option." << std::endl;
        }
    }

    return 0;
}
