#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h> 
#include <fcntl.h>
#include <sys/stat.h>

// Header files for commands defined manually 
#include "gls.h"
#include "gcd.h"
#include "ggrep.h"
#include "gcat.h"
#include "gmv.h"
#include "gpwd.h"
#include "gcp.h"
#include "gmkdir.h"

// sentence_size == size of the command one user can enter (Global)
// separator is used in string tokienization (Global)
#define sentence_size 1024
#define separator " \t\r\n\a&"

// Functions defined for user commands
int gcd(char **args);
int help(char **args);
int gexit(char **args);
int ggrep(char **args);
int gls(char **args);
int gcat(char **args);
int gmv(char **args);
int gpwd(char **args);
int grm(char **args);
int gcp(char **args);
int gmkdir(char **args);
 
// Information helper function for user using this Terminal accessible using help command
int help(char **args)
{
  int i;
  system("clear");
  printf("\nThis is a Custom Shell written in C programming Language\n\n");
  printf("Custom Commands added - gcat, gcd, ggrep, gls, gmv, gcp, gpwd, gmkdir.\n\n");
  printf("All Custom Commands are simple ones ex. gcat is a simpler version of cat and lly for other cmds.\n\n");
  printf("\n--------------------Have Fun--------------------\n\n");
  return 1;
}
// exit command used for leaving the terminal process
int gexit(char **args)
{
  printf("Exiting.........\n");
  exit(EXIT_SUCCESS);
  return 0;
} 
/* Arguments list which are defined manually(means no builtins)..... (Global)

All commands working is the simple case working of different terminal commands 
For ex. ggrep == grep, gcd == cd, gls == ls, gmv == mv...etc
*/

char *myArgs_list[] = {
  "help",
  "gexit",
  "gmkdir",
  "gcd",
  "gls",
  "gmv",
  "ggrep",
  "gcat",
  "gcp",
  "gpwd"
};
// Manually defined arguments list length (Global) 
int myArgs_list_size = sizeof(myArgs_list)/sizeof(char*);

// function to tokenize or split the sentence into its words or equivalently command into arguments.
// Parameter sentence is accepted from the user using fgets() in main().
char** split_sentence(char *sentence){
  char **args_list = malloc(sentence_size*sizeof(char*)); // Defining argument character array with column 1024 with each box of bits equal to bits of char
  char *token; // word or token extracted from the sentence or command
  int index=0; // index for storing the tokens in args_list

  if(!args_list){ // Failure in the Memory allocation of args_list
    fprintf(stderr,"Memory allocation Failed\n");
    exit(EXIT_FAILURE); // exit(EXIT_FAILURE) ensures the termination of the process 
  }
  token= strtok(sentence,separator); // strtok() accepts the string with the delimiters on basis of which the command to be splitted into words
  // strtok() returns a pointer to the next token and NULL if no token exsist. 
  while(token!=NULL){ // Checking if the tokens are finished or not in the string
    args_list[index] = token; // stroing the tokens in the args_list
    index++; // incrementing index to store unique tokens in unique places in the args_list
    token = strtok(NULL,separator); // Take pointer to the next token
  }
  args_list[index]=NULL; // Stroing NULL at the last
  return args_list; // Complete args_list with all arguments
}


int builtin(char **args) // Builtin function to run commands which are not defined by the user 
{
  int rc,wait; //rc flag to ensure the creation of child process, wait flag for storing the successful run of child as child pid or an error as -1
  int status; // ensure that the command is ran successfully with no error and carry on the loop in main() using this status
  rc=fork(); // creating Parent and Child Processes
  if(rc<0){  // child not created
      fprintf(stderr,"FORK NOT WORKING\n"); 
  }
  else if(rc==0){ // Child process
  /*
execvp() -- second argument is an array of null-terminated strings that represent
 the appropriate arguments to the file as specified in the man page.
   executing the builtin command args[0] represent the file you want to execute
  */
      if(execvp(args[0],args)==-1){
          fprintf(stderr,"Enter the correct command\n");
      }
  }else{
      do{ 
          wait=waitpid(rc, &status, WUNTRACED); // wait() command waits for the process to change the state
      }while(!WIFEXITED(status) && !WIFSIGNALED(status));
    // WIFEXITED returns true if the child terminated normally.
    // WIFSIGNALED returns true if the child process was terminated by a signal.
    // WUNTRACED also  return if a child has stopped.
  }
  return 1; // Indicates the successful running of the command and allowing loop in main to carry further commands
}
// Function which either run defined commands or the builtin command
// Parameter accepted is args which came from the splitting function split_sentence()

