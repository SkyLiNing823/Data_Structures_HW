﻿// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

#define possible_direction 8
TForm1 *Form1;

struct offset {
	int dx, dy;
};

offset move[possible_direction];

enum directions {
	N, E, S, W, NE, SE, SW, NW
};

struct position {
	int x, y;
	directions dir; // direction dir
};

int m, p, top = 0;
position* stack;
int **maze;
int **maze_sol;
int **mark;

void push(position data) {
	if (top == m*p - 1)
		Form1->Memo1->Lines->Add("StackFull");
	else
		stack[++top] = data;
}

position pop() {
	if (top == -1)
		Form1->Memo1->Lines->Add("StackEmpty");
	else
		return stack[top--];
}

int ** generatemaze(int ** maze, int x, int y) {
	int direction;
	int j, i;
	maze[x][y] = 0; // 標示此格已設定
	// Form1->Memo1->Lines->Add("(x,y,dir)=" + IntToStr(x) + "," + IntToStr(y) +
	// "," + IntToStr(direction));
	while ((y != m - 2 && maze[x][y + 2] == 1) ||
		(x != p - 2 && maze[x + 2][y] == 1) || (y != 1 && maze[x][y - 2] == 1)
		|| (x != 1 && maze[x - 2][y] == 1))
		// 如果不是外牆
	{
		direction = rand() % 4 + 1; // 決定下一個位置
		if (direction == 1 && y != p - 2) // 向右走
		{
			if (maze[x][y + 2] == 1) {
				maze[x][y + 1] = 0; // 拆掉右牆
				maze = generatemaze(maze, x, y + 2);
			}
		}
		else if (direction == 2 && x != 1) // 向上走
		{
			if (maze[x - 2][y] == 1) {
				maze[x - 1][y] = 0; // 拆掉上牆
				maze = generatemaze(maze, x - 2, y);
			}
		}
		else if (direction == 3 && y != 1) // 向左走
		{
			if (maze[x][y - 2] == 1) {
				maze[x][y - 1] = 0; // 拆掉右牆
				maze = generatemaze(maze, x, y - 2);
			}
		}
		else if (direction == 4 && x != m - 2) // 向下走
		{
			if (maze[x + 2][y] == 1) {
				maze[x + 1][y] = 0; // 拆掉上牆
				maze = generatemaze(maze, x + 2, y);
			}
		}
	}
	return maze;
}

void path() {
	stack = new position[m * p]; // 動態宣告一維陣列
	position step;
	int i, j, u, v;
	directions d;
	String out;
	step.x = 1;
	step.y = 0;
	step.dir = (directions)N;
	top = 0;
	push(step);
	mark[step.x][step.y] = 1;
	move[E].dx = 0, move[E].dy = 1;
	move[SE].dx = 1, move[SE].dy = 1;
	move[S].dx = 1, move[S].dy = 0;
	move[SW].dx = 1, move[SW].dy = -1;
	move[W].dx = 0, move[W].dy = -1;
	move[NW].dx = -1, move[NW].dy = -1;
	move[N].dx = -1, move[N].dy = 0;
	move[NE].dx = -1, move[NE].dy = 1;
	while (top != 0) {
		step = pop();
		i = step.x;
		j = step.y;
		d = step.dir;
		while (d <= (directions)NW) { // d<=NW
			u = i + move[d].dx;
			v = j + move[d].dy;
			if ((!maze[u][v]) && (!mark[u][v])) {
				step.x = u;
				step.y = v;
				step.dir = (directions)(N);
				Form1->StringGrid3->Cells[step.y][step.x] = "×";
				push(step);
				if ((u == m - 2) && (v == p - 1)) {
					mark[u][v] = 1;
					return;
				}
				mark[u][v] = 1;
				i = u;
				j = v;
				d = (directions)N;
			}
			else {
				d = (directions)(d + 1);
			}
		}

	}
	Form1->Memo1->Lines->Add("There is no EXIT!!!"); // 輸出迷宮無出路

}

