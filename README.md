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

### Using Makefile

To display the available options:

```bash
make help
```

1. Build the application:

```bash
make app-build
```

2. Run the application:

```bash
mkdir app-run
cd build
```

3. Run applicatio with example input file:

```bash
make app-example
```

4. Build application with tests:

```bash
make all-build
```

5. Run tests:

```bash
make test-run
```

## License

This project is licensed under the [MIT License](LICENSE).
