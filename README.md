#  Smart Home Management using Device Control Tree (CRUD in C)

##  Project Overview
This project implements a Smart Home Management System using the C programming language. It utilizes a Binary Search Tree (BST) to efficiently manage and control smart devices like AC, Fan, Light, TV, and more.

In addition to basic CRUD operations, the system includes smart automation features that automatically control devices based on environmental conditions such as temperature, time (day/night), and user presence.

---

##  Problem Statement
Managing multiple smart home devices manually can be inefficient, time-consuming, and lead to unnecessary power consumption.

This project provides a structured and intelligent system to:
- Organize devices efficiently  
- Automate device control  
- Reduce electricity usage  

---

##  Team Members
- Suhaas Sarabu  
- Vishnu Polamera  

---

##  Data Structure Used
###  Binary Search Tree (BST)
- Left subtree → Devices with smaller IDs  
- Right subtree → Devices with larger IDs  
- Provides efficient operations (average O(log n))

---

##  Features

###  CRUD Operations
- Create – Add a new device  
- Read – Display all devices in sorted order  
- Update – Modify device details with validation  
- Delete – Remove a device  
- Search – Find a device by ID  

---

###  Smart Automation
- Automatically controls AC based on temperature  
- Controls fan based on room temperature  
- Turns lights ON/OFF based on day/night  
- Turns all devices OFF when user is not at home  
- Adjusts room temperature dynamically  
- Calculates total power usage  

---

###  Intelligent Power Management
- Automatic power assignment for devices  
- Real-time total power calculation  
- Helps simulate electricity optimization  

---

###  Input Handling & Validation
- Converts input to uppercase (case-insensitive)  
- Validates status (only ON/OFF allowed)  
- Safe update using backup to prevent invalid data  

---

##  Algorithm Explanation
- Devices are stored as nodes in a Binary Search Tree  
- Insertion follows BST rules based on device ID  
- Inorder traversal displays devices in sorted order  
- Search, update, and delete use recursive traversal  
- Smart automation traverses all devices and updates their state automatically  

---

##  Technologies Used
- C Programming Language  
- Structures (struct)  
- Pointers  
- Dynamic Memory Allocation (malloc, free)  
- Recursion  

---

##  Compilation & Execution

```bash
gcc main.c -o project
./project
```

## Sample Output

==== SMART HOME MENU ====

1.Add
2.Delete
3.Update
4.Search
5.Display
6.Smart System
7.Exit

Smart System Activated...
Power Usage: 35 units
Temp: 28°C | Night | User: Home
All devices adjusted automatically!

##Demo Video

 Upload your demo video to Google Drive and paste the link below:
[Add your Google Drive link here]

 Note: Keep access set to private or restricted as per instructions.

## Conclusion

This project demonstrates how Binary Search Trees can be effectively used to manage smart home devices in an organized and efficient way.

By integrating automation logic with data structures, the system not only performs CRUD operations but also simulates real-world intelligent behavior such as automatic temperature control, power management, and device optimization.

Overall, the project showcases both strong programming fundamentals and practical application of data structures.

## Future Enhancements

GUI-based interface for better user interaction
Mobile application integration
Real-time IoT device connectivity
AI-based voice control system
Sensor-based automatic environment detection
Cloud-based remote monitoring system
