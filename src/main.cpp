#include <wx/wx.h>

class AppGui : public wxApp
{
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(AppGui);

class MainFrame : public wxFrame
{
public:
    MainFrame(const wxString &title, const wxPoint &pos, const wxSize &size);

private:
    wxBoxSizer *MainSizer = nullptr;
    wxBoxSizer *LeftSizer = nullptr;
    wxBoxSizer *RightSizer = nullptr;
};

MainFrame::MainFrame(const wxString &title, const wxPoint &pos, const wxSize &size)
    : wxFrame(nullptr, wxID_ANY, title, pos, size)
{
    auto PRIMARY_BUTTON_SIZE = wxSize(256, 64);
    auto USER_IMAGE_SIZE = wxSize(128, 128);
    auto PANEL_LEFT_SIZE = wxSize(256, 860);
    auto PANEL_RIGHT_SIZE = wxSize(1184, 860);
    auto PRIMARY_COLOR_1 = wxColour(100, 100, 200);
    auto PRIMARY_COLOR_2 = wxColour(100, 200, 100);
    auto SECONDARY_COLOR_1 = wxColour(100, 100, 100);
    auto SECONDARY_COLOR_2 = wxColour(100, 100, 50);

    auto LeftMainPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, PANEL_LEFT_SIZE);
    auto ButtonTop = new wxButton(LeftMainPanel, wxID_ANY, ("Click me!"), wxDefaultPosition, PRIMARY_BUTTON_SIZE);
    auto ButtonLeft = new wxButton(LeftMainPanel, wxID_ANY, ("Ok Cool right"), wxDefaultPosition, PRIMARY_BUTTON_SIZE);

    LeftMainPanel->SetBackgroundColour(PRIMARY_COLOR_1);
    ButtonTop->SetBackgroundColour(SECONDARY_COLOR_1);
    ButtonLeft->SetBackgroundColour(SECONDARY_COLOR_2);

    auto RightMainPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, PANEL_RIGHT_SIZE);
    RightMainPanel->SetBackgroundColour(PRIMARY_COLOR_2);

    MainSizer = new wxBoxSizer(wxHORIZONTAL);
    MainSizer->Add(LeftMainPanel, 0, wxEXPAND, 0);
    MainSizer->Add(RightMainPanel, 1, wxEXPAND, 0);

    LeftSizer = new wxBoxSizer(wxVERTICAL);
    LeftSizer->Add(ButtonTop, 0, wxEXPAND | wxALL, FromDIP(15));
    LeftSizer->Add(ButtonLeft, 0, wxEXPAND | wxALL, FromDIP(15));

    LeftMainPanel->SetSizerAndFit(LeftSizer);

    // MainSizer->Add(LeftSizer, 0, wxEXPAND);
    // MainSizer->Add(RightSizer, 1, wxEXPAND);

    auto InnerRightPanel = new wxPanel(RightMainPanel, wxID_ANY, wxDefaultPosition, USER_IMAGE_SIZE);
    RightSizer = new wxBoxSizer(wxVERTICAL);
    InnerRightPanel->SetBackgroundColour(wxColour(200, 100, 100));

    auto text_name = new wxStaticText(RightMainPanel, wxID_ANY, "ADMIN");
    RightSizer->Add(text_name, 0, wxALIGN_RIGHT | wxALL, FromDIP(50));

    RightSizer->Add(InnerRightPanel, 0, wxALIGN_RIGHT | wxALL, FromDIP(50));
    RightMainPanel->SetSizer(RightSizer);

    MainSizer->SetSizeHints(this);
    this->SetBackgroundColour(wxColour(0, 0, 0));
    this->SetSizer(MainSizer);
    this->Center();
}

bool AppGui::OnInit()
{
    MainFrame *mainFrame = new MainFrame("Remote Desktop App", wxDefaultPosition, wxDefaultSize);
    mainFrame->Show();

    return true;
}

// class PannelButton : public wxPanel
// {
// public:
//     PannelButton();

// private:
//     wxButton *button = nullptr;
// };

// PannelButton::PannelButton()
// {
//     button = new wxButton(this, wxID_ANY, "Click Me!");

//     // this->Add(button);
// }