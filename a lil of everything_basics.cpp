/*************************************************************

SMART CAMPUS MANAGEMENT SYSTEM (DSA INTEGRATED PROBLEM)

You are required to design a Smart Campus System using
different data structures. Each module represents a real-world
scenario and must be implemented using the specified data structure.

---------------------------------------------------------------
PART 1: ENTRY GATE SYSTEM (QUEUE)
---------------------------------------------------------------
Students enter the campus in a FIFO manner.

Tasks:
- Implement a Queue (array or linked list)
- enqueue(studentID)
- dequeue()
- peek()
- display queue

---------------------------------------------------------------
PART 2: CAFETERIA UNDO SYSTEM (STACK)
---------------------------------------------------------------
Students place orders. Last order should be undone first.

Tasks:
- Implement a Stack
- push(order)
- pop() → undo last order
- display order history

---------------------------------------------------------------
PART 3: STUDENT NAVIGATION SYSTEM (DOUBLY LINKED LIST)
---------------------------------------------------------------
Admin browses student records forward and backward.

Tasks:
- Create doubly linked list
- Insert student
- Traverse forward
- Traverse backward
- Delete a student node

---------------------------------------------------------------
PART 4: COMPLAINT SYSTEM (SINGLY LINKED LIST)
---------------------------------------------------------------
Students submit complaints. Only forward traversal required.

Tasks:
- Insert complaint
- Delete complaint
- Display complaints

---------------------------------------------------------------
PART 5: ACADEMIC RECORD SYSTEM (BINARY SEARCH TREE)
---------------------------------------------------------------
Store student marks efficiently.

Tasks:
- Insert marks into BST
- Search a mark
- Inorder traversal (sorted output)
- Find minimum and maximum marks

---------------------------------------------------------------
PART 6: COURSE PREREQUISITE SYSTEM (BINARY TREE)
---------------------------------------------------------------
Courses have prerequisite structure.

Tasks:
- Build a binary tree
- Perform traversals:
    * Preorder
    * Inorder
    * Postorder
- Find height of tree

---------------------------------------------------------------
BONUS (OPTIONAL)
Create a menu-driven program integrating all modules.

*************************************************************/

#include <iostream>
#include <cmath>
#include <queue>
#include <string>
#define MAX 1024
#define INVALID -1
using namespace std;

// singly linked list
class singleNode {
public:
    string data;
    singleNode* next;


    singleNode(string data = "NULL") {
        this->data = data;
        this->next = NULL;
    }
};

//doubly linked list
class doubleNode {
public:
    int data;
    doubleNode* next;
    doubleNode* prev;

    doubleNode(int data = 0) {
        this->data = data;
        next = prev = NULL;
    }
};

class binaryTreeNode {
public:
    float data;
    binaryTreeNode* left;
    binaryTreeNode* right;

    binaryTreeNode(float data = 0) {
        this->data = data;
        left = right = NULL;
    }
};

class courseNode {
public:
    string data;
    courseNode* left;
    courseNode* right;

    courseNode(string val) {
        data = val;
        left = right = NULL;
    }
};

class entryGateSystem {
private:
    int queue[MAX], start, end;

    bool isEmpty() { return start > end || end == INVALID; }

    bool isFull() { return end == MAX - 1; }

public:
    entryGateSystem() : start(INVALID), end(INVALID) {}

    void enqueue(int studentID) {
        if (isFull()) {
            cout << "\nLimit Reached!\n";
            return;
        }
        else {
            if (start == INVALID) start = 0;
            ++end;
            queue[end] = studentID;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "\nEmpty! Add entry first.\n";
            return;
        }
        else {
            int temp = queue[start];
            start++;
            cout << "Student with ID " << temp << " entered. \n";
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "\nEmpty! Add entry first.\n";
            return;
        }
        else {
            cout << "Now dealing with ID " << queue[start] << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "\nEmpty! Add entry first.\n";
            return;
        }
        else {
            cout << "\n---Student Entering Gate Info---\n";
            for (int i = start; i <= end; i++) {
                cout << "ID " << queue[i] << endl;
            }
        }
    }
};

class cafeteriaSystem {
private:
    string orders[MAX];
    int top;
    bool isEmpty() { return top == INVALID; }

    bool isFull() { return top == MAX - 1; }

public:

    cafeteriaSystem() : top(INVALID) {}

