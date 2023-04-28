#include <iostream>
using namespace std;

void inserirSemRepetir(int v[], int x, int &pos, int max);
void listar(int v[], int qnt);

int main(void){
	//Declarando as variaveis
	int x, max, max2, i;

	//A quantidade de fatores existentes na lista
	int qnt = 0, qnt2 = 0;

	cout << "Digite o tamanho maximo da primeira lista: ";
	cin >> max;
	
	cout << "Digite o tamanho maximo da segunda lista: ";
	cin >> max2;
	
	//Declarando os vetores
	int v1[max];
	int v2[max2];

	//Inserindo os valores
	cout << "Valores para a lista 1:" << endl;
	for (i = 0; i < max; i++){
		cout << i << "P: ";
		cin >> x;
		inserirSemRepetir(v1, x, qnt, max);
	}
	
	cout << "Valores para a lista 2:" << endl;
	for (i = 0; i < max2; i++){
		cout << i << "P: ";
		cin >> x;
		inserirSemRepetir(v2, x, qnt2, max2);
	}

	//Listando
	cout << "\nLista 1:" << endl;
	listar(v1, qnt);
	cout << endl << "Lista 2:" << endl;
	listar(v2, qnt2);

	//Intercalando
	if (max == max2){
	int max3 = max + max2;
	int v3[max3];
	int k = 0;
	for (i = 0; i < max3;){
		if (i % 2 == 0){
			k = i / 2;
		}

		if (k < max){
			v3[i] = v1[k];
			i++;
			}
		if (k < max2){
			v3[i] = v2[k];
			i++;
			} 
		}

	cout << endl << "Lista 3:" << endl;
	listar(v3, max3);
	} else {
		cout << "Não foi possivel intervalar";
	}
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