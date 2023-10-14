#pragma once

#include "Ship.h"
 
class Boat : public Ship {
private:
    char* purpose;
    char* hullMaterial;
    char* drivingCharacteristics;
    double speed;
    int maxCapacity;

public:
    Boat(const char* _name, const char* _type, const char* _purpose,
         const char* _hullMaterial, const char* _drivingCharacteristics,
         double _speed, int _maxCapacity);

    ~Boat() override;

    // Get functions
    const char* getPurpose() const;
    const char* getHullMaterial() const;
    const char* getDrivingCharacteristics() const;
    double getSpeed() const;
    int getMaxCapacity() const;
    
    // Set functions
    void setPurpose(const char* _purpose);
    void setHullMaterial(const char* _hullMaterial);
    void setDrivingCharacteristics(const char* _drivingCharacteristics);
    void setSpeed(double _speed);
    void setMaxCapacity(int _maxCapacity);

    void displayInfo() const override;
};
