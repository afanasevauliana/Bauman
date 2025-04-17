#include "Client.h"
#include <iostream>

Client::Client(const std::string& firstName, const std::string& lastName, int age, 
               const std::string& login, const std::string& password, const Service& service)
    : User(firstName, lastName, age, login, password), service(service) {}

void Client::displayInfo() const {
    User::displayInfo();
    std::cout << "Service: " << service.getName() << std::endl;
}

void Client::authenticate() const {
    User::authenticate();
}