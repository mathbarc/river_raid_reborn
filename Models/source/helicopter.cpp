// helicoptero.cpp
// Projeto "River Raid"

#include "helicopter.hpp"
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

#include "utils.hpp"


Helicoptero::Helicoptero() {
    angulo=0.0;

    x=0.0;
    y=0.0;
    z=0.0;
}

void Helicoptero::refresh() {
    // Corpo
    glColor3f(0.0, 0.5, 0.0);
    float corpo1[] = { 0.0f+x, 0.0f+y, 0.0f+z };
    float corpo2[] = { 0.0f+x, 0.0f+y, 10.0f+z };
    Utils::desenhaTronco(corpo1, 5.0, corpo2, 5.0);

    // Traseira
    float traseira1[] = { 0.0f+x, 0.0f+y, 10.0f+z };
    float traseira2[] = { 0.0f+x, 3.5f+y, 13.0f+z };
    Utils::desenhaTronco(traseira1, 5.0, traseira2, 1.5);

    // Cauda
    float cauda1[] = { 0.0f+x, 3.5f+y, 13.0f+z };
    float cauda2[] = { 0.0f+x, 4.0f+y, 30.0f+z };
    Utils::desenhaTronco(cauda1, 1.5, cauda2, 1.0);

    // Eixo do rotor principal
    glColor3f(0.2, 0.2, 0.2);
    glPushMatrix();
        glTranslatef(0.0f+x, 9.0f+y, 5.0f+z);
        glRotatef(90, 1.0, 0.0, 0.0);
        float eixorotor1[] = { 0.0, 0.0, 0.0 };
        float eixorotor2[] = { 0.0, 0.0, 2.0 };
        Utils::desenhaTronco(eixorotor1, 0.5, eixorotor2, 0.5);
    glPopMatrix();

    // Eixo da helice da cauda
    glPushMatrix();
        glTranslatef(-2.0f+x, 5.0f+y, 30.0f+z);
        glRotatef(90, 0.0, 1.0, 0.0);
        float eixohcauda1[] = { 0.0, 0.0, 0.0 };
        float eixohcauda2[] = { 0.0, 0.0, 1.5 };
        Utils::desenhaTronco(eixohcauda1, 0.5, eixohcauda2, 0.5);
    glPopMatrix();

    // Cabine
    glPushMatrix();
        glTranslatef(x, y, z);
        glColor3f(0.0f, 0.0f, 0.0f);
        glutSolidSphere(4.9f, 20, 20);
    glPopMatrix();

    // Saida para o rotor (motor)
    float motor1[] = { 0.0f+x, 4.0f+y, 2.0f+z };
    float motor2[] = { 0.0f+x, 4.0f+y, 10.0f+z };
    Utils::desenhaTronco(motor1, 3.0, motor2, 3.0);

    // Desenha helice
    glPushMatrix();
        glTranslatef(0.0f+x, 0.0f+y, 5.0f+z);
        glRotatef(angulo, 0.0, 1.0, 0.0);
        float xhelice1[] = { -25.0, 25.0 };
        float yhelice1[] = { 8.0, 8.5 };
        float zhelice1[] = { -1.0, 1.0 };
        Utils::desenhaParalelepipedo(xhelice1, yhelice1, zhelice1);
    glPopMatrix();

    // Helice da cauda
    glPushMatrix();
        glTranslatef(-1.5f+x, 5.0f+y, 30.0f+z);
        glRotatef(2*angulo, 1.0, 0.0, 0.0);
        float xhcauda[] = { 0.0, 0.5 };
        float yhcauda[] = { -3.0, 3.0 };
        float zhcauda[] = { -1.0, 1.0 };
        Utils::desenhaParalelepipedo(xhcauda, yhcauda, zhcauda);
    glPopMatrix();

    // Leme da cauda
    glPushMatrix();
        glTranslatef(0.0f+x, 4.0f+y, 30.0f+z);
        float xleme[] = { -1.0, 0.0 };
        float yleme[] = { -3.0, 4.0 };
        float zleme[] = { -1.0, 1.0 };
        Utils::desenhaParalelepipedo(xleme, yleme, zleme);
    glPopMatrix();

    // Apoios
    glPushMatrix();
        float apoiodireito1[] = { 2.5f+x, -7.0f+y, 1.0f+z };
        float apoiodireito2[] = { 2.5f+x, -7.0f+y, 10.0f+z };
        Utils::desenhaTronco(apoiodireito1, 0.5, apoiodireito2, 0.5);

        glTranslatef(0.0f+x, -2.5f+y, 5.0f+z);
        glRotatef(90, 1.0, 0.0, 0.0);
        glRotatef(30, 0.0, 1.0, 0.0);
        float apoiodireito3[] = { 0.0, 0.0, 0.0 };
        float apoiodireito4[] = { 0.0, 0.0, 5.0 };
        Utils::desenhaTronco(apoiodireito3, 0.5, apoiodireito4, 0.5);
    glPopMatrix();

    glPushMatrix();
        float apoioesquerdo1[] = { -2.5f+x, -7.0f+y, 1.0f+z };
        float apoioesquerdo2[] = { -2.5f+x, -7.0f+y, 10.0f+z };
        Utils::desenhaTronco(apoioesquerdo1, 0.5, apoioesquerdo2, 0.5);

        glTranslatef(0.0f+x, -2.5f+y, 5.0f+z);
        glRotatef(90, 1.0, 0.0, 0.0);
        glRotatef(-30, 0.0, 1.0, 0.0);
        float apoioesquerdo3[] = { 0.0, 0.0, 0.0 };
        float apoioesquerdo4[] = { 0.0, 0.0, 5.0 };
        Utils::desenhaTronco(apoioesquerdo3, 0.5, apoioesquerdo4, 0.5);
    glPopMatrix();
}

