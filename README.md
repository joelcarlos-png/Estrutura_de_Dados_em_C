# Data Structures in C 🚀

This repository contains implementations of fundamental data structures developed for study and practice in C. The project covers the concepts of **Queues** and **Stacks**, exploring the differences between **Static** and **Dynamic (Linked)** allocation.

---

## 📋 Contents

The project is structured into four main modules:

### 1. Stacks - LIFO Concept (Last In, First Out)
* **Static Stack:** Implementation using arrays with a pre-defined size.
* **Linked Stack:** Dynamic implementation using pointers, where the size increases as needed.

### 2. Queues - FIFO Concept (First In, First Out)
* **Static Queue:** Implementation with arrays, generally using circular queue logic for better space optimization.
* **Linked Queue:** Dynamic implementation with nodes pointing to the next element, allowing flexible growth.

---

## 💻 Applied Technologies and Concepts

* **Language:** C
* **Memory Management:** `malloc()`, `free()`, and pointer manipulation.
* **Modularity:** Separation between definition (`.h`), implementation (`.c`), and execution (`main.c`).
* **Abstract Data Types (ADT):** Encapsulation of structures to keep code organized and secure.

---

## 📂 Folder Structure

```text
.
├── Pilha_Estatica/      # Static Stack implementation
├── Pilha_Encadeada/     # Linked Stack implementation
├── Fila_Estatica/       # Static Queue implementation
├── Fila_Encadeada/      # Linked Queue implementation
├── includes/            # Libraries used in the folders above
└── README.md            # Project documentation
````

-----

## 🚀 How to Run the Project

To test any of the structures, follow the steps below:

1.  **Clone the repository:**

    ```bash
    git clone [https://github.com/YOUR_USERNAME/YOUR_REPOSITORY_NAME.git](https://github.com/YOUR_USERNAME/YOUR_REPOSITORY_NAME.git)
    ```

2.  **Navigate to the desired folder:**

    ```bash
    cd Pilha_Encadeada
    ```

3.  **Compile the source files:**

    ```bash
    gcc main.c linked_stack.c -o program
    ```

4.  **Run the generated binary:**

    ```bash
    ./program
    ```

-----

## 📊 Quick Comparison

| Feature | Static | Linked |
| :--- | :--- | :--- |
| **Allocation** | Contiguous Memory (Array) | Dispersed Memory (Pointers) |
| **Size** | Fixed (defined at compile time) | Dynamic (adjusts at runtime) |
| **Memory Usage** | Occupies total space from the start | Occupies only what is needed for each node |

-----

## ✍️ Author

Developed by Joel Carlos

  * LinkedIn: www.linkedin.com/in/joelcarlosassuncaopadilha
  * GitHub: https://github.com/joelcarlos-png

-----

*This project was created to consolidate knowledge in algorithms and data structures.*
