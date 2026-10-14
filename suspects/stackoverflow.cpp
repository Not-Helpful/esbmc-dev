struct A {
  virtual int f(int n) { return n ? this->g(n - 1) : 0; }
  virtual int g(int n) { return n ? this->f(n - 1) : 0; }
};

int main() {
  A a;
  return a.f(3);
}
