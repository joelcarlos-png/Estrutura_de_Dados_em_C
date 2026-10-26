Versão em português aqui: [LINK](./README_pt-BR.md)

# Data Structures in C 🚀

This repository contains robust implementations of fundamental and advanced data structures developed for study and practice in C. The project explores the differences between **Static (array-based)** and **Dynamic (pointer-based)** allocation across **Stacks**, **Queues**, **Lists**, and **Trees**, featuring balanced search trees, prefix trees, modular ADT libraries, and academic exercise sets.

---

## 📋 Contents

The project is structured into comprehensive modules covering theoretical concepts and practical applications:

### 1. Stacks (LIFO - Last In, First Out)
* **Static Stack (`Pilhas/Pilha_Estatica`):** Array-based stack with predefined capacity, featuring push/pop operations and overflow protection (`atv1.c` - `atv3.c`).
* **Linked Stack (`Pilhas/Pilha_Encadeada`):** Dynamic stack allocating nodes on the heap as elements arrive.
* **Practical Application - Postfix Calculator:** Reverse Polish Notation (RPN) calculator implementing a linked stack to evaluate arithmetic expressions (`Calculadora.c`).

### 2. Queues (FIFO - First In, First Out)
* **Static Queue (`Filas/Fila_Estatica`):** Array-based queue utilizing circular buffer indexing (`atv3.c` - `atv12.c`) to optimize memory reuse.
* **Linked Queue (`Filas/Fila_Encadeada`):** Dynamic queue with front and rear pointers, supporting enqueue, dequeue, queue reversal, and string character processing (`JoelCarlos.c`).

### 3. Lists
* **Static List (`Listas/Lista_Estatica`):** Sequential array-based list with arbitrary index insertion and removal.
* **Singly Linked List (`Listas/Lista_Encadeada`):** Dynamic linear collection linked through forward pointers (`JoelCarlos-ListaEnc.Simples.c`).
* **Doubly Linked List (`Listas/Lista_Encadeada`):** Bidirectional linked list with previous and next references, supporting multiple lists and advanced operations (`JoelCarlos-ListaEnc.Dupla.c`).
* **Circular Linked Lists (`Listas/Lista_Encadeda_Circular`):** Closed-loop lists where the last element points back to the head node:
  * *Singly Circular Linked List:* Single directional circular iteration (`JoelCarlos-Enc.Circular.c`).
  * *Doubly Circular Linked List:* Bidirectional circular traversal and indexing (`JoelCarlos-Dupla_Enc.Circular.c`).

### 4. Trees
* **Binary Search Tree - BST (`Arvores/Arvores_Binarias`):** Ordered binary tree supporting node insertion, search, deletion, minimum/maximum lookup, node counting, and recursive/iterative traversals (pre-order, in-order, post-order).
* **AVL Tree (`Arvores/Arvores_AVL`):** Self-balancing binary search tree maintaining balance factor $|h_L - h_R| \le 1$ using rotations (LL, RR, LR, RL) with an interactive driver (`JoelCarlos.c`).
* **Red-Black Tree (`Arvores/Arvore_RubroNegra`):** Self-balancing BST using node coloring (Red/Black) and restructuring to guarantee $O(\log n)$ worst-case time complexity (`JoelCarlos.c`).
* **Trie Tree / Prefix Tree (`Arvores/Arvore_TRIE`):** Multi-way search tree specialized for string storage, dictionary lookups, prefix searches, and word removal (`JoelCarlos.c`).

### 5. Reusable ADT Library (`includes/`)
A modular set of C headers and source files designed as reusable Abstract Data Types (ADT):
* **Trees:** `arvoresBi`, `arvoreavl`, `arvorerb`, `arvoretrie`, and `arvoreparci`.
* **Stacks:** Typed stacks for integer (`pilha`), character (`pilhaChar`), and floating-point (`pilhaFloat`).
* **Queues:** Typed queues for integer (`filaint`), character (`filachar`), and floating-point (`filareal`).
* **Lists:** Typed lists for characters (`listachar`, `listacharE`, `listacharEDupla`), doubly linked (`ListaDupla`), and circular lists (`ListaECircularSimples`, `ListaECircularDupla`).
* **Review & Prep:** Review implementations (`revisaoBST`, `revisaoLD`, `revisaoLS`).
* **Terminal Utilities:** ANSI color codes (`cores.h`) and validated console input helpers (`controle.h`/`controle.c`).

### 6. Academic Worksheets (PDFs)
Each topic folder contains original academic assignment sheets (`.pdf`) detailing problem statements and constraints.

---

## 💻 Applied Technologies and Concepts

* **Language:** C (C99 / C11).
* **Memory Management:** Dynamic allocation with `malloc()` and `free()`, pointer arithmetic, and heap leak avoidance.
* **Modularity:** Clean separation between interface definitions (`.h`), implementations (`.c`), and execution drivers.
* **Abstract Data Types (ADT):** Strict encapsulation of data structures to prevent improper memory mutation.
* **Algorithmic Balancing:** Tree rotations, color flips, prefix indexing, and circular array pointer arithmetic.
* **Console UI/UX:** Terminal text coloring via ANSI escape sequences and robust input validation.

---

## 📂 Folder Structure

