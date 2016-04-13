/***************************************************************************
*
*  $MCD M�dulo de defini��o: M�dulo Pe�a
*
*  Arquivo gerado:              PECA.H
*  Letras identificadoras:      PEC
*
*  Nome da base de software:    Exemplo de teste automatizado
*
*  Projeto: Disciplinas INF 1628 / 1301
*  Gestor:  DI/PUC-Rio
*  Autores: avs - Arndt von Staa
*			fvc - Felipe Vieira C�rtes
*			tbm - T�ssio Borges de Miranda
*			db  - Daniela Braz�o

*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*       1.00   tbm   14/09/2015 In�cio do desenvolvimento
*
*  $ED Descri��o do m�dulo
*     Este m�dulo implementa um conjunto simples de fun��es para manipular a pe�a
*	alem de descrever sua estrutura.
*
***************************************************************************/

#if defined( PECA_OWN )
   #define PECA_EXT
#else
   #define PECA_EXT extern
#endif

typedef struct tgPeca * tppPeca;

/***********************************************************************
*
*  $TC Tipo de dados: MAT Condicoes de retorno
*
*
***********************************************************************/

   typedef enum {

         Pec_CondRetOK = 0 ,
               /* Executou correto */

         Pec_CondRetErro = 1 ,
               /* Estrutura do DadoPontos est� errada */

         Pec_CondRetMatrizNaoExiste = 2 ,
               /* DadoPontos n�o existe */

         Pec_CondRetFaltouMemoria = 3
               /* Faltou mem�ria ao alocar dados */

   } Pec_tpCondRet ;

/***********************************************************************
*
*  $FC Fun��o: DADPnt Criar Pe�a
*
*  $ED Descri��o da fun��o
*	  Cria uma nova pe�a
*  $FV Valor retonado
*     Pec_CondRetOK
*     Pec_CondRetFaltouMemoria
*
***********************************************************************/

  Pec_tpCondRet Pec_CriarPeca(tppPeca * PecCriado1, char CorDaNovaPeca);

/***********************************************************************
*
*  $FC Fun��o: DADPnt Destruir Pe�a
*
*  $ED Descri��o da fun��o
*	  Destroi uma pe�a
*  $FV Valor retonado
*     Pec_CondRetOK
*     Pec_CondRetFaltouMemoria
*
***********************************************************************/

  Pec_tpCondRet Pec_DestruirPeca(tppPeca Peca);

/***********************************************************************
*
*  $FC Fun��o: DADPnt Obter Cor
*
*  $ED Descri��o da fun��o
*	  Obtem cor de uma peca
*  $FV Valor retonado
*     Pec_CondRetOK
*     Pec_CondRetFaltouMemoria
*
***********************************************************************/
Pec_tpCondRet Pec_ObterCor(tppPeca Peca, char *cor);