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
const long UGS_editorFrame::ID_BUTTON2 = wxNewId();
const long UGS_editorFrame::ID_CHECKBOX3 = wxNewId();
const long UGS_editorFrame::ID_CHECKBOX2 = wxNewId();
const long UGS_editorFrame::ID_CHECKBOX1 = wxNewId();
const long UGS_editorFrame::ID_STATICLINE1 = wxNewId();
const long UGS_editorFrame::ID_STATICBOX1 = wxNewId();
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
    SetClientSize(wxSize(543,539));
    Move(wxPoint(-1,-1));
    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(0,8), wxSize(528,494), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("ULTIMATE GUITAR SHOW EDITOR"), wxPoint(72,40), wxSize(416,40), 0, _T("ID_STATICTEXT1"));
    wxFont StaticText1Font(18,wxFONTFAMILY_TELETYPE,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Nimbus Mono PS"),wxFONTENCODING_DEFAULT);
    StaticText1->SetFont(StaticText1Font);
    TextCtrl1 = new wxTextCtrl(Panel1, ID_TEXTCTRL1, wxEmptyString, wxPoint(144,136), wxSize(328,34), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("Artista"), wxPoint(65,144), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    TextCtrl2 = new wxTextCtrl(Panel1, ID_TEXTCTRL2, wxEmptyString, wxPoint(144,192), wxSize(328,34), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _("Musica"), wxPoint(65,200), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    Choice1 = new wxChoice(Panel1, ID_CHOICE1, wxPoint(176,248), wxSize(296,34), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
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
    StaticText4 = new wxStaticText(Panel1, ID_STATICTEXT4, _("Instrumento"), wxPoint(65,256), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    StaticText5 = new wxStaticText(Panel1, ID_STATICTEXT5, _("Dificuldade"), wxPoint(65,310), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    StaticText6 = new wxStaticText(Panel1, ID_STATICTEXT6, _("Audio .ogg"), wxPoint(65,365), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    TextCtrl3 = new wxTextCtrl(Panel1, ID_TEXTCTRL3, _("C://files/audio"), wxPoint(176,360), wxSize(248,34), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    TextCtrl3->Disable();
    Button1 = new wxButton(Panel1, ID_BUTTON1, _("..."), wxPoint(432,360), wxSize(37,34), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    Button2 = new wxButton(Panel1, ID_BUTTON2, _("Iniciar"), wxPoint(200,440), wxSize(160,34), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    CheckBox3 = new wxCheckBox(Panel1, ID_CHECKBOX3, _("Dificil"), wxPoint(380,310), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX3"));
    CheckBox3->SetValue(false);
    CheckBox2 = new wxCheckBox(Panel1, ID_CHECKBOX2, _("Medio"), wxPoint(280,310), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX2"));
    CheckBox2->SetValue(false);
    CheckBox1 = new wxCheckBox(Panel1, ID_CHECKBOX1, _("Facil"), wxPoint(190,310), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
    CheckBox1->SetValue(false);
    StaticLine1 = new wxStaticLine(Panel1, ID_STATICLINE1, wxPoint(50,65), wxSize(400,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
    StaticBox1 = new wxStaticBox(Panel1, ID_STATICBOX1, _("     Dados da Faixa    "), wxPoint(24,96), wxSize(496,328), 0, _T("ID_STATICBOX1"));
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
