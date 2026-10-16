template <class T>
struct S { T x; };

template <class T>
void f(T) {}

// Implicit instantiation: NO ExplicitInstantiationDecl
S<int> a;
void g() { f(1.0); }

// Explicit instantiation definition: one node each
template struct S<char>;
template void f<long>(long);

// Explicit instantiation declaration (extern): one node
extern template struct S<short>;
