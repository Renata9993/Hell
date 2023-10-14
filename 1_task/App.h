#pragma once

class App {
public:
    void mainTask();
    
    // Functions for saving and loading ships to/from a file
    void saveToFile(const char* filename) const;
    void loadFromFile(const char* filename);
};
