English version here: [LINK](./README.md)

# Estruturas de Dados em C 🚀

Este repositório contém implementações robustas de estruturas de dados fundamentais e avançadas, desenvolvidas para fins de estudo e prática aprofundada na linguagem C. O projeto explora as diferenças entre alocação **Estática (baseada em vetores)** e **Dinâmica (baseada em ponteiros)** abordando **Pilhas**, **Filas**, **Listas** e **Árvores**, além de árvores autobalanceadas, árvores de prefixo, uma biblioteca modular de TADs e listas de exercícios acadêmicos.

---

## 📋 Conteúdo

O projeto é estruturado em módulos abrangentes que englobam desde a fundamentação teórica até aplicações práticas:

### 1. Pilhas (Stacks) - Conceito LIFO (Last In, First Out)
* **Pilha Estática (`Pilhas/Pilha_Estatica`):** Implementação baseada em vetores de tamanho fixo, com operações de push/pop e verificação de limites (`atv1.c` a `atv3.c`).
* **Pilha Encadeada (`Pilhas/Pilha_Encadeada`):** Implementação dinâmica utilizando alocação em heap via ponteiros sob demanda.
* **Aplicação Prática - Calculadora Pós-fixa:** Calculadora de Notação Polonesa Reversa (RPN) implementada com pilha encadeada para avaliação de expressões aritméticas (`Calculadora.c`).

### 2. Filas (Queues) - Conceito FIFO (First In, First Out)
* **Fila Estática (`Filas/Fila_Estatica`):** Implementação com vetores circulares (`atv3.c` a `atv12.c`) para reaproveitamento otimizado do espaço de memória.
* **Fila Encadeada (`Filas/Fila_Encadeada`):** Fila dinâmica com ponteiros para início e fim, incluindo operações de inversão de fila e conversão de strings em caracteres enfileirados (`JoelCarlos.c`).

### 3. Listas (Lists)
* **Lista Estática (`Listas/Lista_Estatica`):** Lista sequencial baseada em vetor com operações por índice arbitrário.
* **Lista Simplesmente Encadeada (`Listas/Lista_Encadeada`):** Coleção dinâmica linear encadeada com ponteiro simples para o próximo nó (`JoelCarlos-ListaEnc.Simples.c`).
* **Lista Duplamente Encadeada (`Listas/Lista_Encadeada`):** Lista bidirecional com ponteiros anterior e próximo, suportando gerenciamento de múltiplas listas e operações avançadas (`JoelCarlos-ListaEnc.Dupla.c`).
* **Listas Encadeadas Circulares (`Listas/Lista_Encadeda_Circular`):** Estruturas em anel onde o último elemento aponta de volta para o início:
  * *Circular Simples:* Iteração circular unidirecional (`JoelCarlos-Enc.Circular.c`).
  * *Circular Dupla:* Navegação circular bidirecional (`JoelCarlos-Dupla_Enc.Circular.c`).

### 4. Árvores (Trees)
* **Árvore Binária de Busca - BST (`Arvores/Arvores_Binarias`):** Árvores binárias ordenadas com suporte a inserção, busca, remoção de chaves, verificação de mínimo/máximo, contagem de nós e percursos recursivos e iterativos (pré-ordem, em-ordem e pós-ordem).
* **Árvore AVL (`Arvores/Arvores_AVL`):** Árvore binária de busca autobalanceada baseada no fator de balanceamento $|h_E - h_D| \le 1$, implementando rotações (LL, RR, LR, RL) com menu interativo (`JoelCarlos.c`).
* **Árvore Rubro-Negra (`Arvores/Arvore_RubroNegra`):** Árvore binária autobalanceada utilizando propriedades e regras de coloração (nós vermelhos e pretos) garantindo complexidade $O(\log n)$ no pior caso (`JoelCarlos.c`).
* **Árvore TRIE / Árvore de Prefixos (`Arvores/Arvore_TRIE`):** Estrutura de busca em árvore digital multi-caminho otimizada para armazenamento de cadeias de caracteres, busca por prefixo, autocompletar e remoção de palavras (`JoelCarlos.c`).

