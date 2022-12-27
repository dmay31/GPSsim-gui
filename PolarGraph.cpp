#include "PolarGraph.h"
#include<cmath>
#include <math.h>

BEGIN_EVENT_TABLE(PolarGraph, wxPanel)
// some useful events
/*
 EVT_MOTION(BasicDrawPane::mouseMoved)
 EVT_LEFT_DOWN(BasicDrawPane::mouseDown)
 EVT_LEFT_UP(BasicDrawPane::mouseReleased)
 EVT_RIGHT_DOWN(BasicDrawPane::rightClick)
 EVT_LEAVE_WINDOW(BasicDrawPane::mouseLeftWindow)
 EVT_KEY_DOWN(BasicDrawPane::keyPressed)
 EVT_KEY_UP(BasicDrawPane::keyReleased)
 EVT_MOUSEWHEEL(BasicDrawPane::mouseWheelMoved)
 */

 // catch paint events
EVT_PAINT(PolarGraph::paintEvent)

END_EVENT_TABLE()

PolarGraph::PolarGraph(wxFrame* parent, wxSize aGraphCenter) : wxPanel(parent), mCenter(aGraphCenter)
{
}


PolarGraph::~PolarGraph()
{
}

void PolarGraph::DrawSatellite(int aAzimuth, int aElevation) {

}

void PolarGraph::paintEvent(wxPaintEvent & evt) {
	wxPaintDC dc(this);
	render(dc);
}

void PolarGraph::render(wxDC&  dc) {
	int xCenter = mCenter.GetWidth();
	int yCenter = mCenter.GetHeight();

	auto aBrush = new wxBrush(wxColor(0, 0, 0));
	auto aPen = new wxPen(wxColor(0, 0, 0), 2, wxPENSTYLE_DOT);
	//dc.SetBrush(*aBrush);
	dc.DrawCircle(wxPoint(xCenter, yCenter), sCircleRadius );
	dc.SetPen(*aPen);
	dc.DrawCircle(wxPoint(xCenter, yCenter), sCircleRadius - 60 );
	dc.DrawCircle(wxPoint(xCenter, yCenter), sCircleRadius - 120 );
	dc.DrawLine(xCenter, xCenter - sCircleRadius, xCenter, xCenter + sCircleRadius); // draw line across the rectangle
	dc.DrawLine(xCenter - sCircleRadius, yCenter, yCenter + sCircleRadius, yCenter); // draw line across the rectangle

	auto sz90 = dc.GetTextExtent("90");
	auto sz180 = dc.GetTextExtent("180");
	auto sz270 = dc.GetTextExtent("270");
	auto sz0 = dc.GetTextExtent("0");
	dc.DrawRotatedText("0", { xCenter + sCircleRadius + 4, yCenter - dc.GetCharHeight()/2 }, 0);
	dc.DrawRotatedText("90", { xCenter - sz90.GetWidth()/2, 60 - dc.GetCharHeight() }, 0);
	dc.DrawRotatedText("180", { xCenter - sCircleRadius - sz180.GetWidth() - 4, yCenter - dc.GetCharHeight() / 2 }, 0);
	dc.DrawRotatedText("270", { xCenter - sz270.GetWidth() / 2, 440 + 1 }, 0);

	// Draw 45 degree lines
	double y = sCircleRadius * sin(45 * (M_PI / 180));
	double x = sCircleRadius * cos(45 * (M_PI / 180));
	dc.DrawLine(xCenter - x, yCenter + y, xCenter + x, yCenter - y);
	dc.DrawLine(xCenter - x, yCenter - y, xCenter + x, yCenter + y);

	dc.SetPen(wxPen(wxColor(0, 0, 255), 2));
	dc.DrawCircle(wxPoint(xCenter + 20, yCenter - 30), 5);


}
