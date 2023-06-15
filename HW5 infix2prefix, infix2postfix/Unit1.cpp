// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

String stack[50];    //stack
String stack_opn[50];   //stack for operation
int i, j, top = 0, top_opn = 0;

void printStack(int mode, bool pop = false) {  //print stack's contain
	int i, n = 0;
	String x;
	if (pop == true)    //if next line is pop
		n = 1;         //top need to -1
	if (mode == 1) {
		x += "Stack: ";
		for (i = 0; i <= top - n; i++) {
			x += stack[i] + "  ";
		}
	}
	else {
		x += "Stack_opn: ";
		for (i = 0; i <= top_opn - n; i++) {
			x += stack_opn[i] + "  ";
		}
	}
	Form1->Memo1->Lines->Add(x);
}

void push(String data) {
	if (top == 100 - 1)
		Form1->Memo1->Lines->Add("StackFull");
	else {
		stack[++top] = data;
		printStack(1);
	}
}

void push_opn(String data) {  //push for stack for operation
	if (top_opn == 100 - 1)
		Form1->Memo1->Lines->Add("StackFull");
	else {
		stack_opn[++top_opn] = data;
		printStack(2);
	}
}

String pop() {
	if (top == -1)
		Form1->Memo1->Lines->Add("StackEmpty");
	else {
		printStack(1, true);
		return stack[top--];
	}
}

String pop_opn() {    //oop for stack for operation
	if (top_opn == -1)
		Form1->Memo1->Lines->Add("StackEmpty");
	else {
		printStack(2, true);
		return stack_opn[top_opn--];
	}
}

bool IsOpn(String s) {   //judge s a operation or operater
	if (s != "+" && s != "-" && s != "/" && s != "*" && s != "^" && s != "&" &&
		s != "|" && s != "(" && s != ")")       //these are operators
		return true;
	else
		return false;
}

int p(String x) {     //level before in stack
	if (x == "(")
		return 9;
	else if (x == "^")
		return 8;
	else if (x == "*" || x == "/" || x == "%")
		return 7;
	else if (x == "+" || x == "-")
		return 6;
	else if (x == "&")
		return 2;
	else if (x == "|")
		return 1;
	else if (x == "#")
		return 0;
}

int q(String x) {   //level after in stack
	if (x == "(")
		return 0;         //9->0
	else if (x == "^")
		return 8;
	else if (x == "*" || x == "/" || x == "%")
		return 7;
	else if (x == "+" || x == "-")
		return 6;
	else if (x == "&")
		return 2;
	else if (x == "|")
		return 1;
	else if (x == "#")
		return 0;
}

