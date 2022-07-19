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


## Integration
*This Library can be built and used as either a shared library or a static library (you get to choose !)*

For non-CMake projects, [git submodule](https://git-scm.com/book/en/v2/Git-Tools-Submodules) can be your goto. Simply add the project as submodule and <a href="#building-the-library">follow instructions</a> to build either a shared or static library and link it to your project. A simple example can be [found here](https://github.com/uzoochogu/Ursidae/tree/examples).

## CMake
You can also embed Ursidae into an existing cmake project in two(2) ways:

1. Using [Fetchcontent](https://cmake.org/cmake/help/latest/module/FetchContent.html), cmake's way of managing dependencies. This project is completely compatible with CMake FetchContent, and we recommend users to utilize this method to incorporate the library into their projects. An example of how this is done can be found [in this branch](https://github.com/uzoochogu/Ursidae/tree/examples).

2. The project can be cloned to a subdirectory of your project via [git submodule](https://git-scm.com/book/en/v2/Git-Tools-Submodules) or manually and called from the `add_subdirectory` in your `CMakeLists.txt` file. You can also see an example [of this here](https://github.com/uzoochogu/Ursidae/tree/examples).
 

### Requirements
- Cmake 3.10+
- C++ Compiler that support C++17 and above

## Building the Library

```cmd
mkdir build
cd build
```

### For static library
```cmd
cmake ..
```
```cmd
cmake --build .
```

### For shared library 
```cmd
cmake -D BUILD_SHARED_LIB=ON ..
```
```cmd
cmake --build .
```
For users with Microsoft Visual Studio , this automatically creates a solution file `Ursidae.sln` in the build directory.

### Build Documentation (Optional)
To build documentation, install:
1. [Doxygen](https://www.doxygen.nl/download.html), 
2. [Sphinx](https://www.sphinx-doc.org/en/master/usage/installation.html) 
3. [Breathe](https://breathe.readthedocs.io/en/latest/)
4.  [sphinx_rtd_theme](https://github.com/rtfd/sphinx_rtd_theme) or any other supported [sphinx themes](https://sphinx-themes.org/) like [groundwork](https://sphinx-themes.org/sample-sites/groundwork-sphinx-theme/).
Then set `BUILD_DOCUMENTATION=ON` when building the library just like below: 

(Depending on the type of library being built) 

```cmd
cmake -D BUILD_DOCUMENTATION=ON ..
```
or

```cmd
cmake -D BUILD_DOCUMENTATION=ON -D BUILD_SHARED_LIB=ON ..
```
## Getting Started
This library supports both object oriented programming paradigm and functional paradigm. For larger projects, the Object oriented usage will allow for better organization, efficiency and memory management. You might consider the Functional usage for quick protyping and smaller projects.
<p>In an Object oriented approach, DataTables and DataColumns are used.</p>

### DataColumn
DataColumns are column vectors of data. For example:

<p align="left">
	<table>
		<tr>
			<th>Name</th>
		</tr>
		<tr>
			<td>Akpos John</td>
		</tr>
		<tr>
			<td>Eze Kelechi</td>
		</tr>
	</table>
</p>


They help to optimize data storage. They are basically a wrapper around
1. A string containing the name of the DataColumn.
2. A vector of the stored data. (Can be string or Numeric type).

### Creating a DataColumn
1. **Passing a Name and a vector of the data**
To create the DataColumn above:
```cpp
DataColumn names{"Name", {"Akpos John","Eze Kelechi"}};
```

### Creating a DataTable
There are multiple ways to create a DataTable. 
1. **Initialize with a 2D vector (vector of vector) of strings**
```cpp
std::vector<std::vector<strings>> data = {{"Name",       "Sex",           "Age","Weight(Kg)"},
					  {"Akpos John", "Male",          "27", "70"  },
					  {"Eze Kelechi","Not Disclosing","23", "60"}};
DataTable ursa(data);
```
This creates a Table like:
| |Name 	    | Sex            | Age | Weight(Kg) |
|-| ---------   | -------        | --- | ----       |
|0|Akpos John   | Male           | 27  | 70         |
|1|Eze Kelechi  | Not Disclosing | 23  | 60         |

2. **Initialize with a csv file**      
```cpp
DataTable ursa(std::string filepath, true);              
```

3. **Specify the datatype of the data**: All the above methods of initializing support this.
```cpp       
std::vector<std::vector<strings>> data = {{"Name",       "Sex",           "Age","Weight(Kg)"},
					  {"Akpos John", "Male",          "27", "70"  },
					  {"Eze Kelechi","Not Disclosing","23", "60"  }};
DataTable ursa(data, {"std::string", "std::string", "std::string", "unsigned int", "double" });
```
4. **Composing with DataColumns**
```cpp
//DataColumns
DataColumn names{"Name", {"Akpos John","Eze Kelechi"}};
DataColumn names{"Sex", {"Male","Not Disclosing"}};
DataColumn names{"Age", {"27","23"}};
DataColumn names{"Weight(Kg)", {"70","60"}};

//DataTable
DataTable ursa({Name,Sex, Age, Weight});
```

5. Maps - Experimental.


## Reading from a CSV File
 
### OOP Approach 

```cpp
DataTable ursa;
ursa.read_csv("test.csv", "utf8");  //Stores it in memory more efficiently.
```
 
### Functional Approach 

```cpp
std::vector<std::vector<std::string>> ursa = Ursidae::read_csv("test.csv", "utf8")     //if you want to manipulate it yourself but less efficient.
```

## Streaming  from file / Random Access 
You can query specific cells within the csv file.
```cpp
int age = std::static_cast <int>(ursa.at(-1,2));          //returns string, converted to 23
//or
int age = std::static_cast <int>(ursa[-1][2]);            //same implementation as at()
```

### Using functional approach
```cpp
int age = std::static_cast <int>( Ursidae::read_csv("test.csv", "utf8")[-1][2]);     //23
```


## Write to File
Writes to a csv file, you can create, overwrite or append.
```cpp
ursa.to_csv("test.csv");	       //overwrites or creates file
Ursidae::to_csv("test.csv", data);     //functional approach
```

## Editing Cells
```cpp
ursa.put("Akpos", 1, 2);      //Overwrites row 1, column 2 cell with data; 
//or
ursa[1][2] = "Akpos";         //Random Access and Write
```

## Note
More functionality is being added.




