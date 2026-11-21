template <typename D>
struct ebo
{
  D d;
  ebo(D x) : d(x)
  {
  }
  static D &get(ebo &e)
  {
    return e.d;
  }
};

template <typename D>
struct counted
{
  struct impl : ebo<D>
  {
    impl(D x) : ebo<D>(x)
    {
    }
    D &_M_del()
    {
      return ebo<D>::get(*this);
    }
  };

  impl i;
  counted(D x) : i(x)
  {
  }
};

template <typename T>
struct buf
{
  buf(int mode)
  {
    if (mode == 0)
    {
      auto l = [](T *) {};
      counted<decltype(l)> c(l);
      c.i._M_del();
    }
    else
    {
      auto l = [](T *) {};
      counted<decltype(l)> c(l);
      c.i._M_del();
    }
  }
};

int main()
{
  buf<double> b(0);
  return 0;
}
