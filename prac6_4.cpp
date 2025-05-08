#include <iostream>
#include <cstring>
using namespace std;
class Entity
{
protected:
    char *name;

public:
    Entity(const char *n = "Entity")
    {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        cout << "Entity Constructor: " << name << endl;
    }
    virtual ~Entity()
    {
        cout << "Entity Destructor: " << name << endl;
        delete[] name;
    }
    virtual void display() const
    {
        cout << "Name: " << name << endl;
    }
};
class Agent : public Entity
{
private:
    int *data;

public:
    Agent(const char *n, int size = 5) : Entity(n)
    {
        data = new int[size];
        for (int i = 0; i < size; ++i)
            data[i] = i * 10;
        cout << "Agent Constructor: Data allocated.\n";
    }
    ~Agent() override
    {
        delete[] data;
        cout << "Agent Destructor: Data deallocated.\n";
    }
    void display() const override
    {
        Entity::display();
        cout << "Agent has data buffer.\n";
    }
};
int main()
{
    cout << "=== Creating Agent via Base Pointer ===\n";
    Entity *e = new Agent("SimulationAgent");
    cout << "\n=== Displaying Object ===\n";
    e->display();
    cout << "\n=== Deleting Object ===\n";
    delete e;
    cout << endl
         << endl
         << "This program is created by 24CE141 _ JENIL VIRADIA.";
    return 0;
}
