#include <iostream>
using namespace std;
//=======================================================================
// struct pra reprensentar nó da lista
struct No {
    int chave; // informação a ser guardada
    No* prox; // ponteiro pro proximo elemento da lista
};
//=======================================================================
// busca em lista encadeada ordenada
void busca_enc(No* ptlista, int x, No*& ant, No*& pont){

    ant = ptlista; // 'ant' começa no nó-cabeça
    pont = nullptr; // 'pont' começa nulo (lambda)
    No* ptr = ptlista->prox; 
    // 'ptr' é o ponteiro de percurso (começa no 1º nó real)

    while (ptr != nullptr){ 
        if (ptr->chave < x){
            ant = ptr; // atualiza ant
            ptr = ptr->prox; // avança ptr
        }
        else if (ptr->chave == x){
            pont = ptr; // chave encontrada! guarda em 'pont'
            ptr = nullptr; // força a saída do laço
        }
        else {
            ptr = nullptr; // força a saída do laço
        }

    }
}
//=======================================================================
int main () {

    // criando o nó cabeça
    No* ptlista = new No{-1, nullptr};

    // criando os nós reais (lista ordenada)
    No* no1 = new No{10, nullptr};
    No* no2 = new No{20, nullptr};
    No* no3 = new No{40, nullptr};

    // ligando todo mundo (Nó-cabeça -> no1 -> no2 -> no3 -> NULL)
    ptlista->prox = no1;
    no1->prox = no2;
    no2->prox = no3;

    // Variáveis que vão receber os resultados da busca
    No* anterior = nullptr;
    No* encontrado = nullptr;

    // teste
    cout << "testando\n";
    int valor;
    cout << "Digite o valor procurado: ";
    cin >> valor;

    // chamando a função
    busca_enc(ptlista, valor, anterior, encontrado);

    if (encontrado != nullptr){
        cout << "Valor " << valor << " ENCONTRADO!\n";
        cout << "Ele esta logo depois do no que tem a chave: " << anterior->chave << "\n";
    }
    else {
        cout << "Valor " << valor << " NAO ENCONTRADO!\n";
    }

    return 0;
}