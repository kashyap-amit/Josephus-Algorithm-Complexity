#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>
using namespace std;

// Recursive Implementation: J(n,k) = (J(n-1, k) + k) mod n
int josephusRecursive(int n, int k) {
    if (n == 1) return 0;
    return (josephusRecursive(n - 1, k) + k) % n;
}

// Iterative Implementation
int josephusIterative(int n, int k) {
    int result = 0;
    for (int i = 2; i <= n; i++) {
        result = (result + k) % i;
    }
    return result;
}

int main() {
    int k = 3; // Constant k for the experiment

    int n_values[] = {1000, 5000, 10000, 15000, 20000, 25000, 30000, 35000, 40000, 45000};
    int num_trials = 1000; // Number of repetitions to average out noise

    cout << "n_value" << "," << "Iterative_Time" << "," << "Recursive_Time" << endl;

    for (int n : n_values) {
        // --- Measure Iterative ---
        clock_t start_i = clock();
        for (int t = 0; t < num_trials; t++) {
            josephusIterative(n, k);
        }
        clock_t end_i = clock();
        double time_i = (double)(end_i - start_i) / (CLOCKS_PER_SEC * num_trials);

        // --- Measure Recursive ---
        clock_t start_r = clock();
        for (int t = 0; t < num_trials; t++) {
            josephusRecursive(n, k);
        }
        clock_t end_r = clock();
        double time_r = (double)(end_r - start_r) / (CLOCKS_PER_SEC * num_trials);

        // Output in CSV format
        cout << n << "," << fixed << setprecision(10) << time_i << "," << time_r << endl;
    }

    return 0;
}