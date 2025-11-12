#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>

int main() {
    // Program: Predict population size over days with input validation
    double startPopulation = 0.0;
    double dailyIncreasePercent = 0.0;
    int days = 0;

    // Input: starting population (must be >= 2)
    while (true) {
        std::cout << "Enter the starting number of organisms (>= 2): ";
        if (!(std::cin >> startPopulation)) {
            // non-numeric input
            std::cout << "Invalid input. Please enter a numeric value.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        if (startPopulation < 2.0) {
            std::cout << "Starting population must be at least 2.\n";
            continue;
        }
        break;
    }

    // Input: average daily population increase in percent (must be >= 0)
    while (true) {
        std::cout << "Enter the average daily population increase (percentage, >= 0): ";
        if (!(std::cin >> dailyIncreasePercent)) {
            std::cout << "Invalid input. Please enter a numeric value.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        if (dailyIncreasePercent < 0.0) {
            std::cout << "Daily increase percentage cannot be negative.\n";
            continue;
        }
        break;
    }

    // Input: number of days (must be >= 1)
    while (true) {
        std::cout << "Enter the number of days they will multiply (>= 1): ";
        if (!(std::cin >> days)) {
            std::cout << "Invalid input. Please enter an integer number of days.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        if (days < 1) {
            std::cout << "Number of days must be at least 1.\n";
            continue;
        }
        break;
    }

    // Calculations: show a table of population by day
    std::cout << "\nPopulation Growth Report\n";
    std::cout << "------------------------\n";
    std::cout << std::left << std::setw(8) << "Day" << "Population\n";

    // Use a double for calculation; show population rounded to nearest integer
    double currentPopulation = startPopulation;
    double growthFactor = 1.0 + (dailyIncreasePercent / 100.0);

    for (int day = 1; day <= days; ++day) {
        // display: round to nearest whole organism (if desired)
        long long displayed = static_cast<long long>(std::llround(currentPopulation));
        std::cout << std::left << std::setw(8) << day << displayed << '\n';

        // compute next day's population (only if not last iteration)
        currentPopulation *= growthFactor;
    }

    return 0;
}