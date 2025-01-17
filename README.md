# Qt Project Template for macOS with VSCode Integration

## Overview
This project provides a ready-to-use template for creating Qt applications on macOS, configured to work seamlessly with Visual Studio Code. The template includes:

- A pre-configured `CMakeLists.txt` file for building Qt projects.
- A `c_cpp_properties.json` file for VSCode to enable IntelliSense and smooth development.
- Compatibility with macOS and Qt's development environment.

## Features

- **CMake Integration**: Simplifies the build process with a ready-to-use `CMakeLists.txt` tailored for Qt applications.
- **VSCode Support**: Includes a `c_cpp_properties.json` file pre-configured for macOS, making it easy to use VSCode for editing, building, and debugging.
- **Cross-Platform Potential**: While optimized for macOS, the structure can be adapted to other platforms with minor changes.

## Requirements

- **Qt Framework**: Make sure you have Qt installed. You can download it from the [Qt website](https://www.qt.io/).
- **CMake**: Install the latest version of CMake. [Download CMake](https://cmake.org/download/).
- **Visual Studio Code**: Ensure you have VSCode installed with the following extensions:
  - C/C++ Extension by Microsoft.
  - CMake Tools Extension.
- **Xcode Command Line Tools**: Required for building and compiling on macOS. Install them by running `xcode-select --install` in the terminal.

## File Structure

```
project-template/
├── CMakeLists.txt        # CMake configuration file
├── src/                  # Source files for the project
│   ├── main.cpp          # Example Qt application entry point
│   ├── mainwindow.cpp    # Example main window implementation
│   ├── mainwindow.h      # Header file for main window
│   └── styles.qss        # Example Qt stylesheet
├── include/              # Additional headers (optional)
├── resources/            # Qt resource files (e.g., .qrc)
├── c_cpp_properties.json # VSCode IntelliSense configuration
└── README.md             # Project documentation
```

## Getting Started

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/your-username/qt-vscode-template.git
   cd qt-vscode-template
   ```

2. **Set Up Qt Paths**:
   - Open `c_cpp_properties.json` and update the `includePath` and `defines` to match your Qt installation path.
   - Modify `CMakeLists.txt` if needed to set the correct `Qt6` installation directory.

3. **Open in VSCode**:
   - Open the project folder in Visual Studio Code.
   - Ensure the required extensions (C/C++ and CMake Tools) are installed.

4. **Configure and Build the Project**:
   - Use the CMake Tools extension to configure the project.
   - Select a build kit (e.g., Xcode or Unix Makefiles).
   - Build the project using the build button or by running `cmake --build .` from the terminal.

5. **Run the Application**:
   - After building, run the application directly from VSCode or execute the binary from the `build/` directory.

## Pre-configured CMakeLists.txt

Below is the included `CMakeLists.txt` file:

```cmake
cmake_minimum_required(VERSION 3.16)
project(NameApp)

set(CMAKE_CXX_STANDARD 17)

find_package(Qt6 REQUIRED COMPONENTS Gui Widgets)

set(SOURCES src/main.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets Qt6::Core)

# Copy the styles.qss file to the build directory
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/src/styles.qss
    DESTINATION $<TARGET_FILE_DIR:${PROJECT_NAME}>
)
```

## Customization

- **CMakeLists.txt**:
  Adjust the CMake configuration to include additional libraries, define macros, or set specific build options.

- **c_cpp_properties.json**:
  Modify the IntelliSense configuration for additional include paths or compiler settings.

## Contributing

Feel free to fork this repository and submit pull requests for improvements or additional features. Contributions are welcome!

## License

This project is licensed under the MIT License. See the `LICENSE` file for details.

## Acknowledgments

- [Qt Documentation](https://doc.qt.io/)
- [CMake Documentation](https://cmake.org/documentation/)
- [VSCode C++ Extension](https://code.visualstudio.com/docs/cpp/cpp-ide)
