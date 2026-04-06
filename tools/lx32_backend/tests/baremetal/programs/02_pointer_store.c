int pointer_load(int *p) {
  return *p;
}

int pointer_roundtrip(int *p, int input) {
  *p = input;
  return *p;
}




