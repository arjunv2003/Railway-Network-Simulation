#include "train_logger.h"
#include "train.h"
#include <iostream>
#include <iomanip>

using namespace std;

string TrainLogger::getTrainTypeName(TrainCategory type) {
    switch(type) {
        case PASSENGER: return "Passenger Train";
        case FREIGHT: return "Freight Train";
        case EXPRESS: return "Express Train";
        case CARGO: return "Cargo Train";
        case BULLET_TRAIN: return "Bullet Train";
        default: return "Unknown Train";
    }
}

void TrainLogger::logTrainMovement(const Train& train, int movement_distance) {
    cout << fixed << setprecision(2);
    cout << "🚂 Train Movement Report:" << endl;
    cout << "   Name: " << train.getName() << endl;
    cout << "   Type: " << getTrainTypeName(train.getType()) << endl;
    cout << "   Track: " << train.getTrackName() << endl;
    cout << "   Current Movement: " << movement_distance << " km" << endl;
    cout << "   Total Distance Traveled: " << train.getCurrentDistance() << " km" << endl;
    cout << "   Speed: " << train.getSpeed() << " km/h" << endl;
    cout << "   Estimated Travel Time: " 
         << static_cast<float>(movement_distance) / train.getSpeed() << " hours" << endl;
    cout << "   Remaining Distance: " 
         << (500 - train.getCurrentDistance()) << " km" << endl;
    cout << "-----------------------------------" << endl;
}

void TrainLogger::logTrainStart(const Train& train) {
    cout << "🚂 Train Dispatch Report:" << endl;
    cout << "   Name: " << train.getName() << endl;
    cout << "   Type: " << getTrainTypeName(train.getType()) << endl;
    cout << "   Track: " << train.getTrackName() << endl;
    cout << "   Initial Speed: " << train.getSpeed() << " km/h" << endl;
    cout << "   Total Journey Distance: 500 km" << endl;
    cout << "-----------------------------------" << endl;
}

void TrainLogger::logTrainCompletion(const Train& train) {
    cout << "🏁 Train Completion Report:" << endl;
    cout << "   Name: " << train.getName() << endl;
    cout << "   Type: " << getTrainTypeName(train.getType()) << endl;
    cout << "   Track: " << train.getTrackName() << endl;
    cout << "   Total Distance Traveled: 500 km" << endl;
    cout << "   Average Speed: " << train.getSpeed() << " km/h" << endl;
    cout << "-----------------------------------" << endl;
}