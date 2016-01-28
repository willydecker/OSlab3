#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    printf("--beginning of program\n");

    int counter = 0;
    int Child1 = 0;
    int Child2 = 0;

    pid_t pid = fork();

    if(pid == 0)
    {
        // child processes
        pid_t pid = fork();
        if (pid == 0)
        {
          int pidC1 = getpid();
          Child1 = pidC1;
          int number = 4;
          int divider = 2;
          printf("\nChild process 2 reporting in with pid of %d.\n", pidC1);
          printf("This is 4: %d\n", number);
          printf("This is 2: %d\n", divider);
          printf("This is 4/2: %d\n", (number/divider));
          printf("--end of child 2--\n");
          exit(0);
        }
        else
        {
          int pidC2 = getpid();
          Child2 = pidC2;
          printf("\nChild process 1 reporting in with pid of %d.\nReady to divide by 0.\n", pidC2);
          //int crash = 9/0;
          printf("Crashing now!\n");
          printf("--end of child 1--\n");
          exit(0);
        }
    }

    else
    {
      printf("Im the parent, but I dont know how to wait \nfor my kids or exit the program.\n");
    }

    return 0;
}
