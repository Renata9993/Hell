#include "Keeper.h"

// Default constructor
Keeper::Keeper() : ships(nullptr), shipCount(0) {
    std::cout << "Keeper constructor was called." << std::endl;
}

// Copy constructor
Keeper::Keeper(const Keeper& other) {
    shipCount = other.shipCount;
    ships = new Ship*[shipCount];
    for (int i = 0; i < shipCount; ++i) {
        // Depending on the ship type, create a new ship object and copy its properties
        if (dynamic_cast<Submarine*>(other.ships[i])) {
            ships[i] = new Submarine(*dynamic_cast<Submarine*>(other.ships[i]));
        } else if (dynamic_cast<Sailboat*>(other.ships[i])) {
            ships[i] = new Sailboat(*dynamic_cast<Sailboat*>(other.ships[i]));
        } else if (dynamic_cast<Boat*>(other.ships[i])) {
            ships[i] = new Boat(*dynamic_cast<Boat*>(other.ships[i]));
        }
    }
    std::cout << "Keeper copy constructor was called." << std::endl;
}

// Destructor
Keeper::~Keeper() {
    if (ships) {
        for (int i = 0; i < shipCount; ++i) {
            delete ships[i];
        }
        delete[] ships;
    }
    std::cout << "Keeper destructor called." << std::endl;
}

Ship* Keeper::getShip(int index) {
    if (index >= 0 && index < shipCount) {
        return ships[index];
    } else {
        std::cerr << "Invalid index, cannot get ship." << std::endl;
        return nullptr;
    }
}

int Keeper::getShipCount() {
    return shipCount;
}

void Keeper::addShip(Ship* newShip) {
    Ship** newShips = new Ship*[shipCount + 1];
    for (int i = 0; i < shipCount; ++i) {
        newShips[i] = ships[i];
    }
    newShips[shipCount] = newShip;

    if (ships) {
        delete[] ships;
    }

    ships = newShips;
    shipCount++;
}

void Keeper::removeShip(const int index) {
    if (index >= 0 && index < shipCount) {
        delete ships[index];
        for (int i = index; i < shipCount - 1; ++i) {
            ships[i] = ships[i + 1];
        }
        shipCount--;
    } else {
        std::cerr << "Invalid index, cannot remove ship." << std::endl;
    }
}

void Keeper::editShip(const int index) {
    if (index >= 0 && index < shipCount) {
        ships[index]->edit();
    } else {
        std::cerr << "Invalid index, cannot remove ship." << std::endl;
    }
}

void Keeper::saveToFile(const std::string& filename) {
    std::ofstream file;
    file.exceptions(std::ios::failbit | std::ios::badbit);
    try {
        file.open(filename, std::ios::binary);
        for (int i = 0; i < shipCount; ++i) {
            ships[i]->save(file);
        }
        file.close();
        std::cout << "Done." << std::endl << std::endl;
    } catch (const std::ios_base::failure& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void Keeper::loadFromFile(const std::string& filename) {
    std::ifstream file;
    file.exceptions(std::ios::failbit | std::ios::badbit);
    try {
        file.open(filename, std::ios::binary);

        while (!file.eof()) {
            std::string shipType;
            file >> shipType;
            file.ignore();
            Ship* newShip = nullptr;

            if (shipType == "Boat") {
                newShip = new Boat();
            } else if (shipType == "Submarine") {
                newShip = new Submarine();
            } else if (shipType == "Sailboat") {
                newShip = new Sailboat();
            }

            if (newShip) {
                newShip->load(file);
                addShip(newShip);
            }
        }
        
        file.close();
    } catch (const std::ios_base::failure& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
