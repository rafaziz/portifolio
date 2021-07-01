/* ************************************************************************ *
 *    ex19.c, v1.0                                                          *
 *    Programa que ministra um jogo da velha JvJ.                           *
 *                                                                          *
 *    Copyright (C) 2017 by Rafael Aziz Da Silva Rocha                      *
 *                                                                          *
 *    This program is free software; you can redistribute it and/or modify  *
 *    it under the terms of the GNU General Public License as published by  *
 *    the Free Software Foundation; either version 2 of the License, or     *
 *    (at your option) any later version.                                   *
 *                                                                          *
 *    This program is distributed in the hope that it will be useful,       *
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *    GNU General Public License for more details.                          *
 *                                                                          *
 *    You should have received a copy of the GNU General Public License     *
 *    along with this program; if not, write to the                         *
 *    Free Software Foundation, Inc.,                                       *
 *    59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 *                                                                          *
 *    To contact the author, please write to:                               *
 *    Rafael Aziz Da Silva Rocha <rafaelazizlvr@gmail.com>                  *
 *    Webpage: http://www.upe.br                                            *
 *    Phone: +55 (81) 99940-3183                                            *
 * ************************************************************************ *
 * 
 */

/*
 * Instructions to compile:
 * 
 *      $gcc tic-tac-toe.c -o tic-tac-toe.x -lm -Wall -lncurses -Wextra
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>

#define FIR 9
void imprime(char vet[FIR][FIR+3], int linha, int coluna, int aux, int afir, int pont1, int pont2);
char turno(int cont);
void rainbowsix(void);

char grid[FIR][FIR+3]=
         {
             "   |   |   ",
             "   |   |   ",
             "___|___|___",
             "   |   |   ",
             "   |   |   ",
             "___|___|___",
             "   |   |   ",
             "   |   |   ",
             "   |   |   "
         };

int main(void)
{
    int x, y, lin, liny, colx, col, a, b;
    int contador = 0, verd = 0, p1 = 0, p2 = 0;
    char ch = '#';
    int read = '@';
    
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    getmaxyx(stdscr, y, x);
    curs_set(0);
    start_color();
    rainbowsix();
    timeout(0);
    
    lin = (y/2)+1;
    liny = (y/2)+1;
    col = ((x-FIR)/2)+1;
    colx = ((x-FIR)/2)+1;
    imprime(grid, y, x, contador, verd, p1, p2);
    
    while(read != 'e')
    {
        imprime(grid, y, x, contador, verd, p1, p2); 
        read = getch();
        if(verd == 1 || verd == 2)
        {
            if(verd == 1)
            {
                mvprintw((y/2)-(FIR-5), (x-FIR+2)/2, "%c ganhou!", turno(contador));
                if(turno(contador) == 'X')
                    mvchgat((y/2)-(FIR-5), (x-FIR+2)/2, 1, A_BOLD, 1, NULL);
                else
                    mvchgat((y/2)-(FIR-5), (x-FIR+2)/2, 1, A_BOLD, 5, NULL);
                mvprintw((y/2)-(FIR-6), (x-FIR-37)/2, "pressione 'e' para sair ou 'y' para jogar novamente.");
                refresh();
            }
            else
            {
                mvprintw((y/2)-(FIR-5), (x-FIR+2)/2, "Deu velha!");
                mvchgat((y/2)-(FIR-5), (x-FIR+2)/2, -1, A_BOLD, 2, NULL);
                mvprintw((y/2)-(FIR-6), (x-FIR-37)/2, "pressione 'e' para sair ou 'y' para jogar novamente.");
                refresh();
            }
            if(read == 'y')
            {
                clear();
                grid[1][1] = ' ';
                grid[1][5] = ' ';
                grid[1][9] = ' ';
                grid[4][1] = ' ';
                grid[4][5] = ' ';
                grid[4][9] = ' ';
                grid[7][1] = ' ';
                grid[7][5] = ' ';
                grid[7][9] = ' ';
                imprime(grid, y, x, contador, verd, p1, p2);
                verd = 0;
                contador = 0;
            }
        }
        if(read == KEY_UP)
        {    
            lin = lin - 3;
            if(lin < liny)
                lin = lin + 9;
            ch = '#';
        }
        if(read == KEY_DOWN)
        {
            lin = lin + 3;
            if(lin > liny + 6)
                lin = lin - 9;
            ch = '#';
        }
        if(read == KEY_LEFT)
        {
            col = col - 4;
            if(col < colx)
                col = col + 12;
            ch = '#';
        }
        if(read == KEY_RIGHT)
        {
            col = col + 4;
            if(col > colx + 8)
                col = col - 12;
            ch = '#';
        }
        if(read == ' ')
        {    
            if(verd != 0)
                continue;
            getyx(stdscr, a, b);
            if(grid[FIR-(abs(lin-a)+1)][(FIR+3)-abs((col-b)-1)] == ' ')
            {
                contador++;
                ch = turno(contador);
                grid[FIR-(abs(lin-a)+1)][(FIR+3)-abs((col-b)-1)] = turno(contador);
                if(grid[1][1] == grid[1][5] && grid[1][5] == grid[1][9])
                {
                    if(grid[1][1] != ' ')
                    {
                        verd = 1;
                        if(turno(contador) == 'X')
                            p1++;
                        else
                            p2++;
                    }
                }
                else if(grid[4][1] == grid[4][5] && grid[4][5] == grid[4][9])
                     {      
                         if(grid[4][1] != ' ')
                         {
                             verd = 1;
                             if(turno(contador) == 'X')
                                p1++;
                             else
                                p2++;
                    
                         }
                     }    
                     else if(grid[7][1] == grid[7][5] && grid[7][5] == grid[7][9])
                          {
                              if(grid[7][1] != ' ')
                              {
                                  verd = 1;
                                  if(turno(contador) == 'X')
                                      p1++;
                                  else
                                      p2++;
                              }
                          }    
                          else if(grid[1][1] == grid[4][1] && grid[4][1] == grid[7][1])
                               {  
                                   if(grid[1][1] != ' ')
                                   {
                                       verd = 1;
                                       if(turno(contador) == 'X')
                                           p1++;
                                       else
                                           p2++;
                                   }
                               }
                               else if(grid[1][5] == grid[4][5] && grid[4][5] == grid[7][5])
                                    {
                                        if(grid[1][5] != ' ')
                                        {
                                            verd = 1;
                                            if(turno(contador) == 'X')
                                                p1++;
                                            else
                                                p2++;
                                        }
                                    }
                                    else if(grid[1][9] == grid[4][9] && grid[4][9] == grid[7][9])
                                         {   
                                             if(grid[1][9] != ' ')
                                             {
                                                 verd = 1;
                                                 if(turno(contador) == 'X')
                                                     p1++;
                                                 else
                                                     p2++;
                                             }
                                         }
                                         else if(grid[1][1] == grid[4][5] && grid[4][5] == grid[7][9])
                                              {
                                                  if(grid[1][1] != ' ')
                                                  {
                                                      verd =1;
                                                      if(turno(contador) == 'X')
                                                          p1++;
                                                      else
                                                          p2++;
                                                  }
                                              }
                                              else if(grid[7][1] == grid[4][5] && grid[4][5] == grid[1][9])
                                                   {  
                                                       if(grid[7][1] != ' ')
                                                       {
                                                           verd = 1;
                                                           if(turno(contador) == 'X')
                                                               p1++;
                                                           else
                                                               p2++;
                                                       }
                                                   }
                                                   else
                                                       if(contador == 9)
                                                       { 
                                                           verd = 2;
                                                       }
            }                                       
            else
                continue;
        }
        mvprintw(lin, col, "%c", ch);
        mvchgat(lin, col, 1, A_BOLD, 6, NULL);
        refresh();
        usleep(20000);
    }
    endwin();
    return 0;
}

void imprime(char vet[FIR][FIR+3], int linha, int coluna, int aux, int afir, int pont1, int pont2)
{
    int i, j;
    mvprintw((linha/6), (coluna-FIR-5)/2, "# JOGO DA VELHA #");
    mvprintw((linha/6)+1, (coluna-FIR-(coluna/2))-25, "JOGADOR 1 - PONTUACAO: %i                      JOGADOR 2 - PONTUACAO: %i", pont1, pont2);
    mvchgat((linha/6)+1, (coluna-FIR-(coluna/2))-25, 25, A_BOLD, 1, NULL);
    mvchgat((linha/6)+1, (coluna-FIR-(coluna/2))+21, 25, A_BOLD, 5, NULL);
    mvprintw((linha/4), (coluna-FIR-(coluna/2))-25, "Para escolher a posicao, cada jogador deve pressionar as setas do teclado.");
    mvprintw((linha/4)+1, (coluna-FIR-(coluna/2))-25, "Em seguida a barra de espaco para jogar na posicao desejada.");
    
    if(afir == 0)
    {
        if(aux%2 == 0)
        {
            mvprintw((linha/2)-(FIR-5), (coluna-FIR-7)/2, "Jogador 1, sua vez!");
            mvchgat((linha/2)-(FIR-5), (coluna-FIR-7)/2, -1, A_BOLD, 1, NULL);
            mvchgat((linha/6)+1, (coluna-FIR-(coluna/2))-25, 25, A_BOLD, 4, NULL);
        }
        else
        {
            mvprintw((linha/2)-(FIR-5), (coluna-FIR-7)/2, "Jogador 2, sua vez!");
            mvchgat((linha/2)-(FIR-5), (coluna-FIR-7)/2, -1, A_BOLD, 5, NULL);
            mvchgat((linha/6)+1, (coluna-FIR-(coluna/2))+21, 25, A_BOLD, 4, NULL);
        }
    }
    else
        mvprintw((linha/2)-(FIR-5), (coluna-FIR-7)/2, "                   ");

    for(i=0;i<FIR;i++)
    {
        for(j=0;j<FIR+3;j++)
        {
            mvprintw((linha/2)+i, ((coluna-FIR)/2)+j, "%c", vet[i][j]);
            if(vet[i][j] == 'X')
                mvchgat((linha/2)+i, ((coluna-FIR)/2)+j, 1, A_BOLD, 1, NULL);
            if(vet[i][j] == 'O')
                mvchgat((linha/2)+i, ((coluna-FIR)/2)+j, 1, A_BOLD, 5, NULL);
        }
    }
    
    refresh();
}
char turno(int cont)
{
    if(cont%2 == 0)
        return 'O';
    else
        return 'X';
}
void rainbowsix(void)
{
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(3, COLOR_CYAN, COLOR_BLACK);
    init_pair(4, COLOR_GREEN, COLOR_BLACK);
    init_pair(5, COLOR_BLUE, COLOR_BLACK);
    init_pair(6, COLOR_YELLOW, COLOR_BLACK);
}
