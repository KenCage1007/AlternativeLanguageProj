#ifndef CELLDATA_H
#define CELLDATA_H

#include <unordered_map>
#include <set>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <numeric>
#include "Cell.h" // Include the Cell class definition

class CellData {
private:
    std::unordered_map<std::string, Cell> cell_map;

public:
    void readCSV(const std::string& filename);
    void displayAllCells() const;
    std::vector<float> getAllBodyWeights() const;
    // Additional utility methods as required, e.g., statistics, unique values, add/delete object
};

#endif // CELLDATA_H
