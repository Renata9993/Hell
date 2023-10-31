#pragma once

#include "Ship.h"
 
#include <iostream>
#include <fstream>
#include <string>

class Boat : public Ship {
private:
    // Properties specific to boats
    std::string purpose;
    std::string hullMaterial;
    std::string drivingCharacteristics;
    double speed;
    int maxPassengers;

public:
    // Default constructor
    Boat();

    // Constructor with parameters
    Boat(const std::string& purpose, const std::string& hullMaterial, 
         const std::string& drivingCharacteristics, double speed, int maxPassengers);
    
    // Copy constructor
    Boat(const Boat& other);

    // Destructor
    ~Boat();
    
    // Getter functions
    std::string getPurpose() const;
    std::string getHullMaterial() const;
    std::string getDrivingCharacteristics() const;
    double getSpeed() const;
    int getMaxPassengers() const;

    // Setter functions
    void setPurpose(const std::string& newPurpose);
    void setHullMaterial(const std::string& newHullMaterial);
    void setDrivingCharacteristics(const std::string& newDrivingCharacteristics);
    void setSpeed(double newSpeed);
    void setMaxPassengers(int newMaxPassengers);
    
    bool operator==(const Ship& ship) const override;

    // Display boat information
    void display() const override;

    // Input boat details from the user
    void input() override;
    
    // Change boat data
    void edit() override;

    // Save boat details to a file
    void save(std::ofstream& file) const override;

    // Load boat details from a file
    void load(std::ifstream& file) override;
};
