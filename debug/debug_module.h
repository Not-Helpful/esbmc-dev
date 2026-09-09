#pragma once
#ifdef __cplusplus
#  include <iostream>
#  ifdef ESBMC_PERSONAL_DEBUG

#    define DBM_PRINT(expr) std::cout << expr << std::endl
#    define DBM_LET_PRINT(fn) fn()
#    define DBM_BLOCK(...) __VA_ARGS__

#  else

#    define DBM_PRINT(expr) ((void)0)
#    define DBM_LET_PRINT(fn) ((void)0)
#    define DBM_BLOCK(...) ((void)0)

#  endif

#endif // __cplusplus
