// ---------------------------------------------------------------------------

#include <vcl.h>
#include<time.h>
#pragma hdrstop

#include "Unit1.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

struct BSTreeNode {       //中序走訪
	BSTreeNode *leftchild;
	int data;
	BSTreeNode *rightchild;
};

BSTreeNode *root;
String str;
int notfound = false;

BSTreeNode *NewBSTnode(int data) {
	BSTreeNode *node = new BSTreeNode;
	node->data = data;
	node->leftchild = NULL;
	node->rightchild = NULL;
	return node;
}

BSTreeNode *InsertBSTree(BSTreeNode *node, int x) {
	if (node == NULL) // first node
			return NewBSTnode(x);
	if (x < node->data)
		node->leftchild = InsertBSTree(node->leftchild, x);
	else
		node->rightchild = InsertBSTree(node->rightchild, x);
	return node;
}

void inorder(BSTreeNode *node) {
	if (node != NULL) {
		inorder(node->leftchild);
		str += IntToStr(node->data) + "_";
		inorder(node->rightchild);
	}
}

BSTreeNode *InorderSucc(BSTreeNode *node) {
	BSTreeNode *p = node;
	while (p->leftchild != NULL)
		p = p->leftchild;
	return p;
}

BSTreeNode *DeleteBSTree(BSTreeNode *node, int x) {
	BSTreeNode *temp;
	if (node == NULL) {     //沒有找到目標
		notfound = true;
		return node;
	}
	if (x < node->data)
		node->leftchild = DeleteBSTree(node->leftchild, x);
	else if (x > node->data)
		node->rightchild = DeleteBSTree(node->rightchild, x);
	else { // x be found
		if ((node->leftchild == NULL) || (node->rightchild == NULL)) {
			// node only has one child
			temp = node->leftchild ? node->leftchild : node->rightchild;
			if (temp == NULL) // node is a leaf
			{
				temp = node;
				node = NULL;
			}
			else
				*node = *temp;
			free(temp);
		}
		else {
			// node has two children
			temp = InorderSucc(node->rightchild);
			node->data = temp->data;
			node->rightchild = DeleteBSTree(node->rightchild, temp->data);
		}
	}
	return node;
}

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender) // Insert into BST
{
	int x = StrToInt(Form1->Edit1->Text);
	root = InsertBSTree(root, x);
	str = "";
	inorder(root);
	Form1->Memo1->Lines->Add(str);
    Form1->Memo1->Lines->Add("----------------------------------------");
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender) // delete from BST
{
	int x = StrToInt(Form1->Edit1->Text);
	notfound = false;
	root = DeleteBSTree(root, x);
	str = "";
	if (root != NULL) {
		if (notfound == true)      //沒找到目標
			Form1->Memo1->Lines->Add("Not found");
		else {
			inorder(root);
			Form1->Memo1->Lines->Add(str);
		}
	}
	else {    //BST已無節點
		Form1->Memo1->Lines->Add("Tree is empty");
	}
	Form1->Memo1->Lines->Add("----------------------------------------");

}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender) {
	int k = StrToInt(Form1->Edit2->Text);
	int range = StrToInt(Form1->Edit3->Text);
	srand(time(NULL));    //時間亂數種子
	String str2 = "The Number inserted: ";
	for (int i = 0; i < k; i++) {
		int x = rand() % range + 1;
		str2+=IntToStr(x);
		if(i!=k-1)
			str2+=", ";
		root = InsertBSTree(root, x);
	}
	str = "";
	inorder(root);
	Form1->Memo1->Lines->Add(str2);   //印出生成亂數
	Form1->Memo1->Lines->Add(str);
	Form1->Memo1->Lines->Add("----------------------------------------");
}
// ---------------------------------------------------------------------------
