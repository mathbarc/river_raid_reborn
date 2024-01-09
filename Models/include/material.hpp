 
#ifndef MATERIAL_HPP
#define MATERIAL_HPP
#include <GL/gl.h>



class Material{

  private:

    GLfloat ambient_r;
    GLfloat ambient_g;
    GLfloat ambient_b;

    GLfloat diffuse_r;
    GLfloat diffuse_g;
    GLfloat diffuse_b;

    GLfloat specular_r;
    GLfloat specular_g;
    GLfloat specular_b;


    public:

        Material(GLfloat ar, GLfloat ag, GLfloat ab, GLfloat dr, GLfloat dg, GLfloat db, GLfloat sr, GLfloat sg, GLfloat sb);

        void active();
};

static Material turquesa(0.1, 0.18725, 0.1745, 0.396, 0.74151, 0.69102, 0.297254, 0.30829, 0.306678);
static Material esmeralda(0.0215, 0.1745, 0.0215, 0.07568, 0.61424, 0.07568, 0.633, 0.727811, 0.633);
static Material jade(0.135, 0.2225, 0.1575, 0.54, 0.89, 0.63, 0.316228, 0.316228, 0.316228);
static Material obsidian(0.05375, 0.05, 0.06625, 0.18275, 0.17, 0.22525, 0.332741, 0.328634, 0.346435);

#endif
