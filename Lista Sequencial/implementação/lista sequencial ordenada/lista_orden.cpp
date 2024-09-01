#include <iostream>

struct SequentialSortedListInt {
    int size;       // Número de elementos na lista
    int maxSize;    // Capacidade máxima da lista
    int* arrayList; // Ponteiro para a lista de elementos na memória 

    // Construtor
    SequentialSortedListInt(int maxSize){
        this->size = 0;
        this->maxSize = maxSize;
        this->arrayList = new int[maxSize];
    }

    // Destrutor
    ~SequentialSortedListInt(){
        delete[] arrayList;
        std::cout << "SequentialSortedListInt deleted" << std::endl;
    }

    // Retorna o valor do elemento na posição 'index'
    int get(int index){
        return arrayList[index];
    }

    // Se houver espaço na lista, insere o
    // elemento 'item' na posição correta, ou seja,
    // o 'arrayList' deve permanecer ordenado (crescente)
    // após a inserção. 
    void insert(int item){
        if (size == maxSize)
            return;

        int i = size - 1;

        // Move os elementos para a direita até encontrar a posição correta
        while (i >= 0 && arrayList[i] > item) {
            arrayList[i + 1] = arrayList[i];
            i--;
        }

        // Insere o novo elemento na posição correta
        arrayList[i + 1] = item;
        size++;
    }

    // Retorna a quantidade de elementos únicos na lista.
    // Exemplo: A lista [1,2,2,3,3,3] possui 3 únicos. 
    int countUnique(){
        if (size == 0)
            return 0;

        int count = 1;

        // Contabiliza elementos únicos
        for (int i = 1; i < size; i++) {
            if (arrayList[i] != arrayList[i - 1]) {
                count++;
            }
        }

        return count;
    }

    // Remove elementos da lista
    void clear(){
        size = 0;
    }

    // Printa elementos da lista
    void print(){
        std::cout << "[";
        for(int i = 0; i < size; i++){
            std::cout << arrayList[i];
            if(i != size-1)
                std::cout << ",";
        }
        std::cout << "]" << std::endl;
    }
};
