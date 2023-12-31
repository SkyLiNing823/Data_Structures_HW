// ---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "SelectionSort.h"
#include <time.h>
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

#define SWAP(x, y, t) (t=x, x=y, y=t)     //Macro

int data[100000];
int original_data[100000];
int n;
int r;
int DataSize[1000];
double SelSortTime[1000];
double BubSortTime[1000];
int D_times = -1;
int S_times = -1;
int B_times = -1;

TForm1 *Form1;

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
}

void SelectionSort(int data[], int n) {
	int i, j, min, temp;
	for (i = 0; i < n; i++) {
		min = i;
		for (j = i + 1; j < n; j++) {
			if (data[j] < data[min]) {
				min = j;
			}
		}
		SWAP(data[i], data[min], temp);

	}
}

void BubbleSort(int data[], int n) {
	int i, j, temp;
	for (i = n - 1; i >= 0; i--) {
		for (j = 1; j < i + 1; j++) {
			if (data[j - 1] > data[j])
				SWAP(data[j - 1], data[j], temp);
		}
	}
}

int BinarySearch(int data[], int n, int target) { // O(logn)
	int start = 0;
	int end = n;
	int index = -1;
	int mid; // middle
	while (start <= end) {
		mid = (start + end) / 2; // 動態調整middle
		if (data[mid] < target)
			start = mid + 1;
		else if (data[mid] > target)
			end = mid - 1;
		else { // data[mid] = target
			index = mid;
			break;
		}
	}
	return index;
}

void RandData(int original_data[], int n, int range) {
	int i;
	for (i = 0; i < n; i++)
		original_data[i] = rand() % range + 1;
}

void getData(int data[], int original_data[], int range) {
	int i;
	for (i = 0; i < range; i++)
		data[i] = original_data[i];
}

void printData(int data[], int n, int flag) {
	int i;
	if (flag == 1)
		for (i = 0; i < n; i++) {
			Form1->Memo1->Lines->Add("data[" + IntToStr(i) + "] = " +
				IntToStr(data[i]));
		}
	else if (flag == 2)
		for (i = 0; i < n; i++) {
			Form1->Memo2->Lines->Add("data[" + IntToStr(i) + "] = " +
				IntToStr(data[i]));
		}
	else // flag == 3
		for (i = 0; i < n; i++) {
			Form1->Memo3->Lines->Add("data[" + IntToStr(i) + "] = " +
				IntToStr(data[i]));
		}
}

