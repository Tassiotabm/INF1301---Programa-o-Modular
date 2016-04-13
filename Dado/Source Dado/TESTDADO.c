/***************************************************************************
*  $MCI M�dulo de implementa��o: M�dulo de teste espec�fico

*	M�dulo modificado para operar matrizes que armazenam listas!
*
*  Arquivo gerado:              TESTMAT.C
*  Letras identificadoras:      TMAT
*
*  Nome da base de software:    Exemplo de teste automatizado
*
*  Projeto: Disciplinas INF 1628 / 1301
*  Gestor:  DI/PUC-Rio
*  Autores: avs - Arndt von Staa
			fvc	- Felipe Vieira Cortes
*			tbm - T�ssio Borges de Miranda
*			db  - Daniela Braz�o
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
		4.00   fvc	 23/08/2015 M�dulo modificado para operar matrizes
*       3.00   avs   28/02/2003 Uniformiza��o da interface das fun��es e
*                               de todas as condi��es de retorno.
*       2.00   avs   03/08/2002 Elimina��o de c�digo duplicado, reestrutura��o
*       1.00   avs   15/08/2001 In�cio do desenvolvimento
*
*  $ED Descri��o do m�dulo
*     Este m�dulo cont�m as fun��es espec�ficas para o teste do
*     m�dulo Matriz. Ilustra como redigir um interpretador de comandos
*     de teste espec�ficos utilizando o arcabou�o de teste para C.
*
*  $EIU Interface com o usu�rio pessoa
*     Comandos de teste espec�ficos para testar o m�dulo Matriz:
*
*     =criarmatriz		<inxmat>	<linha>		<coluna>	<CondRet> - Chama a fun��o MAT_CriarMatriz( linha, coluna, vtMatriz[inxmat])
*	  =criarlista		<CondRet>									  - Chama a fun��o MAT_CriarLista( lista )
*     =avancar			<Dire��o>	<inxmat>	<CondRet>			  - Chama a fun��o MAT_Avancar(vtMatriz[inxmat], direcao )
*																		e avan�a a c�lula corrente da matriz de acordo com a dire��o dada.
																		as dire��es s�o: norte, nordeste, leste, sudeste, sul, sudoeste, oeste e noroeste
*     =inscharantes"	<Char>		<CondRet>						  - Chama a fun��o MAT_InserirCharAntes( lista ) e insere o char na posi��o posterior ao corrente
*     =inschardepois"	<Char>		<CondRet>						  - Chama a fun��o MAT_InserirCharDepois( lista ) e insere o char na posi��o anterior ao corrente
*     "=inslista"		<inxmat>	<linha>		<coluna>	<CondRet> - chama a fun��o MAT_InserirLista(vtMatriz[inxmat], linha, coluna )
																		e insere a lista na posi��o linhaXcoluna da matriz
*     "=excluirelem"    <CondRet>									  - Chama a fun��o MAT_ExcluirElemento( lista ) e exclui o elemento corrente da lista
*     "=irinicio"		<CondRet>									  - chama a fun��o MAT_IrInicio( lista )
*     "=irfinal"		<CondRet>									  - chama a fun��o MAT_IrIFinal( lista )
*     "=obtervalorelem" <Char>		<CondRet>						  - Chama a fun��o  MAT_ObterValor( lista, charRecebido )
																		e compara o charRecebido com o valor <Char>
*     "=avancarelem"	<numElem>	<CondRet>					 	  - chama a fun��o MAT_AvancarElementoCorrente( lista, numElem )
*
*	  "=destruirmatriz" <inxmat>	<CondRet>						  - Chama a fun��o  MAT_DestruirMatriz( vtMatriz[inxmat] )
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
#define     INI_DADO_CMD     "=inicializardado"

/*****  C�digo das fun��es exportadas pelo m�dulo  *****/


/***********************************************************************
*
*  $FC Fun��o: TMAT Efetuar opera��es de teste espec�ficas para Matrizes
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
      /* Testar MAT Criar Matriz */

         if ( strcmp( ComandoTeste , JOGAR_DADO_CMD ) == 0 )
         {

            if ( NumLidos != -1 )
            {
               return TST_CondRetParm ;
            } /* if */

			while( i < 60) {
			CondRetObtido = DAD_NumPular(&valorDado) ;

			printf(" \n dado: %d\n", valorDado);
			i++;
			}

            return TST_CondRetOK;

         } /* fim ativa: Testar MAT Criar Matriz */

      return TST_CondRetNaoConhec ;

   } /* Fim fun��o: TMAT Efetuar opera��es de teste espec�ficas para �rvore */