#include <iostream>
using namespace std;

void inserir(float v[], float n, int &pos, int max);
void listar(float v[], int quant);
int buscar(float v[], int quant, float valor);
void remover(float v[], int &quant, float valor);

int main(void){
	float notas[10];
	int quant;
	float n;
	int pos;
	
	quant = 0;
	do {
		cout << "Digite um valor :";
		cin >> n;
		if (n != 0){
			inserir(notas, n, quant, 10);
		}
	}while(n!=0);
	
	listar(notas, quant);
	
	cout << "Informe o valor a ser buscado: ";
	cin >> n;
	pos = buscar(notas, quant, n);
	if (pos>= 0) cout<<"Valor encontrado na posicao " << pos << endl;
	else cout<< "Valor nao encontrado! " << endl;
	
	cout<< "Digite o valor a ser removido" <<endl;
	cin >> n;
	remover (notas,quant, n);
	
	listar(notas, quant);

}

void inserir(float v[], float n, int &pos, int max){
	if (pos >= max){
		cout<< "Erro: Lista cheia!" << endl;
	} 
	else{
		v[pos] = n;
		pos++;
	}
}

void listar (float v[], int quantidade) {
    int i;
    for (i=0; i<quantidade; i++) {
        cout << v[i] << endl;
    }
}

int buscar(float v[], int quant, float valor){
	int i;
	for (i=0; i< quant; i++){
		if (v[i] == valor){
			return i;
		}
	}
	return -1;
}

void remover (float v[], int &quant, float n){
	int pos;
	if (quant == 0) cout << "Lista Vazia!";
	else{
		pos = buscar(v, quant, n);
		if (pos < 0) cout << "Elemento nao existe";
		else{
			v[pos] = v[quant-1];
			quant--;
		}
	}
}