int redirect(char **args){
    if(args[0] == NULL){
        return 1;   
    } // If no command is entered and user press simply enter then status == 1 retured, to continue the loop in main()

    for(int i=0;i<myArgs_list_size;i++) 
    {
      /*Checking if the entered command argument matches with the argument defined
        If yes, then run the user defined command defined in myArgsList[]
        If not, then run builtin binary commands defined.
      */
        if(strcmp(args[0],myArgs_list[i])==0){ //Commands comparison using stringCompare strcmp()
            switch (i)
            {
            case 0:
                return help(args);
                
            case 1:
                return gexit(args);
                
            case 2:
                return gmkdir(args);
                
            case 3:
                return gcd(args);
                
            case 4:
                return gls(args);
                
            case 5:
                return gmv(args);
                
            case 6:
                return ggrep(args);
                
            case 7:
                return gcat(args);
            case 8:
                return gcp(args);
            case 9:
                return gpwd(args);   
            default:
                break;
            }
        }
    }
    return builtin(args); // If no command matches then run the builtin command
    
}
int check_chracter(char *input){
    char *output = NULL;
    output = strrchr(input, '&');

    if(output != NULL){
        return 1;
    }
    return 0;
}


int main(int argc, char const *argv[])
{
  /*Loop which continues and waiting for 
  command to enter and can be 
  terminated by using exit command (defined above) 
  or ctrl+C keyboard intterupt
  */
  system("clear"); // Used to clear the terminal screen
  printf("--Welcome to Lovepreet's Shell--\n\n");

  char  **args; // Used to store the arguments splitted from the command entered in the terminal
  int n_args; // Number of arguments or words splitted
  int status; // Status of command whether ran correct or not
  char* sentence = malloc(sentence_size); // stores the input from the user entered in the terminal

  do{
    char dir[500]; // Character array defined to store the current directory
    ssize_t size = 500; // size command for the getcwd()
    getcwd(dir, size); // Storing the current working directory into dir char array of size 500
    printf("%s > ", dir); // Print the current directory on the terminal
    
    fgets(sentence,sentence_size,stdin);// Read the input from the terminal entered by the user
    int flag = check_chracter(sentence); // Check if & is present or not to run commands in background
    // printf("Flag : %d\n", flag);
    if(flag){ 
      int rc = fork();
      if(rc < 0){ // Child creation Failed
        perror("Fork Failed\n"); 
      }
      else if(rc == 0){ // Child process
        args = split_sentence(sentence); // splitting the sentence entered by the user.
        n_args = sizeof(args)/sizeof(char); // Number of tokens splitted from the whole inputted command
        status = redirect(args); // redirect to a function which will run either a command defined or a builtin binary command
        free(args);
      }
      else{
        status = 1;
        continue;
      }
    }else{ // Process running not in background
        args = split_sentence(sentence); // splitting the sentence entered by the user.
        n_args = sizeof(args)/sizeof(char); // Number of tokens splitted from the whole inputted command
        status= redirect(args); // redirect to a function which will run either a command defined or a builtin binary command

        free(args); // Memory free from the storage of the earlier entered arguments
    }
        
    }while(status); // Make the loop running until error doesn't occur (fork failed or memory allocation error) or process not interrupted
 
  return 0;
}