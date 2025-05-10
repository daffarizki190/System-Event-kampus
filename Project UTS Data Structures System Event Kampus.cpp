#include <iostream>
#include <string>
using namespace std;

struct EventNode {
    string eventName;
    string eventDate;
    string eventLocation;
    EventNode* next;
};

void insertEvent(EventNode*& head, const string& name, const string& date, const string& location) {
    EventNode* newNode = new EventNode{name, date, location, nullptr};
    newNode->next = head;
    head = newNode;
}

void displayEvents(EventNode* head) {
    if (!head) {
        cout << "No completed events.\n";
        return;
    }
    EventNode* temp = head;
    while (temp) {
        cout << "Event: " << temp->eventName << ", Date: " << temp->eventDate << ", Location: " << temp->eventLocation << endl;
        temp = temp->next;
    }
}

void deleteEvent(EventNode*& head, const string& name) {
    if (!head) return;

    EventNode* temp = head;
    if (head->eventName == name) {
        head = head->next;
        delete temp;
        cout << "Event '" << name << "' removed.\n";
        return;
    }

    while (temp->next && temp->next->eventName != name) {
        temp = temp->next;
    }

    if (temp->next) {
        EventNode* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
        cout << "Event '" << name << "' removed.\n";
    } else {
        cout << "Event not found.\n";
    }
}

struct Queue {
    int front, rear, capacity;
    string* participants;

    Queue(int size) {
        capacity = size;
        front = rear = -1;
        participants = new string[capacity];
    }

    bool isFull() {
        return rear == capacity - 1;
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(const string& name) {
        if (isFull()) {
            cout << "Queue is full. Cannot register more participants.\n";
            return;
        }
        if (front == -1) front = 0;
        participants[++rear] = name;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "No participants to remove.\n";
            return;
        }
        cout << "Removed participant: " << participants[front] << endl;
        for (int i = 0; i < rear; i++) {
            participants[i] = participants[i + 1];
        }
        --rear;
        if (front > rear) front = rear = -1;
    }

    void displayQueue() {
        if (isEmpty()) {
            cout << "No participants in the queue.\n";
            return;
        }
        cout << "Participants:\n";
        for (int i = front; i <= rear; i++) {
            cout << participants[i] << endl;
        }
    }
};

struct TreeNode {
    string category;
    string eventName;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* insertTreeNode(TreeNode* root, const string& category, const string& eventName) {
    if (!root) {
        root = new TreeNode{category, eventName, nullptr, nullptr};
        return root;
    }

    if (category < root->category) {
        root->left = insertTreeNode(root->left, category, eventName);
    } else {
        root->right = insertTreeNode(root->right, category, eventName);
    }

    return root;
}

void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << "Category: " << root->category << ", Event: " << root->eventName << endl;
    inorder(root->right);
}

int main() {
    EventNode* completedEvents = nullptr;
    Queue eventQueue(5);
    TreeNode* eventTree = nullptr;

    int choice, subChoice;
    string eventName, eventDate, eventLocation, participantName, category;

    while (true) {
        cout << "\nMenu Event Kampus:\n";
        cout << "1. Manage Completed Events (Linked List)\n";
        cout << "2. Register Participants (Queue)\n";
        cout << "3. Manage Event Categories (Tree)\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\n1. Insert Event\n2. Display Events\n3. Delete Event\n";
                cout << "Choose operation: ";
                cin >> subChoice;
                if (subChoice == 1) {
                    cout << "Enter event name: ";
                    cin >> eventName;
                    cout << "Enter event date: ";
                    cin >> eventDate;
                    cout << "Enter event location: ";
                    cin >> eventLocation;
                    insertEvent(completedEvents, eventName, eventDate, eventLocation);
                } else if (subChoice == 2) {
                    displayEvents(completedEvents);
                } else if (subChoice == 3) {
                    cout << "Enter event name to delete: ";
                    cin >> eventName;
                    deleteEvent(completedEvents, eventName);
                }
                break;

            case 2:
                cout << "\n1. Register Participant\n2. Display Participants\n3. Remove Participant\n";
                cout << "Choose operation: ";
                cin >> subChoice;
                if (subChoice == 1) {
                    cout << "Enter participant name: ";
                    cin >> participantName;
                    eventQueue.enqueue(participantName);
                } else if (subChoice == 2) {
                    eventQueue.displayQueue();
                } else if (subChoice == 3) {
                    eventQueue.dequeue();
                }
                break;

            case 3:
                cout << "\n1. Add Event to Category\n2. Display Events by Category\n";
                cout << "Choose operation: ";
                cin >> subChoice;
                if (subChoice == 1) {
                    cout << "Enter category: ";
                    cin >> category;
                    cout << "Enter event name: ";
                    cin >> eventName;
                    eventTree = insertTreeNode(eventTree, category, eventName);
                } else if (subChoice == 2) {
                    inorder(eventTree);
                }
                break;

            case 4:
                cout << "Exiting application...\n";
                return 0;
        }
    }
}
