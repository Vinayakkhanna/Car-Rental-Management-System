#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Car {
private:
    int carId;
    string brand;
    string model;
    double price;
    bool available;
public:
    Car(int id, string b, string m, double p)
        : carId(id), brand(b), model(m), price(p), available(true) {}
    int getId() { return carId; }
    string getBrand() { return brand; }
    string getModel() { return model; }
    double getPrice() { return price; }
    bool isAvailable() { return available; }
    void rentCar() { available = false; }
    void returnCar() { available = true; }
    void displayInfo() {
        cout << carId << ". " << brand << " " << model
             << " - Rs." << price << "/day - "
             << (available ? "Available" : "Rented") << endl;
    }
};
class Customer {
private:
    int id;
    string name;
    string phone;
public:
    Customer(int i, string n, string p) : id(i), name(n), phone(p) {}
    int getId() { return id; }
    string getName() { return name; }
    string getPhone() { return phone; }
};
struct RentalHistory {
    string customerName;
    string phone;
    string carName;
    int days;
    double totalCost;
};
class CarRentalSystem {
private:
    vector<Car> cars;
    vector<Customer> customers;
    vector<RentalHistory> history;
    int nextCustomerId = 101;

public:
    void addCar(Car c) { cars.push_back(c); }
    Car* findCar(int carId) {
        for (auto &c : cars) {
            if (c.getId() == carId)
                return &c;
        }
        return nullptr;
    }
    Customer* findCustomer(int custId) {
        for (auto &c : customers) {
            if (c.getId() == custId)
                return &c;
        }
        return nullptr;
    }
    Customer* registerCustomer() {
        string name, phone;
        cin.ignore();
        cout << "Enter your name: ";
        getline(cin, name);
        cout << "Enter your phone number: ";
        getline(cin, phone);

        Customer newCust(nextCustomerId++, name, phone);
        customers.push_back(newCust);
        cout << "✅ Welcome, " << name << "! Your Customer ID is "
             << newCust.getId() << ".\n";
        return &customers.back();
    }
    void showCars() {
        cout << "\n--- Available Cars ---\n";
        for (auto &car : cars)
            car.displayInfo();
        cout << "----------------------\n";
    }
    void rentCar() {
        int carid, days, custId;
        cout << "\nAre you a new customer? (y/n): ";
        char choice;
        cin >> choice;

        Customer* cust = nullptr;

        if (choice == 'y' || choice == 'Y') {
            cust = registerCustomer();
        } else {
            cout << "Enter your Customer ID: ";
            cin >> custId;
            cust = findCustomer(custId);

            if (cust == nullptr) {
                cout << "❌ Customer not found. Please register first.\n";
                cust = registerCustomer();
            } else {
                cout << "Welcome back, " << cust->getName() << "!\n";
            }
        }
        cout << "\nEnter Car ID to rent: ";
        cin >> carid;
        Car* car = findCar(carid);
        if (car == nullptr) {
            cout << "❌ Car not found.\n";
            return;
        }
        if (!car->isAvailable()) {
            cout << "❌ Sorry, this car is already rented.\n";
            return;
        }
        cout << "Enter number of days: ";
        cin >> days;
        car->rentCar();
        double total = days * car->getPrice();
        history.push_back({cust->getName(), cust->getPhone(),
                           car->getBrand() + " " + car->getModel(), days, total});
        cout << "\n✅ " << cust->getName() << " rented "
             << car->getBrand() << " " << car->getModel()
             << " for " << days << " days.\n💰 Total cost: Rs."
             << total << "\n";
    }
    void returnCar() {
        int carid;
        cout << "\nEnter Car ID to return: ";
        cin >> carid;
        Car* car = findCar(carid);
        if (car == nullptr) {
            cout << "❌ Car not found.\n";
            return;
        }
        if (car->isAvailable()) {
            cout << "ℹ️ This car was not rented.\n";
            return;
        }
        car->returnCar();
        cout << "✅ " << car->getBrand() << " " << car->getModel()
             << " returned successfully.\n";
    }
    void showHistory() {
        if (history.empty()) {
            cout << "\n📜 No rentals yet.\n";
            return;
        }
        cout << "\n--- Rental History ---\n";
        for (auto &h : history) {
            cout << "👤 " << h.customerName
                 << " | 📞 " << h.phone
                 << " | 🚗 " << h.carName
                 << " | 🕒 " << h.days << " days"
                 << " | 💰 Rs." << h.totalCost << endl;
        }
        cout << "----------------------\n";
    }
};
int main() {
    CarRentalSystem system;
    system.addCar(Car(1, "Toyota", "Innova Crysta", 3000));
    system.addCar(Car(2, "Hyundai", "Creta", 2500));
    system.addCar(Car(3, "BMW", "X5", 10000));
    system.addCar(Car(4, "Mercedes", "E-Class", 9500));
    system.addCar(Car(5, "Range Rover", "Velar", 11000));
    system.addCar(Car(6, "Land Cruiser", "Prado", 12000));
    int choice;
    while (true) {
        cout << "\n=== Car Rental Management System ===\n";
        cout << "1. Show Cars\n";
        cout << "2. Rent a Car\n";
        cout << "3. Return a Car\n";
        cout << "4. Show Rental History\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            system.showCars();
            break;
        case 2:
            system.rentCar();
            break;
        case 3:
            system.returnCar();
            break;
        case 4:
            system.showHistory();
            break;
        case 5:
            cout << "👋 Thank you for using the system. Goodbye!\n";
            return 0;
        default:
            cout << "❌ Invalid choice. Try again.\n";
        }
    }
}
