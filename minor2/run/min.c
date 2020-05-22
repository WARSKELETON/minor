extern int _pfpow(int base, int exponent) {
  int result = 1;
  for (exponent; exponent > 0; exponent--) {
    result = result * base;
  }
  return result;
}

extern int _pfstrcmp(const char* s1, const char* s2) {
    while(*s1 && (*s1==*s2))
        s1++,s2++;
    return *(const unsigned char*)s1-*(const unsigned char*)s2;
}