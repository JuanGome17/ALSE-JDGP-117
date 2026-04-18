#include <iostream>
#include <unordered_map>
using namespace std;
class UndergroundSystem {
private:
    unordered_map<int, pair<string, int>> checkInData;
    unordered_map<string, pair<int, int>> travelData;
public:
    UndergroundSystem() {
    }
    void checkIn(int id, string stationName, int t) {
        checkInData[id] = {stationName, t};
    }
    void checkOut(int id, string stationName, int t) {
        auto checkIn = checkInData[id];
        string startStation = checkIn.first;
        int startTime = checkIn.second;
        int travelTime = t - startTime;
        string key = startStation + "-" + stationName;
        travelData[key].first += travelTime; // suma tiempos
        travelData[key].second += 1;         // cuenta viajes
        checkInData.erase(id); // elimina el registro
    }
    double getAverageTime(string startStation, string endStation) {
        string key = startStation + "-" + endStation;
        auto data = travelData[key];
        return (double)data.first / data.second;
    }
};
int main() {
    UndergroundSystem undergroundSystem;
    undergroundSystem.checkIn(1, "A", 3);
    undergroundSystem.checkIn(2, "A", 8);
    undergroundSystem.checkOut(1, "B", 10);
    undergroundSystem.checkOut(2, "B", 15);
    cout << undergroundSystem.getAverageTime("A", "B") << endl;
    return 0;
}