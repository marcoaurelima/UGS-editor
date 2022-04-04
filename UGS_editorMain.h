/***************************************************************
 * Name:      UGS_editorMain.h
 * Purpose:   Defines Application Frame
 * Author:    Marco Aurélio Lima (marco_aurelio029@hotmail.com)
 * Created:   2022-03-21
 * Copyright: Marco Aurélio Lima (github.com/marcoaurelima)
 * License:
 **************************************************************/

#ifndef UGS_EDITORMAIN_H
#define UGS_EDITORMAIN_H

//(*Headers(UGS_editorFrame)
#include <wx/button.h>
#include <wx/choice.h>
#include <wx/dirdlg.h>
#include <wx/filedlg.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/statline.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

#include <fstream>
#include <random>

#include "Player.h"

#include "SequenceEditor.h"

class UGS_editorFrame: public wxFrame
{
    public:

        UGS_editorFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~UGS_editorFrame();

    private:

        //(*Handlers(UGS_editorFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnButton4Click(wxCommandEvent& event);
        void OnButton5Click(wxCommandEvent& event);
        void OnButton6Click(wxCommandEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        void OnButton3Click(wxCommandEvent& event);
        void OnPanel2Paint(wxPaintEvent& event);
        void OnButton7Click(wxCommandEvent& event);
        void OnTextCtrl7Text(wxCommandEvent& event);
        void OnPanel1KeyUp(wxKeyEvent& event);
        void OnPanel1KeyDown(wxKeyEvent& event);
        void OnKeyDown(wxKeyEvent& event);
        void OnButton2Click1(wxCommandEvent& event);
        void OnButton2Click2(wxCommandEvent& event);
        void OnButton3Click1(wxCommandEvent& event);
        void OnButton7Click1(wxCommandEvent& event);
        //*)

        //(*Identifiers(UGS_editorFrame)
        static const long ID_TEXTCTRL8;
        static const long ID_BUTTON7;
        static const long ID_STATICTEXT7;
        static const long ID_PANEL10;
        static const long ID_STATICTEXT10;
        static const long ID_TEXTCTRL4;
        static const long ID_BUTTON4;
        static const long ID_TEXTCTRL5;
        static const long ID_TEXTCTRL6;
        static const long ID_BUTTON5;
        static const long ID_BUTTON6;
        static const long ID_STATICTEXT11;
        static const long ID_STATICTEXT12;
        static const long ID_TEXTCTRL1;
        static const long ID_TEXTCTRL2;
        static const long ID_CHOICE1;
        static const long ID_TEXTCTRL3;
        static const long ID_STATICTEXT2;
        static const long ID_STATICTEXT3;
        static const long ID_STATICTEXT4;
        static const long ID_STATICTEXT6;
        static const long ID_BUTTON1;
        static const long ID_STATICTEXT5;
        static const long ID_TEXTCTRL7;
        static const long ID_BUTTON2;
        static const long ID_PANEL2;
        static const long ID_STATICTEXT1;
        static const long ID_STATICLINE1;
        static const long ID_BUTTON3;
        static const long ID_PANEL1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        //*)

        //(*Declarations(UGS_editorFrame)
        wxButton* Button1;
        wxButton* Button2;
        wxButton* Button3;
        wxButton* Button4;
        wxButton* Button5;
        wxButton* Button6;
        wxButton* Button7;
        wxChoice* Choice1;
        wxDirDialog* DirDialog1;
        wxFileDialog* FileDialog1;
        wxFileDialog* FileDialog2;
        wxPanel* Panel10;
        wxPanel* Panel1;
        wxPanel* Panel2;
        wxStaticLine* StaticLine1;
        wxStaticText* StaticText10;
        wxStaticText* StaticText11;
        wxStaticText* StaticText12;
        wxStaticText* StaticText1;
        wxStaticText* StaticText2;
        wxStaticText* StaticText3;
        wxStaticText* StaticText4;
        wxStaticText* StaticText5;
        wxStaticText* StaticText6;
        wxStaticText* StaticText7;
        wxTextCtrl* TextCtrl1;
        wxTextCtrl* TextCtrl2;
        wxTextCtrl* TextCtrl3;
        wxTextCtrl* TextCtrl4;
        wxTextCtrl* TextCtrl5;
        wxTextCtrl* TextCtrl6;
        wxTextCtrl* TextCtrl7;
        wxTextCtrl* TextCtrl8;
        //*)

        std::string pathCard;
        std::string pathLogo;
        std::string pathPoster;
        std::string pathAudio;
        std::string audioTotalTime;
        std::string pathOutput;

        DECLARE_EVENT_TABLE()
};

#endif // UGS_EDITORMAIN_H
