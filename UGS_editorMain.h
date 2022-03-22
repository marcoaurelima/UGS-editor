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
#include <wx/checkbox.h>
#include <wx/choice.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/statbox.h>
#include <wx/statline.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class UGS_editorFrame: public wxFrame
{
    public:

        UGS_editorFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~UGS_editorFrame();

    private:

        //(*Handlers(UGS_editorFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(UGS_editorFrame)
        static const long ID_STATICTEXT1;
        static const long ID_TEXTCTRL1;
        static const long ID_STATICTEXT2;
        static const long ID_TEXTCTRL2;
        static const long ID_STATICTEXT3;
        static const long ID_CHOICE1;
        static const long ID_STATICTEXT4;
        static const long ID_STATICTEXT5;
        static const long ID_STATICTEXT6;
        static const long ID_TEXTCTRL3;
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_CHECKBOX3;
        static const long ID_CHECKBOX2;
        static const long ID_CHECKBOX1;
        static const long ID_STATICLINE1;
        static const long ID_STATICBOX1;
        static const long ID_PANEL1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        //*)

        //(*Declarations(UGS_editorFrame)
        wxButton* Button1;
        wxButton* Button2;
        wxCheckBox* CheckBox1;
        wxCheckBox* CheckBox2;
        wxCheckBox* CheckBox3;
        wxChoice* Choice1;
        wxPanel* Panel1;
        wxStaticBox* StaticBox1;
        wxStaticLine* StaticLine1;
        wxStaticText* StaticText1;
        wxStaticText* StaticText2;
        wxStaticText* StaticText3;
        wxStaticText* StaticText4;
        wxStaticText* StaticText5;
        wxStaticText* StaticText6;
        wxTextCtrl* TextCtrl1;
        wxTextCtrl* TextCtrl2;
        wxTextCtrl* TextCtrl3;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // UGS_EDITORMAIN_H