String get_prefix(String x) {
	String a = pop_opn();
	return x + pop_opn() + a;
}

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender) {
	// infix2prefix
	String str = Form1->Edit1->Text;
	String x, ans = "";
	int n = str.Length();
	top = 0, top_opn = 0;
	Form1->Memo1->Lines->Add("----------Infix2Prefix----------");
	push("#");
	for (i = 0; i < n; i++) {
		String s = str.SubString(i + 1, 1);    //just get string s[i+1]
		if (IsOpn(s)) {
			push_opn(s);
		}
		else if (s == ")") {
			while ((x = pop()) != "(") {
				push_opn(get_prefix(x));
			}
		}
		else {
			while (p(s) <= q(stack[top])) {
				x = pop();
				push_opn(get_prefix(x));
			}
			push(s);
		}
	}
	while (stack[top] != "#") {
		x = pop();
		push_opn(get_prefix(x));
	}
	pop();
	ans = pop_opn();
	Form1->Edit2->Text = ans;
	Form1->Memo1->Lines->Add("Infix: " + Form1->Edit1->Text);
	Form1->Memo1->Lines->Add("Prefix: " + ans);
	Form1->Memo1->Lines->Add("----------Infix2Prefix----------");
	// Form1->Memo1->Lines->Add(str);

}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender) {
	// infix2postfix
	String str = Form1->Edit1->Text;
	String x, ans = "";
	int n = str.Length();
	top = 0, top_opn = 0;
	Form1->Memo1->Lines->Add("----------Infix2Postfix----------");
	push("#");
	for (i = 0; i < n; i++) {
		String s = str.SubString(i + 1, 1);
		if (IsOpn(s)) {
			ans += s;
		}
		else if (s == ")") {
			while ((x = pop()) != "(") {
				ans += x;
			}
		}
		else {
			while (p(s) <= q(stack[top])) {
				x = pop();
				ans += x;
			}

			push(s);
		}
	}
	while (stack[top] != "#") {
		x = pop();
		ans += x;
	}
	pop();
	Form1->Edit3->Text = ans;
	Form1->Memo1->Lines->Add("Infix: " + Form1->Edit1->Text);
	Form1->Memo1->Lines->Add("Postfix: " + ans);
	Form1->Memo1->Lines->Add("----------Infix2Postfix----------");
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender) {
	// prefix2postfix
	String str = Form1->Edit4->Text;
	String x, y, ans = "";
	int n = str.Length();
	top = 0, top_opn = 0;
	Form1->Memo1->Lines->Add("----------Prefix2Postfix----------");
	for (i = 0; i < n; i++) {
		String s = str.SubString(i + 1, 1);
		if (IsOpn(s)) {
			while (IsOpn(stack[top]) && top != 0) {
				y = pop();
				x = pop();
				s = y + s + x;
			}
			push(s);
		}
		else
			push(s);
	}
	ans = pop();
	Form1->Edit6->Text = ans;
	Form1->Memo1->Lines->Add("Prefix: " + Form1->Edit4->Text);
	Form1->Memo1->Lines->Add("Postfix: " + ans);
	Form1->Memo1->Lines->Add("----------Prefix2Postfix----------");
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject * Sender) {
	// prefix2infix
	String str = Form1->Edit4->Text;
	String x, y, ans;
	int n = str.Length();
	int big = 0;
	top = 0, top_opn = 0;
	Form1->Memo1->Lines->Add("----------Prefix2Infix----------");
	for (i = n; i >= 0; i--) {
		String s = str.SubString(i + 1, 1);
		big = 0;
		if (IsOpn(s)) {
			push(s);
		}
		else {
			x = pop();
			y = pop();
			for (j = i-1; j >= 0; j--) {
				String s1 = str.SubString(j + 1, 1);
				if (!IsOpn(s1)) {
					if (p(s) < p(s1)) //if the previous operator > s[i+1]
						big = 1;
					break;
				}
			}
			s = x + s + y;
			if (big == 1)    //need ()
				s = "(" + s + ")";
			push(s);
		}
	}
	ans = pop();
	Form1->Edit5->Text = ans;
	Form1->Memo1->Lines->Add(ans);
	Form1->Memo1->Lines->Add("Prefix: " + Form1->Edit4->Text);
	Form1->Memo1->Lines->Add("Infix: " + ans);
	Form1->Memo1->Lines->Add("----------Prefix2Infix----------");

}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject * Sender) {
	// postfix2prefix
	String str = Form1->Edit7->Text;
	String s1, s2, ans;
	int n = str.Length();
	top = 0, top_opn = 0;
	Form1->Memo1->Lines->Add("----------Postfix2Prefix----------");
	for (i = 0; i < n; i++) {
		String s = str.SubString(i + 1, 1);
		if (IsOpn(s)) {
			push_opn(s);
		}
		else {
			s1 = pop_opn();
			s2 = pop_opn();
			s = s + s2 + s1;
			push_opn(s);
		}
	}
	ans = pop_opn();
	Form1->Edit9->Text = ans;
	Form1->Memo1->Lines->Add("Postfix: " + Form1->Edit7->Text);
	Form1->Memo1->Lines->Add("Prefix: " + ans);
	Form1->Memo1->Lines->Add("----------Postfix2Prefix----------");
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject * Sender) {
	// postfix2infix
	String str = Form1->Edit7->Text;
	String s1, s2, x, y, ans;
	int n = str.Length();
	top = 0, top_opn = 0;
	Form1->Memo1->Lines->Add("----------Postfix2Infix----------");
	for (i = 0; i < n; i++) {
		String s = str.SubString(i + 1, 1);
		if (IsOpn(s)) {
			push_opn(s);
			push("@");
		}
		else {
			s1 = pop();
			s2 = pop();
			x = pop_opn();
			y = pop_opn();
			if (p(s) > p(s1))
				x = "(" + x + ")";
			if (p(s) > p(s2))
				y = "(" + y + ")";
			push_opn(y + s + x);
			push(s);
		}
	}
	while (top != -1) {
		x = pop();
	}
	ans = pop_opn();
	Form1->Edit8->Text = ans;
	Form1->Memo1->Lines->Add("Postfix: " + Form1->Edit7->Text);
	Form1->Memo1->Lines->Add("Infix: " + ans);
	Form1->Memo1->Lines->Add("----------Postfix2Infix----------");
}

// ---------------------------------------------------------------------------
