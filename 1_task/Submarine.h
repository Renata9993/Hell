#pragma once

#include "Ship.h"

class Submarine : public Ship {
private:
    double length;
    double width;
    int crew;
    double timeUnderWater;
    double maxUnderwaterSpeed;
    char* armament;
    
public:
    Submarine(const char* _name, const char* _type, double _length, double _width, int _crew, double _timeUnderWater, double _maxUnderwaterSpeed, const char* _armament);

    ~Submarine() override;

    // Get functions
    double getLength() const;
    double getWidth() const;
    int getCrew() const;
    double getTimeUnderWater() const;
    double getMaxUnderwaterSpeed() const;
    const char* getArmament() const;

    // Set functions
    void setLength(double _length);
    void setWidth(double _width);
    void setCrew(int _crew);
    void setTimeUnderWater(double _timeUnderWater);
    void setMaxUnderwaterSpeed(double _maxUnderwaterSpeed);
    void setArmament(const char* _armament);

    void displayInfo() const override;
};
