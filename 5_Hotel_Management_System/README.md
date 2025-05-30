# 🏨 Hotel Management System (C Language)

A simple **console-based Hotel Management System** written in C that uses **file handling** to manage room bookings, check-ins, check-outs, and billing operations. This project is ideal for beginners learning file operations in C.

---

## 📌 Features

- ✅ Book Room (Add new customer)
- ✅ View All Customers (Read from file)
- ✅ Check-Out Customer (Remove from file and generate bill)
- ✅ Store data in `records.txt` using file handling
- ✅ Simple command-line menu interface

---

## 💻 How It Works

### 1. Book Room
- Takes customer name, room number, days of stay, and daily rate.
- Appends the data to `records.txt`.

### 2. View Customers
- Reads and displays all customer data from `records.txt`.

### 3. Check-Out
- Removes a customer’s record from the file based on room number.
- Calculates and displays the bill = `days * rate`.
- Creates a temporary file to rewrite all records excluding the checked-out customer.

---

## 🛠️ File Structure
hotel_management/
│
├── hotel.c # Main C source file
├── records.txt # File where customer data is stored (auto-created)
└── README.md # This file

---

## 🚀 How to Run

### 💡 Requirements
- GCC compiler (Linux/Windows with MinGW or CodeBlocks)

### ⏯️ Steps to Compile and Run

#### Linux/Mac:
```bash
gcc hotel.c -o hotel
./hotel


====== Hotel Management System ======
1. Book Room
2. View All Customers
3. Check-Out Customer
4. Exit
Enter your choice: 1
Enter Customer Name: Alice
Enter Room Number: 101
Enter Number of Days: 3
Enter Room Rate per Day: 1500
Room Booked Successfully!
