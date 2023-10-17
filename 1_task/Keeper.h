#pragma once

#include "Ship.h"
#include "Sailboat.h"
#include "Submarine.h"
#include "Boat.h"

#include <stdexcept>

class Keeper {
private:
    Ship** ships;
    int shipCount;
    
public:
    // Default constructor
    Keeper();

    Keeper(const Keeper& other);
    
    // Destructor
    ~Keeper();
    
    Ship* getShip(int index);
    int getShipCount();
    
    void addShip(Ship* newShip);
    void removeShip(const int index);
    void editShip(const int index);
    
    void saveToFile(const std::string& filename);
    void loadFromFile(const std::string& filename);
};
