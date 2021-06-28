/***************************************************************************
 *   sudoku999.c                           Version 20201018.020303         *
 *                                                                         *
 *   Sudoku Solver                                                         *
 *   Copyright (C) 2016-2021    by Ruben Carlo Benante                     *
 ***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; version 2 of the License.               *
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
 *   Webpage: http://www.beco.cc                                           *
 *   Phone: +55 (81) 3184-7555                                             *
 ***************************************************************************/

/* ---------------------------------------------------------------------- */
/**
 * @file sudoku999.c
 * @ingroup GroupUnique
 * @brief Brief description
 * @details This program really do a nice job as a template, and template only!
 * @version 20160908.182830
 * @date 2016-09-08
 * @author Ruben Carlo Benante <<rcb@beco.cc>>
 * @par Webpage
 * <<a href="http://www.beco.cc">www.beco.cc</a>>
 * @copyright (c) 2016 GNU GPL v2
 * @note This program is free software: you can redistribute it
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
 * @todo Now that you have the template, hands on! Programme!
 * @warning Be carefull not to lose your mind in small things.
 * @bug This file right now does nothing usefull
 *
 */

/*
 * Instrucoes para compilar:
 *   $gcc sudoku999.c -o sudoku999.x -Wall
 *        -Wextra -ansi -pedantic-errors -g -O0 -DDEBUG=1 -DVERSION="0.1.160612.142044"
 *   ou preferencialmente inclua um makefile e use:
 *   $make
 *
 * Modelo de indentacao:
 * Estilo: --style=allman ou -A1
 *
 * Opcoes: -A1 -s4 -k3 -xj -SCNeUpv
 *
 *  * No vi use:
 *      :% !astyle -A1 -s4 -k3 -xj -SCNeUpv
 *  * No linux:
 *      $astlye -A1 -s4 -k3 -xj -SCNeUpv sudoku999.c
 */

/* ---------------------------------------------------------------------- */
/* includes */

#include <stdio.h> /* Standard I/O functions */
#include <stdlib.h> /* Miscellaneous functions (rand, malloc, srand)*/
#include "sudoku999.h" /* To be created for this template if needed */

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
/* #include <pthread.h> */ /* Parallel programming with threads */
/* #include <ncurses.h> */ /* Screen handling and optimisation functions */
/* #include <allegro.h> */ /* A game library for graphics, sounds, etc. */
/* #include <libintl.h> */ /* Internationalization / translation */
/* #include <locale.h> */ /* MACROS LC_ for location specific settings */

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief This is the main event of the evening
 * @details Ladies and Gentleman... It's tiiiime!
 * Fightiiiiing at the blue corner,
 * he, who has compiled more C code than any other adversary in the history,
 * he, who has developed UNIX and Linux, and is an inspiration to maaany languages
 * and compilers, the GNU C Compiler, GCC!
 * Fightiiiiing at the red corner, the challenger, in his first fight, lacking of any
 * valid experience but angrily, blindly, and no doubtfully, will try to
 * compile this program without errors. He, the student, the apprentice,
 * the developer, beco!!
 *
 * @param[in] argc Argument counter
 * @param[in] argv Argument strings (argument values)
 *
 * @retval 0 If succeed (EXIT_SUCCESS).
 * @retval 1 Or another error code if failed.
 *
 * @par Example
 * @code
 *    $./sudoku999 -h
 * @endcode
 *
 * @warning   Be carefull with...
 * @bug There is a bug with...
 * @todo Need to do...
 * @note You can read more about it at <<a href="http://www.beco.cc">www.beco.cc</a>>
 * @author Ruben Carlo Benante
 * @version 20160908.182830
 * @date 2016-09-08
 *
 */
int main(void)
{
    int z; /* flag indicativa de deducao com sucesso */
    int sudoku[9][9][9]={{{0}}}; /* todas as 729 possibilidades */

    IFDEBUG("Starting optarg loop...");

    sudoku999_init(sudoku); /* initialization function: set all candidates to true */


    do
    {
        z=0;
        z+=d1(sudoku); /* naked single */
        z+=d2(sudoku); /* hidden single */
        z+=d3(sudoku); /* naked pair */
        z+=d4(sudoku); /* hidden pair */
        z+=d5(sudoku); /* pointing candidate */
        z+=d6(sudoku); /* claiming candidate */
        z+=d7(sudoku); /* x-wing */
        z+=d8(sudoku); /*xy-wing */
        z+=d9(sudoku); /* x-wing : swordfish */
        z+=d11(sudoku); /* skyscraper */
    }while(z);

    /* backtracking */ 
    if(!check(sudoku)) 
        z=d10(sudoku);  

    printsudoku(sudoku);
    return check(sudoku);
}

/* Write your functions here... */

/* ---------------------------------------------------------------------- */
/* funcoes de apoio */

/**
 * @brief remove o candidato
 * @param [in,out] origem candidatos da celula a ser determinado
 * @param [in] comparador candidatos de outras celulas
 * @author Barbara Valdete Correia da Cunha
 */

void clearcandy(int w[9][9][9], int l, int c, int y[9])
{
    int i;

    for(i=0; i<9; i++)
    {
        if(w[l][c][i]==y[i] && y[i]!=0)
            y[i] = 0;
    }
    return;
}

/* ---------------------------------------------------------------------- */
/* imprime o tabuleiro de sudoku */
void printsudoku(int w[9][9][9])
{
    int i=0,j=0;   
    printf("\n     +-----------+-----------+-----------+\n");
    
    for(i=0; i<9;i++)           
    {                  
        printf("     | %d   %d   %d |  %d   %d   %d |  %d   %d   %d|\n",unico(w[i][j]), unico(w[i][j+1]), unico(w[i][j+2]), unico(w[i][j+3]), unico(w[i][j+4]), unico(w[i][j+5]), unico(w[i][j+6]), unico(w[i][j+7]), unico(w[i][j+8]));      
        if(i==2 || i == 5 || i==8 )          
            printf("     +-----------+------------+-----------+\n");      
    }      
    return;         
}

/* ---------------------------------------------------------------------- */

/**
 * @ingroup GroupUnique
 * @brief Prints help information and exit
 * @details Prints help information (usually called by opt -h)
 * @return Void
 * @author Ruben Carlo Benante
 * @version 20160908.182830
 * @date 2016-09-08
 *
 */
