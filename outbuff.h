#ifndef __OUT_BUFFER__
#define __OUT_BUFFER__

// Buffer length for result of sprintf
#define _BUFFER_MAX_LENGTH 1024

#define _OUT_BUFFER_MIN_LENGTH 256
#define _OUT_BUFFER_GROW_COEFICIENT 2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

// Global
extern char *_outBuffer;
extern int _bufferLength;

// Printf to the global buffer
void b_printf(const char*, ...);

// Flush the global buffer to stdout
void b_flush(void);

// Flush the global buffer to a file
void b_fflush(FILE*);

// Clears the global buffer
void b_clear(void);


// Internal
void _b_realloc(const int);

#endif