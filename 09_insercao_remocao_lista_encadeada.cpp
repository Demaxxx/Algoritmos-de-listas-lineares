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
// inserção em lista endadeada ordenada
void inserir_enc(No* ptlista, int x) {
    No* ant = nullptr;
    No* pont = nullptr;
    
    // 1. Busca onde o elemento deveria estar
    busca_enc(ptlista, x, ant, pont);

    // 2. Se for nulo, o elemento não existe, então podemos inserir
    if (pont == nullptr) { 
        No* ptr = new No;      // Cria a nova caixinha
        ptr->chave = x;        // Guarda a informação
        
        // 3. Fazendo as ligações ("costurando" o nó na lista)
        ptr->prox = ant->prox; // A nova caixa aponta pro próximo elemento
        ant->prox = ptr;       // A caixa anterior aponta pra nova caixa
        
        cout << "-> Valor " << x << " inserido com sucesso!\n";
    } 
    else {
        cout << "-> Atencao! O valor " << x << " ja existe na lista!\n";
    }
}
//=======================================================================
// remoção em lista endadeada ordenada
void remover_enc(No* ptlista, int x) {
    No* ant = nullptr;
    No* pont = nullptr;
    
    // 1. Busca o elemento
    busca_enc(ptlista, x, ant, pont);

    // 2. Se for diferente de nulo, ele existe, então podemos remover
    if (pont != nullptr) { 
        
        // 3. "Pula" o nó que vai ser removido
        ant->prox = pont->prox; 
        
        // 4. Apaga o nó da memória do computador
        delete pont; 
        
        cout << "-> Valor " << x << " removido com sucesso!\n";
    } 
    else {
        cout << "-> Erro: Valor " << x << " nao encontrado para remocao!\n";
    }
}
//=======================================================================
// Função extra para mostrar a lista
void imprimir_lista(No* ptlista) {
    No* ptr = ptlista->prox; // Começa no primeiro nó real (pula o nó-cabeça)
    cout << "Lista: [ ";
    while (ptr != nullptr) {
        cout << ptr->chave << " ";
        ptr = ptr->prox;
    }
    cout << "]\n";
}
//=======================================================================
int main () {

    // Só precisamos criar o nó-cabeça! A lista começa vazia.
    No* ptlista = new No{-1, nullptr};

    cout << "--- TESTANDO INSERCOES ---\n";
    // inserindo fora de ordem, mas a lista vai ficar ordenada
    inserir_enc(ptlista, 40);
    inserir_enc(ptlista, 10);
    inserir_enc(ptlista, 20);
    inserir_enc(ptlista, 15); // Vai entrar exatamente entre o 10 e o 20!
    inserir_enc(ptlista, 10); // Vai dar erro de duplicado
    
    imprimir_lista(ptlista);

    cout << "\n--- TESTANDO REMOCOES ---\n";
    remover_enc(ptlista, 20); // Removendo do meio
    remover_enc(ptlista, 10); // Removendo do começo
    remover_enc(ptlista, 99); // Tentando remover um que não existe
    
    imprimir_lista(ptlista);

    return 0;
}