// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Magic_Square.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int size;
int square[21][21]; // ぃよMagic_Square
int square2[21][21];
int square3[21][21];
int square4[21][21];

void magic_square(int n) {
	int i, j, k, l, p, data;
	if ((n > 21) || (n < 3)) {
		Form1->Memo1->Lines->Add("Size goes WRONG: 3 <= n < = 21 !!!"); // ň
		Form1->Memo2->Lines->Add("Size goes WRONG: 3 <= n < = 21 !!!");
		Form1->Memo3->Lines->Add("Size goes WRONG: 3 <= n < = 21 !!!");
		Form1->Memo4->Lines->Add("Size goes WRONG: 3 <= n < = 21 !!!");
	}
	else if (n % 2 == 0) {
		Form1->Memo1->Lines->Add("Please Input an ODD Number !!!"); // 案计窽ゎ
		Form1->Memo2->Lines->Add("Please Input an ODD Number !!!");
		Form1->Memo3->Lines->Add("Please Input an ODD Number !!!");
		Form1->Memo4->Lines->Add("Please Input an ODD Number !!!");
	}
	else {
		Form1->Memo1->Lines->Add("-------- Magic Square " + IntToStr(size) +
			"x" + IntToStr(size) + " --------");
		Form1->Memo2->Lines->Add("-------- Magic Square " + IntToStr(size) +
			"x" + IntToStr(size) + " --------");
		Form1->Memo3->Lines->Add("-------- Magic Square " + IntToStr(size) +
			"x" + IntToStr(size) + " --------");
		Form1->Memo4->Lines->Add("-------- Magic Square " + IntToStr(size) +
			"x" + IntToStr(size) + " --------");
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++) {
				square[i][j] = 0;
				square2[i][j] = 0;
				square3[i][j] = 0;
				square4[i][j] = 0;
			}
		i = 0, j = (n - 1) / 2;
		square[i][j] = 1;
		square2[i][j] = 1;
		square3[i][j] = 1;
		square4[i][j] = 1;
		data = 2;
		while (data <= n * n) { // Left-Up
			k = (i - 1 < 0) ? n - 1 : i - 1;
			l = (j - 1 < 0) ? n - 1 : j - 1;
			if (square[k][l] > 0)
				i = (i + 1) % n;     //Τ计玥
			else {
				i = k;
				j = l;
			}
			square[i][j] = data++;
		}
		data = 2;
		i = 0, j = (n - 1) / 2;
		while (data <= n * n) { // Left-Down
			k = (i + 1 > n - 1) ? 0 : i + 1;
			l = (j - 1 < 0) ? n - 1 : j - 1;
			if (square2[k][l] > 0)
				j = (j + 1) % n;     //Τ计玥
			else {
				i = k;
				j = l;
			}
			square2[i][j] = data++;
		}
		data = 2;
		i = 0, j = (n - 1) / 2;
		while (data <= n * n) { // Right-Up
			k = (i - 1 < 0) ? n - 1 : i - 1;
			l = (j + 1 > n - 1) ? 0 : j + 1;
			if (square3[k][l] > 0)
				j = (j + 2) % n;   //Τ计玥オ
			else {
				i = k;
				j = l;
			}
			square3[i][j] = data++;
		}
		data = 2;
		i = 0, j = (n - 1) / 2;
		while (data <= n * n) { // Right-Down
			k = (i + 1 > n - 1) ? 0 : i + 1;
			l = (j + 1 > n - 1) ? 0 : j + 1;
			if (square4[k][l] > 0)
				i = (i + 2) % n;    //Τ计玥
			else {
				i = k;
				j = l;
			}
			square4[i][j] = data++;
		}
		for (i = 0; i < n; i++) {
			String tmp = ""; // 瞓string
			String tmp2 = "";
			String tmp3 = "";
			String tmp4 = "";
			for (j = 0; j < n; j++) {
				int length = IntToStr(square[i][j]).Length();
				for (p = 0; p <= 4 - length; p++) // 璸衡┮惠
						tmp += "  ";
				tmp += IntToStr(square[i][j]);
				length = IntToStr(square2[i][j]).Length();
				for (p = 0; p <= 4 - length; p++)
					tmp2 += "  ";
				tmp2 += IntToStr(square2[i][j]);
				length = IntToStr(square3[i][j]).Length();
				for (p = 0; p <= 4 - length; p++)
					tmp3 += "  ";
				tmp3 += IntToStr(square3[i][j]);
				length = IntToStr(square4[i][j]).Length();
				for (p = 0; p <= 4 - length; p++)
					tmp4 += "  ";
				tmp4 += IntToStr(square4[i][j]);
			}
			Form1->Memo1->Lines->Add(tmp);
			Form1->Memo2->Lines->Add(tmp2);
			Form1->Memo3->Lines->Add(tmp3);
			Form1->Memo4->Lines->Add(tmp4);
		}

	}
}

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender) {
	size = StrToInt(Edit1->Text);
	magic_square(size);

}
// ---------------------------------------------------------------------------
