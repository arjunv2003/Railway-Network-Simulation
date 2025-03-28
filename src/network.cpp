#include "network.h"
#include "train_logger.h"
#include <iomanip>

void RailwayNetwork::initializeNetwork() {
    // Placeholder for network initialization
    std::cout << "🚉 Initializing Railway Network..." << std::endl;
    
    // You can add more detailed initialization logic here
    // For example, setting up tracks, stations, etc.
}

void RailwayNetwork::addTrain(Train train) {
    // Move the train into the network's train collection
    trains.push_back(std::move(train));
}

void RailwayNetwork::simulateTraffic() {
    // Placeholder for traffic simulation
    std::cout << "🚂 Simulating Railway Network Traffic..." << std::endl;
    
    // Generate final network report
    generateNetworkReport();
}

void RailwayNetwork::generateNetworkReport() {
    std::cout << "\n🚉 Railway Network Comprehensive Report 🚉" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    
    // Network Overview
    std::cout << "Network Statistics:" << std::endl;
    std::cout << "  Total Tracks: 3" << std::endl;
    std::cout << "    1. Main Line" << std::endl;
    std::cout << "    2. Express Route" << std::endl;
    std::cout << "    3. Freight Corridor" << std::endl;
    
    // Train Performance Summary
    std::cout << "\nTrain Performance Summary:" << std::endl;
    std::cout << std::setw(20) << std::left << "Train Name" 
              << std::setw(15) << "Type" 
              << std::setw(15) << "Track" 
              << std::setw(15) << "Speed (km/h)" 
              << "Status" << std::endl;
    
    std::cout << std::string(70, '-') << std::endl;
    
    for (const auto& train : trains) {
        std::cout << std::setw(20) << std::left << train.getName()
                  << std::setw(15) << TrainLogger::getTrainTypeName(train.getType())
                  << std::setw(15) << train.getTrackName()
                  << std::setw(15) << train.getSpeed()
                  << "Completed" << std::endl;
    }
}