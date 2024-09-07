/*       ATIVIDADE        */
#include <iostream>

// Node: classe utilizada para representar um No
// NAO ALTERE ESSA CLASSE
struct Node {
    int info; // Informacao salva pelo usuario na lista
    Node *next; // Ponteiro para o proximo elemento da lista

    Node(); // Construtor
    Node(int info, Node *next=NULL); // Construtor
    
    ~Node(); // Destrutor
};

// Stack ou Pilha
// Altere somente os campos marcados com TODO
struct Stack {
    Node *top; // Ponteiro para a cabeca da lista (primeiro No)
    int size;  // Quantidade de elementos da pilha (salvar esse valor permite sua consulta em O(1))

    Stack(){
        top = NULL;
        size = 0;
    }

    ~Stack(){
        clear();
    }


    // Adiciona um elemento no topo da pilha
    // info: informacao do elemento a ser inserido
    void push(int info){
        Node* newNode = new Node(info, top);  // Cria um novo nó apontando para o topo atual
        top = newNode;  // Atualiza o topo para o novo nó
        size++;  // Incrementa o tamanho da pilha
        // TODO
    }


    // Remove um elemento do topo da pilha.
    // Nao faz nada caso a pilha esteja vazia.
    void pop(){
        if (top != NULL) {
            Node* temp = top;  // Armazena o nó do topo
            top = top->next;  // Atualiza o topo para o próximo nó
            delete temp;  // Deleta o nó anterior
            size--;  // Decrementa o tamanho da pilha
        }
        // TODO
    }


    // Retorna a informacao do elemento no topo da pilha.
    // Retorna -1, caso a pilha esteja vazia.
    int peek(){
        if (top != NULL) {
            return top->info;  // Retorna a informação do topo
        } else {
            return -1;  // Retorna -1 se a pilha estiver vazia
        }
        // TODO
    }


    // Remove todos os elementos da pilha
    void clear(){
        while (top != NULL) {
            pop();
        }
        // TODO
    }


    // Devolve true se cheia e false caso contrario
    bool empty(){
        return top == NULL;
    }


    // Printa as informacoes da lista
    void print(){
        std::cout << "[";
        for(Node* node = top; node != NULL; node = node->next){
            std::cout << node->info;
            if(node->next != NULL)
                std::cout << " -> ";
        }
        std::cout << "]" << std::endl;
    }    
};