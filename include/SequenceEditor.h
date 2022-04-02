#ifndef SEQUENCEEDITOR_H
#define SEQUENCEEDITOR_H

#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


class SequenceEditor
{
public:
    SequenceEditor(std::string trackInfo, std::string trackPath);

    bool open();

    virtual ~SequenceEditor();

protected:

private:
    std::string trackInfo;
    std::string trackPath;
    const int WIDTH {700};
    const int HEIGHT {500};
    sf::RenderWindow window;
    sf::Music musicIntro;
    sf::Music music;
    sf::Sprite spriteBg;
    sf::Texture textureControlButtons[4];
    sf::Sprite spriteControlButtons[4];
    float durationLineSize = 1;
    sf::RectangleShape durationLine[2];
    sf::Font font;
    std::string chords;
    sf::RectangleShape btCancel;
    sf::Text textCancel;
    sf::RectangleShape btOk;
    sf::Text textOk;
    sf::RectangleShape weightNote[4];
    bool shift[4];
    std::vector<std::string> vectorNotes;
    std::vector<std::string> vectorNotes2;
    float noteInitialTime = 0;
    float noteFinalTime = 0;
    int tamMinimal = 50;
    sf::Texture textureBg;
    sf::Text textElapsedTime;
    sf::Text textTrackInfo;
    sf::Text textChords;
    char codeABCDE[3]{'a','b','c'};

    bool mouseColision(auto &sprite, sf::RenderWindow& window);
    std::string secToMin(int tempoTotal, int segundos);
};

#endif // SEQUENCEEDITOR_H
