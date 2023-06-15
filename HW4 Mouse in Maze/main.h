//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TSplitter *Splitter1;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TLabel *Label1;
	TLabel *Label2;
	TEdit *Edit1;
	TEdit *Edit2;
	TOpenDialog *OpenDialog1;
	TSaveDialog *SaveDialog1;
	TLabel *Label3;
	TEdit *Edit3;
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TMemo *Memo1;
	TTabSheet *TabSheet2;
	TStringGrid *StringGrid1;
	TTabSheet *TabSheet3;
	TStringGrid *StringGrid2;
	TTabSheet *TabSheet4;
	TStringGrid *StringGrid3;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall StringGrid1DrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State);
	void __fastcall StringGrid2DrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State);
	void __fastcall StringGrid3DrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State);

private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
