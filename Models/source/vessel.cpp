#include "vessel.hpp"

#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include "material.hpp"

Nave::Nave(){
    x=0.0;
    y=0.0;
    z=0.0;
    _v = (2*M_PI)/(MAX-1);
    armazenaPontos();
}

void Nave::armazenaPontos(){
    int i,j;
    float u,v;

    for(i=0;i<=(MAX-1);i++) {
        for(j=0;j<=(MAX-1);j++) {
            v = j*_v;
            cilindro[i][j].x = 6.75*cos(v);
            cilindro[i][j].y = 6.75*sin(v);
            cilindro[i][j].z = 1.5*i+33.75;
        }
    }

    for(i=0;i<=(MAX-1);i++) {
        u = ((MAX-1)-i)*15/(MAX-1);
        for(j=0;j<=(MAX-1);j++) {
            v = j*_v;
            paraboloide[i][j].x = 0.45*u*cos(v);
            paraboloide[i][j].y = 0.45*u*sin(v);
            paraboloide[i][j].z = 0.15*u*u;
        }
    }

    for(i=0;i<=(MAX-1);i++) {
        u = ((MAX-1)-i)*_v;
        for(j=0;j<=(MAX-1);j++) {
            v = j*_v;
            elipsoide[i][j].x = 2.25*sin(u)*cos(v);
            elipsoide[i][j].y = 2.25*sin(u)*sin(v);
            elipsoide[i][j].z = 6.75*cos(u);
        }
    }
}

void Nave::desenhaMatriz(Ponto pontos[MAX][MAX], int max) {
    int i,j;
    for(i=0;i<max;i++) {
        for(j=0;j<max;j++) {
            glBegin(GL_QUADS);
                glVertex3f(pontos[i][j].x+x,pontos[i][j].y+y,pontos[i][j].z+z);
                glVertex3f(pontos[i+1][j].x+x,pontos[i+1][j].y+y,pontos[i+1][j].z+z);
                glVertex3f(pontos[i+1][j+1].x+x,pontos[i+1][j+1].y+y,pontos[i+1][j+1].z+z);
                glVertex3f(pontos[i][j+1].x+x,pontos[i][j+1].y+y,pontos[i][j+1].z+z);
            glEnd();
        }
    }
}

void Nave::desenhaCabine() {
    glPushMatrix();
        glColor3f(1,1,1);
        glTranslatef(cilindro[20][(MAX-1)/4].x,cilindro[20][(MAX-1)/4].y,cilindro[20][(MAX-1)/4].z);
        desenhaMatriz(elipsoide, MAX-1);
    glPopMatrix();
}

void Nave::desenhaAerofolio() {
    float _x = x + cilindro[MAX-1][(MAX-1)/4-5].x;
    float _y = y + cilindro[MAX-1][(MAX-1)/4-5].y;
    float _z = z + cilindro[MAX-1][(MAX-1)/4-5].z;

    obsidian.active();

    glBegin(GL_QUADS);
        glVertex3f(0+_x,0+_y,0+_z);
        glVertex3f(0+_x,0+_y,-10.5+_z);
        glVertex3f(0.75+_x,4.5+_y,-10.5+_z);
        glVertex3f(1.5+_x,9+_y,0+_z);
    glEnd();

    _x = x + cilindro[MAX-1][(MAX-1)/4+5].x;
    _y = y + cilindro[MAX-1][(MAX-1)/4+5].y;
    _z = z + cilindro[MAX-1][(MAX-1)/4+5].z;

    glBegin(GL_QUADS);
        glVertex3f(0+_x,0+_y,0+_z);
        glVertex3f(0+_x,0+_y,-10.5+_z);
        glVertex3f(-0.75+_x,4.5+_y,-10.5+_z);
        glVertex3f(-1.5+_x,9+_y,0+_z);
    glEnd();
}

