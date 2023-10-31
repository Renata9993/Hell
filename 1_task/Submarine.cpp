#include "Submarine.h"

// Default constructor
Submarine::Submarine()
    : length(0.0),
      width(0.0),
      crew(0),
      timeUnderWater(0.0),
      maxUnderwaterSpeed(0.0),
      armament("None")
{
    std::cout << "Submarine constructor was called." << std::endl;
}

// Constructor with parameters
Submarine::Submarine(double length, double width, int crew,
                     double timeUnderWater, double maxUnderwaterSpeed, const std::string& armament)
    : length(length),
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
    : length(other.length),
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

bool Submarine::operator==(const Ship& ship) const {
    if (dynamic_cast<const Submarine*>(&ship)) {
        const Submarine& submarine = dynamic_cast<const Submarine&>(ship);
        return length == submarine.length && width == submarine.width && armament == submarine.armament &&
            crew == submarine.crew && maxUnderwaterSpeed == submarine.maxUnderwaterSpeed && timeUnderWater == submarine.timeUnderWater;
    }
    return false;
}

// Display submarine information
void Submarine::display() const {
    std::cout << "\n----Submarine----" << std::endl;
    std::cout << "Length (meters): " << length << std::endl;
    std::cout << "Width (meters): " << width << std::endl;
    std::cout << "Crew: " << crew << std::endl;
    std::cout << "Time Under Water (hours): " << timeUnderWater << std::endl;
    std::cout << "Max Underwater Speed (knots): " << maxUnderwaterSpeed << std::endl;
    std::cout << "Armament: " << armament << std::endl;
}

// Input submarine details from the user
void Submarine::input() {
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
    std::cout << "1. Length" << std::endl;
    std::cout << "2. Width" << std::endl;
    std::cout << "3. Crew" << std::endl;
    std::cout << "4. Time Under Water" << std::endl;
    std::cout << "5. Max Underwater Speed" << std::endl;
    std::cout << "6. Armament" << std::endl;
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
            double newLength;
            try {
                newLength = stod(change);
                if (newLength >= 0) {
                    setLength(newLength);
                    std::cout << "Length changed to: " << newLength << std::endl;
                } else {
                    std::cerr << "Value cannot be less than 0." << std::endl;
                }
            } catch (const std::invalid_argument& e) {
                std::cerr << "Please enter a double value." << std::endl;
                std::cin.clear();
            }
            break;
        }
        case 2: {
            double newWidth;
            try {
                newWidth = stod(change);
                if (newWidth >= 0) {
                    setWidth(newWidth);
                    std::cout << "Width changed to: " << newWidth << std::endl;
                } else {
                    std::cerr << "Value cannot be less than 0." << std::endl;
                }
            } catch (const std::invalid_argument& e) {
                std::cerr << "Please enter a double value." << std::endl;
                std::cin.clear();
            }
            break;
        }
        case 3: {
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
        case 4: {
            double newTimeUnderWater;
            try {
                newTimeUnderWater = stod(change);
                if (newTimeUnderWater >= 0) {
                    setTimeUnderWater(newTimeUnderWater);
                    std::cout << "Time under water changed to: " << newTimeUnderWater << std::endl;
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
            double newMaxUnderwaterSpeed;
            try {
                newMaxUnderwaterSpeed = stod(change);
                if (newMaxUnderwaterSpeed >= 0) {
                    setMaxUnderwaterSpeed(newMaxUnderwaterSpeed);
                    std::cout << "Max underwater speed changed to: " << newMaxUnderwaterSpeed << std::endl;
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
            setArmament(change);
            std::cout << "Armament changed to: " << change << std::endl;
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
        file << "Submarine " << length << " " << width << " " << crew << " " << timeUnderWater << " " << maxUnderwaterSpeed << " " << armament << std::endl;
        std::cout << "Submarine data saved." << std::endl;
    } else {
        std::cerr << "Failed to save Submarine data." << std::endl;
    }
}

// Load submarine details from a file
void Submarine::load(std::ifstream& file) {
    if (file.is_open()) {
        file >> length >> width >> crew >> timeUnderWater >> maxUnderwaterSpeed >> armament;
        std::cout << "Submarine data loaded." << std::endl;
    } else {
        std::cerr << "Failed to load submarine data." << std::endl;
    }
}
