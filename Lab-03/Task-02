/* Name: Fahad Qureshi
 ROll NO: 24K-0824
*/
#include<iostream>
#include<string>
using namespace std;

class FitnessTracker {
    private:
    int DailystepsGoal;
    string Username;
    int steps_taken;
    int CaloriesBurnt;
    int count;
    string Progress[500];
    
    public:
    FitnessTracker() {
        Username = "Laiba";
        steps_taken = 0;
        CaloriesBurnt = 0;
        DailystepsGoal = 15000; //assumed goal
        count = 0;
        Progress[count] = "Journey has started for " + Username + ". Good Luck!";
    }

    void set_steps_taken (int steps) {
        if (steps < 0) {
            cout << "Invalid steps." << endl;
        } else {
        steps_taken = steps;
        count++;
        Progress[count] = to_string(steps) + " steps Has been taken.";
        }
        cout << "\n";
    }

    void TotalCaloriesBurnt() {
        if (steps_taken < 100) {
            cout << "You have to walk more to start burning calories" << endl;
        } else {
            CaloriesBurnt = steps_taken/25; //assuming that a human burns 4 calories per 100 steps
            cout << "You have burnt " << CaloriesBurnt << " Calories so far :))" << endl;
            count++;
            Progress[count] = to_string(CaloriesBurnt) + " has been burnt so far.";
        }
        cout << "\n";
    }

    void Display_progress() {
        cout << "Your progess history is displayed below: " << endl;
        for (int i=0;i<=count;i++) {
            cout << i+1 << ". " << Progress[i] << endl;
        }
        count++;
        Progress[count] = "Progress history was seen.";
        cout << "\n";
    }

    void CheckGoal() {
        if (steps_taken >= DailystepsGoal) {
            cout << "Congratulations " << Username << ". You have met your goal today <3" << endl;
        } else if (steps_taken < DailystepsGoal) {
            cout << "You need " << DailystepsGoal - steps_taken << " more steps to achieve your goal. Keep going!" << endl;
        }
        cout << "\n";
    }
};

int main () {
    FitnessTracker Laiba_Dashboard;
    int opt, steps;
    
while(1) {
    cout << "1. Add steps to the Tracker." << endl;
    cout << "2. View the calories burn." << endl;
    cout << "3. Watch tracking history." << endl;
    cout << "4. See if you have met the goal today." << endl;
    cout << "Choose from one of the above: " << endl;
    cin >> opt;
    switch (opt)
    {
    case 1:
    cout << "Enter the number of steps you have taken so far: ";
    cin >> steps;
    Laiba_Dashboard.set_steps_taken(steps);
    break;
    case 2:
    Laiba_Dashboard.TotalCaloriesBurnt();
    break;
    case 3:
    Laiba_Dashboard.Display_progress();
    break;
    case 4:
    Laiba_Dashboard.CheckGoal();
    break;
    default:
    cout << "Invalid option." << endl;
    break;
    }
  }
    return 0;
}
