#pragma once
#include "User.h"
#include "Service.h"

class Client : public User {
private:
    Service service;

public:
    Client(const std::string& firstName, const std::string& lastName, int age, 
           const std::string& login, const std::string& password, const Service& service);
    void displayInfo() const override;
    void authenticate() const override;
};