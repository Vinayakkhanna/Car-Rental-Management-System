
# 🚗 Car Rental Management System (C++)


---

## 📝 Project Overview

The **Car Rental Management System** is a **C++ console-based project** designed to automate the process of renting and managing cars. It allows users to **view available cars, register customers, rent or return vehicles, and check rental history** through an easy-to-use, menu-driven interface.

This project demonstrates the application of **Object-Oriented Programming (OOP)** principles — including **classes**, **encapsulation**, and **abstraction** — while efficiently managing data using **vectors (STL)**.

---

## 🚀 Features

* **🧾 View Available Cars:** List all cars with ID, brand, model, price, and availability status.
* **👤 Customer Registration:** Register new customers with name and phone number.
* **🚘 Rent a Car:** Rent any available car for a specific number of days with automatic cost calculation.
* **🔁 Return a Car:** Return cars and mark them as available again.
* **📜 Rental History:** View complete rental records with customer and vehicle details.
* **🖥️ Interactive Menu:** Simple console interface for smooth user interaction.

---

## ⚙️ Concepts Used

* **Classes and Objects** – to model cars, customers, and rental system.
* **Encapsulation** – to protect internal data from direct modification.
* **Abstraction** – to hide complex operations behind simple functions.
* **Vectors (STL)** – for dynamic data storage and management.
* **Structs** – for efficient handling of rental history records.
* **Loops and Conditional Logic** – for program flow and menu control.

---

## 💡 How It Works

1. The system starts with a predefined list of available cars.
2. The user can register as a **new customer** or log in using an existing Customer ID.
3. The customer selects a car by ID and specifies the number of rental days.
4. The system calculates the total rental cost and marks the car as **Rented**.
5. Returned cars are marked **Available** again.
6. Every transaction is logged in the **rental history**.

### 🧾 Example Output

```
1. Toyota Innova Crysta - Rs.3000/day - Available  
2. BMW X5 - Rs.10000/day - Rented  
3. Range Rover Velar - Rs.11000/day - Available
```

---

## 🧩 Class Structure

| Class / Struct             | Description                                                                                  |
| -------------------------- | -------------------------------------------------------------------------------------------- |
| **Car**                    | Manages car details (ID, brand, model, price, availability) and handles rent/return actions. |
| **Customer**               | Stores customer details such as ID, name, and phone number.                                  |
| **CarRentalSystem**        | Main controller class handling cars, customers, rentals, returns, and history.               |
| **RentalHistory (struct)** | Keeps records of each rental — customer info, car name, days, and total cost.                |

---

## 🧠 Learning Outcomes

* Apply **OOP principles** in a real-world project.
* Manage **data dynamically** using vectors and structs.
* Build **interactive console programs** with menus and loops.
* Design **modular, reusable code** using multiple classes.
* Strengthen C++ fundamentals with practical implementation.

---

## 🛠️ Technologies Used

* **Language:** C++
* **Compiler:** GCC / MinGW
* **IDE:** Code::Blocks / Dev-C++ / Visual Studio Code
* **Libraries:**

  * `<iostream>` – Input/Output operations
  * `<vector>` – Dynamic data storage
  * `<string>` – String manipulation

---

## 📚 Future Enhancements

* Implement **file handling** to store and retrieve data persistently.
* Add **admin and customer login authentication**.
* Include **search and filter** features for cars.
* Generate **invoices or rental receipts** automatically.
* Create a **graphical user interface (GUI)** using Qt or SFML.
* Integrate a **database (MySQL/SQLite)** for scalable storage.

---

## 🏁 Conclusion

The **Car Rental Management System** is a beginner-friendly yet practical C++ project that demonstrates the real-world use of **Object-Oriented Programming**. It provides a clear understanding of modular design, data organization, and system interaction — making it an ideal project for students and developers looking to enhance their C++ skills and build management-based applications.

---

⭐ **If you found this project helpful, don’t forget to give it a star on GitHub!** ⭐

---