### 5. Biblioteca Modular de TADs (`includes/`)
Conjunto modular de headers (`.h`) e implementações (`.c`) encapsulando Tipos Abstratos de Dados reutilizáveis:
* **Árvores:** Módulos para BST (`arvoresBi`), AVL (`arvoreavl`), Rubro-Negra (`arvorerb`), TRIE (`arvoretrie`) e operações parciais (`arvoreparci`).
* **Pilhas:** Pilhas tipadas para inteiros (`pilha`), caracteres (`pilhaChar`) e números de ponto flutuante (`pilhaFloat`).
* **Filas:** Filas tipadas para inteiros (`filaint`), caracteres (`filachar`) e reais (`filareal`).
* **Listas:** Listas de caracteres estática e encadeadas (`listachar`, `listacharE`, `listacharEDupla`), lista duplamente encadeada genérica (`ListaDupla`), e circulares (`ListaECircularSimples`, `ListaECircularDupla`).
* **Revisão e Preparação:** Módulos dedicados para fixação e exercícios (`revisaoBST`, `revisaoLD`, `revisaoLS`).
* **Utilitários:** Constantes de cores ANSI para terminal (`cores.h`) e leitor com validação de dados de entrada (`controle.h`/`controle.c`).

### 6. Listas de Exercícios Acadêmicos (PDFs)
Cada diretório de tópicos contém as listas de exercícios originais em PDF com os enunciados e restrições propostas.

---

## 💻 Tecnologias e Conceitos Aplicados

* **Linguagem:** C (padrões C99 / C11).
* **Gestão de Memória:** Alocação dinâmica com `malloc()` e liberação com `free()`, controle de vazamento de memória (memory leaks) e manipulação precisa de ponteiros.
* **Modularização:** Separação entre interface/especificação (`.h`), implementação dos métodos (`.c`) e programas executáveis.
* **Tipos Abstratos de Dados (TAD):** Encapsulamento das estruturas internas para proteção de acesso direto à memória.
* **Algoritmos de Balanceamento e Busca:** Rotações AVL, balanceamento por cores em Rubro-Negra, percursos em árvore e indexação por prefixos (Trie).
* **Interface e Experiência em Terminal:** Formatação com cores ANSI e rotinas de leitura sanitizada do `stdin`.

---

## 📂 Estrutura de Pastas

```text
.
├── Arvores/
│   ├── Arvores_Binarias/             # Implementações de Árvores Binárias de Busca (BST) e exercícios
│   │   ├── Exercicio 1/              # Percursos em BST (recursivo/iterativo), menor/maior, contagem
│   │   ├── Exercicio2/               # Menu interativo de operações em BST
│   │   └── Lista Revisao/            # Enunciados e desafios de revisão
│   ├── Arvores_AVL/                  # Árvore AVL autobalanceada (rotações e fator de balanceamento)
│   ├── Arvore_RubroNegra/            # Árvore Rubro-Negra autobalanceada (propriedades de cores)
│   └── Arvore_TRIE/                  # Árvore TRIE (árvore de prefixos para dicionário e strings)
├── Filas/
│   ├── Fila_Estatica/                # Exercícios de fila estática circular (atv3 a atv12)
│   └── Fila_Encadeada/               # Fila encadeada dinâmica com menu interativo
├── Listas/
│   ├── Lista_Estatica/               # Lista sequencial com vetor
│   ├── Lista_Encadeada/              # Listas simplesmente e duplamente encadeadas
│   └── Lista_Encadeda_Circular/      # Listas encadeadas circulares (simples e dupla)
├── Pilhas/
│   ├── Pilha_Estatica/               # Exercícios de pilha estática (atv1 a atv3)
│   └── Pilha_Encadeada/              # Pilha dinâmica encadeada e Calculadora Pós-fixa
├── includes/                         # Biblioteca modular compartilhada de TADs (.h / .c)
│   ├── arvoreavl.{h,c}               # Módulo de Árvore AVL
│   ├── arvorerb.{h,c}                # Módulo de Árvore Rubro-Negra
│   ├── arvoresBi.{h,c}               # Módulo de Árvore Binária
│   ├── arvoretrie.{h,c}              # Módulo de Árvore TRIE
│   ├── arvoreparci.{h,c}             # Módulo de operações parciais em árvores
│   ├── filachar.{h,c} / filaint.{h,c} / filareal.{h,c} # Filas (char, int, float)
│   ├── listachar.{h,c} / listacharE.{h,c} / listacharEDupla.{h,c} # Listas (char)
│   ├── ListaDupla.{h,c}              # Módulo de Lista Duplamente Encadeada
│   ├── ListaECircularSimples.{h,c}   # Módulo de Lista Circular Simples
│   ├── ListaECircularDupla.{h,c}     # Módulo de Lista Circular Dupla
│   ├── pilha.{h,c} / pilhaChar.{h,c} / pilhaFloat.{h,c} # Pilhas (int, char, float)
│   ├── revisaoBST.{h,c} / revisaoLD.{h,c} / revisaoLS.{h,c} # Módulos de revisão
│   ├── controle.{h,c}                # Utilitários para entrada segura no terminal
│   └── cores.h                       # Constantes de cores ANSI para o console
├── LICENSE                           # Licença MIT
├── README.md                         # Documentação em Inglês
└── README_pt-BR.md                   # Documentação em Português
```

