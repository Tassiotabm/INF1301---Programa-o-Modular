/***************************************************************************
*  $MCI M�dulo de implementa��o: Gerador de numeroes aleatorios restrito ao
*								 numero de faces 
*
*  Arquivo gerado:              DADOPONTOS.c
*  Letras identificadoras:      DADPnt
*
*  Nome da base de software:    Exemplo de teste automatizado
*
*  Projeto: Disciplinas INF 1628 / 1301
*  Gestor:  DI/PUC-Rio
*  Autores: 
*			fvc - Felipe Vieira C�rtes
*			tbm - T�ssio Borges de Miranda
*			db  - Daniela Braz�o
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*	  1.0     tbm   02/set/2015	In�cio do desenvolvimento
*
***************************************************************************/

#include <stdlib.h>
#include <stdio.h> 
#include <malloc.h>
#include <string.h>
#include "GENERICO.H"

#define DADO_OWN
#include "DADOPONTOS.h"
#undef DADO_OWN

/***********************************************************************
*
*  $TC Tipo de dados: DADPnt Descritor do dados de ponto.
*
*  $ED Descri��o do tipo
*		Descreve a estrutura do dados ponto
***********************************************************************/

   typedef struct tgDadoPontos {
		int valor;
		/*Valor atual do dado de pontos*/
		char CorDoJogador;
		/*Ponteiro para o jogador que pode usar o dado
		*$EED Assertivas Estruturais
		*	� NULL se o jogo esta no come�o e ninguem fez nenhuma dobra */

   } tpDadoPontos ;

/*****  Dados encapsulados no m�dulo  *****/


/*****  C�digo das fun��es exportadas pelo m�dulo  *****/

/***************************************************************************
*
*  Fun��o: DADPnt Criar Dado de Pontos
*  ****/

DADPnt_tpCondRet DADPnt_CriarDado(tppDadoPontos * DadoPontoCriado)
{

	*DadoPontoCriado = (tpDadoPontos*)malloc(sizeof(tpDadoPontos));

	if(DadoPontoCriado == NULL)
		return DADPnt_CondRetFaltouMemoria;

	(*DadoPontoCriado)->valor = 2;
	/*Valor Inicial do Dado de Pontos*/
	(*DadoPontoCriado)->CorDoJogador = 's';
	/*Quando o dado � criado, todos os jogadores podem usa-lo o inicio
	 s determinado que qualquer jogador pode usar*/
	return  DADPnt_CondRetOK;
}
/***************************************************************************
*
*  Fun��o: DADPnt Dobrar Dado de Pontos e Mudar "Dono" do Dado de Pontos
*  ****/

DADPnt_tpCondRet DADPnt_DobrarDado(tppDadoPontos DadoDobrar, char CorNovoDono)
{
	if(CorNovoDono == DadoDobrar->CorDoJogador)
		return DADPnt_CondRetErro;
	DadoDobrar->valor = DadoDobrar->valor * 2;
	/*Pega o valor atual do dado e multiplica por 2*/
	DadoDobrar->CorDoJogador = CorNovoDono;
	return  DADPnt_CondRetOK;
}

/***************************************************************************
*
*  Fun��o: DADPnt Gerar Valor da Partida
*  ****/

DADPnt_tpCondRet DADPnt_ValorPartida(tppDadoPontos DadoAtual, int * valorjogo)
{
	if(DadoAtual->CorDoJogador == 's' )
		*valorjogo = 2;
	else
		*valorjogo = DadoAtual->valor;
	return DADPnt_CondRetOK;
}

/***************************************************************************
*
*  $FC Fun��o: DADPnt Obter "Dono" do dado de pontos atual
*
*  $ED Descri��o da fun��o
*	  Retorno o dono do Dado
*  $FV Valor retonado
*     DADPnt_CondRetOK
*
***********************************************************************/

DADPnt_tpCondRet DADPnt_ObterDono(tppDadoPontos DadoPonto, char * CorDonoAtual)
{
	*CorDonoAtual = DadoPonto->CorDoJogador;
	return DADPnt_CondRetOK;
}

/***************************************************************************
*
*  Fun��o: DADPnt Destruir Dado de Pontos
*  ****/

DADPnt_tpCondRet DADPnt_DestruirDado(tppDadoPontos Dado)
{
	if(Dado == NULL)
		return DADPnt_CondRetDadoPontosNaoExiste;
	free(Dado);
	return DADPnt_CondRetOK;
}
/*********** Fim do m�dulo de implementa��o: M�dulo DadoPontos **************/
