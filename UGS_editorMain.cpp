/***************************************************************
 * Name:      UGS_editorMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Marco Aurélio Lima (marco_aurelio029@hotmail.com)
 * Created:   2022-03-21
 * Copyright: Marco Aurélio Lima (github.com/marcoaurelima)
 * License:
 **************************************************************/

#include "UGS_editorMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(UGS_editorFrame)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/settings.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(UGS_editorFrame)
const long UGS_editorFrame::ID_STATICTEXT10 = wxNewId();
const long UGS_editorFrame::ID_TEXTCTRL4 = wxNewId();
const long UGS_editorFrame::ID_BUTTON4 = wxNewId();
const long UGS_editorFrame::ID_TEXTCTRL5 = wxNewId();
const long UGS_editorFrame::ID_TEXTCTRL6 = wxNewId();
const long UGS_editorFrame::ID_BUTTON5 = wxNewId();
const long UGS_editorFrame::ID_BUTTON6 = wxNewId();
const long UGS_editorFrame::ID_STATICTEXT11 = wxNewId();
const long UGS_editorFrame::ID_STATICTEXT12 = wxNewId();
const long UGS_editorFrame::ID_PANEL2 = wxNewId();
const long UGS_editorFrame::ID_STATICTEXT1 = wxNewId();
const long UGS_editorFrame::ID_TEXTCTRL1 = wxNewId();
const long UGS_editorFrame::ID_STATICTEXT2 = wxNewId();
const long UGS_editorFrame::ID_TEXTCTRL2 = wxNewId();
const long UGS_editorFrame::ID_STATICTEXT3 = wxNewId();
const long UGS_editorFrame::ID_CHOICE1 = wxNewId();
const long UGS_editorFrame::ID_STATICTEXT4 = wxNewId();
const long UGS_editorFrame::ID_STATICTEXT5 = wxNewId();
const long UGS_editorFrame::ID_STATICTEXT6 = wxNewId();
const long UGS_editorFrame::ID_TEXTCTRL3 = wxNewId();
const long UGS_editorFrame::ID_BUTTON1 = wxNewId();
const long UGS_editorFrame::ID_CHECKBOX3 = wxNewId();
const long UGS_editorFrame::ID_CHECKBOX2 = wxNewId();
const long UGS_editorFrame::ID_CHECKBOX1 = wxNewId();
const long UGS_editorFrame::ID_STATICLINE1 = wxNewId();
const long UGS_editorFrame::ID_BUTTON2 = wxNewId();
const long UGS_editorFrame::ID_STATICTEXT7 = wxNewId();
const long UGS_editorFrame::ID_GAUGE1 = wxNewId();
const long UGS_editorFrame::ID_PANEL4 = wxNewId();
const long UGS_editorFrame::ID_STATICTEXT8 = wxNewId();
const long UGS_editorFrame::ID_STATICTEXT9 = wxNewId();
const long UGS_editorFrame::ID_PANEL5 = wxNewId();
const long UGS_editorFrame::ID_PANEL3 = wxNewId();
const long UGS_editorFrame::ID_BUTTON3 = wxNewId();
const long UGS_editorFrame::ID_BUTTON7 = wxNewId();
const long UGS_editorFrame::ID_BUTTON8 = wxNewId();
const long UGS_editorFrame::ID_PANEL1 = wxNewId();
const long UGS_editorFrame::idMenuQuit = wxNewId();
const long UGS_editorFrame::idMenuAbout = wxNewId();
//*)

BEGIN_EVENT_TABLE(UGS_editorFrame,wxFrame)
    //(*EventTable(UGS_editorFrame)
    //*)
END_EVENT_TABLE()

