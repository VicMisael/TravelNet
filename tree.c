#include "tree.h"
#include "viagem.h"
#include "data.h"
#include <stdlib.h>
#include <stdio.h>
struct tree{
  Node* root;
};

struct node{
  Node* parent;
  Node* left;
  Node* right;
  Viagem* viagem;
  int id;
};

Tree* createTree(){
  Tree* t=(Tree*)malloc(sizeof(Tree));
  return t;
}
Node* createNode(Viagem* viagem){
  Node* n=(Node*)malloc(sizeof(Node));
  n->left=NULL;
  n->right=NULL;
  n->viagem=viagem;
  return n;
};

Node* minimum(Node* x){
  while(x->left!=NULL){
    x=x->left;
  }
  return x;
}

Node* getRoot(Tree* t){
  return t->root;
}
Viagem* getViagemFromNode(Node* x){
  return x->viagem;
}

//cadastrar, buscar (listar todas ou filtrar por data de viagem e local de destino), alterar e remover
Node* searchDate(Node* x,Data* d){
  if(x==NULL || compararData(getData(x->viagem),d)==0){
    return x;
  }
  else if(compararData(d,getData(x->viagem)) ==  -1){
    return searchDate(x->left,d);
  }else{
    return searchDate(x->right,d);
  }
  
}

void searchIdRemove(Tree* T,Node* x,int d){
  if(x!=NULL){
    showAllInOrder(x->left);
    if((x->id)==d){
      tRemove(T,x);
      return;
    }
    showAllInOrder(x->right);
  }
 
}
void showAllInOrder(Node* x){
  if(x!=NULL){
    showAllInOrder(x->left);
    printf("id: %d \n ",x->id);
    printDadosViagem(x->viagem);
    showAllInOrder(x->right);
  }
}
void Tupdate(Tree* T,Node* x,Viagem* v){ 
  tRemove(T,x);
  insert(T,createNode(v));
}
//troca a subarvore de u pela subarvore de v
void transplant(Tree* T,Node* u,Node* v){
  if(u->parent==NULL){
    T->root=v;
  }else if(u == u->parent->left){
    u->parent->left=v;
  }else{
    u->parent->right=v;
  }
  if(v!=NULL){
    v->parent=u->parent;
  }

}
static int i=0;
void insert(Tree* T,Node* z){
  z->id=i;
  i++;
  Node* y=NULL;
  Node* x=T->root;
  while(x!=NULL){
    y=x;
    if(compararDatas(z->viagem,x->viagem)==-1){
      x=x->left;
    }else{
      x=x->right;
    }
  }
  z->parent=y;
  if(y==NULL){
    T->root=z;
  }else if(compararDatas(z->viagem,y->viagem)==-1){
    y->left=z;
  }else{
    y->right=z;
  }

}

void tRemove(Tree* T,Node* z){
  if(z->left==NULL){
    transplant(T,z,z->right);
  }else if(z->right==NULL){
    transplant(T,z,z->left); 
  }else{
    Node* y=minimum(z->right);
    if(y->parent!=z){
      transplant(T,y,y->right);
      y->right=z->right;
      y->right->parent=y;
    }
    transplant(T,z,y);
    y->left=z->left;
    y->left->parent = y;
  }
  free(z);
}

