#include <iostream>
#include "Playlist.h"

using namespace std;

void PrintMenu(string);

int main(){
    string title;
    cout << "Enter playlist's title:" << endl;
    getline(cin, title);
    cout << endl;

    Playlist test;
    bool loop = true;
    char input = ' ';
    string id;
    string song;
    string artist;
    int length;
    int pos1, pos2;
    PrintMenu(title); 
    while(loop){
        cin >> input;
        switch(input){
            case 'a':
                cout << "ADD SONG" << endl << "Enter song's unique ID:" << endl;
                cin >> id;
                cout << "Enter song's name:" << endl; cin.ignore();
                getline(cin, song);
                cout << "Enter artist's name:" << endl;
                getline(cin, artist);
                cout << "Enter song's length (in seconds):" << endl;
                cin >> length; cout << endl;
                test.AddSong(id, song, artist,length);
                PrintMenu(title);
                break;
            case 'd':
                cout << "REMOVE SONG" << endl
                    << "Enter song's unique ID:" << endl;
                cin >> id;
                test.RemoveSong(id);
                cout << endl;
                PrintMenu(title);
                break;
            case 'c': 
                cout << "CHANGE POSITION OF SONG" << endl
                    << "Enter song's current position:" << endl;
                cin >> pos1;
                cout<< "Enter new position for song:" << endl;
                cin >> pos2;
                test.ChangePosition(pos1,pos2);
                PrintMenu(title);
                break;
            case 's': 
                cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl
                    << "Enter artist's name:" << endl; cin.ignore();
                getline(cin, artist); cout << endl;
                test.PrintSpecificArtist(artist);
                PrintMenu(title);
                break;
            case 't':
                cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl 
                    << "Total time: " << test.TotalTime() << " seconds" << endl << endl;
                PrintMenu(title);
                break;
            case 'o':
                cout << title << " - OUTPUT FULL PLAYLIST" << endl;
                test.PrintPlaylist();
                PrintMenu(title);
                break;
            case 'q':
                loop = false;
                break;
            default: 
                PrintMenu(title);
        }
    }
    return 0;
}



void PrintMenu(string title){
    cout << title << " PLAYLIST MENU" << endl
        << "a - Add song" << endl
        << "d - Remove song" << endl 
        << "c - Change position of song" << endl
        << "s - Output songs by specific artist" << endl
        << "t - Output total time of playlist (in seconds)" << endl
        << "o - Output full playlist" << endl
        << "q - Quit" << endl << endl
        << "Choose an option:" << endl;
}