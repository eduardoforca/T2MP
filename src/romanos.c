/* Trabalho 2 de Metodos de Programacao **
** Aluno: Eduardo Sousa da Silva        **
** Matricula: 13/0108405                */

#include "romanos.h"
#include <string.h>
/*Retorna conversao de string de algarismos romanos para algarismos arabicos para valores entre 1 e 3000
	Retorna -1 para conversoes invalidas
*/
int Converte(char* roman_seq){
	if(strlen(roman_seq) <= 30 && strlen(roman_seq) > 0){
		int resultado = 0, alg_atual = 0;
		for(int i = 0; i < strlen(roman_seq); i++){
			if((alg_atual = RetornaNumero(roman_seq[i])) != -1){
				resultado += alg_atual;
			} else{
				return -1;
			}

		}
		return resultado;
	}
	return -1;
}

int RetornaNumero(char alg_romano){
	switch(alg_romano){
		case 'I':
			return 1;
		case 'V':
			return 5;
		case 'X':
			return 10;
		case 'L':
			return 50;
		case 'C':
			return 100;
		case 'D':
			return 500;
		case 'M':
			return 1000;
		default:
			return -1;
	}
}