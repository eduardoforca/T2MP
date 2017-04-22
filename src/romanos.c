/* Trabalho 2 de Metodos de Programacao **
** Aluno: Eduardo Sousa da Silva        **
** Matricula: 13/0108405                */

#include "romanos.h"
#include <string.h>

#define TRUE 1
#define FALSE 0

// Enum representando os possiveis algarismos romanos
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

int Converte(char* roman_seq){
	if(strlen(roman_seq) <= 30 && strlen(roman_seq) > 0){

		int soma_parcial = 0, resultado = 0, alg_antigo = 1001, count_reps = 0, subtraiu = 0;

		for(int i = 0; i < strlen(roman_seq); i++){
			int alg_atual = RetornaNumero(roman_seq[i]);

			if(alg_atual != INVALID){

				if(alg_atual == alg_antigo){
					//Nao pode haver repeticao apos subtracao
					if(subtraiu)
						return INVALID;

					count_reps++;
					soma_parcial += alg_atual;

					//Numeros nao podem se repetir mais de 3 vezes
					if(count_reps > 3)
						return INVALID;

					//V L and D nao podem ser repetidos
					if(alg_atual == V || alg_atual == L || alg_atual == D)
						return INVALID;
				}else if(alg_atual > alg_antigo){
					
					//Valor deve sempre diminuir apos subtracao
					if(subtraiu)
						return INVALID;

					//Numeros repetidos nao podem ser usados em subtracao
					if(count_reps > 1)
						return INVALID;

					//Nem todas subtracoes sao aceitas
					if(ChecaSubtracao(alg_atual, alg_antigo) == FALSE)
						return INVALID;
					
					//2 vezes pois foi adicionado anteriormente
					soma_parcial = alg_atual - alg_antigo;

					subtraiu = alg_antigo;
				}else {
					if(subtraiu){
						//Valor novo deve ser menor que menor membro da subtracao
						if(subtraiu <= alg_atual){
							return INVALID;
						}else{
							subtraiu = FALSE;
						}
					}
					resultado += soma_parcial;
					count_reps = 1;
					soma_parcial = alg_atual;
				}
			} else{
				return INVALID;
			}
			alg_antigo = alg_atual;
		}
		resultado += soma_parcial;
		if(resultado > 3000)
			return INVALID;
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

int ChecaSubtracao(int maior, int menor){
	int sub = maior - menor;
	switch(sub){
		case 4:
		case 9:
		case 40:
		case 90:
		case 400:
		case 900: return TRUE;
		default: return FALSE;
	}
}