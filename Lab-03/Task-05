/* Name: Fahad Qureshi
 ROll NO: 24K-0824
*/
#include<iostream>
#include<string>
using namespace std;

class MusicPlayer {
    private:
    string playlist[500];
    string currentplayingsong;
    int count;

    public:
    MusicPlayer() {
        playlist[0] = "Tiny Light";
        playlist[1] = "Bad Habit";
        playlist[2] = "Heather";
        playlist[3] = "Switch";
        playlist[4] = "Teenage Dream";
        currentplayingsong = "Heather";
        count = 5;
    }

    void addsongs(int n) {
        if (n > 0) {
            cin.ignore();
            for (int i=count;i<(count+n);i++) {
                cout << "Enter the song " << count+1 << " of the playlist: ";
                getline(cin, playlist[i]);
            }
            count += n;
            cout << "The songs have been added successfully!" << endl;
        } else {
            cout << "Invalid number of songs." << endl;
        }
    }

    void remove_songs(int n) {
        string names[n];
        cin.ignore();
        if (n > 0) {
            for (int i=0;i<n;i++) {
                cout << "Enter the name of song " << i+1 << " to be removed: ";
                getline(cin, names[i]);
                for (int j=0;j<count;j++) {
                    if (names[i] == playlist[j]) {
                        for(int k=j;k<count;k++) {
                            if (k < count) {
                                playlist[k] = playlist[k+1];
                            } 
                        }
                        count--;
                        cout << "The song has been successfully removed!" << endl;
                    } 
                }
            }
        } else {
            cout << "Invalid number of songs." << endl;
        }
    }

    void Playsong(string name) {
        for (int i=0;i<count;i++) {
            if (name == playlist[i]) {
                currentplayingsong = name;
                cout << "The song " << name << " is being played." << endl;
            } 
        }
    }

    void displaysongs() {
        cout << "\n-----------------\n";
        if (count == 0) {
            cout << "There are no songs in the playlist!" << endl;
        } else {
        cout << "The songs in the playlist are: " << endl;
        for(int i=0;i<count;i++) {
            cout << i+1 << ". " << playlist[i] << endl;
        }
      }
      cout << "-----------------\n\n";
    }
};

int main () {
    int opt, num;
    string Song_Name;
    MusicPlayer Imran_space;

while(1) {
    cout << "1. Add songs to the playlist." << endl;
    cout << "2. Remove songs from the playlist." << endl;
    cout << "3. Display the playlist." << endl;
    cout << "4. Play a song from the playlist." << endl;
    cout << "Choose from one of the above: " << endl;
    cin >> opt;
    switch (opt)
    {
    case 1:
    cout << "Enter the number of songs to be added: ";
    cin >> num;
    Imran_space.addsongs(num);
    break;
    case 2:
    cout << "Enter the number of songs to be removed: ";
    cin >> num;
    Imran_space.remove_songs(num);
    break;
    case 3:
    Imran_space.displaysongs();
    break;
    case 4:
    cin.ignore();
    cout << "Enter name of the song to be played: ";
    cin >> Song_Name;
    break;
    default:
    cout << "Invalid option." << endl;
    break;
    }
  }
    return 0;
}
