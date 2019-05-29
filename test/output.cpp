#include "../src/output.h"
#include "../thirdparty/ctest.h"

CTEST(File, Read) {
  // Given
  char word[256];
  int s;

  // When
  FileRead(NULL, &s);

  // Then
  const double exp = 1;
  ASSERT_DBL_NEAR(word, exp);
}
