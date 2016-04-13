#if ! defined( PF_ )
#define PF_
/***************************************************************************
*
*  $MCD M�dulo de defini��o: OF  Lista de Pe�as Finalizadas
*
*  Arquivo gerado:              PecasFinalizadas.h
*  Letras identificadoras:      PF
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
 
#if defined( PF_OWN )
   #define PF_EXT
#else
   #define PF extern
#endif

/***** Declara��es exportadas pelo m�dulo *****/

/* Tipo refer�ncia para a estrutura de pecas finalizadas */

typedef struct PF_tagFinalizadas * PF_tppFinalizadas;


/***********************************************************************
*
*  $TC Tipo de dados: PF Condi��es de retorno
*
*
*  $ED Descri��o do tipo
*     Condi��es de retorno das fun��es do m�dulo de pe�as Finalizadas
*
***********************************************************************/

   typedef enum {

         PF_CondRetOK ,
               /* Concluiu corretamente */

         PF_CondRetVazia ,
               /* PF n�o cont�m elementos */

		 PF_CondRetErro,
				/* N�o concluiu corretamente */

         PF_CondRetFaltouMemoria
               /* Faltou mem�ria ao tentar criar a estrutura*/

   } PF_tpCondRet ;

/***********************************************************************
*
*  $FC Fun��o: PF &Criar estrutura de pe�as Finalizadas

*  $ED Descri��o da fun��o
*     Cria uma estrutura para as pe�as Finalizadas do jogo de gam�o
*
*  $EP Par�metros
*	  pPF		- Ponteiro da estrutura de pe�as finalizadas passada por refer�ncia
*     ExcluirValor  - ponteiro para a fun��o que processa a
*                     exclus�o do valor referenciado pelo elemento
*                     a ser exclu�do.
*                     Ver descri��o do m�dulo.
*
*  $FV Valor retornado
*		PF_CondRetOk
*		PF_CondRetFaltouMemoria
*
***********************************************************************/

   PF_tpCondRet PF_CriarPF(PF_tppFinalizadas *pPF, char cor,
             void   ( * ExcluirValor ) ( void * pDado ) ) ;

/***********************************************************************
*
*  $FC Fun��o: PF Adicionar uma pe�a ao PF
*
*  $ED Descri��o da fun��o
*		Adiciona uma pe�a a lista de pe�as finalizadas
*
*  $EP Par�metros
*	  pPF			- A estrutura que ser� adicionada a pe�a

*  $FV Valor retornado
*		PF_CondRetOk
*		PF_CondRetErro
*
***********************************************************************/

   PF_tpCondRet PF_AdicionarPecaPF(PF_tppFinalizadas pPF) ;

/***********************************************************************
*
*  $FC Fun��o: PF Obter tamanho da lista de pe�as finalizadas
*
*  $ED Descri��o da fun��o
*		Obtem a quantidade de pe�as na lista
*
*  $EP Par�metros
*	  pPF			- A estrutura que se deseja saber o tamanho
*	  *tam			- Ponteiro de referencia para o tamanho da PF

*  $FV Valor retornado
*		PF_CondRetOk
*		PF_CondRetVazia
*		PF_CondRetErro
*
***********************************************************************/

   PF_tpCondRet PF_ObterTamanhoPF(PF_tppFinalizadas pPF, int *tam) ;

/***********************************************************************
*
*  $FC Fun��o: PF Obter Cor da PF
*
*  $ED Descri��o da fun��o
*		Obtem a cor das pe�as da PF
*
*  $EP Par�metros
*	  pPF		    - A PF que se deseja saber a cor
	  *cor			- Cor esperada

*  $FV Valor retornado
*		PF_CondRetOk
*		PF_CondRetErro
*
***********************************************************************/

   PF_tpCondRet PF_ObterCorPF(PF_tppFinalizadas pPF, char *cor) ;

/***********************************************************************
*
*  $FC Fun��o: PF Destruir PF
*
*  $ED Descri��o da fun��o
*		Destroi a lista de pe�as finalizadas
*
*  $EP Par�metros
*	  pPF		    - A PF que se deseja destruir
*  $FV Valor retornado
*		PF_CondRetOk
*		PF_CondRetErro
*
***********************************************************************/

   PF_tpCondRet PF_DestruirPF(PF_tppFinalizadas pPF) ;

#undef PF_EXT

/********** Fim do m�dulo de defini��o: PF  Lista de Pe�as Finalizadas **********/

#else
#endif
