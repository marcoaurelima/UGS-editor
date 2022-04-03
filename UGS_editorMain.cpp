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
const long UGS_editorFrame::ID_TEXTCTRL3 = wxNewId();
const long UGS_editorFrame::ID_STATICTEXT2 = wxNewId();
const long UGS_editorFrame::ID_STATICTEXT3 = wxNewId();
const long UGS_editorFrame::ID_STATICTEXT4 = wxNewId();
const long UGS_editorFrame::ID_STATICTEXT6 = wxNewId();
const long UGS_editorFrame::ID_BUTTON1 = wxNewId();
const long UGS_editorFrame::ID_STATICTEXT5 = wxNewId();
const long UGS_editorFrame::ID_TEXTCTRL7 = wxNewId();
const long UGS_editorFrame::ID_BUTTON2 = wxNewId();
const long UGS_editorFrame::ID_PANEL2 = wxNewId();
const long UGS_editorFrame::ID_STATICTEXT1 = wxNewId();
const long UGS_editorFrame::ID_STATICLINE1 = wxNewId();
const long UGS_editorFrame::ID_BUTTON3 = wxNewId();
const long UGS_editorFrame::ID_PANEL10 = wxNewId();
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
    SetClientSize(wxSize(542,612));
    Move(wxPoint(-1,-1));
    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(0,8), wxSize(542,592), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    Panel1->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVEBORDER));
    Panel2 = new wxPanel(Panel1, ID_PANEL2, wxPoint(32,72), wxSize(480,424), wxBORDER_DOUBLE|wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    Panel2->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENUBAR));
    StaticText10 = new wxStaticText(Panel2, ID_STATICTEXT10, _("Card (148x148)"), wxPoint(48,184), wxDefaultSize, 0, _T("ID_STATICTEXT10"));
    TextCtrl4 = new wxTextCtrl(Panel2, ID_TEXTCTRL4, wxEmptyString, wxPoint(168,176), wxSize(225,34), 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
    TextCtrl4->Disable();
    Button4 = new wxButton(Panel2, ID_BUTTON4, _("..."), wxPoint(400,176), wxSize(37,34), 0, wxDefaultValidator, _T("ID_BUTTON4"));
    TextCtrl5 = new wxTextCtrl(Panel2, ID_TEXTCTRL5, wxEmptyString, wxPoint(168,224), wxSize(225,34), 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
    TextCtrl5->Disable();
    TextCtrl6 = new wxTextCtrl(Panel2, ID_TEXTCTRL6, wxEmptyString, wxPoint(168,272), wxSize(225,34), 0, wxDefaultValidator, _T("ID_TEXTCTRL6"));
    TextCtrl6->Disable();
    Button5 = new wxButton(Panel2, ID_BUTTON5, _("..."), wxPoint(400,224), wxSize(37,34), 0, wxDefaultValidator, _T("ID_BUTTON5"));
    Button6 = new wxButton(Panel2, ID_BUTTON6, _("..."), wxPoint(400,272), wxSize(37,34), 0, wxDefaultValidator, _T("ID_BUTTON6"));
    StaticText11 = new wxStaticText(Panel2, ID_STATICTEXT11, _("Logo (246x246)"), wxPoint(48,240), wxDefaultSize, 0, _T("ID_STATICTEXT11"));
    StaticText12 = new wxStaticText(Panel2, ID_STATICTEXT12, _("Poster (1368x769)"), wxPoint(32,280), wxDefaultSize, 0, _T("ID_STATICTEXT12"));
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
    TextCtrl3 = new wxTextCtrl(Panel2, ID_TEXTCTRL3, wxEmptyString, wxPoint(120,320), wxSize(275,34), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    TextCtrl3->Disable();
    StaticText2 = new wxStaticText(Panel2, ID_STATICTEXT2, _("Artista"), wxPoint(40,40), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    StaticText3 = new wxStaticText(Panel2, ID_STATICTEXT3, _("Musica"), wxPoint(40,88), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    StaticText4 = new wxStaticText(Panel2, ID_STATICTEXT4, _("Instrumento"), wxPoint(40,136), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    StaticText6 = new wxStaticText(Panel2, ID_STATICTEXT6, _("Audio .ogg"), wxPoint(32,328), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    Button1 = new wxButton(Panel2, ID_BUTTON1, _("..."), wxPoint(400,320), wxSize(37,34), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    StaticText5 = new wxStaticText(Panel2, ID_STATICTEXT5, _("Arquivo de sequencia bruta"), wxPoint(24,376), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    TextCtrl7 = new wxTextCtrl(Panel2, ID_TEXTCTRL7, _("Ausente"), wxPoint(224,368), wxSize(111,34), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL7"));
    TextCtrl7->Disable();
    TextCtrl7->SetForegroundColour(wxColour(223,22,24));
    TextCtrl7->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_3DDKSHADOW));
    Button2 = new wxButton(Panel2, ID_BUTTON2, _("Gerar"), wxPoint(344,369), wxSize(95,34), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("ULTIMATE GUITAR SHOW EDITOR"), wxPoint(72,35), wxSize(416,40), 0, _T("ID_STATICTEXT1"));
    wxFont StaticText1Font(18,wxFONTFAMILY_TELETYPE,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Nimbus Mono PS"),wxFONTENCODING_DEFAULT);
    StaticText1->SetFont(StaticText1Font);
    StaticLine1 = new wxStaticLine(Panel1, ID_STATICLINE1, wxPoint(50,60), wxSize(400,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
    Panel10 = new wxPanel(Panel1, ID_PANEL10, wxPoint(32,510), wxSize(480,56), wxBORDER_DOUBLE|wxTAB_TRAVERSAL, _T("ID_PANEL10"));
    Panel10->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENUBAR));
    Button3 = new wxButton(Panel10, ID_BUTTON3, _("Exportar Fase"), wxPoint(288,10), wxSize(153,34), 0, wxDefaultValidator, _T("ID_BUTTON3"));
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
    Center();

    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&UGS_editorFrame::OnButton4Click);
    Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&UGS_editorFrame::OnButton5Click);
    Connect(ID_BUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&UGS_editorFrame::OnButton6Click);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&UGS_editorFrame::OnButton1Click);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&UGS_editorFrame::OnButton2Click2);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&UGS_editorFrame::OnButton3Click1);
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
    pathAudio = path.ToStdString();

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
    pathCard = path.ToStdString();
}

void UGS_editorFrame::OnButton5Click(wxCommandEvent& event)
{
    auto res = FileDialog2->ShowModal();
    if(res == wxID_CANCEL)
        return;

    wxString path = FileDialog2->GetPath();
    TextCtrl5->SetValue(shortenPath(path.ToStdString(), 28));
    pathLogo = path.ToStdString();
}

void UGS_editorFrame::OnButton6Click(wxCommandEvent& event)
{
    auto res = FileDialog2->ShowModal();
    if(res == wxID_CANCEL)
        return;

    wxString path = FileDialog2->GetPath();
    TextCtrl6->SetValue(shortenPath(path.ToStdString(), 28));
    pathPoster = path.ToStdString();
}



void UGS_editorFrame::OnButton2Click2(wxCommandEvent& event)
{
    // Boquear edição se os campos estão faltando
    bool lock = TextCtrl1->IsEmpty() ||
                TextCtrl2->IsEmpty() ||
                TextCtrl3->IsEmpty() ||
                TextCtrl4->IsEmpty() ||
                TextCtrl5->IsEmpty() ||
                TextCtrl6->IsEmpty() ||
                Choice1->GetSelection() < 0;
    if(lock){ wxMessageBox("Preencha todos os campos.", "Alerta"); return; }

    std::string artista = TextCtrl1->GetValue().Upper().ToStdString();
    std::string musica = TextCtrl2->GetValue().Upper().ToStdString();
    std::string instrumento = Choice1->GetString(0).ToStdString();

    std::string trackInfo = "ARTISTA: " + artista + "\nMUSICA: "  + musica + "\nINSTRUMENTO: " + instrumento;
    std::string trackPath = pathAudio;

    SequenceEditor seqEdit(trackInfo, trackPath);
    bool res = seqEdit.open();

    if(!res){ return; }

    std::ifstream file("exports/brute-sequence.txt");
    if(file.is_open())
    {
        TextCtrl7->SetValue("Presente");
        TextCtrl7->SetForegroundColour(wxColor(0,255,0));
    }

}

int getRandInt(int range)
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0,range);

    return dist6(rng);
}

std::vector<int> genChord(int chordWeight, int dificulty)
{
    int chordSize = chordWeight;
    if(chordSize > 2){ chordSize = 2; }

    std::vector<int> chords;

    // Gerar os acordes

    while(true)
    {
        if(chords.size() == (unsigned)chordSize){ break; }

        int tileColor = getRandInt(chordSize);

        bool exists = false;
        for(auto& i : chords)
        {
            if(i == tileColor){ exists = true; }
        }

        if(!exists)
        chords.push_back(tileColor);
    }

    std::cout << "\nAcorde gerado: ";
    for(auto& i : chords)
    {
        std::cout << i << " ";
    }
    puts("\n");

    return chords;
}

void UGS_editorFrame::OnButton3Click1(wxCommandEvent& event)
{
    FILE* file = fopen("exports/brute-sequence.txt", "r");
    if(file == NULL) { wxMessageBox("Arquivo de sequencia bruta inexistente.", "Erro", wxICON_ERROR); return; }

    std::vector<float> seqTime;
    std::vector<int> seqWeight;
    std::vector<float> seqBend;

    float a = 0.0;
    float c = 0.0;
    int b = 0;

    while(fscanf(file, "%f %d %f", &a, &b, &c) != EOF)
    {
        //std::cout << a << " - " << b << " - " << c << "\n";
        seqTime.push_back(a);
        seqWeight.push_back(b);
        seqBend.push_back(c);
    }
    fclose(file);

    std::stringstream sequence;

    // Produção da faixa fácil
    for(unsigned i=0;i<seqTime.size();i++)
    {
        auto chords = genChord(seqWeight[i], 0);
        for(unsigned j=0;j<chords.size();j++)
        {
            sequence << seqTime[i] << " " << chords[j] << " " << seqBend[i] << "\n";
        }
    }

    file = fopen("exports/brute-sequence-facil.txt", "w");
    fputs(sequence.str().c_str(), file);
    fclose(file);

    std::cout << "STREAM:\n" << sequence.str() << "\n";





}











