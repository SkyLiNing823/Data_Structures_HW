// ---------------------------------------------------------------------------
#include <vcl.h>
#include<string>
#pragma hdrstop

#include "Unit1.h"

#define SWAP(x,y,t)(t=x,x=y,y=t)
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;
int k, n, count;

void permStr(String in_string, int k, int n, bool check) {
	int i;
	wchar_t tmp; // 定義 tmp 為 wchar_t 型態 (佔2 bytes) ，可存放中文字
	if (k == n) {
		if (check) {
			Form1->Memo2->Lines->Add("==>(k,n)=(" + IntToStr(k) + "," +
				IntToStr(n) + ")! k==n print!");
			Form1->Memo2->Lines->Add(in_string + "  [" + IntToStr(count) + "]");
		}
		Form1->Memo1->Lines->Add(in_string + "  [" + IntToStr(count++) + "]");
	}
	else {
		for (i = k; i <= n; i++) {
			SWAP(in_string[k], in_string[i], tmp);
			if (check) {
				Form1->Memo2->Lines->Add(">i=" + IntToStr(i) + " (k,n)=(" +
					IntToStr(k) + "," + IntToStr(n) + "), swap[k,i]=[" +
					IntToStr(k) + "," + IntToStr(i) + "] list[]=" + in_string);
			}
			permStr(in_string, k + 1, n, check);
			SWAP(in_string[k], in_string[i], tmp);
			if (check) {
				Form1->Memo2->Lines->Add("<i=" + IntToStr(i) + " (k,n)=(" +
					IntToStr(k) + "," + IntToStr(n) + "), swap[k,i]=[" +
					IntToStr(k) + "," + IntToStr(i) + "] list[]=" + in_string);
			}
		}

	}
}

void Hanoi(int disk, String source, String spare, String destination) {
	if (disk == 1) {
		Form1->Memo1->Lines->Add("STEP " + IntToStr(++count) +
			": Moving disk from " + source + " to " + destination);
		if (Form1->CheckBox3->Checked) {
			Form1->Memo2->Lines->Add("<" + IntToStr(disk) +
				"> Try moving the top " + IntToStr(disk) + " disk from Tower " +
				source + " to Tower " + destination);
			Form1->Memo2->Lines->Add("STEP " + IntToStr(count) +
				": Moving disk from " + source + " to " + destination);
		}

	}
	else {
		if (Form1->CheckBox3->Checked) {
			Form1->Memo2->Lines->Add("<" + IntToStr(disk) +
				"> Try moving the top " + IntToStr(disk) + " disk from Tower " +
				source + " to Tower " + destination);
		}
		Hanoi(disk - 1, source, destination, spare);
		Hanoi(1, source, spare, destination);
		Hanoi(disk - 1, spare, source, destination);
	}

}

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent * Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject * Sender) {
	k = StrToInt(Edit1->Text);
	n = StrToInt(Edit2->Text);
	bool check = false;
	char charStr[9];
	if (n > 9)
		Form1->Memo1->Lines->Add("n should be <= 9 !!!"); // 防呆
	else if (k >= n)
		Form1->Memo1->Lines->Add("k should be < n !!!"); // 防呆
	else {
		for (int i = 0; i < n; i++) {
			char A = 'A';
			charStr[i] = A + i; // 利用ascii碼來添加字母
		}
		if (Form1->CheckBox1->Checked) {
			check = true;
			Form1->Memo2->Lines->Add("Go==>(k,n)=(" + IntToStr(k) + "," +
				IntToStr(n) + ")");
			Form1->Memo2->Lines->Add(">i=0 (k,n)=(" + IntToStr(k) + "," +
				IntToStr(n) + "), swap[k,x]=[0,0], list[]=" + charStr);
		}
		count = 0;
		permStr(charStr, k + 1, n, check);
		if (Form1->CheckBox1->Checked)
			Form1->Memo2->Lines->Add
				("----------------------------------------------");
	}
	Form1->Memo1->Lines->Add("----------------------------------------------");

}

// ---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject * Sender) {
	int disk = StrToInt(Edit3->Text);
	count = 0;
	Hanoi(disk, "A", "B", "C");
	Form1->Memo1->Lines->Add("----- " + IntToStr(count) + " step(s) in total " +
		IntToStr(disk) + " disk(s) -----");
	if (Form1->CheckBox3->Checked) {
		Form1->Memo2->Lines->Add("----- " + IntToStr(count) +
			" step(s) in total " + IntToStr(disk) + " disk(s) -----");
	}
}

// ---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject * Sender) {
	k = StrToInt(Edit5->Text);
	String str = Edit4->Text;
	n = str.Length();
	bool check = false;
	if (n > 9)
		Form1->Memo1->Lines->Add("Length of String should be <= 9 !!!"); // 防呆
	else if (k >= n)
		Form1->Memo1->Lines->Add("k should be < Length of String !!!"); // 防呆
	else {
		if (Form1->CheckBox2->Checked) {
			check = true;
			Form1->Memo2->Lines->Add("Go==>(k,n)=(" + IntToStr(k) + "," +
				str + ")");
			Form1->Memo2->Lines->Add(">i=0 (k,n)=(" + IntToStr(k) + "," +
				IntToStr(n) + ")");
		}
		count = 0;
		permStr(str, k + 1, n, check);
		if (Form1->CheckBox2->Checked)
			Form1->Memo2->Lines->Add
				("----------------------------------------------");
	}
	Form1->Memo1->Lines->Add("----------------------------------------------");

}
// ---------------------------------------------------------------------------
