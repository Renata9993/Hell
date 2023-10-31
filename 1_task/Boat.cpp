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

bool Boat::operator==(const Ship& ship) const {
    if (dynamic_cast<const Boat*>(&ship)) {
        const Boat& boat = dynamic_cast<const Boat&>(ship);
        return purpose == boat.purpose && hullMaterial == boat.hullMaterial && speed == boat.speed &&
            drivingCharacteristics == boat.drivingCharacteristics && maxPassengers == boat.maxPassengers;
    }
    return false;
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

// Change boat data
void Boat::edit() {
    std::cout << "Current Boat details:" << std::endl;
    display();

    std::cout << "Select the data to change:" << std::endl;
    std::cout << "1. Purpose" << std::endl;
    std::cout << "2. Hull Material" << std::endl;
    std::cout << "3. Driving Characteristics" << std::endl;
    std::cout << "4. Speed" << std::endl;
    std::cout << "5. Max Passengers" << std::endl;
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
            setPurpose(change);
            std::cout << "Purpose changed to: " << change << std::endl;
            break;
        }
        case 2: {
            setHullMaterial(change);
            std::cout << "Hull Material changed to: " << change << std::endl;
            break;
        }
        case 3: {
            setDrivingCharacteristics(change);
            std::cout << "Driving Characteristics changed to: " << change << std::endl;
            break;
        }
        case 4: {
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
        case 5: {
            int newMaxPassengers;
            try {
                newMaxPassengers = stoi(change);
                if (newMaxPassengers >= 0) {
                    setMaxPassengers(newMaxPassengers);
                    std::cout << "Max Passengers changed to: " << newMaxPassengers << std::endl;
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

