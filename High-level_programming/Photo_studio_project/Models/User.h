#pragma once
#include <string>
#include <iostream>

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


    friend std::ostream& operator<<(std::ostream& os, const User& user);
    bool operator==(const User& other) const;
};