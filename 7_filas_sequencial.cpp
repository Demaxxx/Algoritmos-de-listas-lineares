#include <iostream>
using namespace std;
//=======================================================================
// estrutura da fila
struct Fila {
    int itens[5]; // capacidade maxima de 5 elementos
    int inicio; // indice do inicio (onde elementos saem)
    int retaguarda; // indice da retaguarda (onde elementos entram)
};

// inicializar fila vazia
void inicializar_fila(Fila &f) {
    f.inicio = 0;
    f.retaguarda = 0;
    // quando inicio = retaguarda, a fila tá vazia
}

// inserir (enfileirar)
void inserir(Fila &f, int x){
    int capacidade = 5;
    if (f.retaguarda < capacidade){ // ve se tem espaço no fim
        f.itens[f.retaguarda] = x; // coloca valor na retaguarda
        f.retaguarda++; // move retaguarda pro proximo espaço vazio
        cout << "-> " << x << " entrou na fila!\n";
    }
    else {
        cout << "Fila cheia!\n";
    }
}

// remover (desenfileirar)
void remover (Fila &f){
    if (f.inicio < f.retaguarda) { // ve se a fila não ta vazia
        int valor_removido = f.itens[f.inicio]; // pega o valor do inicio
        f.inicio++; // move a fila andando com o inicio pra direita 
        cout << "-> " << valor_removido << " saiu da fila!\n";
    }
    else {
        cout << "Fila vazia!\n";
    }
}
//=======================================================================
int main () {

    Fila fila01; // variavel da fila

    inicializar_fila(fila01);

    cout << "teste de entrar na fila\n";
    inserir(fila01, 10);
    inserir(fila01, 20);
    inserir(fila01, 30);
    inserir(fila01, 40);
    inserir(fila01, 50);

    inserir(fila01, 60); // inserindo elemento a mais pra testar o erro

    cout << "teste de sair da fila\n";
    remover(fila01);
    remover(fila01);
    remover(fila01);
    remover(fila01);
    remover(fila01);

    remover(fila01); // testando o erro da fila vazia

    return 0;
}