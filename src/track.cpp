#include "track.h"
#include <utility>

using namespace std;

// Parameterized constructor
Track::Track(int id, string name) 
    : track_id(id), track_name(std::move(name)), is_occupied(false) {}

// Move constructor
Track::Track(Track&& other) noexcept
    : track_id(std::move(other.track_id)),
      track_name(std::move(other.track_name)),
      is_occupied(std::move(other.is_occupied)) {
    other.track_id = 0;
    other.track_name = "";
    other.is_occupied = false;
}

// Move assignment operator
Track& Track::operator=(Track&& other) noexcept {
    if (this != &other) {
        track_id = std::move(other.track_id);
        track_name = std::move(other.track_name);
        is_occupied = std::move(other.is_occupied);
        
        other.track_id = 0;
        other.track_name = "";
        other.is_occupied = false;
    }
    return *this;
}

bool Track::requestAccess() {
    lock_guard<mutex> lock(track_mutex);
    if (!is_occupied) {
        is_occupied = true;
        return true;
    }
    return false;
}

void Track::releaseAccess() {
    lock_guard<mutex> lock(track_mutex);
    is_occupied = false;
}

string Track::getTrackName() const {
    return track_name;
}

int Track::getTrackId() const {
    return track_id;
}

// TrackNetwork implementation
void TrackNetwork::addTrack(Track track) {
    lock_guard<mutex> lock(network_mutex);
    tracks.push_back(std::move(track));
}

Track TrackNetwork::findAvailableTrack() {
    lock_guard<mutex> lock(network_mutex);
    for (auto& track : tracks) {
        if (track.requestAccess()) {
            return std::move(track);
        }
    }
    // Return a default track if no track is available
    return Track();
}

vector<Track>& TrackNetwork::getTracks() {
    return tracks;
}

bool TrackNetwork::hasTrack(int track_id) const {
    for (const auto& track : tracks) {
        if (track.getTrackId() == track_id) {
            return true;
        }
    }
    return false;
}