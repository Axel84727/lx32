__attribute__((noinline)) int add3(int x) {
  return x + 3;
}

__attribute__((noinline)) int use_calls(int a, int b) {
  int t = add3(a);
  return t + b;
}

int main(int argc, char **argv) {
  (void)argv;
  return use_calls(argc, 20);
}