void printMaze() {
	int i, j;
	String out;
	int grid_size = Form1->Edit3->Text.ToInt();
	position step;
	for (i = 0; i < m; i++) {
		for (j = 0; j < p; j++)
			maze_sol[i][j] = maze[i][j];
	}
	maze_sol[1][0] = 3;
	Form1->StringGrid3->Cells[1][0] = "√";
	maze_sol[m - 2][p - 1] = 3;
	out = "";
	for (i = 1; i <= top; i++) {
		maze_sol[stack[i].x][stack[i].y] = 3;
		Form1->StringGrid3->Cells[stack[i].x][stack[i].y] = "√";
		out += "(" + IntToStr(stack[i].x) + "," + IntToStr(stack[i].y) + ")";
		if (i != top)
			out += "->";
	}
	Form1->Memo1->Lines->Add(out);

	for (i = 0; i < m; i++) {
		out = "";
		for (j = 0; j < p; j++)
			out += "  " + IntToStr(maze_sol[i][j]);
		Form1->Memo1->Lines->Add(out);
	}

	Form1->StringGrid1->RowCount = m;
	Form1->StringGrid1->ColCount = p;
	for (i = 0; i < m; i++)
		for (j = 0; j < p; j++)
			Form1->StringGrid1->Cells[j][i] = maze_sol[i][j];

	Form1->StringGrid2->RowCount = m;
	Form1->StringGrid2->ColCount = p;

	Form1->StringGrid2->DefaultDrawing = false;

	Form1->StringGrid2->FixedCols = 0;
	Form1->StringGrid2->FixedRows = 0;
	Form1->StringGrid2->GridLineWidth = 0;

	Form1->StringGrid3->RowCount = m;
	Form1->StringGrid3->ColCount = p;

	Form1->StringGrid3->DefaultDrawing = false;
	Form1->StringGrid3->FixedCols = 0;
	Form1->StringGrid3->FixedRows = 0;
	Form1->StringGrid3->GridLineWidth = 0;

	for (i = 0; i < m; i++) {
		Form1->StringGrid2->RowHeights[i] = grid_size;
		Form1->StringGrid3->RowHeights[i] = grid_size;
	}

	for (i = 0; i < p; i++) {
		Form1->StringGrid2->ColWidths[i] = grid_size;
		Form1->StringGrid3->ColWidths[i] = grid_size;
	}

	for (i = 0; i < m; i++)
		for (j = 0; j < p; j++) {
			Form1->StringGrid2->Cells[j][i] = Form1->StringGrid1->Cells[j][i];
			Form1->StringGrid3->Cells[j][i] = Form1->StringGrid1->Cells[j][i];
		}

	Form1->StringGrid2->Refresh();
	Form1->StringGrid3->Refresh();
}

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent * Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject * Sender) { // Generate Maze
	int i, j;
	String out;
	if (maze) // delete the previous maze
	{
		for (int i = 0; i < m; i++) {
			delete(maze[i]);
			delete(mark[i]);
			delete(maze_sol[i]);
		}
		delete(maze);
		delete(mark);
		delete(maze_sol);
	}
	m = Edit1->Text.ToInt();
	p = Edit2->Text.ToInt();
	maze = new int * [m];
	mark = new int * [m];
	maze_sol = new int * [m];
	for (int i = 0; i < m; i++) {
		maze[i] = new int[p];
		mark[i] = new int[p];
		maze_sol[i] = new int[p];
	}
	int Start_i = 1, Start_j = 1, End_i = m - 2, End_j = p - 2;
	int x, y;
	srand(time(NULL));
	for (x = 0; x < m; x++) {
		for (y = 0; y < p; y++) {
			if (x == 0 || y == 0 || x == m - 1 || y == p - 1)
				maze[x][y] = 2; // 設定外牆
			else
				maze[x][y] = 1; // 初始迷宮內部
			mark[x][y] = 0;
		}
	}
	maze = generatemaze(maze, End_i, End_j); // 產生迷宮
	maze[Start_i][Start_j - 1] = 0; // 拆掉入口左牆
	maze[End_i][End_j + 1] = 0; // 拆掉出口右牆
	StringGrid1->RowCount = m;
	StringGrid1->ColCount = p;
	out = "----------" + IntToStr(m) + "x" + IntToStr(p) + "----------";
	Memo1->Lines->Add(out);
	for (i = 0; i < m; i++) // Print maze[][] in Memo1
	{
		out = "";
		for (j = 0; j < p; j++)
			out += "  " + IntToStr(maze[i][j]);
		Memo1->Lines->Add(out);
	}
	Memo1->Lines->Add("------------------------");
	path();
	printMaze();

}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject * Sender) { // Load Maze
	FILE *fp;
	AnsiString out, fname;
	int grid_size = Edit3->Text.ToInt();
	int i, j;
	if (OpenDialog1->Execute()) {
		fname = OpenDialog1->FileName;
		fp = fopen(fname.c_str(), "r+");
		fscanf(fp, "%d %d", &m, &p); // Reda integers m & p
		maze = new int * [m];
		mark = new int * [m];
		maze_sol = new int * [m];
		for (i = 0; i < m; i++) {
			maze[i] = new int[p];
			mark[i] = new int[p];
			maze_sol[i] = new int[p];
		}
		Memo1->Lines->Add("m=" + IntToStr(m));
		Memo1->Lines->Add("p=" + IntToStr(p));
		for (i = 0; i < m; i++)
			for (j = 0; j < p; j++) {
				fscanf(fp, "%d", &maze[i][j]);
				mark[i][j] = 0;
			}
		out = "----------" + IntToStr(m) + "x" + IntToStr(p) + "----------";
		Memo1->Lines->Add(out);
		for (i = 0; i < m; i++) // Print maze[][] in Memo1
		{
			out = "";
			for (j = 0; j < p; j++)
				out += "  " + IntToStr(maze[i][j]);
			Memo1->Lines->Add(out);
		}
		Memo1->Lines->Add("------------------------");
		fclose(fp);
	}
	else
		Memo1->Lines->Add("Nothing happens.");

	// Print out maze[][] in StringGrid1
	path();
	printMaze();

}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject * Sender) { // Save Maze
	if (SaveDialog1->Execute()) // 確認SaveDialog1讀取檔案成功
	{ // 取SaveDialog1所開啟的檔案名稱, 將檔案名稱轉為char格式後用fopen開啟此檔案
		AnsiString file_name = SaveDialog1->FileName;
		FILE *fp = fopen(file_name.c_str(), "w"); // "w" 表示開以寫檔的方式開啟
		// 利用fprintf將g_matrix中的元素寫入fp, 當需要換行時使用putc將'\n'加入fp中
		if (fp) {
			fprintf(fp, "%d %d", m, p);
			putc('\n', fp);
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < p; j++) {
					fprintf(fp, "%d ", maze[i][j]);
				}
				putc('\n', fp);
			}
			fclose(fp); // 寫完檔後請關檔
		}
	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::StringGrid1DrawCell(TObject * Sender, int ACol,
	int ARow, TRect & Rect, TGridDrawState State) {
	StringGrid1->Canvas->Brush->Color = clWhite;
	StringGrid1->Canvas->Font->Color = clBlue;
	StringGrid1->Canvas->FillRect(Rect);
	AnsiString text = StringGrid2->Cells[ACol][ARow];
	StringGrid1->Canvas->TextRect(Rect, Rect.Left + 8, Rect.Top + 8, text);
}

