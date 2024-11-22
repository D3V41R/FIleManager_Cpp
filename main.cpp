#include <iostream>
#include<vector>
#include<fstream>
#include<filesystem>


#include "UserInterface.h"


int main() {


    UserInterface ui;
    bool running = true;

    while (running) {
        ui.displayMainMenu();
        ui.handleUserInput();
        std::cout << "\n";
    }

    return 0;
}
