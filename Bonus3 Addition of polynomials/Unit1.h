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
	TTabSheet *TabSheet1;
	TMemo *Memo1;
	TTabSheet *TabSheet2;
	TMemo *Memo2;
	TButton *Button1;
	TLabel *Label1;
	TLabel *Label2;
	TButton *Button2;
	TEdit *Edit1;
	TEdit *Edit2;
	TGroupBox *GroupBox1;
	TLabel *Label3;
	TLabel *Label4;
	TEdit *Edit3;
	TEdit *Edit4;
	TButton *Button3;
	TButton *Button4;
	TButton *Button5;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
