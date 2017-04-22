/* Trabalho 2 de Metodos de Programacao **
** Aluno: Eduardo Sousa da Silva        **
** Matricula: 13/0108405                */

#include <gtest/gtest.h>
#include "romanos.h"

//Testa RetornaNumero para os algarismos validos e para um algarismo invalido
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

//Testa Converte para Strings vazias e com mais de 30 caracteres
TEST(ConverteTest, EmptyStringLongString){
	
	ASSERT_EQ(Converte(""), -1);
	ASSERT_EQ(Converte("Essa String tem: 31 caracteres."), -1);

}

//Testa Converte para algarismos sozinhos
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

//Testa Converte para repetições de apenas um algarismo
TEST(ConverteTest, Repetitions){
	EXPECT_EQ(Converte("XX"), 20);
	EXPECT_NE(Converte("VV"), 10);
	EXPECT_EQ(Converte("CCC"), 300);
	EXPECT_NE(Converte("IIII"), 4);
}

//Testa Converte para subtrações de apenas 2 membros
TEST(ConverteTest, SimpleSubtractions){
	EXPECT_EQ(Converte("IV"), 4);
	EXPECT_EQ(Converte("IX"), 9);
	EXPECT_EQ(Converte("XL"), 40);
	EXPECT_EQ(Converte("XC"), 90);
	EXPECT_EQ(Converte("CD"), 400);
	EXPECT_EQ(Converte("CM"), 900);

	EXPECT_NE(Converte("VX"), 5);
}

//Testa Converte para strings com valores sempre decrescentes
TEST(ConverteTest, OnlyDecreasingString){
	EXPECT_EQ(Converte("MDCLXVI"), 1666);
	EXPECT_EQ(Converte("CCCXXI"), 321);
	EXPECT_EQ(Converte("CXXIII"), 123);
}

//Testa Converte para sequências longas com subtrações
TEST(ConverteTest, LongWithSubtractions){
	EXPECT_NE(Converte("IIV"), 3);
	EXPECT_NE(Converte("XCCC"), 290);
	EXPECT_EQ(Converte("MCDXXXIV"), 1434);
	EXPECT_NE(Converte("DIXV"), 514);
	EXPECT_NE(Converte("XCM"), 910);
}

//Testa Converte para strings em caixa baixa e valores limitrofes
TEST(ConverteTest, LowercaseValueBounds){
	EXPECT_NE(Converte("iv"), 4);
	EXPECT_NE(Converte("MMMI"), 3001);
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}