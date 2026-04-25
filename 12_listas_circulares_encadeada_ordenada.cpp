#include <iostream>
using namespace std;

// 1. Estrutura do Nó
struct No {
    int chave;
    No* prox;
};

// =======================================================================
// BUSCA EM LISTA CIRCULAR ORDENADA (Baseada na pág. 58-60)
// =======================================================================
void busca_circular(No* ptlista, int x, No*& ant, No*& pont) {
    // A mágica do material: coloca a chave procurada no nó-cabeça
    ptlista->chave = x; 
    
    ant = ptlista;
    No* ptr = ptlista->prox; // Começa no primeiro nó real

    // Como o x está no nó-cabeça, o laço vai parar com certeza!
    // Se a lista for ordenada, ele para no primeiro valor >= x
    while (ptr->chave < x) {
        ant = ptr;
        ptr = ptr->prox;
    }

    // Após sair do laço, verificamos se o que encontramos é o que queríamos
    // e se não é o próprio nó-cabeça (o sentinela)
    if (ptr != ptlista && ptr->chave == x) {
        pont = ptr; // Encontrou!
    } else {
        pont = nullptr; // Não encontrou (ou parou no sentinela ou num valor maior)
    }
}

// =======================================================================
// INSERÇÃO EM LISTA CIRCULAR (Necessária para testar a busca)
// =======================================================================
void inserir_circular(No* ptlista, int x) {
    No* ant = nullptr;
    No* pont = nullptr;

    busca_circular(ptlista, x, ant, pont);

    if (pont == nullptr) {
        No* novo = new No;
        novo->chave = x;
        novo->prox = ant->prox;
        ant->prox = novo;
        cout << "-> " << x << " inserido.\n";
    } else {
        cout << "-> Erro: Chave " << x << " ja existe.\n";
    }
}

// =======================================================================
// MAIN PARA TESTE
// =======================================================================
int main() {
    // Inicialização da Lista Circular:
    // O nó-cabeça deve apontar para si mesmo no início!
    No* ptlista = new No;
    ptlista->chave = -1; // Valor qualquer, será sobrescrito pelo sentinela
    ptlista->prox = ptlista; 

    cout << "--- TESTANDO LISTA CIRCULAR ---" << endl;
    inserir_circular(ptlista, 10);
    inserir_circular(ptlista, 30);
    inserir_circular(ptlista, 20);

    // Testando a busca diretamente
    No* anterior = nullptr;
    No* encontrado = nullptr;
    int valor = 20;

    cout << "\nBuscando o valor " << valor << "..." << endl;
    busca_circular(ptlista, valor, anterior, encontrado);

    if (encontrado != nullptr) {
        cout << "Sucesso! Encontrado o valor: " << encontrado->chave << endl;
        cout << "O anterior a ele e: " << anterior->chave << endl;
    } else {
        cout << "Valor nao existe na lista." << endl;
    }

    return 0;
}