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

### windows command 

'''bash
gcc smart_home_management.c
./a.exe
'''

### linux command 

'''bash
gcc smart_home_management.c
./a.out
'''

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

## Output Screenshots

Display Menu

<img width="203" height="181" alt="image" src="https://github.com/user-attachments/assets/bb63b1e2-674e-4f97-8515-a49998d2908e" />

Inputting the data

<img width="233" height="269" alt="image" src="https://github.com/user-attachments/assets/4e41fb9a-a9de-491d-a5ec-5973d609d931" />

Display

<img width="383" height="308" alt="image" src="https://github.com/user-attachments/assets/2ec7764d-b16c-4ce6-99b9-418fa3502177" />

Searching for required data

<img width="305" height="208" alt="image" src="https://github.com/user-attachments/assets/a3e33374-fd98-4471-a6e8-bc01ee0f232f" />

Updating

<img width="252" height="261" alt="image" src="https://github.com/user-attachments/assets/7544ce5e-2095-47de-80e2-94b3b48a5042" />

After Updating

<img width="360" height="284" alt="image" src="https://github.com/user-attachments/assets/5aa262ae-d651-4313-9edc-8770dfc96623" />

Delete

<img width="207" height="184" alt="image" src="https://github.com/user-attachments/assets/00bb6a00-0b45-447d-b139-b6e1279d0a84" />

After Deleting

<img width="345" height="264" alt="image" src="https://github.com/user-attachments/assets/52c19b0d-0f5b-4881-8355-55dc0fcfba6c" />

Smart System(User at Home)

<img width="268" height="302" alt="image" src="https://github.com/user-attachments/assets/6355a140-952d-4fc3-8f12-b33e4833032e" />

Display after changes

<img width="356" height="280" alt="image" src="https://github.com/user-attachments/assets/5e03b542-ea46-4fb1-81ac-15c77178fcbb" />

User Not At Home

<img width="264" height="301" alt="image" src="https://github.com/user-attachments/assets/1d8bebe1-f482-48dd-ac3e-c0737e1332ca" />

Display

<img width="452" height="276" alt="image" src="https://github.com/user-attachments/assets/8439ce4f-3b15-4998-a88b-9fa1ce7494a9" />

Exiting from the menu

<img width="189" height="200" alt="image" src="https://github.com/user-attachments/assets/e13145cc-35f9-4ba8-8d52-412a0f1bfb98" />

##  Demo Video



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
