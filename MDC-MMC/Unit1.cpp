//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include <math>
#include <string>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TPrincipal *Principal;

int mmc_function(int a, int b)
  {
     int aa, bb;
     int resto;

     aa = a;
     bb = b;


     while(bb != 0)
      {
        resto = aa % bb;
        aa = bb;
        bb = resto;
      }

    return a*b / aa;
  }

int mdc_function(int a, int b)
 {
    int resto;


     while(b != 0)
     {
      resto = a % b;
      a = b;
      b = resto;
     }

    return a;
 }

//---------------------------------------------------------------------------
__fastcall TPrincipal::TPrincipal(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TPrincipal::Button3Click(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------
void __fastcall TPrincipal::Button2Click(TObject *Sender)
{
  EditNumber1->Text = "0";
  EditNumber2->Text = "0";
  EditMMCResult->Text = "0";
  EditMDCResult->Text = "0";
}
//---------------------------------------------------------------------------
void __fastcall TPrincipal::Button1Click(TObject *Sender)
{
   int number1, number2;
   int tmp_result;

   number1 = StrToInt(EditNumber1->Text);
   number2 = StrToInt(EditNumber2->Text);

   if(number1 == 0 || number2 == 0)
     {
       ShowMessage("Perigo de Exce��o, divis�o por zero !!!");
       return;
     }

   if(RDMDC->Checked)
    {
      tmp_result = mdc_function(number1, number2);
      EditMMCResult->Enabled = False;
      EditMDCResult->Enabled = True;
      EditMDCResult->Text = IntToStr(tmp_result);
    }
   else if(RDMMC->Checked)
          {

            tmp_result = mmc_function(number1, number2);
            EditMDCResult->Enabled = False;
            EditMMCResult->Enabled = True;
            EditMMCResult->Text = IntToStr(tmp_result);


          }
        else if(RBAMBOS->Checked)
              {
                 EditMDCResult->Enabled = True;
                 EditMMCResult->Enabled = True;
                 tmp_result = mdc_function(number1, number2);
                 EditMDCResult->Text = IntToStr(tmp_result);
                 tmp_result = mmc_function(number1, number2);
                 EditMMCResult->Text = IntToStr(tmp_result);

              }


}
//---------------------------------------------------------------------------
