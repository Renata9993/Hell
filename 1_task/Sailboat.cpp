#include "Sailboat.h"

// Default constructor
Sailboat::Sailboat()
    : type("None"),
      name("None"),
      purpose("None"),
      hullLength(0.0),
      speed(0.0),
      crew(0) 
{
    std::cout << "Sailboat constructor was called." << std::endl;
}

// Constructor with parameters
Sailboat::Sailboat(const std::string& type, const std::string& name, 
                   const std::string& purpose, double hullLength, double speed, int crew)
    : type(type), 
      name(name),
      purpose(purpose),
      hullLength(hullLength),
      speed(speed),
      crew(crew)
{
    std::cout << "Sailboat constructor with parameters was called." << std::endl;
}


// Copy constructor
Sailboat::Sailboat(const Sailboat& other)
    : type(other.type), 
      name(other.name),
      purpose(other.purpose),
      hullLength(other.hullLength),
      speed(other.speed),
      crew(other.crew)
{
    std::cout << "Sailboat copy constructor was called." << std::endl;
}

// Destructor
Sailboat::~Sailboat() {
    std::cout << "Sailboat destructor was called." << std::endl;
}

// Getter functions
std::string Sailboat::getType() const {
    return type;
}

std::string Sailboat::getName() const {
    return name;
}

std::string Sailboat::getPurpose() const {
    return purpose;
}

double Sailboat::getHullLength() const {
    return hullLength;
}

double Sailboat::getSpeed() const {
    return speed;
}

int Sailboat::getCrew() const {
    return crew;
}

// Setter functions
void Sailboat::setType(const std::string& newType) {
    type = newType;
}

void Sailboat::setName(const std::string& newName) {
    name = newName;
}

void Sailboat::setPurpose(const std::string& newPurpose) {
    purpose = newPurpose;
}

void Sailboat::setHullLength(double newHullLength) {
    hullLength = newHullLength;
}

void Sailboat::setSpeed(double newSpeed) {
    speed = newSpeed;
}

void Sailboat::setCrew(int newCrew) {
    crew = newCrew;
}

bool Sailboat::operator==(const Ship& ship) const {
    if (dynamic_cast<const Sailboat*>(&ship)) {
        const Sailboat& sailboat = dynamic_cast<const Sailboat&>(ship);
        return type == sailboat.type && name == sailboat.name && purpose == sailboat.purpose &&
            hullLength == sailboat.hullLength && speed == sailboat.speed && crew == sailboat.crew;
    }
    return false;
}

// Display sailboat information
void Sailboat::display() const {
    std::cout << "\n----Sailboat----" << std::endl;
    std::cout << "Type: " << type << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Purpose: " << purpose << std::endl;
    std::cout << "Hull Length: " << hullLength << " meters" << std::endl;
    std::cout << "Speed: " << speed << " knots" << std::endl;
    std::cout << "Crew: " << crew << " people" << std::endl;
}

// Input sailboat details from the user
void Sailboat::input() {
    std::cout << "Enter Sailboat Type: ";
    std::cin >> type;
    std::cout << "Enter Sailboat Name: ";
    std::cin >> name;
    std::cout << "Enter Sailboat Purpose: ";
    std::cin >> purpose;
    std::cout << "Enter Hull Length: ";
    std::cin >> hullLength;
    std::cout << "Enter Speed: ";
    std::cin >> speed;
    std::cout << "Enter Crew: ";
    std::cin >> crew;
}

// Change Sailboat data
void Sailboat::edit() {
    std::cout << "Current Sailboat details:" << std::endl;
    display();

    std::cout << "Select the data to change:" << std::endl;
    std::cout << "1. Type" << std::endl;
    std::cout << "2. Name" << std::endl;
    std::cout << "3. Purpose" << std::endl;
    std::cout << "4. Hull Length" << std::endl;
    std::cout << "5. Speed" << std::endl;
    std::cout << "6. Crew" << std::endl;
    std::cout << "0. Cancel" << std::endl;
    std::cout << "Enter your choice: ";

    int choice;
    if (!(std::cin >> choice)) {
        std::cin.clear();
        std::cerr << "Invalid choice. Please enter a number." << std::endl;
        return;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear any remaining newline characters

    
    std::cout << "Enter the new value: ";
    std::string change;
    std::cin >> change;
    
    switch (choice) {
        case 1: {
            setType(change);
            std::cout << "Type changed to: " << change << std::endl;
            break;
        }
        case 2: {
            setName(change);
            std::cout << "Name changed to: " << change << std::endl;
            break;
        }
        case 3: {
            setPurpose(change);
            std::cout << "Purpose changed to: " << change << std::endl;
            break;
        }
        case 4: {
            double newHullLength;
            try {
                newHullLength = stod(change);
                if (newHullLength >= 0) {
                    setHullLength(newHullLength);
                    std::cout << "Hull length changed to: " << newHullLength << std::endl;
                } else {
                    std::cerr << "Value cannot be less than 0." << std::endl;
                }
            } catch (const std::invalid_argument& e) {
                std::cerr << "Please enter a double value." << std::endl;
                std::cin.clear();
            }
            break;
        }
        case 5: {
            double newSpeed;
            try {
                newSpeed = stod(change);
                if (newSpeed >= 0) {
                    setSpeed(newSpeed);
                    std::cout << "Speed changed to: " << newSpeed << std::endl;
                } else {
                    std::cerr << "Value cannot be less than 0." << std::endl;
                }
            } catch (const std::invalid_argument& e) {
                std::cerr << "Please enter a double value." << std::endl;
                std::cin.clear();
            }
            break;
        }
        case 6: {
            int newCrew;
            try {
                newCrew = stoi(change);
                if (newCrew >= 0) {
                    setCrew(newCrew);
                    std::cout << "Crew size changed to: " << newCrew << std::endl;
                } else {
                    std::cerr << "Value cannot be less than 0." << std::endl;
                }
            } catch (const std::invalid_argument& e) {
                std::cerr << "Please enter an integer value." << std::endl;
                std::cin.clear();
            }
            break;
        }
        case 0: {
            std::cout << "Modification canceled." << std::endl;
            break;
        }
        default: {
            std::cerr << "Invalid choice. Please try again." << std::endl;
        }
    }
}

// Save sailboat details to a file
void Sailboat::save(std::ofstream& file) const {
    if (file.is_open()) {
        file << "Sailboat " << type << " " << name << " " << purpose << " " << hullLength << " " << speed << " " << crew << std::endl;
        std::cout << "Sailboat data saved." << std::endl;
    } else {
        std::cerr << "Failed to save Sailboat data." << std::endl;
    }
}

// Load sailboat details from a file
void Sailboat::load(std::ifstream& file) {
    if (file.is_open()) {
        file >> type >> name >> purpose >> hullLength >> speed >> crew;
        std::cout << "Sailboat data loaded." << std::endl;
    } else {
        std::cerr << "Failed to load Sailboat data." << std::endl;
    }
}
