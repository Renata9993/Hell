#include "Boat.h"

// Default constructor
Boat::Boat()
    : purpose("None"),
      hullMaterial("None"),
      drivingCharacteristics("None"),
      speed(0.0),
      maxPassengers(0) 
{
    std::cout << "Boat constructor called." << std::endl;
}

// Constructor with parameters
Boat::Boat(const std::string& purpose, const std::string& hullMaterial, 
           const std::string& drivingCharacteristics, double speed, int maxPassengers)
    : purpose(purpose), 
      hullMaterial(hullMaterial),
      drivingCharacteristics(drivingCharacteristics),
      speed(speed),
      maxPassengers(maxPassengers)
{
    std::cout << "Boat constructor with parameters called." << std::endl;
}

// Copy constructor
Boat::Boat(const Boat& other)
    : purpose(other.purpose), 
      hullMaterial(other.hullMaterial),
      drivingCharacteristics(other.drivingCharacteristics),
      speed(other.speed), 
      maxPassengers(other.maxPassengers)
{
    std::cout << "Boat copy constructor called." << std::endl;
}

// Destructor
Boat::~Boat() {
    std::cout << "Boat destructor called." << std::endl;
}

// Getter functions
std::string Boat::getPurpose() const {
    return purpose;
}

std::string Boat::getHullMaterial() const {
    return hullMaterial;
}

std::string Boat::getDrivingCharacteristics() const {
    return drivingCharacteristics;
}

double Boat::getSpeed() const {
    return speed;
}

int Boat::getMaxPassengers() const {
    return maxPassengers;
}

// Setter functions
void Boat::setPurpose(const std::string& newPurpose) {
    purpose = newPurpose;
}

void Boat::setHullMaterial(const std::string& newHullMaterial) {
    hullMaterial = newHullMaterial;
}

void Boat::setDrivingCharacteristics(const std::string& newDrivingCharacteristics) {
    drivingCharacteristics = newDrivingCharacteristics;
}

void Boat::setSpeed(double newSpeed) {
    speed = newSpeed;
}

void Boat::setMaxPassengers(int newMaxPassengers) {
    maxPassengers = newMaxPassengers;
}

// Display boat information
void Boat::display() const {
    std::cout << "\n----Boat----" << std::endl;
    std::cout << "Purpose: " << purpose << std::endl;
    std::cout << "Hull Material: " << hullMaterial << std::endl;
    std::cout << "Driving Characteristics: " << drivingCharacteristics << std::endl;
    std::cout << "Speed: " << speed << " knots" << std::endl;
    std::cout << "Maximum Passengers: " << maxPassengers << " persons" << std::endl;
}

// Input boat details from the user
void Boat::input() {
    std::cout << "Enter Boat Purpose: ";
    std::cin >> purpose;
    std::cout << "Enter Hull Material: ";
    std::cin >> hullMaterial;
    std::cout << "Enter Driving Characteristics: ";
    std::cin >> drivingCharacteristics;
    std::cout << "Enter Speed (in knots): ";
    std::cin >> speed;
    std::cout << "Enter Maximum Passengers: ";
    std::cin >> maxPassengers;
}

// Save boat details to a file
void Boat::save(std::ofstream& file) const {
    if (file.is_open()) {
        file << "Boat " << purpose << " " << hullMaterial << " " << drivingCharacteristics << " " << speed << " " << maxPassengers << std::endl;
        std::cout << "Boat data saved." << std::endl;
    } else {
        std::cerr << "Failed to save Boat data." << std::endl;
    }
}

// Load boat details from a file
void Boat::load(std::ifstream& file) {
    if (file.is_open()) {
        file >> purpose >> hullMaterial >> drivingCharacteristics >> speed >> maxPassengers;
        std::cout << "Boat data loaded." << std::endl;
    } else {
        std::cerr << "Failed to load Boat data." << std::endl;
    }
}

