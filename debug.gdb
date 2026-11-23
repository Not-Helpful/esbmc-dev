set style enabled off
set logging file gdb-output.txt
set logging enabled on
set logging redirect on

# Start the program and stop at main so we can redirect the inferior's stdout once
tbreak main
run
call (void)freopen("gdb-dump.txt", "a", stderr)

break get_decl_name
commands
    silent
    call (void)nd.dump()
    call (void)fflush(0)
    continue
end

continue