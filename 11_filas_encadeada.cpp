#include <iostream>
using namespace std;
//=======================================================================
// struct pra reprensentar nó da lista
struct No {
    int chave; // informação a ser guardada
    No* prox; // ponteiro pro proximo elemento da lista
};
//=======================================================================
// Estrutura que agrupa os ponteiros da Fila para facilitar a passagem por referência
struct Fila {
    No* inicio;
    No* fim;
};

// Inicializa a fila (ambos apontam para lambda/nullptr)
void inicializar_fila(Fila &f) {
    f.inicio = nullptr;
    f.fim = nullptr;
}

// =======================================================================
// ALGORITMO 2.20: Inserção na fila
// =======================================================================
void inserir(Fila &f, int novo_valor) {
    No* pt = new No;
    
    pt->chave = novo_valor;
    
    pt->prox = nullptr;

    if (f.fim != nullptr) {
        f.fim->prox = pt;
    } else {
        f.inicio = pt;
    }
    
    f.fim = pt;
    
    cout << "-> " << novo_valor << " entrou na fila.\n";
}

// =======================================================================
// ALGORITMO 2.21: Remoção da fila
// =======================================================================
void remover(Fila &f) {
    if (f.inicio != nullptr) {
        No* pt = f.inicio;
        
        f.inicio = f.inicio->prox;
        
        if (f.inicio == nullptr) {
            f.fim = nullptr;
        }
        
        int valor_recuperado = pt->chave;
        
        delete pt;
        
        cout << "-> " << valor_recuperado << " saiu da fila.\n";
    } else {
        cout << "Erro: Underflow (Fila vazia)!\n";
    }
}

// =======================================================================
// MAIN PARA TESTE
// =======================================================================
int main() {
    Fila minhaFila;
    inicializar_fila(minhaFila);

    cout << "--- TESTANDO FILA ENCADEADA (MATERIAL 2.20/2.21) ---\n";
    inserir(minhaFila, 10);
    inserir(minhaFila, 20);
    inserir(minhaFila, 30);

    cout << "\n--- TESTANDO REMOCOES ---\n";
    remover(minhaFila); // Tira o 10
    remover(minhaFila); // Tira o 20
    remover(minhaFila); // Tira o 30
    remover(minhaFila); // Underflow!

    return 0;
}
