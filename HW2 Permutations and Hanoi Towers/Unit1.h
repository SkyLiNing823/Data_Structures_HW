//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TSplitter *Splitter1;
	TLabel *Label1;
	TLabel *Label2;
	TButton *Button1;
	TPageControl *PageControl2;
	TTabSheet *TabSheet4;
	TTabSheet *TabSheet5;
	TTabSheet *TabSheet6;
	TEdit *Edit1;
	TEdit *Edit2;
	TLabel *Label3;
	TCheckBox *CheckBox1;
	TLabel *Label4;
	TEdit *Edit3;
	TButton *Button2;
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TMemo *Memo1;
	TTabSheet *TabSheet2;
	TMemo *Memo2;
	TCheckBox *CheckBox2;
	TLabel *Label5;
	TLabel *Label6;
	TEdit *Edit4;
	TLabel *Label7;
	TEdit *Edit5;
	TButton *Button3;
	TCheckBox *CheckBox3;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);


private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
