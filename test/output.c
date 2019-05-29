#include "../src/output.h"
#include "../thirdparty/ctest.h"

CTEST(File, Read) {
  // Given
  char word[256];
  int s;

  // When
  FileRead(NULL, s);

  // Then
  ASSERT_STR(NULL, word);
}
