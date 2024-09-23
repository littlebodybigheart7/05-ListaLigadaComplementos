#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;
NO* ultimo = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;
		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{
	// se a lista já possuir elementos
// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;
	NO* aux = primeiro;
	bool elementoRep = false;

	while (aux != NULL) {
		if (aux->valor == novo->valor) {
			elementoRep = true;
			return;
		}
		aux = aux->prox;
	}
	aux = primeiro;

	if (elementoRep) {
		cout << "Este elemento ja existe na lista, digite outro elemento \n" << endl;
	}
	else {
		if (primeiro == NULL) {
			primeiro = novo;
		}
		else if (primeiro->valor > novo->valor) {
			novo->prox = primeiro;
			primeiro = novo;
		}
		else {
			while (aux->prox != NULL && aux->prox->valor < novo->valor) {
				aux = aux->prox;
			}
			novo->prox = aux->prox;
			aux->prox = novo;
		}
	}
}

void excluirElemento()
{
	if (primeiro == NULL) {
		cout << "Lista vazia. \n";
		return;
	}
	else {
		int excluir;
		cout << "Digite o elemento que quer excluir: ";
		cin >> excluir;

		NO* aux = primeiro;
		NO* anterior = NULL;
		while (aux != NULL && aux->valor <= excluir) {
			if (aux->valor == excluir) {
				break;
			}
			anterior = aux;
			aux = aux->prox;
		}
		if (aux == NULL && aux->valor != excluir) {
			if (aux == NULL || aux->valor != excluir) {
				cout << "O elemento nao esta na lista. \n";
				return;
			}
			else if (aux == primeiro) {
				primeiro = aux->prox;
			}
			else {
				anterior->prox = aux->prox;
			}
			free(aux);
			cout << "Elemento excluido! \n";
		}
}

void buscarElemento()
{
	if (primeiro == NULL) {
		cout << "Lista vazia. \n";
		return;
	}
	else {
		int procurador;
		cout << "Digite o elemento que voce deseja encontrar: ";
		cin >> procurador;

		NO* aux = primeiro;
		while (aux != NULL && aux->valor <= procurador) {
			if (aux->valor == procurador) {
				cout << "O elemento esta na lista! \n";
				return;
			}
			aux = aux->prox;
		}
		cout << "O elemento nao existe. \n";
	}
}


