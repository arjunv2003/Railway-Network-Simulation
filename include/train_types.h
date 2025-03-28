#pragma once
#include <string>
#include <vector>

using namespace std;

enum TrainCategory {
    PASSENGER,
    FREIGHT,
    EXPRESS,
    CARGO,
    BULLET_TRAIN
};

struct TrainSpecification {
    string name;
    TrainCategory category;
    int max_speed;
    int passenger_capacity;
    string color;
};

class TrainTypeManager {
public:
    static vector<TrainSpecification> getAllTrainTypes();
    static TrainSpecification getTrainTypeByCategory(TrainCategory category);
};