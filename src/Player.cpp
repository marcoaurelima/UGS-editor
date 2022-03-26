#include "Player.h"

Player::Player()
{
    //ctor
}

Player::~Player()
{
    //dtor
}

void Player::openFile(std::string path)
{
    music.openFromFile(path);
}

std::string Player::getCurrentTime()
{
    int time = static_cast<int>(music.getPlayingOffset().asSeconds());

    std::string min = ("00" + std::to_string(time / 60));
    std::string sec = ("00" + std::to_string(time % 60));

    std::stringstream ss;
    ss << min.substr(min.size()-2, min.size()-1) << ":" << sec.substr(sec.size()-2, sec.size()-1);

    return ss.str();

}

void Player::play()
{
    music.play();
}


void Player::pause()
{
    music.pause();
}

void Player::stop()
{
    music.stop();
}
