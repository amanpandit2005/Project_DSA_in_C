# Project DSA in C — Parcel Delivery System 📦

An algorithmic logistics application written in C to simulate a real-time **Parcel Delivery System**. This project uses data structures and optimization principles to schedule, allocate, and route deliveries.

---

## 🛠️ Key Features

*   **Parcel Sorting**: Organizes parcels dynamically based on priority, destination, and dimensions.
*   **Optimized Routing**: Simulates route plotting to minimize transit costs and delivery time.
*   **Low-Level Memory Management**: Implemented entirely in standard C, using custom pointers, arrays, and structs to ensure high-performance executions.

---

## 📂 Data Structures Implemented

*   **Structs**: Custom structures modeling Parcels (ID, weight, address) and Delivery Vans.
*   **Arrays/Lists**: Storing current inventories and routing stops.
*   **Queueing Systems**: Scheduling parcel priority queues (FIFO/Priority-based).

---

## 🚀 How to Run Locally

### Requirements
You will need a C compiler (`gcc` or similar toolchains) installed.

### Compile
Run this command in your terminal:
```bash
gcc main.c -o parcel_system
