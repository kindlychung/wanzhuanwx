
#include <wx/app.h>
#include <wx/wx.h>
#include <iostream>

class MyApp : public wxApp {
   public:
    virtual bool OnInit();
};

class MyFrame : public wxFrame {
   public:
    MyFrame(const wxString& title);
    void OnQuit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);

   private:
    DECLARE_EVENT_TABLE();
};

DECLARE_APP(MyApp);
IMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
    MyFrame* frame = new MyFrame(wxT("Minimal app"));
    frame->Show(true);
    return true;
}

BEGIN_EVENT_TABLE(MyFrame, wxFrame)
EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
EVT_MENU(wxID_EXIT, MyFrame::OnQuit)
END_EVENT_TABLE()

void MyFrame::OnAbout(wxCommandEvent& event) {
    wxString msg;
    msg.Printf(wxT("welcome to app, v%s"), wxVERSION_STRING);
    wxMessageBox(msg, wxT("About"), wxOK | wxICON_INFORMATION, this);
}

void MyFrame::OnQuit(wxCommandEvent& event) { Close(); }

#include "icon.xpm"

MyFrame::MyFrame(const wxString& title) : wxFrame(NULL, wxID_ANY, title) {
    SetIcon(wxIcon(icon));
    wxMenu* helpMenu = new wxMenu;
    wxMenu* fileMenu = new wxMenu;
    helpMenu->Append(wxID_ABOUT, wxT("&About...\tF1"),
                     wxT("Show about dialog"));
    fileMenu->Append(wxID_EXIT, wxT("E&xit\tAlt-X"), wxT("Quit this app"));
    wxMenuBar* menubar = new wxMenuBar;
    menubar->Append(fileMenu, wxT("&File"));
    menubar->Append(helpMenu, wxT("&Help"));
    SetMenuBar(menubar);
    CreateStatusBar(2);
    SetStatusText(wxT("welcome"));
}
