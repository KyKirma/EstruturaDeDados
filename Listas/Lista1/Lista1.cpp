#include <iostream>
#include <vector>
using namespace std;

void inserirSemRepetir(int v[], int x, int &pos, int max);
void listar(int v[], int qnt);
void intercalar(int vetor1[], int &tamanho1, int vetor2[], int &tamanho2, int vetor_resultante[], int &tamanho3);
void intersecao(int v1[], int max1, int v2[], int max2, int vFinal[], int &maxFinal);
void uniao(int v1[], int max1, int v2[], int max2, int vFinal[], int &maxFinal);

int main(void){
	//Declarando as variaveis
	int x, max1, max2, i;

	//A quantidade de fatores existentes na lista
	int qnt = 0, qnt2 = 0;

	cout << "Digite o tamanho maximo da primeira lista: ";
	cin >> max1;
	
	cout << "Digite o tamanho maximo da segunda lista: ";
	cin >> max2;
	
	//Declarando os vetores
	int v1[max1];
	int v2[max2];

	//Inserindo os valores
	cout << "Valores para a lista 1:" << endl;
	for (i = 0; i < max1; i++){
		cout << i << "P: ";
		cin >> x;
		inserirSemRepetir(v1, x, qnt, max1);
	}
	
	cout << "Valores para a lista 2:" << endl;
	for (i = 0; i < max2; i++){
		cout << i << "P: ";
		cin >> x;
		inserirSemRepetir(v2, x, qnt2, max2);
	}

	//Listando
	cout << "\nLista 1: ";
	listar(v1, qnt);
	cout << endl << "Lista 2: ";
	listar(v2, qnt2);

	//Novos parametros para as novas listas
	// não foi reutilizado os parametros pois as funções retornam um novo valor pra max"x"
	int maxC = max1 + max2;
	int maxD = max1 + max2;
	int maxF = max1 + max2;
	//Intercalando
	int vC[maxC];

	intercalar(v1, max1, v2, max2, vC, maxC);
	cout << endl << "Lista 3|Intercalando: ";
	listar(vC, maxC);

	//Inserseção
	int vD[maxD];

	cout << endl << "Lista 4|Intersecao: ";
	intersecao(v1, max1, v2, max2, vD, maxD);
	listar(vD, maxD);

	//União
	int vF[maxF];
	uniao(v1, max1, v2, max2, vF, maxF);
	cout << endl << "Lista 5|Uniao: ";
	listar(vF, maxF);
}


void inserirSemRepetir(int v[], int x, int &pos, int max){
	int i;
	if (pos >= max){
		cout<< "Erro: Lista cheia!" << endl;
	} 
	else{
		for (i = 0; i <= pos; i++){
			if(v[i] == x){
				cout << "Erro: Elemento repetido na posicao: " << i << endl << "Tente novamente: ";
				cin >> x;
				i = -1;
			}
		}
		v[pos] = x;
		pos++;
	}
}

void listar (int v[], int qnt) {
    int i;
    for (i = 0; i < qnt; i++) {
        cout << v[i] << " ";
    }
}

void intercalar(int vetor1[], int &tamanho1, int vetor2[], int &tamanho2, int vetor_resultante[], int &tamanho3) {
    int i = 0, j = 0, k = 0;
    while (true) {
        if (i < tamanho1) {
            vetor_resultante[k] = vetor1[i];
            i++;
            k++;
        }
        if (j < tamanho2) {
            vetor_resultante[k] = vetor2[j];
            j++;
            k++;
        }
        if(i >= tamanho1 && j >= tamanho2) break;
    }
    tamanho3 = k;
}

void intersecao(int v1[], int max1, int v2[], int max2, int vFinal[], int &maxFinal){
	int i = 0, k = 0;
	while (true) {
        if (i < max1) {
			for(int ix = 0; ix < max2; ix++){
				if(v1[i] == v2[ix]){
					vFinal[k] = v1[i];
					k++;
				}
			}
            i++;
        }
        if(i >= max1) break;
    }
	maxFinal = k;
	if(k == 0){ cout << "ERRO! Não há elementos para a intersecao."; }
}

void uniao(int v1[], int max1, int v2[], int max2, int vFinal[], int &maxFinal){
	int i, k = 0;
	for(i = 0; i < max1; i++){
		vFinal[k] = v1[i];
		k++; 
	}

	for(i = 0; i < max2; i++){
		bool pertence = false;
		for(int j = 0; j < max2; j++){
			if(v2[i] == v1[j]){
				pertence = true;
				break;
			}
		}
		if(!pertence){
			vFinal[k] = v2[i];
			k++;
		}
	}
	maxFinal = k;
}