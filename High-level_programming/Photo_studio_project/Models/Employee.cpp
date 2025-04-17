#include "Employee.h"
#include <iostream>

Employee::Employee(const std::string& firstName, const std::string& lastName, int age, 
                   const std::string& login, const std::string& password, const std::string& position)
    : User(firstName, lastName, age, login, password), position(position) {}

void Employee::displayInfo() const {
    User::displayInfo();
    std::cout << "Position: " << position << std::endl;
}

void Employee::authenticate() const {
    User::authenticate();
}