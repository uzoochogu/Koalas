![Windows](https://github.com/uzoochogu/Ursidae/actions/workflows/windows.yml/badge.svg)
![Ubuntu](https://github.com/uzoochogu/Ursidae/actions/workflows/ubuntu.yml/badge.svg)
![macOS](https://github.com/uzoochogu/Ursidae/actions/workflows/macos.yml/badge.svg)
![GitHub](https://img.shields.io/github/license/uzoochogu/Ursidae)
![GitHub top language](https://img.shields.io/github/languages/top/uzoochogu/Ursidae)
# Ursidae 
A shared library for parsing Comma Separated Value (CSV) files.

## Features

| Item                               | Description                                                                                                            |
| -----------                        | -----------                                                                                                            |
| Read from file to memory           | Creates a copy of the file in memory for fast operations. This should be limited to small CSVs or may not be considered|
| Stream from file / Random Access   | Can query specific cells within the csv file                                                                           |
|Edit CSV                            | Edit particular cells (still part of Random Access)                                                                    |
|Write to file                       |Writes to a csv file. Create, overwrite or append.                                                                      |
|Print CSV                           |Displays contents in the command line                                                                                   |


## Installation
This Library can be built and used as either a shared library or a static library.
### Requirements
- Cmake 3.10+
- C++ Compiler that support C++17 and above

### Building

```cmd
git clone https://github.com/uzoochogu/Ursidae.git
mkdir build
cd build
```

**(Shared)** For Static library
```powershell
cmake ..
cmake --build .
```
**(Static)** For Shared library 
```powershell
cmake -D BUILD_SHARED_LIBS=ON ..
cmake --build .
```

## Simple User Tutorial
This library supports both object oriented programming paradigm and functional paradigm. For larger projects, the Object oriented usage will allow for better organization, efficiency and memory management. You might consider the Functional usage for quick protyping and smaller projects.
<p>In an Object oriented approach, DataTables are used.</p>

### Creating a DataTable:
There are multiple ways to create a DataTable. 
1. **Passing a list of Comma Separated values**
```c++
DataTable ursa{"Name,Sex,Age,Weight(kg)","Akpos John,Male,27,70", "Eze Kelechi,Not Disclosing,23,60"};
```
This creates a Table like:
| |Name 	| Sex            | Age | Weight(Kg) |
|-| ---------   | -------        | --- | ----       |
|0|Akpos John   | Male           | 27  | 70         |
|1|Eze Kelechi  | Not Disclosing | 23  | 60         |

2. **Initialize with a csv file**      
```c++
DataTable ursa(std::string filepath, true);              
```
3. **Initialize with a vector of vector of strings**
```c++
std::vector<std::vector<strings>> data = {{"Name",       "Sex",           "Age","Weight(Kg)"},
					  {"Akpos John", "Male",          "27", "70"  },
					  {"Eze Kelechi","Not Disclosing","23", "60"  
DataTable ursa(data);
```

        
4. **Specify the datatype of the data**: All methods of initializing support this.
```c++        
std::vector<std::vector<strings>> data = {{"Name",       "Sex",           "Age","Weight(Kg)"},
					  {"Akpos John", "Male",          "27", "70"  },
					  {"Eze Kelechi","Not Disclosing","23", "60"  }};
DataTable ursa(data, {"std::string", "std::string", "std::string", "unsigned int", "double" });
```
5. Maps - Experimental


### Reading from a CSV File
#### OOP Approach
```c++
DataTable ursa;
ursa.read_csv("test.csv", "utf8");  //Stores it in memory more efficiently.
```

#### Functional Approach
```c++
std::vector<std::vector<std::string>> ursa = Ursidae::read_csv("test.csv", "utf8")     //if you want to manipulate it yourself but less efficient.
```

### Streaming  from file / Random Access 
You can query specific cells within the csv file.
```c++
int age = std::static_cast <int>(ursa.at(-1,2));          //returns string, converted to 23
//or
int age = std::static_cast <int>(ursa[-1][2]);            //same implementation as at()
```

#### Using functional approach
```c++
int age = std::static_cast <int>( Ursidae::read_csv("test.csv", "utf8")[-1][2]);     //23
```


### Write to File
Writes to a csv file, you can create, overwrite or append.
```c++
ursa.to_csv("test.csv");	       //overwrites or creates file
Ursidae::to_csv("test.csv", data);     //functional approach
```

### Editing Cells
```c++
ursa.put("Akpos", 1, 2);      //Overwrites row 1, column 2 cell with data; 
//or
ursa[1][2] = "Akpos";         //Random Access and Write
```



## Notes
1. More functionality is being added.
2. A proper documentation would be published later when there are more features.



