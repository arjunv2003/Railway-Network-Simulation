#include "color_output.h"

using namespace std;

const string ColorOutput::RED = "\033[1;31m";
const string ColorOutput::GREEN = "\033[1;32m";
const string ColorOutput::YELLOW = "\033[1;33m";
const string ColorOutput::BLUE = "\033[1;34m";
const string ColorOutput::RESET = "\033[0m";

void ColorOutput::trainStart(const string& trainName) {
    cout << GREEN << "🚂 " << trainName << " is starting its journey! Choo choo! 🚂" << RESET << endl;
}

void ColorOutput::trainStop(const string& trainName) {
    cout << YELLOW << "🛑 " << trainName << " has stopped at a station. Rest time! 😴" << RESET << endl;
}

void ColorOutput::trainMove(const string& trainName, int distance) {
    cout << BLUE << "🚉 " << trainName << " is moving " << distance << " kilometers! Zoom zoom! 💨" << RESET << endl;
}

void ColorOutput::stationArrival(const string& trainName, const string& station) {
    cout << RED << "🏁 " << trainName << " has arrived at " << station << " station! Woohoo! 🎉" << RESET << endl;
}