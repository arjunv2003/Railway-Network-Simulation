#pragma once
#include <iostream>
#include <string>

using namespace std;

class ColorOutput {
public:
    // ANSI color codes
    static const string RED;
    static const string GREEN;
    static const string YELLOW;
    static const string BLUE;
    static const string RESET;

    // Child-friendly output methods
    static void trainStart(const string& trainName);
    static void trainStop(const string& trainName);
    static void trainMove(const string& trainName, int distance);
    static void stationArrival(const string& trainName, const string& station);
};