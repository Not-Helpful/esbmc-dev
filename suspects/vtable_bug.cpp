template <typename T>
struct B;
struct trigger;

template<>
struct B<void>
{
  using C = trigger;
  B<void> *a;

  virtual C bug();
};

template<typename T>
struct B : B<void>
{
  B<T> getb();
};


template<typename T>
B<T> B<T>::getb()
{
  return B<T>{};
}

struct trigger : B<char>
{
  C bug() override
  {
    return *this;
  }
}; 

int main()
{
  B<int> b;
}
