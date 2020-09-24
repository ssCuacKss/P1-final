#ifndef DADOS_H
#define DADOS_H
class Dados{
	private:
		int d1_;
		int d2_;
		int d1_Lanzamientos;
		int d2_Lanzamientos;
		int d1_sum_valores;
		int d2_sum_valores;
		int ultimos5D1[5];
		int ultimos5D2[5];
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