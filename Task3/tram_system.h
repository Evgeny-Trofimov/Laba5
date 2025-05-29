#pragma once
#include <vector>
#include <string>
#include <map>

using namespace std;

class TramSystem {
    map<string, vector<string>> trams;
    map<string, vector<string>> stops;
    public:
        void addTram(const string& tram, const vector<string>& route);
        vector<string> getTrams(const string& stop);
        void printRoute(const string& tram);
        void printAll();
};
