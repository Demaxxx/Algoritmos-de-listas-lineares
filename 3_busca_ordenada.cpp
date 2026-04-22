#include <iostream>
using namespace std;
//=======================================================================
// struct pra reprensentar nó da lista
struct No{
    int chave;
};
//=======================================================================
// função
int busca_ord(No L[], int tamanho, int x){
    
    L[tamanho].chave = x; // coloca sentinela no fim
    int i = 0;

    // loop para assim que encontrar número maior ou igual a x
    while(L[i].chave < x) {
        i++;
    }
    // verifica por que parou
    if (i != tamanho && L[i].chave == x){
        return i; // elemento encontrado
    }
    else {
        return -1; // não encontrado (maior que x ou era a sentinela)
    }
}
//=======================================================================
// main
int main (){

    // lista tem que ser ordenana (óbvio)
    int tamanho = 5;
    // tamanho com 1 espaço extra pro sentinela
    No lista[6] = {{10}, {20}, {30}, {40}, {50}};

    // pegando valor pra buscar
    int valor;
    cout << "Digite o valor a ser buscado: ";
    cin >> valor;

    // chamando a função de busca
    int resultado = busca_ord(lista, tamanho, valor);

    // testando
    if(resultado != -1){
        cout << "Elemento encontrado! no índice [" << resultado << "]\n";
    }
    else {
        cout << "Elemento não encontrado!\n";
    }

    return 0;
}