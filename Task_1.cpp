#include<iostream>
#include<ctime>
#include<vector>
#include<string>
#include<cassert>

int songIndex = 0;

class AudioPlayer {

    class Treck {
        std::time_t t = std::time(nullptr);
        std::tm * date = localtime(&t);
        int duration = (rand() % 300) + 100;
        std::string song_name = "song#" + std::to_string(songIndex++);
        friend AudioPlayer;
    };

    std::vector<Treck> play_list;
    int now_playing = -1;    
    bool pause_b = true;

    Treck addSong(){        
        std::string temp_name;
        do{            
            std::cout<<"\nEnter song name : ";            
            std::cin>>temp_name;
        } while(search(temp_name) != -1);
        Treck temp;
        std::time_t temp_t = std::time(nullptr);
        temp.date = localtime(&temp_t);
        temp.song_name = temp_name;
        int temp_Duration = 0;
        do {
            std::cout<<"\nEnter song duration : ";
            std::cin>>temp_Duration;
        }while(temp_Duration <= 0);
        temp.duration = temp_Duration;
        return temp;
    }

    int search(const std::string & sf_name) {
        for (int i = 0; i < play_list.size(); ++i) {
            if (sf_name == play_list[i].song_name) {                
                return i;
            }
        }
        return -1;
    }

public:

    void startSong(int i) {
        assert(i > 0);
        play_list.resize(i);
    }

    void next(int i = -1) {
        if (i == -1) {
            now_playing = rand() % play_list.size();
        }
        else {
            now_playing = i;
        }
        std::cout << "\n\tStart playing : ";
        std::cout << "\nSong name : " << play_list[now_playing].song_name;
        std::cout << "\nSong duration : " << play_list[now_playing].duration;
        std::cout << "\nDate created : " << play_list[now_playing].date->tm_mday << "/" << play_list[now_playing].date->tm_mon + 1 << "/" << play_list[now_playing].date->tm_year + 1900;
        pause_b = false;
    }

    void play() {
        if(now_playing == -1) {
            int i = 0;
            std::string sf_name;
            std::cout << "\nEnter song name : ";
            std::cin >> sf_name;
            search(sf_name);
            if(i == -1){
                std::cout << "\nNot found";
            }
            else{
                next(i);
            }            
        }
        else {
            std::cout << "\nAlredy playing song";
        }        
    }

    void pause() {
        if (pause_b && now_playing == -1) {
            std::cout << "\nNothing playing now";
        }
        else if (pause_b) {
            std::cout << "\nAlredy on pause";
        }
        else {
            std::cout << "\nPause playing song";
            pause_b = true;
        }
    }

    void stop() {
        if (now_playing == -1) {
            std::cout << "\nNothing stop";
        }
        else {
            std::cout << "\nStop playing song";
            now_playing = -1;
        }
    }

    void add(){
        play_list.push_back(addSong());
    }

    void deleteSong(){
        std::string sf_name;
        std::cout<<"\nEnter song name you want delete : ";
        std::cin>>sf_name;
        int i = search(sf_name);
        if(i == -1){
            std::cout<<"\nNot found this song"<<std::endl;
        }
        else {
            std::cout<<"\nYou really want delete this song (yes/no) : ";
            std::cin>>sf_name;
            if(sf_name == "yes"){
                std::vector<Treck>::iterator iter = play_list.begin() + i;
                play_list.erase(iter);
                std::cout<<"\nSong been deleted"<<std::endl;
            }
        }
    }
};

int main() {
    int * i = new int (0);
    std::string choice;
    AudioPlayer song;
    std::cout<<"\nHow many songs will be in the player initially : ";
    std::cin>>*i;
    song.startSong(*i);
    delete i;
    while (choice != "exit") {
        std::cout << "\nMake choice\nnext\nplay\npause\nstop\nadd\ndelete\nexir\nEtner : ";
        std::cin >> choice;
        if (choice == "next") {
            song.next();
        }
        else if(choice == "add") {
            song.add();
        }
        else if (choice == "play") {
            song.play();
        }
        else if (choice == "pause") {
            song.pause();
        }
        else if (choice == "stop") {
            song.stop();
        }
        else if(choice == "delete"){
            song.deleteSong();
        }
        else if (choice != "exit") {
            std::cout << "\nWrong option";
        }
    }
}