void selfCheck(int data[], int n, int flag) {
	int i;
	for (i = 0; i < n - 1; i++) {
		if (data[i] > data[i + 1])
			break;
	}
	if (i == n - 1) {
		if (flag == 2)
			Form1->Memo2->Lines->Add("Correctly Sorted!");
		else if (flag == 3)
			Form1->Memo3->Lines->Add("Correctly Sorted!");
	}
	else {
		if (flag == 2)
			Form1->Memo2->Lines->Add("NOT Sorted!");
		else if (flag == 3)
			Form1->Memo3->Lines->Add("NOT Sorted!");
	}

}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender) {
	Button1->Caption = "Loading..."; // 程式在執行
	n = StrToInt(Edit1->Text);
	int range = StrToInt(Edit2->Text);
	if (range < n) {
		Form1->Memo1->Lines->Add("n is BIGGER than range!!!"); //防呆
	}
	else {
		int i;
		r = StrToInt(Edit4->Text);
		for (i = 0; i < r; i++) {
			srand(time(NULL));
			clock_t t_begin, t_end;
			t_begin = clock();
			RandData(original_data, n, range);
			t_end = clock();
			if (CheckBox1->Checked)
				printData(original_data, n, 1);
			Form1->Memo1->Lines->Add("CPU time (sec.) = " +
				FloatToStr(((double)(t_end - t_begin) / CLOCKS_PER_SEC)));
			DataSize[++D_times] = n;
		}
	}
    Button1->Caption = "Generate Random Number"; // 程式執行完成
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender) {
	Button2->Caption = "Loading..."; // 程式在執行
	clock_t t_begin, t_end;
	int i;
	r = StrToInt(Edit4->Text);
	for (i = 0; i < r; i++) {
		t_begin = clock();
		getData(data, original_data, n);
		SelectionSort(data, n);
		t_end = clock();
		if (CheckBox1->Checked)
			printData(data, n, 2);
		if (CheckBox2->Checked)
			selfCheck(data, n, 2);
		Form1->Memo2->Lines->Add("CPU time (sec.) = " +
			FloatToStr(((double)(t_end - t_begin) / CLOCKS_PER_SEC)));
		SelSortTime[++S_times] =
			(double)(t_end - t_begin) / CLOCKS_PER_SEC * 1000;

	}
	Button2->Caption = "Selection Sort"; // 程式執行完成
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender) {
	Button3->Caption = "Loading..."; // 程式在執行
	clock_t t_begin, t_end;
	int i;
	r = StrToInt(Edit4->Text);
	for (i = 0; i < r; i++) {
		t_begin = clock();
		getData(data, original_data, n);
		BubbleSort(data, n);
		t_end = clock();
		if (CheckBox1->Checked)
			printData(data, n, 3);
		if (CheckBox2->Checked)
			selfCheck(data, n, 3);
		Form1->Memo3->Lines->Add("CPU time (sec.) = " +
			FloatToStr(((double)(t_end - t_begin) / CLOCKS_PER_SEC)));
		BubSortTime[++B_times] =
			(double)(t_end - t_begin) / CLOCKS_PER_SEC * 1000;
	}
	Button3->Caption = "Bubble Sort"; // 程式執行完成
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender) {
	int target = StrToInt(Edit3->Text);
	int success = -1;
	success = BinarySearch(data, n, target);
	if (success >= 0 && success < n)
		Memo4->Lines->Add(IntToStr(target) + " is in data[" +
		IntToStr(success) + "]");
	else
		Memo4->Lines->Add(IntToStr(target) + " has NOT been found!");
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender) {
	int i;
	Chart1->RemoveAllSeries(); // Remove all previous series
	Chart1->Title->Text->Clear(); // Clear chart chart title
	Chart1->Title->Text->Add("A sample chart");
	Chart1->BottomAxis->Title->Caption = "data size"; // x-axis' title
	Chart1->LeftAxis->Title->Caption = "CPU time (ms)"; // y-axis' title
	Chart1->AddSeries(new TBarSeries(this)); // create a new BAR series
	Chart1->Series[0]->Title = "Selection Sort";
	Chart1->Series[0]->AddArray(SelSortTime, S_times);
	// assign the values in SelSortTime onto the series one by one from 0 to 4
	Chart1->AddSeries(new TBarSeries(this));
	Chart1->Series[1]->Title = "Bubble Sort";
	for (i = 0; i <= B_times; i++)
		Chart1->Series[1]->Add(BubSortTime[i], DataSize[i], clGreen);

	for (int i = 0; i < 2; i++) // Set marks visible
	{
		Chart1->Series[i]->Marks->Visible = true;
		Chart1->Series[i]->Marks->Style = smsValue;
	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender) {
	Button5->Caption = "Loading..."; // 程式在執行

	Button1->Caption = "Loading..."; // 程式在執行
	n = StrToInt(Edit1->Text);
	int range = StrToInt(Edit2->Text);
	int i;
	srand(time(NULL));
	clock_t t_begin, t_end;
	t_begin = clock();
	RandData(original_data, n, range);
	t_end = clock();
	if (CheckBox1->Checked)
		printData(original_data, n, 1);
	Form1->Memo1->Lines->Add("CPU time (sec.) = " +
		FloatToStr(((double)(t_end - t_begin) / CLOCKS_PER_SEC)));
	DataSize[++D_times] = n;
	Button1->Caption = "Generate Random Number"; // 程式執行完成

	Button2->Caption = "Loading..."; // 程式在執行
	r = StrToInt(Edit4->Text);
	for (i = 0; i < r; i++) {
		t_begin = clock();
		getData(data, original_data, n);
		SelectionSort(data, n);
		t_end = clock();
		if (CheckBox1->Checked)
			printData(data, n, 2);
		if (CheckBox2->Checked)
			selfCheck(data, n, 2);
		Form1->Memo2->Lines->Add("CPU time (sec.) = " +
			FloatToStr(((double)(t_end - t_begin) / CLOCKS_PER_SEC)));
		SelSortTime[++S_times] =
			(double)(t_end - t_begin) / CLOCKS_PER_SEC * 1000;

	}
	Button2->Caption = "Selection Sort"; // 程式執行完成

	Button3->Caption = "Loading..."; // 程式在執行
	for (i = 0; i < r; i++) {
		t_begin = clock();
		getData(data, original_data, n);
		BubbleSort(data, n);
		t_end = clock();
		if (CheckBox1->Checked)
			printData(data, n, 3);
		if (CheckBox2->Checked)
			selfCheck(data, n, 3);
		Form1->Memo3->Lines->Add("CPU time (sec.) = " +
			FloatToStr(((double)(t_end - t_begin) / CLOCKS_PER_SEC)));
		BubSortTime[++B_times] =
			(double)(t_end - t_begin) / CLOCKS_PER_SEC * 1000;
	}
	Button3->Caption = "Bubble Sort"; // 程式執行完成

	Button5->Caption = "Load Chart"; // 程式執行完成
}
// ---------------------------------------------------------------------------
