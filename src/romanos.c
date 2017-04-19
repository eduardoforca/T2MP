/* Trabalho 2 de Metodos de Programacao **
** Aluno: Eduardo Sousa da Silva        **
** Matricula: 13/0108405                */

#include "romanos.h"
#include <string.h>

enum Algarism {
	I = 1,
	V = 5,
	X = 10,
	L = 50,
	C = 100,
	D = 500,
	M = 1000,
	INVALID = -1
};

/*Retorna conversao de string de algarismos romanos para algarismos arabicos para valores entre 1 e 3000
	Retorna -1 para conversoes invalidas
*/

int Converte(char* roman_seq){
	if(strlen(roman_seq) <= 30 && strlen(roman_seq) > 0){

		int soma_parcial = 0, resultado = 0, alg_atual = 0, alg_antigo = 0, count_reps = 0;

		for(int i = 0; i < strlen(roman_seq); i++){
			alg_antigo = alg_atual;
			alg_atual = RetornaNumero(roman_seq[i]);

			if(alg_atual != INVALID){
				if(alg_atual == alg_antigo){
					count_reps++;
					soma_parcial += alg_atual;

					//Numeros nao podem se repetir mais de 3 vezes
					if(count_reps > 3)
						return INVALID;

					//V L and D nao podem ser repetidos
					if(alg_atual == V || alg_atual == L || alg_atual == D)
						return INVALID;
				} else {
					resultado += soma_parcial;
					soma_parcial = alg_atual;
					count_reps = 1;
				}
			} else{
				return INVALID;
			}
		}
		if(soma_parcial > 0){
			resultado += soma_parcial;
		}
		return resultado;
	}
	return INVALID;
}

int RetornaNumero(char alg_romano){
	switch(alg_romano){
		case 'I': return I;
		case 'V': return V;
		case 'X': return X;
		case 'L': return L;
		case 'C': return C;
		case 'D': return D;
		case 'M': return M;
		default:
			return INVALID;
	}
}