#include <iostream>
using namespace std;


struct no{
	int valor;
	no *prox;
};


no *insereInicio(no *lista, int valor);
no *removerInicio(no *lista, int &valor);


int main(void){
	no *pilha = NULL;
	int n, i, val;
	
	cout<<"Digite quantos elementos deseja inserir"<< endl;
	cin>>n;
	
	for (i=0;i<n;i++){
		cout<<"Digite o valor"<<endl;
		cin>>val;
		pilha = insereInicio(pilha,val);
	}
	
	cout<<"Digite o valor a remover"<< endl;
	cin>>val;
	
	pilha = removerInicio(pilha, val);
	
}



no *insereInicio(no *lista, int valor){
	no *tmp;
	tmp = new no;
	tmp->valor = valor;
	tmp->prox = lista;
	
	lista = tmp;
	
	return lista;
}

no *removerInicio(no *lista, int &valor){
	no *tmp;
	if (lista == NULL){
		return NULL;
	}
	valor = lista->valor;
	lista = lista->prox;
	delete tmp;
	
	return lista;
}
