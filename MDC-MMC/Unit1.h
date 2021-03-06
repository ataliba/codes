//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class TPrincipal : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *GroupBox1;
        TEdit *EditNumber1;
        TEdit *EditNumber2;
        TLabel *Label1;
        TLabel *Label2;
        TGroupBox *GroupBox2;
        TEdit *EditMMCResult;
        TLabel *Label3;
        TEdit *EditMDCResult;
        TLabel *Label4;
        TPanel *Panel1;
        TStatusBar *StatusBar1;
        TButton *Button1;
        TButton *Button2;
        TButton *Button3;
        TGroupBox *GroupBox3;
        TRadioButton *RDMMC;
        TRadioButton *RDMDC;
        TRadioButton *RBAMBOS;
        TImage *Image1;
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TPrincipal(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TPrincipal *Principal;
//---------------------------------------------------------------------------
#endif
