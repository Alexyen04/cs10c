#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <iostream>

using namespace std;

class PlaylistNode {
    public:
        PlaylistNode();
        PlaylistNode(string, string, string, int);
        void InsertAfter(PlaylistNode*);
        void SetNext(PlaylistNode*);
        string GetID() const;
        string GetSongName() const;
        string GetArtistName() const;
        int GetSongLength() const;
        PlaylistNode* GetNext() const;
        void PrintPlaylistNode();
    private:
        string uniqueID;
        string songName;
        string artistName;
        int songLength;
        PlaylistNode *nextNodePtr;
};

class Playlist {
    private:
        PlaylistNode *head;
        PlaylistNode *tail;
    public: 
        Playlist();
        ~Playlist();
        bool IsEmpty();
        void AddSong(string, string, string, int);
        void RemoveSong(string);
        int NumberOfNodes() const;
        void ChangePosition(int, int);
        void PrintPlaylist();
        void PrintSpecificArtist(string);
        int TotalTime() const;

    
};

#endif 