/***************************************************************************
*  $MCI M�dulo de implementa��o: M�dulo de teste espec�fico
*
*  Arquivo gerado:              TESTDADO.C
*  Letras identificadoras:      TDADO
*
*  Nome da base de software:    Exemplo de teste automatizado
*
*  Projeto: Disciplinas INF 1628 / 1301
*  Gestor:  DI/PUC-Rio
*  Autores: fvc	- Felipe Vieira Cortes
*			tbm - T�ssio Borges de Miranda
*			db  - Daniela Braz�o
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
		1.00   fvc	 14/09/2015 In�cio e t�rmino do deselvolvimento
*
*  $ED Descri��o do m�dulo
*     Este m�dulo cont�m as fun��es espec�ficas para o teste do
*     m�dulo Dados, que gera um n�mero aleat�rio de 1 a 6
*
*  $EIU Interface com o usu�rio pessoa
*     Comandos de teste espec�ficos para testar o m�dulo Matriz:
*
*     =jogardado		chama a fun��o DAD_tpCondRet DAD_NumPular(int* NumPular) e retorna um valor inteiro de 1 a 6 e imprime na tela
***************************************************************************/

#include    <string.h>
#include    <stdio.h>
#include    <malloc.h>

#include    "TST_ESPC.H"

#include    "generico.h"
#include    "lerparm.h"
#include	"DADO.H"


/* Tabela dos nomes dos comandos de teste espec�ficos */

#define     JOGAR_DADO_CMD     "=jogardado"

/*****  C�digo das fun��es exportadas pelo m�dulo  *****/


/***********************************************************************
*
*  $FC Fun��o: TDADO Efetuar opera��es de teste espec�ficas para um dado de 6 faces
*
*  $ED Descri��o da fun��o
*     Efetua os diversos comandos de teste espec�ficos para o m�dulo
*     Matriz sendo testado.
*
*  $EP Par�metros
*     $P ComandoTeste - String contendo o comando
*
*  $FV Valor retornado
*     Ver TST_tpCondRet definido em TST_ESPC.H
*
***********************************************************************/

   TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
   {

      int CondRetObtido   = DAD_CondRetOK ;
      int CondRetEsperada = DAD_CondRetFaltouMemoria ;
                                      /* inicializa para qualquer coisa */

      char ValorEsperado = '?'  ;
      char ValorObtido   = '!'  ;
      char ValorDado     = '\0' ;

      int  NumLidos = -1 ;
	  int i = 0;
	  int valorDado;
      /* Testar DADO Jogar Dado */

         if ( strcmp( ComandoTeste , JOGAR_DADO_CMD ) == 0 )
         {

            if ( NumLidos != -1 )
            {
               return TST_CondRetParm ;
            } /* if */

			CondRetObtido = DAD_NumPular(&valorDado) ;

			printf(" \n dado: %d\n", valorDado);

            return TST_CondRetOK;

         } /* fim ativa: Testar DADO Jogar Dado */

      return TST_CondRetNaoConhec ;

   } /* Fim fun��o: TDADO Efetuar opera��es de teste espec�ficas para um dado de 6 faces*/