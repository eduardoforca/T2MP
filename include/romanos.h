/** @file romanos.h
 *  @brief Protótipos das funções de conversão de algarismos romanos
 *
 *  Esse arquivo contém os protótipos das funções utilizadas na conversão de algarismos romanos para algarismos arábicos,
 *  assim como qualquer macro, constante ou variável global que venha a ser necessário
 *  
 *	@author Eduardo Sousa (eduardoforca)
 *  @date 21 Apr 2017
 */

#ifndef ROMANOS_H_
#define ROMANOS_H_

/**
 * @brief Converte uma string roman_seq de algarismos romanos para algarismos arábicos
 * 
 * Válido apenas para números de 1 a 3000. A string não pode ter mais do que 30 caracteres.
 * Caracteres minúsculos não são entradas válidas.
 * 
 * @param roman_seq Sequência de caracteres representando um número romano
 * @return Resultado da conversão
 * @retval -1 Entrada inválida
 * 
 * @test TEST(ConverteTest, EmptyStringLongString)
 * @test TEST(ConverteTest, SoloNumber)
 * @test TEST(ConverteTest, Repetitions)
 * @test TEST(ConverteTest, SimpleSubtractions)
 * @test TEST(ConverteTest, OnlyDecreasingString)
 * @test TEST(ConverteTest, LongWithSubtractions)
 * @test TEST(ConverteTest, LowercaseValueBounds)
 */
int Converte(char* roman_seq);

/**
 * @brief Retorna valor de alg_romano
 * @param alg_romano Algarismo a ser convertido
 * @return Valor de alg_romano
 * @retval -1 Algarismo inválido
 */
int RetornaNumero(char alg_romano);

/**
 * @brief Checa se subtração é permitida em algarismos romanos
 * 
 * @param maior Maior membro da subtração
 * @param menor Menor membro da subtração
 * 
 * @retval 1 a subtração é permitida
 * @retval 0 a subtração não é permitida
 * 
 * @test TEST(RetornaNumeroTest, AllNumbers)
 */
int ChecaSubtracao(int maior, int menor);

#endif  // ROMANOS_H_
