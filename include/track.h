#pragma once
#include <string>
#include <vector>
#include <mutex>

using namespace std;

class Track {
private:
    int track_id;
    string track_name;
    bool is_occupied;
    mutex track_mutex;

public:
    // Default constructor
    Track() : track_id(0), track_name(""), is_occupied(false) {}
    
    // Parameterized constructor
    Track(int id, string name);
    
    // Move constructor
    Track(Track&& other) noexcept;
    
    // Move assignment operator
    Track& operator=(Track&& other) noexcept;
    
    // Deleted copy constructors
    Track(const Track&) = delete;
    Track& operator=(const Track&) = delete;
    
    bool requestAccess();
    void releaseAccess();
    string getTrackName() const;
    int getTrackId() const;
};

class TrackNetwork {
private:
    vector<Track> tracks;
    mutex network_mutex;

public:
    // Add track method
    void addTrack(Track track);
    
    // Find available track
    Track findAvailableTrack();
    
    // Get all tracks
    vector<Track>& getTracks();
    
    // Check if track exists
    bool hasTrack(int track_id) const;
};