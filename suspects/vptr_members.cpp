// repro_vptr.cpp
struct B
{
  virtual int f()
  {
    return 1;
  }
  virtual ~B()
  {
  }
};

// D has no virtual methods of its own, so only B gets a vtable type symbol.
// The vptr is reached from D through the nested @base@B component.
struct D : B
{
  int g()
  {
    return 2;
  }
};

struct E : D
{
};

// Control: a plain virtual call through a D. Clang inserts a derived-to-base
// conversion to B before the call, so this should work.
int call_virtual(D &d)
{
  return d.f();
}

// Suspect: dynamic_cast whose static source type is D, but whose vptr
// belongs to B. build_dynamic_cast walks up from D to find B and then reads
// "tag-B::@vtable_pointer" off *d, a D.
E *down_ptr(D *d)
{
  return dynamic_cast<E *>(d);
}

int main()
{
  E e;
  D *d = &e;
  call_virtual(e);
  return down_ptr(d) != 0 ? 0 : 1;
}
