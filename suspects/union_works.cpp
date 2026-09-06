
struct S {
  int tag;
  union {
    int a;
    float b;
  };
};

int main() {
  S s;
  s.tag = 1;
  s.a = 5;          // ordinary access into the anon-union member — this is your dump target
  return 0;
}
