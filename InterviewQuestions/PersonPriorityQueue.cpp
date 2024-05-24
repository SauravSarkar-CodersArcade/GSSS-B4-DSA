#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
// Structure to hold the Person Parameters
struct Person {
    string name;
    int age;
    Person(string n, int a) : name(n), age(a) {}
};
// Comparator for the priority queue
struct ComparePerson {
    bool operator() (Person const& p1, Person const& p2){
        // Higher age has higher priority
        return p1.age < p2.age;
    }
};
int main() {
    priority_queue<Person, vector<Person>, ComparePerson> pq;
    pq.push(Person("Alice", 30));
    pq.push(Person("Bryan", 25));
    pq.push(Person("Cynthia", 35));

    while (!pq.empty()){
        Person p = pq.top();
        cout << p.name << " (" << p.age << ") " << endl;
        pq.pop();
    }
    return 0;
}
