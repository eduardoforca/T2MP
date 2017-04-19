/* Trabalho 2 de Metodos de Programacao **
** Aluno: Eduardo Sousa da Silva        **
** Matricula: 13/0108405                */

#include <gtest/gtest.h>
#include "romanos.h"

TEST(ConverteTest, EmptyString){
	
	ASSERT_EQ(Converte(""), -1);
	
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}