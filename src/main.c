#include "../head/args.h"


int main (int argc, char** argv) {
  args my_args;
  init_args (&my_args);

  verif_args(&my_args, argc, argv);

  return 0;
}
