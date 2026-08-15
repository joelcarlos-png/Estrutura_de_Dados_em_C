English version here: [LINK](./README.md)

# Estruturas de Dados em C 🚀
Este repositório contém implementações de estruturas de dados fundamentais, desenvolvidas para fins de estudo e prática da linguagem C.  
O projeto aborda os conceitos de **Pilhas**, **Filas**, **Listas** e **Árvores**, explorando as diferenças entre alocação **Estática** e **Dinâmica (Encadeada)**.

---

## 📋 Conteúdo

O projeto está estruturado em vários módulos principais:

### 1. Pilhas (Stacks) - Conceito LIFO (Last In, First Out)
* **Pilha Estática:** Implementação utilizando arrays (vetores) com tamanho pré-definido.
* **Pilha Encadeada:** Implementação dinâmica utilizando ponteiros, onde o tamanho aumenta conforme a necessidade.

### 2. Filas (Queues) - Conceito FIFO (First In, First Out)
* **Fila Estática:** Implementação com vetores, geralmente utilizando a lógica de fila circular para melhor aproveitamento do espaço.
* **Fila Encadeada:** Implementação dinâmica com nós apontando para o próximo elemento, permitindo crescimento flexível.

### 3. Listas (Lists)
* **Lista Estática:** Implementação de lista utilizando vetores.
* **Lista Encadeada:** Implementação dinâmica de lista utilizando ponteiros (simples e dupla).
* **Lista Encadeada Circular:** Implementação dinâmica onde o último elemento aponta de volta para o primeiro, formando um ciclo (simples e dupla).

### 4. Árvores (Trees)
* **Árvore Binária:** Implementação de árvores binárias e árvores binárias de busca (BST).
* **Árvore AVL:** Árvore binária de busca autobalanceada.
* **Árvore Rubro-Negra:** Árvore binária de busca autobalanceada com balanceamento baseado em cores.

---

## 💻 Tecnologias e Conceitos Aplicados

* **Linguagem:** C
* **Gestão de Memória:** `malloc()`, `free()`, e manipulação de ponteiros.
* **Modularização:** Separação entre definição (`.h`), implementação (`.c`) e execução (`main.c`).
* **Tipos Abstratos de Dados (TAD):** Encapsulamento das estruturas para manter o código organizado e seguro.

---

## 📂 Estrutura de Pastas

```text
.
├── Pilhas/
│   ├── Pilha_Estatica/           # Implementação de Pilha com Vetor
│   └── Pilha_Encadeada/          # Implementação de Pilha com Ponteiros
├── Filas/
│   ├── Fila_Estatica/            # Implementação de Fila com Vetor
│   └── Fila_Encadeada/           # Implementação de Fila com Ponteiros
├── Listas/
│   ├── Lista_Estatica/           # Implementação de Lista com Vetor
│   ├── Lista_Encadeada/          # Implementação de Lista com Ponteiros (simples e dupla)
│   └── Lista_Encadeda_Circular/  # Implementação de Lista Circular com Ponteiros
├── Arvores/
│   ├── Arvores_Binarias/         # Implementação de Árvore Binária / BST
│   ├── Arvores_AVL/              # Implementação de Árvore AVL
│   └── Arvore_RubroNegra/        # Implementação de Árvore Rubro-Negra
├── includes/                     # Bibliotecas usadas para todas as pastas acima
├── README.md                     # Documentação do projeto (inglês)
└── README_pt-BR.md               # Documentação do projeto (português)
```

## 🚀 Como Executar o Projeto

Para testar qualquer uma das estruturas, siga os passos abaixo:

1.  **Clone o repositório:**

    ```bash
    git clone https://github.com/joelcarlos-png/Estrutura_de_Dados_em_C.git
    ```

2.  **Acesse a pasta da estrutura desejada:**

    ```bash
    cd Pilhas/Pilha_Encadeada
    ```

3.  **Compile os arquivos fonte:**

    ```bash
    gcc main.c pilha_encadeada.c -o programa
    ```

4.  **Execute o binário gerado:**

    ```bash
    ./programa
    ```

-----

## 📊 Comparativo Rápido

| Característica | Estática | Encadeada |
| :--- | :--- | :--- |
| **Alocação** | Memória contígua (Vetor) | Memória dispersa (Ponteiros) |
| **Tamanho** | Fixo (definido na compilação) | Dinâmico (ajusta em tempo de execução) |
| **Uso de Memória** | Ocupa o espaço total desde o início | Ocupa apenas o necessário para cada nó |

-----

## ✍️ Autor

Desenvolvido por **Joel Carlos**

  * LinkedIn: www.linkedin.com/in/joelcarlosassuncaopadilha
  * GitHub: https://github.com/joelcarlosap321-png

-----

*Este projeto foi criado para aprimorar conhecimentos em algoritmos e estruturas de dados.*
