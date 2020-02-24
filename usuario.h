#include "viagem.h"
#include "tree.h"
typedef struct usuario Usuario;

Usuario* newUser();

int get_user(Usuario *id);

void add_friend(int id);

int get_id(Usuario *u);

Tree* getUserTree(Usuario* u);

int new_next(Usuario *u,Usuario *next);

int remove_friend(Usuario *id);

char* getUser(Usuario* u);

int countFriends(Usuario *u);

char* getPassword(Usuario* u);

void insert_travel(Usuario *u,Viagem *v);


void printUser(Usuario *u);

void print_friends();


void printLista();
char* getName(Usuario* u);
void removeFriend(int id);
