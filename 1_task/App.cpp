#include "App.h"

using namespace std;

void App::mainTask() {
    Keeper keeper;
    string filename; 
    int choice;

    while (true) {
        std::cout << std::endl;
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Add a ship" << std::endl;
        std::cout << "2. Remove a ship" << std::endl;
        std::cout << "3. Display all ships" << std::endl;
        std::cout << "4. Change parameters" << std::endl;
        std::cout << "5. Save to file" << std::endl;
        std::cout << "6. Load from file" << std::endl;
        std::cout << "7. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        
        if (!(std::cin >> choice)) {
            std::cin.clear(); // Clear error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard the invalid input
            std::cout << "Invalid choice. Please enter a number." << std::endl;
            continue; // Restart the loop
        }

        switch (choice) {
            case 1: {
                // Add a ship
                int shipType;
                std::cout << "Enter ship type (1: Submarine, 2: Sailboat, 3: Boat): ";
                if (!(std::cin >> shipType)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid ship type. Please enter a number." << std::endl;
                    continue; // Restart the loop
                }
                
                Ship* newShip = nullptr;
                if (shipType == 1)
                    newShip = new Submarine;
                else if (shipType == 2)
                    newShip = new Sailboat;
                else if (shipType == 3)
                    newShip = new Boat;
                if (newShip) {
                    newShip->input();
                    keeper.addShip(newShip);
                }
                break;
            }
            case 2: {
                // Remove a ship
                int index;
                std::cout << "Enter the index of the ship to remove: ";
                if (!(std::cin >> index)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid index. Please enter a number." << std::endl;
                    continue; // Restart the loop
                }
                keeper.removeShip(index);
                break;
            }
            case 3: {
                // Display all ships
                for (int i = 0; i < keeper.getShipCount(); ++i) {
                    keeper.getShip(i)->display();
                }
                break;
            }
            case 4: {
                // Change parameters of a ship
                int index;
                std::cout << "Enter the index of the ship to be changed: ";
                if (!(std::cin >> index)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid index. Please enter a number." << std::endl;
                    continue; // Restart the loop
                }
                keeper.editShip(index);
                break;
            }
            case 5: {
                // Save to file
                std::string filename;
                std::cout << "Enter the filename to save to: ";
                if (!(std::cin >> filename)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid filename. Please enter a valid filename." << std::endl;
                    continue; // Restart the loop
                }
                try {
                    keeper.saveToFile(filename);
                    std::cout << "Saved to " << filename << std::endl;
                } catch (const std::runtime_error& e) {
                    std::cerr << e.what() << std::endl;
                }
                break;
            }
            case 6: {
                // Load from file
                std::cout << "Enter the filename to load from: ";
                if (!(std::cin >> filename)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid filename. Please enter a valid filename." << std::endl;
                    continue; // Restart the loop
                }
                try {
                    keeper.loadFromFile(filename);
                    std::cout << "Loaded from " << filename << std::endl;
                } catch (const std::runtime_error& e) {
                    std::cerr << e.what() << std::endl;
                }
                break;
            }
            case 7: {
                return;
            }
            default: {
                std::cout << "Invalid choice. Please try again." << std::endl;
            }
        }
    }
}
