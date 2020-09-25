// Function accepts args as parameter and return 1 to continue the loop() on successful completion with no error
int gcd(char **args)
{
  int n;
  if (args[1] == NULL) {
    fprintf(stderr, "Directory or Path not entered\n");
  } else {
    n = chdir(args[1]); // change the directory to the path specified by argument 1
    if(n == -1){
      printf("No Such dir or path exsist\n");
    }
  }
  return 1;
}