    void push(string order) {
        if (isFull()) {
            cout << "\nCapacity reached! Cannot take more orders :( \n";
            return;
        }
        else {
            ++top;
            orders[top] = order;
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "\nNo orders yet!\n";
            return;
        }
        else {
            string temp = orders[top];
            cout << "Latest order undone: " << temp << endl;
            --top;
        }
    }

    void displayHistory() {
        if (isEmpty()) {
            cout << "\nNo orders to display!\n";
            return;
        }
        else {
            cout << "\n---Order History---\n";

            for (int i = 0; i <= top; i++) {
                cout << orders[i] << endl;
            }
        }
    }
};


class complaintSystem {
private:
    singleNode* start, * ptr;
    bool isEmpty() { return start == NULL; }

    void deleteComplaintSystem(singleNode* node) {
        if (node == NULL) return;

        deleteComplaintSystem(node->next);
        delete node;
    }

public:
    complaintSystem() : start(NULL) {}


    void addComplaint(string complaint) {
        if (isEmpty()) {
            singleNode* newNode = new singleNode(complaint);
            this->start = newNode;
        }
        else {   //attaching complaints at the end
            ptr = start;
            while (ptr->next != NULL) {
                ptr = ptr->next;
            }
            singleNode* newNode = new singleNode(complaint);
            ptr->next = newNode;
        }

    }

    void deleteComplaint() {
        if (isEmpty()) {
            cout << "\nNo complaints added!\n";
            return;
        }
        else {
            // deleting at specific positions
            ptr = start;
            int pos;
            cout << "Enter position of complaint to delete(starting 0): ";
            cin >> pos;
            if (0 == pos) {
                cout << "Deleting complaint: " << start->data << endl << endl;
                start = start->next;
                return;
            }
            for (int i = 0; i < pos - 1 && ptr != NULL; i++)
                ptr = ptr->next;

            singleNode* temp = ptr->next;
            ptr->next = temp->next;
            cout << "Deleting complaint: " << temp->data << endl << endl;
            delete temp;

        }
    }

    void displayComplaint() {
        if (isEmpty()) {
            cout << "\nNo complaints to display!\n";
            return;
        }
        else {
            ptr = start;
            while (ptr != NULL) {
                cout << "Complaint: " << ptr->data << endl;
                ptr = ptr->next;
            }
        }
    }

    ~complaintSystem() {
        deleteComplaintSystem(start);
    }

};

class navigationSystem {
private:
    doubleNode* start, * end, * ptr;
    bool isEmpty() { return start == NULL || end == NULL; }

    void deleteNav(doubleNode* node) {
        if (node == NULL) return;

        deleteNav(node->next);
        delete node;
    }

public:
    navigationSystem() : start(NULL), end(NULL) {}

    void addStudent(int id) {
        if (isEmpty()) {
            doubleNode* newNode = new doubleNode(id);
            this->start = this->end = newNode;
        }
        else { //adding at end assumption
            ptr = start;
            doubleNode* newNode = new doubleNode(id);
            while (ptr->next != NULL)
                ptr = ptr->next;

            ptr->next = newNode;
            newNode->prev = ptr;
            this->end = newNode;
        }

    }

    void deleteStudent() {
        if (isEmpty()) {
            cout << "\nNo students added!\n";
            return;
        }
        else {
            // deleting at specific positions assuming positions start from front(*start) end
            ptr = start;
            int pos;
            cout << "Enter position of student to delete (starting 0): ";
            cin >> pos;

            if (0 == pos) {
                cout << "Deleting student: " << start->data << endl << endl;
                start = start->next;
                return;
            }
            for (int i = 0; i < pos - 1 && ptr != NULL; i++)
                ptr = ptr->next;

            doubleNode* temp = ptr->next;
            ptr->next = temp->next;

            if (temp->next != NULL)
                temp->next->prev = ptr;
            else
                end = ptr;

            cout << "Deleting student: " << temp->data << endl << endl;
            delete temp;

        }
    }

    void displayForward() {
        if (isEmpty()) {
            cout << "\nNo students added!\n";
            return;
        }
        else {
            ptr = start;
            while (ptr != NULL) {
                cout << "Student ID registered: " << ptr->data << endl;
                ptr = ptr->next;
            }
        }
    }

    void displayBackward() {
        if (isEmpty()) {
            cout << "\nNo students added!\n";
            return;
        }
        else {
            ptr = end;
            while (ptr != NULL) {
                cout << "Student ID registered: " << ptr->data << endl;
                ptr = ptr->prev;
            }
        }
    }

