#include "outbuff.h"

char *_outBuffer;
int _bufferLength = 0;

void b_printf(const char* format, ...){
	va_list args;
	va_start(args, format);

	char buffer[_BUFFER_MAX_LENGTH];
	vsprintf(buffer, format, args);
	int bLen = strlen(buffer);
	_b_realloc(_bufferLength + bLen + 1);
	strcat(_outBuffer, buffer);

	va_end(args);
}

void b_flush(void){
	b_fflush(stdout);
}

void b_fflush(FILE* stream){
	fputs(_outBuffer, stream);
}

void b_clear(void){
	free(_outBuffer);
	_bufferLength = 0;
}

void _b_realloc(const int length){
	if(_bufferLength == 0){
		_bufferLength = (length < _OUT_BUFFER_MIN_LENGTH) ? _OUT_BUFFER_MIN_LENGTH : length;
		_outBuffer = (char*)malloc(_bufferLength);
	}else{
		while(_bufferLength < length) _bufferLength *= _OUT_BUFFER_GROW_COEFICIENT;
		_outBuffer = (char*)realloc(_outBuffer, _bufferLength);
	}
}