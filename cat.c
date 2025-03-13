/*
cat - a UNIX command line utility program to concatenate and print files
Date : 13.03.2025
*/
#include "file.h"

int main(int argc, char* argv[]){

  // TODO : handle flags (no flag), -n or -b
  int show_line_count = 0; // true if -n in argv
  for(int i=1;i<argc;i++){
    if(strcmp(argv[i],"-n")==0)
      show_line_count = 1;
  }

  for(int i=1;i<argc;i++){
    const char* path = argv[i];

    FILE* fd;
    if(strcmp(path,"-")==0){
      // Read from stdin
      fd = stdin;
    }else if(strcmp(path,"-n")==0){
      // for flag -n
      continue;
    }else{
      if(validate_path(path)!=0)
        return EXIT_FAILURE;
      
      // Read from path
      fd = fopen(path,"r");
    }

    if(fd == NULL){
      fprintf(stderr,"cat: %s: unexpected error",path);
      return EXIT_FAILURE;
    }

    cat_file(fd,show_line_count);

    if(fd != stdin){
      fclose(fd);
    }
  }
}
