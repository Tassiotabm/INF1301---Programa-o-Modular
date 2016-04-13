/***************************************************************************
*  $MCI M�dulo de implementa��o: M�dulo de teste espec�fico

*	M�dulo modificado para operar matrizes que armazenam listas!
*
*  Arquivo gerado:              TESTDADOPONTOS.C
*  Letras identificadoras:      TPec
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
		4.00   tbm	 23/08/2015 M�dulo modificado para operar dadospontos
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
*     =criardadoponto		<inxpec>	<cor>	<CondRet>				- Chama a fun��o Pec_tpCondRet Pec_CriarPeca(tppPeca * PecCriado);
*	  =destruirdadoponto	<inxpec>	<CondRet>							  - Chama a fun��o Pec_tpCondRet Pec_DestruirPeca(tppPeca  Peca);
*     =obtervalorjogo		<inxpec>	<cor Esperada> <CondRet	>			 - Chama a fun��o Pec_tpCondRet Pec_ObterCor(tppPeca  Peca, char *cor);
***************************************************************************/

#include    <string.h>
#include    <stdio.h>
#include    <malloc.h>

#include    "TST_ESPC.H"

#include    "GENERICO.H"
#include    "lerparm.h"
#include	"DADOPONTOS.h"

/* Tabela dos nomes dos comandos de teste espec�ficos */
#define MAX 5
#define     CRIAR_DADOPONTOS_CMD		"=criardadopontos"
#define     DESTRUIR_DADOPONTOS_CMD		"=destruirdadoponto"
#define     OBTER_VALORPARTIDA_CMD	    "=obtervalorpartida"
#define		DOBRAR_DADO_CMD				"=dobrardado"
#define		OBTER_DONO_CMD				"=obterdono"


tppDadoPontos P[MAX];
/*****  C�digo das fun��es exportadas pelo m�dulo  *****/

/***********************************************************************
*
*  $FC Fun��o: TPec Efetuar opera��es de teste espec�ficas para o Modulo Peca
*
*  $ED Descri��o da fun��o
*     Efetua os diversos comandos de teste espec�ficos para o m�dulo
*     Peca sendo testado.
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

      int CondRetObtido   = DADPnt_CondRetOK ;
      int CondRetEsperada = DADPnt_CondRetFaltouMemoria ;
                                      /* inicializa para qualquer coisa */

      char ValorEsperado = '?'  ;
      char ValorObtido   = '!'  ;
      char ValorDado     = '\0' ;
	  char corEsperada	= 'x';

      int  NumLidos = -1 ;
	  int i = 0;
	  int ValorPontos,valoresperado;
	  char corRecebida;
	  int inxpec;
	
	  TST_tpCondRet Ret;
	
      /* Testar  Pec Criar Dado Pontos */
         if ( strcmp( ComandoTeste , CRIAR_DADOPONTOS_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "ici" ,
                             &inxpec,&corEsperada, &CondRetEsperada ) ;
            if ( NumLidos != 3 )
            {
               return TST_CondRetParm ;
            } /* if */
			if(inxpec > 5 || inxpec < 0) return TST_CondRetErro;

            CondRetObtido = DADPtn_CriarDado(&P[inxpec]);


            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao criar ao criar dadopontos." );

         } 
		 /* fim ativa: Testar  Criar Dado Pontos */

		 /* Testar  Pec Destruir DadoPontos */
		 else	if ( strcmp( ComandoTeste , DESTRUIR_DADOPONTOS_CMD ) == 0 )
         {

			NumLidos = LER_LerParametros( "ii" ,
                              &inxpec, &CondRetEsperada ) ;
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            } /* if */

			CondRetObtido = DADPtn_DestruirDado(P[inxpec]) ;

			return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao destruir o dadopontos." );

         }
		/* fim ativa: Testar DadoPontos Destruir*/

		/* Testar Obter Dono do DadoPonto */
		 else	if ( strcmp( ComandoTeste , OBTER_DONO_CMD	 ) == 0 )
         {

			NumLidos = LER_LerParametros( "ici" ,
                              &inxpec, &corEsperada ,&CondRetEsperada ) ;
            if ( NumLidos != 3 )
            {
               return TST_CondRetParm ;
            } /* if */
			CondRetObtido = DADPtn_ObterDono(P[inxpec],&corRecebida) ;

            Ret = TST_CompararChar( corRecebida , corEsperada ,
                         "Cor do jogador errado, diferente do esperado" ) ;

			if ( Ret != TST_CondRetOK )
            {
               return Ret ;
            } /* if */

			return TST_CompararChar(CondRetObtido, CondRetEsperada, "Retorno errado ao obter o dono do dado");

         }
		 /* fim ativa: Testar Obter Dono do DadoPonto*/

		 /* Testar  Dadoponto DobrarDado */
         else if ( strcmp( ComandoTeste , DOBRAR_DADO_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "ici" ,
                             &inxpec,&corEsperada, &CondRetEsperada ) ;
            if ( NumLidos != 3 )
            {
               return TST_CondRetParm ;
            } /* if */
			if(inxpec > 5 || inxpec < 0) return TST_CondRetErro;

            CondRetObtido = DADPtn_DobrarDado(P[inxpec],corEsperada);

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao dobrar o valor do dadopontos." );

         } /* fim ativa: Fim Dobrar Dado */

		 /* Testar  Dadoponto Obter Valor */
         else if ( strcmp( ComandoTeste , OBTER_VALORPARTIDA_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "iii" ,
                             &inxpec,&valoresperado, &CondRetEsperada ) ;
            if ( NumLidos != 3 )
            {
               return TST_CondRetParm ;
            } /* if */
			if(inxpec > 5 || inxpec < 0) return TST_CondRetErro;

            CondRetObtido = DADPtn_ValorPartida(P[inxpec],&ValorPontos);

		    Ret = TST_CompararInt( valoresperado , ValorPontos , " Valor da Partida Errado" ) ;

			if ( Ret != TST_CondRetOK )
            {
               return Ret ;
            } 

            return TST_CompararInt( CondRetObtido, CondRetEsperada ,
                                    "Retorno errado ao obter valor do dado pontos." );

         } /* fim ativa: Fim Dobrar Dado */


      return TST_CondRetNaoConhec ;

   } /* Fim fun��o: TPec Efetuar opera��es de teste espec�ficas para DadoPonto */