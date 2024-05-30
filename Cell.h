#ifndef CELL_H
#define CELL_H

#include <string>
#include <sstream>
#include <regex>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>

class Cell {
private:
    std::string oem;
    std::string model;
    int launch_announced;
    std::string launch_status;
    std::string body_dimensions;
    float body_weight;
    std::string body_sim;
    std::string display_type;
    float display_size;
    std::string display_resolution;
    std::string features_sensors;
    std::string platform_os;

public:
    // Constructors
    Cell();
    Cell(std::string oem, std::string model, int launch_announced, std::string launch_status, std::string body_dimensions,
         float body_weight, std::string body_sim, std::string display_type, float display_size, std::string display_resolution,
         std::string features_sensors, std::string platform_os);

    // Getters and Setters
    std::string getOem() const;
    void setOem(const std::string& oem);

    std::string getModel() const;
    void setModel(const std::string& model);

    int getLaunchAnnounced() const;
    void setLaunchAnnounced(int launch_announced);

    std::string getLaunchStatus() const;
    void setLaunchStatus(const std::string& launch_status);

    std::string getBodyDimensions() const;
    void setBodyDimensions(const std::string& body_dimensions);

    float getBodyWeight() const;
    void setBodyWeight(float body_weight);

    std::string getBodySim() const;
    void setBodySim(const std::string& body_sim);

    std::string getDisplayType() const;
    void setDisplayType(const std::string& display_type);

    float getDisplaySize() const;
    void setDisplaySize(float display_size);

    std::string getDisplayResolution() const;
    void setDisplayResolution(const std::string& display_resolution);

    std::string getFeaturesSensors() const;
    void setFeaturesSensors(const std::string& features_sensors);

    std::string getPlatformOs() const;
    void setPlatformOs(const std::string& platform_os);

    // Utility Methods
    static int cleanLaunchAnnounced(const std::string& value);
    static float cleanBodyWeight(const std::string& value);
    static float cleanDisplaySize(const std::string& value);
    static std::string cleanPlatformOs(const std::string& value);
    static std::string cleanBodySim(const std::string& value);

    // Method to convert object details to a string
    std::string toString() const;

    // Additional Methods
    static float calculateMean(const std::vector<float>& values);
    static float calculateMedian(std::vector<float> values);
    static float calculateStandardDeviation(const std::vector<float>& values);
    static std::vector<std::string> listUniqueValues(const std::vector<Cell>& cells, std::string (Cell::*getter)() const);
    static void addObject(std::vector<Cell>& cells, const Cell& cell);
    static void deleteObject(std::vector<Cell>& cells, const std::string& model);
};

#endif // CELL_H
