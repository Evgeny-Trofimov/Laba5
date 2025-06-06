#pragma once  // Защита от многократного включения

#include <vector>  
#include <string>  
#include <map>     

using namespace std;  

class TramSystem {
    map<string, vector<string>> trams;  // Трамваи и их маршруты
    map<string, vector<string>> stops;  // Остановки и трамваи на них
    
public:
    // Добавление трамвая с маршрутом
    void addTram(const string& tram, const vector<string>& route);
    // Получение трамваев на остановке
    vector<string> getTrams(const string& stop);
    // Вывод маршрута трамвая
    void printRoute(const string& tram);
    // Вывод всех трамваев
    void printAll();
};
