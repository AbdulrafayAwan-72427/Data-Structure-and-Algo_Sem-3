#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

// Reads a non-negative number safely (typing letters won't cause an infinite loop)
template <typename T>
T read(string msg) {
    T x;
    cout << msg;
    while (!(cin >> x) || x < 0) {
        if (cin.eof()) exit(0);
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid! Enter a non-negative number: ";
    }
    return x;
}

// ---------- 1. Product (Linked List Node) ----------
struct Product {
    int id;
    string name;
    double price;
    int qty;
    Product* next;
};

// ---------- 2. Inventory (Singly Linked List) ----------
class Inventory {
    Product* head = nullptr;

public:
    ~Inventory() {
        while (head) { Product* t = head; head = head->next; delete t; }
    }

    // Returns the product with this id, or nullptr if not found
    Product* find(int id) {
        for (Product* p = head; p; p = p->next)
            if (p->id == id) return p;
        return nullptr;
    }

    void print(Product* p) {
        cout << "ID: " << p->id << " | Name: " << p->name
             << " | Price: $" << p->price << " | Qty: " << p->qty << endl;
    }

    void add(int id, string name, double price, int qty) {
        if (find(id)) { cout << "Product ID already exists!\n"; return; }
        Product* n = new Product{id, name, price, qty, nullptr};
        if (!head) head = n;
        else {
            Product* p = head;
            while (p->next) p = p->next;
            p->next = n;
        }
        cout << "Product added!\n";
    }

    void display() {
        if (!head) cout << "No products in inventory.\n";
        for (Product* p = head; p; p = p->next) print(p);
    }

    void search(int id) {
        Product* p = find(id);
        if (p) print(p); else cout << "Product not found.\n";
    }

    void update(int id, int qty) {
        Product* p = find(id);
        if (p) { p->qty = qty; cout << "Stock updated!\n"; }
        else cout << "Product not found.\n";
    }

    void remove(int id) {
        Product *cur = head, *prev = nullptr;
        while (cur && cur->id != id) { prev = cur; cur = cur->next; }
        if (!cur) { cout << "Product not found.\n"; return; }
        if (prev) prev->next = cur->next;   // middle / last node
        else head = cur->next;              // first node
        delete cur;
        cout << "Product deleted!\n";
    }

    void lowStock() {
        bool found = false;
        for (Product* p = head; p; p = p->next)
            if (p->qty < 10) { print(p); found = true; }
        if (!found) cout << "No low-stock products.\n";
    }
};

// Simple node used by both Stack and Queue
struct Node {
    int val;
    Node* next;
};

// ---------- 3. Stack - Recent Stock Operations (LIFO) ----------
class Stack {
    Node* top = nullptr;

public:
    ~Stack() { while (top) { Node* t = top; top = top->next; delete t; } }

    void push(int id) { top = new Node{id, top}; cout << "Operation pushed.\n"; }

    void pop() {
        if (!top) { cout << "Stack is empty!\n"; return; }
        Node* t = top;
        cout << "Removed operation for Product ID " << t->val << endl;
        top = top->next;
        delete t;
    }

    void display() {
        if (!top) cout << "Stack is empty.\n";
        for (Node* p = top; p; p = p->next) cout << "Product ID: " << p->val << endl;
    }
};

// ---------- 4. Queue - Pending Orders (FIFO) ----------
class Queue {
    Node *front = nullptr, *rear = nullptr;

public:
    ~Queue() { while (front) { Node* t = front; front = front->next; delete t; } }

    void enqueue(int id) {
        Node* n = new Node{id, nullptr};
        if (!rear) front = rear = n;
        else { rear->next = n; rear = n; }
        cout << "Order added.\n";
    }

    void dequeue() {
        if (!front) { cout << "No pending orders!\n"; return; }
        Node* t = front;
        cout << "Processed Order ID " << t->val << endl;
        front = front->next;
        if (!front) rear = nullptr;
        delete t;
    }

    void display() {
        if (!front) cout << "Queue is empty.\n";
        for (Node* p = front; p; p = p->next) cout << "Order ID: " << p->val << endl;
    }
};

int main() {
    Inventory inv;
    Stack st;
    Queue q;
    int choice;

    do {
        cout << "\n===== INVENTORY MANAGEMENT SYSTEM =====\n"
             << "1. Add Product\n2. Display Products\n3. Search Product\n"
             << "4. Update Stock\n5. Delete Product\n6. Low-Stock Products\n"
             << "7. Add Stock Operation\n8. Undo Last Operation\n9. Display Stack\n"
             << "10. Add Order\n11. Process Order\n12. Display Queue\n"
             << "13. Array Demo (5 Products)\n14. Exit\n";
        choice = read<int>("Enter choice: ");

        switch (choice) {
        case 1: {
            int id = read<int>("Product ID: ");
            string name;
            cout << "Product Name: ";
            cin.ignore(1000, '\n');
            getline(cin, name);                 // allows names with spaces
            double price = read<double>("Price: ");
            int qty = read<int>("Quantity: ");
            inv.add(id, name, price, qty);
            break;
        }
        case 2:  inv.display(); break;
        case 3:  inv.search(read<int>("Product ID: ")); break;
        case 4: {
            int id = read<int>("Product ID: ");
            inv.update(id, read<int>("New Quantity: "));
            break;
        }
        case 5:  inv.remove(read<int>("Product ID: ")); break;
        case 6:  inv.lowStock(); break;
        case 7: {
            int id = read<int>("Product ID: ");
            if (inv.find(id)) st.push(id);
            else cout << "Product not found.\n";
            break;
        }
        case 8:  st.pop(); break;
        case 9:  st.display(); break;
        case 10: q.enqueue(read<int>("Order ID: ")); break;
        case 11: q.dequeue(); break;
        case 12: q.display(); break;
        case 13: {
            Product arr[5] = {
                {1, "Laptop", 999.99, 5, nullptr},
                {2, "Mouse", 19.99, 50, nullptr},
                {3, "Keyboard", 49.99, 30, nullptr},
                {4, "Monitor", 199.99, 8, nullptr},
                {5, "Printer", 149.99, 12, nullptr}
            };
            for (int i = 0; i < 5; i++) {
                cout << "arr[" << i << "] -> ";
                inv.print(&arr[i]);
            }
            break;
        }
        case 14: cout << "Goodbye!\n"; break;
        default: cout << "Invalid choice!\n";
        }
    } while (choice != 14);

    return 0;
}