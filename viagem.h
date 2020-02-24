#include "data.h"
typedef struct viagem Viagem;

int compararDatas(Viagem* v1,Viagem* v2);

Data* getData(Viagem* v);

void printDadosViagem(Viagem* v);

Viagem* criarViagem(Data* d,char* destino,int pp);

int getPermanencia(Viagem* v);
char* getLugar(Viagem* v);
