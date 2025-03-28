#pragma once
#include <string>
#include <thread>
#include <mutex>
#include <random>
#include "train_types.h"

class Train {
private:
    std::string name;
    TrainCategory type;
    int speed;
    int total_distance;
    int current_distance;
    bool is_moving;
    std::string track_name;

    // Random number generation
    std::random_device rd;
    std::mt19937 gen;

public:
    // Constructors
    Train(const std::string& train_name, TrainCategory train_type);
    Train(Train&& other) noexcept;
    Train& operator=(Train&& other) noexcept;

    // Deleted copy operations
    Train(const Train&) = delete;
    Train& operator=(const Train&) = delete;

    // Public methods
    void start();
    void stop();
    void move();

    // Internal methods
    int calculateRandomDistance();
    void takeBreaks();
    void simulateJourney();

    // Getters
    std::string getName() const;
    TrainCategory getType() const;
    int getCurrentDistance() const;
    int getSpeed() const;
    std::string getTrackName() const;
};