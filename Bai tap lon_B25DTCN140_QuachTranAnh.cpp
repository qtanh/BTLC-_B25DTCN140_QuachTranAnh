#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Entity {
public:
    virtual void input() = 0;
    virtual void display() = 0;
    virtual string getID() = 0;
    virtual ~Entity() {}
};
class Classroom : public Entity {
private:
    string classId, className, major, classification;
public:
    void input() {
        cout << "ID: "; cin >> classId; cin.ignore();
        cout << "Name: "; getline(cin, className);
        cout << "Major: "; getline(cin, major);
        cout << "Type: "; getline(cin, classification);
    }
    void display() {
        cout << "[Class] " << classId << " - " << className << endl;
    }
    string getID() { return classId; }
};
class Student : public Entity {
private:
    string studentId, fullName, dob, email, phone;
public:
    void input() {
        cout << "ID: "; cin >> studentId; cin.ignore();
        cout << "Name: "; getline(cin, fullName);
        cout << "DOB: "; getline(cin, dob);
        cout << "Email: "; getline(cin, email);
        cout << "Phone: "; getline(cin, phone);
    }
    void display() {
        cout << "[Student] " << studentId << " - " << fullName << endl;
    }
    string getID() { return studentId; }
};
void manage(vector<Entity*>& list, string type) {
    int choice;
    while (true) {
        cout << "\n1. Display\n2. Add\n3. Delete\n4. Update\n0. Back\nSelect: ";
        cin >> choice;
        if (choice == 0) break;
        if (choice == 1) {
            for (int i = 0; i < (int)list.size(); i++) list[i]->display();
        } else if (choice == 2) {
            Entity* obj = (type == "C") ? (Entity*)new Classroom() : (Entity*)new Student();
            obj->input();
            list.push_back(obj);
        } else {
            string id; cout << "Enter ID: "; cin >> id;
            for (int i = 0; i < (int)list.size(); i++) {
                if (list[i]->getID() == id) {
                    if (choice == 3) { delete list[i]; list.erase(list.begin() + i); }
                    else list[i]->input();
                    break;
                }
            }                   
        }
    }
}
int main() {
    vector<Entity*> classes, students;
    int cmd;
    while (true) {
        cout << "\n1. Class\n2. Student\n0. Exit\nChoice: ";
        cin >> cmd;
        if (cmd == 1) manage(classes, "C");
        else if (cmd == 2) manage(students, "S");
        else break;
    }
    for (int i = 0; i < (int)classes.size(); i++) delete classes[i];
    for (int i = 0; i < (int)students.size(); i++) delete students[i];
    return 0;
} 
