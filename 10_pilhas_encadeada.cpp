#include <iostream>
using namespace std;
//=======================================================================
// struct pra reprensentar nó da lista
struct No {
    int chave; // informação a ser guardada
    No* prox; // ponteiro pro proximo elemento da lista
};
//=======================================================================
// inserir (push)
void inserir(No*& topo, int x) {
    No* ptr = new No;  // Cria a nova caixinha
    ptr->chave = x;    // Guarda o valor
    
    ptr->prox = topo;  // O novo nó aponta para o antigo topo (que está embaixo dele)
    topo = ptr;        // O ponteiro 'topo' agora aponta para o novo nó
    
    cout << "-> " << x << " empilhado!\n";
}
//=======================================================================
// remover (pop)
void remover(No*& topo) {
    if (topo != nullptr) { // Verifica se a pilha não está vazia
        No* ptr = topo;          // Guarda o nó do topo numa variável temporária
        int valor = ptr->chave;  // Salva o valor só para mostrar na tela
        
        topo = topo->prox;       // O 'topo' desce para o próximo nó da pilha
        delete ptr;              // Destrói a caixinha velha da memória
        
        cout << "-> " << valor << " desempilhado!\n";
    } else {
        cout << "-> Erro: Pilha vazia (Underflow)!\n";
    }
}
//=======================================================================
int main() {
    No* topo = nullptr; // A pilha começa vazia (aponta para o nada)

    cout << "--- TESTANDO PILHA ENCADEADA ---\n";
    inserir(topo, 10);
    inserir(topo, 20);
    inserir(topo, 30); // 30 é o topo agora!

    cout << "\n--- TESTANDO REMOCAO ---\n";
    remover(topo); // Tira o 30
    remover(topo); // Tira o 20

    return 0;
}