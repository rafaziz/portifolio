/* UPECMAN 2017.2 */
/***************************************************************************
 *   upecman.c                                Version 20210628.013231      *
 *                                                                         *
 *   Pacman Ncurses                                                        *
 *   Copyright (C) 2017         by upe-clyde                               *
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
 *                                                                         *
 *   Rafael Aziz da Silva Rocha, @Rafaziz                                  *
 *                                                                         *
 *   Email: rafaelazizlvr@gmail.com                                        *
 *   Webpage: https://www.linkedin.com/in/rafaziz                          *
 *   Phone: +55 (81) 99940-3183                                            *
 ***************************************************************************/

/* ---------------------------------------------------------------------- */
/**
 * @file upecman.c
 * @ingroup GroupUnique
 * @brief Pacman Ncurses
 * @details This program really do a nice job as a template, and template only!
 * @version 20160529.013231
 * @date 2016-05-29
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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
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
 *      $make
 * ou
 *      $gcc upecman.c -o upecman.x -lm -Wall -lncurses -g -Og
 *          -Wextra -ansi -pedantic-errors -DDEBUG=1
 */

/* ---------------------------------------------------------------------- */
/* includes */

#include <stdio.h> /* Standard I/O functions */
#include <stdlib.h> /* Miscellaneous functions (rand, malloc, srand)*/
#include <ncurses.h> /* Screen handling and optimisation functions */
#include <getopt.h> /* get options from system argc/argv */
#include <string.h> /* Strings functions definitions */
#include <assert.h> /* Verify assumptions with assert */
#include <unistd.h> /* UNIX standard function */
#include "upecman.h" /* To be created for this template if needed */
#include <time.h> /* Time and date functions */
#include <math.h> /* Mathematics functions */
/* #include <dlfcn.h> */ /* Dynamic library */
/* #include <malloc.h> */ /* Dynamic memory allocation */
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
/* #include <allegro.h> */ /* A game library for graphics, sounds, etc. */
/* #include <libintl.h> */ /* Internationalization / translation */
/* #include <locale.h> */ /* MACROS LC_ for location specific settings */
/* #include "libeco.h" */ /* I/O, Math, Sound, Color, Portable Linux/Windows */

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief This is the main event of the evening
 *
 * @param[in] argc Argument counter
 * @param[in] argv Argument strings (argument values)
 *
 * @retval 0 If succeed (EXIT_SUCCESS).
 * @retval 1 Or another error code if failed.
 *
 * @par Example
 * @code
 *    $./upecman -h
 * @endcode
 *
 * @warning   Be carefull with...
 * @bug There is a bug with...
 * @todo Need to do...
 * @note You can read more about it at <<a href="http://www.beco.cc">www.beco.cc</a>>
 * @author Ruben Carlo Benante
 * @version 20160529.013231
 * @date 2016-05-29

 */

