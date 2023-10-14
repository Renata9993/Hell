#include "Boat.h"

Boat::Boat(const char* _name, const char* _type, const char* _purpose,
     const char* _hullMaterial, const char* _drivingCharacteristics,
     double _speed, int _maxCapacity)
    : Ship(_name, _type), speed(_speed), maxCapacity(_maxCapacity) {
    purpose = new char[strlen(_purpose) + 1];
    strcpy(purpose, _purpose);
    hullMaterial = new char[strlen(_hullMaterial) + 1];
    strcpy(hullMaterial, _hullMaterial);
    drivingCharacteristics = new char[strlen(_drivingCharacteristics) + 1];
    strcpy(drivingCharacteristics, _drivingCharacteristics);
}

Boat::~Boat() {
    delete[] purpose;
    delete[] hullMaterial;
    delete[] drivingCharacteristics;
}

const char* Boat::getPurpose() const {
    return purpose;
}

const char* Boat::getHullMaterial() const {
    return hullMaterial;
}

const char* Boat::getDrivingCharacteristics() const {
    return drivingCharacteristics;
}

double Boat::getSpeed() const {
    return speed;
}

int Boat::getMaxCapacity() const {
    return maxCapacity;
}

void Boat::setPurpose(const char* _purpose) {
    delete[] purpose;
    purpose = new char[strlen(_purpose) + 1];
    strcpy(purpose, _purpose);
}

void Boat::setHullMaterial(const char* _hullMaterial) {
    delete[] hullMaterial;
    hullMaterial = new char[strlen(_hullMaterial) + 1];
    strcpy(hullMaterial, _hullMaterial);
}

void Boat::setDrivingCharacteristics(const char* _drivingCharacteristics) {
    delete[] drivingCharacteristics;
    drivingCharacteristics = new char[strlen(_drivingCharacteristics) + 1];
    strcpy(drivingCharacteristics, _drivingCharacteristics);
}

void Boat::setSpeed(double _speed) {
    speed = _speed;
}

void Boat::setMaxCapacity(int _maxCapacity) {
    maxCapacity = _maxCapacity;
}

void Boat::displayInfo() const {
    std::cout << "Boat Name: " << getName() << std::endl;
    std::cout << "Boat Type: " << getType() << std::endl;
    std::cout << "Purpose: " << purpose << std::endl;
    std::cout << "Hull Material: " << hullMaterial << std::endl;
    std::cout << "Driving Characteristics: " << drivingCharacteristics << std::endl;
    std::cout << "Speed: " << speed << " knots" << std::endl;
    std::cout << "Max Capacity: " << maxCapacity << " people" << std::endl;
}
