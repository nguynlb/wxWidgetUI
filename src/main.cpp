// // wxWidgets "Hello world" Program
// // For compilers that support precompilation, includes "wx/wx.h".
// #include <wx/wxprec.h>
// #ifndef WX_PRECOMP
// #include <wx/wx.h>
// #endif
// class MyApp : public wxApp
// {
// public:
//     virtual bool OnInit();
// };
// class MyFrame : public wxFrame
// {
// public:
//     MyFrame(const wxString &title, const wxPoint &pos, const wxSize &size);

// private:
//     void OnHello(wxCommandEvent &event);
//     void OnExit(wxCommandEvent &event);
//     void OnAbout(wxCommandEvent &event);
//     wxDECLARE_EVENT_TABLE();
// };
// enum
// {
//     ID_Hello = 1
// };
// wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
//     EVT_MENU(ID_Hello, MyFrame::OnHello)
//         EVT_MENU(wxID_EXIT, MyFrame::OnExit)
//             EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
//                 wxEND_EVENT_TABLE()
//                     wxIMPLEMENT_APP(MyApp);
// bool MyApp::OnInit()
// {
//     MyFrame *frame = new MyFrame("Hello World", wxPoint(50, 50), wxSize(450, 340));
//     frame->Show(true);
//     return true;
// }
// MyFrame::MyFrame(const wxString &title, const wxPoint &pos, const wxSize &size)
//     : wxFrame(NULL, wxID_ANY, title, pos, size)
// {
//     wxMenu *menuFile = new wxMenu;
//     menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
//                      "Help string shown in status bar for this menu item");
//     menuFile->AppendSeparator();
//     menuFile->Append(wxID_EXIT);
//     wxMenu *menuHelp = new wxMenu;
//     menuHelp->Append(wxID_ABOUT);
//     wxMenuBar *menuBar = new wxMenuBar;
//     menuBar->Append(menuFile, "&File");
//     menuBar->Append(menuHelp, "&Help");
//     SetMenuBar(menuBar);
//     CreateStatusBar();
//     SetStatusText("Welcome to wxWidgets!");
// }
// void MyFrame::OnExit(wxCommandEvent &event)
// {
//     Close(true);
// }
// void MyFrame::OnAbout(wxCommandEvent &event)
// {
//     wxMessageBox("This is a wxWidgets' Hello world sample",
//                  "About Hello World", wxOK | wxICON_INFORMATION);
// }
// void MyFrame::OnHello(wxCommandEvent &event)
// {
//     wxLogMessage("Hello world from wxWidgets!");
// }

// #include <wx/wx.h>

// class MyApp : public wxApp
// {
// public:
//     virtual bool OnInit();
// };

// wxIMPLEMENT_APP(MyApp);

// class wxImagePanel : public wxPanel
// {
//     wxBitmap image;

// public:
//     wxImagePanel(wxFrame *parent, wxString file, wxBitmapType format);

//     void paintEvent(wxPaintEvent &evt);
//     void paintNow();

//     void render(wxDC &dc);

//     // some useful events
//     /*
//      void mouseMoved(wxMouseEvent& event);
//      void mouseDown(wxMouseEvent& event);
//      void mouseWheelMoved(wxMouseEvent& event);
//      void mouseReleased(wxMouseEvent& event);
//      void rightClick(wxMouseEvent& event);
//      void mouseLeftWindow(wxMouseEvent& event);
//      void keyPressed(wxKeyEvent& event);
//      void keyReleased(wxKeyEvent& event);
//      */

//     DECLARE_EVENT_TABLE()
// };

// BEGIN_EVENT_TABLE(wxImagePanel, wxPanel)
// // some useful events
// /*
//  EVT_MOTION(wxImagePanel::mouseMoved)
//  EVT_LEFT_DOWN(wxImagePanel::mouseDown)
//  EVT_LEFT_UP(wxImagePanel::mouseReleased)
//  EVT_RIGHT_DOWN(wxImagePanel::rightClick)
//  EVT_LEAVE_WINDOW(wxImagePanel::mouseLeftWindow)
//  EVT_KEY_DOWN(wxImagePanel::keyPressed)
//  EVT_KEY_UP(wxImagePanel::keyReleased)
//  EVT_MOUSEWHEEL(wxImagePanel::mouseWheelMoved)
//  */

// // catch paint events
// EVT_PAINT(wxImagePanel::paintEvent)

// END_EVENT_TABLE()

// // some useful events
// /*
//  void wxImagePanel::mouseMoved(wxMouseEvent& event) {}
//  void wxImagePanel::mouseDown(wxMouseEvent& event) {}
//  void wxImagePanel::mouseWheelMoved(wxMouseEvent& event) {}
//  void wxImagePanel::mouseReleased(wxMouseEvent& event) {}
//  void wxImagePanel::rightClick(wxMouseEvent& event) {}
//  void wxImagePanel::mouseLeftWindow(wxMouseEvent& event) {}
//  void wxImagePanel::keyPressed(wxKeyEvent& event) {}
//  void wxImagePanel::keyReleased(wxKeyEvent& event) {}
//  */

