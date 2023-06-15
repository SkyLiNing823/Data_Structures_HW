// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include <time.h>
#include <stdlib.h>
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int i, j, x, y;
String str;

long long binpow(long long a, long long b) {   //二進制取冪
	long long res = 1;
	while (b > 0) {
		if (b & 1)
			res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}

long long Horner(int a[], long long k, int x) {   //霍納法則
	int i;
	long long p = a[k - 1]; // 最高位係數

	for (i = k - 2; i >= 0; i--) {
		p = x * p + a[i];
	}
	return p;
}

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender) {
	long long x = StrToInt(Form1->Edit1->Text);
	long long n = StrToInt(Form1->Edit2->Text);
	long long t = StrToInt(Form1->Edit3->Text);
	long long sum;

	if (n < 0) {   //n>=0
		Form1->Memo1->Lines->Add("n must >= 0!");
	}
	else {
		Form1->Button1->Caption = "Waiting...";
		Form1->Memo1->Lines->Add("-------------Power:naive-------------");
		clock_t start = clock();    //start
		//simple method
		for (i = 0; i < t; i++) {
			sum = 1;
			for (j = 0; j < n; j++) {
				sum *= x;
			}
		}
		clock_t end = clock();  //end
		double CPUTime = (double)(end - start) / CLOCKS_PER_SEC;
		str = "Pow(x,n) = " + IntToStr(x) + "^" + IntToStr(n);
		Form1->Memo1->Lines->Add(str);
		str = "= " + IntToStr(sum) + " [" + FloatToStr(CPUTime) + "(sec.)] " +
			IntToStr(t) + " times.";
		Form1->Memo1->Lines->Add(str);
		Form1->Memo1->Lines->Add("Time complexity : O(n)");
		Form1->Memo1->Lines->Add("----------Power:well-known----------");
		sum = 1;
		start = clock();     //start
		//using binary_pow method
		for (i = 0; i < t; i++)
			sum = binpow(x, n);
		end = clock(); //end
		CPUTime = (double)(end - start) / CLOCKS_PER_SEC;
		str = "Pow(x,n) = " + IntToStr(x) + "^" + IntToStr(n);
		Form1->Memo1->Lines->Add(str);
		str = "= " + IntToStr(sum) + " [" + FloatToStr(CPUTime) + "(sec.)] " +
			IntToStr(t) + " times.";
		Form1->Memo1->Lines->Add(str);
		Form1->Memo1->Lines->Add("Time complexity : O(log(n))");
		Form1->Memo1->Lines->Add("------------------------------------------");
		Form1->Button1->Caption = "x^n";
	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender) {
	long long k = StrToInt(Form1->Edit4->Text);
	long long n = StrToInt(Form1->Edit5->Text);
	long long t = StrToInt(Form1->Edit6->Text);
	int *a;
	long long *f;
	long long sum = 1;
	long long total = 0;
	if (k < 0) {
		Form1->Memo2->Lines->Add("k must >= 0!");
	}
	else if (n < 0) {
		Form1->Memo2->Lines->Add("n must >= 0!");
	}
	else {
		Form1->Button2->Caption = "Waiting...";
		Form1->Memo2->Lines->Add("-------------Polynomial:naive-------------");
		a = new int[k];
		f = new long long[n];
		srand(time(NULL));   //using time as rand seed
		for (i = 0; i < k; i++) {
			a[i] = rand() % 1000 + 1; // 係數range:1~1000
		}
		clock_t start = clock();    //start
		//simple method
		for (i = 0; i < t; i++) { // times
			for (j = 1; j <= n; j++) { // f(1)...f(n)
				total = 0;
				for (x = 0; x < k; x++) {  //x^k
					sum = 1;
					for (y = 0; y < x; y++) { //calculate x^k
						sum *= j;
					}
					total += a[x] * sum; //a[i]*x^k
				}
				f[j - 1] = total; //store f(x)
			}
		}
		clock_t end = clock();   //end
		double CPUTime = (double)(end - start) / CLOCKS_PER_SEC;
		str = "f(x) = " + IntToStr(a[0]) + " + ";
		for (i = 1; i < k; i++) {
			str += IntToStr(a[i]) + " x^" + IntToStr(i);
			if (i != k - 1)
				str += " + ";
		}
		Form1->Memo2->Lines->Add(str);
		for (i = 1; i <= n; i++) {
			Form1->Memo2->Lines->Add("f(" + IntToStr(i) + ")= " +
				IntToStr(f[i - 1]));
		}
		str = " [" + FloatToStr(CPUTime) + "(sec.)] " + IntToStr(t) + " times.";
		Form1->Memo2->Lines->Add(str);
		Form1->Memo2->Lines->Add("Time complexity : O(n^2)");
		Form1->Memo2->Lines->Add("----------Polynomial:well-known----------");
		start = clock(); //start
		//using Horner Method
		for (i = 0; i < t; i++) { // times
			for (j = 1; j <= n; j++) { // f(1)...f(n)
				total = Horner(a, k, j);
				f[j - 1] = total; //store f(x)
			}
		}
		end = clock();  //end
		CPUTime = (double)(end - start) / CLOCKS_PER_SEC;
		str = "f(x) = " + IntToStr(a[0]) + " + ";
		for (i = 1; i < k; i++) {
			str += IntToStr(a[i]) + " x^" + IntToStr(i);
			if (i != k - 1)
				str += " + ";
		}
		Form1->Memo2->Lines->Add(str);
		for (i = 1; i <= n; i++) {
			Form1->Memo2->Lines->Add("f(" + IntToStr(i) + ")= " +
				IntToStr(f[i - 1]));
		}
		str = " [" + FloatToStr(CPUTime) + "(sec.)] " + IntToStr(t) + " times.";
		Form1->Memo2->Lines->Add(str);
		Form1->Memo2->Lines->Add("Time complexity : O(nlog(n))");
		Form1->Memo2->Lines->Add
			("---------------------------------------------");
        Form1->Button2->Caption = "Doing f(x)";
	}

}
// ---------------------------------------------------------------------------
