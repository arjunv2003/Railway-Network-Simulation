#pragma once
#include <vector>
#include <iostream>
#include "train.h"
#include "station.h"
#include "track.h"

class RailwayNetwork {
private:
    // Network components
    std::vector<Train> trains;

public:
    // Network initialization
    void initializeNetwork();

    // Train management
    void addTrain(Train train);

    // Traffic simulation
    void simulateTraffic();

    // Network reporting
    void generateNetworkReport();
};