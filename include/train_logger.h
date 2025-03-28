#pragma once
#include <string>
#include "train_types.h"

class Train;  // Forward declaration

class TrainLogger {
public:
    // Static methods for logging
    static std::string getTrainTypeName(TrainCategory type);
    
    // Logging methods that take a Train reference
    static void logTrainMovement(const Train& train, int movement_distance);
    static void logTrainStart(const Train& train);
    static void logTrainCompletion(const Train& train);
};