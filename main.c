#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define timeout usleep(1100000);

typedef struct envs {
  char *users;
  uint euid;

} ENV;
ENV env;

int main() {
  timeout;
  fprintf(stderr, "hello.\n");
  timeout;
  fprintf(stderr, "I know who you are\n");
  timeout;
  env.users = getenv("USER");
  fprintf(stderr, "You are %s\n", env.users);
  timeout;
  fprintf(stderr, "Matter of fact, let's see if you have admin privileges.\n");
  timeout;
  env.euid = geteuid();
  fprintf(stderr, "Your euid is %d\n", env.euid);
  timeout;
  switch (env.euid) {
  case 0:
    // we can execute some nasty stuff now...
    fprintf(stderr, "you really... you're root...\n");
    timeout;
    fprintf(stderr, "now we can do nasty things like start system processes, "
                    "overwrite system files, some pretty malicious stuff.\n");
    timeout;
    fprintf(stderr, "This is only a theoretical program however, I wouldn't do "
                    "such a thing.\n");
    break;

  default:
    // do a normal thing...
    fprintf(stderr, "You aren't root huh.\n");
    timeout;
    fprintf(stderr,
            "You can't do too much here. If I were a malicious program, I "
            "would just do a normal non-malicious process.\n");
    break;
  }
  timeout;

  return 0;
};