```text
.
├── Arvores/
│   ├── Arvores_Binarias/             # Binary Search Tree (BST) implementations & exercises
│   │   ├── Exercicio 1/              # BST traversals (recursive/iterative), min/max, size
│   │   ├── Exercicio2/               # Interactive BST operations menu
│   │   └── Lista Revisao/            # Review exercise statements and exercises
│   ├── Arvores_AVL/                  # Self-balancing AVL Tree (rotations, balance factor)
│   ├── Arvore_RubroNegra/            # Self-balancing Red-Black Tree (coloring properties)
│   └── Arvore_TRIE/                  # Trie (Prefix Tree) for dictionary and string storage
├── Filas/
│   ├── Fila_Estatica/                # Static circular queue exercises (atv3 - atv12)
│   └── Fila_Encadeada/               # Dynamic linked queue with interactive driver
├── Listas/
│   ├── Lista_Estatica/               # Static array-based list
│   ├── Lista_Encadeada/              # Singly & Doubly dynamic linked lists
│   └── Lista_Encadeda_Circular/      # Singly & Doubly circular linked lists
├── Pilhas/
│   ├── Pilha_Estatica/               # Static stack exercises (atv1 - atv3)
│   └── Pilha_Encadeada/              # Dynamic linked stack & RPN Postfix Calculator
├── includes/                         # Shared modular ADT library (.h / .c)
│   ├── arvoreavl.{h,c}               # AVL Tree module
│   ├── arvorerb.{h,c}                # Red-Black Tree module
│   ├── arvoresBi.{h,c}               # Binary Tree module
│   ├── arvoretrie.{h,c}              # Trie Tree module
│   ├── arvoreparci.{h,c}             # Partial tree operations module
│   ├── filachar.{h,c} / filaint.{h,c} / filareal.{h,c} # Queues (char, int, float)
│   ├── listachar.{h,c} / listacharE.{h,c} / listacharEDupla.{h,c} # Lists (char)
│   ├── ListaDupla.{h,c}              # Doubly linked list module
│   ├── ListaECircularSimples.{h,c}   # Singly circular list module
│   ├── ListaECircularDupla.{h,c}     # Doubly circular list module
│   ├── pilha.{h,c} / pilhaChar.{h,c} / pilhaFloat.{h,c} # Stacks (int, char, float)
│   ├── revisaoBST.{h,c} / revisaoLD.{h,c} / revisaoLS.{h,c} # Review modules
│   ├── controle.{h,c}                # Safe terminal input utilities
│   └── cores.h                       # ANSI terminal color formatting
├── LICENSE                           # MIT License
├── README.md                         # Documentation (English)
└── README_pt-BR.md                   # Documentation (Português)
```

---

## 🚀 How to Run the Project

### Prerequisites
* GCC compiler installed (`gcc --version`).
* Terminal or command line interface (Git Bash, PowerShell, or Linux/macOS shell).

### 1. Clone the repository
```bash
git clone https://github.com/joelcarlos-png/Estrutura_de_Dados_em_C.git
cd Estrutura_de_Dados_em_C
```

### 2. Compilation Examples

Programs that depend on the `includes/` library can be compiled by referencing their respective module `.c` files and setting `-I includes`.

#### Example A: Trie Tree (Prefix Tree)
```bash
gcc Arvores/Arvore_TRIE/JoelCarlos.c includes/arvoretrie.c includes/controle.c -I includes -o arvore_trie
```

#### Example B: AVL Tree
```bash
gcc Arvores/Arvores_AVL/JoelCarlos.c includes/arvoreavl.c includes/controle.c -I includes -o arvore_avl
```

#### Example C: Red-Black Tree
```bash
gcc Arvores/Arvore_RubroNegra/JoelCarlos.c includes/arvorerb.c includes/controle.c -I includes -o arvore_rb
```

#### Example D: Doubly Linked List
```bash
gcc Listas/Lista_Encadeada/JoelCarlos-ListaEnc.Dupla.c includes/ListaDupla.c includes/controle.c -I includes -o lista_dupla
```

#### Example E: Postfix Expression Calculator (Linked Stack)
```bash
gcc Pilhas/Pilha_Encadeada/Calculadora.c -o calculadora
```

### 3. Run the generated binary

* **On Linux / macOS:**
  ```bash
  ./arvore_trie
  ```
* **On Windows:**
  ```powershell
  .\arvore_trie.exe
  ```

---

## 📊 Quick Comparison

| Feature | Static Allocation | Dynamic (Linked) Allocation |
| :--- | :--- | :--- |
| **Memory Allocation** | Contiguous block in stack or static memory | Dispersed nodes on the heap via pointers |
| **Size / Capacity** | Fixed at compile time or initialization | Dynamic, grows and shrinks at runtime |
| **Memory Overhead** | Pre-allocates full capacity regardless of usage | Extra memory per node for pointer references |
| **Element Access** | Direct access via index in $O(1)$ | Sequential traversal in $O(n)$ |
| **Insertion / Deletion** | Requires shifting elements in $O(n)$ (except at end) | Fast pointer reconfiguration in $O(1)$ (with node reference) |
| **Cache Locality** | High (contiguous sequential memory) | Low (nodes scattered across heap) |

---

## ✍️ Author

Developed by **Joel Carlos**

* **LinkedIn:** [Joel Carlos Assunção Padilha](https://www.linkedin.com/in/joelcarlosassuncaopadilha)
* **GitHub:** [@joelcarlos-png](https://github.com/joelcarlos-png)

---

## 📝 License

This project is licensed under the [MIT License](LICENSE).
