# 🏥 Hospital Management System (C++ Console Application)

A C++ console-based Hospital Management System that efficiently manages hospital operations using file-based data storage and a menu-driven interface. The system supports role-based access for admins and users, and covers all essential modules like patient records, appointments, prescriptions, billing, and more.

---

## 📌 Project Overview

This system is built to simulate a real hospital management environment, focusing on data persistence, role-based access control, and ease of use. It is fully modular, scalable, and works on both Windows and Linux systems using simple file operations for data handling.

---

## ✅ Features

### 🔐 Authentication System
- Secure login system with username/password
- Admin privileges for system management
- File-based credential handling

### 🧑‍⚕️ Patient Management
- Add, update, delete, and search patients
- Stores personal info, blood type, vital signs, and medical history

### 👨‍⚕️ Doctor Management
- Manage doctor records: add, update, delete, and search
- Store professional info, specialization, availability, and consultation fees

### 📅 Appointment System
- Schedule appointments between patients and doctors
- View and manage appointment slots

### 💊 Prescription Management
- Create and link prescriptions to patients
- Generate reports and document medicines

### 🧴 Medicine Inventory
- Add, edit, delete, and search medicines
- Track availability and pricing

### 🧪 Laboratory Management
- Manage lab tests with descriptions and pricing
- Search and update test records

### 💵 Billing System
- Calculate bills based on medicine, lab tests, hospital stay, and emergencies
- Generate detailed bills and store billing history

### 🛠 Administrative Features
- Add, remove, and update user credentials
- Control system-level access

---

## 🧰 Technical Features

- File-based data persistence (no external DB required)
- Modular, menu-driven architecture
- Input validation and error handling
- Cross-platform (tested on Windows & Linux)

---

## 🚀 Getting Started

### Prerequisites
- C++ Compiler (e.g., g++, MinGW, or MSVC)
- Terminal or Command Prompt

### Compile and Run
```bash
g++ main.cpp -o hospital
./hospital
