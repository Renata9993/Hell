#pragma once

#include <iostream>
#include <fstream>
#include <string>

class Ship {
public:
    // Default constructor
    Ship() { std::cout << "Base Ship constructor called." << std::endl; }
    
    // Virtual destructor
    virtual ~Ship() { std::cout << "Base Ship destructor called." << std::endl; }
    
    virtual void display() const = 0;
    virtual void input() = 0;
    virtual void save(std::ofstream& file) const = 0;
    virtual void load(std::ifstream& file) = 0;
};
