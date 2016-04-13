/***************************************************************************
*  $MCI Módulo de implementação: LIS  Lista duplamente encadeada
*
*  Arquivo gerado:              LISTA.c
*  Letras identificadoras:      LIS
*
*  Nome da base de software:    Arcabouço para a automação de testes de programas redigidos em C
*  Arquivo da base de software: D:\AUTOTEST\PROJETOS\LISTA.BSW
*
*  Projeto: INF 1301 / 1628 Automatização dos testes de módulos C
*  Gestor:  LES/DI/PUC-Rio
*  Autores: avs
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*     4       avs   01/fev/2006 criar linguagem script simbólica
*     3       avs   08/dez/2004 uniformização dos exemplos
*     2       avs   07/jul/2003 unificação de todos os módulos em um só projeto
*     1       avs   16/abr/2003 início desenvolvimento
*
***************************************************************************/

#include   <stdio.h>
#include   <string.h>
#include   <memory.h>
#include   <malloc.h>
#include   <assert.h>

#define TABULEIRO_OWN
#include "LISTA.H"
#include "GENERICO.H"
#include "PECA.h"
#include "TABULEIRO.H"

#undef TABULEIRO_OWN

/***********************************************************************
*
*  $TC Tipo de dados: TAB Tabuleiro
*
*
***********************************************************************/

typedef struct TAB_tagTabuleiro {

	LIS_tppLista Casas;

} TAB_tpTabuleiro;


/*****  Código das funções exportadas pelo módulo  *****/

/***************************************************************************
*
*  Função: LIS  &Criar Tabuleiro
*  ****/

TAB_tpCondRet TAB_CriarTabuleiro(TAB_tppTabuleiro * pTab,
	void   ( * ExcluirValor ) ( void * pDado ) )
{
	LIS_tppLista vtCasa[24]; // vetor de casas auxiliar
	tppPeca vtPecaB[15]; // vetor de peças brancas
	tppPeca vtPecaP[15]; //vetor de peças pretas
	int i, jb = 0,jp = 0;

	*pTab = (TAB_tppTabuleiro)malloc(sizeof(TAB_tpTabuleiro));
	(*pTab)->Casas = LIS_CriarLista(ExcluirValor);

	/* Cria 15 peças brancas */
	for(i = 0; i < 15; i++)
		if(Pec_CriarPeca(&vtPecaB[i], 'b')!=Pec_CondRetOK)
			return TAB_CondRetErro;
	/* Cria 15 peças pretas */
	for(i = 0; i < 15; i++)
		if(Pec_CriarPeca(&vtPecaP[i], 'p')!=Pec_CondRetOK)
			return TAB_CondRetErro;
	/* Cria 24 listas que representam cada casa do tabuleiro*/
	for(i = 0; i < 24; i++)
		vtCasa[i] = LIS_CriarLista(ExcluirValor);

	// Pretas
	LIS_InserirElementoApos(vtCasa[23], vtPecaP[jp]); jp++;
	LIS_InserirElementoApos(vtCasa[23], vtPecaP[jp]); jp++;
	// Brancas
	LIS_InserirElementoApos(vtCasa[0], vtPecaB[jb]); jb++;
	LIS_InserirElementoApos(vtCasa[0], vtPecaB[jb]); jb++;
	for(i = 0; i < 5; i++)
	{
		// Pretas
		LIS_InserirElementoApos(vtCasa[5], vtPecaP[jp]); jp++;
		LIS_InserirElementoApos(vtCasa[12], vtPecaP[jp]); jp++;
		// Brancas
		LIS_InserirElementoApos(vtCasa[11], vtPecaB[jb]); jb++;
		LIS_InserirElementoApos(vtCasa[18], vtPecaB[jb]); jb++;
	}
	for(i = 0; i < 3; i++)
	{
		// Pretas
		LIS_InserirElementoApos(vtCasa[7], vtPecaP[jp]); jp++;
		// Brancas
		LIS_InserirElementoApos(vtCasa[16], vtPecaB[jb]); jb++;
	}
	// Alocar as 24 casas na lista do tabuleiro
	for(i = 0; i < 24; i++)
		LIS_InserirElementoApos((*pTab)->Casas, vtCasa[i]);

	free(vtCasa);
	free(vtPecaB);
	free(vtPecaP);

	return TAB_CondRetOK;
}

/* Destuir Tabuleiro */

TAB_tpCondRet TAB_DestruirTabuleiro (TAB_tppTabuleiro pTab)
{
	LIS_tppLista temp;
	int i;
	// Destroi as 24 casas
	for(i = 0; i < 24; i++)
	{
		temp = (LIS_tppLista)LIS_ObterValor(pTab->Casas);
		LIS_DestruirLista(temp);
		LIS_AvancarElementoCorrente(pTab->Casas, -1);
	}
	// Destroi a lista principal
	LIS_DestruirLista(pTab->Casas);
	// Libera o ponteiro para o  tabuleiro
	free(pTab);

	return TAB_CondRetOK;
}







	   


