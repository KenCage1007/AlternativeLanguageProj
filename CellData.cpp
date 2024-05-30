#include "CellData.h"

void CellData::readCSV(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    std::set<std::string> unique_rows;

    if (!file.is_open()) {
        throw std::runtime_error("Could not open file");
    }

    // Skip header
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::vector<std::string> row;
        std::string cell;

        while (std::getline(ss, cell, ',')) {
            if (cell == "-" || cell.empty()) {
                cell = "";
            }
            row.push_back(cell);
        }

        if (unique_rows.find(line) != unique_rows.end()) {
            continue; // Skip duplicate rows
        }
        unique_rows.insert(line);

        if (row.size() == 12) {
            Cell cell(
                    row[0], row[1], Cell::cleanLaunchAnnounced(row[2]), row[3],
                    row[4], Cell::cleanBodyWeight(row[5]), Cell::cleanBodySim(row[6]),
                    row[7], Cell::cleanDisplaySize(row[8]), row[9],
                    row[10], Cell::cleanPlatformOs(row[11])
            );
            cell_map[row[1]] = cell;
        }
    }

    file.close();
}

void CellData::displayAllCells() const {
    for (const auto& pair : cell_map) {
        std::cout << pair.second.toString() << std::endl;
    }
}

std::vector<float> CellData::getAllBodyWeights() const {
    std::vector<float> body_weights;
    for (const auto& pair : cell_map) {
        body_weights.push_back(pair.second.getBodyWeight());
    }
    return body_weights;
}
