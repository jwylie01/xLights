#include "OnPanel.h"

//(*InternalHeaders(OnPanel)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>
#include <wx/slider.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(OnPanel)
const long OnPanel::IDD_SLIDER_Eff_On_Start = wxNewId();
const long OnPanel::ID_TEXTCTRL_Eff_On_Start = wxNewId();
const long OnPanel::IDD_SLIDER_Eff_On_End = wxNewId();
const long OnPanel::ID_TEXTCTRL_Eff_On_End = wxNewId();
const long OnPanel::IDD_SLIDER_On_Cycles = wxNewId();
const long OnPanel::ID_TEXTCTRL_On_Cycles = wxNewId();
const long OnPanel::ID_CHECKBOX_On_Shimmer = wxNewId();
//*)

BEGIN_EVENT_TABLE(OnPanel,wxPanel)
	//(*EventTable(OnPanel)
	//*)
END_EVENT_TABLE()

#include "EffectPanelUtils.h"

OnPanel::OnPanel(wxWindow* parent)
{
	//(*Initialize(OnPanel)
	wxTextCtrl* TextCtrl_Eff_On_End;
	wxFlexGridSizer* FlexGridSizer95;
	wxStaticText* StaticText174;
	wxFlexGridSizer* FlexGridSizer96;
	wxTextCtrl* TextCtrl_Eff_On_Start;
	wxStaticText* StaticText114;
	wxStaticText* StaticText73;
	wxCheckBox* CheckBox2;
	wxSlider* Slider7;
	wxSlider* Slider_Eff_On_End;
	wxStaticText* StaticText113;
	wxTextCtrl* TextCtrl24;
	wxFlexGridSizer* FlexGridSizer93;
	wxSlider* Slider_Eff_On_Start;
	wxFlexGridSizer* FlexGridSizer92;

	Create(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("wxID_ANY"));
	FlexGridSizer92 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer92->AddGrowableCol(0);
	FlexGridSizer96 = new wxFlexGridSizer(0, 1, 0, 0);
	StaticText73 = new wxStaticText(this, wxID_ANY, _("This Effect turns every pixel on."), wxDefaultPosition, wxDefaultSize, 0, _T("wxID_ANY"));
	FlexGridSizer96->Add(StaticText73, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer92->Add(FlexGridSizer96, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 2);
	FlexGridSizer93 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer93->AddGrowableCol(0);
	FlexGridSizer95 = new wxFlexGridSizer(0, 3, 0, 0);
	FlexGridSizer95->AddGrowableCol(1);
	StaticText113 = new wxStaticText(this, wxID_ANY, _("Start Intensity"), wxDefaultPosition, wxDefaultSize, 0, _T("wxID_ANY"));
	FlexGridSizer95->Add(StaticText113, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 2);
	Slider_Eff_On_Start = new wxSlider(this, IDD_SLIDER_Eff_On_Start, 100, 0, 100, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("IDD_SLIDER_Eff_On_Start"));
	FlexGridSizer95->Add(Slider_Eff_On_Start, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 2);
	TextCtrl_Eff_On_Start = new wxTextCtrl(this, ID_TEXTCTRL_Eff_On_Start, _("100"), wxDefaultPosition, wxDLG_UNIT(this,wxSize(20,-1)), wxTE_PROCESS_ENTER, wxDefaultValidator, _T("ID_TEXTCTRL_Eff_On_Start"));
	FlexGridSizer95->Add(TextCtrl_Eff_On_Start, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 2);
	StaticText114 = new wxStaticText(this, wxID_ANY, _("End Intensity"), wxDefaultPosition, wxDefaultSize, 0, _T("wxID_ANY"));
	FlexGridSizer95->Add(StaticText114, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 2);
	Slider_Eff_On_End = new wxSlider(this, IDD_SLIDER_Eff_On_End, 100, 0, 100, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("IDD_SLIDER_Eff_On_End"));
	FlexGridSizer95->Add(Slider_Eff_On_End, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 2);
	TextCtrl_Eff_On_End = new wxTextCtrl(this, ID_TEXTCTRL_Eff_On_End, _("100"), wxDefaultPosition, wxDLG_UNIT(this,wxSize(20,-1)), wxTE_PROCESS_ENTER, wxDefaultValidator, _T("ID_TEXTCTRL_Eff_On_End"));
	FlexGridSizer95->Add(TextCtrl_Eff_On_End, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 2);
	StaticText174 = new wxStaticText(this, wxID_ANY, _("Cycle Count"), wxDefaultPosition, wxDefaultSize, 0, _T("wxID_ANY"));
	FlexGridSizer95->Add(StaticText174, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 2);
	Slider7 = new wxSlider(this, IDD_SLIDER_On_Cycles, 10, 0, 200, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("IDD_SLIDER_On_Cycles"));
	FlexGridSizer95->Add(Slider7, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	TextCtrl24 = new wxTextCtrl(this, ID_TEXTCTRL_On_Cycles, _("1.0"), wxDefaultPosition, wxDLG_UNIT(this,wxSize(20,-1)), 0, wxDefaultValidator, _T("ID_TEXTCTRL_On_Cycles"));
	TextCtrl24->SetMaxLength(4);
	FlexGridSizer95->Add(TextCtrl24, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 2);
	FlexGridSizer93->Add(FlexGridSizer95, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 2);
	FlexGridSizer92->Add(FlexGridSizer93, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 2);
	CheckBox2 = new wxCheckBox(this, ID_CHECKBOX_On_Shimmer, _("Shimmer"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_On_Shimmer"));
	CheckBox2->SetValue(false);
	FlexGridSizer92->Add(CheckBox2, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FlexGridSizer92);
	FlexGridSizer92->Fit(this);
	FlexGridSizer92->SetSizeHints(this);

	Connect(IDD_SLIDER_Eff_On_Start,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&OnPanel::UpdateLinkedTextCtrl);
	Connect(ID_TEXTCTRL_Eff_On_Start,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&OnPanel::UpdateLinkedSlider);
	Connect(IDD_SLIDER_Eff_On_End,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&OnPanel::UpdateLinkedTextCtrl);
	Connect(ID_TEXTCTRL_Eff_On_End,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&OnPanel::UpdateLinkedSlider);
	Connect(IDD_SLIDER_On_Cycles,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&OnPanel::UpdateLinkedTextCtrlFloat);
	Connect(ID_TEXTCTRL_On_Cycles,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&OnPanel::UpdateLinkedSliderFloat);
	//*)
    
    SetName("ID_PANEL_ON");
}

OnPanel::~OnPanel()
{
	//(*Destroy(OnPanel)
	//*)
}

PANEL_EVENT_HANDLERS(OnPanel)
