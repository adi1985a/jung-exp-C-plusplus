# ⚛️🔬 QuantumSlit Voyager: Young's Double-Slit Experiment Simulator ✨
_A C++ console application demonstrating the wave-particle duality of quantum mechanics through a simulation of Young's double-slit experiment._

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![C++](https://img.shields.io/badge/Language-C%2B%2B%2011%2B-blue.svg)](https://isocpp.org/)
[![Platform: Windows](https://img.shields.io/badge/Platform-Windows-lightgrey.svg)](https://www.microsoft.com/windows)

## 📋 Table of Contents
1.  [Overview](#-overview)
2.  [Key Features & Experiment Modes](#-key-features--experiment-modes)
3.  [Screenshots](#-screenshots)
4.  [System Requirements](#-system-requirements)
5.  [Core Configuration (`config.h`)](#-core-configuration-configh)
6.  [Installation and Setup](#️-installation-and-setup)
7.  [Usage Guide](#️-usage-guide)
8.  [File Structure](#-file-structure)
9.  [Technical Notes](#-technical-notes)
10. [Contributing](#-contributing)
11. [License](#-license)
12. [Contact](#-contact)

## 📄 Overview

**QuantumSlit Voyager**, authored by Adrian Lesniak, is a captivating C++ console application designed to simulate and illustrate the foundational principles of quantum mechanics as demonstrated by Young's double-slit experiment. The program vividly models the contrasting behaviors of "electrons":
*   **With an Observer**: Demonstrates particle-like behavior, where electrons are observed passing through one of the two slits.
*   **Without an Observer**: Simulates wave-like behavior, leading to an interference pattern as electrons appear to pass through both slits simultaneously or interact with the wall.
The simulation uses random number generation for electron paths, calculates a simplified interference pattern, and features a colorful Windows-specific console interface. Configurations like sample size and program title are managed through a user-provided `config.h` file.

## ✨ Key Features & Experiment Modes

*   🔬 **Dual Experiment Modes**:
    *   **With Observer**: Simulates electrons behaving as distinct particles. The output shows which of the two slits each "electron" hits, an average hit position, and a simple ASCII visualization of slit impacts.
    *   **Without Observer**: Simulates electrons exhibiting wave-like properties. Tracks whether electrons "hit" the wall, one slit, or appear to interact with both, ultimately forming an interference pattern on a virtual "blackboard."
*   🎲 **Probabilistic Simulation**:
    *   `RandomNumber` generation (seeded for variability) determines the path and outcome for each simulated electron shot.
    *   `calculateInterference`: A function to compute a simplified interference pattern (e.g., using a cosine-squared function) when wave-like behavior is modeled.
    *   `SAMPLE_SIZE` (from `config.h`): Defines the number of "electron shots" per experiment run.
*   🖥️ **Interactive Console Interface**:
    *   `displayHeader`: Shows the program title, author, and a brief description of the experiment.
    *   `displayMenu`: Clearly lists options to run the experiment with an observer, without an observer, or to exit.
    *   **Colorful Output**: Employs Windows console API for distinct colors (cyan, magenta, yellow, white) to enhance the visual presentation of results and UI elements.
*   📊 **Detailed Output & Visualization**:
    *   **Observer Mode**: Lists individual slit hits (1 or 2), calculates an average hit value, and provides a simple ASCII art representation of the distribution.
    *   **No Observer Mode**: Categorizes electron destinations (wall, right slit, both slits, left slit), calculates an average, interprets the most common outcome, and displays an ASCII representation of the interference pattern on a virtual blackboard (1-7 hit zones).
*   🔊 **Auditory Feedback**: A `Beep()` (Windows-specific) signals the completion of each experiment run.
*   🛠️ **Utility Functions**:
    *   `runExperiment`: Core function that orchestrates the simulation based on the presence or absence of an "observer."
    *   `logError`: (Defined but noted as not fully implemented) Intended for logging errors to a file.

## 🖼️ Screenshots

**Coming soon!**

_This section will be updated with screenshots showcasing the main menu, the output for the "With Observer" mode (slit hits, ASCII viz), the output for the "Without Observer" mode (interference pattern, blackboard viz), and other relevant UI elements._

## ⚙️ System Requirements

*   **Operating System**: Windows (due to dependencies like `<windows.h>` for `SetConsoleTextAttribute`, `<conio.h>` for `_getch`, and the `Beep` function).
*   **C++ Compiler**: A C++ compiler supporting C++11 or later (e.g., g++, MSVC).
*   **Standard C++ Libraries**: `<iostream>`, `<ctime>`, `<time.h>`, `<stdio.h>`, `<cstdlib>`, `<cmath>`, `<iomanip>`, `<fstream>`.
*   📄 **`config.h` Header File (User-Provided)**: This project **critically requires** a header file named `config.h`. **This file is not included in the repository and must be created by the user.** It must define essential configuration constants. See "Core Configuration (`config.h`)" and "Installation and Setup" for details.
*   **Write Permissions**: If `logError` is fully implemented, write permissions will be needed for the log file in the execution directory.

## ⚙️ Core Configuration (`config.h`)

The `config.h` file is essential for customizing the simulation and must be provided by the user. It should define at least:

*   `PROGRAM_TITLE` (e.g., `"Young's Double-Slit Experiment Simulator v1.0"`)
*   `SAMPLE_SIZE` (e.g., `1000` or `10000` for the number of electron shots)
*   `ConsoleColors` enum or equivalent constants (e.g., `ConsoleColors::ERROR_COLOR`, `ConsoleColors::INFO_CYAN`) used for `SetConsoleTextAttribute`.

**Example structure for `config.h`:**
```cpp
#ifndef CONFIG_H
#define CONFIG_H

#include <string> // For PROGRAM_TITLE if it's a std::string

// Program Configuration
const std::string PROGRAM_TITLE = "QuantumSlit Voyager: Young's Experiment";
const int SAMPLE_SIZE = 10000; // Number of electrons to simulate

// Console Color Definitions (Windows-specific values for SetConsoleTextAttribute)
namespace ConsoleColors {
    const int DEFAULT = 7;
    const int CYAN = 11;
    const int MAGENTA = 13;
    const int YELLOW = 14;
    const int WHITE = 15;
    const int RED_ERROR = 12; // Example for errors
    // Add other colors as used by the program
}

// Potentially other constants used by the simulation
// const double SLIT_SEPARATION = 0.1; // Example, if needed
// const double DISTANCE_TO_SCREEN = 1.0; // Example, if needed

#endif // CONFIG_H
```

## 🛠️ Installation and Setup

1.  **Clone the Repository**:
    ```bash
    git clone <repository-url>
    cd <repository-directory>
    ```
    *(Replace `<repository-url>` and `<repository-directory>` with your specific details)*

2.  **Create `config.h`**:
    Place your `config.h` file (as described in the "Core Configuration (`config.h`)" section) in the project directory.

3.  **Save Main Code**:
    Ensure your main program logic is saved as `quantum_experiment.cpp` (or your chosen main file name) in the project directory.

4.  **Compile the Program**:
    Open a terminal (Command Prompt, PowerShell, etc.) in the project directory.
    **Example using g++ (MinGW):**
    ```bash
    g++ quantum_experiment.cpp -o quantum_experiment.exe -std=c++11 -static-libgcc -static-libstdc++
    ```
    *(Adjust if you have other `.cpp` files, e.g., for utility functions if they are not inlined in a header).*

5.  **Run the Program**:
    ```bash
    .\quantum_experiment.exe
    ```
    *(or `quantum_experiment.exe` in CMD)*

## 💡 Usage Guide

1.  Compile and run `quantum_experiment.exe` as detailed in the "Installation and Setup" section.
2.  **Interface**:
    *   The program will display a header with its title and a brief description.
    *   A menu will then appear with the following options:
        1.  Run experiment WITH observer
        2.  Run experiment WITHOUT observer
        3.  Exit
3.  **Input**:
    *   Select a menu option (1–3) using a single keypress.
    *   **For Experiments (Option 1 or 2)**:
        *   **With Observer**: The simulation runs immediately. After results are shown, you can choose to repeat (`y`), exit the experiment sub-loop and return to the main menu (`s`), or exit the program entirely (often implicitly handled if `n` is chosen and it exits the sub-loop).
        *   **Without Observer**: The program may prompt you to "turn off your screen" (a conceptual instruction for the "no observation" principle) before running. After results, you can typically repeat (`y`) or return to the menu/exit (`n`).
    *   Invalid menu inputs will trigger an error message.
4.  **Output**:
    *   **With Observer Mode**:
        *   A list or summary of which slit (1 or 2) each of the `SAMPLE_SIZE` electrons "hit."
        *   The calculated average hit position (a value between 1.0 and 2.0).
        *   An ASCII art visualization representing the distribution of hits on the slits (e.g., more on left, right, or roughly equal).
    *   **Without Observer Mode**:
        *   A simulation of electron paths, categorizing outcomes (e.g., hit wall directly, hit right slit, appeared to pass through both slits, hit left slit – typically mapped to numbers 1-4).
        *   The calculated average of these path outcomes.
        *   An interpretation of the results (e.g., "Most electrons hit the wall," "Interference pattern observed").
        *   An ASCII art representation of the interference pattern on a virtual "blackboard" (e.g., hits distributed across 1-7 zones, with higher concentrations in some, mimicking wave peaks).
    *   A **Beep** sound signals the end of each experiment simulation.
5.  **Actions**:
    *   Follow the on-screen prompts (`y`/`n`/`s`) to repeat experiments or return to the main menu.
    *   Select option `3` from the main menu to exit the program.

## 🗂️ File Structure
*   `quantum_experiment.cpp`: The main C++ source file containing all program logic, including simulation, UI, and menu handling.
*   `config.h`: (User-provided) Header file for essential configurations like `PROGRAM_TITLE`, `SAMPLE_SIZE`, and `ConsoleColors`.
*   `[log_file_name].log`: (If `logError` is implemented and used) A log file for recording errors. The name would be defined by the `logError` implementation.
*   `README.md`: This documentation file.

## 📝 Technical Notes
*   **Windows Specifics**: The project heavily relies on Windows-specific headers (`<windows.h>`, `<conio.h>`) for functionalities like colored console output (`SetConsoleTextAttribute`), direct keypress input (`_getch()`), and sound (`Beep()`). Adapting for true cross-platform use would require significant changes (e.g., ANSI escape codes for colors, ncurses or similar for console I/O, a cross-platform sound library).
*   **Random Number Generation**: Uses `srand(time(NULL) * Wsp)` (where `Wsp` is likely a constant or variable to further vary the seed) to initialize the pseudo-random number generator (`rand()`). For more robust scientific simulations, C++11 `<random>` utilities are generally preferred.
*   **`logError` Functionality**: The description notes `logError` is defined but might be unused or not fully implemented. Implementing this robustly would enhance error tracking.
*   **Interference Pattern Simplification**: The `calculateInterference` function and the resulting pattern are likely simplified representations for console display. A more physically accurate model would be complex.
*   **Potential Enhancements**: Could be extended by logging detailed simulation data, adding options for graphical output (e.g., by writing data for an external plotter), allowing user configuration of more experiment parameters (slit width, distance), or implementing more sophisticated visualization techniques.

## 🤝 Contributing
Contributions to **QuantumSlit Voyager** are highly encouraged! If you have ideas for enhancing the simulation physics, improving the visualizations, adding more configurable parameters, or working on cross-platform compatibility:

1.  Fork the repository.
2.  Create a new branch for your feature (`git checkout -b feature/YourQuantumIdea`).
3.  Make your changes and commit them (`git commit -m 'Feature: Implement YourQuantumIdea'`).
4.  Push to the branch (`git push origin feature/YourQuantumIdea`).
5.  Open a Pull Request.

Please ensure your code is well-commented and adheres to good C++ practices.

## 📃 License
This project is licensed under the **MIT License**.
(If you have a `LICENSE` file in your repository, refer to it: `See the LICENSE file for details.`)

## 📧 Contact
Created by **Adrian Lesniak**.
For questions, feedback, or issues, please open an issue on the GitHub repository or contact the repository owner.

---
🌌 _Exploring the enigmatic dance of particles and waves, one simulation at a time._
