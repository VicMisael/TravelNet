#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "data.h"
#include "viagem.h"
#include <stdlib.h>

struct viagem{
  char lugar[45];
  Data* partida;
  int periodoDePermanencia;
};

//retorna -1 se a data da  primeira for menor q a segunda 0 se igual, 
//1 se a primeira for maior q a segunda
int compararDatas(Viagem* v1,Viagem* v2){
  return compararData(v1->partida,v2->partida);


}
Data* getData(Viagem* v){
  return v->partida;
}
char* getLugar(Viagem* v){
return v->lugar;

}
int getPermanencia(Viagem* v){
  return v->periodoDePermanencia;
}

Viagem* criarViagem(Data* d,char* destino,int pp){
  Viagem* v=(Viagem*)malloc(sizeof(Viagem));
  v->partida=d;
  strcpy(v->lugar,destino);
  v->periodoDePermanencia=pp;
  return v;
}



void printDadosViagem(Viagem* v){
Data *d;
d = getData(v);
printf("Data:");
printData(d);
printf("\n");
printf("O Lugar de estadia é:%s \n",getLugar(v));
printf("O tempo de permanencia: %d \n",getPermanencia(v));

  
}
