// nave.cpp
// Projeto "River Raid"
#ifndef VESSEL_HPP
#define VESSEL_HPP

#define MAX 31

struct Ponto{
	float x;
	float y;
	float z;
};

class Nave {

	public:
		float x;
		float y;
		float z;
		
        Nave();
        void refresh();


    private:
        Ponto elipsoide[MAX][MAX];
        Ponto paraboloide[MAX][MAX];
        Ponto cilindro[MAX][MAX];

        float _v;

        void armazenaPontos();
        void desenhaMatriz(Ponto pontos[MAX][MAX], int max);
        void desenhaCabine();
        void desenhaAerofolio();
        void desenhaAsa();
        void desenhaTurbina();

};

#endif
