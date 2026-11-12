#ifndef FILAENC_H
#define FILAENC_H

typedef struct filaEnc tFilaEnc;

void insereFilaEnc(tFilaEnc* fila, float amostra);
float retiraFilaEnc(tFilaEnc* fila);

#endif