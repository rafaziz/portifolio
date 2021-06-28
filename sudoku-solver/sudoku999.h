/***************************************************************************
 *   sudoku999.h                           Version 20201018.020303         *
 *                                                                         *
 *   Sudoku Solver                                                         *
 *   Copyright (C) 2016-2021    by Ruben Carlo Benante                     *
 ***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License.        *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************
 *   To contact the author, please write to:                               *
 *   Ruben Carlo Benante                                                   *
 *   Email: rcb@beco.cc                                                    *
 *   Webpage: www.beco.cc                                                  *
 *   Phone: +55 (81) 3184-7555                                             *
 ***************************************************************************/

/* ---------------------------------------------------------------------- */
/**
 * \file sudoku999.h
 * \ingroup GroupUnique
 * \brief Brief description
 * \details This program really do a nice job as a template, and template only!
 * \version 20160908.182854
 * \date 2016-09-08
 * \author Ruben Carlo Benante <<rcb@beco.cc>>
 * \par Webpage
 * <<a href="www.beco.cc">www.beco.cc</a>>
 * \copyright (c) 2016 GNU GPL v2
 * \note This program is free software: you can redistribute it
 * and/or modify it under the terms of the
 * GNU General Public License as published by
 * the Free Software Foundation version 2 of the License.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.
 * If not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place - Suite 330, Boston, MA. 02111-1307, USA.
 * Or read it online at <<http://www.gnu.org/licenses/>>.
 *
 *
 * \todo Now that you have the template, hands on! Programme!
 * \warning Be carefull not to lose your mind in small things.
 * \bug This file right now does nothing usefull
 *
 */

#ifndef _EXN_H
#define _EXN_H

/* ---------------------------------------------------------------------- */
/* includes */

/* #include <stdio.h> */ /* Standard I/O functions */
/* #include <stdlib.h> */ /* Miscellaneous functions (rand, malloc, srand)*/
/* #include <getopt.h> */ /* get options from system argc/argv */

/* #include <time.h> */ /* Time and date functions */
/* #include <math.h> */ /* Mathematics functions */
/* #include <string.h> */ /* Strings functions definitions */
/* #include <dlfcn.h> */ /* Dynamic library */
/* #include <malloc.h> */ /* Dynamic memory allocation */
/* #include <unistd.h> */ /* UNIX standard function */
/* #include <limits.h> */ /* Various C limits */
/* #include <ctype.h> */ /* Character functions */
/* #include <errno.h> */ /* Error number codes errno */
/* #include <signal.h> */ /* Signal processing */
/* #include <stdarg.h> */ /* Functions with variable arguments */
/* #include <pthread.h> */ /* Parallel programming with threads */
/* #include <fcntl.h> */ /* File control definitions */
/* #include <termios.h> */ /* Terminal I/O definitions POSIX */
/* #include <sys/stat.h> */ /* File status and information */
/* #include <float.h> */ /* Float constants to help portability */
/* #include <setjmp.h> */ /* Bypass standard function calls and return */
/* #include <stddef.h> */ /* Various types and MACROS */
/* #include <SWI-Prolog.h> */ /* Prolog integration with C */
/* #include <ncurses.h> */ /* Screen handling and optimisation functions */
/* #include <allegro.h> */ /* A game library for graphics, sounds, etc. */
/* #include <libintl.h> */ /* Internationalization / translation */
/* #include <locale.h> */ /* MACROS LC_ for location specific settings */
/* #include "libeco.h" */ /* I/O, Math, Sound, Color, Portable Linux/Windows */
/* #include "sudoku999.h" */ /* To be created for this template if needed */

/* ---------------------------------------------------------------------- */
/* definitions */

#ifndef VERSION /* gcc -DVERSION="0.1.160612.142628" */
#define VERSION "20160908.182854" /**< Version Number (string) */
#endif

/* Debug */
#ifndef DEBUG /* gcc -DDEBUG=1 */
#define DEBUG 0 /**< Activate/deactivate debug mode */
#endif

#if DEBUG==0
#define NDEBUG
#endif
/* #include <assert.h> */ /* Verify assumptions with assert. Turn off with #define NDEBUG */ 

/** @brief Debug message if DEBUG on */
#define IFDEBUG(M) if(DEBUG) fprintf(stderr, "[DEBUG file:%s line:%d]: " M "\n", __FILE__, __LINE__); else {;}

