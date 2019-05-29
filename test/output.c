#include "../src/output.h"
#include "../thirdparty/ctest.h"

CTEST(File, Read) {
  // Given
  char word[256];
  int s;

  // When
  int real = FileRead(NULL, s);

  // Then
  int exp = -1;
  ASSERT_EQUAL(exp, real);
}
