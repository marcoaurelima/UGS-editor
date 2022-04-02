/***************************************************************
 * Name:      UGS_editorApp.h
 * Purpose:   Defines Application Class
 * Author:    Marco Aurélio Lima (marco_aurelio029@hotmail.com)
 * Created:   2022-03-21
 * Copyright: Marco Aurélio Lima (github.com/marcoaurelima)
 * License:
 **************************************************************/

#ifndef UGS_EDITORAPP_H
#define UGS_EDITORAPP_H

#include <wx/app.h>


#include "include/SequenceEditor.h"

class UGS_editorApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // UGS_EDITORAPP_H
