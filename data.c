
#include "data.h"
#include <stdio.h>
#include <stdlib.h>
struct data{
  int dia;
  int mes;
  int ano; 
};

Data* criarData(int dia,int mes,int ano){
  Data* d=(Data*) malloc(sizeof(Data));
  d->dia=dia;
  d->mes=mes;
  d->ano=ano;
  return d;
}
void printData(Data* data){
  printf("%d/%d/%d",data->dia,data->mes,data->ano);
}
//retorna -1 se a primeira for menor q a segunda 0 se igual, 
//1 se a primeira for maior q a segunda
int compararData(Data* d1,Data* d2){
  #define ano1  d1->ano
  #define ano2  d2->ano
  #define mes1  d1->mes
  #define mes2  d2->mes
  #define dia1  d1->dia
  #define dia2  d2->dia
  if(ano1>ano2){
    return 1;
  }else if(ano1<ano2){
    return -1;
  }
  if(mes1>mes2){
    return 1;
  }else if(mes1<mes2){
    return -1;
  }
  if(dia1>dia2){
    return 1;
  }else if(dia1<dia2){
    return -1;
  }
  return 0;

}