    ~navigationSystem() {
        deleteNav(start);
    }

};

class academicRecords {
private:
    binaryTreeNode* root;

    binaryTreeNode* addMarksHelper(binaryTreeNode* node, float marks) {
        if (node == NULL)
            return new binaryTreeNode(marks);

        if (marks < node->data)
            node->left = addMarksHelper(node->left, marks);
        else
            node->right = addMarksHelper(node->right, marks);

        return node;
    }

    void deleteTree(binaryTreeNode* node) {
        if (node == NULL) return;

        deleteTree(node->left);
        deleteTree(node->right);

        delete node;
    }

    void traversal(binaryTreeNode* node) {
        if (node != NULL) {
            traversal(node->left);
            cout << node->data << ", ";
            traversal(node->right);
        }
        cout << endl;
    }

    void searchHelper(binaryTreeNode* node, float key) {
        if (node == NULL) {
            cout << "\nGiven data does not exist!\n";
            return;
        }
        else if (key == node->data) {
            cout << "\n Found in tree!\n";
            return;
        }
        else if (key < node->data)
            searchHelper(node->left, key);
        else
            searchHelper(node->right, key);

    }

public:
    academicRecords() : root(NULL) {}

    void inOrderTraversal() {
        traversal(root);
    }

    void search(float key) {
        searchHelper(root, key);
    }

    void minmax() {
        binaryTreeNode* temp = root;
        if (temp != NULL) {
            while (temp->left != NULL)
                temp = temp->left;
            cout << "Minimum marks: " << temp->data << endl;

            temp = root;
            while (temp->right != NULL)
                temp = temp->right;
            cout << "Maximum marks: " << temp->data << endl;
        }
        else {
            cout << "Empty tree! No marks to display.\n";
            return;
        }

    }

    void addMarks(float marks) {
        root = addMarksHelper(root, marks);
    }

    ~academicRecords() {
        deleteTree(root);
    }

};

class classPreRequisite {
private:
    courseNode* root;

    void addCourseHelper(string course) {
        if (root == NULL) {
            root = new courseNode(course);
            return;
        }

        queue<courseNode*> q;
        q.push(root);

        while (!q.empty()) {

            courseNode* curr = q.front();
            q.pop();

            // insert node at first available position (level order insertion)
            if (curr->left == NULL) {
                curr->left = new courseNode(course);
                return;
            }
            else {
                q.push(curr->left);
            }

            if (curr->right == NULL) {
                curr->right = new courseNode(course);
                return;
            }
            else {
                q.push(curr->right);
            }
        }
    }

    void deleteTree(courseNode* node) {
        if (node == NULL) return;

        deleteTree(node->left);
        deleteTree(node->right);

        delete node;
    }


    int height(courseNode* node) {
        if (NULL == node)
            return 0;

        return 1 + max(height(node->left), height(node->right)); //max no. of nodes from root to leaf
    }

    void inOrder(courseNode* node) {
        if (node == NULL)
            return;
        inOrder(node->left);
        cout << node->data << ", ";
        inOrder(node->right);
    }

    void preOrder(courseNode* node) {
        if (node == NULL)
            return;
        cout << node->data << ", ";
        preOrder(node->left);
        preOrder(node->right);
    }

    void postOrder(courseNode* node) {
        if (node == NULL)
            return;
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << ", ";
    }

public:

    classPreRequisite() : root(NULL) {}

    void inOrderTraversal() {
        inOrder(root);
    }

    void preOrderTraversal() {
        preOrder(root);
    }

    void postOrderTraversal() {
        postOrder(root);
    }

    void getHeight() {
        int finalHeight = height(root);
        cout << "Height of tree: " << finalHeight << endl;
    }

    void addCourse(string course) {
        addCourseHelper(course);
    }

    ~classPreRequisite() {
        deleteTree(root);
    }
};

