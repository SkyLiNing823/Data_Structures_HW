// ---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#define SWAP(x,y,z) z=x, x=y, y=z;
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int i, j, k;
int** W;
int** W2;
int* W3;
int* W4;
int* D;
int* E;
int* found;
int* U;
int* V;
int* S;
int n;
int range;
int limit;
int largeint;
int e;
int N[100];
double Ktime[100];
double Ptime[100];
int Num = 0;
bool printG;
bool printinMST;

struct Dsnode {
	int data;
	Dsnode *parent;
};

Dsnode* nodes;

void MakeSet(Dsnode* x) { // initial
	x->parent = x;
}

Dsnode* Find(Dsnode* x) { // find parent(if union or not)
	if (x->parent == x)
		return x;
	else
		x->parent = Find(x->parent);
	return x->parent;
}

void Union(Dsnode *x, Dsnode *y) { // union 2 nodes
	Dsnode *xRoot = Find(x);
	Dsnode *yRoot = Find(y);
	xRoot->parent = yRoot;
}

int Partition(int *data, int *data2, int front, int end) {
	int tmp;
	int pivot = data[end];
	int i = front - 1;
	for (int j = front; j < end; j++) {
		if (data[j] < pivot) {
			i++;
			SWAP(data[i], data[j], tmp);
			SWAP(data2[i], data2[j], tmp);
		}
	}
	i++;
	SWAP(data[i], data[end], tmp);
	SWAP(data2[i], data2[end], tmp);
	return i;
}

void QuickSort(int *data, int *data2, int front, int end) {
	if (front < end) {
		int pivot = Partition(data, data2, front, end);
		QuickSort(data, data2, front, pivot - 1);
		QuickSort(data, data2, pivot + 1, end);
	}
}

double Kruskal() {
	if (W3 != NULL) { // free memory
		delete W3;
		delete W4;
		delete U;
		delete V;
		delete S;
		delete nodes;
	}
	W3 = new int[e]; // W3 is sorted W2
	W4 = new int[e]; // W4 is after sorted nodes name
	U = new int[e];
	V = new int[e];
	S = new int[e];
	nodes = new Dsnode[n]; // using datastruct

	for (i = 0; i < e; i++) {
		W3[i] = W2[i][2];
		W4[i] = i;
	}

	int tmp;
	QuickSort(W3, W4, 0, e - 1); // QuickSort

	for (i = 0; i < n; i++)
		MakeSet(&nodes[i]); // initial makeset
	int s = 0;
	int u, v;

	i = 0;
	clock_t start = clock(); // start
	while (s < e) {
		u = W2[W4[s]][0];
		v = W2[W4[s++]][1];
		while (Find(&nodes[u]) == Find(&nodes[v])) {
			u = W2[W4[s]][0];
			v = W2[W4[s++]][1];
			if (s == e) // out of range
					break;
		}
		if (s == e)
			break;
		U[i] = u; // storing data
		V[i] = v;
		S[i++] = s;

		Union(&nodes[u], &nodes[v]); // union
	}
	clock_t end = clock(); // end
	double CPUTime = (double)(end - start) / CLOCKS_PER_SEC;
	if (printinMST) { // whether user want to print
		for (j = 0; j < i; j++)
			Form1->Memo1->Lines->Add("Edge" + IntToStr(j) + ": (" +
			IntToStr(U[j]) + "," + IntToStr(V[j]) + ") [" +
			IntToStr(W2[W4[S[j]]][2]) + "]");
		if (i != n - 1) // can't connect every nodes
				Form1->Memo1->Lines->Add("G無延展樹");
	}
	Form1->Memo1->Lines->Add("Kruskal: " + FloatToStr(CPUTime) + " sec");
	Form1->Memo1->Lines->Add("------------------------");
	return CPUTime;
}

double Prim() {
	if (D != NULL) { // free memory
		delete D;
		delete E;
		delete found;
	}
	D = new int[n];
	E = new int[n];

	found = new int[n];
	for (j = 0; j < n; j++) {
		D[j] = W[0][j];
		E[j] = 0;
		found[j] = 0;
	}
	found[0] = 1;
	D[0] = largeint;
	clock_t start = clock(); // start
	while (true) {
		k = -1;
		int min = largeint;
		for (i = 0; i < n; i++) {
			if (found[i] == 0 && D[i] < min) {
				k = i;
				min = D[i];
			}
		}
		if (k == -1)
			break;
		i = 0;
		found[k] = 1;
		for (i = 0; i < n; i++) {
			if (!found[i] && D[k] + W[k][i] < D[i]) {
				D[i] = D[k] + W[k][i];
				E[i] = k;
			}
		}
	}
	clock_t end = clock(); // end
	double CPUTime = (double)(end - start) / CLOCKS_PER_SEC;
	if (printinMST) { // whether user want to print
		j = 0;
		for (i = 0; i < n; i++)
			if (D[i] != largeint) {
				Form1->Memo1->Lines->Add("Edge" + IntToStr(i) + ": (" +
					IntToStr(i) + "," + IntToStr(E[i]) + ") [" +
					IntToStr(D[i]) + "]");
				j++;
			}
		if (j != n - 1) // can't connect every nodes
				Form1->Memo1->Lines->Add("G無延展樹");
	}
	Form1->Memo1->Lines->Add("Prim: " + FloatToStr(CPUTime) + " sec");
	Form1->Memo1->Lines->Add("------------------------");
	return CPUTime;
}

