#include "SequenceEditor.h"

SequenceEditor::SequenceEditor(std::string trackInfo, std::string trackPath) : trackInfo(trackInfo), trackPath(trackPath)
{
    window = new sf::RenderWindow(sf::VideoMode(WIDTH,HEIGHT), "ULTIMATE GUITAR SHOW EDITOR", sf::Style::Close);
    sf::Vector2i windowPosition((sf::VideoMode::getDesktopMode().width/2 - WIDTH/2), (sf::VideoMode::getDesktopMode().height/2) - (HEIGHT/2));
    window->setPosition(windowPosition);
    window->setFramerateLimit(50);

    music.openFromFile(trackPath);
    musicIntro.openFromFile("src/intro.audi");

    //sf::Texture textureBg;
    textureBg.loadFromFile("src/ugsbg.png");
    spriteBg.setTexture(textureBg);



    textureControlButtons[0].loadFromFile("src/ugsbtpause.png");
    textureControlButtons[1].loadFromFile("src/ugsbtplay.png");
    textureControlButtons[2].loadFromFile("src/ugsbtstop.png");
    textureControlButtons[3].loadFromFile("src/ugsbtsave.png");


    spriteControlButtons[0].setTexture(textureControlButtons[0]);
    spriteControlButtons[1].setTexture(textureControlButtons[1]);
    spriteControlButtons[2].setTexture(textureControlButtons[2]);
    spriteControlButtons[3].setTexture(textureControlButtons[3]);
    spriteControlButtons[0].setOrigin(spriteControlButtons[0].getLocalBounds().width/2, spriteControlButtons[0].getLocalBounds().height/2);
    spriteControlButtons[1].setOrigin(spriteControlButtons[1].getLocalBounds().width/2, spriteControlButtons[1].getLocalBounds().height/2);
    spriteControlButtons[2].setOrigin(spriteControlButtons[2].getLocalBounds().width/2, spriteControlButtons[2].getLocalBounds().height/2);
    spriteControlButtons[3].setOrigin(spriteControlButtons[3].getLocalBounds().width/2, spriteControlButtons[3].getLocalBounds().height/2);
    spriteControlButtons[0].setPosition(350,330);
    spriteControlButtons[1].setPosition(350,330);
    spriteControlButtons[2].setPosition(410,330);
    spriteControlButtons[3].setPosition(290,330);
    spriteControlButtons[3].setColor(sf::Color(255,255,255,100));


    //float durationLineSize = 1;
    //sf::RectangleShape durationLine[2];
    durationLine[0].setSize(sf::Vector2f(616,15));
    durationLine[1].setSize(sf::Vector2f(durationLineSize,9));
    durationLine[0].setFillColor(sf::Color(0,0,0));
    durationLine[1].setFillColor(sf::Color::Red);
    durationLine[0].setPosition(41,280);
    durationLine[1].setPosition(44,283);


    //sf::Font font;
    font.loadFromFile("Fonts/freemono-bold.ttf");
    //sf::Text textElapsedTime;
    textElapsedTime.setFont(font);
    textElapsedTime.setCharacterSize(17);
    textElapsedTime.setFillColor(sf::Color::White);
    textElapsedTime.setPosition(523,300);
    textElapsedTime.setString("00:00 / 00:00");


    trackInfo="ARTISTA: NIRVANA\nMUSICA:  BREED\nINSTRUMENTO: GUITARRA";
    //sf::Text textTrackInfo;
    textTrackInfo.setFont(font);
    textTrackInfo.setCharacterSize(20);
    textTrackInfo.setFillColor(sf::Color(200,200,200));
    textTrackInfo.setPosition(86,95);
    textTrackInfo.setString(trackInfo);
    textTrackInfo.setLineSpacing(1.5);

    chords="ACORDES:    A-Y:1  S-U:2  D-I:3  F-O:4  ";
    //sf::Text textChords;
    textChords.setFont(font);
    textChords.setCharacterSize(17);
    textChords.setFillColor(sf::Color(200,200,200));
    textChords.setPosition(118,198);
    textChords.setString(chords);

    //sf::RectangleShape btCancel(sf::Vector2f(130,35));
    btCancel.setSize(sf::Vector2f(130,35));
    btCancel.setFillColor(sf::Color(0,0,180,100));
    btCancel.setOutlineColor(sf::Color(0,0,255));
    btCancel.setOutlineThickness(1);
    btCancel.setPosition(50,440);
    //sf::Text textCancel;
    textCancel.setFont(font);
    textCancel.setCharacterSize(22);
    textCancel.setFillColor(sf::Color(200,200,200));
    textCancel.setPosition(60,442);
    textCancel.setString("CANCELAR");

    //sf::RectangleShape btOk(sf::Vector2f(130,35));
    btOk.setSize(sf::Vector2f(130,35));
    btOk.setFillColor(sf::Color(0,110,0,100));
    btOk.setOutlineColor(sf::Color(0,160,0));
    btOk.setOutlineThickness(1);
    btOk.setPosition(520,440);
    //sf::Text textOk;
    textOk.setFont(font);
    textOk.setCharacterSize(22);
    textOk.setFillColor(sf::Color(200,200,200));
    textOk.setPosition(570,442);
    textOk.setString("OK");

    //sf::RectangleShape weightNote[4];
    for(unsigned i=0; i<4; i++)
    {
        weightNote[i].setSize(sf::Vector2f(80,25));
        weightNote[i].setFillColor(sf::Color(255,255,0, 80));
        weightNote[i].setOutlineColor(sf::Color::Blue);
        weightNote[i].setOutlineThickness(1);
        weightNote[i].setPosition((85 * i) + 185, 370);
    }

    //bool shift[3];
    shift[0]=false;
    shift[1]=false;
    shift[2]=false;

}

