#pragma once

#include "Ship.h"

#include <iostream>
#include <fstream>
#include <string>

class Submarine : public Ship {
private:
    // Properties specific to submarines
    std::string name;
    double length;
    double width;
    int crew;
    double timeUnderWater;
    double maxUnderwaterSpeed;
    std::string armament;
    
public:
    // Default constructor
    Submarine();

    // Constructor with parameters
    Submarine(const std::string& name, double length, double width, int crew,
              double timeUnderWater, double maxUnderwaterSpeed, const std::string& armament);

    // Copy constructor
    Submarine(const Submarine& other);

    // Destructor
    ~Submarine();
    
    // Getter functions
    std::string getName() const;
    double getLength() const;
    double getWidth() const;
    int getCrew() const;
    double getTimeUnderWater() const;
    double getMaxUnderwaterSpeed() const;
    std::string getArmament() const;
    
    // Setter functions
    void setName(const std::string& newName);
    void setLength(double newLength);
    void setWidth(double newWidth);
    void setCrew(int newCrew);
    void setTimeUnderWater(double newTimeUnderWater);
    void setMaxUnderwaterSpeed(double newMaxUnderwaterSpeed);
    void setArmament(const std::string& newArmament);
    
    // Display submarine information
    void display() const override;

    // Input submarine details from the user
    void input() override;
    
    // Change submarine data
    void edit() override;

    // Save submarine details to a file
    void save(std::ofstream& file) const override;

    // Load submarine details from a file
    void load(std::ifstream& file) override;
};
