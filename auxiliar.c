#include "usuario.h"
#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
static Usuario** u;
static int uSize;
static int i=0;
static int myId;
//poder acessar os usuários em qualquer parte do programa





void setGlobalUsuarios(Usuario** user,int userSize){
  uSize=userSize;
  u=(Usuario**)malloc(sizeof(Usuario*)*sizeof(uSize));
  for(int i=0;i<uSize;i++){
    u[i]=user[i];
  }
  
}
//usuário especifico
Usuario* getGlobalUsuario(int i){
  if(u[i]!=NULL){
  return u[i];
  }
  else
  return NULL;
}

int getGlobalUsuarioId(int i){
  return get_id(u[i]);
}
Usuario** getGlobalUsuarios(){
  return u;
}
int getIndex(){
  return i;
}
void cadastrarUsuario(Usuario* user){
  u[i]=user;
  i++;
  
}
void printUsuariosWithoutX(int x){
  for(int g=0;g<i;g++){
    if(g!=x){
    printf("id: %d\n",get_id(u[g]));
    printUser(u[g]);
    }
  }
}

int getMyId(){
  return myId;
}



void printAllusuarios(){
  for(int g=0;g<i;g++){
   printf("id: %d\n",get_id(u[g]));
   printUser(u[g]);}
  
}

void printUsuarios(){
  for(int g=0;g<i;g++){
    int id = getMyId();
    if(get_id(u[g]) == id){
    
    
    }
    else{
    printf("id: %d\n",get_id(u[g]));
    printUser(u[g]);}
  }
}
//
void setMyid(int i){
  myId=i;

}



void inicializar(Usuario *me){
  while(1){
  printf("-----------------------------------\n");
  printf("------------PRESSIONE--------------\n1 = Adicionar Amigos.\n2 = Remover Amigos.\n3 = Mostrar amigos.\n4 = Adicionar Viagens.\n5 = Alterar Viagens.\n6 = Remover Viagens.\n7 = Mostrar Agenda \n8 = Mostrar viagens de um amigo.\n9 = Exit.\n");
  printf("-----------------------------------\n");

  int interacao;
  
  scanf("%d",&interacao);
  Node* y=getRoot(getUserTree(getGlobalUsuario(getMyId())));
  Tree* T=getUserTree(getGlobalUsuario(getMyId()));
  switch(interacao){
    case 1: 
      printUsuarios();
      printf("Digite o ID que você deseja adicionar:\n ");
      int idaux;
      scanf("%d",&idaux);
      
      if(getIndex() > idaux){
        
        add_friend(idaux); 
      }
      else

      printf("Usuario invalido\n");

      break;
    case 2: 
      printUsuarios();
      printf("Digite o ID que você deseja remover:\n ");
      int paz;
      scanf("%d",&paz);
       if(countFriends(getGlobalUsuario(getMyId())) > paz){
        
        removeFriend(paz);
      }
      else
        printf("Você não tem esse amigo adicionado!!\n");
      
      
      break;
    case 3:
      print_friends(getGlobalUsuario(getMyId()));
      break;
    case 4: 
      printf("Digite o dia da partida: ");
      int dia;
      scanf(" %d",&dia);
      printf("Digite o mes da partida: ");
      int mes;
      scanf(" %d",&mes);
      printf("Digite o ano da partida: ");
      int ano;
      scanf(" %d",&ano);
      printf("Digite a cidade: ");
      char cidade[50];
      scanf(" %s",cidade);
      printf("Digite o numero de dias que ira ficar: ");
      int dias;
      scanf(" %d",&dias);

      Node* n=createNode(criarViagem(criarData(dia,mes,ano),cidade,dias));


      insert(T,n);
      break;
    case 5:
    printf("");
      
      showAllInOrder(y);
      printf("Digite a data da viagem que deseja alterar!!!\n");
       printf("Digite o dia da partida: ");
      int diaA;
      scanf(" %d",&diaA);
      printf("Digite o mes da partida: ");
      int mesA;
      scanf(" %d",&mesA);
      printf("Digite o ano da partida: ");
      int anoA;
      scanf(" %d",&anoA); 
      Node* ga = searchDate(y,criarData(diaA,mesA,anoA));
      if(ga!=NULL){      
      Viagem* v2 = getViagemFromNode(ga);

    printf("Digite o novo dia da partida: ");
      
      scanf(" %d",&diaA);
      printf("Digite o novo mes da partida: ");
      
      scanf(" %d",&mesA);
      printf("Digite o novo ano da partida: ");
      
      scanf(" %d",&anoA); 

      printf("Digite o novo destino: ");
      char dest[45];
      scanf(" %s",dest);
      printf("Digite o novo numero de dias que ia ficar: ");
      int pp;
      scanf("%d",&pp);


      Tupdate(T,ga, criarViagem(criarData(diaA,mesA,anoA) , dest,pp));
      
      }
      else
      printf("Viagem invalida!!!\n");

      break;
    case 6:
      printf("");
      
      showAllInOrder(y);
      printf("Digite a data que deseja remover!!!\n");
       printf("Digite o dia da partida: ");
      int diaR;
      scanf(" %d",&diaR);
      printf("Digite o mes da partida: ");
      int mesR;
      scanf(" %d",&mesR);
      printf("Digite o ano da partida: ");
      int anoR;
      scanf(" %d",&anoR); 
      Node* g = searchDate(y,criarData(diaR,mesR,anoR));      
      Viagem* v1 = getViagemFromNode(g);
      printf("Deseja remover a viagem :\n");
      printDadosViagem(v1);
      char option;
      scanf(" %c",&option);
      if(option=='s'){
        tRemove(getUserTree(getGlobalUsuario(getMyId())),g);
      }
      break;
    case 7: 
      printf("As sua agenda é: \n");
      
      showAllInOrder(y);
      
      break;
    case 8:
     print_friends(getGlobalUsuario(getMyId()));
     printf("Entre com o id do amigo para ver as viagens: ");
     int idamigo;
     scanf("%d",&idamigo);
    if(idamigo<getIndex()){
        Node* k =getRoot(getUserTree(getGlobalUsuario(idamigo)  ));
        showAllInOrder(k);


    }else{
      printf("Id Inváálido");
    }
    break;
    case 9: 
      return;
      break;
  }}
}
