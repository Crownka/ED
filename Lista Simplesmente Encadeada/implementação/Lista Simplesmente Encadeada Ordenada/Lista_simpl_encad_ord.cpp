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
struct OrderedSLinkedList {
    Node *head; // Ponteiro para a cabeca da lista (primeiro No)

    OrderedSLinkedList(){
        this->head = NULL;
    }

    // Para esse exercicio, nao precisa implementar o destrutor
    // ~OrderedSLinkedList();

    // Adiciona um elemento na lista, mantendo a ordenação das informacoes da lista
    // info: informacao do elemento a ser inserido
    void push(int info){
        // TODO: Complexidade O(n)
        Node *newNode = new Node(info);
        if (head == NULL || head->info >= info) { // se a lista for vazia ou info é menor que o valor do primeiro nó, o novo nó vira a cabeça da lista.
            newNode->next = head;
            head = newNode;
        } else {
            Node *current = head;
            while (current->next != NULL && current->next->info < info) { // percorre os nós até encontrar a posição onde deve inserir o novo valor
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }
    // Exemplo:
    // L == []
    // L.push(4)
    // L == 4
    // L.push(10)
    // L == 4 -> 10
    // L.push(18)
    // L == 4 -> 10 -> 18
    // L.push(1)
    // L == 1 -> 4 -> 10 -> 18
    // L.push(4)
    // L == 1 -> 4 -> 4 -> 10 -> 18

    // Retorna a maior informacao da lista
    // Pode assumir que a lista possui pelo menos 1 elemento
    int min(){
        // TODO
        if (head == NULL) { // menor valor vai ser sempre a cabeça(se estiver ordenada)
            throw std::out_of_range("Lista Vazia");
        }
        return head->info;
    }
    // Exemplo:
    // L == 1 -> 4 -> 4 -> 10 -> 18
    // L.min() == 1


    // Retorna a maior informacao da lista
    // Pode assumir que a lista possui pelo menos 1 elemento
    int max(){
        // TODO
        if (head == NULL) {
            throw std::out_of_range("Lista Vazia");
        }
        Node *current = head;
        while (current->next != NULL) { // percorre a lista até encontrar o último nó, que vai ter o maior valor
            current = current->next;
        }
        return current->info;
    }
    // Exemplo:
    // L == 1 -> 4 -> 4 -> 10 -> 18
    // L.max() == 18

    // Remove todos elementos com informacao duplicada da lista.
    // Sobrando apenas os nos com informacoes únicas.
    void remove_duplicated(){
        // TODO: Complexidade O(n)
        // dica: aproveite que os elementos estao ordenados
    }
    // Exemplo:
    // L == 1 -> 1 -> 1 -> 1 -> 2 -> 2 -> 2 -> 4 -> 4 -> 8
    // L.remove_duplicated()
    // L == 1 -> 2 -> 4 -> 8
    // L.remove_duplicated()
    // L == 1 -> 2 -> 4 -> 8

    bool empty(){
        return head == NULL;
    }

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