void DrawChart() { // Generate Chart
	Form1->Chart1->RemoveAllSeries(); // Remove all previous series
	Form1->Chart1->Title->Text->Clear(); // Clear chart chart title
	Form1->Chart1->Title->Text->Add("Comparison of Kruskal's and Prim's");
	Form1->Chart1->BottomAxis->Title->Caption = "n(=|V|)"; // 水平座標軸的標題
	Form1->Chart1->LeftAxis->Title->Caption = "CPU Time"; // 垂直座標軸的標題
	Form1->Chart1->AddSeries(new TBarSeries(Form1->Chart1));
	Form1->Chart1->AddSeries(new TBarSeries(Form1->Chart1));
	Form1->Chart1->Series[0]->Title = "Kruskal";
	Form1->Chart1->Series[1]->Title = "Prim";
	printinMST = false;
	n = StrToInt(Form1->Edit1->Text);
	N[Num] = n;
	Ktime[Num] = Kruskal();
	Ptime[Num++] = Prim();
	for (i = 0; i < Num; i++) {
		Form1->Chart1->Series[0]->Add(Ktime[i], N[i]);
	}
	for (i = 0; i < Num; i++) {
		Form1->Chart1->Series[1]->Add(Ptime[i], N[i]);
	}
	for (i = 0; i < 2; i++) {
		Form1->Chart1->Series[i]->Marks->Visible = true;
		Form1->Chart1->Series[i]->Marks->Style = smsValue;
	}
}

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender) { // Generate G

	if (W != NULL) {
		for (i = 0; i < n; i++)
			delete W[i];
		delete W;
	}

	n = StrToInt(Form1->Edit1->Text);
	range = StrToInt(Form1->Edit2->Text);
	limit = StrToInt(Form1->Edit3->Text);
	largeint = StrToInt(Form1->Edit4->Text);
	printG = Form1->CheckBox1->Checked;

	W = new int*[n];
	for (i = 0; i < n; i++)
		W[i] = new int[n];

	srand(time(NULL));
	e = 0;
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			W[i][j] = rand() % range + 1;
			if (W[i][j] > limit)
				W[i][j] = largeint;
			else
				e++;
			W[j][i] = W[i][j];
		}
		W[i][i] = largeint;
	}
	W2 = new int* [e];
	for (i = 0; i < e; i++)
		W2[i] = new int[3];
	k = 0;
	for (i = 0; i < n; i++)
		for (j = i + 1; j < n; j++) {
			if (W[i][j] != largeint) {
				W2[k][0] = i;
				W2[k][1] = j;
				W2[k++][2] = W[i][j];
			}
		}

	if (printG) {

		StringGrid1->RowCount = n + 1;
		StringGrid1->ColCount = n + 1;
		for (i = 1; i < n + 1; i++)
			StringGrid1->Cells[i][0] = IntToStr(i - 1);
		for (i = 1; i < n + 1; i++) {
			StringGrid1->Cells[0][i] = IntToStr(i - 1);
			for (j = 1; j < n + 1; j++)
				StringGrid1->Cells[j][i] = IntToStr(W[i - 1][j - 1]);
		}
		StringGrid2->RowCount = e;
		StringGrid2->ColCount = 3;
		for (i = 0; i < e; i++) {
			StringGrid2->Cells[0][i] = IntToStr(W2[i][0]);
			StringGrid2->Cells[1][i] = IntToStr(W2[i][1]);
			StringGrid2->Cells[2][i] = IntToStr(W2[i][2]);
		}

	}
}

void __fastcall TForm1::Button2Click(TObject * Sender) { // Kruskal
	printinMST = Form1->CheckBox2->Checked;
	Kruskal();
}

void __fastcall TForm1::Button3Click(TObject * Sender) { // Prim
	printinMST = Form1->CheckBox2->Checked;
	Prim();
}

void __fastcall TForm1::Button4Click(TObject *Sender) { // DrawChart
	DrawChart();
}
// ---------------------------------------------------------------------------
