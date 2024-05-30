#include <iostream>
#include "Cell.h"
#include "CellData.h"

int main() {
    CellData cell_data;

    try {
        cell_data.readCSV("/Users/queencage/Downloads/cells.csv");
        cell_data.displayAllCells();

        std::vector<float> body_weights = cell_data.getAllBodyWeights();
        float sum = std::accumulate(body_weights.begin(), body_weights.end(), 0.0);
        float mean = sum / body_weights.size();
        std::cout << "Mean Body Weight: " << mean << std::endl;

        // Add other statistical calculations and display unique values as needed
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