// wxImagePanel::wxImagePanel(wxFrame *parent, wxString file, wxBitmapType format) : wxPanel(parent)
// {
//     // load the file... ideally add a check to see if loading was successful
//     image.LoadFile(file, format);
// }

// /*
//  * Called by the system of by wxWidgets when the panel needs
//  * to be redrawn. You can also trigger this call by
//  * calling Refresh()/Update().
//  */

// void wxImagePanel::paintEvent(wxPaintEvent &evt)
// {
//     // depending on your system you may need to look at double-buffered dcs
//     wxPaintDC dc(this);
//     render(dc);
// }

// /*
//  * Alternatively, you can use a clientDC to paint on the panel
//  * at any time. Using this generally does not free you from
//  * catching paint events, since it is possible that e.g. the window
//  * manager throws away your drawing when the window comes to the
//  * background, and expects you will redraw it when the window comes
//  * back (by sending a paint event).
//  */
// void wxImagePanel::paintNow()
// {
//     // depending on your system you may need to look at double-buffered dcs
//     wxClientDC dc(this);
//     render(dc);
// }

// /*
//  * Here we do the actual rendering. I put it in a separate
//  * method so that it can work no matter what type of DC
//  * (e.g. wxPaintDC or wxClientDC) is used.
//  */
// void wxImagePanel::render(wxDC &dc)
// {
//     dc.DrawBitmap(image, 0, 0, false);
// }

// class MyFrame : public wxFrame
// {
// public:
//     MyFrame(const wxString &title, const wxPoint &pos, const wxSize &size);
//     ~MyFrame();
// };

// MyFrame::MyFrame(const wxString &title, const wxPoint &pos, const wxSize &size)
//     : wxFrame(nullptr, wxID_ANY, title, pos, size)
// {
//     this->SetBackgroundColour(wxColor(0, 0, 0));

//     wxPanel *panel_top = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(300, 200));
//     panel_top->SetBackgroundColour(wxColor(100, 100, 200));

//     wxPanel *panel_bottom = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(150, 200));
//     panel_bottom->SetBackgroundColour(wxColor(100, 200, 100));

//     wxPanel *panel_bottom_right = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(150, 200));
//     panel_bottom_right->SetBackgroundColour(wxColor(200, 100, 100));

//     wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);
//     wxBoxSizer *sizer_bottom = new wxBoxSizer(wxHORIZONTAL);

//     sizer_bottom->Add(panel_bottom, 1, wxEXPAND);
//     sizer_bottom->Add(panel_bottom_right, 0, wxEXPAND);

//     wxPNGHandler *handler = new wxPNGHandler;
//     wxImage::AddHandler(handler);
//     wxStaticBitmap *image;
//     image = new wxStaticBitmap(this, wxID_ANY, wxBitmap("asserts/Z_08.jpg", wxBITMAP_TYPE_JPEG), wxPoint(50, 100), wxSize(100, 500));

//     sizer->Add(panel_top, 1, wxEXPAND | wxTOP | wxLEFT | wxRIGHT, 10);
//     sizer->Add(image, 1, wxEXPAND | wxALL, 10);

//     this->SetSizerAndFit(sizer);
// }

// MyFrame::~MyFrame(){

// };

// bool MyApp::OnInit()
// {
//     MyFrame *my_frame = new MyFrame("RemoteDesktop", wxDefaultPosition, wxDefaultSize);
//     my_frame->Show();
//     return true;
// }

// #include <wx/wx.h>
// #include <wx/sizer.h>
// #include <wx/image.h>

// class wxImagePanel : public wxPanel
// {
//     wxBitmap image;

// public:
//     wxImagePanel(wxFrame *parent, wxString file, wxBitmapType format);

//     void paintEvent(wxPaintEvent &evt);
//     void paintNow();

//     void render(wxDC &dc);

//     // some useful events
//     /*
//      void mouseMoved(wxMouseEvent& event);
//      void mouseDown(wxMouseEvent& event);
//      void mouseWheelMoved(wxMouseEvent& event);
//      void mouseReleased(wxMouseEvent& event);
//      void rightClick(wxMouseEvent& event);
//      void mouseLeftWindow(wxMouseEvent& event);
//      void keyPressed(wxKeyEvent& event);
//      void keyReleased(wxKeyEvent& event);
//      */

//     DECLARE_EVENT_TABLE()
// };
// BEGIN_EVENT_TABLE(wxImagePanel, wxPanel)
// // some useful events
// /*
//  EVT_MOTION(wxImagePanel::mouseMoved)
//  EVT_LEFT_DOWN(wxImagePanel::mouseDown)
//  EVT_LEFT_UP(wxImagePanel::mouseReleased)
//  EVT_RIGHT_DOWN(wxImagePanel::rightClick)
//  EVT_LEAVE_WINDOW(wxImagePanel::mouseLeftWindow)
//  EVT_KEY_DOWN(wxImagePanel::keyPressed)
//  EVT_KEY_UP(wxImagePanel::keyReleased)
//  EVT_MOUSEWHEEL(wxImagePanel::mouseWheelMoved)
//  */