void help(void)
{
    IFDEBUG("help()");
    printf("%s - %s\n", "sudoku999", "Brief description");
    printf("\nUsage: %s [-h|-v]\n", "sudoku999");
    printf("\nOptions:\n");
    printf("\t-h,  --help\n\t\tShow this help.\n");
    printf("\t-V,  --version\n\t\tShow version and copyright information.\n");
    printf("\t-v,  --verbose\n\t\tSet verbose level (cumulative).\n");
    /* add more options here */
    printf("\nExit status:\n\t0 if ok.\n\t1 some error occurred.\n");
    printf("\nTodo:\n\tLong options not implemented yet.\n");
    printf("\nAuthor:\n\tWritten by %s <%s>\n\n", "Ruben Carlo Benante", "rcb@beco.cc");
    exit(EXIT_FAILURE);
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Prints version and copyright information and exit
 * @details Prints version and copyright information (usually called by opt -V)
 * @return Void
 * @author Ruben Carlo Benante
 * @version 20160908.182830
 * @date 2016-09-08
 *
 */
void copyr(void)
{
    IFDEBUG("copyr()");
    printf("%s - Version %s\n", "sudoku999", VERSION);
    printf("\nCopyright (C) %d %s <%s>, GNU GPL version 2 <http://gnu.org/licenses/gpl.html>. This  is  free  software: you are free to change and redistribute it. There is NO WARRANTY, to the extent permitted by law. USE IT AS IT IS. The author takes no responsability to any damage this software may inflige in your data.\n\n", 2016, "Ruben Carlo Benante", "rcb@beco.cc");
    if(verb > 3) printf("copyr(): Verbose: %d\n", verb); /* -vvvv */
    exit(EXIT_FAILURE);
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief This function initializes some operations before start
 * @details Details to be written in
 * multiple lines
 *
 * @pre You need to call foo() before calling this function
 *
 * @param[in] i Input parameter that does bla
 * @param[out] o Parameter that outputs ble
 * @param[in,out] z The @a z variable is used as input and output
 *
 * @retval 0 Returned when bli
 * @retval 1 Error code: function returned blo
 *
 * @par Example
 * @code
 *    if(x == funcexample(i, o, z))
 *       printf("And that is it\n");
 * @endcode
 *
 * @return Void
 *
 * @warning Be carefull with blu
 * @todo Need to implement it. Its empty now. This doxygen tags are overwhelming.
 * Mandatory tags are: ingroup, brief, details, param, return, author and date.
 * The others are optional.
 *
 * @deprecated This function will be deactivated in version +11
 * @see help()
 * @see copyr()
 * @bug There is a bug with x greater than y
 * @note You can read more about it at <<a href="http://www.beco.cc">www.beco.cc</a>>
 *
 * @author Ruben Carlo Benante
 * @version 20160908.182830
 * @date 2016-09-08
 * @copyright Use this tag only if not the same as the whole file
 *
 */
void sudoku999_init(int w[9][9][9])
{
    IFDEBUG("sudoku999_init()");
    /* initialization */

    entrada(w);

    return;
}

/**
 * @brief Coleta a matriz[9][9] do sudoku com alguamas celulas pre definidas
 * e transforma em um matriz[9][9][9] definindo a todos 1 a 9 possibilidades
 * a nao ser que já definido
 * @param [out] w matriz sudoku com seus possiveis candidatos
 * @author Lucas Silva Borges, Barbara Valdete Correia da Cunha
 */

void entrada(int w[9][9][9])
{
    int l, c, k, val;
    char strInput[12];

    for(l=0; l<9 ; l++)
    {
        setbuf(stdin, NULL);
        fgets(strInput, 12, stdin);

        for(c=0; c<9; c++)
        {
            val= strInput[c] - 48;
            if(val != 0)
                w[l][c][val - 1]= 1;
            else
            {
                for(k=0; k<9; k++)
                {
                    w[l][c][k]= 1;
                }
            }
        }
    }
    return;
}
/**
 * @brief Remove candidatos que nao serao usados na propria celula da matriz
 * @author Ricardo Ferreira 
 */

int limparCelula(int w[9][9][9],int l, int c, int d1, int d2, char *hd)
{
   int i;
   int z = 0;
   for(i=1;i<10;i++)
   {
       if(i!=d1 && i!=d2)
       {
           if(w[l][c][i-1]!=0)
           {
               w[l][c][i-1]=0;
               printf("\n%s dado o par %d%c, contendo %i e %i, removemos o candidato %i na celula %d%c",hd, l, c+65,d1, d2,i,l,c+65);
               z++;
           }
       }
   }
   return z;
}

/* ---------------------------------------------------------------------- */
/* acha coordenada superior esquerda do bloco que contem uma celula l,c dada */
/* retorna o numero do bloco e seta as coordenadas em *ql, *qc
 * +---+---+---+
 * | 0 | 1 | 2 | 0,0 0,3 0,6
 * +---+---+---+
 * | 3 | 4 | 5 | 3,0 3,3 3,6
 * +---+---+---+
 * | 6 | 7 | 8 | 6,0 6,3 6,6
 * +---+---+---+
 */
int cbloco(int l, int c, int *ql, int *qc)
{
    int b; /* numero do bloco 0 - 8*/

    b= (c/3) + (l/3) * 3;

    *qc= (int) (b%3) * 3;
    *ql= (int) (b/3) * 3;

    return b;
}

/* ---------------------------------------------------------------------- */
/* acha coordenada superior esquerda do bloco n dado */
/* retorna void
 * +---+---+---+
 * | 0 | 1 | 2 | 0,0 0,3 0,6
 * +---+---+---+
 * | 3 | 4 | 5 | 3,0 3,3 3,6
 * +---+---+---+
 * | 6 | 7 | 8 | 6,0 6,3 6,6
 * +---+---+---+
 */
void bloco(int n, int *ql, int *qc)
{
    *qc= (int) (n%3) * 3;
    *ql= (int) (n/3) * 3;

    return;
}

/* ---------------------------------------------------------------------- */
/**
 * @brief Verifica se a celula possui apenas um candidato
 * @param [in] y lista de possiveis candidatos
 * @retval 0 caso haja mais de um candidato
 * @retval n caso haja um unico valor, 1<= n <= 9
 * @author Lucas Silva Borges
 */
int unico(int y[9])
{
    int i, cont= 0, unico;

    for(i=0; i<9 && cont < 2; i++)
    {
        if(y[i] != 0)
        {
            cont++;
            unico= i+1;
        }
    }

    if(cont == 1)
        return unico;

    return 0;
}
/* ---------------------------------------------------------------------- */
/* funcao para contar o total de candidatos em uma celula*/

int totalcandy(int y[9]){
         int i, cont=0;

         for(i=0;i<9; i++){
    
              if(y[i] != 0)      /* para cada vez que sera verdadeiro, sera adicionado 1 na variavel cont*/
                  cont++;
    
         }
         return cont;
}


/* ----------------------------------------------------------------------- */
/* naked single: remove candidatos de linhas e colunas  */


int remover(int recebe, int w[9][9][9], int l, int c, char tipo, char *hd)
{
    int j;
    int z = 0; /* variavel a ser retorndada, valor zerado, pois se não obtiver sucesso, o retorno será zero */

    switch (tipo)
    {

        case 1: /* parametro constante --> linha   */
            for (j = 0; j < 9; j++) 
            {
                if (j != c && w[l][j][recebe-1]!=0)
                {   
                    w[l][j][recebe-1] = 0; 
                    printf("\n%s dado que a celula %d%c contem apenas o cadidato %d, remove o mesmo como candidato de %d%c",hd, l+1, c+65, recebe, l+1,j+65);    
                    z++;
                }
            } 
            break;

        case 2:        
            for (j = 0; j < 9; j++) 
            {
                if (j != l && w[j][c][recebe-1]!=0)
                {   
                    w[j][c][recebe-1] = 0; 
                    printf("\n%s dado que a celula %d%c contem apenas o cadidato %d, remove o mesmo como candidato de %d%c",hd, l+1, c+65, recebe, j+1,c+65);    
                    z++;
                }
            } 

            break;
        default:
            break;
    }
    return z;
}

/* ---------------------------------------------------------------------- */
int removexwing(int recebe, int w[9][9][9], int l, int c, int arg2, int tipo, char *hd)
{
    int i, d ;
    int z = 0; /* flag que identifica se ocorreu mudança */

    switch(tipo)
    {
        case 1: /* remove candidato da coluna */
            for(i=0;i<9;i++)
            {
                if(i==l || i==arg2)
                    continue;
                for(d=0;d<9;d++)
                        if(d == recebe && w[i][c][d]!=0)
                        {
                            w[i][c][d]=0;
                            printf("\n%s dado que o candidato %d está presente no par %d%c e %d%c, remove ele de %d%c",hd, d+1, l+1, c+65, arg2+1,c+65,i+1,c+65);
                            z=1;
                        }
            }
            break;
        case 2: /* remove candidato da linha */
            for(i=0;i<9;i++)
            {
                if(i==c || i==arg2)
                    continue;
                for(d=0;d<9;d++)
                    if(d==recebe && w[l][i][d]!=0)
                    {
                        w[l][i][d]=0;
                            printf("\n%s dado que o candidato %d está presente no par %d%c e %d%c, remove ele de %d%c",hd, d+1, l+1, c+65, l+1,arg2+65,l+1,i+65);
                            z=1;
                    }
            }
            break;
        default:
            break;
    }
    return z;
}
/* ---------------------------------------------------------------------- */
/*skyremove: remove os candidatos na funcao skyscraper */

int skyscraper(int w[9][9][9], int d, int l1, int l2, int c1, int c2, char *hd)
{
    int z=0;
    int i,ls,cs;

    for(i=0;i<9;i++)
    {
        if(cbloco(i,c1,&ls,&cs)==cbloco(l2,c2,&ls,&cs) && i!=l1)
        {
            if(w[i][c1][d]==w[l1][c1][d])
            {
                w[i][c1][d]=0;
                printf("\n%s",hd); /* print para tirar warning  */
                z=1;
            }
        }
        if(cbloco(l1,i,&ls,&cs)==cbloco(l2,c2,&ls,&cs) && i!=c1)
        {
            if(w[l1][i][d]==w[l1][c1][d])
            {
                w[l1][i][d]=0;
                printf("\n%s",hd); /* print para tirar warning  */
                z=1;
            }
        }
    }
                      
    return z;
}

/* naked single: remove candidatos de linhas e colunas  */
int removebloco(int w[9][9][9], int recebe, int l, int c, int lb, int cb, char *hd)
{
    int coluna,
        linha;
    int z=0;

    for ( linha = lb; linha < lb+3; linha++)
    {
        for ( coluna = cb; coluna < cb+3; coluna++)
        {
            if ((linha != l || coluna != c) && w[linha][coluna][recebe-1]!=0)
            {
                w[linha][coluna][recebe-1]=0;
                printf("\n%s dado que a celula %d%c contem apenas o cadidato %d, remove o mesmo como candidato de %d%c",hd, l+1, c+65, recebe, linha+1,coluna+65);
                z++;
            }
        }
    }
    return z;
}

/* ---------------------------------------------------------------------- */
/* check if sudoku is solved, incomplete or invalid */

int check(int w[9][9][9])
{
    int i,j;
    for(i=0;i<9;i++)
        for(j=0;j<9;j++)
        {
            if(unico(w[i][j]))
                continue;
            return 0;
        }
    return 1;
}

/* ---------------------------------------------------------------------- */
/* funcoes de deducao de d1 a d8 */


/* ---------------------------------------------------------------------- */
/* naked single : peladao */
/* d1 : naked sigle
 * limpa linha: confronta cada valor ja deduzido com sua linha (horizontal) limpando falsas possibilidades
 *
 * Explicacao:
 *      percorre todas as 9x9 celulas da grade (cada celula contem 9 possibilidades)
 *      Para cada celula que achar que tiver o valor ja determinado (unica possibilidade), 
 *      percorre a horizontal que ela pertence e remove nas outras celulas dessa horizontal 
 *      a possibilidade deste valor que nao pode ser repetido
 */

/* 1- naked single : peladao : 
   --> quando as possibilidades de uma celula se reduzem a um unico numero, ele e o valor correto.

   se um numero foi deduzido, remove-se o mesmo como candidato nas outras celulas da mesma linha, coluna ou bloco

algoritmo: fixa celula e gira digito, comparando-o com os grupos (linha, coluna, bloco), ate reduzir suas possibilidades a apenas uma.

*/
int d1(int w[9][9][9])
{
    int z=0;
    z+=d1l(w); /* naked single : line */
    z+=d1c(w); /* naked single : column */
    z+=d1b(w); /* naked single : block */
    return z;
}

/* ---------------------------------------------------------------------- */
/* hidden single : peladao escondido */
/* d2: procura um numero que aparece apenas uma vez na linha */
/* Explicacao:
 *      Procura, para cada celula, uma que nao tem valor definido e chame-a de celula com n candidatos.
 *      Percorre a horizontal da celula com n candidatos e remove candidatos que se repetem
 *      Ao final, se restar apenas um candidato na celula fixada inicialmente, este eh o valor
 *      correto da celula.
 * 
 *      Exemplo, o valor 7 para a celula a7. Inicialmente os candidatos sao 1, 3, 6 e 7
 *      Percorrendo a horizontal e removendo os repetidos sobra apenas o 7 como possibilidade

 a   b   c   d   e   f   g   h   i
 +===========+===========+===========+
 |1 3:1 3:   |1  :  3:   |   :   : 2 |
 7  |  6:  6:   |   :  6:4 6| 5 :   :   |
 |7  :   :  9|   :   :   |   : 8 :   |
 +-----------+-----------+-----------+
 */

/* 2- hidden single : peladao escondido :
   --> mesmo que tenham mais candidatos, se em uma celula tem um valor que nao aparece nas outras da mesma linha, coluna ou bloco, ele eh o solteirao escondido.

 * uma celula com multiplos candidatos eh chamada de solteirao se um dos candidatos so
 * aparece em um local na linha, coluna ou bloco. Ele e a solucao e os outros candidatos podem ser eliminados

algoritmo: 

*/
int d2(int w[9][9][9])
{
    int z=0;
    z+=d2l(w); /* hidden single : line */
    z+=d2c(w); /* hidden single : column */
    z+=d2b(w); /* hidden single : block */
    return z;
}

/* ---------------------------------------------------------------------- */
/* naked pair : dupla pelada */
/* naked pair:
 *
 * para cada conjunto de 2 celulas
 * quando tiverem os mesmo 2 candidatos e apenas eles
 * retira das outras celulas do grupo esses candidatos
 *
 * naked tuple: (todos grupos: linha, coluna e bloco)
 * N>1 celulas exatamente iguais com N candidatos cada
 *
 * >> retira das outras celulas do grupo esses numeros
 *
 * Upgrade: N>1 celulas com APENAS N candidatos em comum
 *
 */

/* 3- naked pair : dupla pelada : 

 * duas celulas com o mesmo par de candidatos e apenas ele, chama-se dupla pelada.
 * os valores do par sao removidos do grupo (bloco, linha ou coluna) em que se encontram
 * sobrando somente a duvida do par
 */

/* Opcional: 3.b- naked triple : tripla pelada : ocorre quando 3 celulas em uma mesma linha, coluna ou bloco contem os
 * apenas os mesmos tres candidatos; ou um subconjunto deles. Todas as aparencias dos 3 candidatos podem ser
 * eliminadas do resto do bloco, linha ou coluna
 */


/* Opcional: 3.c- naked quad : quatro pelados : quatro celulas com os mesmos quatro candidatos ou subconjuntos, em uma mesma
 * linha, coluna ou bloco, implicam que os mesmos candidatos em outras celulas no bloco ou seguindo a linha ou
 * coluna respectiva podem ser eliminados.
 */

int d3(int w[9][9][9])
{
    int z = 0;

    z += d3l(w);
    z += d3c(w);
    z += d3b(w);
    return z;
}

/* ---------------------------------------------------------------------- */
/* hidden pair : dupla escondida */
/*
 * Se X candidatos em um grupo estao apenas em X celulas compartilhadas, pode-se limpar
 * os outros candidatos dessas X celulas, sobrando apenas os candidatos repetidos.
 * Afeta: apenas as celulas da tupla.
 *
 * O par escondido quando limpo se transforma em par pelado
 *
 */

/* 4- hidden pair : dupla escondida
 *
 * quando dois candidatos aparecem em apenas duas celulas, em um grupo (linha, coluna ou bloco)
 * mesmo que estas celulas estejam com mais candidatos
 * os demais podem ser eliminados dessas duas celulas, restando assim uma dupla pelada.
 */
int d4(int w[9][9][9])
{
    int z=0;
    z+=d4l(w); /* hidden pair : line */
    z+=d4c(w); /* hidden pair : column */
    z+=d4b(w); /* hidden pair : block */
    return z;
}

/* ---------------------------------------------------------------------- */
/* pointing candidate : candidato dedo-duro */
/* pointing pair : dedo-duro
 * quando um candidato esta dentro de um bloco em apenas duas ou tres celulas
 * alinhadas em linha ou coluna, chama-se dedo-duro. O numero do candidato pode ser removido
 * da linha ou coluna que se estende para fora do bloco. Parecido com o 5, mas aqui remove de linha ou coluna,
 * enquanto la remove de bloco.
 * 
 * Pointing: um certo candidato de um bloco so aparece numa reta: limpa o restante da reta
 * Claiming: um certo candidato de uma reta so aparece em um bloco: limpa o restante do bloco
 * 
 */

/* 5- pointing pair : dedo-duro : quando um candidato esta dentro de um bloco em apenas duas ou tres celulas
 * alinhadas em linha ou coluna, chama-se dedo-duro. O numero do candidato pode ser removido
 * da linha ou coluna que se estende para fora do bloco. Parecido com o 5, mas aqui remove de linha ou coluna,
 * enquanto la remove de bloco.
 */
int d5(int w[9][9][9])
{
    int z=0;
    z+=d5l(w); /* pointing candidate : line */
    z+=d5c(w); /* pointing candidate : column */
    return z;
}

/* ---------------------------------------------------------------------- */
/* claiming pair : exigente : quando um certo candidato precisa estar numa certa linha ou coluna, a linha ou coluna o requisita. Se as possibilidades para essa linha ou coluna estao apenas em um bloco, mantem-se os candidatos na linha ou coluna que intersecciona o bloco, mas remove-se o mesmo do restante do bloco.
 * A linha ou coluna o requisita,
 * logo todas outras celulas deste bloco fora da linha ou coluna, podem ter este numero canditado removido. Parecido com 4, mas aqui remove do bloco, la da linha ou coluna.
 * 
 * Pointing: um certo candidato de um bloco so aparece numa reta: limpa o restante da reta
 * Claiming: um certo candidato de uma reta so aparece em um bloco: limpa o restante do bloco
 * 
 */

/* 6- claiming pair : exigente : quando um certo candidato precisa estar numa certa linha ou coluna, a linha ou coluna o requisita. Se as possibilidades para essa linha ou coluna estao apenas em um bloco, mantem-se os candidatos na linha ou coluna que intersecciona o bloco, mas remove-se o mesmo do restante do bloco.
 * A linha ou coluna o requisita,
 * logo todas outras celulas deste bloco fora da linha ou coluna, podem ter este numero canditado removido. Parecido com 4, mas aqui remove do bloco, la da linha ou coluna.
 */
int d6(int w[9][9][9])
{
    int z=0;
    z+=d6l(w); /* claiming candidate : line */
    z+=d6c(w); /* claiming candidate : column */
    return z;
}

/* ---------------------------------------------------------------------- */
/* x-wing : cruzamento em x */

/* 7- x-wing : cruzamento : quando um candidato aparece em quatro celulas que formam os cantos de um retangulo ou quadrado,
 * e aparece somente em duas celulas para cada uma das linhas, o candidato pode ser removido das colunas.
 * Idem para o inverso entre colunas e linhas.
 */
int d7(int w[9][9][9])
{
    int z=0;
    z+=d7l(w); /* x-wing : line */
    z+=d7c(w); /* x-wing : column */
    return z;
}
/* ---------------------------------------------------------------------- */
/* 8- xy-wing : algoritmo que busca um pivô com 2 candidatos e em seguida 2 celulas no mesmo grupo que o pivo, tambem com 2 candidatos cada.
 * Um desses candidatos deve ser igual a um dos candidatos do pivô, e o outro deve ser igual a outra celula.
 * O candidato que se repete nas celulas deve ser removido das celulas amigas.
 */
int d8(int w[9][9][9])
{
    int z=0;
    z+=d8l(w);
    return z;
}
/* ---------------------------------------------------------------------- */
/* backtracking - retroanalise */
/* 8- Backtraking: algoritmo recursivo que tenta todas possibilidades */
int d10(int w[9][9][9])
{
    int z=0;
    z=tenta8(w); /* backtracking recursive */
   return z;
}

/* --------------------------------------------------------------------- */
/* w-wing : swordfish */
/*9- w-wing : swordfish : variacao do w-wing, que em vez de pegar apenas 4 celulas que possuem o mesmo candidato,no formato de retangulo ou quadrado, 
 * pega de 2 ou 3 linhas ou colunas, removendo depois o candidado das respectivas linhas e colunas */
int d9(int w[9][9][9])
{
  int z=0;
  z+=d9l(w); /* swordfish : line */
  z+=d9c(w); /* swordfish : column */
  return z;
}
/* --------------------------------------------------------------------- */
/*11 - skyscraper : 
 * 
 * */
int d11(int w[9][9][9])
{
  int z=0;
  z+=d11l(w); /* swordfish : line */
  z+=d11c(w); /* swordfish : column */
  return z;
}
/* ---------------------------------------------------------------------- */
/* deducoes divididas por grupo: linha, coluna e bloco */

/* ---------------------------------------------------------------------- */
/* naked single : line */
/* naked single: confronta cada valor ja deduzido com sua linha (horizontal) */
int d1l(int w[9][9][9])
{
    char *hd="d1l: naked single (line)";
    int l, c,d,fd, /* indices para rodar o mapa inteiro */
        unico,
        z=0;; /* flag que indica se ocorreu deducao */
    for ( c = 0; c < 9; c++)
    {
        for ( l = 0; l < 9; l++)
        {
            fd =0;    
            for(d=0 ; d<9 ;d++)
            {
                if(w[l][c][d] == 1)
                {
                    fd++;
                    unico=d;
                }
                if(fd>1)
                {
                    break;
                }
 
            }
            if(fd==1)
            {
                z = remover(unico+1, w, l, c, 1, hd);
            }

        }

    }
    return z;
}
/* ---------------------------------------------------------------------- */
/* naked single : column */
/* naked single: confronta cada valor ja deduzido com sua coluna (vertical) */
int d1c(int w[9][9][9])
{
    char *hd="d1c: naked single (column)";
    int l, c,d,fd, /* indices para rodar o mapa inteiro */
        unico,
        z=0;; /* flag que indica se ocorreu deducao */



    for ( l = 0; l < 9; l++)
    {
        for ( c = 0; c < 9; c++)
        {
            fd =0;    
            for(d=0 ; d<9 ;d++)
            {
                if(w[l][c][d] == 1)
                {
                    fd++;
                    unico=d;
                }
                if(fd>1)
                {
                    break;
                }
 
            }
            if(fd==1)
            {
                z = remover(unico+1, w, l, c, 2, hd);
            }
        }

    }
    return z;
}

/* ---------------------------------------------------------------------- */
/* naked single : block */
/* naked single: confronta cada valor ja deduzido com seu quadrado (bloco) */
int d1b(int w[9][9][9])
{
    int l, c, /* indices para rodar o mapa inteiro */
        ls, /* linha do bloco */
        cs, /* linha do bloco */
        b,
        d,
        fd,/* numeracao do bloco  */
        unico; /* variavel recebe valor para retirar os candidatos */
    int z=0; /* flag que indica se ocorreu deducao */
    char *hd="d1b: naked single (block)";

    for ( b = 0; b < 9; b++)
    {
        bloco(b,&ls,&cs);
        for ( l = ls; l < ls+3; l++)
        {
            for(c = cs ; c < cs + 3 ; c++)
            {
               fd=0;
               for(d=0;d<9;d++)
               {
                    if(w[l][c][d]==1)
                    {
                        fd++;
                        unico=d;
                    }
                    if(fd>1)
                        break;
               }
               if(fd==1)
               {
                    z = removebloco(w, unico+1, l, c, ls, cs, hd);
               }
            }
         }
     }

    return z;
}

/* ---------------------------------------------------------------------- */
/* hidden single : linha */
/* hidden single: procura numa horizontal um numero com apenas uma celula possivel de estar */
int d2l(int w[9][9][9])
{
    int l, c, j, x, z=0;
    int candy[9]; 
    char *hd="d2l: hidden single (line)";

    for(l=0; l<9; l++)
        for(c=0; c<9; c++)
        {
            if(!unico(w[l][c]))
            {
                for(x=0;x<9;x++)
                    candy[x] = w[l][c][x];

                for(j=0; j<9; j++)
                {
                    if(j==c)
                        continue;
                    clearcandy(w,l,j,candy);
                }

                if(totalcandy(candy)!=1)
                    continue;
                else if(w[l][c]!=candy)
                {
                    for(x=0;x<9;x++)
                    {
                        w[l][c][x]=candy[x];
                        if(candy[x]!=1)
                            printf("\n%s dado que a celula %d%c contem apenas um cadidato, remove o candidato %d da celula",hd, l+1, c+65,x+1);    
                    }
                    z=1;
                }
            }
        }
     
   
    return z;

}

/* ---------------------------------------------------------------------- */
/* hidden single : column */
/* hidden single: procura numa vertical um numero com apenas uma celula possivel de estar */
int d2c(int w[9][9][9])
{
    
    int l, c, i, x, z=0; /* flag que indica se ocorreu deducao */
    int candy[9]; 
    char *hd="d2c: hidden single (column)";

    for(c=0; c<9; c++)
        for(l=0; l<9; l++)
        {
            if(!unico(w[l][c]))
            {
                for(x=0;x<9;x++)
                    candy[x]=w[l][c][x];
                for(i=0; i<9; i++)
                {
                    if(i==l)
                        continue;      
                    clearcandy(w, i, c, candy);
                }
                if(totalcandy(candy)!=1)
                    continue;
                else if(w[l][c]!=candy)
                {
                    for(x=0;x<9;x++)
                    {
                        w[l][c][x]=candy[x];
                        if(candy[x]!=1)
                            printf("\n%s dado que a celula %d%c contem apenas um candidato, remove o candidato %d da celula",hd, l+1,c+65,x+1);
                    }
                    z=1;
                }
            }
        }

     
     
    return z;
}

/* ---------------------------------------------------------------------- */
/* hidden single : block */
/* hidden single: procura num bloco um numero com apenas uma celula possivel de estar */
int d2b(int w[9][9][9])
{
    int l, c, ls, cs, i, j, b, x, z=0; /*flag que indica se ocorreu deducao */
    int candy[9]; 
    char *hd="d2b: hidden single (block)";

    for(b=0;b<9;b++)
    {
        bloco(b, &ls, &cs);
        for(l=ls;l<ls+3;l++)
            for(c=cs;c<cs+3;c++)
            {
                
                if(!unico(w[l][c]))
                {
                    for(x=0;x<9;x++)
                        candy[x]=w[l][c][x];
                    for(i=0; i<ls+3; i++)
                    {
                        for(j=0; j<ls+3; j++)
                        {
                            if(i==l && j==c)
                                continue;
                            clearcandy(w,i,j,candy);
                        }
                    }
                    if(totalcandy(candy)!=1)
                        continue;
                    else if(w[l][c]!=candy)
                    {
                        for(x=0;x<9;x++)
                        {
                            w[l][c][x]=candy[x];
                            if(candy[x]!=1)
                                printf("\n%s dado que a celula %d%c contem apenas um candidato, remove o candidato %d da celula",hd, l+1,c+65,x+1);
                        }
                        z=1;
                    }
                }
            }
    } 
    return z;
}

/* ---------------------------------------------------------------------- */
/*Funcoes d3*/
int d3l(int w[9][9][9])
{
  int l, c1, c2, ded[2], d, ls, cs, cont, z=0,fno;
  char *hd = "d3l: naked pair (line)";

  for(l=0;l<9;l++)
      for(c1=0;c1<9;c1++)
          for(c2=0;c2<9;c2++)
          {
              if(c1==c2)
                  continue;
              if(totalcandy(w[l][c1])!=2 || totalcandy(w[l][c2])!=2)
                  continue;
              fno=0;
              cont=0;
              for(d=0;d<9;d++)
              {
                  if(w[l][c1][d]!=w[l][c2][d])
                  {
                      fno=1;
                      break;
                  }
                  else if(w[l][c1][d]==1)
                  {
                      ded[cont]=d;
                      cont++;
                  }
              }            
              if(fno)
                  continue;
              z = removepair(ded,w,l,c1,c2,1,hd);
              if(cbloco(l,c1,&ls,&cs) == cbloco(l,c2,&ls,&cs))
                  z = removepair(ded,w,l,c1,c2,3,hd);
          }
  return z;
}
/* ---------------------------------------------------------------------- */

int d3b (int w[9][9][9])
{
    int d,ded[2],l1,l2,c1,c2,b,ls,cs,cont,z=0,fno;
    char *hd= "d3b: naked pair(block)";
    
    for(b=0;b<9;b++)
    {
        bloco(b,&ls,&cs);
        for(l1=0;l1<ls+3;l1++)
            for(c1=0; c1<cs+3; c1++)
                for(l2=l1+1; l2<ls+3;l2++)
                    for(c2=c1+1;c2<ls+3;c2++)
                    {
                        if(l1==l2 && c1==c2)
                            continue;
                        if(totalcandy(w[l1][c1])!=2||totalcandy(w[l2][c2])!=2)
                            continue;
                        fno=0;
                        cont = 0;
                        for(d=0;d<9;d++)
                        {
                            if(w[l1][c1][d]!=w[l2][c2][d])
                            {
                                fno=1;
                                break;
                            }
                            else if(w[l1][c1][d]==1)
                            {
                                ded[cont]=d;
                                cont++;
                            }
                        }
                        if(fno)
                            continue;
                        z=removepairb(ded,w,l1,c1,l2,c2,hd);
                    }
    }
    return z;
}
/* ---------------------------------------------------------------------- */

int d3c (int w[9][9][9])
{
    int l1, l2, c, d, ded[2], cont, ls, cs, z=0, fno;
    char *hd = "d3c: naked pair (column)";

    for(c=0;c<9;c++)
        for(l1=0;l1<9;l1++)
            for(l2=0;l2<9;l2++)
            {
                if(l1==l2)
                    continue;
                if(totalcandy(w[l1][c])!=2 || totalcandy(w[l2][c])!=2)
                    continue;
                fno=0;
                cont=0;
                for(d=0;d<9;d++)
                {
                    if(w[l1][c][d]!=w[l2][c][d])
                    {
                        fno=1;
                        break;
                    }
                    else if(w[l2][c][d]==1)
                    {
                        ded[cont]=d;
                        cont++;
                    }
                }

                if(fno)
                    continue;
                z=removepair(ded,w,l1,c,l2,2,hd);
                if(cbloco(l1,c,&ls,&cs)==cbloco(l2,c,&ls,&cs))
                    z= removepair(ded,w,l1,c,l2,4,hd);
            }
    return z;
}
int removepair(int recebe[2], int w[9][9][9], int l, int c, int arg2, int tipo, char *hd)
{
    int i, j, d, d2, ls, cs;
    int z = 0; /* flag que identifica se ocorreu mudança */

    switch(tipo)
    {
        case 1: /* remove par da linha */
            for(i=0;i<9;i++)
            {
                if(i==c || i==arg2)
                    continue;
                for(d=0;d<9;d++)
                    for(d2=0;d2<2;d2++)
                        if(d == recebe[d2] && w[l][i][d]!=0)
                        {
                            w[l][i][d]=0;
                            printf("\n%s dado que o candidato %d está presente no par %d%c e %d%c, remove ele de %d%c",hd, d+1, l+1, c+65, l+1,arg2+65,l+1,i+65);
                            z=1;
                        }
            }
            break;
        case 2:
            for(i=0;i<9;i++)
            {
                if(i==l || i==arg2)
                    continue;
                for(d=0;d<9;d++)
                    for(d2=0;d2<2;d2++)
                        if(d == recebe[d2] && w[i][c][d]!=0)
                        {
                            w[i][c][d]=0;
                            printf("\n%s dado que o candidato %d está presente no par %d%c e %d%c, remove ele de %d%c",hd, d+1, l+1, c+65, arg2+1,c+65,i+1,c+65);
                            z=1;
                        }
            }
            break;
        case 3:
            cbloco(l,c,&ls,&cs);
            for(i=ls;i<ls+3;i++)
                for(j=cs;j<cs+3;j++)
                {
                    if((i==l && j==c) || (i==l && j==arg2))
                        continue;
                    for(d=0;d<9;d++)
                        for(d2=0;d2<2;d2++)
                            if(d==recebe[d2] && w[i][j][d]!=0)
                            {
                                w[i][j][d]=0;
                                printf("\n%s dado que o candidato %d está presente no par %d%c e %d%c, remove ele de %d%c",hd, d+1, l+1, c+65, l+1,arg2+65,i+1,j+65);
                                z=1;
                             }
                }
            break;
        case 4:
            cbloco(l,c,&ls,&cs);
            for(j=cs;j<cs+3;j++)
                for(i=ls;i<ls+3;i++)
                {
                    if((j==c && i==l) || (j==c && i==arg2))
                            continue;
                    for(d=0;d<9;d++)
                        for(d2=0;d2<2;d2++)
                            if(d==recebe[d2] && w[i][j][d]!=0)
                            {
                                w[i][j][d]=0;
                                printf("\n%s dado que o candidato %d está presente no par %d%c e %d%c, remove ele de %d%c",hd, d+1, l+1, c+65, arg2+1,c+65,i+1,j+65);
                                z=1;

                            }
                                
                }
            break;
        default:
            break;
    }
    return z;
}
int removepairb(int recebe[2], int w[9][9][9], int l1, int c1, int l2, int c2, char *hd)
{
    int i,j,d,d2,ls,cs;
    int z=0; /* flag que indica se houve deducao */

    cbloco(l1,c1,&ls,&cs);
    for(i=ls;i<ls+3;i++)
        for(j=cs;j<cs+3;j++)
        {
            if((i==l1 && j==c1) || (i==l2 && j==c2))
                continue;
            for(d=0;d<9;d++)
                for(d2=0;d<2;d++)
                    if(d==recebe[d2] && w[i][j][d]!=0)
                    {
                        w[i][j][d]=0;
                        printf("\n%s dado que o candidato %d está presente no par %d%c e %d%c, remove ele de %d%c",hd, d+1, l1+1, c1+65, l2+1,c2+65,i+1,j+65);
                        z=1;
                    }
        }
    return z;
}

/* ---------------------------------------------------------------------- */
/* hidden pair : line */
int d4l(int w[9][9][9])
{
    int z=0; /* flag que indica se ocorreu deducao */
    char *hd="d4l: hidden pair (line)";
    
    int l,c1,c2, d1, d2, check, fc;
    
    for(l=0;l<8;l++)
        for(c1=0;c1<8;c1++)
            for(c2=c1+1;c2<9;c2++)
            {
                if(c1==c2)
                    continue;
                if(totalcandy(w[l][c1])<2 || totalcandy(w[l][c2])<2)
                    continue;
                if(totalcandy(w[l][c1])==2 && totalcandy(w[l][c2])==2)
                    continue;
                for(d1=1;d1<9;d1++)
                {           
                   if(w[l][c1][d1]==w[l][c2][d1])
                        for(d2=d1+1;d2<10;d2++)
                            if(w[l][c1][d2]==w[l][c2][d2])
                            {
                                for(check=c2+1;check<9;check++)
                                { 
                                    fc=0;
                                    if(w[l][check][d1]==w[l][c2][d1] || w[l][check][d2]==w[l][c2][d2])
                                    {
                                        fc=1;
                                        break;
                                    }
                                }
                                if(fc)
                                    continue;
                                z = z + limparCelula(w,l,c1,d1,d2,hd);
                                z = z + limparCelula(w,l,c2,d1,d2,hd);
                            }
                
                }
            }
    return z;
}
/* ---------------------------------------------------------------------- */
/* hidden pair : column */
int d4c(int w[9][9][9])
{
    int z=0; /* flag que indica se ocorreu deducao */
    char *hd="d4c: hidden pair (column)";
    
    int c,l1,l2, d1, d2, check, fc;
    
    for(c=0;c<9;c++)
        for(l1=0;l1<8;l1++)
            for(l2=l1+1;l2<9;l2++)
            {
                if(l1==l2)
                    continue;
                if(totalcandy(w[l1][c])<2 || totalcandy(w[l2][c])<2)
                    continue;
                if(totalcandy(w[l1][c])==2 && totalcandy(w[l2][c])==2)
                    continue;
                for(d1=1;d1<9;d1++)
                {                
                    if(w[l1][c][d1]==w[l2][c][d1])
                        for(d2=d1+1;d2<10;d2++)
                            if(w[l1][c][d2]==w[l2][c][d2])
                            {
                                for(check=l2+1;check<9;check++)
                                { 
                                    fc=0;
                                    if(w[check][c][d1]==w[l2][c][d1] || w[check][c][d2]==w[l2][c][d2])
                                    {
                                        fc=1;
                                        break;
                                    }
                                }
                                if(fc)
                                    continue;
                                z = z + limparCelula(w,l1,c,d1,d2,hd);
                                z = z + limparCelula(w,l2,c,d1,d2,hd);
                            }
                }
            }
    return z;
}
/* ---------------------------------------------------------------------- */
/* hidden pair : block */
int d4b(int w[9][9][9])
{
    int z=0; /* flag que indica se ocorreu deducao */
    int l1,l2,ls,c1,c2,cs,b,d1,d2,check1,check2,fc;
    char *hd="d4b: hidden pair (block)";


    for(b=0; b<9; b++)  /* laço para percorrer a matriz no ponto de vista de blocos */
    {
        bloco(b, &ls, &cs);
        for(l1=ls;l1<ls+3;l1++)
            for(c1=cs;c1<cs+3;c1++)
                for(l2=ls;l2<ls+3;l2++)
                    for(c2=cs;c2<cs+3;c2++)
                    {
                        if(l1==l2 && c1==c2)  /* checando linhas e colunas */
                            continue;
                        if(totalcandy(w[l1][c1])<2 || totalcandy(w[l2][c2])<2) /* checando se os candidatos sao compativeis com a tecnica */ 
                            continue;
                        if(totalcandy(w[l1][c1])==2&&totalcandy(w[l2][c2])==2)
                            continue;

                        for(d1=1;d1<9;d1++)  /* laço para decidir os valores a serem removidos */
                        {
                            if(w[l1][c1][d1]==w[l2][c2][d1])
                                for(d2=d1+1;d2<10;d2++)
                                    if(w[l1][c1][d2]==w[l2][c2][d2])
                                    {
                                        for(check1=0;check1<9;check1++)
                                        {
                                            for(check2=0;check2<9;check2++)
                                            {
                                                if((check1 == l1 && check2==c1) || (check1==l2 && check2==c2))
                                                    continue;
                                                fc=0;
                                                if(w[check1][check2][d1]==w[l1][c1][d1] || w[check1][check2][d2]==w[l1][c1][d2])
                                                {
                                                    fc=1;
                                                    break;
                                                }
                                            }
                                            if(fc)
                                                break;
                                            
                                            z = z + limparCelula(w,l1,c1,d1,d2,hd); 
                                            z = z + limparCelula(w,l2,c2,d1,d2,hd);
                                        }
                                    }
                        }
                    }
    }                
    return z;
}

    
/* ---------------------------------------------------------------------- */
/* pointing candidates : dedo-duro : linha */
int d5l(int w[9][9][9])
{
    int i, c, l, d, b, ls, cs, fd, fl; /*fd e fl flags*/
    int z=0; /* flag que indica se ocorreu deducao */
    char *hd="d5l: pointing pair (line)";
    if(check(w))
        return z;

    for(b=0; b<9; b++)     /*laco que roda o bloco*/
    {
        bloco(b, &ls, &cs);
        for(d=0;d<9;d++)  /*laco que roda os digitos de 1 a 9*/
        {
            for(l=ls;l<ls+3;l++)
            {
                for(c=cs;c<cs+3;c++)
                {
                    fd=0;          /*flag do digito, inicializa um numero que vai ser testado*/
                    if(w[l][c][d]==1)
                    {
                        fd=1;
                        break;
                    }
                }
                if(fd)
                {
                    fl=0;   /*flag da linha*/
                    for(i=l+1; i<ls+3; i++)
                        for(c=cs;c<cs+3;c++)
                            if(w[i][c][d]==1)
                            {
                                fl=1;
                                break;
                            }
                    if(fl==0)
                    {    
                        z=externalremove(d, w, l, cs,b, 1, hd);
                        
                    }
                }
            }
        }
    } 
    return z;
}

/* ---------------------------------------------------------------------- */
/* pointing candidates : dedo-duro : coluna */
int d5c(int w[9][9][9])
{
    int i, c, l, d, b, ls, cs, fd, fc; /*fd e fl flags*/
    int z=0; /* flag que indica se ocorreu deducao */
    char *hd="d5c: pointing pair (column)";
    if(check(w))
        return z;
    
    for(b=0; b<9; b++)     /*laco que roda o bloco*/
    {
        bloco(b, &ls, &cs);
        for(d=0;d<9;d++)  /*laco que roda os digitos de 1 a 9*/
        {
            for (c=cs;c<cs+3;c++)
            {
                for(l=ls;l<ls+3;l++)
                {
                    fd=0;
                    if(w[l][c][d]==1)
                    {
                        fd=1;
                        break;
                    }
                }
                if(fd)
                {
                    fc=0;
                    for(i=c+1;i<cs+3;i++)
                        for(l=ls;l<ls+3;l++)
                            if(w[l][i][d]==1)
                            {
                                fc=1;
                                break;
                            }
                    if(fc==0)
                    {
                        z=externalremove(d,w,c,ls,b,2,hd);
                    }
                }
            }
        }
    } 
    return z;
}

/* ---------------------------------------------------------------------- */
int externalremove(int recebe, int w[9][9][9], int fixo, int variavel, int nbloco, int tipo, char *hd)
{
    int i, j;
    int z = 0; /* flag de retorno caso haja dedução */

    switch(tipo)
    {
        case 1: /* remove linha */
            for(i=0;i<9;i++)
            {
                if(i!=variavel && i!=variavel+1 && i!=variavel+2 && w[fixo][i][recebe]!=0)
                {
                    w[fixo][i][recebe]=0;
                    printf("\n%s dado que o candidato %d esta apenas na linha %d no bloco %d, remove o mesmo como candidato do resto da linha %d",hd,recebe+1, fixo+1,nbloco, fixo+1);
                    z=1;
                }
            }
            break;
        case 2:
            for(j=0;j<9;j++)
            {
                if(j!=variavel && j!=variavel+1 && j!=variavel+2 && w[j][fixo][recebe]!=0)
                {
                    w[j][fixo][recebe]=0;
                    printf("\n%s dado que o candidato %d esta apenas na coluna %c no bloco %d, remove o mesmo como candidato do resto da coluna %c",hd, recebe+1, fixo+65,nbloco,fixo+65);    
                    z=1;
                }
            }
            break;
        default:
            break;
    }
    return z;
}



/* claiming candidate : exigente : line */


int d6l(int w[9][9][9])
{
    int l, c, d, f, b, ls, cs, z=0, j; /* flag que indica se ocorreu deducao */
    char *hd="d6l: claiming candidate (line)";  
    

    for(l=0; l<9; l++)
    {
        for(c=0; c<9; c++)
         {
            if(totalcandy(w[l][c])<2)           /*verificando se a celula possui menos de 2 candidatos,caso tenha, pode seguir para proxima celula*/
               continue;
            for(d=1; d<10; d++)               /*laço para analisar os digitos de cada celula*/
            {
                if(w[l][c][d-1]==0)            /*caso o digito nao seja candidato,ja pode buscar outro digito*/
                   continue;
                f=0;
                b=cbloco(l,c,&ls,&cs);           /* achar o bloco*/
                for(j=0;j<9;j++)                
                {
                   if(cbloco(l,j,&ls,&cs) == b && w[l][j][d-1]==1)  /* verificar se esta no mesmo bloco*/
                      continue;
                   if(w[l][j][d-1]==1 && cbloco(l,j,&ls,&cs)!= b)
                   {
                      f=1;                        /* flag para mostrar que foi encontrado fora do bloco */
                      break;

                   }  
                 }      
                  if(f)
                      continue;                          /* como foi encontrada fora do bloco, pode continuar */
                     
                  z=clap(w,d-1,b,l,c,1,hd);

         
             }   
         }
    }          
    
    return z;

}
/* ---------------------------------------------------------------------- */
/* claiming candidate : exigente : column */
int d6c(int w[9][9][9])
{
    int l, c, d, f, b, ls, cs , z=0; /* flag que indica se ocorreu deducao */
    char *hd="d6c: claiming candidate (column)";
    int i; 
    
         for(c=0;c<9;c++)
         {
             for(l=0; l<9;l++)
             {
              if(totalcandy(w[l][c])<2)     /*verificando se a celula possui menos de 2 candidatos,caso tenha, pode seguir para proxima celula*/
                   continue;
                 for(d=1; d<10; d++)            /*laço para analisar os digitos de cada celula*/
                 {
                    if(w[l][c][d-1]==0)        /*caso o digito nao seja candidato,ja pode buscar outro digito*/
                      continue;
                    f=0;
                    b=cbloco(l,c,&ls,&cs);       /*achar o bloco*/
                    for(i=0;i<9;i++)
                    {
                       if(cbloco(i,c,&ls,&cs) == b && w[i][c][d-1]==1) /*verifica se esta no mesmo bloco*/
                          continue;
                       if(w[i][c][d-1]==1 && cbloco(i,c,&ls,&cs) != b)
                       {   
                         f=1;          /* flag para mostrar que foi encontrado fora do bloco */
                         break;

                       }  
                    }
                    if(f)
                      continue;               /* como foi encontrada fora do bloco, pode continuar */  
                       
                    z=clap(w,d-1,b,l,c,2,hd);     
            
                 }   


             }
         }                 
    
    return z;
}
     
int clap(int w[9][9][9],int d,int nbloco, int lentrada, int centrada, int tipo,char *hd)
{
    int ls, cs, l, c;
    int z = 0;

    bloco(nbloco,&ls,&cs);
    for(l=ls;l<ls+3;l++)
        for(c=cs;c<cs+3;c++)
        {
            if(tipo==1 && l==lentrada)
                continue;
            if(tipo==2 && c==centrada)
                continue;
            if(w[l][c][d] != 0)
            {     w[l][c][d+1]=0;
                 printf("\n%s dado que a celula faz parte do bloco, remove o candidato %d",hd,d);
                 z=1;
        
            }
         }
    return z;
}

/* ---------------------------------------------------------------------- */
/* x-wing */
int d7l(int w[9][9][9])
{
    int z=0; /* flag que indica se ocorreu deducao */
    char *hd="d7l: x-wing (line)";
    int l1, l2, c1, c2, d, check, fcounter, counter; /*variaveis da funçao*/
    
    for (l1 =0;l1<8;l1++)
        for(c1=0;c1<8;c1++)
            for(c2=c1+1;c2<9;c2++)
            {
                for (d=0; d<9;d++)
                {
                    if(w[l1][c1][d]!=w[l1][c2][d] ||w[l1][c1][d]==0)
                        continue;
                    for(check=c2+1;check<9;check++)
                    {
                        fcounter = 0;
                        if(w[l1][c2][d]==w[l1][check][d])
                        {
                            fcounter = 1;
                            break;
                        }
                    }
                    if(fcounter)
                        continue;
                    for(l2=l1+1;l2<9;l2++)
                    {
                        if(w[l2][c1][d]!=w[l2][c2][d] || w[l2][c2][d]==0)
                            continue;
                        for(check=0;check<9;check++)
                        {
                            if(check==c1 || check==c2)
                                continue;
                            counter = 0;
                            if(w[l2][c1][d]==w[l2][check][d])
                            {
                                counter = 1;
                                break;
                            }
                        }
                        if(counter)
                            continue;
                        z = z + removexwing(d,w,l1,c1,l2,1,hd);
                        z = z + removexwing(d,w,l1,c2,l2,1,hd);
                   
                    }
                }
            } 
    return z;
}

/* ---------------------------------------------------------------------- */
/* x-wing */
int d7c(int w[9][9][9])
{
    int z=0; /* flag que indica se ocorreu deducao */
    char *hd="d7c: x-wing (column)";
    int l1, l2, c1, c2, d, check, counter, fcounter; /*variaveis da funçao*/
    
    for(c1=0;c1<8;c1++)
        for(l1=0;l1<8;l1++)
            for(l2=l1+1;l2<9;l2++)
            {
                for(d=0;d<9;d++)
                {
                    if(w[l1][c1][d]!=w[l2][c1][d] || w[l1][c1][d]==0)
                        continue;
                    for(check=l2+1;check<9;check++)
                    {
                        fcounter = 0;
                        if(w[l2][c1][d]==w[check][c1][d])
                        {
                            fcounter = 1;
                            break;
                        }
                    }
                    if(fcounter)
                        continue;
                    for(c2=c1+1;c2<9;c2++)
                    {
                        if(w[l1][c2][d]!=w[l2][c2][d] || w[l2][c2][d]==0)
                            continue;
                        for(check=0;check<9;check++)
                        {
                            if(check==l1 || check==l2)
                                continue;
                            counter=0;
                            if(w[l2][c2][d]==w[check][c2][d])
                            {
                                counter=1;
                                break;
                            }
                        }
                        if(counter)
                            continue;
                        z = z + removexwing(d,w,l1,c1,c2,2,hd);
                        z = z + removexwing(d,w,l2,c1,c2,2,hd);
                    
                    }
                }
            }
 
    return z;
}


/* ---------------------------------------------------------------------- */
/* xy-wing */

int d8l(int w[9][9][9])
{
    int z=0, /* flag que indica se ocorreu deducao */
        retorna=0;
    int l,c,cpivo,lpivo;

    for(l=0;l<9;l++)
    {
        for(c=0;c<9;c++)
        {
            if(conta(w,l,c) != 2)
            {
                continue;
            }
            cpivo = c;
            lpivo = l;
            if(asa1(w,lpivo,cpivo))
            {
                retorna++;
            }
        }
    }

    if(retorna>0)
    {
        z=1;
    }

    return z;
}


/* ------------------------------------------------------------------------ */
/* backtracking */
int tenta8(int w[9][9][9])
{
    /*int z=0;  flag que indica se ocorreu deducao */
    char *hd="tenta8: backtracking";
    int linha,coluna, /* linha e coluna  */
        n,i;/* variaveis para for  */

    /* criterio de parada  */
    if( celula(w,&linha,&coluna) == 0)
    {
        return 1;
    }

    for(i=0;i<9;i++)
    {
        if(pode(w,linha,coluna,i)) /* se numero na celula tiver ok, coloca esse número nela, e limpa o resto na mesma celula */
        {
            for ( n = 0; n < 9; n++) /* fazendo com que a celula venha a ter somente um numero */
            {
                if (n == i)
                {
                    w[linha][coluna][i] = 1; /* colocando numero unico na celula */     
                }
                else
                {
                    w[linha][coluna][n] = 0; /* limpando candidatos na  mesma celula */
                }
            }
            
            /* backtracking */
            if(tenta8(w))
            {
                printf("\n %s celula %d%c recebe candidato %d\n",hd,linha+1,coluna+65,i+1);
                return 1; /* retorna 1, se sudoku estiver resolvido */
            }

            else /* se solução falha, esvazia celula */
            {
                for ( n = 0; n < 9; n++)
                {
                    w[linha][coluna][n] = 1;
                }
            }
        }
    }

    return 1;
}

/* ---------------------------------------------------------------------- */
/* funcoes extra */
/* swordfish     : line*/
int d9l(int w[9][9][9])     
{
    int z=0; /* flag que indica se ocorreu deducao */
    char *hd="d9l: swordfish (line)";
    int l1, l2, l3, c1, c2, c3, d; /*variaveis da funçao*/

    for(l1 =0;l1<7;l1++)
    {
        for(c1=0;c1<7;c1++)
           for(c2=c1+1;c2<8;c2++)
               for(c3=c1+2;c3<9;c3++)
               {                 
                   for(d=0; d<9;d++)
                   {
                       if(contacandl(w,d,l1)!=2 && contacandl(w,d,l1)!=3)
                           continue;
                       if(w[l1][c1][d]==0 && w[l1][c2][d]==0)
                           continue;
                       if(w[l1][c1][d]==0 && w[l1][c3][d] ==0)
                           continue;
                       if(w[l1][c2][d]==0&& w[l1][c3][d]==0)
                           continue;

                       for(l2=l1+1;l2<8;l2++)
                           for(l3=l1+2;l3<9;l3++)
                           {

                               if(w[l2][c1][d]==0&&w[l3][c1][d]==0)
                                   continue;
                               if(w[l2][c2][d]==0&&w[l3][c2][d]==0)
                                   continue;
                               if(w[l2][c3][d]==0&&w[l3][c3][d]==0)
                                   continue;
                               if(w[l2][c1][d]!=w[l2][c2][d]&& w[l2][c1][d]!=w[l2][c3][d] && w[l2][c1][d]==1)
                                   continue;
                               if(w[l3][c1][d]!=w[l3][c2][d]&&w[l3][c1][d]!=w[l3][c3][d] && w[l3][c1][d]==1)
                                   continue;
                               if(w[l2][c2][d]!=w[l2][c1][d]&& w[l2][c2][d]!=w[l2][c3][d] && w[l2][c2][d]==1)
                                   continue;
                               if(w[l3][c2][d]!=w[l3][c1][d]&&w[l3][c2][d]!=w[l3][c3][d] && w[l3][c2][d]==1)
                                   continue;
                               if(w[l2][c3][d]!=w[l2][c1][d]&& w[l2][c3][d]!=w[l2][c2][d] && w[l2][c3][d]==1)
                                   continue;
                               if(w[l3][c3][d]!=w[l3][c1][d]&&w[l3][c3][d]!=w[l3][c2][d] && w[l3][c3][d]==1)
                                   continue;

                               removeswordfish(d,w,l1,c1,l2,l3,1,hd);
                               removeswordfish(d,w,l1,c2,l2,l3,1,hd);
                               removeswordfish(d,w,l1,c3,l2,l3,1,hd);
                               z=1;                            

                                                                                             
                            }

                     }
                }
    }
        return z;
}
/* ----------------------------------------------------------------------- */
/* swordfish    :   column*/        
int d9c(int w[9][9][9])
{
    
    int z=0; /* flag que indica se ocorreu deducao */
    char *hd="d9c: swordfish (column)";
    int l1, l2, l3, c1, c2, c3, d; /*variaveis da funçao*/
    
    for(c1 =0;c1<7;c1++)
    {
        for(l1=0;l1<7;l1++)
            for(l2=l1+1;l2<8;l2++)
                for(l3=l1+2;l3<9;l3++)
                {
                    for(d=0; d<9;d++)
                    {   

                        if(contacandc(w,d,c1)!=2 && contacandc(w,d,c1)!=3)
                            continue;
                        if(w[l1][c1][d]==0 && w[l2][c1][d]==0)
                            continue;
                        if(w[l1][c1][d]==0 && w[l3][c1][d] ==0)
                            continue;
                        if(w[l2][c1][d]==0&& w[l3][c1][d]==0)
                            continue;
                        for(c2=c1+1;c2<8;c2++)
                            for(c3=c1+2;c3<9;c3++)
                            {
                                if(w[l1][c2][d]==0&&w[l1][c3][d]==0)
                                    continue;
                                if(w[l2][c2][d]==0&&w[l2][c3][d]==0)
                                    continue;
                                if(w[l3][c2][d]==0&&w[l3][c3][d]==0)
                                    continue;
                                if(w[l1][c2][d]!=w[l2][c2][d]&& w[l1][c2][d]!=w[l3][c2][d] && w[l1][c2][d]==1)
                                    continue;
                                if(w[l1][c3][d]!=w[l2][c3][d]&&w[l1][c3][d]!=w[l3][c3][d] && w[l1][c3][d]==1)
                                    continue;
                                if(w[l2][c2][d]!=w[l1][c2][d]&& w[l2][c2][d]!=w[l3][c2][d] && w[l2][c2][d]==1)
                                    continue;
                                if(w[l2][c3][d]!=w[l1][c3][d]&&w[l2][c3][d]!=w[l3][c3][d] && w[l2][c3][d]==1)
                                    continue;
                                if(w[l3][c2][d]!=w[l1][c2][d]&& w[l3][c2][d]!=w[l2][c2][d] && w[l3][c2][d]==1)
                                    continue;
                                if(w[l3][c3][d]!=w[l1][c3][d]&&w[l3][c3][d]!=w[l2][c3][d] && w[l3][c3][d]==1)
                                    continue;

                                removeswordfish(d,w,l1,c1,c2,c3,2,hd);
                                removeswordfish(d,w,l1,c2,c2,c3,2,hd);
                                removeswordfish(d,w,l1,c3,c2,c3,2,hd);
                                z=1;
            

                                          
                            }
                     }
                 }
    }
        return z;
}


int contacandl(int w[9][9][9],int d,int l) /*conta candidato linha */

{
    int j,cont=0;

    for(j=0;j<9;j++)
    {
        if(w[l][j][d]==1)
            cont++;

    }

     return cont;
}
int contacandc(int w[9][9][9],int d,int c)
     {
         int i,cont=0;

         for(i=0;i<9;i++)
         {
             if(w[i][c][d]==1)
                 cont++;
    
    
         }

      return cont;
 }

                     

int removeswordfish(int recebe, int w[9][9][9], int l,int c ,int arg2,int arg3,int tipo,char*hd)
{
    int i,d;
    int z = 0; /* flag que identifica se ocorreu mudança */

   switch(tipo)
   {
       case 1: /*remove candidato da coluna */
           for(i=0;i<9;i++)
           {
               if(i==l || i==arg2 || i==arg3)
                   continue;
               for(d=0;d<9;d++)
                       if(d == recebe && w[i][c][d]!=0)
                       {
                            w[i][c][d]=0;
                            printf("\n%s dado que o candidato %d faz parte de um swordfish, remove ele de %d%c",hd, d+1,i+1,c+65);
                            z=1;
                       }
           }
           break;
          
       case 2: /*remove candidato de linha */
           for(i=0;i<9;i++)
           {
               if(i==c || i==arg2 || i==arg3)
                   continue;
               for(d=0;d<9;d++)
                   if(d==recebe && w[l][i][d]!=0)
                   {
                       w[l][i][d]=0;
                       printf("\n%s dado que o candidato %d faz parte de um swordfish, remove ele de %d%c",hd, d+1,l+1,i+65);
                       z=1;
                   }
           }
           break;
      default:
           break;
   }
   return z;
}

/* verifica se tem celula vazia ou preenchida */
int celula(int w[9][9][9], int *linha, int *coluna)
{
    int retorno = 0; /* numero para retornar 0 para falso e 1 para verdadeiro */
    int c,l,d, /* variaveis para primeira, segunda, e terceira dimensao */
        fd; /* variavel para contar quantas vezes o 1 aparece  */


    for ( l = 0; l < 9; l++ ) /* primeira dimensao */
    {
        /* iniciando contador */   
        for ( c = 0; c < 9; c++ ) /* segunda dimensao */
        {
            fd = 0;
            for( d = 0 ; d < 9 ; d++ )
            {
                if(w[l][c][d] == 1) /* terceira dimensao */
                {
                    fd++; /* soma mais um a cada candidato que existir na celula */
                }
            }
            
            /* Se celula vazia, retorna 1 */
            if (fd > 1)
            {
                *linha  = l; /* row recebe linha que tem celula vazia */
                *coluna = c; /* col recebe coluna que tem celula vazia */
                retorno = 1; /* celula vazia -> retorno = 1 */
                return retorno;
            }
        }

    }
    
    return retorno;
}

/* verifica se pode colocar valor na celula em específico */
int pode(int w[9][9][9], int linha, int coluna, int pos)
{
    int l,c,d,
        fd,
        posicao;
    int linha_start = (linha/3)*3;
    int coluna_start = (coluna/3)*3;
    

    /* verificando por linha */
    for ( c = 0; c < 9; c++)
    {   
        fd=0;
        for ( d = 0; d < 9; d++)
        {
            if(w[linha][c][d] == 1) 
            {
                fd++; /* soma mais um a cada candidato que existir na celula */
                posicao = d;
            }
        }
        if (fd ==1 && pos == posicao) /* celula ocupada, celula com valores iguais */
        {
            return 0;
        }
     }
    
    /* verificando por coluna */
    for(l = 0; l < 9; l++)
    {
        fd=0;
        for ( d = 0; d < 9; d++)
        {
            if(w[l][coluna][d] == 1) 
            {
                fd++; /* soma mais um a cada candidato que existir na celula */
                posicao = d;
            }
        }
        if (fd ==1 && pos == posicao) /* celula ocupada, celula com valores iguais */
        {
            return 0;
        }
    }
    
    /* verificando submatriz */
    
    for(l=linha_start;l<linha_start+3;l++)
    {
        fd=0;
        for(c=coluna_start;c<coluna_start+3;c++)
        {
            if(l != linha && c != coluna)/* pula linha e coluna analisados*/
            {
                for ( d = 0; d < 9; d++)
                {
                    if (w[l][c][d] == 1)
                    {
                        fd++;
                        posicao=d;
                    }
                }
                if (fd ==1 && pos == posicao) /* celula ocupada, celula com valores iguais */
                {
                    return 0;
                }
            }
        }
    }
    return 1;
}

/* ----------------------------------------------------------------------- */
/* skyscraper     : line*/
int d11l(int w[9][9][9])
{    
    int z=0; /* flag que indica se ocorreu deducao */
    char *hd="d11l: skyscraper (line)";
    int l1, l2,c1, c2, c3,d, fcounter2, fcounter3, check; /*variaveis da funçao*/

    for(l1=0;l1<8;l1++)
    {
        for(c1=0;c1<8;c1++)
        {
            for(c2=c1+1;c2<9;c2++)
            {
                for(d=0;d<9;d++)
                {
                    if(w[l1][c1][d]!=w[l1][c2][d] || w[l1][c1][d]==0)
                        continue;
                    for(check=c2+1;check<9;check++)
                    {
                        fcounter2 = 0;
                        if(w[l1][c2][d]==w[l1][check][d])
                        {
                            fcounter2 = 1;
                            break;
                        }
                    }
                    if(fcounter2)
                        continue;
                    for(l2=l1+1;l2<9;l2++)
                        for(c3=c1+1;c3<9;c3++)
                        {
                            if(w[l2][c1][d]!=w[l2][c3][d] || w[l2][c3][d]==0 || c3==c2)
                                continue;
                            for(check=c3+1;check<9;check++)
                            {
                                fcounter3 = 0;
                                if(w[l2][c3][d]==w[l2][check][d])
                                {
                                    fcounter3 = 1;
                                    break;
                                }
                            }
                            if(fcounter3)
                                break;
                            z = skyscraper(w,d,l1,l2,c2,c3,hd);
                        }


                }
            }
        }
    }
    return z;
}
/* ----------------------------------------------------------------------- */
/* skyscraper     :   column*/        
int d11c(int w[9][9][9])
{   
    int z=0; /* flag que indica se ocorreu deducao */
    char *hd="d11c: skyscraper (column)";
    int l1, l2,c1, c2, l3,d, fcounter2, fcounter3, check; /*variaveis da funçao*/

    for(c1=0;c1<8;c1++)
        for(l1=0;l1<8;l1++)
            for(l2=l1+1;l2<9;l2++)
            {
                for(d=0;d<9;d++)
                {
                    if(w[l1][c1][d]!=w[l2][c1][d] || w[l1][c1][d]==0)
                         continue;
                    for(check=l2+1;check<9;check++)
                    {
                        fcounter2 = 0;
                        if(w[l2][c1][d]==w[check][c1][d])
                        {
                            fcounter2 = 1;
                            break;
                        }
                    }
                    if(fcounter2)
                        continue;
                    for(c2=c1+1;c2<9;c2++)
                        for(l3=l1+1;l3<9;l3++)
                        {
                            if(w[l1][c2][d]!=w[l3][c2][d] || w[l3][c2][d]==0 || l3==l2)
                                continue;
                            for(check=l3+1;check<9;check++)
                            {
                                fcounter3 = 0;
                                if(w[l3][c2][d]==w[check][c2][d])
                                {
                                    fcounter3 = 1;
                                    break;
                                }
                            }
                            if(fcounter3)
                                break;
                            z = skyscraper(w,d,l2,l3,c1,c2,hd);
                            z=1;

                        }
                }
            }


    return z;
}

/* ----------------------------------------------------------------------- */
/* funcoes extras : xy-wing*/

int asa1(int w[9][9][9], int linha, int coluna)
{
    int lb,cb;
    int i,j;
    int blocopv;
    
    blocopv=cbloco(linha,coluna,&lb,&cb);

    /* verificando se tem asa na linha -> linha constante | varia coluna  */
    for(i=0;i<9;i++)
    {
        if(conta(w,linha,i) !=2)
        {
            continue;
        }
        
        /* comeca do 0 e vai para o final da linha */
        else if(i != coluna)
        {
            if(verifica(w,linha,i,linha,coluna))
            {
                asa2(w,linha,i,linha,coluna,blocopv,1);
                return 1;
            }
        }
    }

    /* verificando se tem asas na coluna -> coluna constante | varia linha */
    for(i=0; i<9; i++)
    {
        if(conta(w,i,coluna) !=2)
        {
            continue;
        }
        
        /* comeca do 0 e vai para o final da coluna */
        else if(i != linha)
        {
            if(verifica(w,i,coluna,linha,coluna))
            {
                asa2(w,i,coluna,linha,coluna,blocopv,2);
                return 1;
            }
        }
    }

    /* veiricando se tem asa no bloco  */
    for (i = 0 ; i < lb+3 ; i++)
    {
        for(j = 0 ; j < cb+3 ; j++)
        {
            if(conta(w,i,j) !=2)
            {
                continue;
            }
            
            /* comeca do 0 e vai para o final da linha */
            else if(i != linha && j != coluna)
            {
                if(verifica(w,i,j,linha,coluna))
                {
                    asa2(w,i,j,linha,coluna,blocopv,3);
                    return 1;
                }
            }
        }
    }
    return 0;
}

int asa2(int w[9][9][9], int linha1, int coluna1, int linhapv, int colunapv, int blocopv, int tipo)
{
    int i,j;
    int lb,cb;

    bloco(blocopv,&lb,&cb);

    switch(tipo)
    {
        case 1:/* asa1-> linha */
            for(i=0 ; i < 9 ; i++)
            {
                if(conta(w,i,colunapv) !=2)
                {
                   continue;
                }
            
                else if(i != linhapv)
                {
                    if(verifica2(w,i,colunapv,linha1,coluna1,linhapv,colunapv))
                    {
                        return 1;
                    }
                }
            }
            break;
        case 2: /* asa1 -> coluna  */
            for(i=0 ; i < 9 ; i++)
            {
                if(conta(w,linhapv,i) !=2)
                {
                   continue;
                }
            
                else if(i != colunapv)
                {
                    if(verifica2(w,linhapv,colunapv,linha1,coluna1,linhapv,colunapv))
                    {
                        return 1;
                    }
                }
            }
            break;
        case 3:
            for(i=0 ; i < lb+3 ; i++)
            {  
                for(j=0 ; j < cb+3 ; j++)
                {
                    if(conta(w,i,j) !=2)
                    {
                        continue;
                    }
            
                    else if((i != linha1 && i != coluna1)&&(i != linhapv && i != colunapv))
                    {
                        if(verifica2(w,i,j,linha1,coluna1,linhapv,colunapv))
                        {
                            return 1;
                        }
                    }
                }
            }
            break;

        default:
            break;
    }
    return 0;
}
int verifica(int w[9][9][9], int linha, int coluna, int linhapv, int colunapv)
{
    int i,
        contando=0,
        retorna=0;
    for (i=0; i<9; i++)
    {
        if(w[linha][coluna][i] == w[linhapv][colunapv][i])
        {
            contando++;
        }
    }

    if(contando==1)
    {
        retorna=1;
    }

    return retorna;
}

int verifica2(int w[9][9][9], int linha2,int coluna2, int linha1, int coluna1, int linhapv, int colunapv)
{
    int i,
        contando =0;
    int lb1,cb1,
        lb2,cb2;

    int recebe1,
        recebe2,
        recebe12;
    
    int bloco1,
        bloco2;

    bloco1 = cbloco(linha1,coluna1,&lb1,&cb1);
    bloco2 = cbloco(linha2,coluna2,&lb2,&cb2);

    /* -------------------------------------------- */
    /* verifica se existe elementos iguais ou nao  */
    
    /* ----------- */
    /* asa1 | pivo */

    for(i=0;i<9;i++)
    {
        if(w[linha1][coluna1][i] == w[linhapv][colunapv][i])/* achou candidato em comum  */
        {
            contando++; /* soma 1 cada vez que acha  */
            recebe1=i; /* num em comum com o pivo */
        }
    }
    
    if(contando != 1)
    {
        return 0;
    }
    contando = 0;

    /* ----------- */
    /* asa2 | pivo */
    for(i = 0;i<9;i++)
    {
        if(w[linha2][coluna2][i]==w[linhapv][colunapv][i])/* achou candidato em comum  */
        {
            contando++; /* soma 1 cada vez que acha  */
            recebe2 = i; /* num em comum com o pivo */

            if(recebe1 == i)/* garante que recebe1 nao seja igual ao recebe 2*/
            {
                return 0;
            }
        }
    }
    
    if(contando != 1)
    {
        return 0;
    }
    contando = 0;
    
    /* ----------- */
    /* asa2 | pivo */
    for(i=0; i < 9 ; i++)
    {
        if(w[linha1][coluna1][i]==w[linha2][coluna2][i])/* achou candidato em comum */
        {
            contando++;/* soma 1 cada vez que acha  */
            recebe12=i;/* num em comum com asa1 */

            if(i==recebe2|| i== recebe1)/* garante que recebe 1 e recebe 2 nao sejam igual ao recebe12 */
            {
                return 0;
            }
        }
    
    }
    if(contando != 1)
    {
        return 0;
    }

    if(amiga(w,linha1,coluna1,bloco1,linha2,coluna2,bloco2,recebe12))/* se encontrar celula amiga, retorna 1*/
    {
        return 1;
    }
    return 0;
}


int conta(int w[9][9][9], int l, int c)
{
    int contando=0;
    int d;

    for(d=0;d<9;d++)
    {
        if(w[l][c][d] == 1)
        {
            contando++;
        }
    }
    return contando;
}
  
int amiga(int w[9][9][9], int linha1,int coluna1,int bloco1,int linha2,int coluna2,int bloco2,int candidato)
{
    int l,c,bloc,lb,cb;
	char *hd = "d8l: xy-wing (line)";
	
    for(c=0;c<9;c++)
	{
		if(w[linha1][c][candidato]==1)
		{	
			
			if(c==coluna2)
			{			
				
				w[linha1][coluna2][candidato]=0;
		    	printf("\n%s dada a celula amiga %d%c contendo o cadidato %d, remove o mesmo como candidato de %d%c",hd, linha1+1, c+65, candidato, linha1+1,c+65);  
				
				return 1;
			}
			else
			{
                bloc=cbloco(linha1,c,&lb,&cb);
				if(bloc==bloco2)
				{	
					
					w[linha1][c][candidato]=0;
					printf("\n%s dada a celula amiga %d%c contendo o cadidato %d, remove o mesmo como candidato de %d%c",hd, linha1+1, c+65, candidato, linha1+1,c+65);  
					return 1;
			    }
		   }
	    }
		else
			continue;
    }
    
   	for(l=0;l<9;l++)
	{
		if(w[l][coluna1][candidato]==1)
		{
			
			if(l==linha2)
			{
				
				w[linha2][coluna1][candidato]=0;
				 printf("\n%s dada a celula amiga %d%c contendo o cadidato %d, remove o mesmo como candidato de %d%c",hd, l+1, c+65, candidato, l+1,c+65);  
				return 1;
			}
			else
			{
                bloc=cbloco(l,coluna1,&lb,&cb);
				if(bloc==bloco2)
				{
					
					w[l][coluna1][candidato]=0;
					printf("\n%s dada a celula amiga %d%c contendo o cadidato %d, remove o mesmo como candidato de %d%c",hd, l+1, c+65, candidato, l+1,c+65);  
					return 1;
				}
		    }
        }
		else{
			continue;
	    }
	}

    for(l=0;l<9;l++)
	{
		for(c=0;c<9;c++)
		{
			if(w[l][c][candidato]==1)
			{	
                bloc=cbloco(l,c,&lb,&cb); 
				/* verifica se é o mesmo bloco da asa 1*/
				if(bloc==bloco1)
				{
					if(l==linha2)
					{
						/* mesma linha asa2*/
						w[linha2][c][candidato]=0;
						printf("\n%s dada a celula amiga %d%c contendo o cadidato %d, remove o mesmo como candidato de %d%c",hd, l+1, c+65, candidato, l+1,c+65);
						return 1;
					}
					else
					{
						if(c==coluna2)
						{
							/*se forem a mesma coluna*/
							w[l][coluna2][candidato]=0;
							printf("\n%s dada a celula amiga %d%c contendo o cadidato %d, remove o mesmo como candidato de %d%c",hd, l+1, c+65, candidato, l+1,c+65);
							return 1;
				   		}
					}
	        	}
				
                else
                {
			        continue;
		        }
            }
		    else
            {
		    	continue;
	        }
        }
    }
    return 0;
}

/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160612.142044      */
