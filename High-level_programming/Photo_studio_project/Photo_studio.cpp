#include "menu/CMenu.h"
#include "menu/CMenuItem.h"
#include "Models/User.h"
#include "Models/Employee.h"
#include "Models/Client.h"
#include "Models/Service.h"
#include <iostream>
#include <cmath>
using namespace std;


#pragma region функции-заглушки
int f1() {
    int value = 25;
    cout << "The root of 25 is " << sqrt(value) << endl;
    return 1;
}

int f2() {
    cout << "\n";
    cout << "   *   \n";
    cout << "  ***  \n";
    cout << " ***** \n";
    cout << "*******\n";
    cout << "*     *\n";
    cout << "*     *\n";
    cout << "*     *\n";
    cout << "*******\n\n";
    return 2;
} 

int displayEmployeeInfo() {
    Employee emp("John", "Doe", 30, "john_doe", "password123", "Master");
    emp.displayInfo();
    cout << endl;
    return 3;
}

int displayClientInfo() {
    Service service("Haircut", 50.0, "Standard haircut for clients");
    Client client("Alice", "Smith", 25, "alice_smith", "password456", service);
    client.displayInfo();
    cout << endl;
    return 4;
}

#pragma endregion

const int ITEMS_NUMBER = 4;


int main() {
    CMenuItem items[ITEMS_NUMBER] {
        CMenuItem{"Root of 25", f1}, 
        CMenuItem{"Print house", f2},
        CMenuItem{"Display Employee Info", displayEmployeeInfo},
        CMenuItem{"Display Client Info", displayClientInfo}};
    CMenu menu("My console menu", items, ITEMS_NUMBER);
    while (menu.runCommand()) {};

    return 0;
}