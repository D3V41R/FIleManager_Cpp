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

   std::vector<File> listFiles(const std::string& path) {
        for (const auto& i : std::filesystem::directory_iterator(path)) {
            std::cout << i.path() << std::endl;
        }

    }


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
        auto filePath = std::filesystem::current_path(); // getting path
        std::filesystem::current_path(filePath); // setting path
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

    void get_fileType(std::string filePath) {
        if (std::filesystem::exists(filePath)) {
            if (std::filesystem::is_regular_file(filePath)) {
                fileType = "regular";
                std::cout << fileType << "\n";
            }
            else if (std::filesystem::is_directory(filePath)) {
                fileType = "directory";
                std::cout << fileType << "\n";
            }
        }
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
        return this->dirPath;

    }

    std::vector<File> get_files() {
        return this->files;
    }
    std::vector<Directory> get_subdirectories() {
        return this->subdirectories;
    }

    void displayMetaData() {

    }

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
