#include <iostream>
#include <cstdio>

typedef struct A {
  double hoge;
};

typedef struct B {
  double hoge;
  double get() {return hoge;};
};

int main () {

  A a;
  B b;

  std::cout << sizeof(a) << std::endl;
  std::cout << sizeof(b) << std::endl;
}

  
