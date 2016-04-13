/***************************************************************************
*  $MCI M�dulo de implementa��o: BAR Pe�as Capturadas
*
*  Arquivo gerado:              BAR.c
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
	   1.0		fvc		18/10	 Come�o do Desenvolvimento
*
***************************************************************************/

#include   <stdio.h>
#include   <string.h>
#include   <malloc.h>
#include "LISTA.h"
#include "PECA.h"
#define BAR_OWN
#include "BAR.h"
#undef BAR_OWN


/***********************************************************************
*
*  $TC Tipo de dados: BAR Descritor da BAR
*
*
***********************************************************************/

typedef struct BAR_tagCapturadas {

	LIS_tppLista ListaCapturadas;
	/* Lista de Pe�as Capturadas*/

	char cor;
	/* A cor das pe�as do BAR */

	int tamanho ;
	/* N�mero de elementos no BAR*/

} BAR_tpCapturadas ;

/*****  C�digo das fun��es exportadas pelo m�dulo  *****/

/***************************************************************************
*
*  Fun��o: TAB  &Criar BAR
*  ****/

BAR_tpCondRet BAR_CriarBAR(BAR_tppCapturadas *pBAR, char cor, void   ( * ExcluirValor ) ( void * pDado ) )
{

	*pBAR = (BAR_tppCapturadas)malloc(sizeof(BAR_tpCapturadas));

	if(*pBAR == NULL)
		return BAR_CondRetFaltouMemoria;

	(*pBAR)->ListaCapturadas = LIS_CriarLista(ExcluirValor);
	(*pBAR)->cor = cor;
	(*pBAR)->tamanho = 0;

	return BAR_CondRetOK;
}

/***************************************************************************
*
*  Fun��o: TAB  &Adicionar Pe�a
*  ****/

BAR_tpCondRet BAR_AdicionarPeca(BAR_tppCapturadas pBAR)
{
	char cor = pBAR->cor;
	tppPeca newPeca;
	if(Pec_CriarPeca(&newPeca, cor) != Pec_CondRetOK)
	{
		printf("Erro ao criar peca (BAR) \n");
		return BAR_CondRetErro;
	}
	if(LIS_InserirElementoApos(pBAR->ListaCapturadas, newPeca) != LIS_CondRetOK)
	{
		printf("Erro ao inserir pe�a na lista (BAR) \n");
		return BAR_CondRetErro;
	}
	pBAR->tamanho++;

	return BAR_CondRetOK;
}

/***************************************************************************
*
*  Fun��o: TAB  &RemoverPe�a
*  ****/

BAR_tpCondRet BAR_RemoverPeca(BAR_tppCapturadas pBAR)
{
	if(LIS_ExcluirElemento(pBAR->ListaCapturadas) != LIS_CondRetOK)
	{
		printf("Erro ao excluir peca da lsita (BAR) \n");
		return BAR_CondRetErro;
	}

	return BAR_CondRetOK;
}

/***************************************************************************
*
*  Fun��o: TAB  &Obter Tamanho BAR
*  ****/

BAR_tpCondRet BAR_ObterTamanhoBar(BAR_tppCapturadas pBAR, int *tam)
{
	if(tam == NULL)
		return BAR_CondRetErro;

	*tam = pBAR->tamanho;

	if(*tam == 0)
		return BAR_CondRetVazia;

	return BAR_CondRetOK;
}

/***************************************************************************
*
*  Fun��o: TAB  &Obter cor BAR
*  ****/

BAR_tpCondRet BAR_ObterCorBar(BAR_tppCapturadas pBAR, char *cor)
{
	if(cor == NULL)
		return BAR_CondRetErro;

	*cor = pBAR->cor;

	return BAR_CondRetOK;
}

/******** Fim do M�dulo de Implementa��o: BAR Lista de Pe�as Capturadas *************/

