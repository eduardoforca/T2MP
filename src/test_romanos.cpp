/** @file test_romanos.cpp
 *  @brief Rotina de testes unitários de romanos.h
 *
 *  Testa as funções da biblioteca romanos.h utilizando o framework
 *  de testes Google Tests
 *  
 *	@author Eduardo Sousa (eduardoforca)
 *  @date 21 Apr 2017
 */

#include <gtest/gtest.h>
#include "romanos.h"

/**
 * @brief Testa RetornaNumero() para os algarismos válidos e para um algarismo inválido.
 * 
 * Ao passar neste teste, é garantido que RetornaNumero() retorna corretamente o valor de todos os algarismos básicos
 * do sistema romano de numeração.
 */
TEST(RetornaNumeroTest, AllNumbers){
	EXPECT_EQ(RetornaNumero('I'), 1);
	EXPECT_EQ(RetornaNumero('V'), 5);
	EXPECT_EQ(RetornaNumero('X'), 10);
	EXPECT_EQ(RetornaNumero('L'), 50);
	EXPECT_EQ(RetornaNumero('C'), 100);
	EXPECT_EQ(RetornaNumero('D'), 500);
	EXPECT_EQ(RetornaNumero('M'), 1000);
	EXPECT_EQ(RetornaNumero('E'), -1);
}

/**
 * @brief Testa Converte() para Strings vazias e com mais de 30 caracteres.
 * 
 * Ao passar neste teste, é garantido que Converte() calcula os algarismos apenas para strings do tamanho desejado.
 */
TEST(ConverteTest, EmptyStringLongString){
	
	ASSERT_EQ(Converte(""), -1);
	ASSERT_EQ(Converte("Essa String tem: 31 caracteres."), -1);

}

/**
 * @brief Testa Converte() para strings com apenas um algarismo.
 * 
 * Ao passar neste teste, é garantido que Converte() reconhece devidamente os algarismos básicos do sistema de numeração
 * romano.
 */
TEST(ConverteTest, SoloNumber){
	
	EXPECT_EQ(Converte("E"), -1);
	EXPECT_EQ(Converte("I"), 1);
	EXPECT_EQ(Converte("V"), 5);
	EXPECT_EQ(Converte("X"), 10);
	EXPECT_EQ(Converte("L"), 50);
	EXPECT_EQ(Converte("C"), 100);
	EXPECT_EQ(Converte("D"), 500);
	EXPECT_EQ(Converte("M"), 1000);

}

/**
 * @brief Testa Converte() para repetições de apenas um algarismo.
 * 
 * Ao passar neste teste, é garantido que Converte():
 *  - Funciona para repetições dos algarismos permitidos(I, X, C, M).
 *  - Não funciona para algarismos não permitidos(V, L, D).
 *  - Não funciona para repetições com 4 algarismos.
 */
TEST(ConverteTest, Repetitions){
	EXPECT_EQ(Converte("XX"), 20);
	EXPECT_NE(Converte("VV"), 10);
	EXPECT_EQ(Converte("CCC"), 300);
	EXPECT_NE(Converte("IIII"), 4);
}


/**
 * @brief Testa Converte() para subtrações.
 * 
 * Ao passar neste teste, é garantido que Converte(): 
 * - Funciona para todas os pares que representam subtrações no sistema numeral romano.
 * - Não funciona para subtrações inválidas.
 */
TEST(ConverteTest, SimpleSubtractions){
	EXPECT_EQ(Converte("IV"), 4);
	EXPECT_EQ(Converte("IX"), 9);
	EXPECT_EQ(Converte("XL"), 40);
	EXPECT_EQ(Converte("XC"), 90);
	EXPECT_EQ(Converte("CD"), 400);
	EXPECT_EQ(Converte("CM"), 900);

	EXPECT_NE(Converte("VX"), 5);
}

/**
 * @brief Testa Converte() para strings com valores decrescentes.
 * 
 * Ao passar neste teste, é garantido que Converte() funciona para sequências com repetições de algarismos diversos ordenados
 * de forma decrescente, ou seja, sem subtração.
 */
TEST(ConverteTest, OnlyDecreasingString){
	EXPECT_EQ(Converte("MDCLXVI"), 1666);
	EXPECT_EQ(Converte("CCCXXI"), 321);
	EXPECT_EQ(Converte("CXXIII"), 123);
}

/**
 * @brief Testa Converte() para sequências longas contendo subtrações.
 * 
 * Ao passar neste teste, é garantido que Converte():
 * - Funciona para sequências contendo repetições e subtrações juntas.
 * - Não funciona para subtrações de não-pares e.g: IIV.
 * - Não funciona para subtrações desordenadas e.g: XCCC, DIXV, XCM.
 * - Em conjunto com outros testes, funciona para toda sequência válida de algarismo romanos.
 */
TEST(ConverteTest, LongWithSubtractions){
	EXPECT_NE(Converte("IIV"), 3);
	EXPECT_NE(Converte("XCCC"), 290);
	EXPECT_EQ(Converte("MCDXXXIV"), 1434);
	EXPECT_NE(Converte("DIXV"), 514);
	EXPECT_NE(Converte("XCM"), 910);
}

/**
 * @brief Testa Converte() para Strings em lowercase e para valores acima do limite.
 * 
 * Ao passar neste teste, é garantido que Converte():
 * - Não funciona para Strings contendo caracteres minúsculos.
 * - Não funciona para valores acima de 3000.
 */
TEST(ConverteTest, LowercaseValueBounds){
	EXPECT_NE(Converte("iv"), 4);
	EXPECT_NE(Converte("MMMI"), 3001);
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}