/* limits */
#define SBUFF 256 /**< String buffer */

/* ---------------------------------------------------------------------- */
/* globals */

static int verb = 0; /**< verbose level, global within the file */

/* ---------------------------------------------------------------------- */
/* prototypes */

/* ---------------------------------------------------------------------- */
/* funcoes de apoio : sugestoes apenas. Apagar se nao utilizar */
void help(void); /**< Prints help information and exit */
void copyr(void); /**< Prints copyright information and exit */
void sudoku999_init(int w[9][9][9]);/**< Initializes some operations before start */

void printsudoku(int w[9][9][9]);
void entrada(int w[9][9][9]);

/* limpa a celula dos candidatos */
int limparcelula(int w[9][9][9], int l, int c, int d1, int d2, char *hd);
/* remove candidatos das linhas e colunas*/
int remover(int recebe, int w[9][9][9], int l, int c, char tipo, char *hd);
/* naked(single): remove candidadtos do bloco  */
int removebloco(int w[9][9][9], int recebe, int l, int c, int lb, int cb, char *hd);
/* remove candidatos externos ao bloco em linha ou coluna */
int externalremove(int recebe, int w[9][9][9], int fixo, int variavel, int nbloco, int tipo, char *hd);
/* dada uma coordenada e um num, faz deducao positiva e elimina possibilidades em w */
int dyes(int l, int c, int n, int w[9][9][9]);
/* dada uma coordenada e um num (de 1 a 9) que nao eh, faz deducao negativa e elimina uma unica possibilidade em w */
int dnot(int l, int c, int n, int w[9][9][9]);
/* retorna verdadeiro (com n de 1 a 9) se a celula ja tem valor unico certo */
int unico(int y[9]);
/* copia os candidatos a serem unica opcao de uma celula */
void copycandy(int w[9][9][9], int l, int c, int y[9]);
/* apaga em candidatos os repetidos em w */
void clearcandy(int w[9][9][9], int l, int c, int y[9]);
/* conta o total de valores verdadeiros em vetor de 9 posicoes */
int totalcandy(int y[9]);
/* conta o total de candidatos na celula e retorna o candidato se for igual a 2*/
int twocandies(int w[9][9][9], int d, int ref, int tipo);
/* acha coordenada superior esquerda do setor que contem a celula l,c */
int cbloco(int l, int c, int *ql, int *qc);
/* dado o numero do bloco (0 a 8), retorna a coordenada da primeira celula */
void bloco(int n, int *ql, int *qc);
/*funcoes do metodo d3*/
int removepair(int recebe[2], int w[9][9][9], int l, int c, int arg2, int tipo, char *hd);
int removepairb(int recebe[2], int w[9][9][9], int l1, int c1, int l2, int c2, char *hd);
/*funcoes para contar a quantidade de vezes que o candidato aparece na linha ou coluna*/
int contacandl(int w[9][9][9],int d,int l);
int contacandc(int w[9][9][9],int d,int c);
/*funcao utilizada para limpar linhas e colunas do swordfish*/
int removeswordfish(int recebe,int w[9][9][9],int l, int c, int arg2,int arg3, int tipo, char *hd);
/* funcao para remover o claiming candidate" */
int clap(int w[9][9][9],int d,int nbloco, int lentrada, int centrada, int tipo, char *hd);
/* funcoes metodo d10(backtracking) */

/* ---------------------------------------------------------------------- */
/* verifica se tem celula vazia ou preenchida */
int celula(int w[9][9][9], int *linha, int *coluna);

/* ---------------------------------------------------------------------- */
/* verifica se pode colocar valor na celula, ve linha,coluna, bloco */
int pode(int w[9][9][9], int linha, int coluna, int pos);
/* ---------------------------------------------------------------------- */

int skyscraper(int w[9][9][9], int d, int l1, int l2, int c1, int c2, char *hd);

/* ---------------------------------------------------------------------- */

/* valida sudoku (candidatos) */
/* dada matriz de candidatos:
 * -1: se todos tem exatamente um candidato: solucao encontrada
 * 1-81: se todos tem pelo menos um candidato: ok, num de celulas em duvida
 * 0: se algum nao tem candidato: erro
 */
