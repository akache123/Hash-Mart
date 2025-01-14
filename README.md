# **HashMart: A Customer Database System**

## **Overview**
HashMart is a C-based program designed to manage customer information using hash tables. This project demonstrates the use of hash tables, file I/O, dynamic memory management, and optional binary search trees for enhanced functionality. The application supports essential operations for managing customer data, including adding, looking up, deleting, and saving customer details. 

Additionally, it provides a robust design that handles memory cleanup and integrates best practices for modular C programming.

---

## **Features**
- **Add Customer**: Add or overwrite customer details using an email as the unique key.
- **Lookup Customer**: Retrieve customer information by email address.
- **Delete Customer**: Remove a customer from the database.
- **List Customers**: Display all customers in the hash table.
- **Save Database**: Persist all customer information to a `customers.tsv` file.
- **Load Database**: Read and parse the database file to populate the hash table.
- **Hard Mode (Optional)**: Synchronize the hash table with a binary search tree (BST) for ordered traversal and retrieval.
  - Includes a `list_ordered` command to display customers sorted by email.

---

## **Getting Started**

### **Prerequisites**
- A Linux environment with GCC installed.
- The `Valgrind` tool for memory leak checks.

Install Valgrind:
```bash
sudo apt install valgrind
```

---

### **Compilation**
1. Clone the repository and navigate to the `hw7` directory.
2. Use the provided `Makefile` to compile the program:
   ```bash
   make
   ```

This will generate the executable file `businessdb`.

---

### **Running the Program**
Run the program using:
```bash
./businessdb
```

Upon launch, the program will attempt to load `customers.tsv` into the hash table. If the file does not exist, it will create an empty database.

---

### **Commands**
- **`add`**: Add a customer to the database.
  - Prompts: Email, Name, Shoe Size, Favorite Food.
  - If the email exists, it updates the customer data.
- **`lookup`**: Retrieve and display customer information by email.
- **`delete`**: Remove a customer by email.
- **`list`**: Display all customers in the database.
- **`list_ordered`**: (Hard mode) Display all customers sorted by email.
- **`save`**: Write the current state of the database to `customers.tsv`.
- **`quit`**: Clean up memory and exit the program.

---

### **Database File Format**
The database is stored in a tab-separated file (`customers.tsv`) with the following format:
```
<email>\t<name>\t<shoe size>\t<favorite food>\n
```

Example:
```
sammy@ucsc.edu   Sammy The Slug   27   bananas
bimmy@ucsc.edu   bimmy   4   vegan jerky
```

---

## **Hard Mode: Binary Search Tree**
- Synchronize a binary search tree (BST) with the hash table to support ordered retrieval.
- Use the `list_ordered` command for in-order traversal of the BST.

---

## **Memory Management**
- All memory allocations are managed using `malloc`, `calloc`, or `realloc`.
- Memory cleanup is ensured using `free`.
- Verify memory management with Valgrind:
  ```bash
  valgrind --leak-check=full ./businessdb
  ```

---

## **Resources**
- **Textbooks**:
  - *The C Programming Language* by Kernighan & Ritchie (Chapters 6, 7, and 8).
- **Tools**:
  - Valgrind for memory leak checks.

---

## **Author**
Anurag Kache  
University of California, Santa Cruz

--- 
