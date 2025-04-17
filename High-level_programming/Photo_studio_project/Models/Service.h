#pragma once
#include <string>

class Service {
private:
    std::string name;
    double price;
    std::string description;

public:
    Service(const std::string& name, double price, const std::string& description);
    std::string getName() const;
    double getPrice() const;
    std::string getDescription() const;
};