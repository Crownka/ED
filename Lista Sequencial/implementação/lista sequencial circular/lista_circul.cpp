#include <iostream>

// Preencha os métodos faltantes.
// Os passos estão marcados com "TODO".

struct SequentialCircularList {
    int size;       // Número de elementos na lista
    int maxSize;    // Capacidade máxima da lista
    int* arrayList; // Ponteiro para a lista de elementos na memória 

    // Construtor
    SequentialCircularList(int maxSize){
        this->size = 0;
        this->maxSize = maxSize;
        this->arrayList = new int[maxSize];
    }

    // Destrutor
    ~SequentialCircularList(){
        delete[] arrayList;
        std::cout << "SequentialCircularList deleted" << std::endl;
    }

    // Retorna o valor do elemento na posição 'index'
    // Como a lista é circular, não há limite para o tamanho
    // de 'index'.
    int get(int index){
        // Para encontrar a posição correta no arrayList, usamos o operador de módulo.
        int circularIndex = index % size;
        return arrayList[circularIndex];
    }

    void insert(int item){
        if(size == maxSize)
            return;
        arrayList[size] = item;
        size++;
    }

    // Remove elementos da lista
    void clear(){
        size = 0;
    }
};