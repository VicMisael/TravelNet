#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "usuario.h"
#include "data.h"
#include "tree.h"
#include "auxiliar.h"

int myId = 0;
int main(){
  Usuario* listUsers[150];
  setGlobalUsuarios(listUsers,150);
   char op;
  
  while(1){
    
  printf("========================================\n");
  printf("    BEM VINDO AO TRAVELNET  beta v0.1\n");
  printf("========================================\n\n");
  printf("Digite C:  Cadastrar \nDigite L:  Logar\n");

  scanf(" %c",&op);
  

   if(tolower(op) == (int)'c'){

     printf("\n---------------CADASTRAR-----------------\n");
     printf("Digite seu nome: ");
     char nome[45];
      scanf(" %s",nome);
     printf("Digite seu usuário: ");
     char user[45];
     scanf(" %s",user);
     printf("Digite sua senha:");
     char key[45];
     scanf(" %s",key);
     printf("-----------------------------------------\n");
     printf("Seu cadastro foi realizado com sucesso!\n\n");
    cadastrarUsuario(newUser(nome,user,getIndex(),key));
   }

   else if(tolower(op) == (int)'l'){
   

    printf("----------------LOGAR-----------------\n");
    printf("Usuário: ");
    char user[45];
    scanf("%s",user);
    char senha[45];
    printf("Senha: ");
    scanf(" %s",senha);
    int logou=0;
    for(int i=0;i<getIndex() && !logou;i++){
      if(!strcmp(getUser(getGlobalUsuario(i)),user)){
        if(!strcmp(getPassword(getGlobalUsuario(i)),senha)){
          myId = getGlobalUsuarioId(i);
          setMyid(myId);
          printf("Logado com sucesso!!!\n");
          printf("Bem vindo %s\n",getUser(getGlobalUsuario(i)));
          logou=1;
          printf("Seu id é: %d\n",getGlobalUsuarioId(i));
          inicializar(getGlobalUsuario(i));//auxiliar.c
          break;
        }else{
          printf("Credenciais erradas!!!!\n");
          i = 0;
          break;
        }
      }
      
      
        
      
      //break;     
    }

   }else if(tolower(op) == (int)'?'){
     printAllusuarios();
   }
   else
    printf("Entre com uma opção valida!!!!!\n");
}

}

