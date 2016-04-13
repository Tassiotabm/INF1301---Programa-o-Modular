/***************************************************************************
*  $MCI M�dulo de implementa��o: M�dulo de teste espec�fico

*	M�dulo criado para operar com listas
*
*  Arquivo gerado:              TESTBAR.C
*  Letras identificadoras:      TBar
*
*  Nome da base de software:    Exemplo de teste automatizado
*
*  Projeto: Disciplinas INF 1628 / 1301
*  Gestor:  DI/PUC-Rio
*  Autores:	fvc	- Felipe Vieira Cortes
*			tbm - T�ssio Borges de Miranda
*			db  - Daniela Braz�o
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*		4.00   tbm	 23/10/2015 M�dulo criado para operar com listas
*
*  $ED Descri��o do m�dulo
*     Este m�dulo cont�m as fun��es espec�ficas para o teste do
*     m�dulo Bar.
*
*  $EIU Interface com o usu�rio pessoa
*     Comandos de teste espec�ficos para testar o m�dulo BAR:

*	 =criarbar			<inxpec>	<cor>	<CondRet>		    - Chama a fun��o BAR_tpCondRet BAR_CriarBAR() 
*	 =obtercorbar		<inxpec>	<cor Esperada> <CondRet>	- Chama a fun��o BAR_tpCondRet BAR_AdicionarPeca(BAR_tppCapturadas pBAR)
*	 =obtertamanhobar	<inxpec>	<tamaho Esperado> <CondRet>	- Chama a fun��o BAR_tpCondRet BAR_RemoverPeca(BAR_tppCapturadas pBAR)
*	 =removerbar		<inxpec>	<CondRet>					- Chama a fun��o BAR_tpCondRet BAR_ObterTamanhoBar(BAR_tppCapturadas pBAR, int *tam)
*    =addbar			<inxpec>	<CondRet>					- Chama a fun��o BAR_tpCondRet BAR_ObterCorBar(BAR_tppCapturadas pBAR, char *cor)
*	 =destruirbar		<inxpec>	<CondRet>					- Chama a fun��o BAR_tpCondRet Bar_DestruirBar(BAR_tppCapturadas pBAR)
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>
#include    <malloc.h>

#include	"BAR.h"
#include	"LISTA.H"
#include	"GENERICO.H"
#include	"LERPARM.H"
#include	"PECA.h"
#include	"TST_ESPC.H"


/* Tabela dos nomes dos comandos de teste espec�ficos */
#define		MAX 5
#define		DIM_VET_BAR			2
#define     CRIAR_BAR_CMD       "=criarbar"
#define     REMOVER_BAR_CMD     "=removerbar"
#define     OBTER_COR_BAR_CMD   "=obtercorbar"
#define		ADD_BAR_CMD			"=addbar"
#define		OBTER_TAM_BAR_CMD	"=obtertamanhobar"
#define		DESTRUIR_BAR_CMD	"=destruirbar"

BAR_tppCapturadas BarCap [DIM_VET_BAR];

