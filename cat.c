/*
cat - a UNIX command line utility program to concatenate and print files
Date : 13.03.2025
*/
#include <stdio.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>

int main(int argc, char* argv[]){
  if(argc==1 || (argc == 2 && strcmp(argv[1],"-")==0)){
    FILE* fd = stdin;
    char buffer[1024];

    while(fgets(buffer,sizeof(buffer),fd)!=NULL){
      printf("%s",buffer);
    }
    return 0;
  }else if(argc == 2){
    printf("%s",argv[1]);
    char* file_path = argv[1];
    FILE* fd = fopen(file_path,"r");

    struct stat path_stat;
    if(stat(file_path,&path_stat)==-1){
      fprintf(stderr,"cat: %s\n", strerror(errno));
      return 1;
    }

    if(S_ISDIR(path_stat.st_mode)){
      fprintf(stderr,"cat: %s: Is a directory\n",file_path);
      return 1;
    }

    char buffer[1024];

    while(fgets(buffer,sizeof(buffer),fd)!=NULL){
      printf("%s",buffer);
    }
    fclose(fd);
  }
  return 0;
}
