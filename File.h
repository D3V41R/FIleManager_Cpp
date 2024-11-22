//
// Created by Zahir on 11/21/2024.
//

#ifndef FILE_H
#define FILE_H

#include<vector>
#include<filesystem>
#include <iostream>


class File {
private:
    std::string fileName;
    std::string filePath;
    std::size_t fileSize;
    std::string creationDate;
    std::string modificationDate;
    std::string fileType;

public:

    void set_filename(std::string fileName) {
        this-> fileName = fileName;

    }

    void set_path(std::string filePath) {
        this->filePath = filePath;

    }

    void set_filesize(std::size_t fileSize) {
        this->fileSize = fileSize;
    }


    void set_creationDate( std::string creationDate) {
        this->creationDate = creationDate;
    }

    void set_modificationDate(std::string modificationDate) {
        this -> modificationDate = modificationDate;
    }

    void set_fileType (std::string fileType) {
        this->fileType = fileType;
    }

    std::string get_fileName() {
        return fileName;
    }

    std::string get_fileType(std::string filePath) {
        if (std::filesystem::exists(filePath)) {
            if (std::filesystem::is_regular_file(filePath)) {
                fileType = "regular";
                std::cout << fileType << "\n";
                return fileType;

            }
            else if (std::filesystem::is_directory(filePath)) {
                fileType = "directory";
                std::cout << fileType << "\n";
                return fileType;
            }
        }
    }

    void displayMetaData() {

        std::cout << "File Name: " << fileName << "\n";
        std::cout << "File Path: " << filePath << "\n";
        std::cout << "File Size: " << fileSize << " bytes\n";
        std::cout << "Creation Date: " << creationDate << "\n";
        std::cout << "Modification Date: " << modificationDate << "\n";
        std::cout << "File Type: " << fileType << "\n";

    }

    std::string previewContent() const {

        std::ifstream file(filePath);
        if (!file.is_open()) {
            return "Unable to open file.";
        }

        std::string preview;
        std::string line;
        int lineCount = 0;

        while (std::getline(file, line) && lineCount < 10) { // Limit preview to 10 lines
            preview += line + "\n";
            lineCount++;
        }

        return preview.empty() ? "File is empty." : preview;

    }


};


#endif //FILE_H