void __fastcall TForm1::StringGrid2DrawCell(TObject * Sender, int ACol,
	int ARow, TRect & Rect, TGridDrawState State) {
	AnsiString text = StringGrid2->Cells[ACol][ARow];
	if (text == "0")
		StringGrid2->Canvas->Brush->Color = TColor(RGB(250, 245, 135));
	else if (text == "1")
		StringGrid2->Canvas->Brush->Color = TColor(RGB(80, 80, 80));
	else if (text == "2")
		StringGrid2->Canvas->Brush->Color = TColor(RGB(255, 87, 51));
	else if (text == "3")
		StringGrid2->Canvas->Brush->Color = TColor(RGB(51, 273, 255));
	StringGrid2->Canvas->FillRect(Rect);

}

void __fastcall TForm1::StringGrid3DrawCell(TObject *Sender, int ACol, int ARow,
	TRect &Rect, TGridDrawState State) {
	AnsiString text = StringGrid3->Cells[ACol][ARow];
	if (text == "0")
		StringGrid3->Canvas->Brush->Color = TColor(RGB(240, 233, 210));
	else if (text == "1")
		StringGrid3->Canvas->Brush->Color = TColor(RGB(8, 32, 50));
	else if (text == "2")
		StringGrid3->Canvas->Brush->Color = TColor(RGB(44, 39, 46));
	else if (text == "3")
		StringGrid3->Canvas->Brush->Color = TColor(RGB(154, 230, 110));
	StringGrid3->Canvas->FillRect(Rect);
	if (text == "√") StringGrid3->Canvas->TextRect(Rect, Rect.Left+10, Rect.Top+10, text);
	else if (text == "×") StringGrid3->Canvas->TextRect(Rect, Rect.Left+10, Rect.Top+10, text);

}
// ---------------------------------------------------------------------------