UGS_editorFrame::UGS_editorFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(UGS_editorFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, wxID_ANY, _("Ultimate Guitar Show - Editor"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(961,575));
    Move(wxPoint(-1,-1));
    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(0,8), wxSize(528,494), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    Panel1->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVEBORDER));
    Panel2 = new wxPanel(Panel1, ID_PANEL2, wxPoint(32,90), wxSize(480,430), wxBORDER_DOUBLE|wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    Panel2->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    StaticText10 = new wxStaticText(Panel2, ID_STATICTEXT10, _("Card (148x148)"), wxPoint(50,280), wxDefaultSize, 0, _T("ID_STATICTEXT10"));
    TextCtrl4 = new wxTextCtrl(Panel2, ID_TEXTCTRL4, _("C://files/card"), wxPoint(168,273), wxSize(225,34), 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
    TextCtrl4->Disable();
    Button4 = new wxButton(Panel2, ID_BUTTON4, _("..."), wxPoint(400,272), wxSize(37,34), 0, wxDefaultValidator, _T("ID_BUTTON4"));
    TextCtrl5 = new wxTextCtrl(Panel2, ID_TEXTCTRL5, _("C://files/logo"), wxPoint(168,316), wxSize(225,34), 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
    TextCtrl5->Disable();
    TextCtrl6 = new wxTextCtrl(Panel2, ID_TEXTCTRL6, _("C://files/poster"), wxPoint(168,359), wxSize(225,34), 0, wxDefaultValidator, _T("ID_TEXTCTRL6"));
    TextCtrl6->Disable();
    Button5 = new wxButton(Panel2, ID_BUTTON5, _("..."), wxPoint(400,312), wxSize(39,34), 0, wxDefaultValidator, _T("ID_BUTTON5"));
    Button6 = new wxButton(Panel2, ID_BUTTON6, _("..."), wxPoint(400,360), wxSize(39,34), 0, wxDefaultValidator, _T("ID_BUTTON6"));
    StaticText11 = new wxStaticText(Panel2, ID_STATICTEXT11, _("Logo (246x246)"), wxPoint(45,322), wxDefaultSize, 0, _T("ID_STATICTEXT11"));
    StaticText12 = new wxStaticText(Panel2, ID_STATICTEXT12, _("Poster (1368x769)"), wxPoint(30,364), wxDefaultSize, 0, _T("ID_STATICTEXT12"));
    StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("ULTIMATE GUITAR SHOW EDITOR"), wxPoint(72,40), wxSize(416,40), 0, _T("ID_STATICTEXT1"));
    wxFont StaticText1Font(18,wxFONTFAMILY_TELETYPE,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Nimbus Mono PS"),wxFONTENCODING_DEFAULT);
    StaticText1->SetFont(StaticText1Font);
    TextCtrl1 = new wxTextCtrl(Panel1, ID_TEXTCTRL1, wxEmptyString, wxPoint(136,136), wxSize(336,34), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("Artista"), wxPoint(65,140), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    TextCtrl2 = new wxTextCtrl(Panel1, ID_TEXTCTRL2, wxEmptyString, wxPoint(136,180), wxSize(336,34), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _("Musica"), wxPoint(65,185), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    Choice1 = new wxChoice(Panel1, ID_CHOICE1, wxPoint(176,225), wxSize(296,34), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
    Choice1->Append(_("Guitarra 1"));
    Choice1->Append(_("Guitarra 2"));
    Choice1->Append(_("Baixo"));
    Choice1->Append(_("Bateria"));
    Choice1->Append(_("Sanfona"));
    Choice1->Append(_("Zabumba"));
    Choice1->Append(_("Triangulo"));
    Choice1->Append(_("Sax"));
    Choice1->Append(_("Violao"));
    Choice1->Append(_("Cavaquinho"));
    Choice1->Append(_("Ukulele"));
    Choice1->Append(_("Trompete"));
    Choice1->Append(_("Sampler"));
    Choice1->Append(_("Piano"));
    Choice1->Append(_("Teclado"));
    StaticText4 = new wxStaticText(Panel1, ID_STATICTEXT4, _("Instrumento"), wxPoint(65,230), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    StaticText5 = new wxStaticText(Panel1, ID_STATICTEXT5, _("Dificuldade"), wxPoint(65,280), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    StaticText6 = new wxStaticText(Panel1, ID_STATICTEXT6, _("Audio .ogg"), wxPoint(65,322), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    TextCtrl3 = new wxTextCtrl(Panel1, ID_TEXTCTRL3, _("C://files/audio"), wxPoint(160,320), wxSize(264,34), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    TextCtrl3->Disable();
    Button1 = new wxButton(Panel1, ID_BUTTON1, _("..."), wxPoint(432,320), wxSize(37,34), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    CheckBox3 = new wxCheckBox(Panel1, ID_CHECKBOX3, _("Dificil"), wxPoint(380,280), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX3"));
    CheckBox3->SetValue(false);
    CheckBox2 = new wxCheckBox(Panel1, ID_CHECKBOX2, _("Medio"), wxPoint(285,280), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX2"));
    CheckBox2->SetValue(false);
    CheckBox1 = new wxCheckBox(Panel1, ID_CHECKBOX1, _("Facil"), wxPoint(190,280), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
    CheckBox1->SetValue(false);
    StaticLine1 = new wxStaticLine(Panel1, ID_STATICLINE1, wxPoint(50,65), wxSize(400,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
    Panel3 = new wxPanel(Panel1, ID_PANEL3, wxPoint(536,90), wxSize(400,272), wxBORDER_DOUBLE|wxTAB_TRAVERSAL, _T("ID_PANEL3"));
    Panel3->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    Panel4 = new wxPanel(Panel3, ID_PANEL4, wxPoint(24,24), wxSize(352,87), wxBORDER_DOUBLE|wxTAB_TRAVERSAL, _T("ID_PANEL4"));
    Panel4->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_SCROLLBAR));
    Button2 = new wxButton(Panel4, ID_BUTTON2, _("Play"), wxPoint(16,16), wxSize(63,34), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    StaticText7 = new wxStaticText(Panel4, ID_STATICTEXT7, _("00:00 / 03:34"), wxPoint(104,17), wxSize(176,31), 0, _T("ID_STATICTEXT7"));
    wxFont StaticText7Font(17,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticText7->SetFont(StaticText7Font);
    Gauge1 = new wxGauge(Panel4, ID_GAUGE1, 100, wxPoint(16,41), wxSize(311,28), 0, wxDefaultValidator, _T("ID_GAUGE1"));
    Gauge1->SetValue(65);
    StaticText8 = new wxStaticText(Panel3, ID_STATICTEXT8, _("Acordes:\n  1  A Y\n  2  S U\n  3  D I  \n  4  F O \n  5  G P\n"), wxPoint(40,125), wxSize(64,135), 0, _T("ID_STATICTEXT8"));
    Panel5 = new wxPanel(Panel3, ID_PANEL5, wxPoint(176,136), wxSize(128,111), wxBORDER_DOUBLE|wxTAB_TRAVERSAL, _T("ID_PANEL5"));
    Panel5->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    StaticText9 = new wxStaticText(Panel5, ID_STATICTEXT9, _("1"), wxPoint(42,32), wxSize(55,63), 0, _T("ID_STATICTEXT9"));
    wxFont StaticText9Font(56,wxFONTFAMILY_TELETYPE,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Nimbus Mono PS"),wxFONTENCODING_DEFAULT);
    StaticText9->SetFont(StaticText9Font);
    Button3 = new wxButton(Panel1, ID_BUTTON3, _("Salvar Edicao"), wxPoint(768,480), wxSize(160,34), 0, wxDefaultValidator, _T("ID_BUTTON3"));
    Button7 = new wxButton(Panel1, ID_BUTTON7, _("Reiniciar"), wxPoint(768,384), wxSize(160,34), 0, wxDefaultValidator, _T("ID_BUTTON7"));
    Button8 = new wxButton(Panel1, ID_BUTTON8, _("Cancelar"), wxPoint(768,432), wxSize(160,34), 0, wxDefaultValidator, _T("ID_BUTTON8"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    Center();

    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&UGS_editorFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&UGS_editorFrame::OnAbout);
    //*)
}

UGS_editorFrame::~UGS_editorFrame()
{
    //(*Destroy(UGS_editorFrame)
    //*)
}

void UGS_editorFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void UGS_editorFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}
