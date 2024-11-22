

#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "File.h"



class FileManager {
private:
    std::string currentPath;

public:
    void createFile(const std::string &fileName) {
        std::fstream file (fileName);

        if (file.is_open()) {
            std::cout << "successfully opened file"  << "\n";
        }

        file.close();

    }

    void createDirectory(const std::string& dirName) {
        std::filesystem::create_directory(dirName);
    }


    void readFile(const std::string &fileName) {
        std::string contents;

        std::ifstream file (fileName);
        do {
            std::cout << contents;

        }while (std::getline(file, contents));
        file.close();

    }

    void updateFile(const std::string &fileName, std::string content) {

        std::ofstream file;
        file.open(fileName);

        file << content;

        file.close();

    }

    void deleteFile(const std::string &fileName) {
        std::filesystem::remove(fileName);

    }

    void deleteDirectory() {
        std::filesystem::remove_all(currentPath);
    }

    std::vector<File>listFiles(const std::string& path) {
        for (const auto& i : std::filesystem::directory_iterator(path)) {
            std::cout << i.path() << std::endl;
        }

    }


};


#endif //FILEMANAGER_H
