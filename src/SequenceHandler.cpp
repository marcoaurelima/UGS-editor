#include "SequenceHandler.h"

SequenceHandler::SequenceHandler(bool easy, bool medium, bool hard) : easy(easy), medium(medium), hard(hard)
{
    file = fopen("sequence.TMP", "w");
    //ctor
}

SequenceHandler::~SequenceHandler()
{
    fclose(file);
    //dtor
}

void SequenceHandler::appendTile(float time, char type, float bend)
{

}
