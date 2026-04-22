#include <iostream>
using namespace std;
//=======================================================================
// struct pra reprensentar nó da lista
struct No{
    int chave;
};
//=======================================================================
// função
int busca(No L[], int tamanho, int x){

    L[tamanho].chave = x; // coloca a sentinela no fim
    int i = 0;

    while (L[i].chave != x){
        i++;
    }

    // se achou antes do indice tamanho, o elemento existe na lista
    if (i != tamanho){
        return i; // elemento encontrado
    }
    else {
        return -1; // elemento não encontrado
    }
}
//=======================================================================
// main
int main (){

    // vetor de teste
    int tamanho = 5; 
    // tamanho com 1 espaço extra pro sentinela
    No lista[6] = {{22}, {13}, {2}, {0}, {100}};

    // pegando valor pra buscar
    int valor;
    cout << "Digite o valor a ser buscado: ";
    cin >> valor;

    // chamando a função de busca
    int resultado = busca(lista, tamanho, valor);

    // testando
    if(resultado != -1){
        cout << "Elemento encontrado! no índice [" << resultado << "]\n";
    }
    else {
        cout << "Elemento não encontrado!\n";
    }
    
    return 0;
}