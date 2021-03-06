#ifndef SERIALPORTWITHRATE_H
#define SERIALPORTWITHRATE_H

//(*Headers(SerialPortWithRate)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/choice.h>
#include <wx/dialog.h>
//*)

class SerialPortWithRate: public wxDialog
{
public:

    SerialPortWithRate(wxWindow* parent);
    virtual ~SerialPortWithRate();
    void ProtocolChange();
    wxString GetRateString();

    //(*Declarations(SerialPortWithRate)
    wxChoice* ChoiceProtocol;
    wxTextCtrl* TextCtrl_Description;
    wxStaticText* StaticText2;
    wxStaticText* StaticTextRate;
    wxChoice* ChoicePort;
    wxStaticText* StaticText1;
    wxStaticText* StaticText3;
    wxTextCtrl* TextCtrlLastChannel;
    wxStaticText* StaticTextExplanation;
    wxChoice* ChoiceBaudRate;
    wxStaticText* StaticTextPort;
    //*)


protected:

    //(*Identifiers(SerialPortWithRate)
    static const long ID_CHOICE_PROTOCOL;
    static const long ID_STATICTEXT_EXPLANATION;
    static const long ID_STATICTEXT_PORT;
    static const long ID_CHOICE_PORT;
    static const long ID_STATICTEXT_RATE;
    static const long ID_CHOICE_BAUD_RATE;
    static const long ID_STATICTEXT3;
    static const long ID_TEXTCTRL_LAST_CHANNEL;
    static const long ID_STATICTEXT1;
    static const long ID_STATICTEXT2;
    static const long ID_TEXTCTRL_DESCRIPTION;
    //*)

private:

    //(*Handlers(SerialPortWithRate)
    void OnChoiceProtocolSelect(wxCommandEvent& event);
    void OnTextCtrl_DescriptionText(wxCommandEvent& event);
    //*)

    wxFlexGridSizer* MainSizer;
    void PopulatePortChooser(wxArrayString *chooser);
    void SetLabel(const wxString& newlabel);

    DECLARE_EVENT_TABLE()
};

#endif
