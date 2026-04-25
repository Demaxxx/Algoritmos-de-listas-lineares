#include <iostream>
using namespace std;

struct No {
    int chave;
    int info; // No material usa-se chave para busca e info para o valor
    No* ant;
    No* post;
};

// =======================================================================
// Algoritmo 2.24: Busca em uma lista duplamente encadeada ordenada
// =======================================================================
No* busca_dup(No* ptlista, int x) {
    No* ultimo = ptlista->ant; // ultimo := ptlista^.ant
    
    // se x <= ultimo^.chave então
    if (x <= ultimo->chave) {
        No* pont = ptlista->post; // pont := ptlista^.post
        
        // enquanto pont^.chave < x faça
        while (pont->chave < x) {
            pont = pont->post;
        }
        return pont; // busca-dup := pont
    } 
    else {
        return ptlista; // busca-dup := ptlista
    }
}

// =======================================================================
// Algoritmo 2.25: Inserção de um nó
// =======================================================================
void inserir_dup(No* ptlista, int x, int novo_valor) {
    // pont := busca-dup(x)
    No* pont = busca_dup(ptlista, x);
    
    // se pont = ptlista ou pont^.chave != x então
    if (pont == ptlista || pont->chave != x) {
        No* anterior = pont->ant; // anterior := pont^.ant
        
        No* pt = new No;          // ocupar(pt)
        pt->info = novo_valor;    // pt^.info := novo-valor
        pt->chave = x;            // pt^.chave := x
        
        pt->ant = anterior;       // pt^.ant := anterior
        pt->post = pont;          // pt^.post := pont
        
        anterior->post = pt;      // anterior^.post := pt
        pont->ant = pt;           // pont^.ant := pt
        
        cout << "-> Inserido: " << x << endl;
    } 
    else {
        cout << "Elemento ja se encontra na lista" << endl;
    }
}

// =======================================================================
// Algoritmo 2.26: Remoção de um nó
// =======================================================================
void remover_dup(No* ptlista, int x) {
    // pont := busca-dup(x)
    No* pont = busca_dup(ptlista, x);
    
    // se pont != ptlista e pont^.chave = x então
    if (pont != ptlista && pont->chave == x) {
        No* anterior = pont->ant;   // anterior := pont^.ant
        No* posterior = pont->post; // posterior := pont^.post
        
        anterior->post = posterior; // anterior^.post := posterior
        posterior->ant = anterior;  // posterior^.ant := anterior
        
        int valor_recuperado = pont->info; // valor-recuperado := pont^.info
        delete pont;                       // desocupar(pont)
        
        cout << "-> Removido: " << x << " (Valor: " << valor_recuperado << ")" << endl;
    } 
    else {
        cout << "Elemento nao se encontra na lista" << endl;
    }
}
//===========================================================================
int main() {
    // Inicialização da Lista Dupla Circular com Nó-Cabeça
    No* ptlista = new No;
    ptlista->chave = -9999; // Um valor sentinela bem pequeno
    ptlista->ant = ptlista;  // Aponta para si mesmo
    ptlista->post = ptlista; // Aponta para si mesmo

    inserir_dup(ptlista, 10, 100);
    inserir_dup(ptlista, 30, 300);
    inserir_dup(ptlista, 20, 200);

    remover_dup(ptlista, 20);
    remover_dup(ptlista, 50); // Não existe

    return 0;
}