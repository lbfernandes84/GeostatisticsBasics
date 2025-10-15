
## Project Structure

- `DllWrapper/` - C++ DLL wrappers for geostatistical algorithms
- `PythonProject/` - Python bindings and usage examples
- `GeostatisticsBasicsLib/` - Core C++ library
- `GeostatisticsBasicsLib.Tests/` - Unit tests for C++ components

## Contributing

Contributions are welcome! Please submit issues or pull requests via GitHub.

## License

This project is licensed under the MIT License.

## Authors

- [lbfernandes84](https://github.com/lbfernandes84)

# GeostatisticsBasics

GeostatisticsBasics is a cross-language geostatistics library providing core algorithms in C++14 with Python bindings. The project focuses on Ordinary Kriging estimation and variogram modeling, exposing high-performance C++ code via a DLL and Python wrappers.

## Features

- **Ordinary Kriging Estimation**: Estimate spatial values, variances, and Lagrange multipliers using sample data and variograms.
- **Variogram Models**: Spherical and Exponential variogram creation and computation.
- **C++14 Core**: Efficient geostatistical algorithms implemented in modern C++.
- **Python Bindings**: Simple Python API using `ctypes` to interact with the C++ DLL.
- **Extensible Entities**: Points, sample sets, and sample values managed from Python.

## Installation

### Prerequisites

- C++14 compatible compiler (for building native code)
- Python 3.7+ (for Python bindings)
- Visual Studio 2022 (recommended for development)
- CMake (for building C++ components)

### Building the C++ Library

1. Clone the repository:
2. Open the solution in Visual Studio 2022.
3. Build the solution to generate the DLLs in the `dlls/` directory.

### Python Usage

1. Ensure the built DLL (`DllWrapper.dll`) is present in the `dlls/` directory.
2. Install required Python packages (if any, see `requirements.txt`).
3. Use the Python wrappers in your scripts.

## Usage Example


## Project Structure

- `DllWrapper/` - C++ DLL wrappers for geostatistical algorithms
- `PythonProject/` - Python bindings and usage examples
- `GeostatisticsBasicsLib/` - Core C++ library
- `GeostatisticsBasicsLib.Tests/` - Unit tests for C++ components

## Contributing

Contributions are welcome! Please submit issues or pull requests via GitHub.

## License

This project is licensed under the MIT License.

## Authors

- [lbfernandes84](https://github.com/lbfernandes84)