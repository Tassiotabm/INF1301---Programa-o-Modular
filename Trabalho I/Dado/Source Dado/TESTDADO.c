/***************************************************************************
*  $MCI Módulo de implementação: Módulo de teste específico

*	Módulo modificado para operar matrizes que armazenam listas!
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
*			tbm - Tássio Borges de Miranda
*			db  - Daniela Brazão
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
		4.00   fvc	 23/08/2015 Módulo modificado para operar matrizes
*       3.00   avs   28/02/2003 Uniformização da interface das funções e
*                               de todas as condições de retorno.
*       2.00   avs   03/08/2002 Eliminação de código duplicado, reestruturação
*       1.00   avs   15/08/2001 Início do desenvolvimento
*
*  $ED Descrição do módulo
*     Este módulo contém as funções específicas para o teste do
*     módulo Matriz. Ilustra como redigir um interpretador de comandos
*     de teste específicos utilizando o arcabouço de teste para C.
*
*  $EIU Interface com o usuário pessoa
*     Comandos de teste específicos para testar o módulo Matriz:
*
*     =criarmatriz		<inxmat>	<linha>		<coluna>	<CondRet> - Chama a função MAT_CriarMatriz( linha, coluna, vtMatriz[inxmat])
*	  =criarlista		<CondRet>									  - Chama a função MAT_CriarLista( lista )
*     =avancar			<Direção>	<inxmat>	<CondRet>			  - Chama a função MAT_Avancar(vtMatriz[inxmat], direcao )
*																		e avança a célula corrente da matriz de acordo com a direção dada.
																		as direções são: norte, nordeste, leste, sudeste, sul, sudoeste, oeste e noroeste
*     =inscharantes"	<Char>		<CondRet>						  - Chama a função MAT_InserirCharAntes( lista ) e insere o char na posição posterior ao corrente
*     =inschardepois"	<Char>		<CondRet>						  - Chama a função MAT_InserirCharDepois( lista ) e insere o char na posição anterior ao corrente
*     "=inslista"		<inxmat>	<linha>		<coluna>	<CondRet> - chama a função MAT_InserirLista(vtMatriz[inxmat], linha, coluna )
																		e insere a lista na posição linhaXcoluna da matriz
*     "=excluirelem"    <CondRet>									  - Chama a função MAT_ExcluirElemento( lista ) e exclui o elemento corrente da lista
*     "=irinicio"		<CondRet>									  - chama a função MAT_IrInicio( lista )
*     "=irfinal"		<CondRet>									  - chama a função MAT_IrIFinal( lista )
*     "=obtervalorelem" <Char>		<CondRet>						  - Chama a função  MAT_ObterValor( lista, charRecebido )
																		e compara o charRecebido com o valor <Char>
*     "=avancarelem"	<numElem>	<CondRet>					 	  - chama a função MAT_AvancarElementoCorrente( lista, numElem )
*
*	  "=destruirmatriz" <inxmat>	<CondRet>						  - Chama a função  MAT_DestruirMatriz( vtMatriz[inxmat] )
***************************************************************************/

#include    <string.h>
#include    <stdio.h>
#include    <malloc.h>

#include    "TST_ESPC.H"

#include    "generico.h"
#include    "lerparm.h"
#include	"DADO.H"


/* Tabela dos nomes dos comandos de teste específicos */

#define     JOGAR_DADO_CMD     "=jogardado"
#define     INI_DADO_CMD     "=inicializardado"

/*****  Código das funções exportadas pelo módulo  *****/


/***********************************************************************
*
*  $FC Função: TMAT Efetuar operações de teste específicas para Matrizes
*
*  $ED Descrição da função
*     Efetua os diversos comandos de teste específicos para o módulo
*     Matriz sendo testado.
*
*  $EP Parâmetros
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

   } /* Fim função: TMAT Efetuar operações de teste específicas para árvore */