// // catch paint events
// EVT_PAINT(wxImagePanel::paintEvent)

// END_EVENT_TABLE()

// // some useful events
// /*
//  void wxImagePanel::mouseMoved(wxMouseEvent& event) {}
//  void wxImagePanel::mouseDown(wxMouseEvent& event) {}
//  void wxImagePanel::mouseWheelMoved(wxMouseEvent& event) {}
//  void wxImagePanel::mouseReleased(wxMouseEvent& event) {}
//  void wxImagePanel::rightClick(wxMouseEvent& event) {}
//  void wxImagePanel::mouseLeftWindow(wxMouseEvent& event) {}
//  void wxImagePanel::keyPressed(wxKeyEvent& event) {}
//  void wxImagePanel::keyReleased(wxKeyEvent& event) {}
//  */

// wxImagePanel::wxImagePanel(wxFrame *parent, wxString file, wxBitmapType format) : wxPanel(parent)
// {
//     // load the file... ideally add a check to see if loading was successful
//     image.LoadFile(file, format);
// }

// /*
//  * Called by the system of by wxWidgets when the panel needs
//  * to be redrawn. You can also trigger this call by
//  * calling Refresh()/Update().
//  */

// void wxImagePanel::paintEvent(wxPaintEvent &evt)
// {
//     // depending on your system you may need to look at double-buffered dcs
//     wxPaintDC dc(this);
//     render(dc);
// }

// /*
//  * Alternatively, you can use a clientDC to paint on the panel
//  * at any time. Using this generally does not free you from
//  * catching paint events, since it is possible that e.g. the window
//  * manager throws away your drawing when the window comes to the
//  * background, and expects you will redraw it when the window comes
//  * back (by sending a paint event).
//  */
// void wxImagePanel::paintNow()
// {
//     // depending on your system you may need to look at double-buffered dcs
//     wxClientDC dc(this);
//     render(dc);
// }

// /*
//  * Here we do the actual rendering. I put it in a separate
//  * method so that it can work no matter what type of DC
//  * (e.g. wxPaintDC or wxClientDC) is used.
//  */
// void wxImagePanel::render(wxDC &dc)
// {
//     dc.DrawBitmap(image, 0, 0, false);
// }

// // ----------------------------------------
// // how-to-use example

// class MyApp : public wxApp
// {

//     wxFrame *frame;
//     wxImagePanel *drawPane;

// public:
//     bool OnInit()
//     {
//         // make sure to call this first
//         wxInitAllImageHandlers();

//         wxBoxSizer *sizer = new wxBoxSizer(wxHORIZONTAL);
//         frame = new wxFrame(NULL, wxID_ANY, wxT("Hello wxDC"), wxPoint(50, 50), wxSize(800, 600));

//         // // then simply create like this
//         // drawPane = new wxImagePanel(frame, wxT(".asserts/Z_08.jpg"), wxBITMAP_TYPE_JPEG);
//         // sizer->Add(drawPane, 1, wxEXPAND);
//         wxImage image("horse.jpg");
//         wxBitmap bitmap(image);
//         wxPaintDC dc(frame);
//         dc.DrawBitmap(bitmap, 0, 0);

//         frame->SetSizer(sizer);

//         frame->Show();
//         return true;
//     }
// };

// wxInitAllImageHandlers(MyApp);

// IMPLEMENT_APP(MyApp)

#include <wx/wx.h>
#include <wx/listctrl.h>
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
};

MyFrame::MyFrame(const wxString &title, const wxPoint &pos, const wxSize &size)
    : wxFrame(nullptr, wxID_ANY, title, pos, size)
{
    wxListView *listView = new wxListView(this, wxID_ANY, wxDefaultPosition, wxSize(650, 450));
    listView->InsertColumn(0, "Name");
    listView->InsertItem(0, "Item");

    wxBoxSizer *s1 = new wxBoxSizer(wxVERTICAL);
    s1->Add(listView, 1, wxEXPAND | wxALL, 5);

    wxBoxSizer *s2 = new wxBoxSizer(wxHORIZONTAL);

    wxButton *cancel_btn = new wxButton(this, wxID_ANY, "Cancel");
    wxButton *submit_btn = new wxButton(this, wxID_ANY, "Submit");

    s2->Add(submit_btn, 0, wxRIGHT, 5);
    s2->Add(cancel_btn, 0);

    s1->Add(s2, 0, wxRIGHT | wxALIGN_RIGHT | wxBOTTOM, 5);

    this->SetBackgroundColour(wxColor(0, 0, 0));
    this->SetSizerAndFit(s1);
}

bool MyApp::OnInit()
{
    MyFrame *my_frame = new MyFrame("Remote Desktop App", wxDefaultPosition, wxDefaultSize);
    my_frame->Show();
    return true;
}