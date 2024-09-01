Nesse exercício, implementaremos métodos de uma estrutura ordenada.

Uma lista ordenada é uma estrutura similar à lista sequencial comum. Porém, após cada operação, os elementos são mantidos em uma ordem específica de acordo com os seus elementos vizinhos. Nesse exercício, utilizamos a ordem não decrescente, onde A[i-1] <= A[i] para todo i > 0.

No arquivo lib.cpp, se encontra a classe SequentialSortedListInt que possui os seguintes métodos métodos com cabeçalho, mas sem implementação:

    void insert(int item);
    bool countUnique();

O método insert deve inserir o novo elemento de tal forma que o vetor interno 'arrayList' permaneça ordenado após a inserção.
Ao implementar o método countUnique(), você pode aproveitar o fato da lista estar ordenada para fazer um algoritmo eficiente de complexidade O(n).

A funcionalidade de cada método está descrita em comentários no próprio arquivo lib.cpp. Sua tarefa é alterar o arquivo lib.cpp, implementando as funcionalidades faltantes citadas. Seu código deve passar no único caso de teste para ser considerado correto.

OBS: Não altere os métodos já implementados.

Arquivo main:


// Arquivo de execucao

#include <iostream>

#include "lib.cpp"

const int MAXSIZE = 8;



int main(){

SequentialListInt list(MAXSIZE);



 /* Testar insertBack */

list.print(); // []

list.insertBack(20);

list.print(); // [20]

list.insertBack(30);

list.print(); // [20,30]

list.insertBack(40);

list.print(); // [20,30,40]



 /* Testar get */

std::cout << list.get(0) << std::endl; // 20

std::cout << list.get(1) << std::endl; // 30

std::cout << list.get(2) << std::endl; // 40



 /* Testar getIndex */

std::cout << list.getIndex(20) << std::endl; // 0

std::cout << list.getIndex(30) << std::endl; // 1

std::cout << list.getIndex(40) << std::endl; // 2

std::cout << list.getIndex(99) << std::endl; // -1



 /* Testar insert */

list.insert(10, 0);

list.print(); // [10,20,30,40]

list.insert(50, 4);

list.print(); // [10,20,30,40,50]



 /* Testar lenght */

std::cout << list.lenght() << std::endl; // 5



 /* Testar removeBack */

list.removeBack();

list.print(); // [10,20,30,40]



 /* Testar remove */

list.remove(2);

list.print(); // [10,20,40]

list.remove(0);

list.print(); // [20,40]

list.remove(0);

list.print(); // [20]

list.remove(0);

list.print(); // []



 /* Testar remover enquanto vazio*/

list.removeBack();

list.print(); // []

list.remove(0);

list.print(); // []



 /* Testar maxSize */

std::cout << list.isFull() << std::endl; // 0

std::cout << list.isEmpty() << std::endl; // 1

list.insertBack(1);

list.insertBack(2);

list.insertBack(3);

list.insertBack(4);

list.insertBack(5);

list.insertBack(6);

list.insertBack(7);

list.insertBack(8);

list.print(); // [1,2,3,4,5,6,7,8]

list.insertBack(9);

list.print(); // [1,2,3,4,5,6,7,8]

list.insertBack(10);

list.print(); // [1,2,3,4,5,6,7,8]

std::cout << list.isFull() << std::endl; // 1

std::cout << list.isEmpty() << std::endl; // 0



 /* Testar clear */

list.clear();

list.print(); // []



 /* Destrutor chamado */

 // SequentialListInt deleted

}