bool SequenceEditor::mouseColision(auto &sprite, sf::RenderWindow* window)
{
    /*
    auto mouse_pos = sf::Mouse::getPosition(&window);
    auto translated_pos = window->mapPixelToCoords(mouse_pos);
    if(sprite.getGlobalBounds().contains(translated_pos))
    {
        return true;
    }
    else
    {
        return false;
    }
    */
    return false;

}

std::string SequenceEditor::segundosParaminutos(int tempoTotal, int segundos)
{
    std::stringstream ss;
    //ss << segundos/60 << ":" << segundos%60 << " / " << tempoTotal/60 << ":" << tempoTotal%60;

    if(segundos%60 <10)
    {
        ss << "0" << segundos/60 << ":" << "0" << segundos%60;
    }
    else
    {
        ss << "0" << segundos/60 << ":" << segundos%60;
    }

    ss << " / ";

    if(tempoTotal%60 <10)
    {
        ss << "0" << tempoTotal/60 << ":" << "0" << tempoTotal%60;
    }
    else
    {
        ss << "0" << tempoTotal/60 << ":" << tempoTotal%60;
    }

    return ss.str();
}


bool SequenceEditor::open()
{

    while(window->isOpen())
    {
        sf::Event e;
        while(window->pollEvent(e))
        {
            if(e.type == sf::Event::Closed)
            {
                window->close();
            }

            if(e.type == sf::Event::MouseButtonReleased)
            {
                if(mouseColision(spriteControlButtons[1], window))
                {
                    if(music.getStatus() == 0 || music.getStatus() == 1)
                    {
                        spriteControlButtons[1].setColor(sf::Color(255,255,255,0));
                        if(music.getStatus()==0)
                        {
                            musicIntro.play();
                        }
                        else
                        {
                            music.play();
                        }

                    }
                    else if(music.getStatus() == 2)
                    {
                        spriteControlButtons[1].setColor(sf::Color(255,255,255,255));
                        music.pause();
                    }
                }
                else if(mouseColision(spriteControlButtons[2], window))
                {
                    spriteControlButtons[1].setColor(sf::Color(255,255,255,255));
                    music.stop();
                    musicIntro.stop();
                }
                else if(mouseColision(spriteControlButtons[3], window))
                {
                    if(spriteControlButtons[3].getColor().a != 100)
                    {
                        std::cout << "Botão salvar...\n";
                    }

                    spriteControlButtons[3].setColor(sf::Color(255,255,255,100));
                }

                if(mouseColision(btCancel, window))
                {
                    exit(0);
                }

                if(mouseColision(btOk, window))
                {
                    exit(0);
                }

            }

            if(e.type == sf::Event::MouseMoved)
            {

                if(mouseColision(btCancel, window))
                {

                    btCancel.setFillColor(sf::Color(0,0,180,255));
                }
                else
                {
                    btCancel.setFillColor(sf::Color(0,0,180,100));
                }

                if(mouseColision(btOk, window))
                {
                    btOk.setFillColor(sf::Color(0,110,0,255));
                }
                else
                {
                    btOk.setFillColor(sf::Color(0,110,0,100));
                }
            }

        }


        if(musicIntro.getStatus()==2)
        {
            durationLine[1].setFillColor(sf::Color(255,100,0));
            durationLine[1].setSize(sf::Vector2f(durationLineSize,9));
            durationLineSize = ((610/musicIntro.getDuration().asSeconds()) * musicIntro.getPlayingOffset().asSeconds());
        }

        if(musicIntro.getPlayingOffset().asSeconds() > musicIntro.getDuration().asSeconds()-0.05)  /// 0.5 serve para entrar na condicional. musica so toca quando a intro termina
        {
            music.play();
            durationLine[1].setFillColor(sf::Color(0,153,51));
        }

        durationLine[1].setSize(sf::Vector2f(durationLineSize,9));
        durationLineSize = ((610/music.getDuration().asSeconds()) * music.getPlayingOffset().asSeconds());
        if(durationLineSize > 609 && music.getStatus() == 2)  /// troca o icone de pause por play
        {
            spriteControlButtons[1].setColor(sf::Color(255,255,255,255));
            music.stop();
            musicIntro.stop();
        }


        textElapsedTime.setString(segundosParaminutos(music.getDuration().asSeconds(), music.getPlayingOffset().asSeconds()));

        window->clear();
        window->draw(spriteBg);
        window->draw(durationLine[0]);
        window->draw(durationLine[1]);
        window->draw(spriteControlButtons[0]);
        window->draw(spriteControlButtons[1]);
        window->draw(spriteControlButtons[2]);
        window->draw(spriteControlButtons[3]);
        window->draw(textElapsedTime);
        window->draw(textTrackInfo);
        window->draw(textChords);

        window->draw(btCancel);
        window->draw(btOk);
        window->draw(textCancel);
        window->draw(textOk);

        window->draw(weightNote[0]);
        window->draw(weightNote[1]);
        window->draw(weightNote[2]);
        window->draw(weightNote[3]);

        window->display();
    }
}

SequenceEditor::~SequenceEditor()
{
    delete(window);
    //dtor
}
