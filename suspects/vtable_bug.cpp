template <typename T>
struct smart_ptr
{
  T *ptr = nullptr;

  smart_ptr() = default;
  explicit smart_ptr(T *p) : ptr(p)
  {
  }

  template <typename Y>
  smart_ptr(smart_ptr<Y> const &r) : ptr(r.ptr)
  {
  }
};

struct Base
{
  void keep_alive_while_waiting()
  {
    smart_ptr<Base> this_(
      this); // <-- triggers conversion of intrusive_ptr<Base>
    (void)this_;
  }

  virtual void execute_deferred()
  {
  }
};

struct Derived : Base
{
};
struct Derived2 : Derived
{
};

void somewhere_else_in_the_program()
{
  smart_ptr<Derived2> sd;
  smart_ptr<Base> sb = sd; // upcast -- instantiates the Y=Allocator ctor
}

int main()
{
}
