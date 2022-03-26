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
