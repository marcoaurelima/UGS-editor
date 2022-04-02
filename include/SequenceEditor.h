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

    sf::Texture textureBg;
    sf::Text textElapsedTime;
    sf::Text textTrackInfo;
    sf::Text textChords;

    int noteTimeSize = 50; // Bends abaixo desse valor são considerados notas
    float initialTimeBend = 0;
    float finalTimeBend = 0;
    int chordWeight = 1; // Peso do acorde; se for 0 significa que é uma nota e não um acorde.


    bool mouseColision(auto &sprite, sf::RenderWindow& window);
    std::string secToMin(int tempoTotal, int segundos);

    FILE* file;
};

#endif // SEQUENCEEDITOR_H
