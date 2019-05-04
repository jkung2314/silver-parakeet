#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

int main(int argc, char *argv[]) {
  int j, i = 0, length = atoi(argv[1]);
  long int sec, usec;
  FILE *fp;
  struct timeval start, end;

  gettimeofday(&start, NULL);

  while (i < length) {
    j = i * 1;
    i++;
  }

  gettimeofday(&end, NULL);
  sec = end.tv_sec - start.tv_sec;
  usec = end.tv_usec - start.tv_usec;

  if (usec < 0) {
    sec--;
    usec = 1000000 + usec;
  }

  fp = fopen(argv[3], "a");
  fprintf(fp, "finished process %s in %ld.%ld seconds\n", argv[2], sec, usec);
  fclose(fp);

  return 0;
}
