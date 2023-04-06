#include "Playlist.h"
#include <iostream>
using namespace std;

//PlaylistNode Definitions//

/*Default Constructor*/
PlaylistNode::PlaylistNode(){
    uniqueID = "none";
    songName = "none";
    artistName = "none";
    songLength = 0;
    nextNodePtr = nullptr;
}

/*Parameterized Constructor*/
PlaylistNode::PlaylistNode(string id, string song, string artist, int length){
    uniqueID = id;
    songName = song;
    artistName = artist;
    songLength = length;
    nextNodePtr = nullptr;
}

/*Inserts song after current node*/
void PlaylistNode::InsertAfter(PlaylistNode *node){
    node->SetNext(this->GetNext());
    this->SetNext(node);
}

/*Sets next node to parameter*/
void PlaylistNode::SetNext(PlaylistNode *next){
    nextNodePtr = next;
}
/*Returns song ID*/
string PlaylistNode::GetID() const{
    return uniqueID;
}

/*Returns song name*/
string PlaylistNode::GetSongName() const{
    return songName;
}

/*Returns artist name*/
string PlaylistNode::GetArtistName() const{
    return artistName;
}

/*Returns song length*/
int PlaylistNode::GetSongLength() const{
    return songLength;
}

/*Returns next song node*/
PlaylistNode* PlaylistNode::GetNext() const{
    return nextNodePtr;
}

/*Prints out attributes of playlistNode*/
void PlaylistNode::PrintPlaylistNode(){
    cout << "Unique ID: " << uniqueID << endl
     << "Song Name: " << songName << endl
     << "Artist Name: " << artistName << endl
     << "Song Length (in seconds): " << songLength << endl;
}


//Playlist Definitions//

/*Playlist constructor*/
Playlist::Playlist(){
    head = nullptr;
    tail = nullptr;
}

/*Playlist deconstructor*/
Playlist::~Playlist(){  
    PlaylistNode *curr = head;
    while(curr != nullptr){
        PlaylistNode *next = curr->GetNext();
        delete curr;
        curr = next;
    }
    head = nullptr;
    tail = nullptr;
}

/*Checks if playlist is empty or not*/
bool Playlist::IsEmpty(){
    return (head==nullptr);
}

/*Adds song to end of playlist,*/
void Playlist::AddSong(string id, string song, string artist, int length){
    PlaylistNode *temp = new PlaylistNode(id, song, artist, length);
    if(head == nullptr){
        head = temp;
        tail = temp;
    } else {
        tail->SetNext(temp);
        tail = temp;
    }
}

/*Removes song from playlist given an ID*/
void Playlist::RemoveSong(string id){
    if(head->GetID() == id){ //special case for front node
        cout << "\"" << head->GetSongName() << "\" removed." << endl;
        PlaylistNode *temp = head;
        head = nullptr;
        tail = nullptr;
        delete temp;
    } else { 
        PlaylistNode *prev = head;
        PlaylistNode *curr = head->GetNext();
        while(curr != nullptr){
            if(curr->GetID() == id){
                cout << "\"" << curr->GetSongName() << "\" removed." << endl;
                prev->SetNext(curr->GetNext());
                delete curr;
                curr = prev->GetNext();
                return;
            }
            prev = prev->GetNext();
            curr = curr->GetNext();
        }
    }
}

/*Returns number of node objects within the list*/
int Playlist::NumberOfNodes() const{
    int num = 0;
    PlaylistNode *curr = head;
    if(head == nullptr){
        return 0;
    } else {
        while(curr != nullptr){
            num++;
            curr = curr->GetNext();
        }
    }
    return num;
}

/*Changes position of node to desired index*/
void Playlist::ChangePosition(int fromIndex, int toIndex){
    if(fromIndex < 1 || fromIndex > this->NumberOfNodes() || fromIndex == toIndex){
        return;
    }

    //Finds locations of nodes before fromIndex and at fromIndex
    PlaylistNode *curr1 = head; //Node at fromIndex
    PlaylistNode *prev1 = nullptr; //previous of curr1 node
    int counter = 1;
    while(counter < fromIndex){
        if(curr1 != nullptr){
            prev1 = curr1;
            curr1 = curr1->GetNext();
            counter++;
        }
    }

    //Finds location of nodes before toIndex and at fromIndex
    counter = 1; 
    PlaylistNode *curr2 = head; //Node at toIndex
    PlaylistNode *prev2 = nullptr; //previous of curr2 node
    while(counter < toIndex){
        if(curr1 != nullptr){
            prev2 = curr2;
            curr2 = curr2->GetNext();
            counter++;
        }
    }

    //Connects node before fromIndex to node after fromIndex
    if(prev1 != nullptr){
        prev1->SetNext(curr1->GetNext()); 
    } else {
        head = curr1->GetNext();
    }
    if(curr1 == tail){
        tail = prev1;
    }

    //Moves fromIndex node to the toIndex node location
    if(toIndex <= 1){
        curr1->SetNext(head);
        head = curr1;
        cout << "\"" << curr1->GetSongName() << "\"" << " moved to position " << toIndex << endl << endl;
    } else {
        if(toIndex < fromIndex){
            curr1->SetNext(curr2);
            prev2->SetNext(curr1);
        } else {
            curr2->InsertAfter(curr1);
            if(curr1->GetNext() == nullptr){
                tail = curr1;
            }
        }
        cout << "\"" << curr1->GetSongName() << "\"" << " moved to position " << toIndex << endl << endl;
    }
}

/*Prints out each node in playlist*/
void Playlist::PrintPlaylist(){
    if(IsEmpty()){
        cout << "Playlist is empty" << endl << endl;
        return;
    }
    PlaylistNode *curr = head;
    int i = 1;
    while(curr != nullptr){
        cout << i << "." << endl; 
        curr->PrintPlaylistNode(); 
        cout << endl;

        curr = curr->GetNext(); 
        i++;
    }
}

/*Prints out the songs from specified artist*/
void Playlist::PrintSpecificArtist(string artistName){
    PlaylistNode *curr = head;
    int i = 1;
    while(curr != nullptr){
        if(curr->GetArtistName() == artistName){
            cout << i << "." << endl; 
            curr->PrintPlaylistNode(); 
            cout << endl;
        }
        curr = curr->GetNext(); 
        i++;
    }
}

/*Returns total time of playlist in seconds */
int Playlist::TotalTime() const{
    PlaylistNode *curr = head;
    int totalTime = 0;
    while(curr != nullptr){
        totalTime += curr->GetSongLength();
        curr = curr->GetNext();
    }
    return totalTime;
}


