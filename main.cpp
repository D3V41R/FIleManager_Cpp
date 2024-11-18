#include <iostream>
#include<vector>
#include<fstream>
#include<filesystem>


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

    }

   std::vector<File> listFiles(const std::string& path) {}


};

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
        this-> fileSize = fileSize;
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

    void displayMetaData() {

    }

    std::string previewContent() const {

    }


};


class Directory {
private:
    std::string dirName;
    std::string dirPath;
    std::vector<File> files;
    std::vector<Directory> subdirectories;

public:

    void listContents() const {

    }

    Directory* navigateToSubdirectory(const std::string& subDirName) {

    }

};

class searchEngine {
private:
    std::string searchCriteria;

public:
    std::vector<File> searchByName(const std::string& keyword, const Directory& dir) {

    }

    std::vector<File> searchByType(const std::string& fileType, const Directory& dir) {

    }

    std::vector<File> searchByDateRange(const std::string& startDate, const std::string& endDate, const Directory& dir) {

    }


};


class SortEngine {
private:
    std::string sortCriteria;


public:
    std::vector<File> sortByName(std::vector<File>& files, bool ascending = true) {

    }

    std::vector<File> sortBySize(std::vector<File>& files, bool ascending = true){

    }

    std::vector<File> sortByDate(std::vector<File>& files, bool ascending = true) {

    }



};


class UserInterface {

private:
    FileManager fileManager;


public:
    void displayMainMenu(){};
    void handleUserInput(){};
    void showFileMetadata(const File& file){};
    void showSearchResults(const std::vector<File>& results){};
};



int main() {



    return 0;
}
