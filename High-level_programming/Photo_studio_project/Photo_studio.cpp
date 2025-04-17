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
    Employee emp("Artem", "Kapralov", 30, "Artem_Kapralov", "123456789", "Photographer");
    emp.displayInfo();
    cout << endl;
    return 3;
}

int displayClientInfo() {
    Service service("Photoshoot", 50.0, "Photoshoot in the style of the nineteenth century");
    Client client("Anastasia", "Frolova", 25, "Anastasia_Frolova", "0345244444", service);
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