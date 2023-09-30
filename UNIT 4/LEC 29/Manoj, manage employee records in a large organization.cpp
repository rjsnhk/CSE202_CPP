// You are using GCC
#include <iostream>
using namespace std;

class Person { protected: string name; string code;

public: void getPersonDetails() { cin >> name >> code; } };

class Account : virtual public Person { protected:
int pay;

public: void getPay() { cin >> pay; } };

class Admin : virtual public Person { protected: int experience;

public: void getExperience() { cin >> experience; }
};

class Master : public Account, public Admin {

public: void create() { getPersonDetails(); getPay(); getExperience(); }

void display() {
  cout << "Name: " << name << endl;
  cout << "Code: " << code << endl;
  cout << "Pay: " << pay << endl;
  cout << "Experience: " << experience << endl;
}
};

int main ()
{
    int count;
    cin>>count;
    Master m[count];
    for(int i=0;i<count;i++){
        m[i].create();
    }
     for(int i=0;i<count;i++){
        m[i].display();
        cout<<std::endl;
    }   
    
  return 0;
}

