#include "Submarine.h"

// Default constructor
Submarine::Submarine()
    : name("None"),
      length(0.0),
      width(0.0),
      crew(0),
      timeUnderWater(0.0),
      maxUnderwaterSpeed(0.0),
      armament("None")
{
    std::cout << "Submarine constructor was called." << std::endl;
}

// Constructor with parameters
Submarine::Submarine(const std::string& name, double length, double width, int crew,
                     double timeUnderWater, double maxUnderwaterSpeed, const std::string& armament)
    : name(name),
      length(length),
      width(width),
      crew(crew),
      timeUnderWater(timeUnderWater),
      maxUnderwaterSpeed(maxUnderwaterSpeed),
      armament(armament)
{
    std::cout << "Submarine constructor with parameters called." << std::endl;
}

// Copy constructor
Submarine::Submarine(const Submarine& other)
    : name(other.name),
      length(other.length),
      width(other.width),
      crew(other.crew),
      timeUnderWater(other.timeUnderWater),
      maxUnderwaterSpeed(other.maxUnderwaterSpeed),
      armament(other.armament)
{
    std::cout << "Submarine copy constructor called." << std::endl;
}

// Destructor
Submarine::~Submarine() {
    std::cout << "Submarine destructor called." << std::endl;
}

// Getter functions
std::string Submarine::getName() const {
    return name;
}

double Submarine::getLength() const {
    return length;
}

double Submarine::getWidth() const {
    return width;
}

int Submarine::getCrew() const {
    return crew;
}

double Submarine::getTimeUnderWater() const {
    return timeUnderWater;
}

double Submarine::getMaxUnderwaterSpeed() const {
    return maxUnderwaterSpeed;
}

std::string Submarine::getArmament() const {
    return armament;
}

// Setter functions
void Submarine::setName(const std::string& newName) {
    name = newName;
}

void Submarine::setLength(double newLength) {
    length = newLength;
}

void Submarine::setWidth(double newWidth) {
    width = newWidth;
}

void Submarine::setCrew(int newCrew) {
    crew = newCrew;
}

void Submarine::setTimeUnderWater(double newTimeUnderWater) {
    timeUnderWater = newTimeUnderWater;
}

void Submarine::setMaxUnderwaterSpeed(double newMaxUnderwaterSpeed) {
    maxUnderwaterSpeed = newMaxUnderwaterSpeed;
}

void Submarine::setArmament(const std::string& newArmament) {
    armament = newArmament;
}

// Display submarine information
void Submarine::display() const {
    std::cout << "\n----Submarine----" << std::endl;
    std::cout << "Submarine Name: " << name << std::endl;
    std::cout << "Length (meters): " << length << std::endl;
    std::cout << "Width (meters): " << width << std::endl;
    std::cout << "Crew: " << crew << std::endl;
    std::cout << "Time Under Water (hours): " << timeUnderWater << std::endl;
    std::cout << "Max Underwater Speed (knots): " << maxUnderwaterSpeed << std::endl;
    std::cout << "Armament: " << armament << std::endl;
}

// Input submarine details from the user
void Submarine::input() {
    std::cout << "Enter Submarine Name: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    std::cout << "Enter Length (meters): ";
    std::cin >> length;
    std::cout << "Enter Width (meters): ";
    std::cin >> width;
    std::cout << "Enter Crew: ";
    std::cin >> crew;
    std::cout << "Enter Time Under Water (hours): ";
    std::cin >> timeUnderWater;
    std::cout << "Enter Max Underwater Speed (knots): ";
    std::cin >> maxUnderwaterSpeed;
    std::cin.ignore();
    std::cout << "Enter Armament: ";
    std::getline(std::cin, armament);
}

// Change submarine data
void Submarine::edit() {
    std::cout << "Current Submarine details:" << std::endl;
    display();
    
    std::cout << "Select the data to change:" << std::endl;
    std::cout << "1. Name" << std::endl;
    std::cout << "2. Length" << std::endl;
    std::cout << "3. Width" << std::endl;
    std::cout << "4. Crew" << std::endl;
    std::cout << "5. Time Under Water" << std::endl;
    std::cout << "6. Max Underwater Speed" << std::endl;
    std::cout << "7. Armament" << std::endl;
    std::cout << "0. Cancel" << std::endl;
    std::cout << "Enter your choice: ";
    
    int choice;
    if (!(std::cin >> choice)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cerr << "Invalid choice. Please enter a number." << std::endl;
        return;
    }
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear any remaining newline characters

    switch (choice) {
        case 1: {
            std::string newName;
            std::cout << "Enter the new name: ";
            std::getline(std::cin, newName);
            setName(newName);
            std::cout << "Name changed to: " << newName << std::endl;
            break;
        }
        case 2: {
            double newLength;
            std::cout << "Enter the new length: ";
            if (!(std::cin >> newLength)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cerr << "Invalid length. Please enter a valid number." << std::endl;
            } else {
                setLength(newLength);
                std::cout << "Length changed to: " << newLength << std::endl;
            }
            break;
        }
        case 3: {
            double newWidth;
            std::cout << "Enter the new width: ";
            if (!(std::cin >> newWidth)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cerr << "Invalid width. Please enter a valid number." << std::endl;
            } else {
                setWidth(newWidth);
                std::cout << "Width changed to: " << newWidth << std::endl;
            }
            break;
        }
        case 4: {
            int newCrew;
            std::cout << "Enter the new crew size: ";
            if (!(std::cin >> newCrew)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cerr << "Invalid crew size. Please enter a valid number." << std::endl;
            } else {
                setCrew(newCrew);
                std::cout << "Crew size changed to: " << newCrew << std::endl;
            }
            break;
        }
        case 5: {
            double newTimeUnderWater;
            std::cout << "Enter the new time under water: ";
            if (!(std::cin >> newTimeUnderWater)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cerr << "Invalid time under water. Please enter a valid number." << std::endl;
            } else {
                setTimeUnderWater(newTimeUnderWater);
                std::cout << "Time under water changed to: " << newTimeUnderWater << std::endl;
            }
            break;
        }
        case 6: {
            double newMaxUnderwaterSpeed;
            std::cout << "Enter the new max underwater speed: ";
            if (!(std::cin >> newMaxUnderwaterSpeed)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cerr << "Invalid max underwater speed. Please enter a valid number." << std::endl;
            } else {
                setMaxUnderwaterSpeed(newMaxUnderwaterSpeed);
                std::cout << "Max underwater speed changed to: " << newMaxUnderwaterSpeed << std::endl;
            }
            break;
        }
        case 7: {
            std::string newArmament;
            std::cout << "Enter the new armament: ";
            std::cin.ignore(); // Clear newline character
            std::getline(std::cin, newArmament);
            setArmament(newArmament);
            std::cout << "Armament changed to: " << newArmament << std::endl;
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

// Save submarine details to a file
void Submarine::save(std::ofstream& file) const {
    if (file.is_open()) {
        file << "Submarine " << name << " " << length << " " << width << " " << crew << " " << timeUnderWater << " " << maxUnderwaterSpeed << " " << armament << std::endl;
        std::cout << "Submarine data saved." << std::endl;
    } else {
        std::cerr << "Failed to save Submarine data." << std::endl;
    }
}

// Load submarine details from a file
void Submarine::load(std::ifstream& file) {
    if (file.is_open()) {
        file >> name >> length >> width >> crew >> timeUnderWater >> maxUnderwaterSpeed >> armament;
        std::cout << "Submarine data loaded." << std::endl;
    } else {
        std::cerr << "Failed to load submarine data." << std::endl;
    }
}
