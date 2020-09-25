int count_args(char **cmd_list){
    int i=0;
    while(cmd_list[i]!=NULL){
        i++;
    }
    return i;
} // Function to give the number of arguments

int gmkdir(char **args){

    int argc = count_args(args);
    int flag_check; 
    int position = 1;
    if(argc<2){
        printf("Format : gmkdir <dir1_path> <dir2_path> ......\n");
    }// In case of less arguments than expected
    while(position<argc){
        char* dirname = args[position]; // Getting the directory name
    
	    flag_check = mkdir(dirname,0777); // Making directory using system call mkdir() with user permission
	  
		// check if directory is created or not 
	if (!flag_check) // Check if directory is created or not
	    printf("%d Directory created Successfully\n",position); 
	else { 
	    printf("Unable to create the directory %d\n",position);  
	}
    position++;
    }
    return 1;
}