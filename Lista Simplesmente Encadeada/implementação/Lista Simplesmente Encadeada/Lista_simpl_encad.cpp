#include <iostream>

// Node: classe utilizada para representar um No
// Nao altere essa classe
struct Node {
    int info; // Informacao salva pelo usuario na lista
    Node *next; // Ponteiro para o proximo elemento da lista

    Node(); // Construtor
    Node(int info, Node *next=NULL); // Construtor
    ~Node(); // Destrutor
};

// Singly Linked List ou
// Lista Simplesmente Encadeada
// Altere somente os campos marcados com TODO
struct SLinkedList {
    Node *head;   // Ponteiro para a cabeca da lista (primeiro No)

    SLinkedList(){
        // TODO
        head = NULL;
        // Atribua NULL no valor do head
    }

    ~SLinkedList(){ // Destrutor
        // TODO
        clear();
        // dica: implemente o metodo clear e apenas o chame
    }

    // Retorna true se uma informacao pertence a lista, false caso contrario
    // index: posicao do elemento
    bool hasInfo(int info){ //  percorre a lista pra ver se o info ta lá
        // TODO: Complexidade O(n)
        Node *current = head; // começa do head e vai até encontrar ou acabar a lista
        while (current != NULL) {
            if (current->info == info) {
                return true;
            }
            current = current->next;
        }
        return false;
    }
    // Exemplo:
    // L == 10 -> 20 -> 15 -> 50
    // L.hasInfo(20) == true
    // L.hasInfo(100) == false


    // Retorna a informacao dada uma posicao
    // index: posicao do elemento
    int get(int index){ // pra retornar o valor do nó que ta no index
        // TODO: Complexidade O(n)
        Node *current = head;
        int count = 0;
        while (current != NULL) { // percorre contando a posição do nó e para quando chega no indice solicitado
            if (count == index) {
                return current->info; // retorna o valor do info desse nó
            }
            count++;
            current = current->next;
        }
        throw std::out_of_range("ERROR"); // solta uma exceção se estourar a lista
    }
    // Exemplo:
    // L == 10 -> 20 -> 15 -> 50
    // L.get(0) == 10
    // L.get(1) == 20
    // L.get(2) == 15


    // operador[] sobrecarregado. Retorna a 
    // informacao do elemento na posicao 'index'
    int operator[](int index){
        return get(index);
    }


    // Adiciona um elemento no inicio da lista
    // info: informacao do elemento a ser inserido
    void push_front(int info){
        Node* newNode = new Node(info, NULL);
        newNode->next = head;
        head = newNode;
        // Ou simplesmente
        // head = new Node(info, head);
    }
    // Exemplo:
    // L == 10 -> 20 -> 15 -> 50
    // L.push_front(30)
    // L == 30 -> 10 -> 20 -> 15 -> 50


    // Adiciona um elemento ao final da lista
    // info: informacao do elemento a ser inserido
    void push_back(int info){ // pra adicionar um novo nó no final da fila
        // TODO: Complexidade O(n)
        Node *newNode = new Node(info);
        if (head == NULL) { // se tiver vazia esse nó vira a cabeça
            head = newNode;
        } else {
            Node *current = head;
            while (current->next != NULL) { // percorre a lista até o último e atualiza pra apontar pro novo nó criado (confuso demais tive que pesquisar)
                current = current->next;
            }
            current->next = newNode;
        }
    }
    // Exemplo:
    // L == 10 -> 20 -> 15 -> 50
    // L.push_front(30)
    // L == 10 -> 20 -> 15 -> 50 -> 30


    // Remove o primeiro elemento da lista.
    // Nao faz nada se a lista esta vazia
    void pop_front(){ // tira o primeiro nó da lista
        // TODO: Complexidade O(1)
        if (head != NULL) { // se a lista não tiver vazia o nó head é removido e o ponteiro head atualiza pra apontar o próximo nó.
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
    // Exemplo:
    // L == 10 -> 20 -> 15 -> 50
    // L.pop_front()
    // L == 20 -> 15 -> 50


    // Remove o ultimo elemento da lista.
    // Nao faz nada se a lista esta vazia
    void pop_back(){ // mesma coisa só que tira o último
        // TODO: Complexidade O(n)
        if (head == NULL) {
            return;
        }
        if (head->next == NULL) { // se tiver só o head, deleta
            delete head;
            head = NULL;
        } else {
            Node *current = head; // percorre até o penultimo e remove o ultimo
            while (current->next->next != NULL) {
                current = current->next;
            }
            delete current->next;
            current->next = NULL; // e agr o penultimo aponta pra null
        }
    }
    // Exemplo:
    // L == 10 -> 20 -> 15 -> 50
    // L.pop_back()
    // L == 10 -> 20 -> 15


    // Deixa a lista vazia, com zero elementos
    void clear(){
        // TODO: Complexidade O(n)
        while (!empty()) {
            pop_front();
        }
        // dica: voce pode usar os metodos pop_front e empty
    }
    // Exemplo:
    // L == 10 -> 20 -> 15 -> 50
    // L.clear()
    // L == []


    // Retorna o numero de elementos da lista
    int length(){ // mesma coisa do index, mas aqui ele só percorre contando
        // TODO: Complexidade O(n)
        int count = 0;
        Node *current = head;
        while (current != NULL) {
            count++;
            current = current->next;
        }
        return count;
    }
    // Exemplo:
    // L == 10 -> 20 -> 15 -> 50
    // L.length() == 4


    // Devolve true se cheia e false caso contrario
    bool empty(){
        // TODO
        return head == NULL;
    }
    // Exemplo:
    // L == 10 -> 20 -> 15 -> 50
    // L.empty() == false
    // L == ''
    // L.empty() == true


    // Dado um no, retorna o proximo no da lista
    // Retorna NULL caso nao exista
    Node* successor(Node* node){
        return node->next;
    }
    // Exemplo:
    // L == 10 -> 20 -> 15 -> 50
    // L.successor(No 20) == No 15
    // L.successor(No 50) == NULL


    // Dado um No, retorna o proximo No da lista
    // Retorna NULL caso nao exista
    Node* predecessor(Node* node){ // encontra o nó anterior do pedido
        // TODO: complexidade O(n)
        if (head == NULL || head == node) {
            return NULL;
        }
        Node *current = head;
        while (current->next != NULL && current->next != node) { // percorre a lista até encontrar o nó que aponta para o nó fornecido
            current = current->next;
        }
        return current->next == node ? current : NULL; 
        // se encontrar um nó cujo próximo nó é o nó dado retorna esse nó, se chegar no final sem encontrar retorna NULL.
    }
    // Exemplo:
    // L == 10 -> 20 -> 15 -> 50
    // L.predecessor([20]) == [10]
    // L.predecessor([10]) == NULL

    // Printa as informacoes da lista
    void print(){
        std::cout << "[";
        for(Node* node = head; node != NULL; node = node->next){
            std::cout << node->info;
            if(node->next != NULL)
                std::cout << " -> ";
        }
        std::cout << "]" << std::endl;
    }    
};