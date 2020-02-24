#include "viagem.h"
#include "data.h"
typedef struct node Node;
typedef struct tree Tree;

Tree* createTree();

Node* searchDate(Node* x,Data* d);
Viagem* getViagemFromNode(Node* x);
Node* getRoot(Tree* T);
Node* createNode(Viagem* viagem);
void showAllInOrder(Node* x);
void searchIdRemove(Tree* T,Node* x,int d);
void Tupdate(Tree* T,Node* x,Viagem* v);
void insert(Tree* t,Node* z);
void tRemove(Tree* T,Node* z);