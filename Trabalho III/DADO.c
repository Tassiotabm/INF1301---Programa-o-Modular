/***************************************************************************
*  $MCI M�dulo de implementa��o: Gerador de numeroes aleatorios restrito ao
*								 numero de faces 
*
*  Arquivo gerado:              DADO.c
*  Letras identificadoras:      DAD
*
*  Nome da base de software:    Exemplo de teste automatizado
*
*  Projeto: Disciplinas INF 1628 / 1301
*  Gestor:  DI/PUC-Rio
*  Autores: fvc - Felipe Vieira C�rtes
*			tbm - T�ssio Borges de Miranda
*			db  - Daniela Braz�o
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor			  Data     Observa��es
*	  1.0     tbm, fvc   02/set/2015	In�cio do desenvolvimento

*
***************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define DADO_OWN
#include "DADO.h"
#include <assert.h>
#undef DADO_OWN
#define RAN_MAX 0x7fff

/***************************************************************************
*
*  Fun��o: DAD & gerar o numero de casas que devem ser puladas com 1 dado
*  ****/


/*****  C�digo das fun��es encapsuladas no m�dulo  *****/

int randint(int n);


/*****  C�digo das fun��es exportadas pelo m�dulo  *****/

/***************************************************************************
*
*  Fun��o: DAD  &Gera numero aleat�rio
*  ****/

DAD_tpCondRet DAD_NumPular(int *NumeroCasas)
{
	*NumeroCasas = randint(6);

	return DAD_CondRetOK;

}/*Fim da fun��o DAD_NumPular */


/* Fun��o usada pelo m�dulo */
/* Returns an integer in the range [1, n]*/
int randint(int n) {
  int r;
  if ((n - 1) == RAND_MAX) {
    return rand();
  } else {
    long end = RAND_MAX / n; // truncate skew
    assert (end > 0L);
    end *= n;
    while ((r = rand()) >= end);

	r = (r|time(NULL));

    return (r % n) +1;
  }
}
/*********** Fim do m�dulo de implementa��o: M�dulo Dado **************/







