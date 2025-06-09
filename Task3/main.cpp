#include "tram_system.h"  
#include <iostream>       
#include <vector>         
// Функция разделения строки по пробелам
vector<string> split(const string& s) {
    vector<string> result;  // Вектор для хранения результата
    size_t start = 0, end = s.find(' ');  // Начальная и конечная позиции

    // Цикл поиска пробелов в строке
    while (end != string::npos) {
        // Добавление подстроки в результат
        result.push_back(s.substr(start, end - start));
        start = end + 1;  // Сдвиг начальной позиции
        end = s.find(' ', start);  // Поиск следующего пробела
    }
    // Добавление последней подстроки
    result.push_back(s.substr(start));
    return result;
}

int main() {
    TramSystem system;  // Создание объекта системы трамваев
    string line;  // Переменная для хранения вводимой строки

     cout << "Доступные команды:\nCREATE_TRAM <№Трамвая> <Остановки 1,2,...> - Создание трамвая\nTRAMS_IN_STOP <Остановка> - Вывод всех трамваев, которые проходят через конкретную остановку\n" << "STOPS_IN_TRAM <№Трамвая> - Вывод всех остановок, которые проезжает трамвай\nTRAMS - Отобразить все трамваи с указанием остановок" << endl;
    
    // Основной цикл чтения команд
    while (getline(cin, line)) {
        if (line.empty()) continue;  // Пропуск пустых строк

        auto parts = split(line);  // Разбиение строки на части
        if (parts.empty()) continue;  // Пропуск, если нет команд

        // Обработка команды CREATE_TRAM
        if (parts[0] == "CREATE_TRAM" && parts.size() > 2) {
            // Создание маршрута из оставшихся частей команды
            vector<string> route(parts.begin() + 2, parts.end());
            system.addTram(parts[1], route);  // Добавление трамвая
        }
        // Обработка команды TRAMS_IN_STOP
        else if (parts[0] == "TRAMS_IN_STOP" && parts.size() > 1) {
            // Получение списка трамваев для остановки
            auto trams = system.getTrams(parts[1]);
            if (trams.empty()) cout << "Trams is absent\n";
            else {
                // Вывод всех трамваев через пробел
                for (const auto& t : trams) cout << t << " ";
                cout << "\n";
            }
        }
        // Обработка команды STOPS_IN_TRAM
        else if (parts[0] == "STOPS_IN_TRAM" && parts.size() > 1) {
            system.printRoute(parts[1]);  // Вывод маршрута трамвая
        }
        // Обработка команды TRAMS
        else if (parts[0] == "TRAMS") {
            system.printAll();  // Вывод информации о всех трамваях
        }
    }

    return 0;  // Завершение программы
}
