#include <iostream>
#include <vector>
using namespace std;
class ExamTracker {
private:
    vector<pair<int, int>> exam;
public:
    ExamTracker() {
    }
    void record(int time, int score) {
        exam.push_back({time, score});
    }
    long long totalScore(int startTime, int endTime) {
            long long total= 0;
            for (auto  &exams : exam){
                if(exams.first >= startTime && exams.first <= endTime){
                    total += exams.second;
                }
            }
            return total;
    }
};
int main() {
    ExamTracker tracker;
    tracker.record(1, 85);
    tracker.record(2, 90);
    tracker.record(3, 78);
    cout << "Total score from time 1 to 2: " << tracker.totalScore(1, 2) << endl;
    cout << "Total score from time 1 to 3: " << tracker.totalScore(1, 3) << endl;
    cout << "Total score from time 2 to 3: " << tracker.totalScore(2, 3) << endl;
    return 0;
}