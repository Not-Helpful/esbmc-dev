template <typename T>
struct A;  

template<>
struct A<void>
{
  virtual void func();
};

template <typename T>
struct A : A<void>
{
};

template <typename T>
struct B : A<T>
{
  void func() override {}
};

// template <typename T>
// struct C
// {
//   int x;  
// };  

int main() {}
