// control.cpp
template <class T> struct I {
  virtual const I<T> *query(const I<T> *other) const { return other; }  // virtual, template, self-typed signature, but no call in body
  int plain(int n) const { return n ? plain(n - 1) : 0; }               // recursive, but non-virtual
};

struct Root : I<int> {};

int main() {
  Root r;
  return r.query(&r) == &r && r.plain(3) == 0 ? 0 : 1;
}
