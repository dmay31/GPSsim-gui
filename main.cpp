#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include <wx/sizer.h>
#include <wx/button.h>
#include "PolarGraph.h"
#include "Controls.h"

#define WIDTH  800
#define HEIGHT 800

class MyApp : public wxApp
{
public:
	virtual bool OnInit();
};

wxIMPLEMENT_APP(MyApp);

class MyFrame : public wxFrame
{
public:
	MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
};

bool MyApp::OnInit() {
	MyFrame *frame = new MyFrame("GPS-GUI", wxPoint(50, 50), wxSize(WIDTH, HEIGHT));

	frame->Show(true);
	return true;
}

MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
	: wxFrame(NULL, wxID_ANY, title, pos, size, wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER | wxMAXIMIZE_BOX))

{
	
	auto aSkyView = new PolarGraph(this, wxSize(250,250));
	auto aControl = new Controls(this);
	auto aConsole = new wxStaticText(this, 1, "Debug Messages");
	aSkyView->SetMinSize(wxSize(500, 600));

	auto hDiv = new wxBoxSizer(wxVERTICAL);
	auto vDiv = new wxBoxSizer(wxHORIZONTAL);
	hDiv->Add(vDiv, 1, wxEXPAND);
	vDiv->Add(aSkyView, 1, wxEXPAND | wxALL);
	vDiv->Add(aControl, 1, wxEXPAND | wxALL);
	hDiv->Add(aConsole, 1, wxEXPAND | wxALL);

	SetSizer(hDiv);
	SetAutoLayout(true);
}
