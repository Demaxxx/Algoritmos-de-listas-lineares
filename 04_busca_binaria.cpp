#include <iostream>
using namespace std;
//=======================================================================
// struct pra reprensentar nó da lista
struct No{
    int chave;
};
//=======================================================================
// função
int busca_bin(No L[], int tamanho, int x){

    int inf = 0; // inicio da lista
    int sup = tamanho - 1; // fim da lista

    // enquanto inferior não ultrapassar superior (ainda ter espaço p/ buscar)
    while (inf <= sup) {
        int meio = (inf + sup) / 2; //calcula o indice do meio

        if(L[meio].chave == x){
            return meio; // achou no meio
        }
        else if (L[meio].chave < x){
            // valor do meio é menor que o procurado
            // Esquece a metade esquerda e ajusta o 'inf'
            inf  = meio + 1;
        }
        else {
            // valor do meio é maior que o procurado
            // Esquece a metade direita e ajusta o 'sup'
            sup = meio - 1;
        }
    }
    // caso não ache
    return -1;
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
    int resultado = busca_bin(lista, tamanho, valor);

    // testando
    if(resultado != -1){
        cout << "Elemento encontrado! no índice [" << resultado << "]\n";
    }
    else {
        cout << "Elemento não encontrado!\n";
    }

    return 0;
}