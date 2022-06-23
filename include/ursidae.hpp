#ifndef URSIDAE_HPP
#define URSIDAE_HPP
#endif

#include <vector>
#include <string>
#include <unordered_map>


namespace Ursidae
{
    class DataTable
    {
    private:	

        std::vector<std::string> column;               //column names.
        std::vector<std::string> index;                //default defined as 1-n, can be assigned to column. 

        std::vector<std::vector<std::string>> data;    //raw data.


    public:
        //constructors
        DataTable();
        DataTable(std::string filepath);                  //initialize with a csv file.
        DataTable(std::string data, bool isData);         //initialize with a string of comma separated values

        //template<typename key, typename value>
        //DataTable(std::unordered_map<key, value> data);  
        //or  stick with
        DataTable(std::unordered_map<std::string, std::vector<std::string>>);

        DataTable(std::vector<std::vector<std::string>> data); 
        DataTable(std::vector<std::vector<std::string>> data, std::vector<std::string> specs); //An Enum can work for the specs

        //member functions
        void read_csv(std::string filepath, std::string encoding);
        void to_csv(std::string filepath);

        //more functionality



    };


    std::vector<std::vector<std::string>> read_csv(std::string filepath, std::string encoding); //example of overloaded function
	void to_csv(std::string filepath);






}
