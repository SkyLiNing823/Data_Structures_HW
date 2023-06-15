//---------------------------------------------------------------------------

#ifndef Magic_SquareH
#define Magic_SquareH
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
	TPageControl *PageControl1;
	TPanel *Panel1;
	TSplitter *Splitter1;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet2;
	TLabel *Label1;
	TEdit *Edit1;
	TLabel *Label2;
	TButton *Button1;
	TMemo *Memo1;
	TMemo *Memo2;
	TTabSheet *TabSheet3;
	TTabSheet *TabSheet4;
	TMemo *Memo3;
	TMemo *Memo4;
	void __fastcall Button1Click(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
