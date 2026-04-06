# 🏠 Smart Home Management using Device Control Tree (CRUD in C)

## 📌 Project Overview
This project implements a Smart Home Management System using the C programming language. It uses a Binary Search Tree (BST) to efficiently manage and control smart devices such as lights, fans, and air conditioners. Each device is represented as a node, allowing structured storage and fast operations.

---

## 🎯 Problem Statement
Managing multiple smart home devices manually can be inefficient and unorganized. This project provides a structured system to store, manage, and control devices efficiently using data structures.

---

## 👥 Team Members
- Suhaas Sarabu  
- [Add your teammate name]

---

## 🌳 Data Structure Used
- Binary Search Tree (BST)
  - Left subtree → smaller IDs  
  - Right subtree → larger IDs  

---

## ⚙️ Features (CRUD Operations)
- Create – Add a new device  
- Read – Display all devices (sorted order)  
- Update – Modify device details  
- Delete – Remove a device  
- Search – Find a device by ID  

---

## 🧠 Algorithm Explanation
- Devices are stored as nodes in a Binary Search Tree.
- Insertion follows BST rules based on device ID.
- Inorder traversal is used to display devices in sorted order.
- Searching, updating, and deletion are performed using recursive tree operations.

---

## 💻 Technologies Used
- C Programming Language  
- Dynamic Memory Allocation (malloc, free)  
- Structures (struct)  
- Pointers and Recursion  

---

## ▶️ Compilation & Execution

```bash
gcc main.c -o project
./project
