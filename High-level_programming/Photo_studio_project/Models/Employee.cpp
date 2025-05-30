#include "Employee.h"
#include <iostream>

Employee::Employee(const std::string& firstName, const std::string& lastName, int age, 
                   const std::string& login, const std::string& password, const std::string& position)
    : User(firstName, lastName, age, login, password), position(position) {}

void Employee::displayInfo() const {
    std::cout << "Сотрудник: " << firstName << " " << lastName << "\nВозраст: " << age 
              << "\nДолжность: " << position << std::endl;
}

void Employee::authenticate() const {
    User::authenticate();
}


std::ostream& operator<<(std::ostream& os, const Employee& employee) {
    employee.displayInfo();
    return os;
}