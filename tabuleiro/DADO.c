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
#include <time.h>

#define DADO_OWN
#include "DADO.h"
#include <assert.h>
#undef DADO_OWN
#define RAN_MAX 0x7fff

/***************************************************************************
*
*  Função: DAD & gerar o numero de casas que devem ser puladas com 1 dado
*  ****/


/* Funcao do Modulo */
int dadorand(void);


/* fim funcao do modulo */

DAD_tpCondRet DAD_NumPular(int *NumeroCasas)
{
	*NumeroCasas = randint(6);

	return DAD_CondRetOK;
}/*Fim da função DAD_NumPular */

/* Função usada pelo módulo */


/* Returns an integer in the range [1, n].
 *
 * Uses rand(), and so is affected-by/affects the same seed.
 */
int randint(int n) {
  int r;
  if ((n - 1) == RAND_MAX) {
    return rand();
  } else {
    // Chop off all of the values that would cause skew...
    long end = RAND_MAX / n; // truncate skew
    assert (end > 0L);
    end *= n;

    // ... and ignore results from rand() that fall above that limit.
    // (Worst case the loop condition should succeed 50% of the time,
    // so we can expect to bail out of this loop pretty quickly.
    while ((r = rand()) >= end);

	r = (r|time(NULL));

    return (r % n) +1;
  }
}
/*********** Fim do módulo de implementação: Módulo Dado **************/







