#include <bits/stdc++.h>

using namespace std;

class A {
  public:
    A() { cout << "A::A()" << endl; }
    ~A() { cout << "A::~A()" << endl; }
    virtual void foo() { cout << "A::foo" << endl; }
    void bar() { cout << "A::Bar" << endl; }
};

class B : public A {
  public:
    B() { cout << "B::B()" << endl; }
    ~B() { cout << "B::~B()" << endl; }
    void foo() { cout << "B::foo" << endl; }
};

class C : public A {
  public:
    C() { cout << "C::C()" << endl; }
    ~C() { cout << "C::~C()" << endl; }
    void bar() { cout << "C::bar" << endl; }
};

int main() {


  A *b = new B();
  A *c = new C();

  std::vector<A*> v; v.push_back(b); v.push_back(c);
  for (std::vector<A*>::iterator iter  = v.begin();
                                 iter != v.end();
                               ++iter) {
      (*iter)->foo();
      (*iter)->bar();
  }
  delete b;
  delete c;
}