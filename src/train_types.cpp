#include "train_types.h"

using namespace std;

vector<TrainSpecification> TrainTypeManager::getAllTrainTypes() {
    return {
        {"Thomas Express", PASSENGER, 120, 250, "🔵"},
        {"Cargo King", FREIGHT, 80, 0, "🟤"},
        {"Lightning Bolt", EXPRESS, 250, 150, "🔴"},
        {"Heavy Hauler", CARGO, 90, 0, "🟢"},
        {"Shinkansen", BULLET_TRAIN, 320, 400, "⚪"}
    };
}

TrainSpecification TrainTypeManager::getTrainTypeByCategory(TrainCategory category) {
    for (const auto& train : getAllTrainTypes()) {
        if (train.category == category) {
            return train;
        }
    }
    // Default train if not found
    return {"Default Train", PASSENGER, 100, 200, "🚂"};
}