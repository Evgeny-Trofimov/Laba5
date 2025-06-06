#include "tram_system.h"  
#include <iostream>       

// Добавление трамвая в систему
void TramSystem::addTram(const string& tram, const vector<string>& route) {
    trams[tram] = route;  // Сохранение маршрута трамвая
    // Добавление трамвая во все остановки его маршрута
    for (const auto& stop : route) {
        stops[stop].push_back(tram);
    }
}

// Получение списка трамваев на остановке
vector<string> TramSystem::getTrams(const string& stop) {
    // Возврат списка трамваев или пустого вектора
    return stops.count(stop) ? stops[stop] : vector<string>{};
}

// Вывод маршрута трамвая
void TramSystem::printRoute(const string& tram) {
    // Проверка существования трамвая
    if (!trams.count(tram)) {
        cout << "Stops is absent\n";
        return;
    }

    // Перебор всех остановок маршрута
    for (const auto& stop : trams[tram]) {
        cout << "Stop " << stop << ": ";
        bool first = true;  // Флаг первого элемента
        
        // Вывод других трамваев на этой остановке
        for (const auto& t : stops[stop]) {
            if (t != tram) {  // Исключение текущего трамвая
                if (!first) cout << " ";
                cout << t;
                first = false;
            }
        }
        if (first) cout << "0";  // Если нет других трамваев
        cout << "\n";
    }
}

// Вывод информации о всех трамваях
void TramSystem::printAll() {
    // Проверка наличия трамваев
    if (trams.empty()) {
        cout << "Trams is absent\n";
        return;
    }

    // Перебор всех трамваев
    for (const auto& [tram, route] : trams) {
        cout << "TRAM " << tram << ": ";
        // Вывод маршрута трамвая
        for (const auto& stop : route) {
            cout << stop << " ";
        }
        cout << "\n";
    }
}
