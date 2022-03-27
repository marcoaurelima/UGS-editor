#ifndef PLAYER_H
#define PLAYER_H

#include <wx/stattext.h>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>

enum class Status{ PLAYING, PAUSED, STOPPED };

class Player
{
    public:
        Player();
        virtual ~Player();

        bool openFile(std::string path);
        int getTotalTime();
        std::string getCurrentTime();
        int getCurrentTimeInt();
        Status getMusicStatus();
        void playIntro();
        void play();
        void pause();
        void stop();

    protected:

    private:
        sf::Music intro;
        sf::Music music;
        std::string path;
};

#endif // PLAYER_H
