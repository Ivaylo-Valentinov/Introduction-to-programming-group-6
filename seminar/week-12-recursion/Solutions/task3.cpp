bool g(const char* text, const char* word)
{
  if (!*word) return true;
  if (!*text) return false;               // Бланк 1: Текстът е свършил, но думата - не.
  if (*word != *text) return false;
  return g(text + 1, word + 1);           // Бланк 2 и 3: Символите съвпадат, проверяваме следващите.
}

bool f(const char* text, const char* word)
{
  if (!*word) return true;                // Бланк 4: Празният низ винаги се съдържа.
  if (!*text) return false;
  return g(text, word) ||                 // Бланк 5 и 6: Проверяваме за съвпадение от ТЕКУЩАТА позиция.
  f(text + 1, word);                      // Бланк 7 и 8: Ако не съвпада тук, пропускаме 1 символ от текста и търсим нататък.
}
