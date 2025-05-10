# Event Management System

This is a simple Event Management System developed using C++ to manage campus events, participants, and event categories. The system is structured using data structures such as linked lists, queues, and binary search trees. The following functionalities are implemented:

## Features

### 1. Manage Completed Events (Linked List)
- **Insert Event**: Allows adding a new event with the name, date, and location.
- **Display Events**: Displays a list of all completed events.
- **Delete Event**: Removes a specific event by its name.

### 2. Register Participants (Queue)
- **Register Participant**: Registers a participant by adding their name to the queue.
- **Display Participants**: Displays the list of all participants in the queue.
- **Remove Participant**: Removes a participant from the queue.

### 3. Manage Event Categories (Binary Search Tree)
- **Add Event to Category**: Inserts an event under a specified category in a binary search tree.
- **Display Events by Category**: Displays events sorted by their category using in-order traversal.

### 4. Exit
- The user can exit the program.

## Requirements

- C++ compiler (e.g., GCC, Clang)
- Basic knowledge of data structures (Linked List, Queue, Tree)

## Compilation and Execution

1. Compile the source code using a C++ compiler:
   ```bash
   g++ -o event_management event_management.cpp
2. Run the program:
   ```bash
   ./event_management
