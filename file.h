#pragma once
#ifndef FILE_H
#define FILE_H

#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

int validate_path(const char* path);
void cat_file(FILE *fd, int show_line_count);

#endif