void Nave::desenhaAsa(){
    float _x = x + cilindro[(MAX-1)/2][(MAX-1)/2].x;
    float _y = y + cilindro[(MAX-1)/2][(MAX-1)/2].y;
    float _z = z + cilindro[(MAX-1)/2][(MAX-1)/2].z;

    obsidian.active();
    glBegin(GL_POLYGON);
        glVertex3f(13.5+_x,0+_y,-15+_z);
        glVertex3f(43.5+_x,0+_y,0+_z);
        glVertex3f(43.5+_x,0+_y,15+_z);
        glVertex3f(13.5+_x,2.25+_y,15+_z);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex3f(13.5+_x,0+_y,-15+_z);
        glVertex3f(43.5+_x,0+_y,0+_z);
        glVertex3f(43.5+_x,0+_y,15+_z);
        glVertex3f(13.5+_x,-2.25+_y,15+_z);
    glEnd();
    glBegin(GL_TRIANGLES);
        glVertex3f(43.5+_x,0+_y,15+_z);
        glVertex3f(13.5+_x,-2.25+_y,15+_z);
        glVertex3f(13.5+_x,2.25+_y,15+_z);
    glEnd();

    _x = x - cilindro[(MAX-1)/2][(MAX-1)/2].x;
    _y = y + cilindro[(MAX-1)/2][(MAX-1)/2].y;
    _z = z + cilindro[(MAX-1)/2][(MAX-1)/2].z;

    glBegin(GL_POLYGON);
        glVertex3f(-13.5+_x,0+_y,-15+_z);
        glVertex3f(-43.5+_x,0+_y,0+_z);
        glVertex3f(-43.5+_x,0+_y,15+_z);
        glVertex3f(-13.5+_x,2.25+_y,15+_z);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex3f(-13.5+_x,0+_y,-15+_z);
        glVertex3f(-43.5+_x,0+_y,0+_z);
        glVertex3f(-43.5+_x,0+_y,15+_z);
        glVertex3f(-13.5+_x,-2.25+_y,15+_z);
    glEnd();
    glBegin(GL_TRIANGLES);
        glVertex3f(-43.5+_x,0+_y,15+_z);
        glVertex3f(-13.5+_x,-2.25+_y,15+_z);
        glVertex3f(-13.5+_x,2.25+_y,15+_z);
    glEnd();
}

void Nave::desenhaTurbina(){
    int i=0;
    Ponto circulo[MAX];
    float ang;
    for(ang=0; ang<=2*M_PI;ang=i*2*M_PI/(MAX-1)) {
        circulo[i].x=3*cos(ang)+x;
        circulo[i].y=3*sin(ang)+y;
        circulo[i].z=84.75+z;
        i++;
    }

    obsidian.active();

    glBegin(GL_QUAD_STRIP);
        for(i=0;i<MAX-1;i++) {
            glVertex3f(circulo[i].x,circulo[i].y,circulo[i].z);
            glVertex3f(cilindro[MAX-1][i].x+x,cilindro[MAX-1][i].y+y,cilindro[MAX-1][i].z+z);
        }
        glVertex3f(circulo[0].x,circulo[0].y,circulo[0].z);
        glVertex3f(cilindro[MAX-1][0].x+x,cilindro[MAX-1][0].y+y,cilindro[MAX-1][0].z+z);
    glEnd();

    glColor3f(1,0,0);

    glBegin(GL_POLYGON);
        for(i=0;i<MAX-1;i++)
            glVertex3f(circulo[i].x,circulo[i].y,circulo[i].z);
    glEnd();
}

void Nave::refresh() {
    desenhaCabine();
    glColor3f(0.9, 0.0, 0.0);
    desenhaMatriz(paraboloide, MAX-1);
    desenhaMatriz(cilindro, MAX-1);
    glColor3f(0.0, 0.6, 0.0);
    desenhaAsa();
    desenhaAerofolio();
    desenhaTurbina();
 }
