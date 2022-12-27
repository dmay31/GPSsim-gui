#include "Controls.h"



Controls::Controls(wxFrame* parent) : wxPanel(parent)
{
	wxStaticBoxSizer *sz = new wxStaticBoxSizer(wxVERTICAL, this, "Box");
	wxButton* aStartButton = new wxButton(sz->GetStaticBox(), 1, wxString("Start"));
	wxButton* aStopButton = new wxButton(sz->GetStaticBox(), 1, wxString("Stop"));
	sz->Add(aStartButton);
	sz->Add(aStopButton);
	SetSizer(sz);
}


Controls::~Controls()
{
}