int check(int w[9][9][9]); /* check if sudoku is solved, incomplete or invalid */


/* ---------------------------------------------------------------------- */
/* estas funcoes de deducao chamam as suas partes para o grupo */
/* atencao: obrigatorio usar essas funcoes como estao na funcao main() */

int d1(int w[9][9][9]); /* naked single */
int d2(int w[9][9][9]); /* hidden single */
int d3(int w[9][9][9]); /* naked pair */
int d4(int w[9][9][9]); /* hidden pair */
int d5(int w[9][9][9]); /* pointing candidate */
int d6(int w[9][9][9]); /* claiming candidate */
int d7(int w[9][9][9]); /* x-wing */
int d8(int w[9][9][9]); /* xy-wing */
int d9(int w[9][9][9]); /* x-wing : swordfish */
int d10(int w[9][9][9]); /* backtracking */
int d11(int w[9][9][9]); /* skyscraper */

/* ---------------------------------------------------------------------- */
/* sub-funcoes de deducao por grupo */
/* d1 : naked single: confronta cada valor ja deduzido com sua linha (horizontal) */
int d1l(int w[9][9][9]);
/* d1 : naked single: confronta cada valor ja deduzido com sua coluna (vertical) */
int d1c(int w[9][9][9]);
/* d1 : naked single: confronta cada valor ja deduzido com seu quadrado (setor) */
int d1b(int w[9][9][9]);

/* d2: hidden single: procura numa horizontal um numero com apenas uma celula possivel de estar */
int d2l(int w[9][9][9]);
/* d2: hidden single: procura numa vertical um numero com apenas uma celula possivel de estar */
int d2c(int w[9][9][9]);
/* d2: hidden single: procura num setor um numero com apenas uma celula possivel de estar */
int d2b(int w[9][9][9]);

/* naked tuple (pair/triple/quad): remove candidatos fora do par, no grupo */
/* d3: naked tuple : line */
int d3l(int w[9][9][9]);
/* d3: naked tuple : column */
int d3c(int w[9][9][9]);
/* d3: naked tuple : block */
int d3b(int w[9][9][9]);

/* hidden pair: remove candidatos na celula do par, limpando-o, tornando-o naked pair */
/* d4: hidden pair na linha */
int d4l(int w[9][9][9]);
/* d4: hidden pairs em colunas */
int d4c(int w[9][9][9]);
/* d4: hidden pairs em bloco */
int d4b(int w[9][9][9]);

/* d5: pointing candidates : dedo-duro : linha */
int d5l( int w[9][9][9]);
/* d5: pointing candidates : dedo-duro : coluna */
int d5c(int w[9][9][9]);

/* d6: claiming line */
int d6l(int w[9][9][9]);
/* d6: claiming column */
int d6c(int w[9][9][9]);

/* d7: x-wing line */
int d7l(int w[9][9][9]);
/* d7: x-wing : column */
int d7c(int w[9][9][9]);

/* d8: xy-wing line */
int d8l(int w[9][9][9]);
int asa1(int w[9][9][9], int linha, int coluna);/* acha asa 1  */
int asa2(int w[9][9][9], int linha1, int coluna1,int linhapv, int colunapv, int blocopv, int tipo);/* acha asa 2  */
int verifica(int w[9][9][9], int linha, int coluna, int linhapv, int colunapv);/* verifica condicao existencia de asa 1  */
int verifica2(int w[9][9][9], int linha2, int coluna2, int linha1, int coluna1, int linhapv, int colunapv);/* verifica condicao existencia de asa 2  */
int amiga(int w[9][9][9],int linha1, int coluna1, int bloco1, int linha2, int coluna2, int bloco2, int candidato);/* acha celula amiga */
int conta(int w[9][9][9], int l, int c);/* conta quantidade de candidatos em uma celula */

/* d10: backtracking */
int tenta8(int w[9][9][9]);

/* d9: x-wing : swordfish line*/
int d9l(int w[9][9][9]);
/* d9: x-wing : swordfish column */
int d9c(int w[9][9][9]);

/* d11: skyscraper line*/
int d11l(int w[9][9][9]);
/* d11: skyscraper column */
int d11c(int w[9][9][9]);
#endif /* NOT def _EXN_H */

/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160612.142044      */
