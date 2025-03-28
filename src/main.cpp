#include <iostream>
#include <vector>
#include <thread>
#include "train.h"
#include "network.h"
#include "train_types.h"

using namespace std;

int main() {
    RailwayNetwork railway_network;
    railway_network.initializeNetwork();

    vector<TrainSpecification> train_types = TrainTypeManager::getAllTrainTypes();
    
    vector<thread> train_threads;

    for (const auto& train_spec : train_types) {
        // Create train and move it into the network
        Train train(train_spec.name, train_spec.category);
        railway_network.addTrain(std::move(train));
        
        // Create a thread for train simulation
        train_threads.emplace_back([train_spec]() {
            Train thread_train(train_spec.name, train_spec.category);
            thread_train.start();
        });
    }

    // Wait for all trains
    for (auto& thread : train_threads) {
        thread.join();
    }

    railway_network.simulateTraffic();

    cout << "🎊 Railway Simulation Complete! 🎊" << endl;
    return 0;
}