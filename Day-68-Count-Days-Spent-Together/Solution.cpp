#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    int countDaysTogether(std::string arriveAlice, std::string leaveAlice,
                          std::string arriveBob, std::string leaveBob) {
        int arriveAliceDay = parseDay(arriveAlice);
        int leaveAliceDay = parseDay(leaveAlice);
        int arriveBobDay = parseDay(arriveBob);
        int leaveBobDay = parseDay(leaveBob);

        int overlapStart = std::max(arriveAliceDay, arriveBobDay);
        int overlapEnd = std::min(leaveAliceDay, leaveBobDay);

        return std::max(0, overlapEnd - overlapStart + 1);
    }

private:
    int parseDay(std::string date) {
        std::vector<int> daysInMonths = {
            31, 28, 31, 30, 31, 30,
            31, 31, 30, 31, 30, 31
        };

        int month = std::stoi(date.substr(0, 2));
        int day = std::stoi(date.substr(3, 2));

        int totalDays = day;

        for (int i = 0; i < month - 1; i++) {
            totalDays += daysInMonths[i];
        }

        return totalDays;
    }
};
