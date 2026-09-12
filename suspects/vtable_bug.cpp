// Repro v5 -- new variable: NEVER reference the base class by name
// anywhere except in the inheritance declarations themselves.
//
// Every previous repro (v1-v4) did something like:
//
//   Base<void> *p = &d;
//   p->execute_deferred();
//
// That explicitly names Base<void> and takes a pointer typed exactly
// as Base<void>. That's a direct "use" of the base type as itself,
// which may be exactly what triggers ESBMC's frontend to convert
// Base<void>'s own CXXRecordDecl independently (giving it its own
// struct_type, its own build_vtable_map call, etc.) -- the thing
// that's been working correctly in every repro so far.
//
// In the real HPX bug log, EVERY missing entry belongs to
// future_data_base<future_data_void> or future_data_base<future<void>>
// -- both of which might genuinely never get named/pointed-to
// directly anywhere in the (large, real) HPX codebase or in your
// specific bug.cpp repro. They might ONLY ever be reached as a base
// subobject of something further derived.
//
// This repro removes every direct mention of Base<void> as a type in
// its own right: no `Base<void> *`, no `Base<void>` variable, nothing.
// The only way the base's virtual methods get invoked is through a
// Derived<int> object, calling into inherited (non-overridden)
// methods directly, and through virtual dispatch triggered via a
// pointer to something declared using the DERIVED class's own name.
//
// If the assertion/missing-entry reproduces here (and did NOT
// reproduce in v1-v4), that isolates the trigger: it's not about
// specialization, multiple inheritance, or CRTP-like template shape
// at all -- it's about whether the base class is ever independently
// "used" as itself anywhere in the translation unit.

struct RefcntBase
{
  virtual ~RefcntBase() {}
};

template <typename T>
struct Base;   // primary template: forward-declared only

template <>
struct Base<void> : RefcntBase   // explicit specialization, same as before
{
  virtual void execute_deferred() {}   // never overridden -- the one to watch
  virtual void overridden_lower() {}   // will be overridden, for comparison
  // NOTE: Base<void> is not named anywhere else in this file except
  // right here and in the template relationships below.
};

template <typename T>
struct Base : Base<void>   // generic template derives from its own specialization
{
  // overrides nothing -- same shape as future_data_base<Result>
};

template <typename T>
struct Derived : Base<T>   // mirrors future_data<Result> : future_data_base<Result>
{
  void overridden_lower() override {}
};

int main()
{
  // Only Derived<int> is ever named directly. No Base<void>*, no
  // Base<int>*, no explicit upcast anywhere -- the base classes are
  // reached ONLY through being Derived<int>'s ancestors.
  Derived<int> d;
  d.overridden_lower();   // dispatches to Derived's own override
  d.execute_deferred();   // dispatches to Base<void>'s implementation,
                          // inherited unchanged -- reached only through
                          // Derived<int>, never through a Base<void>-typed
                          // reference/pointer anywhere in this TU
  return 0;
}
