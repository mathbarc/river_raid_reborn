// main.cpp
// Projeto "River Raid"

#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include "utils.hpp"
#include "vessel.hpp"
#include "helicopter.hpp"
#include "ship.hpp"

// Coordenadas da posicao da camera
GLint xeyes;
GLint yeyes;
GLint zeyes;

// Dimensoes da Janela
GLint windowHeight;
GLint windowWidth;

// Helicoptero
Helicoptero helicoptero1;

// Navio
Navio navio1;

// Nave
Nave nave;

// Funcao callback chamada para fazer o desenho
void Desenha(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	// Objeto solido
		Utils::especificaParametrosVisualizacao(xeyes, yeyes, zeyes);
		
		// Linha de agua
		glColor3f(0.5, 0.5, 0.8);
		float mar_x[] = { 800.0, -800.0, -800.0, 800.0 };
		float mar_y[] = { 0.0, 0.0, 0.0, 0.0 };
		float mar_z[] = { -800.0, -800.0, 800.0, 800.0 };
		Utils::desenhaPlano(mar_x, mar_y, mar_z);
		
		helicoptero1.refresh();
		navio1.refresh();
		nave.refresh();
	
	glutSwapBuffers();
 }

// Inicializa parametros de rendering
void Inicializa (void)
{ 
    xeyes = -150;
    yeyes = 90;
    zeyes = -160;
    
	Utils::inicializaIluminacao();
	
	navio1.y = -1;
	helicoptero1.y = 50;
	nave.y = 75;
}

// Funcao callback chamada quando o tamanho da janela eh alterado 
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
	// Para previnir uma divisao por zero
	if ( h == 0 ) h = 1;
	glViewport(0, 0, w, h);
	// Calcula a correcao de aspecto
	Utils::fAspect = (GLfloat)w/(GLfloat)h;
	
	windowHeight = h;
	windowWidth = w;
}

void GerenciaTeclado(unsigned char key, int x, int y)
{
	switch (key) {
		case 'q': 	xeyes+=5;
					break;
		case 'a': 	xeyes-=5;
					break;
		case 'w': 	yeyes+=5;
					break;
		case 's': 	yeyes-=5;
					break;
		case 'e': 	zeyes+=5;
					break;
		case 'd': 	zeyes-=5;
					break;
		case 'z': 	helicoptero1.y-=1;
					break;
		case 'x': 	helicoptero1.y+=1;
					break;
		case 'c': 	nave.y-=1;
					break;
		case 'v': 	nave.y+=1;
					break;
	}
//	printf("%d %d %d\n", xeyes, yeyes, zeyes);
}

void Temporizador(int value) 
{
	// Rotaciona a helice
	helicoptero1.angulo = helicoptero1.angulo+40 % 360;
	
	// Redesenha a tela
	glutPostRedisplay(); 
	glutTimerFunc(33,Temporizador, 1); 
}

// Programa Principal
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(600*Utils::fAspect,600);
	glutCreateWindow("River Raid");
	glutDisplayFunc(Desenha);
	glutReshapeFunc(AlteraTamanhoJanela);
	glutKeyboardFunc(GerenciaTeclado);
	glutTimerFunc(33, Temporizador, 1);
	Inicializa();
	glutMainLoop();
}
