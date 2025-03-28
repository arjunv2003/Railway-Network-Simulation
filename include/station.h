#pragma once
#include <string>
#include <vector>

using namespace std;

class Station {
private:
    string name;
    string location;
    int platform_count;
    vector<string> available_services;

public:
    Station(string station_name, string station_location);
    
    string getName() const;
    string getLocation() const;
    void addService(string service);
    vector<string> getAvailableServices() const;
};

class StationNetwork {
private:
    vector<Station> stations;

public:
    void addStation(const Station& station);
    vector<Station> getAllStations() const;
    Station findNearestStation(string location) const;
};