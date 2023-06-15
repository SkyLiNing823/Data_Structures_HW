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
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TPageControl *PageControl1;
	TSplitter *Splitter1;
	TLabel *Label1;
	TEdit *Edit1;
	TLabel *Label2;
	TLabel *Label3;
	TEdit *Edit2;
	TEdit *Edit3;
	TTabSheet *TabSheet1;
	TMemo *Memo1;
	TCheckBox *CheckBox1;
	TTabSheet *TabSheet2;
	TStringGrid *StringGrid1;
	TButton *Button1;
	TLabel *Label4;
	TEdit *Edit4;
	TLabel *Label5;
	TEdit *Edit5;
	TEdit *Edit6;
	TEdit *Edit7;
	TTabSheet *TabSheet3;
	TStringGrid *StringGrid2;
	TButton *Button2;
	TTrackBar *TrackBar1;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall StringGrid1DrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall StringGrid2DrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
