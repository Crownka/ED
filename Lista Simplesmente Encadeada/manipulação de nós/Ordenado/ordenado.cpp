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
    std::cout << "[ ";
    Node* temp = head;
    while(temp != NULL){
        std::cout << temp->info << " ";
        temp = temp->next;
    }
    std::cout << "]" << std::endl;
}

// Altere essa funcao.
// Retorna 'true' se a lista esta ordenada, false caso contrario
// Uma lista L esta ordenada se L[i] <= L[i+1] para todo  0 <= i < n
// ou seja, todo elemento e menor ou igual ao seu sucessor
bool isSorted(Node* head){
    if (head == NULL || head->next == NULL) {
        return true;
    }
    
    Node* temp = head;
    while (temp->next != NULL) {
        if (temp->info > temp->next->info) {
            return false;
        }
        temp = temp->next;
    }
    
    return true;
    // TODO
}


int main(){
    /*    TESTE 1   */
    // No vazio
    printNodes(NULL);
    if(isSorted(NULL)){
        std::cout << "ordenado" << std::endl;
    }else{
        std::cout << "nao ordenado" << std::endl;
    }

    /*    TESTE 2   */
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
    if(isSorted(head)){
        std::cout << "ordenado" << std::endl;
    }else{
        std::cout << "nao ordenado" << std::endl;
    }

    /*    TESTE 3   */
    Node* head2 = new Node(10,new Node(20, new Node(30, new Node(40, new Node(40, NULL)))));
    // [10 -> 20 -> 30 -> 40 -> 40]
    printNodes(head2);
    if(isSorted(head2)){
        std::cout << "ordenado" << std::endl;
    }else{
        std::cout << "nao ordenado" << std::endl;
    }
}