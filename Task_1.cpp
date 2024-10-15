#include<iostream>
#include<ctime>
#include<vector>
#include<string>

class AudioPlayer {

    class Treck {
        std::time_t t = std::time(nullptr);
        std::tm * date = localtime(&t);
        int duration = (rand() % 300) + 100;
        std::string song_name = "song#" + std::to_string(rand() % 50);
        friend AudioPlayer;
    };

    std::vector<Treck> play_list;
    int now_playing = -1;    
    bool pause_b = true;

public:

    void add_song() {
        play_list.resize(15);
    }

    void next(int i = 0) {
        if (i == 0) {
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
            std::string sf_name;
            std::cout << "\nEnter song name : ";
            std::cin >> sf_name;
            for (int i = 0; i < play_list.size(); ++i) {
                if (sf_name == play_list[i].song_name) {
                    next(i);
                    return;
                }
            }
            std::cout << "\nNot found";
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
};

int main() {
    std::string choice;
    AudioPlayer song;
    song.add_song();
    while (choice != "exit") {
        std::cout << "\nMake choice\nnext\nplay\npause\nstop\nexir\nEtner : ";
        std::cin >> choice;
        if (choice == "next") {
            song.next();
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
        else if (choice != "exit") {
            std::cout << "\nWrong option";
        }
    }
}