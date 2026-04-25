#include <iostream>
using namespace std;
//=======================================================================
// estrutura da pilha
struct Pilha {
    int itens[5]; // capacidade maxima de 5 elementos
    int topo; // guarda o indice do elemento do topo
};

// inicializar pilha vazia
void inicializar_pilha(Pilha &p) {
    p.topo = -1; // -1 = pilha vazia (indice 0 já é posição)
}

// inserir (push)
void inserir (Pilha &p, int x) {
    int capacidade = 5; // tamanho do vetor
    if (p.topo < capacidade - 1){ // v~e se ainda tem espaço
        p.topo++; // sobe o topo
        p.itens[p.topo] = x; // guarda na nova posição do topo
        cout << "-> " << x << " empilhado!\n";
    }
    else {
        cout << "Pilha cheia (overflow)!\n";
    }
}

// remover (pop)
void remover (Pilha &p){
    if (p.topo >= 0){ // ve se não tá vazia
        int valor_removido = p.itens[p.topo]; // pega o valor do topo atual
        p.topo--; // desce o topo (valor fica mas vai ser sobrescrito)
        cout << "-> " << valor_removido << " desempilhado!\n";
    }
    else {
        cout << "Pilha vazia (underflow)!\n";
    }
}
//=======================================================================
int main () {

    Pilha pilha01; // variavel da pilha

    inicializar_pilha(pilha01);

    cout << "teste de empilhar (push)\n";
    inserir(pilha01, 10);
    inserir(pilha01, 20);
    inserir(pilha01, 30);
    inserir(pilha01, 40);
    inserir(pilha01, 50);

    inserir(pilha01, 60); // inserindo elemento a mais pra testar o erro

    cout << "teste de desempilhar (pop)\n";
    remover(pilha01);
    remover(pilha01);
    remover(pilha01);
    remover(pilha01);
    remover(pilha01);

    remover(pilha01); // testando o erro da pilha vazia

    return 0;
}