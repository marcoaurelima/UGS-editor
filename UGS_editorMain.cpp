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
const long UGS_editorFrame::ID_PANEL5 = wxNewId();
const long UGS_editorFrame::ID_PANEL6 = wxNewId();
const long UGS_editorFrame::ID_PANEL7 = wxNewId();
const long UGS_editorFrame::ID_PANEL8 = wxNewId();
const long UGS_editorFrame::ID_PANEL9 = wxNewId();
const long UGS_editorFrame::ID_STATICTEXT8 = wxNewId();
const long UGS_editorFrame::ID_BUTTON9 = wxNewId();
const long UGS_editorFrame::ID_STATICTEXT9 = wxNewId();
const long UGS_editorFrame::ID_BUTTON10 = wxNewId();
const long UGS_editorFrame::ID_BUTTON11 = wxNewId();
const long UGS_editorFrame::ID_BUTTON12 = wxNewId();
const long UGS_editorFrame::ID_BUTTON13 = wxNewId();
const long UGS_editorFrame::ID_BUTTON14 = wxNewId();
const long UGS_editorFrame::ID_BUTTON15 = wxNewId();
const long UGS_editorFrame::ID_BUTTON16 = wxNewId();
const long UGS_editorFrame::ID_BUTTON17 = wxNewId();
const long UGS_editorFrame::ID_BUTTON18 = wxNewId();
const long UGS_editorFrame::ID_STATICLINE2 = wxNewId();
const long UGS_editorFrame::ID_PANEL3 = wxNewId();
const long UGS_editorFrame::ID_BUTTON7 = wxNewId();
const long UGS_editorFrame::ID_BUTTON3 = wxNewId();
const long UGS_editorFrame::ID_PANEL10 = wxNewId();
const long UGS_editorFrame::ID_PANEL1 = wxNewId();
const long UGS_editorFrame::idMenuQuit = wxNewId();
const long UGS_editorFrame::idMenuAbout = wxNewId();
const long UGS_editorFrame::ID_TIMER1 = wxNewId();
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
    SetClientSize(wxSize(961,585));
    Move(wxPoint(-1,-1));
    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(0,8), wxSize(528,494), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    Panel1->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVEBORDER));
    Panel2 = new wxPanel(Panel1, ID_PANEL2, wxPoint(32,90), wxSize(480,430), wxBORDER_DOUBLE|wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    Panel2->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENUBAR));
    StaticText10 = new wxStaticText(Panel2, ID_STATICTEXT10, _("Card (148x148)"), wxPoint(50,280), wxDefaultSize, 0, _T("ID_STATICTEXT10"));
    TextCtrl4 = new wxTextCtrl(Panel2, ID_TEXTCTRL4, wxEmptyString, wxPoint(168,273), wxSize(225,34), 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
    TextCtrl4->Disable();
    Button4 = new wxButton(Panel2, ID_BUTTON4, _("..."), wxPoint(400,272), wxSize(37,34), 0, wxDefaultValidator, _T("ID_BUTTON4"));
    TextCtrl5 = new wxTextCtrl(Panel2, ID_TEXTCTRL5, wxEmptyString, wxPoint(168,316), wxSize(225,34), 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
    TextCtrl5->Disable();
    TextCtrl6 = new wxTextCtrl(Panel2, ID_TEXTCTRL6, wxEmptyString, wxPoint(168,359), wxSize(225,34), 0, wxDefaultValidator, _T("ID_TEXTCTRL6"));
    TextCtrl6->Disable();
    Button5 = new wxButton(Panel2, ID_BUTTON5, _("..."), wxPoint(400,316), wxSize(37,34), 0, wxDefaultValidator, _T("ID_BUTTON5"));
    Button6 = new wxButton(Panel2, ID_BUTTON6, _("..."), wxPoint(400,360), wxSize(37,34), 0, wxDefaultValidator, _T("ID_BUTTON6"));
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
    TextCtrl3 = new wxTextCtrl(Panel1, ID_TEXTCTRL3, wxEmptyString, wxPoint(160,320), wxSize(266,34), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    TextCtrl3->Disable();
    Button1 = new wxButton(Panel1, ID_BUTTON1, _("..."), wxPoint(432,320), wxSize(37,34), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    CheckBox3 = new wxCheckBox(Panel1, ID_CHECKBOX3, _("Dificil"), wxPoint(380,280), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX3"));
    CheckBox3->SetValue(false);
    CheckBox2 = new wxCheckBox(Panel1, ID_CHECKBOX2, _("Medio"), wxPoint(285,280), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX2"));
    CheckBox2->SetValue(false);
    CheckBox1 = new wxCheckBox(Panel1, ID_CHECKBOX1, _("Facil"), wxPoint(190,280), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
    CheckBox1->SetValue(false);
    StaticLine1 = new wxStaticLine(Panel1, ID_STATICLINE1, wxPoint(50,65), wxSize(400,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
    Panel3 = new wxPanel(Panel1, ID_PANEL3, wxPoint(536,90), wxSize(390,350), wxBORDER_DOUBLE|wxTAB_TRAVERSAL, _T("ID_PANEL3"));
    Panel3->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENUBAR));
    Panel4 = new wxPanel(Panel3, ID_PANEL4, wxPoint(24,24), wxSize(340,87), wxBORDER_DOUBLE|wxTAB_TRAVERSAL, _T("ID_PANEL4"));
    Panel4->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_SCROLLBAR));
    Button2 = new wxButton(Panel4, ID_BUTTON2, _("Iniciar"), wxPoint(16,16), wxSize(70,34), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    StaticText7 = new wxStaticText(Panel4, ID_STATICTEXT7, _("00:00 / 03:34"), wxPoint(104,17), wxSize(176,31), 0, _T("ID_STATICTEXT7"));
    wxFont StaticText7Font(17,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticText7->SetFont(StaticText7Font);
    Gauge1 = new wxGauge(Panel4, ID_GAUGE1, 100, wxPoint(16,41), wxSize(306,28), 0, wxDefaultValidator, _T("ID_GAUGE1"));
    Gauge1->SetValue(65);
    Panel5 = new wxPanel(Panel3, ID_PANEL5, wxPoint(25,130), wxSize(58,90), 0, _T("ID_PANEL5"));
    Panel5->SetBackgroundColour(wxColour(61,233,10));
    Panel6 = new wxPanel(Panel3, ID_PANEL6, wxPoint(95,130), wxSize(58,90), 0, _T("ID_PANEL6"));
    Panel6->SetBackgroundColour(wxColour(255,1,0));
    Panel7 = new wxPanel(Panel3, ID_PANEL7, wxPoint(165,130), wxSize(58,90), 0, _T("ID_PANEL7"));
    Panel7->SetBackgroundColour(wxColour(255,224,0));
    Panel8 = new wxPanel(Panel3, ID_PANEL8, wxPoint(235,130), wxSize(58,90), 0, _T("ID_PANEL8"));
    Panel8->SetBackgroundColour(wxColour(0,119,255));
    Panel9 = new wxPanel(Panel3, ID_PANEL9, wxPoint(305,130), wxSize(58,90), 0, _T("ID_PANEL9"));
    Panel9->SetBackgroundColour(wxColour(255,108,0));
    StaticText8 = new wxStaticText(Panel3, ID_STATICTEXT8, _("Notas"), wxPoint(30,240), wxDefaultSize, 0, _T("ID_STATICTEXT8"));
    Button9 = new wxButton(Panel3, ID_BUTTON9, _("1"), wxPoint(85,240), wxSize(47,23), wxBORDER_DOUBLE, wxDefaultValidator, _T("ID_BUTTON9"));
    Button9->Disable();
    StaticText9 = new wxStaticText(Panel3, ID_STATICTEXT9, _("Teclas"), wxPoint(30,270), wxDefaultSize, 0, _T("ID_STATICTEXT9"));
    Button10 = new wxButton(Panel3, ID_BUTTON10, _("A Y"), wxPoint(85,272), wxSize(47,23), wxBORDER_DOUBLE, wxDefaultValidator, _T("ID_BUTTON10"));
    Button10->Disable();
    Button11 = new wxButton(Panel3, ID_BUTTON11, _("2"), wxPoint(144,240), wxSize(47,23), wxBORDER_DOUBLE, wxDefaultValidator, _T("ID_BUTTON11"));
    Button11->Disable();
    Button12 = new wxButton(Panel3, ID_BUTTON12, _("S U"), wxPoint(144,272), wxSize(47,23), wxBORDER_DOUBLE, wxDefaultValidator, _T("ID_BUTTON12"));
    Button12->Disable();
    Button13 = new wxButton(Panel3, ID_BUTTON13, _("3"), wxPoint(200,240), wxSize(47,23), wxBORDER_DOUBLE, wxDefaultValidator, _T("ID_BUTTON13"));
    Button13->Disable();
    Button14 = new wxButton(Panel3, ID_BUTTON14, _("D I"), wxPoint(200,272), wxSize(47,23), wxBORDER_DOUBLE, wxDefaultValidator, _T("ID_BUTTON14"));
    Button14->Disable();
    Button15 = new wxButton(Panel3, ID_BUTTON15, _("4"), wxPoint(256,240), wxSize(47,23), wxBORDER_DOUBLE, wxDefaultValidator, _T("ID_BUTTON15"));
    Button15->Disable();
    Button16 = new wxButton(Panel3, ID_BUTTON16, _("F O"), wxPoint(256,272), wxSize(47,23), wxBORDER_DOUBLE, wxDefaultValidator, _T("ID_BUTTON16"));
    Button16->Disable();
    Button17 = new wxButton(Panel3, ID_BUTTON17, _("5"), wxPoint(312,240), wxSize(47,23), wxBORDER_DOUBLE, wxDefaultValidator, _T("ID_BUTTON17"));
    Button17->Disable();
    Button18 = new wxButton(Panel3, ID_BUTTON18, _("G P"), wxPoint(312,272), wxSize(47,23), wxBORDER_DOUBLE, wxDefaultValidator, _T("ID_BUTTON18"));
    Button18->Disable();
    StaticLine2 = new wxStaticLine(Panel3, ID_STATICLINE2, wxPoint(35,322), wxSize(320,2), wxLI_HORIZONTAL, _T("ID_STATICLINE2"));
    Panel10 = new wxPanel(Panel1, ID_PANEL10, wxPoint(536,456), wxSize(390,64), wxBORDER_DOUBLE|wxTAB_TRAVERSAL, _T("ID_PANEL10"));
    Panel10->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENUBAR));
    Button7 = new wxButton(Panel10, ID_BUTTON7, _("Descartar Alteracoes"), wxPoint(26,14), wxSize(165,34), 0, wxDefaultValidator, _T("ID_BUTTON7"));
    Button3 = new wxButton(Panel10, ID_BUTTON3, _("Exportar Faixa"), wxPoint(232,15), wxSize(128,34), 0, wxDefaultValidator, _T("ID_BUTTON3"));
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
    Timer1.Start(500, false);
    Center();

    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&UGS_editorFrame::OnButton4Click);
    Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&UGS_editorFrame::OnButton5Click);
    Connect(ID_BUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&UGS_editorFrame::OnButton6Click);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&UGS_editorFrame::OnButton1Click);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&UGS_editorFrame::OnButton2Click);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&UGS_editorFrame::OnButton3Click);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&UGS_editorFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&UGS_editorFrame::OnAbout);
    Connect(ID_TIMER1,wxEVT_TIMER,(wxObjectEventFunction)&UGS_editorFrame::OnTimer1Trigger);
    //*)

    player = new Player();

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

