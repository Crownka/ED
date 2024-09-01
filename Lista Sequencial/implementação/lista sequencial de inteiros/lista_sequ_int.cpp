#include <iostream>
// Preencha os metodos faltantes.
// Os passos estao marcados com "TODO".

struct SequentialListInt {
    int size;       // Numero de elementos na lista
    int maxSize;    // Capacidade maxima da lista
    int* arrayList; // Ponteiro para a lista de elementos na memoria 

    // Construtor
    SequentialListInt(int maxSize){
        this->size = 0;
        this->maxSize = maxSize;
        arrayList = new int[maxSize];
        // TODO: Alocar um vetor de tamanho 'maxSize' e salvar
        //       seu endereço no ponteiro 'arrayList'
    }

    bool isEmpty(){
        if(size == 0)
            return true;

        return false;
        // TODO: Retorne true quando a lista nao possui elementos.
    }
    //feito
    bool isFull(){
        if( size == maxSize)
            return true;

        return false;
        // TODO: Retorne true quando a quantidade de elementos esta no maximo.
    }
    //feito
    //deve ser feito os casos de exceção?
    // Retorna o valor do elemento na posicao 'index'
    int get(int index){

            // TODO: Retornar elemento na posicao 'index'
        return arrayList[index];
    }

    // Retorna a posicao do primeiro elemento com valor igual a 'item'.
    // Caso o elemento nao exista na lista, retorna -1.
    int getIndex(int item){
            // TODO: Percorrer cada elemento do vetor e retornar caso encontre
            //       um elemento igual a 'item'.
        for(int i = 0; i < size; i++)
            if( arrayList[i] == item ) 
                return i;
            // TODO: Retornar -1 caso nao encontre o elemento. 
        return -1;
    }
    // Se a lista nao estiver vazia,
    // remove elemento na posicao 'index'.
    void remove(int index){
            // TODO: Verificar se a fila esta vazia.
            //       Se estiver, retorne!
        if(size == 0) return;
            // TODO: Mova todos os elementos apos o
            //       'index' uma posicao para esquerda.(serio como diminuir 1?)
        for(int i = index; i < size-1; i++ )
            arrayList[i] = arrayList[i+1];
            // TODO: Atualize o 'size'.
        size--;
    }

    // Remove elementos da lista
    void clear(){
        // TODO: Atualize o 'size'.
        size = 0;
    }

    // Se houver espaco na lista, insere o
    // elemento 'item' na posicao 'index' da lista
    void insert(int item, int index){
            // TODO: Verificar se a fila esta cheia.
            //       Se estiver, retorne!
        if(size == maxSize)    return;
            // TODO: Mova todos os elementos apos o
            //       'index' uma posicao para direita.
        for(int i = size; i > index; i --)
            arrayList[i]= arrayList[i-1];
            // TODO: Atribua o valor de 'item' ao elemento
            //       na posicao 'index'.
        arrayList[index] = item ;
            // TODO: Atualize o 'size'
        size ++;
    }
    
    // elemento 'item' no final da lista.
    void insertBack(int item){
        if(size == maxSize)
            return;

        arrayList[size] = item;
        size++;
    }

    // Se a lista nao estiver vazia,
    // remove o ultimo elemento.
    void removeBack(){
        if(size == 0) return;
        size--;
    }


    // Retorna o tamanho da lista
    int lenght(){
        return size;
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
    // Destrutor
    ~SequentialListInt(){
        delete arrayList;
        std::cout << "SequentialListInt deleted" << std::endl;
    }
};