#include <stdio.h>
#include <syscall-nr.h>
//#include <sched.h>
#include "threads/interrupt.h"
#include "devices/shutdown.h"
#include "threads/thread.h"
#include "../threads/thread.h"
#include "process.h"
#include "../filesys/filesys.h"
#include "../threads/interrupt.h"
#include "../lib/kernel/list.h"
#include "../threads/malloc.h"
#include "threads/vaddr.h"
#include "pagedir.h"
#include "../devices/input.h"
#include "../filesys/file.h"
#include "../lib/kernel/stdio.h"
#include "userprog/syscall.h"
#include "vm/paging.h"
#include "userprog/exception.h"
#include "exception.h"
#include "../vm/paging.h"
#include "../lib/syscall-nr.h"
#include "../threads/palloc.h"

#ifndef PROJECT4_FILES_H
#define PROJECT4_FILES_H
unsigned tell_sys (int fd);
bool create_sys (const char *file, unsigned initial_size);
bool remove_sys (const char *file);
int open_sys (const char *file_name, bool readonly);
int filesize_sys (int fd);
unsigned tell_sys (int fd);
void close_sys (int fd);
int read_sys (int fd, void * buffer, unsigned size);
int write_sys (int fd , const void * buffer , unsigned size);
void seek_sys (int fd, unsigned position);
int file_reopen_sys(int fd);

bool chdir (const char * dir);
bool mkdir (const char * dir);
bool readdir (int fd , char * name);
bool isdir (int fd);
int inumber (int fd);
#endif //PROJECT4_FILES_H
