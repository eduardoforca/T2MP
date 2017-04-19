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
TEST(ConverteTest, EmptyStringLongString){
	
	ASSERT_EQ(Converte(""), -1);
	ASSERT_EQ(Converte("Essa String tem: 31 caracteres."), -1);

}
TEST(ConverteTest, SoloNumber){
	
	EXPECT_EQ(Converte("I"), 1);
	EXPECT_EQ(Converte("V"), 5);
	EXPECT_EQ(Converte("X"), 10);
	EXPECT_EQ(Converte("L"), 50);
	EXPECT_EQ(Converte("C"), 100);
	EXPECT_EQ(Converte("D"), 500);
	EXPECT_EQ(Converte("M"), 1000);

}

TEST(ConverteTest, Repetitions){
	EXPECT_EQ(Converte("XX"), 20);
	EXPECT_NE(Converte("VV"), 10);
	EXPECT_EQ(Converte("CCC"), 300);
	EXPECT_NE(Converte("IIII"), 4);
}

TEST(ConverteTest, SimpleSubtractions){
	EXPECT_EQ(Converte("IV"), 4);
	EXPECT_EQ(Converte("IX"), 9);
	EXPECT_EQ(Converte("XL"), 40);
	EXPECT_EQ(Converte("XC"), 90);
	
	EXPECT_NE(Converte("VX"), 5);
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}