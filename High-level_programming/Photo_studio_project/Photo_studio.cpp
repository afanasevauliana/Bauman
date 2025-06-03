#include <windows.h>
#include "menu/CMenu.h"
#include "menu/CMenuItem.h"
#include "Models/User.h"
#include "Models/Employee.h"
#include "Models/Client.h"
#include "Models/Service.h"
#include "Models/MyVector.h"
#include <iostream>
#include <cmath>
#include <locale>
#include <codecvt>
using namespace std;

MyVector<Service> services;
MyVector<Employee> employees;
MyVector<Client> clients;

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

int addService() {
    Service newService;
    cin >> newService;
    services.push_back(newService);
    cout << "Услуга добавлена:\n" << newService << endl;
    return 5;
}

int listServices() {
    cout << "Список услуг:\n";
    cout << services;
    return 6;
}

int sortServicesByPrice() {
    services.sort();
    cout << "Услуги отсортированы по цене.\n";
    listServices();
    return 7;
}

int addEmployee() {
    string firstName, lastName, login, password, position;
    int age;
    
    cout << "Введите имя: ";
    cin >> firstName;
    cout << "Введите фамилию: ";
    cin >> lastName;
    cout << "Введите возраст: ";
    cin >> age;
    cout << "Введите логин: ";
    cin >> login;
    cout << "Введите пароль: ";
    cin >> password;
    cin.ignore();
    cout << "Введите должность: ";
    getline(cin, position);
    
    employees.push_back(Employee(firstName, lastName, age, login, password, position));
    cout << "Сотрудник добавлен:\n" << employees[employees.size() - 1] << endl;
    return 8;
}

int listEmployees() {
    cout << "Список сотрудников:\n";
    cout << employees;
    return 9;
}

int addClient() {
    if (services.empty()) {
        cout << "Сначала добавьте услуги!\n";
        return 10;
    }
    
    string firstName, lastName, login, password;
    int age, serviceChoice;
    
    cout << "Введите имя: ";
    cin >> firstName;
    cout << "Введите фамилию: ";
    cin >> lastName;
    cout << "Введите возраст: ";
    cin >> age;
    cout << "Введите логин: ";
    cin >> login;
    cout << "Введите пароль: ";
    cin >> password;
    
    cout << "Выберите услугу:\n";
    for (size_t i = 0; i < services.size(); ++i) {
        cout << i+1 << ". " << services[i].getName() << " (" << services[i].getPrice() << ")\n";
    }
    cin >> serviceChoice;
    
    if (serviceChoice > 0 && serviceChoice <= services.size()) {
        clients.push_back(Client(firstName, lastName, age, login, password, services[serviceChoice-1]));
        cout << "Клиент добавлен:\n" << clients[clients.size() - 1] << endl;
    } else {
        cout << "Неверный выбор услуги!\n";
    }
    return 11;
}

int listClients() {
    cout << "Список клиентов:\n";
    cout << clients;
    return 12;
}

int compareServices() {
    if (services.size() < 2) {
        cout << "Добавьте хотя бы 2 услуги для сравнения!\n";
        return 13;
    }
    
    cout << "Сравнение услуг:\n";
    cout << "1. " << services[0].getName() << "\n2. " << services[1].getName() << "\n";
    
    if (services[0] == services[1]) {
        cout << "Услуги идентичны\n";
    } else if (services[0] < services[1]) {
        cout << services[0].getName() << " дешевле чем " << services[1].getName() << "\n";
    } else {
        cout << services[1].getName() << " дешевле чем " << services[0].getName() << "\n";
    }
    cout << endl;
    return 14;
}

#pragma endregion

const int ITEMS_NUMBER = 14;

int main() {
    #ifdef _WIN32
    system("chcp 65001");
    #endif
    setlocale(LC_ALL, "ru_RU.UTF-8");
    services.push_back(Service("Фотосессия", 6000.0, "Стандартная фотосессия в студии"));
    services.push_back(Service("Портрет", 7000.0, "Профессиональный портрет"));
    employees.push_back(Employee("Иван", "Петров", 30, "ivan", "123", "Фотограф"));
    clients.push_back(Client("Анна", "Смирнова", 25, "anna", "456", services[0]));

    CMenuItem items[ITEMS_NUMBER] {
        CMenuItem{"Root of 25", f1}, 
        CMenuItem{"Print house", f2},
        CMenuItem{"Display Employee Info", displayEmployeeInfo},
        CMenuItem{"Display Client Info", displayClientInfo},
        CMenuItem{"Добавить услугу", addService},
        CMenuItem{"Список услуг", listServices},
        CMenuItem{"Сортировать услуги по цене", sortServicesByPrice},
        CMenuItem{"Добавить сотрудника", addEmployee},
        CMenuItem{"Список сотрудников", listEmployees},
        CMenuItem{"Добавить клиента", addClient},
        CMenuItem{"Список клиентов", listClients},
        CMenuItem{"Сравнить услуги", compareServices},
        CMenuItem{"Тест оператора вывода", []() { cout << services[0] << endl; return 15; }},
        CMenuItem{"Тест оператора сравнения", []() { 
            cout << "Услуги " << (services[0] == services[1] ? "равны" : "разные") << endl; 
            return 16; 
        }}
    };
    CMenu menu("Фотостудия - Управление", items, ITEMS_NUMBER);
    while (menu.runCommand()) {};

    return 0;
}