#include "file.h"

int validate_path(const char* path){
  struct stat path_stat;
  if(stat(path,&path_stat)==-1){
   fprintf(stderr,"cat: %s\n", strerror(errno));
   return -1;
  }

  if(S_ISDIR(path_stat.st_mode)){
    fprintf(stderr,"cat: %s: Is a directory\n",path);
    return -1;
  }

  return 0;
}

void cat_file(FILE *fd, flags* flag){
  char buffer[1024];
  int line_count = 0;

  while(fgets(buffer,sizeof(buffer),fd)){
    char *trimmed = buffer + strspn(buffer, " \t\n");

    if(flag->FLAG_N!=0){
      printf("%d  %s",++line_count,buffer);
    }else if(flag->FLAG_B !=0){
      if (*trimmed != '\0') {  
        printf("%d  %s", ++line_count, buffer);
      } else {
        printf("%s", buffer); 
      }
    }else{
      printf("%s",buffer);
    }
  }
}