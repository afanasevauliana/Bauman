#include "User.h"
#include <iostream>

User::User(const std::string& firstName, const std::string& lastName, int age, 
           const std::string& login, const std::string& password)
    : firstName(firstName), lastName(lastName), age(age), login(login), password(password) {}

void User::displayInfo() const {
    std::cout << "Name: " << firstName << " " << lastName << "\nAge: " << age << std::endl;
}

void User::authenticate() const {
    std::cout << "Login: " << login << "\nPassword: ******" << std::endl;
}