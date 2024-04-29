#include<bits/stdc++.h>
using namespace std;

class Stopwatch {
private:
    bool isRunning;
    chrono::time_point<chrono::steady_clock> startTime;
    stack<double> lapTimesStack;
    queue<double> lapTimesQueue;

public:
    Stopwatch() : isRunning(false) {}

    void start() {
        isRunning = true;
        startTime = chrono::steady_clock::now();
    }

    void stop() {
        if (!isRunning) {
            cout << "Stopwatch is not running.\n";
            return;
        }
        auto endTime = chrono::steady_clock::now();
        chrono::duration<double> elapsedTime = endTime - startTime;
        double lapTime = elapsedTime.count();
        lapTimesStack.push(lapTime);
        lapTimesQueue.push(lapTime);
        isRunning = false;
        cout << "Stopped. Lap time: " << lapTime << " seconds.\n";
    }

    void reset() {
        while (!lapTimesStack.empty()) lapTimesStack.pop();
        while (!lapTimesQueue.empty()) lapTimesQueue.pop();
        cout << "Stopwatch reset.\n";
    }

    void recordLap() {
        if (!isRunning) {
            cout << "Stopwatch is not running.\n";
            return;
        }
        auto endTime = chrono::steady_clock::now();
        chrono::duration<double> elapsedTime = endTime - startTime;
        double lapTime = elapsedTime.count();
        lapTimesStack.push(lapTime);
        lapTimesQueue.push(lapTime);
        cout << "Lap recorded: " << lapTime << " seconds.\n";
    }

    void displayLapTimes() {
        cout << "Lap times (Stack): ";
        while (!lapTimesStack.empty()) {
            cout << lapTimesStack.top() << " ";
            lapTimesStack.pop();
        }
        cout << "\n";

        cout << "Lap times (Queue): ";
        while (!lapTimesQueue.empty()) {
            cout << lapTimesQueue.front() << " ";
            lapTimesQueue.pop();
        }
        cout << "\n";
    }
};

int main() {
    Stopwatch stopwatch;
    int choice;
    do {
        cout << "1. Start\n2. Stop\n3. Reset\n4. Record Lap\n5. Display Lap Times\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                stopwatch.start();
                break;
            case 2:
                stopwatch.stop();
                break;
            case 3:
                stopwatch.reset();
                break;
            case 4:
                stopwatch.recordLap();
                break;
            case 5:
                stopwatch.displayLapTimes();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 6);

    return 0;
}