void UGS_editorFrame::OnButton1Click(wxCommandEvent& event)
{
    auto res = FileDialog1->ShowModal();
    if(res == wxID_CANCEL)
        return;

    wxString path = FileDialog1->GetPath();
    TextCtrl3->SetValue(path);
}

void UGS_editorFrame::OnButton4Click(wxCommandEvent& event)
{
    auto res = FileDialog2->ShowModal();
    if(res == wxID_CANCEL)
        return;

    wxString path = FileDialog2->GetPath();
    TextCtrl4->SetValue(path);
}

void UGS_editorFrame::OnButton5Click(wxCommandEvent& event)
{
    auto res = FileDialog2->ShowModal();
    if(res == wxID_CANCEL)
        return;

    wxString path = FileDialog2->GetPath();
    TextCtrl5->SetValue(path);
}

void UGS_editorFrame::OnButton6Click(wxCommandEvent& event)
{
    auto res = FileDialog2->ShowModal();
    if(res == wxID_CANCEL)
        return;

    wxString path = FileDialog2->GetPath();
    TextCtrl6->SetValue(path);
}

void UGS_editorFrame::OnButton2Click(wxCommandEvent& event)
{
    std::string path = TextCtrl3->GetValue().ToStdString();

    player->openFile(path);
    player->play();

}






void UGS_editorFrame::OnButton3Click(wxCommandEvent& event)
{
    //player->getCurrentTime(StaticText7);
}

void UGS_editorFrame::OnTimer1Trigger(wxTimerEvent& event)
{
    std::string time = player->getCurrentTime();
    StaticText7->SetLabel(time);

    //std::cout << "intervalo " <<  << "\n";
}