---

## 🚀 Como Executar o Projeto

### Pré-requisitos
* Compilador GCC instalado (`gcc --version`).
* Terminal ou linha de comando (Git Bash, PowerShell ou terminal Linux/macOS).

### 1. Clonar o repositório
```bash
git clone https://github.com/joelcarlos-png/Estrutura_de_Dados_em_C.git
cd Estrutura_de_Dados_em_C
```

### 2. Exemplos de Compilação

Para compilar programas que utilizam a biblioteca `includes/`, passe os respectivos arquivos `.c` dos módulos e inclua a flag `-I includes`.

#### Exemplo A: Árvore TRIE (Prefix Tree)
```bash
gcc Arvores/Arvore_TRIE/JoelCarlos.c includes/arvoretrie.c includes/controle.c -I includes -o arvore_trie
```

#### Exemplo B: Árvore AVL
```bash
gcc Arvores/Arvores_AVL/JoelCarlos.c includes/arvoreavl.c includes/controle.c -I includes -o arvore_avl
```

#### Exemplo C: Árvore Rubro-Negra
```bash
gcc Arvores/Arvore_RubroNegra/JoelCarlos.c includes/arvorerb.c includes/controle.c -I includes -o arvore_rb
```

#### Exemplo D: Lista Duplamente Encadeada
```bash
gcc Listas/Lista_Encadeada/JoelCarlos-ListaEnc.Dupla.c includes/ListaDupla.c includes/controle.c -I includes -o lista_dupla
```

#### Exemplo E: Calculadora de Expressão Pós-fixa (Pilha Encadeada)
```bash
gcc Pilhas/Pilha_Encadeada/Calculadora.c -o calculadora
```

### 3. Execução do binário gerado

* **No Linux / macOS:**
  ```bash
  ./arvore_trie
  ```
* **No Windows:**
  ```powershell
  .\arvore_trie.exe
  ```

---

## 📊 Comparativo Rápido

| Característica | Alocação Estática | Alocação Dinâmica (Encadeada) |
| :--- | :--- | :--- |
| **Alocação de Memória** | Bloco contíguo em pilha (stack) ou estático | Nós dispersos na heap via ponteiros |
| **Tamanho / Capacidade** | Fixo na compilação ou inicialização | Dinâmico, cresce e reduz em tempo de execução |
| **Uso de Memória** | Ocupa a capacidade total mesmo se pouco usada | Ocupa nós conforme necessidade, com overhead de ponteiros |
| **Acesso a Elementos** | Acesso direto via índice em tempo $O(1)$ | Acesso sequencial percorrendo nós em tempo $O(n)$ |
| **Inserção / Remoção** | Exige deslocamento de dados em $O(n)$ (salvo no fim) | Ajuste rápido de ponteiros em $O(1)$ (tendo a referência) |
| **Localidade de Cache** | Alta (memória linear sequencial contígua) | Baixa (nós alocados em posições dispersas na heap) |

---

## ✍️ Autor

Desenvolvido por **Joel Carlos**

* **LinkedIn:** [Joel Carlos Assunção Padilha](https://www.linkedin.com/in/joelcarlosassuncaopadilha)
* **GitHub:** [@joelcarlos-png](https://github.com/joelcarlos-png)

---

## 📝 Licença

Este projeto está licenciado sob a [Licença MIT](LICENSE).
