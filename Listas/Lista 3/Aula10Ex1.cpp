#include <iostream>
using namespace std;

struct no{
	int valor;
	no *ptr;
};

no *inserirInicio(no *lista, int valor);
void imprimir(no * lista);
void substituir(no *lista, int pos, int valor);
no *removerInicio(no *lista);
no *buscar(no *lista, int valor);

int main(void){
	no *lista = NULL;
	int n, i, val, busc;
	
	cout<<"Quantos valores pretende digitar?"<<endl;
	cin>>n;
	
	for (i=0;i<n;i++){
		cout<<"Digite o valor" <<i+1 <<" :"<<endl;
		cin>>val;
		lista = inserirInicio(lista, val);
	}
	cout<<"Digite um valor pra ser buscado" << endl;
    cin >> busc;
    cout<<"Buscando valor na lista"<<endl;
	buscar(lista, busc);
	cout<<"Imprimindo lista Original"<<endl;
	imprimir(lista);
	substituir(lista,3,555);
	cout<<"Imprimindo lista Alterada"<<endl;
	imprimir(lista);
	lista = removerInicio(lista);
	cout<<"Imprimindo lista elemento removido"<<endl;
	imprimir(lista);
	
}

no *buscar(no *lista, int valor){
    int val = 0;
    no *tmp;
	tmp = lista;
	while(tmp != NULL){
        if(tmp -> valor == valor){
            val++;
        }
		tmp = tmp->ptr;
	}
    cout << "foram encontradas: " << val <<" ocorrencias." << endl;
}

no *inserirInicio(no *lista, int valor){
	no * tmp;
	tmp = new no;
	tmp->valor = valor;
	tmp->ptr = NULL;
	if (lista == NULL) {
		lista = tmp;
	}
	else{
		tmp->ptr = lista;
		lista = tmp;
	}
	return lista;
}

void imprimir(no * lista){
	no *tmp;
	tmp = lista;
	while(tmp != NULL){
		cout<<tmp->valor<<endl;
		tmp = tmp->ptr;
	}
}

void substituir(no *lista, int pos, int valor){
	int i;
	no *tmp;
	
	if (pos < 1){
		cout<<"Posição Incorreta!"<<endl;
		return;
	}
	
	tmp = lista;
	i = 1;
	while(tmp != NULL){
		if (i == pos){
			tmp->valor = valor;
			break;
		}
		tmp = tmp->ptr;
		i++;
	}
}

no *removerInicio(no *lista){
	no *tmp;
	if (lista == NULL){
		cout<<"Lista Vazia"<<endl;
		return lista;
	}
	
	tmp = lista;
	lista = tmp->ptr;
	delete tmp;
	return lista;
}