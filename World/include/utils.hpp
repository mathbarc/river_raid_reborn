// utils.cpp
// Projeto "River Raid"
#ifndef UTILS_HPP
#define UTILS_HPP

#include <GL/gl.h>


namespace Utils {
    static GLfloat angle = 45;
    static GLfloat fAspect = 16.f/9.f;
	
    void especificaParametrosVisualizacao(GLint x, GLint y, GLint z);
    void inicializaIluminacao();
    void desenhaParalelepipedo (float *x, float *y, float *z);
    void desenhaTronco(float *c1, float r1, float *c2, float r2);
    void desenhaPlano(float *x, float *y, float *z);
}

#endif
