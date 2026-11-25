# dyncast.gdb
set pagination off
set confirm off
set height 0
set width 0
set print elements 0

set logging file /tmp/dyn.log
set logging overwrite on
set logging redirect off
set logging enabled on

break clang_cpp_convert_vft.cpp:1159
commands
  silent
  printf "[dyncast] V=%s | S.subtype.id=%s | S.subtype.identifier=%s\n", vptr_class_id.c_str(), src_pointer.type().subtype().id().as_string().c_str(), src_pointer.type().subtype().identifier().as_string().c_str()
  if !$_streq(vptr_class_id.c_str(), src_pointer.type().subtype().identifier().as_string().c_str())
    printf "[dyncast] *** V != S ***\n"
    bt 8
  end
  continue
end

catch signal SIGABRT
commands
  silent
  printf "[dyncast] ===== ABORT, backtrace =====\n"
  bt 12
  info breakpoints
  set logging enabled off
end

run