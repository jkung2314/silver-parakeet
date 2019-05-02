#include <kenv.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int length = argv[1][0] - '0';

  kenv(KENV_SET, "CMPS_111_SCHED_SAVE", "1", strlen("1") + 1);
  sleep(length);
  kenv(KENV_SET, "CMPS_111_SCHED_SAVE", "0", strlen("0") + 1);

  return 0;
}
