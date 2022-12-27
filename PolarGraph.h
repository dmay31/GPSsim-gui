#pragma once

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

class PolarGraph : public wxPanel
{
public:
	PolarGraph(wxFrame* parent, wxSize aGraphCenter);
	virtual ~PolarGraph();

private:
	static constexpr int sCircleRadius = 190;
	static constexpr int sSatelliteRadius = 5;

	void DrawSatellite(int aAzimuth, int aElevation);
	void paintEvent(wxPaintEvent & evt);
	void render(wxDC&  dc);
	
	wxSize mCenter;

	DECLARE_EVENT_TABLE()
};

