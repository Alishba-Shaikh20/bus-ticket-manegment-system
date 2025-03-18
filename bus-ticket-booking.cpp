#include <iostream>
#include <string>
using namespace std;

struct User {
    string username;
    string password;
};

struct Ticket {
    string route;
    int seatNumber;
    bool isBooked;
};


User users[10]; 
int userCount = 0;
Ticket tickets[10]; 


void registerUser() {
    if (userCount < 10) {
        cout << "Enter username: ";
        cin >> users[userCount].username;
        cout << "Enter password: ";
        cin >> users[userCount].password;
        userCount++;
        cout << "User registered successfully!\n";
    } else {
        cout << "User limit reached! Cannot register more users.\n";
    }
}

bool loginUser() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    for (int i = 0; i < userCount; ++i) {
        if (users[i].username == username && users[i].password == password) {
            cout << "Login successful!\n";
            return true;
        }
    }
    cout << "Invalid username or password!\n";
    return false;
}

void displayRoutes() {
    cout << "Available Routes:\n1. Route A\n2. Route B\n3. Route C\n";
}

void displaySeats() {
    cout << "Seat Status:\n";
    for (int i = 0; i < 10; ++i) {
        cout << "Seat " << i + 1 << ": " << (tickets[i].isBooked ? "Booked" : "Available") << "\n";
    }
}

void bookTicket() {
    int seatNumber;
    displaySeats();
    cout << "Enter seat number to book: ";
    cin >> seatNumber;

    if (seatNumber > 0 && seatNumber <= 10 && !tickets[seatNumber - 1].isBooked) {
        tickets[seatNumber - 1].isBooked = true;
        cout << "Ticket booked successfully for seat " << seatNumber << "!\n";
    } else {
        cout << "Invalid or already booked seat!\n";
    }
}

void cancelTicket() {
    int seatNumber;
    cout << "Enter seat number to cancel: ";
    cin >> seatNumber;

    if (seatNumber > 0 && seatNumber <= 10 && tickets[seatNumber - 1].isBooked) {
        tickets[seatNumber - 1].isBooked = false;
        cout << "Ticket for seat " << seatNumber << " canceled successfully!\n";
    } else {
        cout << "Invalid or unbooked seat!\n";
    }
}

int main() {
    int choice;

    cout << "Welcome to the Bus Ticket Processing System!\n";
    while (true) {
        cout << "\nMenu:\n1. Register\n2. Login\n3. Display Routes\n4. Book Ticket\n5. Cancel Ticket\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            registerUser();
            break;
        case 2:
            if (loginUser()) {
            }
            break;
        case 3:
            displayRoutes();
            break;
        case 4:
            bookTicket();
            break;
        case 5:
            cancelTicket();
            break;
        case 6:
            cout << "Thank you for using the system!\n";
            return 0;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
    return 0;
}