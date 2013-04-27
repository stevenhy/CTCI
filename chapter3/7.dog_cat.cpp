#include <iostream>
#include <queue>
#include <assert.h>

using namespace std;
// problem: enqueue dogs/cats, dequeue always return the oldest
// one can dequeueAny, dequeueDog, dequeueCat

// there are two approaches for this problem
// A1: create a single queue, dequeueAny is easy, dequeueDog/dequeueCat requires
// check from the head of the queue to get the oldest dog/cat
// A2: create two separate queues for dogs and cats, and create a wrapper class

class Animal {
private:
    string name;
    int order;
public:
    Animal(string n) {
        name = n;
    }

    virtual ~Animal() {
    }

    string getName(){
        return name;
    }

    int getOrder(){
        return order;
    }

    void setOrder(int o) {
        order = o;
    }

    bool isOlder(Animal* a) {
        return order <= a->getOrder();
    }
};

class Cat : public Animal {
public:
    Cat(string n):Animal(n){}
};

class Dog : public Animal {
public:
    Dog(string n):Animal(n){}
};

class AnimalQueue {
private:
    queue<Cat*> cat;
    queue<Dog*> dog;
    int order;
public:
    void setOrder(){
        order = 0;
    }

    void enqueue(Animal* a) {
        a->setOrder(order++);
        Cat* c = dynamic_cast<Cat*>(a);
        if(c) {
            cat.push(c);
        } else {
            Dog* d = dynamic_cast<Dog*>(a);
            dog.push(d);
        }
    }

    Animal* dequeueAny(){
        if(cat.empty()) {
            return dequeueDog();
        } else if(dog.empty()) {
            return dequeueCat();
        } else {
            Cat* c = cat.front();
            Dog* d = dog.front();
            if(c->isOlder(d)) {
                return dequeueCat();
            } else {
                return dequeueDog();
            }
        }
    }

    Cat* dequeueCat(){
        Cat* c = cat.front();
        cat.pop();
        return c;
    }

    Dog* dequeueDog() {
        Dog* d = dog.front();
        dog.pop();
        return d;
    }

};

int main() {
    Animal* a1 = new Cat("c1");
    Animal* a2 = new Dog("d1");
    Animal* a3 = new Cat("c2");
    Animal* a4 = new Dog("d2");
    AnimalQueue q;
    q.setOrder();
    q.enqueue(a1);
    q.enqueue(a2);
    q.enqueue(a3);
    q.enqueue(a4);
    Animal* a = q.dequeueAny();
    assert(a->getName() == "c1");
    Animal* b = q.dequeueDog();
    assert(b->getName() == "d1");
    return 0;
}
