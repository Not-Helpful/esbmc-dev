template <typename T>
struct A;

template<>
struct A<int>
{
  using result_type = void;
  result_type *get_result_void();
  virtual result_type *get_result_void(int ec = 0) = 0;
};

template<typename T>
struct A : A<int>
{
  using result_type = void;
  result_type *get_result_void();
  virtual result_type *get_result_void(int ec = 0) = 0;
};

int main() {}
