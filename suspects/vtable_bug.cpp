template <typename T>
struct intrusive_ptr
{
  T *ptr = nullptr;

  intrusive_ptr() = default;
  explicit intrusive_ptr(T *p) : ptr(p)
  {
  }

  template <typename Y>
  intrusive_ptr(intrusive_ptr<Y> const &r) : ptr(r.ptr)
  {
  }
};

struct Base
{
  virtual ~Base()
  {
  }

  void keep_alive_while_waiting()
  {
    intrusive_ptr<Base> b;
  }

  virtual void execute_deferred()
  {
  }
};

struct Allocator : Base
{
};


void somewhere_else_in_the_program()
{
  Allocator a;
  intrusive_ptr<Allocator> pa(&a);
  intrusive_ptr<Base> pb = pa; // upcast -- instantiates the Y=Allocator ctor
  (void)pb;
}

int main()
{
}
