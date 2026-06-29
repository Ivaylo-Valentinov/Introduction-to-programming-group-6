int power_recursive(int base, unsigned int exp) {
    // Базов случай: всяко число на степен 0 е 1
    if (exp == 0) {
        return 1;
    }
    
    // Рекурсивно пресмятаме base^(exp / 2) само веднъж, за да спестим изчисления
    int half = power_recursive(base, exp / 2);
    
    // Ако степента е четна: base^exp = (base^(exp/2)) * (base^(exp/2))
    if (exp % 2 == 0) {
        return half * half;
    } 
    // Ако степента е нечетна: base^exp = base * (base^(exp/2)) * (base^(exp/2))
    else {
        return base * half * half;
    }
}
