#include "types.h"
#include "stat.h"
#include "user.h"

char buf[512];

// void
// cpt(int fd_dest)
// {
//   int n;

//   while((n = read(fd, buf, sizeof(buf))) > 0) {
//     if (write(1, buf, n) != n) {
//       printf(1, "cat: write error\n");
//       exit();
//     }
//   }
//   if(n < 0){
//     printf(1, "cat: read error\n");
//     exit();
//   }
// }

void
cpt(int fd_src, int fd_dest)
{
    int n;

  while((n = read(fd_src, buf, sizeof(buf))) > 0) {
      int adad = write(fd_dest, buf, n);
      printf(1, "adad: %d\n", adad);
      printf(1, "n: %d\n", n);
    if (write(fd_dest, buf, n) != n) {
      printf(1, "cpt: write error\n");
      exit();
    }
  }
  if(n < 0){
    printf(1, "cpt: read error\n");
    exit();
  }
}

int
main(int argc, char *argv[])
{
  int fd;

  if(argc <= 1){
    printf(1, "cpt: missing file operand :/\n");
    exit();
  }

  if(argc == 2){
    if((fd = open(argv[1], 0)) < 0){
        printf(1, "cpt: cannot open %s :/\n", argv[1]);
        exit();
    }
    cpt(0, 2);
    close(fd);
  }

//   for(i = 1; i < argc; i++){
//     if((fd = open(argv[i], 0)) < 0){
//       printf(1, "cat: cannot open %s\n", argv[i]);
//       exit();
//     }
//     cpt(fd);
//     close(fd);
//   }
  exit();
}
