//
// Created by Zahir on 11/21/2024.
//

#ifndef DIRECTORY_H
#define DIRECTORY_H

#include "File.h"
#include<fstream>
#include<filesystem>


class Directory {
private:
    std::string dirName;
    std::string dirPath;
    std::vector<File> files;
    std::vector<Directory> subdirectories;

public:

    void set_dirName(std::string dirName) {
        this->dirName = dirName;
    }
    void set_dirPath(std::string dirPath) {
        this->dirPath = dirPath;
    }
    void set_files(std::vector<File> files) {
        this->files = files;
    }
    void set_subdirectories(std::vector<Directory> subdirectories) {
        this-> subdirectories = subdirectories;
    }

    std::string get_dirName() {
        return this->dirName;
    }
    std::string get_dirPath() {

        return dirPath;
    }

    std::vector<File> get_files() {

        return this->files;
    }


    std::vector<Directory> get_subdirectories() {
        return this->subdirectories;
    }

    void displayMetaData() {
        std::cout << "Directory Name: " << dirName << "\n";
        std::cout << "Directory Path: " << dirPath << "\n";
        std::cout << "Number of Files: " << files.size() << "\n";
        std::cout << "Number of Subdirectories: " << subdirectories.size() << "\n";

    }

    void listContents() {

        std::cout << "Contents of " << dirName << ":\n";

        std::cout << "Files:\n";
        for (auto& file : files) {
            std::cout << "  - " << file.get_fileName() << "\n"; // Assuming File has a method `getFileName()`
        }

        std::cout << "Subdirectories:\n";
        for ( auto& subdir : subdirectories) {
            std::cout << "  - " << subdir.get_dirName() << "\n";
        }


    }

    Directory* navigateToSubdirectory(const std::string& subDirName) {
        for (auto& subdir : subdirectories) {
            if (subdir.get_dirName() == subDirName) {
                return &subdir;
            }
        }
        std::cout << "Subdirectory '" << subDirName << "' not found.\n";
        return nullptr;

    }

};

#endif //DIRECTORY_H
