// Each constexpr below evaluates to an APValue whose LValueBase holds a ValueDecl*,
// except `mp`, which is a MemberPointer APValue carrying a ValueDecl* (FieldDecl).

int global = 1;
void f() {}

struct S {
  int field;
  static int sm;
};
int S::sm = 2;

constexpr int *p_global = &global;      // LValue, base = VarDecl(global)
constexpr int &r_global = global;       // LValue, base = VarDecl(global)
constexpr int *p_static = &S::sm;       // LValue, base = VarDecl(S::sm)
constexpr void (*p_fn)() = &f;          // LValue, base = FunctionDecl(f)
constexpr int S::*mp = &S::field;       // MemberPointer, decl = FieldDecl(S::field)

int main(){}
