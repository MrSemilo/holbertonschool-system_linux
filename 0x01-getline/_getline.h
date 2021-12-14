#ifndef _GETLINE_H_
#define _GETLINE_H_

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define READ_SIZE 1024

/**
 * struct  reader_s - readers
 *
 * @fd: fd
 * @buf: buf
 * @bytes: bytes
 * @next: next
 **/
typedef struct reader_s
{
	int fd;
	char *buf;
	int bytes;
	struct reader_s *next;
} reader_t;

char *_getline(const int fd);
char *_line(reader_t *rd);

#endif
