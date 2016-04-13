/***************************************************************************
*  $MCI M�dulo de implementa��o: PF Pe�as Finalizadas
*
*  Arquivo gerado:              PF.c
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
	   1.0		fvc		18/10	 Come�o do Desenvolvimento
*
***************************************************************************/

#include   <stdio.h>
#include   <string.h>
#include   <malloc.h>
#include "LISTA.h"
#include "PECA.h"
#define PF_OWN
#include "PecasFinalizadas.h"
#undef PF_OWN


/***********************************************************************
*
*  $TC Tipo de dados: PF Descritor da estrutura de pe�as finalizadas
*
*
***********************************************************************/

typedef struct PF_tagFinalizadas {

	LIS_tppLista ListaFinalizadas;
	/* Lista de Pe�as Finalizadas*/

	char cor;
	/* A cor das pe�as da estrutura */

	int tamanho ;
	/* N�mero de elementos na lista */

} PF_tpFinalizadas ;

/*****  C�digo das fun��es exportadas pelo m�dulo  *****/

/***************************************************************************
*
*  Fun��o: TAB  &Criar PF
*  ****/

PF_tpCondRet PF_CriarPF(PF_tppFinalizadas *pPF, char cor,
             void   ( * ExcluirValor ) ( void * pDado ) )
{

	*pPF = (PF_tppFinalizadas)malloc(sizeof(PF_tpFinalizadas));

	if(*pPF == NULL)
		return PF_CondRetFaltouMemoria;

	(*pPF)->ListaFinalizadas = LIS_CriarLista(ExcluirValor);
	(*pPF)->cor = cor;
	(*pPF)->tamanho = 0;

	return PF_CondRetOK;
}

/***************************************************************************
*
*  Fun��o: TAB  &Adicionar Pe�a
*  ****/

PF_tpCondRet PF_AdicionarPeca(PF_tppFinalizadas pPF)
{
	char cor = pPF->cor;
	tppPeca newPeca;
	if(Pec_CriarPeca(&newPeca, cor) != Pec_CondRetOK)
	{
		printf("Erro ao criar peca (PF) \n");
		return PF_CondRetErro;
	}
	if(LIS_InserirElementoApos(pPF->ListaFinalizadas, newPeca) != LIS_CondRetOK)
	{
		printf("Erro ao inserir pe�a na lista (PF) \n");
		return PF_CondRetErro;
	}
	pPF->tamanho++;

	return PF_CondRetOK;
}


/***************************************************************************
*
*  Fun��o: TAB  &Obter Tamanho PF
*  ****/

PF_tpCondRet PF_ObterTamanhoBar(PF_tppFinalizadas pPF, int *tam)
{
	if(tam == NULL)
		return PF_CondRetErro;

	*tam = pPF->tamanho;

	if(*tam == 0)
		return PF_CondRetVazia;

	return PF_CondRetOK;
}

/***************************************************************************
*
*  Fun��o: TAB  &Obter cor PF
*  ****/

PF_tpCondRet PF_ObterCorBar(PF_tppFinalizadas pPF, char *cor)
{
	if(cor == NULL)
		return PF_CondRetErro;

	*cor = pPF->cor;

	return PF_CondRetOK;
}

/******** Fim do M�dulo de Implementa��o: PF Lista de Pe�as Finalizadas *************/