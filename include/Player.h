#ifndef PLAYER_H
#define PLAYER_H

#include <wx/stattext.h>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>

class Player
{
    public:
        Player();
        virtual ~Player();

        bool openFile(std::string path);
        int getTotalTime();
        std::string getCurrentTime();
        int getCurrentTimeInt();
        void play();
        void pause();
        void stop();

    protected:

    private:
        sf::Music music;
        std::string path;
};

#endif // PLAYER_H
