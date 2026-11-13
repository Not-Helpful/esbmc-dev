#pragma once
#ifdef __cplusplus
#  include <iostream>
#  ifdef ESBMC_PERSONAL_DEBUG



#    define DBM_PRINT(expr) std::cout << expr << std::endl
#    define DBM_LET_PRINT(fn) fn()
#    define DBM_BLOCK(...) __VA_ARGS__

// RAII guard: prints on construction (entry) AND destruction (exit),
// with indentation proportional to depth -- so a genuine nested chain
// shows monotonically increasing indentation all the way down, while
// two unrelated/sibling calls show the SAME (or lower) indentation
// level, not deeper than their common caller.
// C++20 fixed-string wrapper -- lets a string literal be used directly
// as a template parameter (NTTP). This type must be a "structural type"
// (aggregate, no user-provided ctors beyond what's needed) for that to
// work, which is why it's written this way.
template <std::size_t N>
struct FixedString
{
  char data[N]{};

  constexpr FixedString(const char (&str)[N])
  {
    for (std::size_t i = 0; i < N; ++i)
      data[i] = str[i];
  }

  constexpr operator std::string_view() const
  {
    return std::string_view(data, N - 1);   // N-1: drop the trailing '\0'
  }
};

inline int g_trace_depth = 0;   // ONE counter, shared by everything

template <FixedString Label>
struct TraceGuard
{
  std::string what;
  int my_depth;

  TraceGuard(const std::string &w) : what(w), my_depth(g_trace_depth++)
  {
    DBM_PRINT(
      std::string(my_depth * 2, ' ')
      << "-> ENTER [" << Label.operator std::string_view() << "][" << my_depth
      << "] " << what);
  }

  ~TraceGuard()
  {
    --g_trace_depth;
    DBM_PRINT(
      std::string(my_depth * 2, ' ')
      << "<- EXIT  [" << Label.operator std::string_view() << "][" << my_depth
      << "] " << what);
  }
};




#  else

#    define DBM_PRINT(expr) ((void)0)
#    define DBM_LET_PRINT(fn) ((void)0)
#    define DBM_BLOCK(...) ((void)0)

#  endif

#endif // __cplusplus


