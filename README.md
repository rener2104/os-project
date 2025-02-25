# Operating System Project
CSCE 4326-201 
Rene Reyna & Andy De Luna

This program is a simulation of an operating system using C++.

## Build Instructions

1. Clone the repository:
   ```bash
   $ git clone https://{repo}
   ```

2. Change to the project directory:
   ```bash
   $ cd {my-repo}
   ```

3. Create and enter the build directory:
   ```bash
   $ mkdir build && cd build
   ```

4. Configure the project with CMake:
   ```bash
   $ cmake ..  # Make sure CMake is installed
   ```

5. Build the project:
   ```bash
   $ cmake --build .
   ```

6. Run the executable:
   ```bash
   $ ./your_executable_name
   ```
   
## Documentation
0. Incase doxygen isn't installed
   ```bash
   $ brew install doxygen
   ```

1. To generate the documentation, ensure you have Doxygen installed and run:
   ```bash
   $ doxygen Doxyfile # Generated documentation will be in docs/
   ```

2. Open documentation:
   ```bash
   $ open docs/html/index.html # macOS
   ```

   ```bash
   $ start docs/html/index.html # Windows
   ```
