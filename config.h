#pragma once

#define PROGRAM_TITLE "Young's Quantum Experiment Simulator"
#define PROGRAM_AUTHOR "Adrian Lesniak"
#define PROGRAM_VERSION "2.0"

const int SAMPLE_SIZE = 1000;
const int SLEEP_TIME = 3000;
const int BEEP_FREQ = 523;
const int BEEP_DURATION = 200;

// Updated color constants with only bright colors
enum ConsoleColors {
    TITLE_COLOR = 11,     // Bright Cyan
    MENU_COLOR = 15,      // Bright White
    INFO_COLOR = 14,      // Bright Yellow
    ERROR_COLOR = 13,     // Bright Magenta
    RESULT_COLOR = 10     // Bright Green
};

// Add physics constants
const double ELECTRON_WAVELENGTH = 2.43e-12; // de Broglie wavelength
const double SLIT_SEPARATION = 1e-6;         // in meters
