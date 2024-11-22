//
// Created by Zahir on 11/21/2024.
//

#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include "File.h"
#include "Directory.h"
#include "FileManager.h"



class UserInterface {

private:
    FileManager fileManager;


public:
    void displayMainMenu() {
        std::cout << "=== File Manager ===\n";
        std::cout << "1. Create File\n";
        std::cout << "2. Read File\n";
        std::cout << "3. Update File\n";
        std::cout << "4. Delete File\n";
        std::cout << "5. Create Directory\n";
        std::cout << "6. Delete Directory\n";
        std::cout << "7. List Files in Directory\n";
        std::cout << "8. Search Files\n";
        std::cout << "9. Exit\n";
        std::cout << "Please select an option: ";
    };
    void handleUserInput() {
         int choice;
    std::cin >> choice;  // Get user input

    switch (choice) {
        case 1: {
            // Create a new file
            std::string fileName;
            std::cout << "Enter the file name to create: ";
            std::cin >> fileName;
            fileManager.createFile(fileName);
            break;
        }
        case 2: {
            // Read a file
            std::string fileName;
            std::cout << "Enter the file name to read: ";
            std::cin >> fileName;
            fileManager.readFile(fileName);
            break;
        }
        case 3: {
            // Update a file
            std::string fileName, content;
            std::cout << "Enter the file name to update: ";
            std::cin >> fileName;
            std::cout << "Enter content to add: ";
            std::cin.ignore();  // To clear the input buffer
            std::getline(std::cin, content);
            fileManager.updateFile(fileName, content);
            break;
        }
        case 4: {
            // Delete a file
            std::string fileName;
            std::cout << "Enter the file name to delete: ";
            std::cin >> fileName;
            fileManager.deleteFile(fileName);
            break;
        }
        case 5: {
            // Create a directory
            std::string dirName;
            std::cout << "Enter the directory name to create: ";
            std::cin >> dirName;
            fileManager.createDirectory(dirName);
            break;
        }
        case 6: {
            // Delete a directory
            std::string dirName;
            std::cout << "Enter the directory name to delete: ";
            std::cin >> dirName;
            fileManager.deleteDirectory();
            break;
        }
        case 7: {
            // List files in the current directory
            std::string path;
            std::cout << "Enter the directory path: ";
            std::cin >> path;
            fileManager.listFiles(path);
            break;
        }
        case 8: {
            // Search files
            std::string keyword;
            std::cout << "Enter a keyword to search for: ";
            std::cin >> keyword;
            // Assuming a `SearchEngine` is available to handle this
            //SearchEngine searchEngine;
            Directory currentDir;
           // std::vector<File> results = searchEngine.searchByName(keyword, currentDir);
            //showSearchResults(results);  // Display search results
            break;
        }
        case 9:
            std::cout << "Exiting... Goodbye!\n";
            break;
        default:
            std::cout << "Invalid option. Please try again.\n";
            break;
    }

    };
    void showFileMetadata( File& file) {
        std::cout << "=== File Metadata ===\n";
        std::cout << "File Name: " << file.get_fileName() << "\n";
        //std::cout << "File Size: " << file.get_fileSize() << " bytes\n";
        //std::cout << "Creation Date: " << file.get_creationDate() << "\n";
        //std::cout << "Modification Date: " << file.get_modificationDate() << "\n";
        std::cout << "File Type: " << file.get_fileType(file.get_fileName()) << "\n";

    };
    void showSearchResults( std::vector<File>& results) {
        if (results.empty()) {
            std::cout << "No files found matching the search criteria.\n";
        } else {
            std::cout << "=== Search Results ===\n";
            for (auto& file : results) {
                std::cout << "File Name: " << file.get_fileName() << "\n";
                // Optionally, display more metadata if needed:
                showFileMetadata(file);
            }
        }

    };
};


#endif //USERINTERFACE_H
