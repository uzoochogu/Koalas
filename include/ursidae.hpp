#ifndef URSIDAE_HPP
#define URSIDAE_HPP


#include <vector>
#include <string>
#include <unordered_map>

/**
  Ursidae namespace contains functions and classes used in the library
*/
namespace Ursidae
{
    /**
     * @brief DataColumns are column vectors containing a std::string name and a vector of some data
     * 
     * 
     */
    template<typename DataType>
    class DataColumn
    {

    public:
        //constructors
        DataColumn() {};
        DataColumn(std::string name, std::vector<DataType> elements) : col_name(name), col_data(elements){};  
        
        
        

    private:

        std::string col_name;
        std::vector<DataType> col_data;      
    };




    /**
     * @brief DataTables is a table of data. Each DataTable is implemented as a collection of DataColumns 
     * 
     */
    template<typename DataType>
    class DataTable
    {
    
    public:
        //constructors
        DataTable();
        ~DataTable();
        
        
        DataTable(const DataTable &dt);                 //copy constructor
        DataTable(DataTable&& source);                  //move constructor



        DataTable(std::vector<std::string> data);                                             //initialize with a string of comma separated values
        DataTable(std::vector<std::string> data, std::vector<std::string> specs= {0});        //Define datatype specifications
        DataTable(std::string filepath, bool isFile = false);                    	      //initialize with a csv file.
        DataTable(std::string filepath, bool isFile = false, std::vector<std::string> specs= {0});  


        DataTable(std::vector<DataColumn<DataType>> &input);
          

        //template<typename key, typename value>
        //DataTable(std::unordered_map<key, value> data);  
        //or  stick with
        DataTable(std::unordered_map<std::string, std::vector<std::string>>);

        DataTable(std::vector<std::vector<std::string>> data); 
        DataTable(std::vector<std::vector<std::string>> data, std::vector<std::string> specs = {0});      //An Enum can work for the specs


        //Operators
        DataTable operator=(DataTable dt);
        std::string& operator[](int index);




        //member functions
        void read_csv(std::string filepath, std::string encoding="utf8");
        void to_csv(std::string filepath);

        //more functionality here



    private:	

        std::vector<std::string> column;               //column names.
        std::vector<std::string> index;                //default defined as 1-n, can be assigned to column. 

        //std::vector<std::vector<std::string>> data;    //raw data.

        std::vector<DataColumn<DataType>> data;

    };


    std::vector<std::vector<std::string>> read_csv(std::string filepath, std::string encoding="utf8"); //example of overloaded function
    void to_csv(std::string filepath, std::vector<std::vector<std::string>>);


    //more functionality here





}
#endif