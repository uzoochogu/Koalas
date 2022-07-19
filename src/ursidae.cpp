#include <iostream> 
#include "ursidae.hpp"


template <typename DataType>
Ursidae::DataTable<DataType>::DataTable(std::vector<DataColumn<DataType>> &input)  
{
    /**
     * @brief Creates a DataTable from a vector of DataColumns
     * 
     */
    for(auto& dataColumn : input) 
    {
        column.push_back(dataColumn.col_name);
    }
}