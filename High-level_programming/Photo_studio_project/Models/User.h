#pragma once
#include <string>

class User {
protected:
    std::string firstName;
    std::string lastName;
    int age;
    std::string login;
    std::string password;

public:
    User(const std::string& firstName, const std::string& lastName, int age, 
         const std::string& login, const std::string& password);
    virtual ~User() = default;

    virtual void displayInfo() const = 0;
    virtual void authenticate() const = 0;
};