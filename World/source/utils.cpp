// utils.cpp
// Projeto "River Raid"

#include "utils.hpp"

#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

namespace Utils {

    void especificaParametrosVisualizacao(GLint x, GLint y, GLint z)
    {
        // Especifica sistema de coordenadas de projecao
        glMatrixMode(GL_PROJECTION);
        // Inicializa sistema de coordenadas de projecao
        glLoadIdentity();

        // Especifica a projecao perspectiva
        gluPerspective(angle,fAspect,0.4,1600);

        // Especifica sistema de coordenadas do modelo
        glMatrixMode(GL_MODELVIEW);
        // Inicializa sistema de coordenadas do modelo
        glLoadIdentity();

        // Especifica posição do observador e do alvo
        gluLookAt(x, y, z, 0,0,0, 0,1,0);
    }

    void inicializaIluminacao() {
        // Define parametros de iluminacao
        GLfloat luzAmbiente[4]={0.2,0.2,0.2,1.0};
        GLfloat luzDifusa[4]={0.7,0.7,0.7,1.0};
        GLfloat luzEspecular[4]={0.2, 0.2, 0.2, 1.0};
        GLfloat posicaoLuz[4]={0.0, 150.0, 0.0, 1.0};

        // Capacidade de brilho do material
        GLfloat especularidade[4]={1.0,1.0,1.0,1.0};
        GLint especMaterial = 60;

        // Especifica que a cor de fundo da janela sera branca
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

        // Habilita o modelo de colorização de Gouraud
        glShadeModel(GL_SMOOTH);

        // Define a refletancia do material
        glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);
        // Define a concentracao do brilho
        glMateriali(GL_FRONT,GL_SHININESS,especMaterial);

        // Ativa o uso da luz ambiente
        glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

        // Define os parametros da luz de numero 0
        glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
        glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz );
        glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
        glLightfv(GL_LIGHT2, GL_SPECULAR, luzEspecular );

        // Habilita a definicao da cor do material a partir da cor corrente
        glEnable(GL_COLOR_MATERIAL);
        // Habilita o depth-buffering
        glEnable(GL_DEPTH_TEST);

        // Habilita iluminacao para exibir os objetos
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);
    }

    void desenhaParalelepipedo (float *x, float *y, float *z) {
        // Face superior
        glBegin(GL_QUADS);
            glVertex3i(x[0], y[1], z[0]);
            glVertex3i(x[0], y[1], z[1]);
            glVertex3i(x[1], y[1], z[1]);
            glVertex3i(x[1], y[1], z[0]);
        glEnd();

        // Face inferior
        glBegin(GL_QUADS);
            glVertex3i(x[0], y[0], z[0]);
            glVertex3i(x[0], y[0], z[1]);
            glVertex3i(x[1], y[0], z[1]);
            glVertex3i(x[1], y[0], z[0]);
        glEnd();

        // Face lateral direita
        glBegin(GL_QUADS);
            glVertex3i(x[1], y[0], z[0]);
            glVertex3i(x[1], y[1], z[0]);
            glVertex3i(x[1], y[1], z[1]);
            glVertex3i(x[1], y[0], z[1]);
        glEnd();

        // Face lateral esquerda
        glBegin(GL_QUADS);
            glVertex3i(x[0], y[0], z[0]);
            glVertex3i(x[0], y[1], z[0]);
            glVertex3i(x[0], y[1], z[1]);
            glVertex3i(x[0], y[0], z[1]);
        glEnd();

        // Face anterior
        glBegin(GL_QUADS);
            glVertex3i(x[0], y[0], z[0]);
            glVertex3i(x[0], y[1], z[0]);
            glVertex3i(x[1], y[1], z[0]);
            glVertex3i(x[1], y[0], z[0]);
        glEnd();

        // Face posterior
        glBegin(GL_QUADS);
            glVertex3i(x[0], y[0], z[1]);
            glVertex3i(x[0], y[1], z[1]);
            glVertex3i(x[1], y[1], z[1]);
            glVertex3i(x[1], y[0], z[1]);
        glEnd();
    }

    void desenhaTronco(float *c1, float r1, float *c2, float r2) {
        float angulo;
        float step;
        step = 10.0;

        for(angulo=0.0f; angulo<360; angulo+=step) {
            glBegin(GL_POLYGON);
                glVertex3f(r1*cos(angulo*M_PI/180)+c1[0], r1*sin(angulo*M_PI/180)+c1[1], c1[2]);
                glVertex3f(r1*cos((angulo+step)*M_PI/180)+c1[0], r1*sin((angulo+step)*M_PI/180)+c1[1], c1[2]);
                glVertex3f(r2*cos((angulo+step)*M_PI/180)+c2[0], r2*sin((angulo+step)*M_PI/180)+c2[1], c2[2]);
                glVertex3f(r2*cos(angulo*M_PI/180)+c2[0], r2*sin(angulo*M_PI/180)+c2[1], c2[2]);
            glEnd();
        }
        glBegin(GL_POLYGON);
            for(angulo=0.0f; angulo<360; angulo+=step)
                glVertex3f(r1*cos(angulo*M_PI/180)+c1[0], r1*sin(angulo*M_PI/180)+c1[1], c1[2]);
        glEnd();
        glBegin(GL_POLYGON);
            for(angulo=0.0f; angulo<360; angulo+=step)
                glVertex3f(r2*cos(angulo*M_PI/180)+c2[0], r2*sin(angulo*M_PI/180)+c2[1], c2[2]);
        glEnd();
    }

    void desenhaPlano(float *x, float *y, float *z) {
        glBegin(GL_QUADS);
            glVertex3i(x[0], y[0], z[0]);
            glVertex3i(x[1], y[1], z[1]);
            glVertex3i(x[2], y[2], z[2]);
            glVertex3i(x[3], y[3], z[3]);
        glEnd();
    }
}
