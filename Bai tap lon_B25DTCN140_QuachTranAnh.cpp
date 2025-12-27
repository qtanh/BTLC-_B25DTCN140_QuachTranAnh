#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Classroom {
public:
    string id, name, major, type;
    void input() {
        cout << "ID: "; cin >> id; cin.ignore();
        cout << "Name: "; getline(cin, name);
        cout << "Major: "; getline(cin, major);
        cout << "Type: "; getline(cin, type);
    }
    void display() {
        cout << id << "\t" << name << "\t" << major << "\t" << type << endl;
    }
};
class Student {
public:
    string id, name, dob, mail, phone;
    void input() {
        cout << "ID: "; cin >> id; cin.ignore();
        cout << "Name: "; getline(cin, name);
        cout << "DOB: "; getline(cin, dob);
        cout << "Mail: "; getline(cin, mail);
        cout << "Phone: "; getline(cin, phone);
    }
    void display() {
        cout << id << "\t" << name << "\t" << dob << "\t" << mail << "\t" << phone << endl;
    }
};
void manageC(vector<Classroom>& v) {
    int c;
    while (true) {
        cout << ""\nClass: \n1.Show \n2.Add \n3.Del \n4.Edit \n0.Back\n Your selection: "; cin >> c;
        if (c == 0) break;
        if (c == 1) {
            cout << "\nID\tNAME\tMAJOR\tTYPE" << endl;
            for (int i = 0; i < (int)v.size(); i++) v[i].display();
        } else if (c == 2) { Classroom o; o.input(); v.push_back(o); }
        else {
            string s; cout << "ID: "; cin >> s;
            for (int i = 0; i < (int)v.size(); i++)
                if (v[i].id == s) {
                    if (c == 3) v.erase(v.begin() + i);
                    else v[i].input();
                    break;
                }
        }
    }
}
void manageS(vector<Student>& v) {
    int c;
    while (true) {
        cout << "\nStudent: \n1.Show \n2.Add \n3.Del \n4.Edit \n0.Back\n Your decision: "; cin >> c;
        if (c == 0) break;
        if (c == 1) {
            cout << "\nID\tNAME\t\tDOB\tMAIL\tPHONE" << endl;
            for (int i = 0; i < (int)v.size(); i++) v[i].display();
        } else if (c == 2) { Student o; o.input(); v.push_back(o); }
        else {
            string s; cout << "ID: "; cin >> s;
            for (int i = 0; i < (int)v.size(); i++)
                if (v[i].id == s) {
                    if (c == 3) v.erase(v.begin() + i);
                    else v[i].input();
                    break;
                }
        }
    }
}
int main() {
    vector<Classroom> l; vector<Student> s;
    int m;
    while (true) {
        cout << "\n1.Class 2.Student 0.Exit: "; cin >> m;
        if (m == 1) manageC(l);
        else if (m == 2) manageS(s);
        else break;
    }
    return 0;
}
