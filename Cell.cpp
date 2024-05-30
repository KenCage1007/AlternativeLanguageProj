#include "Cell.h"
#include <cmath>
#include <algorithm>
#include <numeric>

// Constructors
Cell::Cell() : launch_announced(0), body_weight(0.0), display_size(0.0) {}

Cell::Cell(std::string oem, std::string model, int launch_announced, std::string launch_status, std::string body_dimensions,
           float body_weight, std::string body_sim, std::string display_type, float display_size, std::string display_resolution,
           std::string features_sensors, std::string platform_os) :
        oem(std::move(oem)), model(std::move(model)), launch_announced(launch_announced), launch_status(std::move(launch_status)), body_dimensions(std::move(body_dimensions)),
        body_weight(body_weight), body_sim(std::move(body_sim)), display_type(std::move(display_type)), display_size(display_size), display_resolution(std::move(display_resolution)),
        features_sensors(std::move(features_sensors)), platform_os(std::move(platform_os)) {}

// Getters and Setters
std::string Cell::getOem() const { return oem; }
void Cell::setOem(const std::string& oem) { this->oem = oem; }

std::string Cell::getModel() const { return model; }
void Cell::setModel(const std::string& model) { this->model = model; }

int Cell::getLaunchAnnounced() const { return launch_announced; }
void Cell::setLaunchAnnounced(int launch_announced) { this->launch_announced = launch_announced; }

std::string Cell::getLaunchStatus() const { return launch_status; }
void Cell::setLaunchStatus(const std::string& launch_status) { this->launch_status = launch_status; }

std::string Cell::getBodyDimensions() const { return body_dimensions; }
void Cell::setBodyDimensions(const std::string& body_dimensions) { this->body_dimensions = body_dimensions; }

float Cell::getBodyWeight() const { return body_weight; }
void Cell::setBodyWeight(float body_weight) { this->body_weight = body_weight; }

std::string Cell::getBodySim() const { return body_sim; }
void Cell::setBodySim(const std::string& body_sim) { this->body_sim = body_sim; }

std::string Cell::getDisplayType() const { return display_type; }
void Cell::setDisplayType(const std::string& display_type) { this->display_type = display_type; }

float Cell::getDisplaySize() const { return display_size; }
void Cell::setDisplaySize(float display_size) { this->display_size = display_size; }

std::string Cell::getDisplayResolution() const { return display_resolution; }
void Cell::setDisplayResolution(const std::string& display_resolution) { this->display_resolution = display_resolution; }

std::string Cell::getFeaturesSensors() const { return features_sensors; }
void Cell::setFeaturesSensors(const std::string& features_sensors) { this->features_sensors = features_sensors; }

std::string Cell::getPlatformOs() const { return platform_os; }
void Cell::setPlatformOs(const std::string& platform_os) { this->platform_os = platform_os; }

// Utility Methods
int Cell::cleanLaunchAnnounced(const std::string& value) {
    std::regex re(R"(\b(\d{4})\b)");
    std::smatch match;
    if (std::regex_search(value, match, re)) {
        return std::stoi(match.str(1));
    }
    return 0;
}

float Cell::cleanBodyWeight(const std::string& value) {
    std::regex re(R"((\d+))");
    std::smatch match;
    if (std::regex_search(value, match, re)) {
        return std::stof(match.str(1));
    }
    return 0.0;
}

float Cell::cleanDisplaySize(const std::string& value) {
    std::regex re(R"((\d+(\.\d+)?))");
    std::smatch match;
    if (std::regex_search(value, match, re)) {
        return std::stof(match.str(1));
    }
    return 0.0;
}

std::string Cell::cleanPlatformOs(const std::string& value) {
    size_t pos = value.find(',');
    if (pos != std::string::npos) {
        return value.substr(0, pos);
    }
    return value;
}

std::string Cell::cleanBodySim(const std::string& value) {
    if (value == "No" || value == "Yes") {
        return "";
    }
    return value;
}

// Method to convert object details to a string
std::string Cell::toString() const {
    std::stringstream ss;
    ss << "OEM: " << oem << ", Model: " << model << ", Launch Announced: " << launch_announced
       << ", Launch Status: " << launch_status << ", Body Dimensions: " << body_dimensions
       << ", Body Weight: " << body_weight << ", Body SIM: " << body_sim << ", Display Type: " << display_type
       << ", Display Size: " << display_size << ", Display Resolution: " << display_resolution
       << ", Features Sensors: " << features_sensors << ", Platform OS: " << platform_os;
    return ss.str();
}

// Additional Methods
float Cell::calculateMean(const std::vector<float>& values) {
    if (values.empty()) return 0.0;
    return std::accumulate(values.begin(), values.end(), 0.0) / values.size();
}

float Cell::calculateMedian(std::vector<float> values) {
    if (values.empty()) return 0.0;
    std::sort(values.begin(), values.end());
    size_t size = values.size();
    if (size % 2 == 0) {
        return (values[size / 2 - 1] + values[size / 2]) / 2;
    }
    return values[size / 2];
}

float Cell::calculateStandardDeviation(const std::vector<float>& values) {
    if (values.size() <= 1) return 0.0;
    float mean = calculateMean(values);
    float sq_sum = std::inner_product(values.begin(), values.end(), values.begin(), 0.0);
    return std::sqrt(sq_sum / values.size() - mean * mean);
}

std::vector<std::string> Cell::listUniqueValues(const std::vector<Cell>& cells, std::string (Cell::*getter)() const) {
    std::set<std::string> unique_values;
    for (const auto& cell : cells) {
        unique_values.insert((cell.*getter)());
    }
    return std::vector<std::string>(unique_values.begin(), unique_values.end());
}

void Cell::addObject(std::vector<Cell>& cells, const Cell& cell) {
    cells.push_back(cell);
}

void Cell::deleteObject(std::vector<Cell>& cells, const std::string& model) {
    cells.erase(std::remove_if(cells.begin(), cells.end(),
                               [&model](const Cell& cell) { return cell.getModel() == model; }), cells.end());
}
