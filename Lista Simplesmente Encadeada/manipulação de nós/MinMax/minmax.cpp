#include <iostream>

struct Node {
    int info; // Informacao salva pelo usuario na lista
    Node *next; // Ponteiro para o proximo elemento da lista

    Node(int info, Node *next){
        this->info = info;
        this->next = next;
    };
};

void printNodes(Node* head){
    Node* temp = head;
    while(temp != NULL){
        std::cout << temp->info << std::endl;
        temp = temp->next;
    }
}

// Altere essa funcao.
// Retorne o maior elementos da lista que inicia do *head
// Pode assumir que a lista tem pelo menos um elemento
int minNode(Node* head){
    int min = head->info;
    Node* temp = head;
    while (temp != NULL) {
        if (temp->info < min) {
            min = temp->info;
        }
        temp = temp->next;
    }
    return min;
    //TODO: Declare a variavel min
    //TODO: Atribua a informacao do primeiro No a min
    
    //TODO: Inicie um No temp que aponta para o primeiro No da lista (head)
    //TODO: Enquanto nao chegar no final da lista,
    //      use o temp para passar para o proximo No.
    //      Use o *min e *max para salvar o valor no menor e maior
}

// Semelhante ao min, mas retorna o maior elemento
int maxNode(Node* head){
    int max = head->info;
    Node* temp = head;
    while (temp != NULL) {
        if (temp->info > max) {
            max = temp->info;
        }
        temp = temp->next;
    }
    return max;
    //TODO
}

int main(){
    // Cria Nos apontando para nada
    Node* node1 = new Node(10, NULL);
    Node* node2 = new Node(99, NULL);
    Node* node3 = new Node(15, NULL);
    Node* node4 = new Node(20, NULL);
    Node* node5 = new Node(2, NULL);

    // Cria variavel head que aponta para o primeiro No
    Node* head = node1;

    // Realiza a ligacao entre os Nos, formando uma lista
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = NULL;
    // [10 -> 99 -> 15 -> 20 -> 2]

    printNodes(head);
    std::cout << "min == " << minNode(head) << std::endl;
    std::cout << "max == " << maxNode(head) << std::endl;
}