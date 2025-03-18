# RadarSim-KF

**RadarSim-KF** is a simulation project that models a radar system employing Kalman filtering techniques to track multiple targets over time. Developed in C++, this project demonstrates real-time data processing and target estimation, providing insights into radar signal processing and object tracking algorithms.

## Table of Contents

- [Project Overview](#project-overview)
- [Features](#features)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)

## Project Overview

RadarSim-KF simulates a radar system capable of detecting and tracking multiple targets using simulated radar data. The core of the simulation utilizes the Kalman filter algorithm to estimate the position and velocity of each target, accounting for noisy measurements and dynamic movements. The project offers:

- Real-time simulation of radar sweeps.
- Implementation of the Kalman filter for precise target tracking.
- Visualization of target positions over successive radar sweeps.

## Features

- **Real-Time Simulation**:  
  Simulates radar sweeps in real-time, updating target positions with each new time step. The radar system dynamically tracks multiple targets, providing an up-to-date view of the targets' movements as the simulation progresses.

- **Kalman Filtering**:  
  Implements the **Kalman filter** algorithm to accurately track and predict the position and velocity of targets. By correcting noisy measurements, the filter improves the precision of the target's predicted path and ensures robust tracking even with uncertain data.

- **Multiple Target Tracking**:  
  Supports simultaneous tracking of multiple targets. Each target has its own independent Kalman filter to estimate its position and velocity, ensuring that the radar system can handle complex tracking scenarios with multiple moving objects.

- **Visualization**:  
  Provides a simple text-based radar visualization, where targets are represented by 'X' and empty space by '-'. Each radar sweep is displayed step-by-step, showing how targets move over time, which helps visualize the system's tracking capabilities.

## Getting Started

To get started with RadarSim-KF, follow the instructions below.

### Prerequisites

Ensure you have the following installed:

- **C++ Compiler**: A C++ compiler that supports C++20 standards (e.g., GCC, Clang).
- **CMake**: A tool for managing the build process and generating project files.
- **Git**: A version control system to clone the repository and manage your code.

### Installation

1. **Clone the Repository**:

   ```bash
   git clone https://github.com/yourusername/RadarSim-KF.git
   ```

2. **Navigate to the Project Directory**:
   
   ```bash
    cd RadarSim-KF
   ```

3. **Create a Build Directory**:

   ```bash
   mkdir build
   cd build
   ```
   
4. **Generate Build Files with CMake**:
   
   ```bash
   cmake ..
   ```
  
5. **Build the Project**:
   ```bash
   make
   ```
   
6. **Run the Simulation**:

   ```bash
   ./RadarSimKF
   ```

  ## Usage
  
  After running the simulation, the program will output a series of radar sweeps, each representing a time step in the tracking process. Targets are shown by 'X' on the radar grid,       and their positions update with each sweep, illustrating the tracking capabilities of the Kalman filter.​
  
  Example Output:

    Radar Sweep: - - - - - X - - - - - - - - - - - - - - - - X - - - - X - - X - - - - X - - - -
    Step 1 complete
    Radar Sweep: - - - - - X - - - - - - - - - - - - - - - - X - - - - X - - X - - - - X - - - -
    Step 2 complete

  ## Contributing

  To contribute:

  1. Fork the Repository: Create your own fork of the project.
  2. Create a Branch: Develop your feature or fix on a separate branch.
  3. Submit a Pull Request: Once your changes are complete, submit a pull request to merge them into the main repository.

    




