#include "train.h"
#include "train_logger.h"
#include <chrono>
#include <random>
#include <iostream>

using namespace std;
using namespace std::chrono;

Train::Train(const string& train_name, TrainCategory train_type)
    : name(train_name), 
      type(train_type), 
      gen(rd()),
      total_distance(500), 
      current_distance(0), 
      is_moving(false) {
    
    // Set speed and track based on train type
    switch(type) {
        case PASSENGER: 
            speed = 50; 
            track_name = "Main Line"; 
            break;
        case FREIGHT: 
            speed = 30; 
            track_name = "Freight Corridor"; 
            break;
        case EXPRESS: 
            speed = 80; 
            track_name = "Express Route"; 
            break;
        case CARGO: 
            speed = 40; 
            track_name = "Freight Corridor"; 
            break;
        case BULLET_TRAIN: 
            speed = 100; 
            track_name = "Main Line"; 
            break;
        default: 
            speed = 50; 
            track_name = "Default Track"; 
            break;
    }
}

// Move constructor
// In train.cpp
Train::Train(Train&& other) noexcept
    : name(std::move(other.name)),
      type(other.type),
      speed(other.speed),
      total_distance(other.total_distance),
      current_distance(other.current_distance),
      is_moving(other.is_moving),
      track_name(std::move(other.track_name)),
      rd(),  // Reinitialize random device
      gen(rd())  // Seed with new random device
{
    // Reset other object's state
    other.total_distance = 0;
    other.current_distance = 0;
    other.is_moving = false;
}

Train& Train::operator=(Train&& other) noexcept {
    if (this != &other) {
        // Use std::move for string members
        name = std::move(other.name);
        type = other.type;
        speed = other.speed;
        total_distance = other.total_distance;
        current_distance = other.current_distance;
        is_moving = other.is_moving;
        track_name = std::move(other.track_name);
        
        // Reinitialize random generator
        gen.seed(rd());
        
        // Reset other object's state
        other.total_distance = 0;
        other.current_distance = 0;
        other.is_moving = false;
    }
    return *this;
}

void Train::start() {
    is_moving = true;
    simulateJourney();
}

void Train::stop() {
    is_moving = false;
    cout << "🛑 " << name << " has stopped." << endl;
}

void Train::move() {
    cout << "🚂 " << name << " is moving..." << endl;
}

int Train::calculateRandomDistance() {
    uniform_int_distribution<> dist(10, 100);
    return dist(gen);
}

void Train::takeBreaks() {
    uniform_int_distribution<> break_dist(1, 5);
    int break_duration = break_dist(gen);
    
    cout << "🛏️ " << name << " taking a break for " 
         << break_duration << " seconds..." << endl;
    
    this_thread::sleep_for(seconds(break_duration));
}

void Train::simulateJourney() {
    TrainLogger::logTrainStart(*this);
    
    while (current_distance < total_distance) {
        int move_distance = calculateRandomDistance();
        current_distance += move_distance;
        
        if (current_distance > total_distance) {
            move_distance -= (current_distance - total_distance);
            current_distance = total_distance;
        }
        
        TrainLogger::logTrainMovement(*this, move_distance);
        
        this_thread::sleep_for(seconds(move_distance / speed));
        
        takeBreaks();
        
        if (current_distance % 150 == 0) {
            stop();
            this_thread::sleep_for(seconds(3));
        }
    }
    
    TrainLogger::logTrainCompletion(*this);
}

// Getter implementations
string Train::getName() const { return name; }
TrainCategory Train::getType() const { return type; }
int Train::getCurrentDistance() const { return current_distance; }
int Train::getSpeed() const { return speed; }
string Train::getTrackName() const { return track_name; }