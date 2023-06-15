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
	TPageControl *PageControl1;
	TSplitter *Splitter1;
	TSplitter *Splitter2;
	TLabel *Label1;
	TLabel *Label2;
	TEdit *Edit1;
	TEdit *Edit2;
	TButton *Button1;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet2;
	TMemo *Memo1;
	TEdit *Edit3;
	TLabel *Label3;
	TGroupBox *GroupBox1;
	TGroupBox *GroupBox2;
	TLabel *Label4;
	TEdit *Edit4;
	TButton *Button2;
	TMemo *Memo2;
	TLabel *Label5;
	TEdit *Edit5;
	TEdit *Edit6;
	TLabel *Label6;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);


private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
