#include "../src/output.h"
#include "../thirdparty/ctest.h"

CTEST(File, Read) {
  // Given
  char word[256];
  int s = 0;

  // When
  int real = FileRead(NULL, s);

  // Then
  int exp = -1;
  ASSERT_EQUAL(exp, real);
}

CTEST(File, S_zero) {
  // Given
  char word[256];
  int s = 0;

  // When
  int real = FileRead(word, s);

  // Then
  int exp = -5;
  ASSERT_EQUAL(exp, real);
}

/*CTEST(File, Schange) {
  // Given
  char word[256];
  int s = 0;

  // When
  int real = FileRead(word, 30);

  // Then
  int exp = -5;
  ASSERT_EQUAL(exp, real);
}*/