int main(int argc, char *argv[])
{
    int opt; /* return from getopt() */
    t_game g, aux; /* the game */
    const char *sready = "Are you ready? (y/n)"; /* ready string */
    t_direction next = left;
    const char *pdead = "Do you want to play again? (y/n)";
    int kin = 0; /* keyboard input */
    int c, round = 0, auxscore, intime=0, actime=11, starttime, auxpel; /* variaveis auxiliares */
    int f; /* fantasmas */
    int pel = 0; /* contador de pellets */
    int n = 1; /* level of the game */
    int scrx, scry;
    IFDEBUG("main()\n");

    IFDEBUG("Starting optarg loop...\n");

    /* getopt() configured options:
     *        -h  help
     *        -c  copyright & version
     *        -v  verbose
     */
    opterr = 0;
    while((opt = getopt(argc, argv, "hvc")) != EOF)
        switch(opt)
        {
            case 'h':
                help();
                break;
            case 'v':
                verb++;
                break;
            case 'c':
                copyr();
                break;
            case '?':
            default:
                printf("Type\n\t$man %s\nor\n\t$%s -h\nfor help.\n\n", argv[0], argv[0]);
                return EXIT_FAILURE;
        }

    if(verb)
        printf("Verbose level set at: %d\n", verb);

    /* ...and we are done */
    IFDEBUG("Starting the game now...\n");

    g = upecman_init();
    colorgame();
    getmaxyx(stdscr, scry, scrx);

    printlab(g, scry, scrx);
    g.lab[17][9]=' ';

    attron(COLOR_PAIR(6));
    mvprintw(scry/2-20, scrx/2-5, "WELCOME TO");
    mvprintw(scry/2-19, scrx/2-2, "THE");
    mvprintw(scry/2-18, scrx/2-6, "PACMAN GAME!");
    attroff(COLOR_PAIR(6));
    mvprintw(scry/2-16, scrx/2-9, "%s", sready);
    refresh();

    while(1)
    {
        kin = getch();
        if(kin == 'y')
        {
            g.pacman.life--;
            break;
        }
        if(kin == 'n')
        {
            endwin();
            return EXIT_SUCCESS;
        }
        usleep(16666); /* wait 16666 microseconds to avoid frying the processor (1/60 s) */
    }

    starttime = time(NULL);

    while(kin != 'q')
    {
        usleep(220000);
        srand((unsigned)time(NULL));
        kin = getch();
        round++;
        if(round == 100000000)
            round = 0;

        for(f = blinky; f <= clyde; f++) /* dead or alive?? */
        {
            if((g.pacman.pos.y == g.ghost[f].pos.y && g.pacman.pos.x == g.ghost[f].pos.x) || (g.pacman.dir == left && g.ghost[f].dir == right && g.pacman.pos.x == g.ghost[f].pos.x-1 && g.pacman.pos.y == g.ghost[f].pos.y) || (g.pacman.dir == right && g.ghost[f].dir == left && g.pacman.pos.x == g.ghost[f].pos.x+1 && g.pacman.pos.y == g.ghost[f].pos.y) || (g.pacman.dir == up && g.ghost[f].dir == down && g.pacman.pos.x == g.ghost[f].pos.x && g.pacman.pos.y == g.ghost[f].pos.y-1) || (g.pacman.dir == down && g.ghost[f].dir == up && g.pacman.pos.x == g.ghost[f].pos.x && g.pacman.pos.y == g.ghost[f].pos.y+1))
            {
                if(g.ghost[f].mode == afraid)
                {
                    g.ghost[f].mode = dead;
                    g.pacman.score += 200;

                }
                else if(g.pacman.life == 0)
                {
                     while(1)
                    {
                        mvprintw(scry/2-17,scrx/2-6,"GAME OVER");
                        mvchgat(scry/2-17,scrx/2-6,-1,A_BOLD,1,NULL);
                        mvprintw(scry/2-15,scrx/2-14,"%s", pdead);
                        kin = getch();

                        if(kin == 'y')
                        {
                            g=upecman_init();
                            pel = 0;
                            g.pacman.life--;
                            printlab(g,scry,scrx);
                            break;
                        }
                        if(kin == 'n')
                        {
                            endwin();
                            return EXIT_SUCCESS;
                        }
                     }
                }

                else if(g.ghost[f].mode != dead)
                {
                    g.pacman.life--;
                    g.lab[17][9]=' ';
                    intime=0;
                    g.pacman.pos.y = 17;
                    g.pacman.pos.x = 9;
                    next = left;
                    g.ghost[blinky].pos.y = 7; /* blinky start position (line) */
                    g.ghost[blinky].pos.x = 9; /* blinky start position (column) */
                    g.ghost[blinky].mode = scatter;
                    g.ghost[pinky].pos.y = 9; /* pinky start position (line) */
                    g.ghost[pinky].pos.x = 10; /* pinky start position (column) */
                    g.ghost[pinky].mode = scatter;
                    g.ghost[inky].pos.y = 10; /* inky start position (line) */
                    g.ghost[inky].pos.x = 10; /* inky start position (column) */
                    g.ghost[inky].mode = scatter;
                    g.ghost[clyde].pos.y = 11; /* clyde start position (line) */
                    g.ghost[clyde].pos.x = 10; /* clyde start position (column) */
                    g.ghost[clyde].mode = scatter;
                    printlab(g, scry, scrx);
                    mvprintw(scry/2-17,scrx/2-6,"GET READY!");
                    mvchgat(scry/2-17,scrx/2-6, -1, A_BOLD,6,NULL);
                    refresh();
                    usleep(2400000);
                    starttime = time(NULL);
               }
            }
        }

        if(kin == KEY_LEFT)
            next = left;
        if(kin == KEY_RIGHT)
            next = right;
        if(kin == KEY_DOWN)
            next = down;
        if(kin == KEY_UP)
            next = up;

        g.pacman = pacmove(g, next);
        aux = g;
        g = ghostmode(g, n, starttime);
        g = ghostmove(g);
        for(f=blinky; f<=clyde; f++)
            if(g.ghost[f].mode == afraid && round%2 == 0)
                g = aux;
        printlab(g, scry, scrx);
        auxscore = g.pacman.score;
        g = getpellet(g.pacman.pos.x, g.pacman.pos.y, g, n);
        if((auxscore<10000 && g.pacman.score>=10000) || (auxscore<100000 && g.pacman.score>=100000)) /*extra life condition*/
            g.pacman.life++;
        auxpel = pel;
        if(auxscore != g.pacman.score && g.pacman.score - auxscore < 100)
            pel++;
        if(pel%188 == 0)
        {
            printlab(g, scry, scrx);
            usleep(2400000);
            g = relevel(g);
            n++;
            printlab(g, scry, scrx);
            mvprintw(scry/2-11,scrx/2-3,"LEVEL %d", n);
            mvprintw(scry/2-17,scrx/2-6,"GET READY!");
            mvchgat(scry/2-11,scrx/2-3, 7, A_BOLD, 2, NULL);
            mvchgat(scry/2-17,scrx/2-6, -1, A_BOLD,6,NULL);
            refresh();
            usleep(3600000);
            pel=0;
            starttime = time(NULL);
            next = left;
        }
        if((pel == 54 || pel == 131) && auxpel != pel)
        {
            intime=time(NULL);
            g.lab[17][9]='&';
        }

        actime=time(NULL);
        if(actime-intime>10)
            g.lab[17][9]=' ';

        while((c = getch()) != '\n' && c != EOF);
        printlab(g, scry, scrx);

    }
    endwin();
    return EXIT_SUCCESS;
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Prints help information and exit
 * @details Prints help information (usually called by opt -h)
 * @return Void
 * @author Ruben Carlo Benante
 * @version 20160529.013231
 * @date 2016-05-29
 *
 */
void help(void)
{
    IFDEBUG("help()");
    printf("%s - %s\n", "upecman", "Pacman Ncurses");
    printf("\nUsage: ./%s [-h|-v|-c]\n", "upecman");
    printf("\nOptions:\n");
    printf("\t-h,  --help\n\t\tShow this help.\n");
    printf("\t-c,  --copyright, --version\n\t\tShow version and copyright information.\n");
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
 * @version 20160529.013231
 * @date 2016-05-29
 *
 */
void copyr(void)
{
    IFDEBUG("copyr()");
    printf("%s - Version %s\n", "upecman", VERSION);
    printf("\nCopyright (C) %d %s <%s>, GNU GPL version 2 <http://gnu.org/licenses/gpl.html>. This  is  free  software:  you are free to change and redistribute it. There is NO WARRANTY, to the extent permitted by law. USE IT AS IT IS. The author takes no responsability to any damage this software may inflige in your data.\n\n", 2016, "Ruben Carlo Benante", "rcb@beco.cc");
    if(verb > 3) printf("copyr(): Verbose: %d\n", verb); /* -vvvv */
    exit(EXIT_FAILURE);
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief This function initializes some operations before start
 * @details Details to be written
 * @return Void
 * @todo Need to implement it. Its empty now.
 * @author Ruben Carlo Benante
 * @version 20160530.224016
 * @date 2016-05-30
 *
 */

t_game getpellet(int x, int y, t_game g, int n)
{
    int i, j;

    if(g.lab[y][x] == '&')
    {
        g.lab[y][x] = ' ';
        g.pacman.score += 100;
    }
    if(g.lab[y][x] == '.')
    {
        g.lab[y][x] = ' ';
        g.pacman.score += 10;
    }
    if(g.lab[y][x] == 'o')
    {
        g.lab[y][x] = ' ';
        g.pacman.score += 50;
        for(i=blinky; i<=clyde; i++)
        {
            g.ghost[i].inittime[inittime] = time(NULL);
            if(g.ghost[i].dir < down)
                g.ghost[i].dir += 2;
            if(g.ghost[i].dir >= down)
                g.ghost[i].dir -= 2;
            if(g.ghost[i].mode != dead)
                g.ghost[i].mode= afraid;
        }
        for(j=1; j<=n; j+=2)
            for(i=blinky; i<=clyde; i++)
                g.ghost[i].inittime[endtime]--;
    }
    for(i=blinky; i<=clyde; i++)
    {
        if(g.ghost[i].mode == afraid)
        {
            g.ghost[i].inittime[ttime] = time(NULL);
            if(g.ghost[i].inittime[ttime] - g.ghost[i].inittime[inittime] == g.ghost[i].inittime[endtime])
            {
                g.ghost[i].mode = chase;
                g.ghost[i].inittime[endtime] = 11;
            }
        }
    }
    return g;
}

t_game upecman_init(void)
{
    /* initialization */
    int y, f;
    t_game g;

    IFDEBUG("init()");

    for(y = 0; y < LABL; y++)
        strcpy(g.lab[y], labmodel[y]); /* copy the labyrinth (lines of strings) */

    g.pacman.pos.y = 17; /* pacman start position (line) */
    g.pacman.pos.x = 9; /* pacman start position (column) */
    g.pacman.dir = left; /*  pacman start direction */
    g.pacman.life = 3; /* 3 lifes */
    g.pacman.score = 0; /* 0 points */

    for(f = blinky; f <= clyde; f++) /* blinky, pinky, inky and clyde */
    {
        switch(f) /* switch with cases for blinky, pinky, inky and clyde */
        {
            case blinky:
                g.ghost[f].pos.y = 7; /* blinky start position (line) */
                g.ghost[f].pos.x = 9; /* blinky start position (column) */
                g.ghost[f].starget.y = 0; /* preferred corner (line) */
                g.ghost[f].starget.x = 19; /* preferred corner (column) */
                g.ghost[f].inittime[endtime] = 11;
                break;
            case pinky:
                g.ghost[f].pos.y = 9; /* pinky start position (line) */
                g.ghost[f].pos.x = 10; /* pinky start position (column) */
                g.ghost[f].starget.y = 0; /* preferred corner (line) */
                g.ghost[f].starget.x = 0; /* preferred corner (column) */
                g.ghost[f].inittime[endtime] = 11;
                break;
            case inky:
                g.ghost[f].pos.y = 10; /* inky start position (line) */
                g.ghost[f].pos.x = 10; /* inky start position (column) */
                g.ghost[f].starget.y = 22; /* preferred corner (line) */
                g.ghost[f].starget.x = 19; /* preferred corner (column) */
                g.ghost[f].inittime[endtime] = 11;
                break;
            case clyde:
                g.ghost[f].pos.y = 11; /* clyde start position (line) */
                g.ghost[f].pos.x = 10; /* clyde start position (column) */
                g.ghost[f].starget.y = 22; /* preferred corner (line) */
                g.ghost[f].starget.x = 0; /* preferred corner (column) */
                g.ghost[f].inittime[endtime] = 11;
        }
        g.ghost[f].dir = left; /* start direction and future direction: left */
        g.ghost[f].mode = scatter;
    }
    return g;
}
void colorgame(void)
{
    initscr(); /* start ncurses mode screen */
    cbreak(); /* stop line buffering */
    keypad(stdscr, TRUE); /* grab extended keys */
    noecho(); /* stop echoing chars */
    curs_set(0);
    timeout(0); /* do not wait */
    start_color(); /* initialize the color functionality */

    /* Initialize all the colors */
    init_pair(1, COLOR_RED, COLOR_BLACK); /* Blinky */
    init_pair(2, COLOR_MAGENTA, COLOR_BLACK); /* Pinky */
    init_pair(3, COLOR_CYAN, COLOR_BLACK); /* Inky */
    init_pair(4, COLOR_GREEN, COLOR_BLACK); /* Clyde doesn't have orange :( */
    init_pair(5, COLOR_BLUE, COLOR_BLACK); /* Afraid mode: blue with A_BLINK */
    init_pair(6, COLOR_YELLOW, COLOR_BLACK); /* Pacman */
    init_pair(7, COLOR_WHITE, COLOR_BLACK); /* Cherry */
}


/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief This function initializes some operations before start
 * @details Details to be written
 * @return Void
 * @todo Need to implement it. Its empty now.
 * @author Ruben Carlo Benante
 * @version 20160530.224016
 * @date 2016-05-30
 *
 */
void printlab(t_game g, int scry, int scrx)
{
    int y, f;
    int k;

    IFDEBUG("printlab()");
    g.lab[7][9] = ' '; /* clear blinky position */
    g.lab[9][10] = ' '; /* clear pinky position */
    g.lab[10][10] = ' '; /* clear inky position */
    g.lab[11][10] = ' '; /* clear clyde position */

  /*  clear();  clear the screen */

    attron(COLOR_PAIR(5));
    for(y = 0; y < LABL; y++)
        mvprintw(scry/2+y-11, scrx/2-10, "%s\n", g.lab[y]);
    attroff(COLOR_PAIR(5));

    for(y = 0; y < LABL; y++)
        for(k = 0; k < LABC; k++)
            if(g.lab[y][k] == '.' || g.lab[y][k] == 'o')
                mvchgat(scry/2+y-11, scrx/2-10+k, 1, A_BOLD, 6, NULL);

    mvprintw(scry/2+12, scrx/2-10, "LIFE: %d", g.pacman.life); /* quantity of lifes */
    mvprintw(scry/2-12, scrx/2-10, "SCORE: %d", g.pacman.score); /* score acquired on game */
    mvprintw(g.pacman.pos.y+scry/2-11, g.pacman.pos.x+scrx/2-10, "@");

    for(f = blinky; f <= clyde; f++) /* blinky, pinky, inky and clyde */
    {
        if(f == blinky)
        {
            mvprintw(g.ghost[f].pos.y+scry/2-11, g.ghost[f].pos.x+scrx/2-10, "B");
            mvchgat(g.ghost[f].pos.y+scry/2-11, g.ghost[f].pos.x+scrx/2-10, 1, A_BOLD, 1, NULL);
        }
        if(f == pinky)
        {
            mvprintw(g.ghost[f].pos.y+scry/2-11, g.ghost[f].pos.x+scrx/2-10, "P");
            mvchgat(g.ghost[f].pos.y+scry/2-11, g.ghost[f].pos.x+scrx/2-10, 1, A_BOLD, 2, NULL);
        }
        if(f == inky)
        {
            mvprintw(g.ghost[f].pos.y+scry/2-11, g.ghost[f].pos.x+scrx/2-10, "I");
            mvchgat(g.ghost[f].pos.y+scry/2-11, g.ghost[f].pos.x+scrx/2-10, 1, A_BOLD, 3, NULL);
        }
        if(f == clyde)
        {
            mvprintw(g.ghost[f].pos.y+scry/2-11, g.ghost[f].pos.x+scrx/2-10, "C");
            mvchgat(g.ghost[f].pos.y+scry/2-11, g.ghost[f].pos.x+scrx/2-10, 1, A_BOLD, 4, NULL);
        }

        if(g.ghost[f].mode == afraid)
        {
            mvchgat(g.ghost[f].pos.y+scry/2-11, g.ghost[f].pos.x+scrx/2-10, 1, A_BOLD, 5, NULL);
            if(g.ghost[f].inittime[ttime] - g.ghost[f].inittime[inittime] >= 7)
                mvchgat(g.ghost[f].pos.y+scry/2-11, g.ghost[f].pos.x+scrx/2-10, 1, A_BLINK, 5, NULL);
        }
        if(g.ghost[f].mode == dead)
            mvprintw(g.ghost[f].pos.y+scry/2-11, g.ghost[f].pos.x+scrx/2-10, "*");
    }
    if(g.lab[17][9]=='&')
        mvchgat(scry/2+6, scrx/2-1, 1, A_DIM, 1, NULL);
    mvchgat(g.pacman.pos.y+scry/2-11, g.pacman.pos.x+scrx/2-10, 1, A_BOLD, 6, NULL);

    refresh();
}

t_pacman pacmove(t_game g, t_direction next)
{
    int xinc = 0, yinc = 0;

    if(next == left)
        if(g.lab[g.pacman.pos.y][g.pacman.pos.x - 1] != '#')
            g.pacman.dir = left;
    if(next == right)
        if(g.lab[g.pacman.pos.y][g.pacman.pos.x + 1] != '#')
            g.pacman.dir = right;
    if(next == up)
        if(g.lab[g.pacman.pos.y - 1][g.pacman.pos.x] != '#')
            g.pacman.dir = up;
    if(next == down)
        if(g.lab[g.pacman.pos.y + 1][g.pacman.pos.x] != '#' && g.lab[g.pacman.pos.y + 1][g.pacman.pos.x] != '-')
            g.pacman.dir = down;

    if(g.pacman.dir == left)
    {
        if(g.pacman.pos.x == 0 && g.pacman.pos.y == 10)
        {
            g.pacman.pos.x = 19;
            g.pacman.pos.y = 10;
        }
        if(g.lab[g.pacman.pos.y][g.pacman.pos.x - 1] != '#')
        {
            xinc = -1;
            yinc = 0;
        }
        else
        {
            xinc = 0;
            yinc = 0;
        }
    }
    if(g.pacman.dir == right)
    {
        if(g.pacman.pos.x == 19 && g.pacman.pos.y == 10)
        {
            g.pacman.pos.x = 0;
            g.pacman.pos.y = 10;
        }
        if(g.lab[g.pacman.pos.y][g.pacman.pos.x + 1] != '#')
        {
            xinc = +1;
            yinc = 0;
        }
        else
        {
            xinc = 0;
            yinc = 0;
        }
    }
    if(g.pacman.dir == up)
    {
        if(g.lab[g.pacman.pos.y - 1][g.pacman.pos.x] != '#')
        {
            xinc = 0;
            yinc = -1;
        }
        else
        {
            xinc = 0;
            yinc = 0;
        }
    }
    if(g.pacman.dir == down)
    {
        if(g.lab[g.pacman.pos.y + 1][g.pacman.pos.x] != '#' && g.lab[g.pacman.pos.y + 1][g.pacman.pos.x] != '-')
        {
            xinc = 0;
            yinc = +1;
        }
        else
        {
            xinc = 0;
            yinc = 0;
        }
    }
    g.pacman.pos.y += yinc;
    g.pacman.pos.x += xinc;

    return g.pacman;

}
t_game ghostmode(t_game g, int n, int starttime)
{
    int i;
    for(i=blinky; i<=clyde; i++)
    {
        if(g.ghost[i].mode == afraid || g.ghost[i].mode == dead)
            continue;

        g.ghost[i].inittime[ttime] = time(NULL);
        if(n==1)
        {
            if(g.ghost[i].inittime[ttime] - starttime <= 7)
                g.ghost[i].mode = scatter;
            else if(g.ghost[i].inittime[ttime] - starttime <= 27)
                g.ghost[i].mode = chase;
            else if(g.ghost[i].inittime[ttime] - starttime <= 34)
                g.ghost[i].mode = scatter;
            else if(g.ghost[i].inittime[ttime] - starttime <= 54)
                g.ghost[i].mode = chase;
            else if(g.ghost[i].inittime[ttime] - starttime <= 59)
                g.ghost[i].mode = scatter;
            else if(g.ghost[i].inittime[ttime] - starttime <= 79)
                g.ghost[i].mode = chase;
            else if(g.ghost[i].inittime[ttime] - starttime <= 84)
                g.ghost[i].mode = scatter;
            else
                g.ghost[i].mode = chase;
        }
        if(n>1 && n<=4)
        {
            if(g.ghost[i].inittime[ttime] - starttime <= 7)
                g.ghost[i].mode = scatter;
            else if(g.ghost[i].inittime[ttime] - starttime <= 27)
                g.ghost[i].mode = chase;
            else if(g.ghost[i].inittime[ttime] - starttime <= 34)
                g.ghost[i].mode = scatter;
            else if(g.ghost[i].inittime[ttime] - starttime <= 54)
                g.ghost[i].mode = chase;
            else if(g.ghost[i].inittime[ttime] - starttime <= 59)
                g.ghost[i].mode = scatter;
            else
                g.ghost[i].mode = chase;
        }
        if(n>4)
        {
            if(g.ghost[i].inittime[ttime] - starttime <= 5)
                g.ghost[i].mode = scatter;
            else if(g.ghost[i].inittime[ttime] - starttime <= 25)
                g.ghost[i].mode = chase;
            else if(g.ghost[i].inittime[ttime] - starttime <= 30)
                g.ghost[i].mode = scatter;
            else if(g.ghost[i].inittime[ttime] - starttime <= 50)
                g.ghost[i].mode = chase;
            else if(g.ghost[i].inittime[ttime] - starttime <= 55)
                g.ghost[i].mode = scatter;
            else
                g.ghost[i].mode = chase;
        }
    }
    return g;
}

t_game ghostmove(t_game g)
{
    int i, sy, sx;
    for(i = blinky; i<=clyde; i++)
    {
        switch(i)
        {
            case blinky:
                if(g.ghost[i].mode == dead)
                {
                    g.ghost[i].pos.y = 10;
                    g.ghost[i].pos.x = 10;
                    g.ghost[i].mode = chase;
                    continue;
                }
                if(g.ghost[i].mode == chase)
                {
                    g.ghost[i].starget.y = g.pacman.pos.y;
                    g.ghost[i].starget.x = g.pacman.pos.x;
                }
                if(g.ghost[i].mode == scatter)
                {
                    g.ghost[i].starget.y = 0;
                    g.ghost[i].starget.x = 19;
                }
                if(g.ghost[i].mode == afraid)
                {
                    g.ghost[i].starget.y = rand()%20;
                    g.ghost[i].starget.x = rand()%20;
                }
                break;
            case pinky:
                if(g.ghost[i].pos.y > 7 && g.ghost[i].pos.y <= 11 && g.ghost[i].pos.x == 10)
                {
                    g.ghost[i].pos.y--;
                    continue;
                }
                if(g.ghost[i].mode == dead)
                {
                    g.ghost[i].pos.y = 9;
                    g.ghost[i].pos.x = 10;
                    g.ghost[i].mode = chase;
                    continue;
                }
                if(g.ghost[i].mode == chase)
                {
                    if(g.pacman.dir == up)
                    {
                        if(g.pacman.pos.y-4 < 0)
                            g.ghost[i].starget.y = 0;
                        else
                            g.ghost[i].starget.y = g.pacman.pos.y-4;
                        g.ghost[i].starget.x = g.pacman.pos.x;
                    }
                    if(g.pacman.dir == down)
                    {
                        if(g.pacman.pos.y+4 > 22)
                            g.ghost[i].starget.y = 22;
                        else
                            g.ghost[i].starget.y = g.pacman.pos.y+4;
                        g.ghost[i].starget.x = g.pacman.pos.x;
                    }
                    if(g.pacman.dir == right)
                    {
                        if(g.pacman.pos.x+4 > 19)
                            g.ghost[i].starget.x = 19;
                        else
                            g.ghost[i].starget.x = g.pacman.pos.x+4;
                        g.ghost[i].starget.y = g.pacman.pos.y;

                    }
                    if(g.pacman.dir == left)
                    {
                        if(g.pacman.pos.x-4 < 0)
                            g.ghost[i].starget.x = 0;
                        else
                            g.ghost[i].starget.x = g.pacman.pos.x-4;
                        g.ghost[i].starget.y = g.pacman.pos.y;

                    }

                }
                if(g.ghost[i].mode == scatter)
                {
                    g.ghost[i].starget.y = 0;
                    g.ghost[i].starget.x = 0;
                }
                if(g.ghost[i].mode == afraid)
                {
                    g.ghost[i].starget.y = rand()%20;
                    g.ghost[i].starget.x = rand()%20;
                }
                break;
            case inky:
                if(g.ghost[i].pos.y > 7 && g.ghost[i].pos.y <= 11 && g.ghost[i].pos.x == 10)
                {
                    g.ghost[i].pos.y--;
                    continue;
                }
                if(g.ghost[i].mode == dead)
                {
                    g.ghost[i].pos.y = 10;
                    g.ghost[i].pos.x = 10;
                    g.ghost[i].mode = chase;
                    continue;
                }
                if(g.ghost[i].mode == chase)
                {
                    sy = g.pacman.pos.y - g.ghost[blinky].pos.y;
                    sx = g.pacman.pos.x - g.ghost[blinky].pos.x;
                    if(g.pacman.dir == up)
                    {
                        if(g.pacman.pos.y-1 - 2*sy < 0)
                            g.ghost[i].starget.y = 0;
                        else
                            g.ghost[i].starget.y = g.pacman.pos.y-1 - 2*sy;
                        g.ghost[i].starget.x = g.pacman.pos.x + sx;
                    }
                    if(g.pacman.dir == down)
                    {
                        if(g.pacman.pos.y+1 + 2*sy > 22)
                            g.ghost[i].starget.y = 22;
                        else
                            g.ghost[i].starget.y = g.pacman.pos.y+1 + 2*sy;
                        g.ghost[i].starget.x = g.pacman.pos.x + sx;
                    }
                    if(g.pacman.dir == right)
                    {
                        g.ghost[i].starget.y = g.pacman.pos.y + sy;
                        if(g.pacman.pos.x+1 + 2*sx > 20)
                            g.ghost[i].starget.x = 20;
                        else
                            g.ghost[i].starget.x = g.pacman.pos.x+1 + 2*sx;
                    }
                    if(g.pacman.dir == left)
                    {
                        g.ghost[i].starget.y = g.pacman.pos.y + sy;
                        if(g.pacman.pos.x-1 - 2*sx < 0)
                            g.ghost[i].starget.x = 0;
                        else
                            g.ghost[i].starget.x = g.pacman.pos.x-1 - 2*sx;
                    }
                }
                if(g.ghost[i].mode == scatter)
                {
                    g.ghost[i].starget.y = 22;
                    g.ghost[i].starget.x = 19;
                }
                if(g.ghost[i].mode == afraid)
                {
                    g.ghost[i].starget.y = rand()%20;
                    g.ghost[i].starget.x = rand()%20;
                }
                break;
            case clyde:
                if(g.ghost[i].pos.y > 7 && g.ghost[i].pos.y <= 11 && g.ghost[i].pos.x == 10)
                {
                    g.ghost[i].pos.y--;
                    continue;
                }
                if(g.ghost[i].mode == dead)
                {
                    g.ghost[i].pos.y = 11;
                    g.ghost[i].pos.x = 10;
                    g.ghost[i].mode = chase;
                    g.ghost[i].dir = left;
                    continue;
                }
                if(g.ghost[i].mode == chase)
                {
                    sy = abs(g.pacman.pos.y - g.ghost[i].pos.y);
                    sx = abs(g.pacman.pos.x - g.ghost[i].pos.x);
                    if(sy + sx >= 8)
                        g.ghost[i].starget = g.pacman.pos;
                    else
                    {
                        g.ghost[i].starget.y = 22;
                        g.ghost[i].starget.x = 0;
                    }
                }
                if(g.ghost[i].mode == scatter)
                {
                    g.ghost[i].starget.y = 22;
                    g.ghost[i].starget.x = 0;
                }
                if(g.ghost[i].mode == afraid)
                {
                    g.ghost[i].starget.y = rand()%20;
                    g.ghost[i].starget.x = rand()%20;
                }
                break;
        }
      /*  if((g.lab[g.ghost[i].pos.y-1][g.ghost[i].pos.x] != '#' && g.lab[g.ghost[i].pos.y][g.ghost[i].pos.x-1] != '#') || (g.lab[g.ghost[i].pos.y][g.ghost[i].pos.x-1] != '#' && g.lab[g.ghost[i].pos.y+1][g.ghost[i].pos.x] != '#') || (g.lab[g.ghost[i].pos.y][g.ghost[i].pos.x+1] != '#' && g.lab[g.ghost[i].pos.y-1][g.ghost[i].pos.x] != '#') || (g.lab[g.ghost[i].pos.y][g.ghost[i].pos.x+1] != '#' && g.lab[g.ghost[i].pos.y+1][g.ghost[i].pos.x] != '#') || (g.lab[g.ghost[i].pos.y][g.ghost[i].pos.x-1] != '#' && g.lab[g.ghost[i].pos.y][g.ghost[i].pos.x+1] != '#' && g.ghost[i].dir%2 != 0) || (g.lab[g.ghost[i].pos.y-1][g.ghost[i].pos.x] != '#' && g.lab[g.ghost[i].pos.y+1][g.ghost[i].pos.x] != '#' && g.ghost[i].dir%2 == 0)) */
        g = targetcalc(g, i);
        if(g.ghost[i].dir == up && g.lab[g.ghost[i].pos.y-1][g.ghost[i].pos.x] != '#')
            g.ghost[i].pos.y--;
        if(g.ghost[i].dir == left && g.lab[g.ghost[i].pos.y][g.ghost[i].pos.x-1] != '#')
            g.ghost[i].pos.x--;
        if(g.ghost[i].dir == down && g.lab[g.ghost[i].pos.y+1][g.ghost[i].pos.x] != '#' && g.lab[g.ghost[i].pos.y+1][g.ghost[i].pos.x] != '-')
            g.ghost[i].pos.y++;
        if(g.ghost[i].dir == right && g.lab[g.ghost[i].pos.y][g.ghost[i].pos.x+1] != '#')
            g.ghost[i].pos.x++;
        if(g.ghost[i].pos.x == 19 && g.ghost[i].pos.y == 10 && g.ghost[i].dir == right)
        {
            g.ghost[i].pos.x = 0;
            g.ghost[i].pos.y = 10;
        }
        if(g.ghost[i].pos.x == 0 && g.ghost[i].pos.y == 10 && g.ghost[i].dir == left)
        {
            g.ghost[i].pos.x = 18;
            g.ghost[i].pos.y = 10;
        }
    }
    return g;
}
t_game targetcalc(t_game g, int f)
{
    float xd[4] = {0}, yd[4] = {0}, d[4] = {0};
    if(g.ghost[f].starget.x == g.ghost[f].pos.x)
    {
        xd[0] = 0;
        xd[2] = 0;
    }
    else
    {
        xd[0] = (g.ghost[f].starget.x - g.ghost[f].pos.x)*(g.ghost[f].starget.x - g.ghost[f].pos.x);
        xd[2] = (g.ghost[f].starget.x - g.ghost[f].pos.x)*(g.ghost[f].starget.x - g.ghost[f].pos.x);
    }
    if(g.ghost[f].starget.y == g.ghost[f].pos.y-1)
        yd[0] = 0;
    else
        yd[0] = (g.ghost[f].starget.y - g.ghost[f].pos.y-1)*(g.ghost[f].starget.y - g.ghost[f].pos.y-1);
    if(g.ghost[f].starget.x == g.ghost[f].pos.x-1)
        xd[1] = 0;
    else
        xd[1] = (g.ghost[f].starget.x - g.ghost[f].pos.x-1)*(g.ghost[f].starget.x - g.ghost[f].pos.x-1);
    if(g.ghost[f].starget.y == g.ghost[f].pos.y)
    {
        yd[1] = 0;
        yd[3] = 0;
    }
    else
    {
        yd[1] = (g.ghost[f].starget.y - g.ghost[f].pos.y)*(g.ghost[f].starget.y - g.ghost[f].pos.y);
        yd[3] = (g.ghost[f].starget.y - g.ghost[f].pos.y)*(g.ghost[f].starget.y - g.ghost[f].pos.y);
    }
    if(g.ghost[f].starget.y == g.ghost[f].pos.y+1)
        yd[2] = 0;
    else
        yd[2] = (g.ghost[f].starget.y - g.ghost[f].pos.y+1)*(g.ghost[f].starget.y - g.ghost[f].pos.y+1);
    if(g.ghost[f].starget.x == g.ghost[f].pos.x+1)
        xd[3] = 0;
    else
        xd[3] = (g.ghost[f].starget.x - g.ghost[f].pos.x+1)*(g.ghost[f].starget.x - g.ghost[f].pos.x+1);
    d[0] = sqrt(xd[0] + yd[0]);
    d[1] = sqrt(xd[1] + yd[1]);
    d[2] = sqrt(xd[2] + yd[2]);
    d[3] = sqrt(xd[3] + yd[3]);


    if(d[0] < d[1] && d[0] < d[2] && d[0] < d[3])
    {
        if(g.lab[g.ghost[f].pos.y-1][g.ghost[f].pos.x] != '#' && g.ghost[f].dir != down)
            g.ghost[f].dir = up;
        else if(d[1] < d[2] && d[1] < d[3])
        {
            if(g.lab[g.ghost[f].pos.y][g.ghost[f].pos.x-1] != '#' && g.ghost[f].dir != right)
                g.ghost[f].dir = left;
            else if(d[2] < d[3])
            {
                if(g.lab[g.ghost[f].pos.y+1][g.ghost[f].pos.x] != '#' && g.ghost[f].dir != up)
                    g.ghost[f].dir = down;
                else
                    g.ghost[f].dir = right;
            }
            else if(d[3] < d[2])
            {
                if(g.lab[g.ghost[f].pos.y][g.ghost[f].pos.x+1] != '#' && g.ghost[f].dir != left)
                    g.ghost[f].dir = right;
                else
                    g.ghost[f].dir = down;
            }
        }
        else if(d[2] < d[1] && d[2] < d[3])
        {
            if(g.lab[g.ghost[f].pos.y+1][g.ghost[f].pos.x] != '#' && g.ghost[f].dir != up)
                g.ghost[f].dir = down;
            else if(d[1] < d[3])
            {
                if(g.lab[g.ghost[f].pos.y][g.ghost[f].pos.x-1] != '#' && g.ghost[f].dir != right)
                    g.ghost[f].dir = left;
                else
                    g.ghost[f].dir = right;
            }
            else if(d[3] < d[1])
            {
                if(g.lab[g.ghost[f].pos.y][g.ghost[f].pos.x+1] != '#' && g.ghost[f].dir != left)
                    g.ghost[f].dir = right;
                else
                    g.ghost[f].dir = left;
            }
        }
        else
        {
            if(g.lab[g.ghost[f].pos.y][g.ghost[f].pos.x+1] != '#' && g.ghost[f].dir != left)
                g.ghost[f].dir = right;
            else if(d[1] < d[2])
            {
                if(g.lab[g.ghost[f].pos.y][g.ghost[f].pos.x-1] != '#' && g.ghost[f].dir != right)
                    g.ghost[f].dir = left;
                else
                    g.ghost[f].dir = down;
            }
            else if(d[2] < d[1])
            {
                if(g.lab[g.ghost[f].pos.y+1][g.ghost[f].pos.x] != '#' && g.ghost[f].dir != up)
                    g.ghost[f].dir = down;
                else
                    g.ghost[f].dir = left;
            }
        }
    }
    if(d[1] < d[0] && d[1] < d[2] && d[1] < d[3])
    {
        if(g.lab[g.ghost[f].pos.y][g.ghost[f].pos.x-1] != '#' && g.ghost[f].dir != right)
            g.ghost[f].dir = left;
        else if(d[0] < d[2] && d[0] < d[3])
        {
            if(g.lab[g.ghost[f].pos.y-1][g.ghost[f].pos.x] != '#' && g.ghost[f].dir != down)
                g.ghost[f].dir = up;
            else if(d[2] < d[3])
            {
                if(g.lab[g.ghost[f].pos.y+1][g.ghost[f].pos.x] != '#' && g.ghost[f].dir != up)
                    g.ghost[f].dir = down;
                else
                    g.ghost[f].dir = right;
            }
            else if(d[3] < d[2])
            {
                if(g.lab[g.ghost[f].pos.y][g.ghost[f].pos.x+1] != '#' && g.ghost[f].dir != left)
                    g.ghost[f].dir = right;
                else
                    g.ghost[f].dir = down;
            }
        }
        else if(d[2] < d[0] && d[2] < d[3])
        {
            if(g.lab[g.ghost[f].pos.y+1][g.ghost[f].pos.x] != '#' && g.ghost[f].dir != up)
                g.ghost[f].dir = down;
            else if(d[0] < d[3])
            {
                if(g.lab[g.ghost[f].pos.y-1][g.ghost[f].pos.x] != '#' && g.ghost[f].dir != down)
                    g.ghost[f].dir = up;
                else
                    g.ghost[f].dir = right;
            }
            else if(d[3] < d[0])
            {
                if(g.lab[g.ghost[f].pos.y][g.ghost[f].pos.x+1] != '#' && g.ghost[f].dir != left)
                    g.ghost[f].dir = right;
                else
                    g.ghost[f].dir = up;
            }
        }
        else
        {
            if(g.lab[g.ghost[f].pos.y][g.ghost[f].pos.x+1] != '#' && g.ghost[f].dir != left)
                g.ghost[f].dir = right;
            else if(d[0] < d[2])
            {
                if(g.lab[g.ghost[f].pos.y-1][g.ghost[f].pos.x] != '#' && g.ghost[f].dir != down)
                    g.ghost[f].dir = up;
                else
                    g.ghost[f].dir = down;
            }
            else if(d[2] < d[0])
            {
                if(g.lab[g.ghost[f].pos.y+1][g.ghost[f].pos.x] != '#' && g.ghost[f].dir != up)
                    g.ghost[f].dir = down;
                else
                    g.ghost[f].dir = up;
            }
        }
    }
    if(d[2] < d[0] && d[2] < d[1] && d[2] < d[3])
    {
        if(g.lab[g.ghost[f].pos.y+1][g.ghost[f].pos.x] != '#' && g.ghost[f].dir != up)
            g.ghost[f].dir = down;
        else if(d[1] < d[0] && d[1] < d[3])
        {
            if(g.lab[g.ghost[f].pos.y][g.ghost[f].pos.x-1] != '#' && g.ghost[f].dir != right)
                g.ghost[f].dir = left;
            else if(d[0] < d[3])
            {
                if(g.lab[g.ghost[f].pos.y-1][g.ghost[f].pos.x] != '#' && g.ghost[f].dir != down)
                    g.ghost[f].dir = up;
                else
                    g.ghost[f].dir = right;
            }
            else if(d[3] < d[0])
            {
                if(g.lab[g.ghost[f].pos.y][g.ghost[f].pos.x+1] != '#' && g.ghost[f].dir != left)
                    g.ghost[f].dir = right;
                else
                    g.ghost[f].dir = up;
            }
        }
        else if(d[0] < d[1] && d[0] < d[3])
        {
            if(g.lab[g.ghost[f].pos.y-1][g.ghost[f].pos.x] != '#' && g.ghost[f].dir != down)
                g.ghost[f].dir = up;
            else if(d[1] < d[3])
            {
                if(g.lab[g.ghost[f].pos.y][g.ghost[f].pos.x-1] != '#' && g.ghost[f].dir != right)
                    g.ghost[f].dir = left;
                else
                    g.ghost[f].dir = right;
            }
            else if(d[3] < d[1])
            {
                if(g.lab[g.ghost[f].pos.y][g.ghost[f].pos.x+1] != '#' && g.ghost[f].dir != left)
                    g.ghost[f].dir = right;
                else
                    g.ghost[f].dir = left;
            }
        }
        else
        {
            if(g.lab[g.ghost[f].pos.y][g.ghost[f].pos.x+1] != '#' && g.ghost[f].dir != left)
                g.ghost[f].dir = right;
            else if(d[1] < d[0])
            {
                if(g.lab[g.ghost[f].pos.y][g.ghost[f].pos.x-1] != '#' && g.ghost[f].dir != right)
                    g.ghost[f].dir = left;
                else
                    g.ghost[f].dir = up;
            }
            else if(d[0] < d[1])
            {
                if(g.lab[g.ghost[f].pos.y-1][g.ghost[f].pos.x] != '#' && g.ghost[f].dir != down)
                    g.ghost[f].dir = up;
                else
                    g.ghost[f].dir = left;
            }
        }
    }
    if(d[3] < d[0] && d[3] < d[1] && d[3] < d[2])
    {
        if(g.lab[g.ghost[f].pos.y][g.ghost[f].pos.x+1] != '#' && g.ghost[f].dir != left)
            g.ghost[f].dir = right;
        else if(d[1] < d[0] && d[1] < d[2])
        {
            if(g.lab[g.ghost[f].pos.y][g.ghost[f].pos.x-1] != '#' && g.ghost[f].dir != right)
                g.ghost[f].dir = left;
            else if(d[2] < d[0])
            {
                if(g.lab[g.ghost[f].pos.y+1][g.ghost[f].pos.x] != '#' && g.ghost[f].dir != up)
                    g.ghost[f].dir = down;
                else
                    g.ghost[f].dir = up;
            }
            else if(d[0] < d[2])
            {
                if(g.lab[g.ghost[f].pos.y-1][g.ghost[f].pos.x] != '#' && g.ghost[f].dir != down)
                    g.ghost[f].dir = up;
                else
                    g.ghost[f].dir = down;
            }
        }
        else if(d[2] < d[0] && d[2] < d[1])
        {
            if(g.lab[g.ghost[f].pos.y+1][g.ghost[f].pos.x] != '#' && g.ghost[f].dir != up)
                g.ghost[f].dir = down;
            else if(d[1] < d[0])
            {
                if(g.lab[g.ghost[f].pos.y][g.ghost[f].pos.x-1] != '#' && g.ghost[f].dir != right)
                    g.ghost[f].dir = left;
                else
                    g.ghost[f].dir = up;
            }
            else if(d[0] < d[1])
            {
                if(g.lab[g.ghost[f].pos.y-1][g.ghost[f].pos.x] != '#' && g.ghost[f].dir != down)
                    g.ghost[f].dir = up;
                else
                    g.ghost[f].dir = left;
            }
        }
        else
        {
            if(g.lab[g.ghost[f].pos.y-1][g.ghost[f].pos.x] != '#' && g.ghost[f].dir != down)
                g.ghost[f].dir = up;
            else if(d[1] < d[2])
            {
                if(g.lab[g.ghost[f].pos.y][g.ghost[f].pos.x-1] != '#' && g.ghost[f].dir != right)
                    g.ghost[f].dir = left;
                else
                    g.ghost[f].dir = down;
            }
            else if(d[2] < d[1])
            {
                if(g.lab[g.ghost[f].pos.y+1][g.ghost[f].pos.x] != '#' && g.ghost[f].dir != up)
                    g.ghost[f].dir = down;
                else
                    g.ghost[f].dir = left;
            }
        }
    }
    return g;
}
t_game relevel(t_game g)
{
    int y, f;
    for(y = 0; y < LABL; y++)
        strcpy(g.lab[y], labmodel[y]); /* copy the labyrinth (lines of strings) */

    g.pacman.pos.y = 17; /* pacman start position (line) */
    g.pacman.pos.x = 9; /* pacman start position (column) */
    g.pacman.dir = left; /* pacman start direction */

    for(f = blinky; f <= clyde; f++) /* blinky, pinky, inky and clyde */
    {
        switch(f) /* switch with cases for blinky, pinky, inky and clyde */
        {
            case blinky:
                g.ghost[f].pos.y = 7; /* blinky start position (line) */
                g.ghost[f].pos.x = 9; /* blinky start position (column) */
                break;
            case pinky:
                g.ghost[f].pos.y = 9; /* pinky start position (line) */
                g.ghost[f].pos.x = 10; /* pinky start position (column) */
                break;
            case inky:
                g.ghost[f].pos.y = 10; /* inky start position (line) */
                g.ghost[f].pos.x = 10; /* inky start position (column) */
                break;
            case clyde:
                g.ghost[f].pos.y = 11; /* clyde start position (line) */
                g.ghost[f].pos.x = 10; /* clyde start position (column) */
                break;
        }
        g.ghost[f].dir = left; /* start direction and future direction: left */
        g.ghost[f].mode = scatter;
    }
    return g;

}

/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160612.142044      */
