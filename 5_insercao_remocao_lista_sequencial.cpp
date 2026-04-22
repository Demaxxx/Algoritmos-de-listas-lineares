#include <iostream>
using namespace std;
//========================================================================
// struct pra reprensentar nó da lista
struct No {
    int chave;
};
//========================================================================
// função de busca pra ser usada abaixo na inserção e remoção
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
//========================================================================
// algoritmo de inserção
void inserir(No L[], int &tamanho, int m, int x){

    if (tamanho < m){ // verifica se tem espaço na memória
        if (busca(L, tamanho, x) == -1){ // se busca retorna nulo
            L[tamanho].chave = x;
            tamanho++; // aumenta tamanho da lista
            cout << "elemento " << x << " inserido!\n";
        }
        else {
            cout << "elemento " << x << " já tem na lista!\n";
        }
    }
    else {
        cout << "Overflow (lista cheia)!\n";
    }
}
//========================================================================
// algoritmo de remoção
void remover(No L[], int &tamanho, int x){

    int i = busca(L, tamanho, x); // descobre em que indice tá o elemento
    if (i != -1){ // se for diferente de nulo, encontrou
        for(int j = i; j < tamanho - 1; j++){
            L[j].chave = L[j + 1].chave; 
        }
        tamanho--; // diminui o tamanho da lista
        cout << "elemento " << x << " removido!\n";
    }
    else {
        cout << "elemento " << x << " não encontrado!\n";
    }

}
//=======================================================================
// função extra pra imprimir a lista
void imprimir(No L[], int tamanho){
    cout << "Lista Atual: [ ";
    for(int i = 0; i < tamanho; i++){
        cout << L[i].chave << " ";
    }
    cout << "]\n";
}
//=======================================================================
// main
int main (){

    int m = 5; // capacidade máxima da memória
    int tamanho = 0; // lista começa vazia

    No L[6]; // vetor com 1 espaço extra pro sentinela

    // teste de inserção
    inserir(L, tamanho, m, 10);
    inserir(L, tamanho, m, 20);
    inserir(L, tamanho, m, 30);
    inserir(L, tamanho, m, 40);
    inserir(L, tamanho, m, 50);
    inserir(L, tamanho, m, 60);
    
    imprimir(L, tamanho);

    // teste de remoção
    remover(L, tamanho, 30);

    imprimir(L, tamanho);

    return 0;
}