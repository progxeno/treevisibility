# Tree Visibility Application

This application calculates the orientation angle for a man to maximize the number of visible trees in a 2D map.

## Project Layout

The project follows a Hierarchical Structure.

Hierarchical structure promotes modularity, reusability, and maintainability by separating components, services, utilities, and test files into distinct directories.

```markdown
/treevisibility
├── /docs
│   ├── /adr
│   │   └── ...
├── /example
│   └── input
├── /src
│   ├── /app
│   │   ├── CMakeLists.txt
│   │   └── main.cpp
│   ├── /recources
│   │   └── constant.hpp
│   ├── /utils
│   │   ├── CMakeLists.txt
│   │   ├── test_tree_visibility.cpp
│   │   ├── tree_visibility.cpp
│   │   └── tree_visibility.hpp
│   └── CMakeLists.txt
├── /tools
│   └── ...
├── CMakeLists.txt
├── LICENSE
└── README.md
```

## Prerequisites

- C++ compiler (GCC or Clang)
- CMake

## Clone the Repository

Clone this repository to your local machine using Git:

```bash
git clone <repository_url>
cd treevisibility
```

## Build the Application

### Using CMake

1. Create a build directory:

```bash
mkdir build
cd build
```

2. Generate the build files with CMake:

```bash
cmake ..
```

3. Build the application:

```bash
cmake --build .
```

## Run the Application

After building the application, you can run it with the provided example input file:

```bash
./cmd/bin/tree_visibility-app < example/input
```

You can also manually enter the input through the terminal, following the format specified in the prompt.

The application will calculate the orientation angle that maximizes the number of visible trees and display the result on the terminal.

## Example Input

An example input file (`example/input`) is provided in the repository. You can use this file to test the application:

```
3.5 3.5 50
4
0.0 0.0
1.5 15
-2.15 5
-4 -2
```

## License

This project is licensed under the [MIT License](LICENSE).
