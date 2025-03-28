#include "station.h"
#include <algorithm>

using namespace std;

Station::Station(string station_name, string station_location)
    : name(station_name), location(station_location), platform_count(3) {}

string Station::getName() const { return name; }
string Station::getLocation() const { return location; }

void Station::addService(string service) {
    available_services.push_back(service);
}

vector<string> Station::getAvailableServices() const {
    return available_services;
}

void StationNetwork::addStation(const Station& station) {
    stations.push_back(station);
}

vector<Station> StationNetwork::getAllStations() const {
    return stations;
}

Station StationNetwork::findNearestStation(string location) const {
    // Simple implementation - in real scenario, use geolocation
    if (!stations.empty()) {
        return stations[0];
    }
    throw runtime_error("No stations available");
}