/***** Prot�tipos das fun��es encapuladas no m�dulo *****/

   static void DestruirValor( void * pValor ) ;

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

      int CondRetObtido   = BAR_CondRetOK ;
      int CondRetEsperada = BAR_CondRetFaltouMemoria ;
                                      /* inicializa para qualquer coisa */

      char ValorEsperado = '?'  ;
      char ValorObtido   = '!'  ;
      char ValorDado     = '\0' ;
	  char corEsperada	= 'x';
	  char corRecebida;
      int  NumLidos = -1 ;
	  int i = 0;
	  int inxpec, tamanhobar,tamanhobaresp;
	
	  TST_tpCondRet Ret;
	  TST_tpCondRet CondRet;
	
      /* Testar  Bar Criar Bar */
         if ( strcmp( ComandoTeste , CRIAR_BAR_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "ici" ,
                             &inxpec, &corRecebida,  &CondRetEsperada ) ;
            if ( NumLidos != 3 )
            {
               return TST_CondRetParm ;
            } /* if */

			if(inxpec > 5 || inxpec < 0) return TST_CondRetErro;

            CondRetObtido = BAR_CriarBAR(&BarCap[inxpec],corRecebida,DestruirValor);

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao criar BAR." );

         } /* fim ativa: Testar  BAR Criar BAr */

		 /* Testar  Bar Remover Bar */
		 else	if ( strcmp( ComandoTeste , REMOVER_BAR_CMD ) == 0 )
         {

			NumLidos = LER_LerParametros( "ii" , &inxpec, &CondRetEsperada ) ;
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            } /* if */

			CondRetObtido = BAR_RemoverPeca(BarCap[inxpec]) ;

			return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao Removar Bar." );

         } /* fim ativa: Testar  Bar Remover Bar */

		/* Testar  Bar Obter cor da Bar */
		 else	if ( strcmp( ComandoTeste , OBTER_COR_BAR_CMD ) == 0 )
         {

			NumLidos = LER_LerParametros( "ici",&inxpec,&corEsperada, &CondRetEsperada ) ;
            if ( NumLidos != 3 )
            {
               return TST_CondRetParm ;
            } /* if */
			CondRetObtido = BAR_ObterCorBar(BarCap[inxpec],&corRecebida) ;

            Ret = TST_CompararChar( corRecebida , corEsperada ,
                         "Valor do elemento errado, diferente do esperado" ) ;

			if ( Ret != TST_CondRetOK )
            {
               return Ret ;
            } /* if */

			return TST_CompararChar(CondRetObtido, CondRetEsperada, "Retorno errado ao obter o cor do BAR.");

         } /* fim ativa: Testar  Bar Obter cor da Bar */

		 /* Testar  Bar AddBar */
		 else	if ( strcmp( ComandoTeste , ADD_BAR_CMD ) == 0 )
         {

			NumLidos = LER_LerParametros( "ii" , &inxpec, &CondRetEsperada ) ;
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            } /* if */

			CondRetObtido = BAR_AdicionarPeca(BarCap[inxpec]) ;

			return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao obter cor da BAR." );

         }
		 /*Fim da ativa: Testar Bar addbar*/

		 /* Testar obter tamanho BAR*/
		 else if( strcmp ( ComandoTeste , OBTER_TAM_BAR_CMD) == 0)
		 {
			NumLidos = LER_LerParametros( "iii" , &inxpec,&tamanhobaresp, &CondRetEsperada);
			if ( NumLidos != 3 )
				return TST_CondRetParm;

			CondRetObtido = BAR_ObterTamanhoBar(BarCap[inxpec],&tamanhobar);

			CondRet = TST_CompararInt(tamanhobaresp,tamanhobar,"Tamanho do elemento errado, diferente do esperado");

			if ( CondRet != TST_CondRetOK )
				return CondRet;

			return TST_CompararInt( CondRetEsperada , CondRetObtido, "Retorno errado ao obter tamanho bar.");
		 }
		 /*Fim da ativa: Testar Bar tamanhoBAR*/

		 /*Testar Destruir Bar*/

		 else if( strcmp ( ComandoTeste , DESTRUIR_BAR_CMD) == 0)
		 {
			NumLidos = LER_LerParametros( "ii" , &inxpec, &CondRetEsperada);
			if ( NumLidos != 2 )
				return TST_CondRetParm;

			CondRetObtido = Bar_DestruirBar(BarCap[inxpec]);

			return TST_CompararInt( CondRetEsperada , CondRetObtido, "Retorno errado ao destruir BAR.");
		 }

		 /*Fim da ativa: Testar Destuir Bar*/
      return TST_CondRetNaoConhec ;
   } /* Fim fun��o: TPec Efetuar opera��es de teste espec�ficas para Peca */

void DestruirValor( void * pValor )
   {
      free( pValor ) ;
   }