#include <wx/dnd.h>
#include "TopEffectsPanel.h"
#include <wx/event.h>
#include "xLightsMain.h"
#include "sequencer/EffectDropTarget.h"
#include "../include/Off.xpm"

//(*InternalHeaders(TopEffectsPanel)
#include <wx/bitmap.h>
#include <wx/settings.h>
#include <wx/intl.h>
#include <wx/image.h>
#include <wx/string.h>
//*)

//(*IdInit(TopEffectsPanel)
const long TopEffectsPanel::ID_BUTTON_UpdateEffect = wxNewId();
const long TopEffectsPanel::ID_BITMAPBUTTON_SelectedEffect = wxNewId();
//*)

BEGIN_EVENT_TABLE(TopEffectsPanel,wxPanel)
	//(*EventTable(TopEffectsPanel)
	//*)
END_EVENT_TABLE()

TopEffectsPanel::TopEffectsPanel(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(TopEffectsPanel)
	wxFlexGridSizer* FlexGridSizer3;
	wxFlexGridSizer* FlexGridSizer5;
	wxFlexGridSizer* FlexGridSizer2;

	Create(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("wxID_ANY"));
	MainSizer = new wxFlexGridSizer(0, 2, 0, 0);
	FlexGridSizer2 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer3 = new wxFlexGridSizer(0, 3, 0, 0);
	FlexGridSizer3->AddGrowableCol(0);
	FlexGridSizer3->AddGrowableCol(1);
	FlexGridSizer3->AddGrowableCol(2);
	FlexGridSizer3->Add(-1,-1,1, wxALL|wxEXPAND, 5);
	FlexGridSizer5 = new wxFlexGridSizer(0, 2, 0, 0);
	ButtonUpdateEffect = new wxButton(this, ID_BUTTON_UpdateEffect, _("Update (F5)"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_UpdateEffect"));
	FlexGridSizer5->Add(ButtonUpdateEffect, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BitmapButtonSelectedEffect = new DragEffectBitmapButton(this, ID_BITMAPBUTTON_SelectedEffect, Off, wxDefaultPosition, wxSize(13,13), wxBU_AUTODRAW|wxNO_BORDER, wxDefaultValidator, _T("ID_BITMAPBUTTON_SelectedEffect"));
	BitmapButtonSelectedEffect->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
	FlexGridSizer5->Add(BitmapButtonSelectedEffect, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer3->Add(FlexGridSizer5, 1, wxALL|wxEXPAND, 5);
	FlexGridSizer3->Add(-1,-1,1, wxALL|wxEXPAND, 5);
	FlexGridSizer2->Add(FlexGridSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	EffectSizer = new wxFlexGridSizer(0, 2, 0, 0);
	FlexGridSizer2->Add(EffectSizer, 1, wxALL|wxEXPAND, 0);
	MainSizer->Add(FlexGridSizer2, 1, wxALL|wxEXPAND, 5);
	SetSizer(MainSizer);
	MainSizer->Fit(this);
	MainSizer->SetSizeHints(this);

	Connect(ID_BUTTON_UpdateEffect,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TopEffectsPanel::OnButtonUpdateEffectClick);
	Connect(ID_BITMAPBUTTON_SelectedEffect,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TopEffectsPanel::OnBitmapButtonSelectedEffectClick);
	Connect(wxEVT_SIZE,(wxObjectEventFunction)&TopEffectsPanel::OnResize);
	//*)

    SetDropTarget(new EffectDropTarget((wxWindow*)this,false));
    BitmapButtonSelectedEffect->SetBitmap(wxBitmap(Off));
}

TopEffectsPanel::~TopEffectsPanel()
{
	//(*Destroy(TopEffectsPanel)
	//*)
}


void TopEffectsPanel::SetDragIconBuffer(const wxBitmap &buffer)
{
    BitmapButtonSelectedEffect->SetBitmap(buffer);
}

void TopEffectsPanel::OnResize(wxSizeEvent& event)
{
    wxCommandEvent eventWindowResized(EVT_WINDOW_RESIZED);
    wxPostEvent(GetParent(), eventWindowResized);
    Refresh();
}

void TopEffectsPanel::OnBitmapButtonSelectedEffectClick(wxCommandEvent& event)
{

}

void TopEffectsPanel::OnLeftDown(wxMouseEvent& event)
{
}


void TopEffectsPanel::OnButtonUpdateEffectClick(wxCommandEvent& event)
{
    wxCommandEvent eventEffectUpdated(EVT_EFFECT_UPDATED);
    wxPostEvent(GetParent(), eventEffectUpdated);
    Refresh();
}
