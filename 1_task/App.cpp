#include "App.h"

using namespace std;

void App::mainTask() {
    Keeper keeper;
    string filename; 
    int choice;

    while (true) {
        cout << endl;
        cout << "Menu:" << endl;
        cout << "1. Add a ship" << endl;
        cout << "2. Remove a ship" << endl;
        cout << "3. Display all ships" << endl;
        cout << "4. Change parameters" << endl;
        cout << "5. Save to file" << endl;
        cout << "6. Load from file" << endl;
        cout << "7. Compare two ships" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        
        if (!(cin >> choice)) {
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard the invalid input
            cout << "Invalid choice. Please enter a number." << endl;
            continue; // Restart the loop
        }

        switch (choice) {
            case 1: {
                // Add a ship
                int shipType;
                cout << "Enter ship type (1: Submarine, 2: Sailboat, 3: Boat): ";
                if (!(cin >> shipType)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid ship type. Please enter a number." << endl;
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
                cout << "Enter the index of the ship to remove: ";
                if (!(cin >> index)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid index. Please enter a number." << endl;
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
                cout << "Enter the index of the ship to be changed: ";
                if (!(cin >> index)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid index. Please enter a number." << endl;
                    continue; // Restart the loop
                }
                keeper.editShip(index);
                break;
            }
            case 5: {
                // Save to file
                string filename;
                cout << "Enter the filename to save to: ";
                if (!(cin >> filename)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid filename. Please enter a valid filename." << endl;
                    continue; // Restart the loop
                }
                try {
                    keeper.saveToFile(filename);
                    cout << "Saved to " << filename << endl;
                } catch (const runtime_error& e) {
                    cerr << e.what() << endl;
                }
                break;
            }
            case 6: {
                // Load from file
                cout << "Enter the filename to load from: ";
                if (!(cin >> filename)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid filename. Please enter a valid filename." << endl;
                    continue; // Restart the loop
                }
                try {
                    keeper.loadFromFile(filename);
                    cout << "Loaded from " << filename << endl;
                } catch (const runtime_error& e) {
                    cerr << e.what() << endl;
                }
                break;
            }
            case 7: {
                cout << "Enter the indexes of the ships." << endl;
                int index1, index2;
                if (!(cin >> index1)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid index. Please enter a number." << endl;
                    continue; // Restart the loop
                }
                if (!(cin >> index2)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid index. Please enter a number." << endl;
                    continue; // Restart the loop
                }
                keeper.compare(index1, index2);
                break;
            }
            case 8: {
                return;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
            }
        }
    }
}
