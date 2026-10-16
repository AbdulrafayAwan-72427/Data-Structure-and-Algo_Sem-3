// Student ID: 72427_abdulrafay | Data Structures & Algorithms - Assignment #2
#include <iostream>
#include <string>

using namespace std;

// 72427_abdulrafay - Q1: Singly Linked List (Patient Registration)
struct SNode {
    int id, age;
    string name, disease;
    SNode* next;
    SNode(int i, string n, int a, string d) : id(i), name(n), age(a), disease(d), next(nullptr) {}
};

struct PatientRegistration {
    SNode* head = nullptr;

    void add(int id, string n, int a, string d) {
        SNode** cur = &head;
        while (*cur) cur = &((*cur)->next);
        *cur = new SNode(id, n, a, d);
        cout << "[Registered] " << n << " (ID: " << id << ")\n";
    }

    void search(int id) const {
        for (SNode* t = head; t; t = t->next) {
            if (t->id == id) {
                cout << "[Found] " << t->name << " | Age: " << t->age << " | Disease: " << t->disease << "\n";
                return;
            }
        }
        cout << "[Search] Patient ID " << id << " not found.\n";
    }

    void remove(int id) {
        for (SNode** cur = &head; *cur; cur = &((*cur)->next)) {
            if ((*cur)->id == id) {
                SNode* toDel = *cur;
                *cur = (*cur)->next;
                delete toDel;
                cout << "[Removed] Patient ID: " << id << "\n";
                return;
            }
        }
        cout << "[Remove] Patient ID " << id << " not found.\n";
    }

    void display() const {
        if (!head) { cout << "No registered patients.\n"; return; }
        cout << "\n--- Registered Patients (SLL) ---\n";
        for (SNode* t = head; t; t = t->next)
            cout << "ID: " << t->id << " | Name: " << t->name << " | Age: " << t->age << " | Disease: " << t->disease << "\n";
    }
};

// 72427_abdulrafay - Q2: Doubly Linked List (Patient History)
struct DNode {
    int id; string name, treatment;
    DNode *prev = nullptr, *next = nullptr;
    DNode(int i, string n, string t) : id(i), name(n), treatment(t) {}
};

struct PatientHistory {
    DNode *head = nullptr, *tail = nullptr;

    void add(int id, string n, string t) {
        DNode* nn = new DNode(id, n, t);
        if (!head) head = tail = nn;
        else { tail->next = nn; nn->prev = tail; tail = nn; }
        cout << "[History Added] " << n << " (" << t << ")\n";
    }

    void displayForward() const {
        cout << "\n--- Patient History (Forward) ---\n";
        for (DNode* t = head; t; t = t->next)
            cout << "ID: " << t->id << " | Name: " << t->name << " | Treatment: " << t->treatment << "\n";
    }

    void displayReverse() const {
        cout << "\n--- Patient History (Reverse) ---\n";
        for (DNode* t = tail; t; t = t->prev)
            cout << "ID: " << t->id << " | Name: " << t->name << " | Treatment: " << t->treatment << "\n";
    }
};

// 72427_abdulrafay - Q3: Circular Linked List (Appointment Management)
struct CNode {
    int id; string name, slot;
    CNode* next = nullptr;
    CNode(int i, string n, string s) : id(i), name(n), slot(s) {}
};

struct AppointmentManagement {
    CNode *head = nullptr, *curr = nullptr;

    void add(int id, string n, string s) {
        CNode* nn = new CNode(id, n, s);
        if (!head) { head = curr = nn; nn->next = head; }
        else {
            CNode* t = head;
            while (t->next != head) t = t->next;
            t->next = nn; nn->next = head;
        }
        cout << "[Scheduled] " << n << " at " << s << "\n";
    }

    void display() const {
        if (!head) { cout << "No appointments.\n"; return; }
        cout << "\n--- Appointment Ring (CLL) ---\n";
        CNode* t = head;
        do {
            cout << "ID: " << t->id << " | " << t->name << " (" << t->slot << ")" 
                 << (t == curr ? " <-- ACTIVE" : "") << "\n";
            t = t->next;
        } while (t != head);
    }

    void nextAppt() {
        if (!curr) { cout << "No appointments available.\n"; return; }
        cout << "[Completed] " << curr->name << "\n";
        curr = curr->next;
        cout << "[Now Attending] " << curr->name << " (" << curr->slot << ")\n";
    }
};

// 72427_abdulrafay - Q4: Stack ADT (Emergency Management - LIFO)
struct StkNode {
    int id; string name, condition;
    StkNode* next;
    StkNode(int i, string n, string c, StkNode* nx) : id(i), name(n), condition(c), next(nx) {}
};

