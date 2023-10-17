#pragma once

#include "Ship.h"

#include <iostream>
#include <fstream>
#include <string>

class Sailboat : public Ship {
private:
    // Properties specific to sailboats
    std::string type;
    std::string name;
    std::string purpose;
    double hullLength;
    double speed;
    int crew;

public:
    // Default constructor
    Sailboat();

    // Constructor with parameters
    Sailboat(const std::string& type, const std::string& name, const std::string& purpose, double hullLength, double speed, int crew);

    // Copy constructor
    Sailboat(const Sailboat& other);

    // Destructor
    ~Sailboat();
    
    
    // Getter functions
    std::string getType() const;
    std::string getName() const;
    std::string getPurpose() const;
    double getHullLength() const;
    double getSpeed() const;
    int getCrew() const;

    // Setter functions
    void setType(const std::string& newType);
    void setName(const std::string& newName);
    void setPurpose(const std::string& newPurpose);
    void setHullLength(double newHullLength);
    void setSpeed(double newSpeed);
    void setCrew(int newCrew);

    // Display sailboat information
    void display() const override;

    // Input sailboat details from the user
    void input() override;
    
    // Change Sailboat data
    void edit() override;

    // Save sailboat details to a file
    void save(std::ofstream& file) const override;

    // Load sailboat details from a file
    void load(std::ifstream& file) override;
};
