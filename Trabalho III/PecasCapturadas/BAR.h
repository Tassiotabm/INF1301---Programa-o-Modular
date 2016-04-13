#if ! defined( BAR_ )
#define BAR_
/***************************************************************************
*
*  $MCD M�dulo de defini��o: BAR  Lista de Pe�as Capturadas
*
*  Arquivo gerado:              BAR.h
*  Letras identificadoras:      BAR
*
*  Nome da base de software:    Arcabou�o para a automa��o de testes de programas redigidos em C
*
*  Projeto: INF 1301 / 1628 Automatiza��o dos testes de m�dulos C
*  Gestor:  LES/DI/PUC-Rio
*  Autores: fvc
			tbm
			db
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*		1.0		fvc		18/10	  Come�o da implementa��o
*
*  $ED Descri��o do m�dulo
*     Implementa uma lista de pe�as do tabuleiro gam�o.
*
***************************************************************************/
 
#if defined( BAR_OWN )
   #define BAR_EXT
#else
   #define BAR extern
#endif

/***** Declara��es exportadas pelo m�dulo *****/

/* Tipo refer�ncia para uma lista */

typedef struct BAR_tagCapturadas * BAR_tppCapturadas ;


/***********************************************************************
*
*  $TC Tipo de dados: BAR Condi��es de retorno
*
*
*  $ED Descri��o do tipo
*     Condi��es de retorno das fun��es da lista
*
***********************************************************************/

   typedef enum {

         BAR_CondRetOK ,
               /* Concluiu corretamente */

         BAR_CondRetVazia ,
               /* BAR n�o cont�m elementos */

		 BAR_CondRetErro,
				/* N�o concluiu corretamente */

         BAR_CondRetFaltouMemoria
               /* Faltou mem�ria ao tentar criar a estrutura*/

   } BAR_tpCondRet ;

/***********************************************************************
*
*  $FC Fun��o: BAR &Criar estrutura de pe�as capturadas
*
*  $ED Descri��o da fun��o
*     Cria uma estrutura para as pe�as capturadas do jogo de gam�o
*
*  $EP Par�metros
*	  pBAR  		- Ponteiro da estrutura de pe�as capturadas passada por refer�ncia
*     ExcluirValor  - ponteiro para a fun��o que processa a
*                     exclus�o do valor referenciado pelo elemento
*                     a ser exclu�do.
*                     Ver descri��o do m�dulo.
*
*  $FV Valor retornado
*		BAR_CondRetOk
*		BAR_CondRetFaltouMemoria
*
***********************************************************************/

   BAR_tpCondRet BAR_CriarBAR(BAR_tppCapturadas *pBAR, char cor,
             void   ( * ExcluirValor ) ( void * pDado ) ) ;

/***********************************************************************
*
*  $FC Fun��o: BAR Adicionar uma pe�a ao BAR
*
*  $ED Descri��o da fun��o
*		Adiciona uma pe�a � BAR
*
*  $EP Par�metros
*	  PBar			- A BAR que ser� adicionada a pe�a

*  $FV Valor retornado
*		BAR_CondRetOk
*		BAR_CondRetErro
*
***********************************************************************/

   BAR_tpCondRet BAR_AdicionarPeca(BAR_tppCapturadas pBAR) ;

/***********************************************************************
*
*  $FC Fun��o: BAR Remover uma pe�a ao BAR
*
*  $ED Descri��o da fun��o
*		Remover uma pe�a � BAR
*
*  $EP Par�metros
*	  PBar			- A BAR que ser� removida a pe�a

*  $FV Valor retornado
*		BAR_CondRetOk
*		BAR_CondRetErro
*
***********************************************************************/

   BAR_tpCondRet BAR_RemoverPeca(BAR_tppCapturadas pBAR) ;

/***********************************************************************
*
*  $FC Fun��o: BAR Obter tamanho da BAR
*
*  $ED Descri��o da fun��o
*		Obtem a quantidade de pe�as na BAR
*
*  $EP Par�metros
*	  PBar			- A BAR que se deseja saber o tamanho
*	  *tam			- Ponteiro de referencia para o tamanho da BAR

*  $FV Valor retornado
*		BAR_CondRetOk
*		BAR_CondRetVazia
*		BAR_CondRetErro
*
***********************************************************************/

   BAR_tpCondRet BAR_ObterTamanhoBar(BAR_tppCapturadas pBAR, int *tam) ;

/***********************************************************************
*
*  $FC Fun��o: BAR Obter Cor da BAR
*
*  $ED Descri��o da fun��o
*		Obtem a cor das pe�as da BAR
*
*  $EP Par�metros
*	  PBar			- A BAR que se deseja saber a cor
	  *cor			- Cor esperada

*  $FV Valor retornado
*		BAR_CondRetOk
*		BAR_CondRetErro
*
***********************************************************************/

   BAR_tpCondRet BAR_ObterCorBar(BAR_tppCapturadas pBAR, char *cor) ;

#undef BAR_EXT

/********** Fim do m�dulo de defini��o: BAR  Lista de Pe�as Capturadas **********/

#else
#endif
