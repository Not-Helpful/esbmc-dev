// Reproducer attempts for esbmc: get_method -> body -> virtual member call -> get_method (same md)
// Build one case at a time, e.g.:  esbmc repro.cpp --std=c++23 -DCASE=2
// Untested: written from the backtrace, not run against esbmc.

#ifndef CASE
#define CASE 1
#endif

#if CASE == 1
// Case 1: virtual method whose body calls itself virtually.
struct A {
  virtual int f(int n) { return n ? this->f(n - 1) : 0; }
};

int main() {
  A a;
  return a.f(3);
}

#elif CASE == 2
struct A {
  virtual int g() { return 0; }
  virtual int f() { return this->g(); }  // virtual call to a different method
};
int main() { A a; return a.f(); }

#elif CASE == 3

struct A {
  virtual int f(int n) { return n ? this->g(n - 1) : 0; }
  virtual int g(int n) { return n ? this->f(n - 1) : 0; }
};

int main() {
  A a;
  return a.f(3);
}

#endif
