#include <wx/wx.h>
#include <wx/bitmap.h>
#include <wx/timer.h>

class CaptureFrame : public wxFrame
{
public:
    CaptureFrame(const wxString &title, const wxPoint &pos, const wxSize &size);

private:
    const int DELAY_MS = 20;
    bool CAPTURING = false;

    wxPanel *CapturePanel = nullptr;
    wxPanel *ButtonPanel = nullptr;

    wxButton *startCaptureBtn = nullptr;
    wxButton *stopCaptureBtn = nullptr;

    wxTimer *timer;

    void OnCaptureScreen(wxTimerEvent &);

    void OnStartPress(wxCommandEvent &);
    void OnStopPress(wxCommandEvent &);
};

CaptureFrame::CaptureFrame(const wxString &title, const wxPoint &pos, const wxSize &size)
    : wxFrame(nullptr, wxID_ANY, title, pos, size)
{
    CapturePanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(1024, 696));
    CapturePanel->SetBackgroundColour(wxColor(38, 37, 54));
    ButtonPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);
    ButtonPanel->SetBackgroundColour(wxColor(52, 51, 62));

    wxBoxSizer *MainSizer = new wxBoxSizer(wxVERTICAL);
    MainSizer->Add(CapturePanel, 1, wxEXPAND, 0);
    MainSizer->Add(ButtonPanel, 0, wxEXPAND, 0);

    startCaptureBtn = new wxButton(ButtonPanel, wxID_ANY, "Start Capture");
    stopCaptureBtn = new wxButton(ButtonPanel, wxID_ANY, "Stop Capture");
    this->Bind(wxEVT_BUTTON, &CaptureFrame::OnStartPress, this, startCaptureBtn->GetId());
    this->Bind(wxEVT_BUTTON, &CaptureFrame::OnStopPress, this, stopCaptureBtn->GetId());

    wxBoxSizer *ButtonSizer = new wxBoxSizer(wxHORIZONTAL);
    ButtonSizer->Add(startCaptureBtn, 0, wxALIGN_CENTER | wxALL, FromDIP(10));
    ButtonSizer->Add(stopCaptureBtn, 0, wxALIGN_CENTER | wxALL, FromDIP(10));
    ButtonPanel->SetSizer(ButtonSizer);

    timer = new wxTimer(this, wxID_ANY);
    this->Bind(wxEVT_TIMER, &CaptureFrame::OnCaptureScreen, this);

    this->SetSizerAndFit(MainSizer);
    this->Center();
}

void CaptureFrame::OnStartPress(wxCommandEvent &e)
{
    CAPTURING = true;
    timer->Start(DELAY_MS);
}

void CaptureFrame::OnStopPress(wxCommandEvent &e)
{
    CAPTURING = false;
    timer->Stop();
    wxClientDC clientDC(CapturePanel);
    clientDC.Clear();
}

void CaptureFrame::OnCaptureScreen(wxTimerEvent &e)
{
    if (CAPTURING)
    {
        wxScreenDC screenDC;
        // Capture Screen
        wxRect frameRect = CapturePanel->GetRect();
        wxBitmap screenshot(frameRect.GetSize());

        wxMemoryDC memDC(screenshot);
        memDC.Blit(0, 0, frameRect.width, frameRect.height, &screenDC, frameRect.x, frameRect.y);
        memDC.SelectObject(wxNullBitmap);

        // Update Screen
        wxClientDC clientDC(CapturePanel);
        clientDC.Clear();
        clientDC.DrawBitmap(screenshot, 0, 0, false);
    }
}

class CaptureApp : public wxApp
{
public:
    virtual bool OnInit();

private:
    CaptureFrame *MainFrame;
};

bool CaptureApp::OnInit()
{
    MainFrame = new CaptureFrame("Remote Desktop", wxDefaultPosition, wxDefaultSize);
    MainFrame->Show();

    return true;
}

wxIMPLEMENT_APP(CaptureApp);
