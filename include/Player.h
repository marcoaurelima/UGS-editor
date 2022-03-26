#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Audio.hpp>

class Player
{
    public:
        Player();
        virtual ~Player();

        void openFile(std::string path);
        void play();
        void pause();
        void stop();

    protected:

    private:
        sf::Music music;
        std::string path;
};

#endif // PLAYER_H
