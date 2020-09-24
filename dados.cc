#include<iostream>
#include<stdlib.h>
#include<time.h>
#include"dados.h"
using namespace std;

Dados::Dados(){
	d1_=d2_=1;
	d1_Lanzamientos=d2_Lanzamientos=0;
	d1_sum_valores=d2_sum_valores=0;
	for(int i=0;i<5;i++){
		ultimos5D1[i]=ultimos5D2[i]=0;
	}
	srand(time(NULL));
}
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
int Dados::getDado1(){
	return d1_;
}
int Dados::getDado2(){
	return d2_;
}
void Dados::sync1(){
	for(int i=3;i>=0;i--){
		ultimos5D1[i+1]=ultimos5D1[i];
	}
	ultimos5D1[0]=d1_;
}
void Dados::sync2(){
	for(int i=3;i>=0;i--){
		ultimos5D2[i+1]=ultimos5D2[i];
	}
	ultimos5D2[0]=d2_;
}
int Dados::getSuma(){
	return d1_+d2_;
}
int Dados::getDiferencia(){
	if(d1_<d2_){
		return d2_ - d1_;
	}
	else{
		return d1_ - d2_;
	}
}
float Dados::getMedia1(){
	if(d1_Lanzamientos==0){
		return 0;
	}
	else{
		return (float)d1_sum_valores/d1_Lanzamientos;
	}
}
float Dados::getMedia2(){
	if(d2_Lanzamientos==0){
		return 0;
	}
	else{
		return (float)d2_sum_valores/d2_Lanzamientos;
	}
}
int Dados::getLanzamientos1(){
	return d1_Lanzamientos;
}
int Dados::getLanzamientos2(){
	return d2_Lanzamientos;
}
void Dados::getUltimos1(int v[]){
	for(int i=0;i<5;i++){
		v[i]=ultimos5D1[i];
	}
}
void Dados::getUltimos2(int v[]){
	for(int i=0;i<5;i++){
		v[i]=ultimos5D2[i];
	}
}