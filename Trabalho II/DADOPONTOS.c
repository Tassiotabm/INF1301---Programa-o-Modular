/***************************************************************************
*  $MCI Módulo de implementação: Gerador de numeroes aleatorios restrito ao
*								 numero de faces 
*
*  Arquivo gerado:              DADO.c
*  Letras identificadoras:      DAD
*
*  Nome da base de software:    Exemplo de teste automatizado
*
*  Projeto: Disciplinas INF 1628 / 1301
*  Gestor:  DI/PUC-Rio
*  Autores: avs - Arndt von Staa
*			fvc - Felipe Vieira Côrtes
*			tbm - Tássio Borges de Miranda
*			db  - Daniela Brazão
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*	  1.0     tbm   02/set/2015	Início do desenvolvimento
*
***************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include "DADO.H"  
#include "GERAALT.H"

#define DADO_OWN
#include "DADOPONTOS.h"
#undef DADO_OWN

/***********************************************************************
*
*  $TC Tipo de dados: DADPnt Descritor do dados de ponto.
*
*  $ED Descrição do tipo
*		Descreve a estrutura do dados ponto
***********************************************************************/

   typedef struct tgDadoPontos {
		int valor;
		/*Valor atual do dado de pontos*/
		char * CorDoJogador;
		/*Ponteiro para o jogador que pode usar o dado
		*$EED Assertivas Estruturais
		*	É NULL se o jogo esta no começo e ninguem fez nenhuma dobra */

   } tpDadoPontos ;
/*
   typedef struct tgPlayers {
	   int id;
   } tpPlayers;
   /*Struct Temporaria*/

/*****  Dados encapsulados no módulo  *****/


/*****  Código das funções exportadas pelo módulo  *****/

/***************************************************************************
*
*  Função: DADPnt Criar Dado de Pontos
*  ****/

DADPnt_tpCondRet DADPtn_CriarDado(tppDadoPontos * DadoCriado)
{
	struct tgDadoPontos * DadoNovo;
	DadoNovo = (tpDadoPontos*)malloc(sizeof(tpDadoPontos));
	if(DadoNovo = NULL)
		return DADPnt_CondRetFaltouMemoria;
	DadoNovo->valor = 2;
	/*Valor Inicial do Dado de Pontos*/
	DadoNovo->CorDoJogador = NULL;
	/*Quando o dado é criado, todos os jogadores podem usa-lo o inicio*/
	(*DadoCriado) = DadoNovo;
	return  DADPnt_CondRetOK;
}
/***************************************************************************
*
*  Função: DADPnt Dobrar Dado de Pontos
*  ****/

DADPnt_tpCondRet DADPtn_DobrarDado(tppDadoPontos DadoDobrar)
{
	DadoDobrar->valor = DadoDobrar->valor * 2;
	/*Pega o valor atual do dado e multiplica por 2*/
	return  DADPnt_CondRetOK;
}
/***************************************************************************
*
*  Função: DADPnt Mudar "Dono" do Dado de Pontos
*  ****/

DADPnt_tpCondRet DADPtn_MudDono(tppDadoPontos DadoDono, char * cor)
{
	DadoDono->CorDoJogador = cor;
	/*Troca o jogador que pode realizar a dobra*/
	return  DADPnt_CondRetOK;
}

/***************************************************************************
*
*  Função: DADPnt Gerar Valor da Partida
*  ****/

DADPnt_tpCondRet DADPtn_ValorPartida(tppDadoPontos Dado, int * valorjogo)
{
	if(Dado->CorDoJogador == NULL)
		*valorjogo = 1;
	else
		*valorjogo = Dado->valor;
	return DADPnt_CondRetOK;
}

/***************************************************************************
*
*  Função: DADPnt Destruir Dado de Pontos
*  ****/

DADPnt_tpCondRet DADPtn_DestruirDado(tppDadoPontos Dado)
{
	Dado->CorDoJogador = NULL;
	Dado->valor = 0;
	free(Dado);
	return DADPnt_CondRetOK;
}
/*********** Fim do módulo de implementação: Módulo DadoPontos **************/
