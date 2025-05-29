#include "tram_system.h"
#include <iostream>
#include <vector>

vector<string> split(const string& s) {
    vector<string> result;
    size_t start = 0, end = s.find(' ');

    while (end != string::npos) {
        result.push_back(s.substr(start, end - start));
        start = end + 1;
        end = s.find(' ', start);
                                                        }
    result.push_back(s.substr(start));
    return result;
}

int main() {
    TramSystem system;
    string line;

    while (getline(cin, line)) {
        if (line.empty()) continue;

        auto parts = split(line);
        if (parts.empty()) continue;

        if (parts[0] == "CREATE_TRAM" && parts.size() > 2) {
            vector<string> route(parts.begin() + 2, parts.end());
            system.addTram(parts[1], route);
        }
        else if (parts[0] == "TRAMS_IN_STOP" && parts.size() > 1) {
            auto trams = system.getTrams(parts[1]);
            if (trams.empty()) cout << "Trams is absent\n";
            else {
                for (const auto& t : trams) cout << t << " ";
                cout << "\n";
            }
        }
        else if (parts[0] == "STOPS_IN_TRAM" && parts.size() > 1) {
            system.printRoute(parts[1]);
        }
        else if (parts[0] == "TRAMS") {
            system.printAll();
        }
    }

    return 0;
}
