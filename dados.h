/**
	@file dados.h
	@title fichero .h con la definicion de la clase Dados.
	@version 1.0
	@date 24/09/2020
	@author ssCuacKss

*/
#ifndef DADOS_H
#define DADOS_H
/**
	@class Dados
	@brief clase Dados

	La clase Dados contiene en la parte privada los datos
	de 2 dados, la parte publica contiene los metodos para la manipulacion de los datos	
*/
class Dados{
	private:
		int d1_; /**<atributo que guarda el valor del dado tras el lanzamiento o asignacion del dado 1*/
		int d2_; /**<atributo que guarda el valor del dado tras el lanzamiento o asignacion del dado 2*/
		int d1_Lanzamientos;/**<guarda el numero de lanzamientos y asignaciones realizadas en el dado 1*/
		int d2_Lanzamientos;/**<guarda el numero de lanzamientos y asignaciones realizadas en el dado 2*/
		int d1_sum_valores;/**<sumatoria de valores historicos del dado 1*/
		int d2_sum_valores;/**<sumatoria de valores historicos del dado 2*/
		int ultimos5D1[5];/**<vector que guarda los 5 ultimos valores del dado 1*/
		int ultimos5D2[5];/**<vector que guarda los 5 ultimos valores del dado 2*/
	public:
		Dados();
		void lanzamiento();
		int getDado1();
		int getDado2();
		int getSuma();
		bool setDado1(int dado1);
		bool setDado2(int dado2);
		int getDiferencia();
		int getLanzamientos1();
		int getLanzamientos2();
		float getMedia1();
		float getMedia2();
		void sync1();
		void sync2();
		void getUltimos1(int v[]);
		void getUltimos2(int v[]);
};
#endif