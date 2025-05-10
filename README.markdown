# Young's Quantum Experiment Simulator

## Overview
This C++ console application, authored by Adrian Lesniak, simulates Young's double-slit experiment to demonstrate quantum behavior. It models particle-like behavior with an observer and wave interference patterns without an observer. The program features Windows-specific colored output, random number generation for electron paths, and logging, with configurations defined in `config.h`.

## Features
- **Experiment Modes**:
  - **With Observer**: Simulates particle-like behavior; electrons hit one slit (1 or 2).
  - **Without Observer**: Simulates wave-like behavior; electrons hit wall, slits, or both, creating interference patterns.
- **Simulation**:
  - `RandomNumber`: Generates pseudo-random numbers for electron paths.
  - `calculateInterference`: Computes interference pattern using cosine-squared function.
  - Uses `SAMPLE_SIZE` (from `config.h`) for number of electron shots.
- **Interface**:
  - `displayHeader`: Shows program title, author, and description.
  - `displayMenu`: Lists options: run with observer, without observer, or exit.
  - Colored output (cyan, magenta, yellow, white) via Windows console API.
- **Output**:
  - With observer: Displays slit hits, average, and ASCII slit visualization.
  - Without observer: Shows electron destinations (wall, slits, both) and interference pattern on a virtual blackboard.
  - Beeps (523.3 Hz) to signal experiment completion.
- **Utilities**:
  - `runExperiment`: Executes simulation based on observer presence.
  - `logError`: Logs errors to a file (not fully implemented in provided code).
- **Main Program**:
  - Loops until user selects exit (3).
  - Handles invalid inputs with error messages.

## Requirements
- C++ compiler (e.g., g++, MSVC) with C++11 or later
- Windows OS (for `<windows.h>`, `SetConsoleTextAttribute`, `_getch`, `Beep`)
- Standard C++ libraries: `<iostream>`, `<ctime>`, `<time.h>`, `<stdio.h>`, `<cstdlib>`, `<conio.h>`, `<cmath>`, `<iomanip>`, `<fstream>`
- Custom header: `config.h` (defines `PROGRAM_TITLE`, `SAMPLE_SIZE`, `ConsoleColors`)
- Write permissions for log file (if `logError` is implemented)
- Operating system: Windows (due to console and sound functions)

## Setup
1. Clone the repository:
   ```bash
   git clone <repository-url>
   cd <repository-directory>
   ```
2. Ensure `config.h` is in the project directory with required definitions (e.g., `PROGRAM_TITLE`, `SAMPLE_SIZE`, `ConsoleColors::ERROR_COLOR`).
3. Save the provided code as `quantum_experiment.cpp`.
4. Compile the program:
   ```bash
   g++ quantum_experiment.cpp -o quantum_experiment
   ```
5. Run the program:
   ```bash
   .\quantum_experiment
   ```

## Usage
1. Compile and run the program using the steps above.
2. **Interface**:
   - Displays header and menu with options:
     1. Run with observer
     2. Run without observer
     3. Exit
3. **Input**:
   - Select 1–3 via keypress.
   - For experiments:
     - With observer: Runs immediately; option to repeat (y/n/s).
     - Without observer: Prompts to turn off screen for "no observation," then runs; option to repeat (y/n).
   - Invalid inputs trigger error messages.
4. **Output**:
   - **With Observer**:
     - Lists electron hits (slit 1 or 2) for `SAMPLE_SIZE` shots.
     - Shows average hit (1.0–2.0) and ASCII slit visualization (e.g., left, right, or equal hits).
   - **Without Observer**:
     - Simulates electron paths (1–4: wall, right slit, both slits, left slit).
     - Displays average (1.0–4.0) and interprets results (e.g., "Most electrons hit the wall").
     - Shows interference pattern for blackboard hits (1–7) with ASCII wave visualization.
   - Beep signals experiment end.
5. **Actions**:
   - Press y/n to repeat or exit experiment; s (with observer) returns to menu.
   - Select 3 to exit program.

## File Structure
- `quantum_experiment.cpp`: Main C++ source file with program logic.
- `config.h`: Header for configuration (e.g., `PROGRAM_TITLE`, `SAMPLE_SIZE`, assumed).
- Log file: Created by `logError` (not implemented in provided code).
- `README.md`: This file, providing project documentation.

## Notes
- Windows-specific due to `<windows.h>`, `_getch`, `Beep`; adapt for cross-platform (e.g., ANSI colors, `system("clear")`).
- Requires `config.h` with constants like `PROGRAM_TITLE`, `SAMPLE_SIZE`, `ConsoleColors`.
- Random number generation uses `srand(time(NULL) * Wsp)` for varied seeds.
- `logError` defined but unused; implement for robust error handling.
- Interference pattern simplified; could use `calculateInterference` more extensively.
- Extend by adding data logging, graphical output, or real-time visualization.
- Ensure write permissions for log file if implemented.
- No external dependencies beyond standard C++ libraries.

## Contributing
Contributions are welcome! To contribute:
1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Make changes and commit (`git commit -m "Add feature"`).
4. Push to the branch (`git push origin feature-branch`).
5. Open a pull request.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Contact
For questions or feedback, open an issue on GitHub or contact the repository owner.