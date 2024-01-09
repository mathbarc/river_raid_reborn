#include "ship.hpp"
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include "utils.hpp"


Navio::Navio() {
    x=0.0;
    y=0.0;
    z=0.0;
}

void Navio::refresh() {
    // Proa
    glColor3f(0.3, 0.3, 0.3);
    float proa_dir_x[] = { 0.0f+x, 24.0f+x, 0.0f+x, 0.0f+x };
    float proa_dir_y[] = { 30.0f+y, 30.0f+y, 0.0f+y, 0.0f+y };
    float proa_dir_z[] = { -90.0f+z, -30.0f+z, -30.0f+z, -30.0f+z };
    Utils::desenhaPlano(proa_dir_x, proa_dir_y, proa_dir_z);

    glColor3f(0.4, 0.4, 0.4);
    float proa_esq_x[] = { 0.0f+x, -24.0f+x, 0.0f+x, 0.0f+x };
    float proa_esq_y[] = { 30.0f+y, 30.0f+y, 0.0f+y, 0.0f+y };
    float proa_esq_z[] = { -90.0f+z, -30.0f+z, -30.0f+z, -30.0f+z };
    Utils::desenhaPlano(proa_esq_x, proa_esq_y, proa_esq_z);

    // Laterais
    glColor3f(0.4, 0.4, 0.4);
    float lateral_dir_x[] = { 24.0f+x, 24.0f+x, 0.0f+x, 0.0f+x };
    float lateral_dir_y[] = { 30.0f+y, 30.0f+y, 0.0f+y, 0.0f+y };
    float lateral_dir_z[] = { -30.0f+z, 90.0f+z, 75.0f+z, -30.0f+z };
    Utils::desenhaPlano(lateral_dir_x, lateral_dir_y, lateral_dir_z);

    glColor3f(0.3, 0.3, 0.3);
    float lateral_esq_x[] = { -24.0f+x, -24.0f+x, 0.0f+x, 0.0f+x };
    float lateral_esq_y[] = { 30.0f+y, 30.0f+y, 0.0f+y, 0.0f+y };
    float lateral_esq_z[] = { -30.0f+z, 90.0f+z, 75.0f+z, -30.0f+z };
    Utils::desenhaPlano(lateral_esq_x, lateral_esq_y, lateral_esq_z);

    // Popa
    glColor3f(0.2, 0.2, 0.2);
    float popa_x[] = { 24.0f+x, -24.0f+x, 0.0f+x, 0.0f+x };
    float popa_y[] = { 30.0f+y, 30.0f+y, 0.0f+y, 0.0f+y };
    float popa_z[] = { 90.0f+z, 90.0f+z, 75.0f+z, 75.0f+z };
    Utils::desenhaPlano(popa_x, popa_y, popa_z);

    // Conves
    glColor3f(0.8, 0.8, 0.8);
    float conves1_x[] = { 21.0f+x, -21.0f+x, -21.0f+x, 21.0f+x };
    float conves1_y[] = { 27.0f+y, 27.0f+y, 27.0f+y, 27.0f+y };
    float conves1_z[] = { -30.0f+z, -30.0f+z, 87.0f+z, 87.0f+z };
    Utils::desenhaPlano(conves1_x, conves1_y, conves1_z);
    float conves2_x[] = { 21.0f+x, -21.0f+x, 0.0f+x, 0.0f+x };
    float conves2_y[] = { 27.0f+y, 27.0f+y, 27.0f+y, 27.0f+y };
    float conves2_z[] = { -30.0f+z, -30.0f+z, -84.0f+z, -84.0f+z };
    Utils::desenhaPlano(conves2_x, conves2_y, conves2_z);


}
