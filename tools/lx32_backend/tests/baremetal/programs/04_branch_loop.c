__attribute__((noinline)) int count_down(int n) {
  int acc = 0;
  while (n > 0) {
    acc += n;
    n--;
  }
  return acc;
}

int main(int argc, char **argv) {
  (void)argv;
  return count_down(argc);
}

