#ifndef SEQUENCEHANDLER_H
#define SEQUENCEHANDLER_H

#include <cstdio>

class SequenceHandler
{
    public:
        SequenceHandler(bool easy, bool medium, bool hard);
        virtual ~SequenceHandler();

        FILE* file;

        void appendTile(float time, char type, float bend);

    protected:

    private:
        bool easy;
        bool medium;
        bool hard;
};

#endif // SEQUENCEHANDLER_H