int main() {
    int choice;
    entryGateSystem entryGate;
    cafeteriaSystem cafeteria;
    navigationSystem navigation;
    complaintSystem complaints;
    academicRecords records;
    classPreRequisite preReq;

    do {
        cout << "---------MENU---------\n 1. ENTRY GATE SYSTEM\n 2. CAFETERIA SYSTEM\n 3. STUDENT NAVIGATION SYSTEM\n 4. COMPLAINT SYSTEM\n 5. ACADEMIC RECORD SYSTEM\n 6. COURSE PREREQUISITE SYSTEM\n > EXIT\n";
        cin >> choice;

        switch (choice) {
        case 1: {
            int students, id, option;
            cout << "Testing Entry Gate System...\n";
            cout << "1. Enqueue students\n2. Dequeue student\n3. Peek next student\n4. Display queue\n";
            cin >> option;
            switch (option) {
            case 1:
                cout << "Enter no.of students entering: ";
                cin >> students;
                for (int i = 0; i < students; i++) {
                    cout << "Enter student ID: ";
                    cin >> id;
                    entryGate.enqueue(id);
                }
                break;
            case 2:
                entryGate.dequeue();
                break;
            case 3:
                entryGate.peek();
                break;
            case 4:
                entryGate.display();
                break;
            }
        }
              break;

        case 2: {
            int orders, option;
            string orderName;
            cout << "Welcome to the Cafeteria...\n";
            cout << "1. Add Order \n2. Remove Orders\n3. Display Orders\n";
            cin >> option;
            switch (option) {
            case 1:
                cout << "Enter total orders: ";
                cin >> orders;
                for (int i = 0; i < orders; i++) {
                    cout << "Enter order: ";
                    cin >> orderName;
                    cafeteria.push(orderName);
                }
                break;
            case 2:
                cafeteria.pop();
                break;
            case 3:
                cafeteria.displayHistory();
                break;
            }
        }
              break;
        case 3:{
                int students, id, option;
                cout << "Testing Student Navigation System...\n";
                cout << "1. Add student\n2. Delete student\n3. Display forward\n4. Display backward\n";
                cin >> option;
                switch (option) {
                case 1:
                    cout << "Enter no.of students to add: ";
                    cin >> students;
                    for (int i = 0; i < students; i++) {
                        cout << "Enter student ID: ";
                        cin >> id;
                        navigation.addStudent(id);
                    }
                    break;
                case 2:
                    navigation.deleteStudent();
                    break;
                case 3:
                    navigation.displayForward();
                    break;
                case 4:
                    navigation.displayBackward();
                    break;
                }
			}
            break;
        case 4: {
                int option, totalComplaints;
                string complaint;
                cout << "Testing Complaint System...\n";
                cout << "1. Add complaint\n2. Delete complaint\n3. Display complaints\n";
                cin >> option;
                switch (option) {
                case 1:
                    cout << "Enter total complaints to add: ";
                    cin >> totalComplaints;
                    for (int i = 0; i < totalComplaints; i++) {
                        cout << "Enter complaint: ";
                        cin.ignore();
                        getline(cin, complaint);
                        complaints.addComplaint(complaint);
                    }
                    break;
                case 2:
                    complaints.deleteComplaint();
                    break;
                case 3:
                    complaints.displayComplaint();
                    break;
				}
        }
            break;
        case 5: {
            int students, option;
            float marks;

            cout << "Testing Academic Records System...\n";
            cout << "1. Add marks\n2. Min-Max Marks\n3. Search Marks\n4. Traversal (in order)\n";
            cin >> option;
            switch (option) {
            case 1:
                cout << "Enter no. of student's marks to add: ";
                cin >> students;
                for (int i = 0; i < students; i++) {
                    cout << "Enter student marks: ";
                    cin >> marks;
                    records.addMarks(marks);
                }
                break;
            case 2:
                records.minmax();
                break;
            case 3:
                records.search(21);
                break;
            case 4:
                records.inOrderTraversal();
                break;
            }
        }
            break;
        case 6: {
            int courses, option;
            string courseName;

            cout << "Testing Class Pre-Requisite System...\n";
            cout << "1. Add course\n2. InOrder traversal\n3. PreOrder traversal\n4. PostOrder traversal\n5. Height of Tree\n";
            cin >> option;
            switch (option) {
            case 1:
                cout << "Enter no.of courses to add: ";
                cin >> courses;
                for (int i = 0; i < courses; i++) {
                    cout << "Enter course name: ";
                    cin >> courseName;
                    cin.ignore();
                    getline(cin, courseName);
                    preReq.addCourse(courseName);
                }
                break;
            case 2:
                preReq.inOrderTraversal();
                break;
            case 3:
                preReq.preOrderTraversal();
                break;
            case 4:
                preReq.postOrderTraversal();
                break;
            case 5: {
                preReq.getHeight();
            }
                  break;
            }
            
        }
            break;
        default:
            cout << "Exiting...\n";
            break;
        }
    } while (choice >= 1 && choice <= 6);

    
}
