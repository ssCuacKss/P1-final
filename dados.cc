/**
	@file dados.cc
	@title fichero .cc con la implementacion de las funciones de la clase Dados.
	@version 1.0
	@date 24/9/2020
	@author ssCuacKss
*/
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include"dados.h"
using namespace std;
/**
	@brief constructor de la clase dados

	Al declarar una variable de la clase Dados, el constructor asigna a d1_ y d2_ el valor 1
	al d1_Lanzamientos y d2_Lanzamientos les asigna el valor 0, le asigna 0 a la suma historica de los valores de los dados
	y rellena con ceros los elementos del los vectores que guardan los ultimos 5 valores de los dados,
	ademas genera la semilla para el lanzamiento de los dados.
*/
Dados::Dados(){
	d1_=d2_=1;
	d1_Lanzamientos=d2_Lanzamientos=0;
	d1_sum_valores=d2_sum_valores=0;
	for(int i=0;i<5;i++){
		ultimos5D1[i]=ultimos5D2[i]=0;
	}
	srand(time(NULL));
}
/**
	@brief funcion que realiza el lanzamiento de los dados

	introduce un valor aletorio entre 1 y 6, ademas actualiza la suma de valores historicos, los lanzamientos y llama a sync1() y sync2() para actualizar la lista de ultimos lanzamientos
	@return no devuelve nada

*/
void Dados::lanzamiento(){
	d1_=rand()%6+1;
	d2_=rand()%6+1;
	d1_sum_valores+=d1_;
	d2_sum_valores+=d2_;
	d1_Lanzamientos++;
	d2_Lanzamientos++;
	this->sync1();
	this->sync2();
}
/**
	@brief asigna un valor de forma manual al dado 1 si el numero esta estre 1 y 6

	si el valor a asignar esta en el intervalo, lo asigna al dado, actualiza el valor de los lanzamientos y suma historica de valores y llama a sync1() para actualizar los ultimos valores del dado
	@param dado1 el valor a asignar al dado
	@return devuelve false si el valor a asignar sale del intervalo, y true si esta dentro
*/
bool Dados::setDado1(int dado1){
	if((dado1<1) || (dado1>6)){
		return false;
	}
	d1_=dado1;
	d1_Lanzamientos++;
	d1_sum_valores+=d1_;
	this->sync1();
	return true;
}
/**
	@brief asigna un valor de forma manual al dado 2 si el numero esta estre 1 y 6

	si el valor a asignar esta en el intervalo, lo asigna al dado, actualiza el valor de los lanzamientos y suma historica de valores y llama a sync2() para actualizar los ultimos valores del dado
	@param dado2 el valor a asignar al dado
	@return devuelve false si el valor a asignar sale del intervalo, y true si esta dentro
*/
bool Dados::setDado2(int dado2){
	if((dado2<1) || (dado2>6)){
		return false;
	}
	d2_=dado2;
	d2_Lanzamientos++;
	d2_sum_valores+=d2_;
	this->sync2();
	return true;
}
/**
	@brief devuelve el valor actual del dado 1
	@return devuelve el valor actual del dado 1
*/
int Dados::getDado1(){
	return d1_;
}
/**
	@brief devuelve el valor actual del dado 2
	@return devuelve el valor actual del dado 2
*/
int Dados::getDado2(){
	return d2_;
}
/**
	@brief actualiza los valores del vector que guarda los ultimos 5 lanzamientos del dado 1

	se realiza el desplazamiento de datos del vector hacia la derecha, con lo que nos deja espacio al principio del vector para el ultimo valor del dado obtenido
	@return no devuelve nada
*/
void Dados::sync1(){
	for(int i=3;i>=0;i--){
		ultimos5D1[i+1]=ultimos5D1[i];
	}
	ultimos5D1[0]=d1_;
}
/**
	@brief actualiza los valores del vector que guarda los ultimos 5 lanzamientos del dado 2

	se realiza el desplazamiento de datos del vector hacia la derecha, con lo que nos deja espacio al principio del vector para el ultimo valor del dado obtenido
	@return no devuelve nada
*/
void Dados::sync2(){
	for(int i=3;i>=0;i--){
		ultimos5D2[i+1]=ultimos5D2[i];
	}
	ultimos5D2[0]=d2_;
}
/**
	@brief realiza la suma de valores actuales del dado 1 y el dado 2

	@return devuelve la suma de valores del dado 1 y el dado 2
*/
int Dados::getSuma(){
	return d1_+d2_;
}
/**
	@brief devuelve la resta entre los valores de los dados 1 y 2

	@return devuelve la diferencia entre el mayor y menor valor de los dados  
*/
int Dados::getDiferencia(){
	if(d1_<d2_){
		return d2_ - d1_;
	}
	else{
		return d1_ - d2_;
	}
}
/**
	@brief devuelve la media de valores del dado 1

	@return si no han habido lanzamientos, devuelve 0, en cualquier otro caso devuelve el cociente de la sumatoria historica de valores del dado 1 entre la cantidad de lanzamientos como un float 
*/
float Dados::getMedia1(){
	if(d1_Lanzamientos==0){
		return 0;
	}
	else{
		return (float)d1_sum_valores/d1_Lanzamientos;
	}
}
/**
	@brief devuelve la media de valores del dado 2

	@return si no han habido lanzamientos, devuelve 0, en cualquier otro caso devuelve el cociente de la sumatoria historica de valores del dado 2 entre la cantidad de lanzamientos como un float 
*/
float Dados::getMedia2(){
	if(d2_Lanzamientos==0){
		return 0;
	}
	else{
		return (float)d2_sum_valores/d2_Lanzamientos;
	}
}
/**
	@brief devuelve la cantidad de lanzamientos que ha tenido el dado 1
	@return devuelve un entero con la cantidad de lanzamientos del dado 1
*/
int Dados::getLanzamientos1(){
	return d1_Lanzamientos;
}
/**
	@brief devuelve la cantidad de lanzamientos que ha tenido el dado 2
	@return devuelve un entero con la cantidad de lanzamientos del dado 2
*/
int Dados::getLanzamientos2(){
	return d2_Lanzamientos;
}
/**
	@brief copia en un vector los valores de los 5 ultimos lanzamientos del dado 1

	se asigna a los valores de un vetor mediante un bucle los valores que hay guardados en el vector ultimos5D1[]
	@param v[] un vector de 5 elementos
	@return no devuelve nada  
*/
void Dados::getUltimos1(int v[]){
	for(int i=0;i<5;i++){
		v[i]=ultimos5D1[i];
	}
}
/**
	@brief copia en un vector los valores de los 5 ultimos lanzamientos del dado 2

	se asigna a los valores de un vetor mediante un bucle los valores que hay guardados en el vector ultimos5D2[]
	@param v[] un vector de 5 elementos
	@return no devuelve nada  
*/
void Dados::getUltimos2(int v[]){
	for(int i=0;i<5;i++){
		v[i]=ultimos5D2[i];
	}
}