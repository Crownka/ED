Nesse exercício, implementaremos uma variação da lista encadeada simples: Lista Simplesmente Encadeada Ordenada.

Nessa lista ordenada inteiros, a informação de um nó é sempre maior ou igual a informação do nó anterior.

Por simplicidade, implementaremos as informações do nó como apenas um inteiro.

No arquivo lib.cpp, se encontra a classe SLinkedList que possui os seguintes métodos:

    OrderedSLinkedList();
    ~SLinkedList();
    void push(int info);
    int min();
    int max();
    void remove_duplicated();
    bool empty();
    void print();

Métodos riscados já estão implementados, você precisa implementar os demais.
A funcionalidade de cada método está descrita em comentários no próprio arquivo lib.cpp. Sua tarefa é alterar o arquivo lib.cpp, implementando as funcionalidades faltantes citadas. Seu código deve passar no caso de teste para ser considerado correto.

OBS.: Não altere os métodos já implementados.
OBS.2: Não precisa escrever a main()