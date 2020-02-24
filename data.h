
typedef struct data Data;

Data* criarData(int dia,int mes,int ano);
void printData(Data* data);

//retorna -1 se a primeira for menor q a segunda 0 se igual, 
//1 se a primeira for maior q a segunda
int compararData(Data* d1,Data* d2);