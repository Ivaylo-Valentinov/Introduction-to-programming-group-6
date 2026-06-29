bool isEven(unsigned int);

bool isOdd(unsigned int n) {
  if (n == 0) return false;       // 0 е четно, затова не е нечетно
  if (n == 1) return true;        // 1 е нечетно
  return isEven(n - 1);           // Числото n е нечетно, ако (n - 1) е четно
}

bool isEven(unsigned int n) {
  if (n == 0) return true;        // 0 е четно
  if (n == 1) return false;       // 1 не е четно
  return isOdd(n - 1);            // Числото n е четно, ако (n - 1) е нечетно
}
