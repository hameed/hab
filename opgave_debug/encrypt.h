#include <stdio.h>
#include <string.h>

char str[20] = "urw zrq qvt";
char result[20];

char rotate_letter(char c)
{
  if (c >= 'a' && c <= 'm') {
    return c += 13;
  } else if (c >= 'n' && c <= 'z') {
    return c -= 13;
  } else if (c >= 'A' && c <= 'M') {
    return c += 13;
  } else if (c >= 'N' && c <= 'Z') {
    return c -= 13;
  }

  return c;
}

char *rot13(char *str)
{
  int i = 0;

  while (str[i] != '\0') {
    result[i] = rotate_letter(str[i]);
    i++;
  }
  result[i] = '\0';
  return result;
}
