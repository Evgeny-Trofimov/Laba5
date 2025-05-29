#include "tram_system.h"
#include <iostream>

void TramSystem::addTram(const string& tram, const vector<string>& route) {
    trams[tram] = route;
    for (const auto& stop : route) {
        stops[stop].push_back(tram);
    }
}

vector<string> TramSystem::getTrams(const string& stop) {
    return stops.count(stop) ? stops[stop] : vector<string>{};
}

void TramSystem::printRoute(const string& tram) {
    if (!trams.count(tram)) {
        cout << "Stops is absent\n";
        return;
    }

    for (const auto& stop : trams[tram]) {
        cout << "Stop " << stop << ": ";
        bool first = true;
        for (const auto& t : stops[stop]) {
            if (t != tram) {
                if (!first) cout << " ";
                cout << t;
                first = false;
            }
        }
        if (first) cout << "0";
        cout << "\n";
    }
}

void TramSystem::printAll() {
    if (trams.empty()) {
        cout << "Trams is absent\n";
        return;
    }

    for (const auto& [tram, route] : trams) {
        cout << "TRAM " << tram << ": ";
        for (const auto& stop : route) {
            cout << stop << " ";
        }
        cout << "\n";
    }
}
