Eduardo Sousa da Silva - 13/0108405

Github do Projeto: https://github.com/eduardoforca/T2MP/
Documentação Doxygen(contém documentação dos testes): https://eduardoforca.github.io/T2MP/html/index.html

-------- README	--------
Para a execução do programa deve-se primeiro compilá-lo utilizando o arquivo makefile. Para isso é necessário que o compilador g++ assim como o make estejam instalados na máquina. O programa foi testado apenas em Linux, não é esperado que funcione com Windows, devido às bibliotecas estáticas na pasta lib.

Para montar o programa deve-se utilizar o comando no terminal:

make -f makefile

Para isto deve-se estar na pasta src, onde o arquivo makefile está presente. Com isso a rotina de testes e romanos.c serão compilados. Para executá-la deve se colocar o seguinte comando no terminal:

./test_romanos

Onde test_romanos é o nome do executável gerado pela compilação, assim como descrito no makefile.

Os arquivos são:
        
|-------Doxyfile - Arquivo de configuração do Doxygen para geração de documentação
|-------errorlog.txt - Arquivo gerado pelo cppcheck com os erros identificados nos arquivos fonte
|-------README.txt - Instruções para compilação e execução
|-------html - Pasta contendo os arquivos html gerados pelo doxygen
        |-------index.html - Arquivo da página inicial da documentação
        |-------...
|-------latex - Pasta contendo os arquivos para a geração do pdf em LaTeX gerados pelo doxygen
        |-------refman.pdf - Documentação em formato PDF
|-------include
	|-------romanos.h - Arquivo header da biblioteca de conversão de algarismos romanos
        |-------gtests - Pasta contendo os arquivos header para o framework. Não é necessária a instalação do mesmo para o meu programa.
                |-------...
|-------lib
	|-------libgtests.a - Arquivo de biblioteca estática necessário para a utilização do framework
|-------src
	|-------romanos.c - Arquivo de implementação biblioteca de conversão de algarismos romanos
	|-------test_romanos.cpp - Arquivo de implementação da rotina de testes
	|-------makefile - Arquivo de make para a compilação do programa
        |-------romanos.c.gcov - Arquivo de saída do gcov, mostrando o quanto do código foi cobrido pelos testes(100%)
	|-------obj - Pasta contendo os objetos necessários para a execução do programa(deve estar vazia antes do primeiro make)
		|-------...
