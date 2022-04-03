/***************************************************************
 * Name:      UGS_editorApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Marco Aurélio Lima (marco_aurelio029@hotmail.com)
 * Created:   2022-03-21
 * Copyright: Marco Aurélio Lima (github.com/marcoaurelima)
 * License:
 **************************************************************/

#include "UGS_editorApp.h"


//(*AppHeaders
#include "UGS_editorMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(UGS_editorApp);

bool UGS_editorApp::OnInit()
{
    /*
    std::string trackInfo = "ARTISTA: NIRVANA\nMUSICA:  BREED\nINSTRUMENTO: GUITARRA";
    std::string trackPath = "song.ogg";
    SequenceEditor seqEdit(trackInfo, trackPath);
    seqEdit.open();
    exit(0);
    */

    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	UGS_editorFrame* Frame = new UGS_editorFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
