                                                          📚 EWU Library Management System
🎯 Project Overview
A comprehensive console-based Library Management System developed in C that allows users to efficiently manage book inventory with secure login authentication and multiple book management functionalities.

Features:
🔐 Authentication System
Secure login with username and password verification.

Maximum 3 login attempts for security.

Access denial protection.

📖 Book Management
Add New Books: Store book details including name, author, price, and issue date.

Search Functionality:

Search by Book Name.

Search by Author Name.

Budget-friendly search (within ±50 of specified budget).

View All Books: Display complete inventory with detailed information.

Delete Operations:

Delete last added book.

Delete any book by index.

🛠️ Technical Implementation
Data Structure
c
struct book {
    char name[100];
    char author[100];
    float price;
    char issue_date[20];
};
Key Functions
Authentication: login() - Handles user verification

CRUD Operations:

add_book() - Create new book entries

search_by_name() / search_by_author() - Read/retrieve books

delete_last_book() / delete_any_book() - Delete operations

Display Functions: show_all_books() - View complete inventory

Utility Functions: budget_friendly() - Find books within budget range

Default Login Credentials
Username: cse
Password: 103

📋 Menu Options
Option	Function	        Description
1	Add New Book	        Add a new book to inventory
2	Search by Name	        Find books by title
3	Search by Author	    Find books by author name
4	Show All Books	        Display complete inventory
5	Delete Last Book	    Remove most recently added book
6	Budget-Friendly Search	Find books within ±50 of budget
7	Delete Any Book	Remove  specific book by index
8	Exit	                Terminate program


📊 Data Persistence
Current Implementation: In-memory array storage (200 book capacity)

Data Loss: Information is not saved between sessions (volatile memory)

⚡ Performance Optimizations
Linear search algorithms for small datasets

Direct array manipulation for deletions

Minimal memory footprint

🐛 Known Issues & Limitations
Memory Storage: Data is not saved to disk

Input Methods: Uses deprecated gets() function

Platform Dependency: system("cls") is Windows-specific

Maximum Capacity: Limited to 200 books

No Sorting: Books are displayed in insertion order


👥 Team & Contribution
Group 07 - CSE103 Mini Project

Developed as part of EWU CSE curriculum

Collaborative project focusing on practical C programming

📝 License
Educational Project - EWU CSE Department

🤝 Contributing
This is a student project. For educational purposes only.

🎓 Learning Outcomes
C Programming: Structures, arrays, pointers, functions

System Design: Menu-driven application architecture

Problem Solving: CRUD operations implementation

Error Handling: Input validation and edge cases
