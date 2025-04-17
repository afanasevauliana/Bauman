#include "Service.h"

Service::Service(const std::string& name, double price, const std::string& description)
    : name(name), price(price), description(description) {}

std::string Service::getName() const {
    return name;
}

double Service::getPrice() const {
    return price;
}

std::string Service::getDescription() const {
    return description;
}