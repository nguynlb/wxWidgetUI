#include <wx/wx.h>

class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(MyApp);

class MyFrame : public wxFrame
{
public:
    MyFrame(const wxString &title, const wxPoint &pos, const wxSize &size);

private:
    wxStaticBitmap *staticBitmap;
    wxStaticText *textView;
    wxImage image;

    void OnLoadImage(wxCommandEvent &event);
    void UpdateImage(const wxImage &image);
};

MyFrame::MyFrame(const wxString &title, const wxPoint &pos, const wxSize &size)
    : wxFrame(nullptr, wxID_ANY, title, pos, size)
{
    wxInitAllImageHandlers();

    auto sizer = new wxBoxSizer(wxVERTICAL);

    textView = new wxStaticText(this, wxID_ANY, "Here is your image: ");
    staticBitmap = new wxStaticBitmap(this, wxID_ANY, wxBitmap(wxSize(1, 1)), wxDefaultPosition, FromDIP(wxSize(500, 500)));
    staticBitmap->SetScaleMode(wxStaticBitmap::Scale_None);

    auto image_btn = new wxButton(this, wxID_ANY, "Load Image...");
    image_btn->Bind(wxEVT_BUTTON, &MyFrame::OnLoadImage, this);

    auto sizer_btn = new wxBoxSizer(wxHORIZONTAL);
    sizer_btn->Add(image_btn, 0, wxLEFT, FromDIP(5));

    sizer->Add(textView, 0, wxALIGN_CENTER | wxALL, FromDIP(10));
    sizer->Add(staticBitmap, 1, wxALL, FromDIP(10));
    sizer->Add(sizer_btn, 0, wxALIGN_CENTER | wxALL, FromDIP(10));

    this->SetSizer(sizer);
}

void MyFrame::OnLoadImage(wxCommandEvent &event)
{
    wxFileDialog dialog(this, "Load your image", "", "",
                        "Image Files (*.png, *.jpg, *.jpeg, *.bmp)|*.png;*.jpg;*.jpeg;*.bmp",
                        wxFD_OPEN | wxFD_FILE_MUST_EXIST);

    if (dialog.ShowModal() == wxID_CANCEL)
        return;

    if (!image.LoadFile(dialog.GetPath()))
    {
        wxMessageBox("Failed to load image", "Error", wxOK | wxICON_ERROR);
        return;
    }
    UpdateImage(image);
}

bool MyApp::OnInit()
{
    (new MyFrame("Remote Desktop", wxDefaultPosition, wxDefaultSize))->Show();
    return true;
}

void MyFrame::UpdateImage(const wxImage &image)
{
    staticBitmap->SetBitmap(wxBitmap(image));
    this->Layout();
}