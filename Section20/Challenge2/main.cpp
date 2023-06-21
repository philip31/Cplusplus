// Section 20
// Challenge 2
//  Lists

#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include <iomanip>
#include <limits>
#include <algorithm>

class Song {
    friend std::ostream &operator<<(std::ostream &os, const Song &s);
    std::string name;
    std::string artist;
    int rating;
public:
    Song() = default;
    Song(std::string name, std::string artist, int rating)
            : name{name}, artist{artist}, rating{rating} {}
    std::string get_name() const {
        return name;
    }
    std::string get_artist() const {
        return artist;
    }
    int get_rating() const {
        return rating;
    }
    
    bool operator<(const Song &rhs) const  {
        return this->name < rhs.name;
    }
    
    bool operator==(const Song &rhs) const  {
        return this->name == rhs.name;
    }
};

std::ostream &operator<<(std::ostream &os, const Song &s) {
    os << std::setw(20) << std::left << s.name
       << std::setw(30) << std::left << s.artist
       << std::setw(2) << std::left << s.rating;
       return os;
}

void add_song(std::list<Song> &playlist, std::list<Song>::iterator &current_song)
{
    std::cout << "Adding and playing a new song" << std::endl << "Enter a song name: " ;
    std::string name{};
    std::cin.ignore();
    getline(std::cin, name);

    std::cout << "Enter song artist: ";
    std::string artist{};
    getline(std::cin, artist);
    
    std::cout << "Enter your rating: ";
    int rating{};
    std::cin >> rating;
    
    playlist.insert(current_song,Song(name, artist, rating));
    current_song--;
    
}

void display_menu() {
    std::cout << "\nF - Play First Song" << std::endl;
    std::cout << "N - Play Next song" << std::endl;
    std::cout << "P - Play Previous song" << std::endl;
    std::cout << "A - Add and play a new Song at current location" << std::endl;
    std::cout << "L - List the current playlist" << std::endl;
    std::cout << "===============================================" << std::endl;
    std::cout << "Enter a selection (Q to quit): ";
}


void play_current_song(const Song &song) {
    // This function should display 
    // Playing: followed by the song that is playing
    std::cout << "Current Song: " << std::endl;
    std::cout << song << std::endl;
}

void display_playlist(const std::list<Song> &playlist, const Song &current_song) {
    // This function should display the current playlist 
    // and then the current song playing.
    for_each(playlist.begin(), playlist.end(), [](const Song &s) { std::cout << s << std::endl; });
    //play_current_song(current_song);
}

int main() {

    std::list<Song> playlist{
            {"God's Plan",        "Drake",                     5},
            {"Never Be The Same", "Camila Cabello",            5},
            {"Pray For Me",       "The Weekend and K. Lamar",  4},
            {"The Middle",        "Zedd, Maren Morris & Grey", 5},
            {"Wait",              "Maroone 5",                 4},
            {"Whatever It Takes", "Imagine Dragons",           3}          
    };
    
    std::list<Song>::iterator current_song = playlist.begin();
    
    std::cout << "To be implemented" << std::endl;
    // Your program logic goes here
    bool exit{false};
    
    while(!exit)
    {
        display_menu();
        char choice{};
        std::cin >> choice;
        
        switch(toupper(choice))
        {
            case 'F': current_song = playlist.begin(); break;
            
            case 'N': ++current_song; if(current_song == playlist.end()) current_song = playlist.begin(); break;
            
            case 'P': if(current_song == playlist.begin()) current_song = --playlist.end(); else --current_song; break;
            
            case 'A': add_song(playlist, current_song); break;
            
            case 'L': display_playlist(playlist, *current_song); break;
            
            case 'Q': exit = true; break; 
            
            default : std::cout << "Invalid choice" << std::endl; break;
        }
    
        if (choice == 'q' || choice == 'Q')
            break;
            
        play_current_song(*current_song);
    }

    std::cout << "Thanks for listening!" << std::endl;
    return 0;
}