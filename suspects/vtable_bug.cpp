// STRUCT_DUMP:
// struct
//   * tag: struct &$&$&$&std::atomic<hpx::lcos::detail::future_data_base<hpx::traits::detail::future_data_void>::state>
//   * components: 
//     0: component
//         * type: unsignedbv
//             * width: 32
//             * alignment: constant
//                 * type: unsignedbv
//                     * width: 64
//                 * value: 0000000000000000000000000000000000000000000000000000000000000100
//                 * #cformat: 4
//             * #member_name: tag-struct &$&$&$&std::atomic<hpx::lcos::detail::future_data_base<hpx::traits::detail::future_data_void>::state>
//             * #cpp_type: unsigned_int
//         * name: _M_i
//         * access: private
//         * pretty_name: _M_i
//         * #location: 
//           * file: /../lib64/gcc/x86_64-pc-linux-gnu/16/../../../../include/c++/16/atomic
//           * line: 213
//           * column: 7
//   * #location: 
//     * file: /../lib64/gcc/x86_64-pc-linux-gnu/16/../../../../include/c++/16/atomic
//     * line: 199
//     * column: 3
// END!


int printf(char *, ...);

template <typename T>
struct A;  

template<>
struct A<void>
{
  int one;
  virtual void func();
};

template <typename T>
struct A : A<void>
{
  int two;
};

template <typename T>
struct B : A<T>
{
};

template <typename T>
struct C : B<T>
{
  int x; 
  void func() override {printf("%d",this->two);}
};

int main()
{
  C<int> c;
  c.func();
}
