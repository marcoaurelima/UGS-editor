#include "../include/SequenceEditor.h"

SequenceEditor::SequenceEditor(std::string trackInfo, std::string trackPath) : trackInfo(trackInfo), trackPath(trackPath)
{
    window.create(sf::VideoMode(WIDTH,HEIGHT), "ULTIMATE GUITAR SHOW EDITOR", sf::Style::Close);
    sf::Vector2i windowPosition((sf::VideoMode::getDesktopMode().width/2 - WIDTH/2), (sf::VideoMode::getDesktopMode().height/2) - (HEIGHT/2));
    window.setPosition(windowPosition);
    window.setFramerateLimit(50);

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


    //trackInfo="ARTISTA: NIRVANA\nMUSICA:  BREED\nINSTRUMENTO: GUITARRA";
    //sf::Text textTrackInfo;
    textTrackInfo.setFont(font);
    textTrackInfo.setCharacterSize(20);
    textTrackInfo.setFillColor(sf::Color(200,200,200));
    textTrackInfo.setPosition(86,95);
    textTrackInfo.setString(trackInfo);
    textTrackInfo.setLineSpacing(1.5);

    chords="ACORDES:    A-U:1  S-I:2  D-O:3  F-P:4  ";
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
        weightNote[i].setFillColor(sf::Color(0,255,0, 80));
        weightNote[i].setOutlineColor(sf::Color(0,100,0, 200));
        weightNote[i].setOutlineThickness(2);
        weightNote[i].setPosition((85 * i) + 185, 370);
    }

    //bool shift[3];
    shift[0] = true;
    shift[1] = true;
    shift[2] = true;
    shift[3] = true;

    remove("exports/brute-sequence.txt");
}

bool SequenceEditor::mouseColision(auto &sprite, sf::RenderWindow& window)
{
    auto mouse_pos = sf::Mouse::getPosition(window);
    auto translated_pos = window.mapPixelToCoords(mouse_pos);
    if(sprite.getGlobalBounds().contains(translated_pos))
    {
        return true;
    }
    return false;
}

std::string SequenceEditor::secToMin(int tempoTotal, int segundos)
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

    while(window.isOpen())
    {
        sf::Event e;
        while(window.pollEvent(e))
        {
            if(e.type == sf::Event::Closed)
            {
                window.close();
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                window.close();
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
                    bruteSequence.clear();
                }
                else if(mouseColision(spriteControlButtons[3], window))
                {
                    if(spriteControlButtons[3].getColor().a != 100)
                    {
                        std::ofstream file("exports/brute-sequence.txt");
                        file << bruteSequence.str();
                        file.close();
                    }

                    spriteControlButtons[3].setColor(sf::Color(255,255,255,100));
                }

                if(mouseColision(btCancel, window))
                {
                    remove("exports/brute-sequence.txt");
                    return false;
                }

                if(mouseColision(btOk, window))
                {
                    return true;
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

            if(e.type == sf::Event::KeyPressed)
            {
                if((sf::Keyboard::isKeyPressed(sf::Keyboard::A) ||
                        sf::Keyboard::isKeyPressed(sf::Keyboard::U)) && shift[0])
                {
                    //std::cout << "Botao A pressionado...\n";
                    shift[0] = false;
                    weightNote[0].setFillColor(sf::Color(0, 255,0,255));

                    initialTimeBend = music.getPlayingOffset().asSeconds();
                    chordWeight = 1;
                    //fprintf(file, "%f %d %f", )
                }
                else if((sf::Keyboard::isKeyPressed(sf::Keyboard::S) ||
                         sf::Keyboard::isKeyPressed(sf::Keyboard::I)) && shift[1])
                {
                    //std::cout << "Botao S pressionado...\n";
                    shift[1] = false;
                    weightNote[0].setFillColor(sf::Color(0, 255,0,255));
                    weightNote[1].setFillColor(sf::Color(0, 255,0,255));

                    initialTimeBend = music.getPlayingOffset().asSeconds();
                    chordWeight = 2;
                }
                else if((sf::Keyboard::isKeyPressed(sf::Keyboard::D) ||
                         sf::Keyboard::isKeyPressed(sf::Keyboard::O)) && shift[2])
                {
                    //std::cout << "Botao D pressionado...\n";
                    shift[2] = false;
                    weightNote[0].setFillColor(sf::Color(0, 255,0,255));
                    weightNote[1].setFillColor(sf::Color(0, 255,0,255));
                    weightNote[2].setFillColor(sf::Color(0, 255,0,255));

                    initialTimeBend = music.getPlayingOffset().asSeconds();
                    chordWeight = 3;
                }
                else if((sf::Keyboard::isKeyPressed(sf::Keyboard::F) ||
                         sf::Keyboard::isKeyPressed(sf::Keyboard::P)) && shift[3])
                {
                    //std::cout << "Botao F pressionado...\n";
                    shift[3] = false;
                    weightNote[0].setFillColor(sf::Color(0, 255,0,255));
                    weightNote[1].setFillColor(sf::Color(0, 255,0,255));
                    weightNote[2].setFillColor(sf::Color(0, 255,0,255));
                    weightNote[3].setFillColor(sf::Color(0, 255,0,255));

                    initialTimeBend = music.getPlayingOffset().asSeconds();
                    chordWeight = 4;
                }
            }

            if(e.type == sf::Event::KeyReleased)
            {
                if(music.getStatus() == sf::SoundSource::Playing)
                {
                    const float SAFE_MARGIN = 0.15; // Margem de segurança para os bends não atropelarem uns aos outros

                    finalTimeBend = music.getPlayingOffset().asSeconds();

                    bruteSequence << initialTimeBend << " " << chordWeight << " " << ((finalTimeBend - initialTimeBend)-SAFE_MARGIN) << "\n";

                    //std::cout << initialTimeBend << " " << chordWeight << " " << (finalTimeBend - initialTimeBend) << "\n";
                }

                // Botão "Salvar"
                spriteControlButtons[3].setColor(sf::Color(255,255,255,255));

                shift[0] = true;
                shift[1] = true;
                shift[2] = true;
                shift[3] = true;
                weightNote[0].setFillColor(sf::Color(0, 255,0,80));
                weightNote[1].setFillColor(sf::Color(0, 255,0,80));
                weightNote[2].setFillColor(sf::Color(0, 255,0,80));
                weightNote[3].setFillColor(sf::Color(0, 255,0,80));
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

        textElapsedTime.setString(secToMin(music.getDuration().asSeconds(), music.getPlayingOffset().asSeconds()));

        window.clear();
        window.draw(spriteBg);
        window.draw(durationLine[0]);
        window.draw(durationLine[1]);
        window.draw(spriteControlButtons[0]);
        window.draw(spriteControlButtons[1]);
        window.draw(spriteControlButtons[2]);
        window.draw(spriteControlButtons[3]);
        window.draw(textElapsedTime);
        window.draw(textTrackInfo);
        window.draw(textChords);

        window.draw(btCancel);
        window.draw(btOk);
        window.draw(textCancel);
        window.draw(textOk);

        window.draw(weightNote[0]);
        window.draw(weightNote[1]);
        window.draw(weightNote[2]);
        window.draw(weightNote[3]);

        window.display();
    }

    return false;
}

SequenceEditor::~SequenceEditor()
{
    //dtor
}
