#include <iostream> 
#include "ursidae.hpp"
#include <filesystem>

namespace fs = std::filesystem;

/**
* @brief variadic Constructor that auto assigns index
*
* @todo implement function
*/

template <typename Datatype1, typename... Datatype>
Ursidae::DataTable::DataTable(const std::vector<std::string_view>& column,
              const std::vector<Datatype1>& col1, const std::vector<Datatype>&... cols): column(column), index(col1.size())  {
    
    
}

/**
* @brief  Constructor that takes in csv file path as input
*
* @todo implement function, add exceptions
*/

Ursidae::DataTable::DataTable(std::string& filepath) {

    std::ifstream inputFile(filepath);

    if(!fs::is_regular_file(fs::path(filepath)) || fs::path(filepath).extension() != ".csv" || !inputFile.is_open()) {
        std::cerr << "invalid file \n";     // ToDo change to exceptions
    }
    
}