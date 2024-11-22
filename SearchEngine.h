//
// Created by Zahir on 11/21/2024.
//

#ifndef SEARCHENGINE_H
#define SEARCHENGINE_H

#include"File.h"
#include"Directory.h"


class searchEngine {
private:
    std::string searchCriteria;

public:
    std::vector<File> searchByName(const std::string& keyword,  Directory& dir) {
        std::vector<File> result;
        for( auto file : dir.get_files()) {
            if (file.get_fileName().find(keyword) != std::string::npos) {
                result.push_back(file); // Add matching file to the result
            }
        }
        return result;

    }
    std::vector<File> searchByType(const std::string& fileType, Directory& dir) {

        std::vector<File> result;

        for( auto& file : dir) {
            if (file.get_fileType() == fileType ){
                result.push_back(file);
            }
        }
        return result;

    }

    std::vector<File> searchByDateRange(const std::string& startDate, const std::string& endDate, const Directory& dir) {


    }


};


#endif //SEARCHENGINE_H
