#pragma once

#include <iostream>

class Ship {
protected: /* ?????? */
    // Common attributes for all ships
    char* name;
    char* type;
    
private:
    Ship** ships;
    int shipCount;

public:
    Ship(); // Default constructor
    Ship(const Ship& other); // Copy constructor
    Ship(const char* _name, const char* _type); // Constructor with parameters
    virtual ~Ship(); // Destructor
    
    // File and type set an get functions
    const char* getName() const;
    const char* getType() const;

    void setName(const char* _name);
    void setType(const char* _type);

    virtual void displayInfo() const = 0;
    
    // Functions for adding, removing, and displaying ships
    void addShip(Ship* ship);
    void removeShip(const char* shipName);
    void displayAllShips() const;
    
    /* ????????? добавить ????????*/
    void displayByType(const char* _type) const;

    // Functions for saving and loading ships to/from a file
    void saveToFile(const char* filename) const;
    void loadFromFile(const char* filename);
};
