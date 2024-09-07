/*       ATIVIDADE        */
#include <iostream>
#include <stack>

// Pilha Dupla
// Classe implementa duas pilhas sequenciais A e B que
// compartilham o mesmo Array de elementos
// Altere somente os campos marcados com "TODO"
struct DoubleStack {
    int sizeA;  // Quantidade de elementos da pilha A
    int sizeB;  // Quantidade de elementos da pilha B
    int capacity;  // Quantidade máxima de elementos permitidos dentro da pilha
    int *Arr; // Array onde sao salvas ambas informacoes da pilha A e pilha B

    DoubleStack(int capacity){
        sizeA = 0;
        sizeB = 0;
        this->capacity = capacity;
        Arr = new int[capacity];
    }

    ~DoubleStack(){
        delete[] Arr;
    }

    bool full(){
        return sizeA + sizeB == capacity;
    }

    ////              PILHA A             ////

    // Adiciona um elemento no topo da pilha A.
    // Nao faz nada caso a pilha esteja cheia.
    // info: informacao do elemento a ser inserido
    void pushA(int info){
        if(!full()){
            Arr[sizeA] = info; // Adiciona o elemento no topo da pilha A
            sizeA++;
        }
    }
    // Exemplo:
    // Pilha A:[1,2,3]
    // Pilha B:[4,5]
    // pushA(10)
    // Pilha A:[1,2,3,10]
    // Pilha B:[4,5]


    // Remove um elemento do topo da pilha.
    // Nao faz nada caso a pilha esteja vazia.
    void popA(){ // Remove o elemento no topo da pilha A
        if (!emptyA()) {
            sizeA--;
        }
    }
    // Exemplo:
    // Pilha A:[1,2,3]
    // Pilha B:[4,5]
    // popA()
    // Pilha A:[1,2]
    // Pilha B:[4,5]


    // Retorna a informacao do elemento no topo da pilha A.
    // Retorna -1, caso a pilha A esteja vazia.
    int peekA(){
        if (!emptyA()) {
            return Arr[sizeA - 1]; // Retorna o elemento no topo da pilha A
        } else {
            return -1; // Retorna -1 caso a pilha A esteja vazia
        }
    }
    // Exemplo:
    // Pilha A:[1,2,3]
    // Pilha B:[4,5]
    // peekA() == 3


    // Remove todos os elementos da pilha
    void clearA(){
        sizeA = 0; // Limpa a pilha A
    }
    // Exemplo:
    // Pilha A:[]
    // Pilha B:[4,5]
    // peekA() == 3


    // Devolve true se vazia e false caso contrario
    bool emptyA(){
        return sizeA == 0; // Retorna true se a pilha A estiver vazia (deixei direto, diferente do outro)
    }
    // Exemplo:
    // Pilha A:[]
    // Pilha B:[4,5]
    // emptyA() == true


    // Devolve true se cheia e false caso contrario
    // Considere o tamanho da Pilha A e Pilha B

    ///        PILHA B        ///

    // Adiciona um elemento no topo da pilha A.
    // Nao faz nada caso a pilha esteja cheia.
    // info: informacao do elemento a ser inserido 
    void pushB(int info) { // Adiciona um elemento no topo da pilha B
        if (!full()) { 
            Arr[capacity - sizeB - 1] = info; // Adiciona o elemento no topo da pilha B
            sizeB++;
        }
    }
    // Exemplo:
    // Pilha A:[1,2,3]
    // Pilha B:[4,5]
    // pushB(10)
    // Pilha A:[1,2,3]
    // Pilha B:[4,5,10]


    // Remove um elemento do topo da pilha.
    // Nao faz nada caso a pilha esteja vazia.
    void popB() { // Remove o elemento no topo da pilha B
        if (!emptyB()) {
            sizeB--;
        }
    }
    // Exemplo:
    // Pilha A:[1,2,3]
    // Pilha B:[4,5]
    // popB()
    // Pilha A:[1,2,3]
    // Pilha B:[4]


    // Retorna a informacao do elemento no topo da pilha A.
    // Retorna -1, caso a pilha A esteja vazia.
    int peekB() {
        if (!emptyB()) {
            return Arr[capacity - sizeB]; // Retorna o elemento no topo da pilha B
        } else {
            return -1; // Retorna -1 caso a pilha B esteja vazia
        }
    }
    // Exemplo:
    // Pilha A:[1,2,3]
    // Pilha B:[4,5]
    // peekB() == 5


    // Remove todos os elementos da pilha
    void clearB() {
        sizeB = 0; // Limpa a pilha B
    }
    // Exemplo:
    // Pilha A:[1,2,3]
    // Pilha B:[4,5]
    // clearB()
    // Pilha A:[1,2,3]
    // Pilha B:[]


    // Devolve true se vazia e false caso contrario
    bool emptyB(){
        return sizeB == 0; // Retorna true se a pilha B estiver vazia (deixei direto, diferente do outro)
    }


    // Printa as informacoes da lista
    void print(){
        std::stack<int> stk;

        std::cout << "Pilha A: [";
        while(!emptyA()){
            stk.push(peekA());
            popA();
        }

        while(!stk.empty()){
            std::cout << stk.top();
            pushA(stk.top());
            stk.pop();
            if(!stk.empty()) std::cout << ", ";
        }
        std::cout << "]" << std::endl;

        //////////////////////////////////////////

        std::cout << "Pilha B: [";
        while(!emptyB()){
            stk.push(peekB());
            popB();
        }

        while(!stk.empty()){
            std::cout << stk.top();
            pushB(stk.top());
            stk.pop();
            if(!stk.empty()) std::cout << ", ";
        }
        std::cout << "]" << std::endl;
    }  
};