#pragma once
#ifndef FILE_H
#define FILE_H

#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

typedef struct flags{
  int FLAG_NO;
  int FLAG_N;
  int FLAG_B;
} flags;

int validate_path(const char* path);
void cat_file(FILE *fd, flags* flag);

#endif
