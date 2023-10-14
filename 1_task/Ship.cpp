#include "Ship.h"

Ship::Ship()
    : name(nullptr)
    , type(nullptr)
{
}

Ship::Ship(const Ship& other) {
    
}

Ship::Ship(const char* _name, const char* _type) {
    name = new char[strlen(_name) + 1];
    strcpy(name, _name);
    type = new char[strlen(_type) + 1];
    strcpy(type, _type);
}

Ship::~Ship() {
//    delete[] name;
//    delete[] type;
    
    for (int i = 0; i < shipCount; ++i) {
        delete ships[i];
    }
    delete[] ships;
}

const char* Ship::getName() const {
    return name;
}

const char* Ship::getType() const {
    return type;
}

void Ship::setName(const char* _name) {
    delete[] name;
    name = new char[strlen(_name) + 1];
    strcpy(name, _name);
}

void Ship::setType(const char* _type) {
    delete[] type;
    type = new char[strlen(_type) + 1];
    strcpy(type, _type);
}


void Ship::addShip(Ship *ship) {
    Ship** newShips = new Ship*[shipCount + 1];
    
    for (int i = 0; i < shipCount; ++i) {
        newShips[i] = ships[i];
    }
    
    newShips[shipCount] = ship;
    delete[] ships;
    
    ships = newShips;
    shipCount++;
}

void Ship::removeShip(const char* shipName) {
    for (int i = 0; i < shipCount; ++i) {
        if (strcmp(ships[i]->getName(), shipName) == 0) {
            delete ships[i];
            for (int j = i; j < shipCount - 1; ++j) {
                ships[j] = ships[j + 1];
            }
            shipCount--;
            break;
        }
    }
}

void Ship::displayAllShips() const {
    for (int i = 0; i < shipCount; ++i) {
        ships[i]->displayInfo();
        std::cout << std::endl;
    }
}

void Ship::displayByType(const char* _type) const {
    for (int i = 0; i < shipCount; i++) {
        if (ships[i]->type == _type) { // Compares only the first letter
            ships[i]->displayInfo();
            std::cout << std::endl;
        }
    }
}
