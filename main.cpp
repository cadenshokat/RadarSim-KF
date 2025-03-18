#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <map>
#include <cmath>

// Simple Kalman Filter for tracking a single target
class KalmanFilter {
public:
    // Default constructor (required for map)
    KalmanFilter() : x(0), v(0), P(1), R(1), Q(1) {}

    // Constructor with initial position and velocity
    KalmanFilter(float init_x, float init_v) : x(init_x), v(init_v), P(1), R(1), Q(1) {}

    void predict(float dt) {
        // Predict the new state
        x = x + v * dt;
        v = v;  // constant velocity model
        P = P + Q;
    }

    void update(float z) {
        // Kalman Gain
        float K = P / (P + R);
        // Update the state estimate
        x = x + K * (z - x);
        v = v;
        // Update the error covariance
        P = (1 - K) * P;
    }

    float getPosition() const { return x; }

private:
    float x, v; // Position and velocity
    float P; // Estimation covariance
    float R; // Measurement noise
    float Q; // Process noise
};

// Function to generate radar signal data (more complexity for multiple targets)
std::vector<int> generateRadarData(int numTargets) {
    std::vector<int> radarData;
    for (int i = 0; i < numTargets; ++i) {
        // Simulate radar data (signal strength) with noise
        radarData.push_back(rand() % 100);  // Random signal strength between 0-100
    }
    return radarData;
}

// Function to process the radar signal (basic noise filtering using moving average)
std::vector<int> processSignal(const std::vector<int>& radarData) {
    std::vector<int> processedData;
    for (size_t i = 1; i < radarData.size() - 1; ++i) {
        // Simple moving average for noise reduction
        int avg = (radarData[i - 1] + radarData[i] + radarData[i + 1]) / 3;
        processedData.push_back(avg);
    }
    return processedData;
}

// Function to detect targets based on signal threshold (with multiple targets)
std::vector<int> detectTargets(const std::vector<int>& processedData, int threshold) {
    std::vector<int> targets;
    for (size_t i = 0; i < processedData.size(); ++i) {
        if (processedData[i] > threshold) {
            targets.push_back(i);  // Store index of detected target
        }
    }
    return targets;
}

// Function to visualize radar (display target locations on a simple grid)
void visualizeRadar(const std::map<int, KalmanFilter>& trackers, int gridSize) {
    std::vector<int> radarGrid(gridSize, 0);  // Initialize radar grid

    // Simulate the radar sweep
    for (const auto& target : trackers) {
        int position = (int)target.second.getPosition();
        if (position >= 0 && position < gridSize) {
            radarGrid[position] = 1; // Mark the target position
        }
    }

    std::cout << "Radar Sweep: ";
    for (int i = 0; i < gridSize; ++i) {
        std::cout << (radarGrid[i] == 1 ? "X " : "- ");
    }
    std::cout << std::endl;
}

// Main function to simulate radar with multiple targets and tracking
int main() {
    // Seed the random number generator for variability
    srand(time(0));

    // Parameters
    int numTargets = 5;  // Number of targets (for simplicity, we track 5 targets)
    int gridSize = 40;   // Size of radar sweep (visualization)
    int threshold = 50;  // Signal threshold for target detection
    int timeSteps = 10;  // Number of simulation steps (e.g., radar sweeps)

    // Initialize Kalman Filters for each target
    std::map<int, KalmanFilter> trackers;
    for (int i = 0; i < numTargets; ++i) {
        // Initialize each target's Kalman filter with random starting positions and velocities
        trackers.emplace(i, KalmanFilter(rand() % gridSize, 1 + rand() % 2)); // Random velocity
    }

    // Simulation loop: simulate radar over time
    for (int t = 0; t < timeSteps; ++t) {
        // Generate new radar data
        std::vector<int> radarData = generateRadarData(numTargets);

        // Process the radar signal
        std::vector<int> processedData = processSignal(radarData);

        // Detect targets
        std::vector<int> detectedTargets = detectTargets(processedData, threshold);

        // Update each target's Kalman filter with the new detected positions
        for (auto& target : trackers) {
            if (!detectedTargets.empty()) {
                // Simulate target detection being close to the radar reading
                target.second.predict(1); // Predict next position
                target.second.update(rand() % gridSize); // Randomly update position
            }
        }

        // Visualize the radar sweep with tracked targets
        visualizeRadar(trackers, gridSize);
        std::cout << "Step " << t + 1 << " complete" << std::endl;
    }

    return 0;
}
