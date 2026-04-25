#include <iostream>
using namespace std;
//===============================================================
// struct pra reprensentar nó da lista
struct No{
    int chave;
};
//===============================================================
// função
int busca1(No L[], int tamanho, int x) {

    int i = 0;
    int resultado = -1; // caso não encontrado

    // a cada loop verifica o limite e o valor
    while (i < tamanho){
        if (L[i].chave == x){
            resultado = i; // valor encontrado
            i = tamanho; // para a pesquisa
        }
        else {
            i++; // continua a pesquisa
        }
    }
    return resultado;
}
//===============================================================
// main
int main () {
    
    // vetor de teste
    int tamanho = 5;
    No lista[5] = {{22}, {13}, {2}, {0}, {100}};

    // pegando valor pra buscar
    int valor;
    cout << "Digite o valor a ser buscado: ";
    cin >> valor;

    // chamando a função de busca
    int resultado = busca1(lista, tamanho, valor);

    // testando
    if(resultado != -1){
        cout << "Elemento encontrado! no índice [" << resultado << "]\n";
    }
    else {
        cout << "Elemento não encontrado!\n";
    }

    return 0;
}