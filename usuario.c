#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"
#include "tree.h"
#include "auxiliar.h"

//static int myId;
struct usuario{
  Tree *t;
  int queueFriends[150];

  
  int id;

  char *user;
  char *password;
  char *name;

};

Usuario* newUser(char* name,char* user,int id,char* password){
  Usuario *usuario = (Usuario*)malloc(sizeof(Usuario));
  usuario->t = createTree();
  
  
  usuario->id = id;
  usuario->name=(char*)malloc(sizeof(char)*strlen(name));
  strcpy(usuario->name,name);
  usuario->user=(char*)malloc(sizeof(char)*strlen(user));
  strcpy(usuario->user,user);
  usuario->password=(char*)malloc(sizeof(char)*strlen(password));
  strcpy(usuario->password,password);
  memset(usuario->queueFriends,-1,sizeof(int)*150);
  return usuario;
}
int get_id(Usuario *u){
  return u->id;
}

Tree* getUserTree(Usuario* u){
  return u->t;
}

void add_friend(int id){
  int i = 0;
  while(getGlobalUsuario(getMyId())->queueFriends[i] != -1){
    i++;
  }
  getGlobalUsuario(getMyId())->queueFriends[i] = id;
  i=0;
  while(getGlobalUsuario(id)->queueFriends[i] != -1){
    i++; 
  }
  getGlobalUsuario(id)->queueFriends[i] = getMyId();

}

char* getName(Usuario* u){
  return u->name;
}

char* getUser(Usuario* u){
  return u->user;
}



char* getPassword(Usuario* u){
  return u->password;
}

void print_friends(Usuario* u){
int i = 0;
while(u->queueFriends[i] != -1){
  printf("Id amigo: %d\n",u->queueFriends[i]);
  printf("Nome: %s\n",getName(getGlobalUsuario(u->queueFriends[i])));
  i++;
}

}
void printUser(Usuario *u){
  printf("Usuario: %s \n",u->user);
  printf("Nome: %s \n",u->name);
}

int countFriends(Usuario *u){
  int k = 0;
  while(u->queueFriends[k]!=-1){
    k++;
  }
  return k;
}

void removeFriend(int id){
  int i = 0;
  while(getGlobalUsuarioId(i)!= id){
    i++;
  }
 
 for(int j = 0;j<150;j++){
   getGlobalUsuario(getMyId())->queueFriends[j] = getGlobalUsuario(getMyId())->queueFriends[j+1];}
}

//Inserir Viagem,passo a passo, 
//

//insert(T,createNode(criarViagem(CriarData(xx/xx/xx),lugar,periodo)))