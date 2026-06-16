# 💻 Lista de Exercícios: Estruturas de Dados

---

## 🔗 Listas Encadeadas

**1. Ordenação In-place (Crescente para Decrescente)**
Crie uma função que, dada uma lista encadeada `L` desordenada, cria uma lista `K` ordenada, com os mesmos nós da lista `L`. A função deve remover os elementos da lista `L`, sempre do menor para o maior e inseri-los no início da lista `K`.

* **Condição:** Ao final, a lista `K` deve estar ordenada em ordem decrescente. Para melhorar o desempenho, **não devem ser criados outros nós** (ou seja, os nós devem ser removidos de `L` e inseridos em `K`).

**2. Remoção de Duplicatas**
Crie uma função que remova elementos repetidos em uma lista encadeada.

**3. Transformação de Valores**
Crie uma função que faça uma busca em uma lista encadeada e modifique todos os valores ímpares para que se tornem pares.

* **Condição:** Os novos valores precisam ser múltiplos de pelo menos três números pares.

**4. Inversão de Lista**
Escreva uma função que receba uma lista simplesmente encadeada e inverta a ordem dos elementos.

* **Condição:** Para otimizar a memória e o processamento, **não poderão ser criados novos nós e nem outra lista**. Desta forma, será necessário modificar as ligações entre os nós.

**5. Remoção de Nó Específico**
Considere `A` o nó que representa o início da lista e `B` um nó pertencente à lista. Crie uma função que receba `A` e `B` e remova `B` da lista.

**6. Troca de Elementos (Lista Duplamente Encadeada)**
Crie uma função para trocar dois elementos de uma lista duplamente encadeada.

* **Condição:** A troca deve ser feita **modificando os ponteiros**, ou seja, os valores internos dos nós não poderão ser alterados.

**7. Busca Simples (`search`)**
Crie uma função chamada `search`, que receba um ponteiro `l` para uma lista de inteiros e um inteiro `x`, e retorne um ponteiro para um nó contendo `x` (se existir) ou nulo (se não existir).

**8. Inserção Condicional (`insert`)**
Escreva outra função, `insert(l, x)`, que inclua `x` em `l` **apenas se** `x` não estiver armazenado em `l`. A função deve retornar sempre um ponteiro para o nó contendo `x`.

---

## 🧮 Conjuntos

**9. Operações Usuais de Conjuntos**
Um conjunto pode ser representado pela lista de seus elementos. Sendo assim, escreva funções para as seguintes operações usuais de conjunto:

* **União:** ($C = A \cup B$)
* **Interseção:** ($C = A \cap B$)
* **Diferença:** ($C = A - B$)
* **Pertinência**

---

## 🌳 Árvores Binárias de Busca (BST)

**10. Implementação Completa de BST**
Implemente uma árvore binária de busca em que cada nó da árvore armazene os seguintes dados:

* **Chave:** (Inteiro)
* **Nome:** (String)

Crie funções para realizar as seguintes operações:

* **a.** Inserir nó na árvore.
* **b.** Procurar uma chave (recebe a chave como parâmetro). *A função deverá retornar o nome se a chave for encontrada ou `NULL` se a chave não for encontrada.*
* **c.** Retornar a menor chave.
* **d.** Retornar a maior chave.
* **e.** Exibir as chaves e os nomes com os percursos: pré-ordem, em-ordem e pós-ordem.
* **f.** Remover um nó.
* **g.** Crie um **menu** que permita ao usuário realizar as operações das funções criadas acima.