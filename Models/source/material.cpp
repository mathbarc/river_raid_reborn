#include "material.hpp"

Material::Material(GLfloat ar, GLfloat ag, GLfloat ab, GLfloat dr, GLfloat dg, GLfloat db, GLfloat sr, GLfloat sg, GLfloat sb)
{
    ambient_r=ar;   ambient_g=ag;   ambient_b=ab;
    diffuse_r=dr;   diffuse_g=dg;   diffuse_b=db;
    specular_r=sr;  specular_g=sg;  specular_b=sb;
}

void Material::active()
{

    GLfloat ambient[]={ambient_r, ambient_g, ambient_b, 1.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
    GLfloat diffuse[]={diffuse_r, diffuse_g, diffuse_b};
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
    GLfloat specular[]={specular_r, specular_g, specular_b};
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

}


