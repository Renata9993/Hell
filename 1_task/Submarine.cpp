#include "Submarine.h"

Submarine::Submarine(const char* _name, const char* _type, double _length, double _width, int _crew, double _timeUnderWater, double _maxUnderwaterSpeed, const char* _armament)
        : Ship(_name, _type), length(_length), width(_width), crew(_crew),
          timeUnderWater(_timeUnderWater), maxUnderwaterSpeed(_maxUnderwaterSpeed) {
        armament = new char[strlen(_armament) + 1];
        strcpy(armament, _armament);
    }

Submarine::~Submarine() {
    delete[] armament;
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

const char* Submarine::getArmament() const {
    return armament;
}

void Submarine::setLength(double _length) {
    length = _length;
}

void Submarine::setWidth(double _width) {
    width = _width;
}

void Submarine::setCrew(int _crew) {
    crew = _crew;
}

void Submarine::setTimeUnderWater(double _timeUnderWater) {
    timeUnderWater = _timeUnderWater;
}

void Submarine::setMaxUnderwaterSpeed(double _maxUnderwaterSpeed) {
    maxUnderwaterSpeed = _maxUnderwaterSpeed;
}

void Submarine::setArmament(const char* _armament) {
    delete[] armament;
    armament = new char[strlen(_armament) + 1];
    strcpy(armament, _armament);
}

void Submarine::displayInfo() const {
    std::cout << "Submarine Name: " << getName() << std::endl;
    std::cout << "Submarine Type: " << getType() << std::endl;
    std::cout << "Length: " << length << " meters" << std::endl;
    std::cout << "Width: " << width << " meters" << std::endl;
    std::cout << "Crew: " << crew << " members" << std::endl;
    std::cout << "Time Under Water: " << timeUnderWater << " hours" << std::endl;
    std::cout << "Max Underwater Speed: " << maxUnderwaterSpeed << " knots" << std::endl;
    std::cout << "Armament: " << armament << std::endl;
}