struct EmergencyStack {
    StkNode* top = nullptr;

    void push(int id, string n, string c) {
        top = new StkNode(id, n, c, top);
        cout << "[Admitted Emergency] " << n << " (" << c << ")\n";
    }

    void pop() {
        if (!top) { cout << "Emergency stack is empty!\n"; return; }
        StkNode* t = top;
        cout << "[Discharged/Treated] " << t->name << " (" << t->condition << ")\n";
        top = top->next;
        delete t;
    }

    void peek() const {
        if (top) cout << "[Top Emergency Case] " << top->name << " (" << top->condition << ")\n";
        else cout << "No emergency cases.\n";
    }

    void display() const {
        if (!top) { cout << "Emergency stack is empty.\n"; return; }
        cout << "\n--- Emergency Stack (Top to Bottom) ---\n";
        for (StkNode* t = top; t; t = t->next)
            cout << "ID: " << t->id << " | " << t->name << " | " << t->condition << "\n";
    }
};

// 72427_abdulrafay - Q5: Demonstration Records Loader (5 Records)
void loadDemo(PatientRegistration& reg, PatientHistory& hist, AppointmentManagement& appt, EmergencyStack& emg) {
    cout << "=== Loading 5 Demo Records (72427_abdulrafay) ===\n";
    reg.add(101, "Ali Khan", 34, "Hypertension");
    reg.add(102, "Sara Ahmed", 27, "Appendicitis");
    reg.add(103, "Bilal Tariq", 45, "Fracture");
    reg.add(104, "Zainab Bibi", 52, "Cardiac Arrest");
    reg.add(105, "Usman Malik", 19, "Severe Burn");

    hist.add(101, "Ali Khan", "Beta Blockers");
    hist.add(103, "Bilal Tariq", "Plaster Cast");

    appt.add(101, "Ali Khan", "09:30 AM");
    appt.add(102, "Sara Ahmed", "10:15 AM");
    appt.add(105, "Usman Malik", "11:00 AM");

    emg.push(104, "Zainab Bibi", "Cardiac Arrest");
    emg.push(102, "Sara Ahmed", "Acute Appendicitis");
    cout << "=================================================\n\n";
}

// 72427_abdulrafay - Main Driver
int main() {
    PatientRegistration reg;
    PatientHistory hist;
    AppointmentManagement appt;
    EmergencyStack emg;

    loadDemo(reg, hist, appt, emg);

    int choice = 0;
    while (choice != 5) {
        cout << "\n=== HOSPITAL PATIENT MANAGEMENT SYSTEM ===\n"
             << "1. Patient Registration (SLL)\n2. Patient History (DLL)\n"
             << "3. Appointment Management (CLL)\n4. Emergency Management (Stack)\n5. Exit\nEnter Choice: ";
        if (!(cin >> choice)) break;

        int op;
        if (choice == 1) {
            cout << "[1] Add [2] Search [3] Remove [4] Display All: "; cin >> op;
            if (op == 1) {
                int id, age; string name, disease;
                cout << "Enter ID Age Name Disease: "; cin >> id >> age >> name >> disease;
                reg.add(id, name, age, disease);
            } else if (op == 2) { int id; cout << "Enter ID: "; cin >> id; reg.search(id); }
            else if (op == 3) { int id; cout << "Enter ID: "; cin >> id; reg.remove(id); }
            else if (op == 4) reg.display();
        } else if (choice == 2) {
            cout << "[1] Add [2] Display Forward [3] Display Reverse: "; cin >> op;
            if (op == 1) {
                int id; string name, trt;
                cout << "Enter ID Name Treatment: "; cin >> id >> name >> trt;
                hist.add(id, name, trt);
            } else if (op == 2) hist.displayForward();
            else if (op == 3) hist.displayReverse();
        } else if (choice == 3) {
            cout << "[1] Add [2] Display All [3] Next Appointment: "; cin >> op;
            if (op == 1) {
                int id; string name, slot;
                cout << "Enter ID Name Slot: "; cin >> id >> name >> slot;
                appt.add(id, name, slot);
            } else if (op == 2) appt.display();
            else if (op == 3) appt.nextAppt();
        } else if (choice == 4) {
            cout << "[1] Push [2] Pop [3] Peek [4] Display: "; cin >> op;
            if (op == 1) {
                int id; string name, cond;
                cout << "Enter ID Name Condition: "; cin >> id >> name >> cond;
                emg.push(id, name, cond);
            } else if (op == 2) emg.pop();
            else if (op == 3) emg.peek();
            else if (op == 4) emg.display();
        } else if (choice == 5) {
            cout << "Exiting system. Goodbye!\n";
        }
    }
    return 0;
}