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
const long UGS_editorFrame::ID_TEXTCTRL1 = wxNewId();
const long UGS_editorFrame::ID_TEXTCTRL2 = wxNewId();
const long UGS_editorFrame::ID_CHOICE1 = wxNewId();
const long UGS_editorFrame::ID_CHECKBOX3 = wxNewId();
const long UGS_editorFrame::ID_CHECKBOX2 = wxNewId();
const long UGS_editorFrame::ID_CHECKBOX1 = wxNewId();
const long UGS_editorFrame::ID_TEXTCTRL3 = wxNewId();
const long UGS_editorFrame::ID_STATICTEXT2 = wxNewId();
const long UGS_editorFrame::ID_STATICTEXT3 = wxNewId();
const long UGS_editorFrame::ID_STATICTEXT4 = wxNewId();
const long UGS_editorFrame::ID_STATICTEXT5 = wxNewId();
const long UGS_editorFrame::ID_STATICTEXT6 = wxNewId();
const long UGS_editorFrame::ID_BUTTON1 = wxNewId();
const long UGS_editorFrame::ID_PANEL2 = wxNewId();
const long UGS_editorFrame::ID_STATICTEXT1 = wxNewId();
const long UGS_editorFrame::ID_STATICLINE1 = wxNewId();
const long UGS_editorFrame::ID_BUTTON3 = wxNewId();
const long UGS_editorFrame::ID_BUTTON2 = wxNewId();
const long UGS_editorFrame::ID_PANEL10 = wxNewId();
const long UGS_editorFrame::ID_PANEL1 = wxNewId();
const long UGS_editorFrame::idMenuQuit = wxNewId();
const long UGS_editorFrame::idMenuAbout = wxNewId();
const long UGS_editorFrame::ID_TIMER1 = wxNewId();
const long UGS_editorFrame::ID_TIMER2 = wxNewId();
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
    SetClientSize(wxSize(542,612));
    Move(wxPoint(-1,-1));
    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(0,8), wxSize(542,592), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    Panel1->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVEBORDER));
    Panel2 = new wxPanel(Panel1, ID_PANEL2, wxPoint(32,72), wxSize(480,424), wxBORDER_DOUBLE|wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    Panel2->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENUBAR));
    StaticText10 = new wxStaticText(Panel2, ID_STATICTEXT10, _("Card (148x148)"), wxPoint(48,224), wxDefaultSize, 0, _T("ID_STATICTEXT10"));
    TextCtrl4 = new wxTextCtrl(Panel2, ID_TEXTCTRL4, wxEmptyString, wxPoint(168,216), wxSize(225,34), 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
    TextCtrl4->Disable();
    Button4 = new wxButton(Panel2, ID_BUTTON4, _("..."), wxPoint(400,216), wxSize(37,34), 0, wxDefaultValidator, _T("ID_BUTTON4"));
    TextCtrl5 = new wxTextCtrl(Panel2, ID_TEXTCTRL5, wxEmptyString, wxPoint(168,264), wxSize(225,34), 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
    TextCtrl5->Disable();
    TextCtrl6 = new wxTextCtrl(Panel2, ID_TEXTCTRL6, wxEmptyString, wxPoint(168,312), wxSize(225,34), 0, wxDefaultValidator, _T("ID_TEXTCTRL6"));
    TextCtrl6->Disable();
    Button5 = new wxButton(Panel2, ID_BUTTON5, _("..."), wxPoint(400,264), wxSize(37,34), 0, wxDefaultValidator, _T("ID_BUTTON5"));
    Button6 = new wxButton(Panel2, ID_BUTTON6, _("..."), wxPoint(400,312), wxSize(37,34), 0, wxDefaultValidator, _T("ID_BUTTON6"));
    StaticText11 = new wxStaticText(Panel2, ID_STATICTEXT11, _("Logo (246x246)"), wxPoint(48,272), wxDefaultSize, 0, _T("ID_STATICTEXT11"));
    StaticText12 = new wxStaticText(Panel2, ID_STATICTEXT12, _("Poster (1368x769)"), wxPoint(32,320), wxDefaultSize, 0, _T("ID_STATICTEXT12"));
    TextCtrl1 = new wxTextCtrl(Panel2, ID_TEXTCTRL1, wxEmptyString, wxPoint(104,32), wxSize(336,34), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    TextCtrl2 = new wxTextCtrl(Panel2, ID_TEXTCTRL2, wxEmptyString, wxPoint(104,80), wxSize(336,34), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    Choice1 = new wxChoice(Panel2, ID_CHOICE1, wxPoint(144,128), wxSize(296,34), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
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
    CheckBox3 = new wxCheckBox(Panel2, ID_CHECKBOX3, _("Dificil"), wxPoint(352,176), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX3"));
    CheckBox3->SetValue(true);
    CheckBox2 = new wxCheckBox(Panel2, ID_CHECKBOX2, _("Medio"), wxPoint(256,176), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX2"));
    CheckBox2->SetValue(true);
    CheckBox1 = new wxCheckBox(Panel2, ID_CHECKBOX1, _("Facil"), wxPoint(160,176), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
    CheckBox1->SetValue(true);
    TextCtrl3 = new wxTextCtrl(Panel2, ID_TEXTCTRL3, wxEmptyString, wxPoint(120,361), wxSize(275,34), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    TextCtrl3->Disable();
    StaticText2 = new wxStaticText(Panel2, ID_STATICTEXT2, _("Artista"), wxPoint(40,40), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    StaticText3 = new wxStaticText(Panel2, ID_STATICTEXT3, _("Musica"), wxPoint(40,88), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    StaticText4 = new wxStaticText(Panel2, ID_STATICTEXT4, _("Instrumento"), wxPoint(40,136), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    StaticText5 = new wxStaticText(Panel2, ID_STATICTEXT5, _("Dificuldade"), wxPoint(48,180), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    StaticText6 = new wxStaticText(Panel2, ID_STATICTEXT6, _("Audio .ogg"), wxPoint(32,368), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    Button1 = new wxButton(Panel2, ID_BUTTON1, _("..."), wxPoint(400,360), wxSize(37,34), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("ULTIMATE GUITAR SHOW EDITOR"), wxPoint(72,35), wxSize(416,40), 0, _T("ID_STATICTEXT1"));
    wxFont StaticText1Font(18,wxFONTFAMILY_TELETYPE,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Nimbus Mono PS"),wxFONTENCODING_DEFAULT);
    StaticText1->SetFont(StaticText1Font);
    StaticLine1 = new wxStaticLine(Panel1, ID_STATICLINE1, wxPoint(50,60), wxSize(400,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
    Panel10 = new wxPanel(Panel1, ID_PANEL10, wxPoint(32,510), wxSize(480,56), wxBORDER_DOUBLE|wxTAB_TRAVERSAL, _T("ID_PANEL10"));
    Panel10->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENUBAR));
    Button3 = new wxButton(Panel10, ID_BUTTON3, _("Exportar Faixa"), wxPoint(288,10), wxSize(153,34), 0, wxDefaultValidator, _T("ID_BUTTON3"));
    Button2 = new wxButton(Panel10, ID_BUTTON2, _("Editar sequencia"), wxPoint(40,10), wxSize(207,34), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Sair\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&Arquivo"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("Sobre\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Ajuda"));
    SetMenuBar(MenuBar1);
    FileDialog1 = new wxFileDialog(this, _("Select file"), wxEmptyString, wxEmptyString, _("*.ogg"), wxFD_DEFAULT_STYLE, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
    FileDialog2 = new wxFileDialog(this, _("Select file"), wxEmptyString, wxEmptyString, _("*.png"), wxFD_DEFAULT_STYLE, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
    Timer1.SetOwner(this, ID_TIMER1);
    Timer1.Start(100, false);
    Timer2.SetOwner(this, ID_TIMER2);
    Timer2.Start(125, false);
    Center();

    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&UGS_editorFrame::OnButton4Click);
    Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&UGS_editorFrame::OnButton5Click);
    Connect(ID_BUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&UGS_editorFrame::OnButton6Click);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&UGS_editorFrame::OnButton1Click);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&UGS_editorFrame::OnButton2Click2);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&UGS_editorFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&UGS_editorFrame::OnAbout);
    //*)


}




UGS_editorFrame::~UGS_editorFrame()
{
    //(*Destroy(UGS_editorFrame)
    //*)
    delete player;
}

void UGS_editorFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void UGS_editorFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = "       Autor: Marco Aurelio Lima \nhttps://github.com/marcoaurelima";
    wxMessageBox(msg, _("Sobre"));
}

std::string shortenPath(std::string path, int finalSize)
{
    int half = (finalSize/3)-1;

    std::stringstream ss;
    ss << path.substr(0, half) << "..." << path.substr(path.size()-(half*2)-1, path.size()-1);

    return ss.str();

}

void UGS_editorFrame::OnButton1Click(wxCommandEvent& event)
{
    auto res = FileDialog1->ShowModal();
    if(res == wxID_CANCEL)
        return;

    wxString path = FileDialog1->GetPath();
    TextCtrl3->SetValue(shortenPath(path.ToStdString(), 34));

    sf::Music music;
    bool opened = music.openFromFile(path.ToStdString());
    if(!opened){ wxMessageBox(wxT("ERRO"), wxT("Não foi possível abrir o arquivo."), wxICON_ERROR); return;}

}

void UGS_editorFrame::OnButton4Click(wxCommandEvent& event)
{
    auto res = FileDialog2->ShowModal();
    if(res == wxID_CANCEL)
        return;

    wxString path = FileDialog2->GetPath();
    TextCtrl4->SetValue(shortenPath(path.ToStdString(), 28));
}

void UGS_editorFrame::OnButton5Click(wxCommandEvent& event)
{
    auto res = FileDialog2->ShowModal();
    if(res == wxID_CANCEL)
        return;

    wxString path = FileDialog2->GetPath();
    TextCtrl5->SetValue(shortenPath(path.ToStdString(), 28));
}

void UGS_editorFrame::OnButton6Click(wxCommandEvent& event)
{
    auto res = FileDialog2->ShowModal();
    if(res == wxID_CANCEL)
        return;

    wxString path = FileDialog2->GetPath();
    TextCtrl6->SetValue(shortenPath(path.ToStdString(), 28));
}



void UGS_editorFrame::OnButton2Click2(wxCommandEvent& event)
{
    system("./edit-seq");
}
