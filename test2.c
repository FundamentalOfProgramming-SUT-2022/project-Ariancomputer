#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# define limit 1000
int x = 0;
char address[500]={0};
char file[500][1000]={0};
char highlight[500][1000]={0};
void cat_file();
void get_address(char * command);
int main(){
	initscr();
    start_color();
    noecho();
    keypad(stdscr,TRUE);
    char * name = calloc(limit , sizeof(char));
    strcpy(name , "NULL");
    init_pair(1,COLOR_WHITE,COLOR_BLACK);
    init_pair(2,COLOR_CYAN,COLOR_BLACK);
    init_pair(3,COLOR_BLACK,COLOR_WHITE);
    init_pair(4,COLOR_RED,COLOR_MAGENTA);
    init_pair(5,COLOR_BLUE,COLOR_BLACK);
    init_pair(6,COLOR_GREEN,COLOR_MAGENTA);
    init_pair(7,COLOR_RED,COLOR_WHITE);
    init_pair(8 , COLOR_GREEN , COLOR_YELLOW);
    char mode[10];
    int chert = 0;
    int save = 0;
    strcpy(mode,"NORMAL");
    char  * command = calloc(limit , sizeof(char));
    char c = 'o';
    int i = 0 , modei = 3 , saveds = 6;
    int choos=0;
    while(c != 'q')
    {
        attron(COLOR_PAIR(modei));
        mvprintw(LINES-2 , 0  , "%s" , mode);
        attroff(COLOR_PAIR(modei));
        attron(COLOR_PAIR(1));
        for(int i = 0 ; i < LINES-2 ; i++ )
            {
                if(i>x)
                mvprintw(i , 0 , "~");
            }

        attroff(COLOR_PAIR(1));
        attron(COLOR_PAIR(6));

        attroff(COLOR_PAIR(6));
        c = getch();
        if(c ==':')
            {
            while(c !='\n')
                {

                command[i++] = c;
                command[i] = '\0';
                attron(COLOR_PAIR(1));
                mvprintw(LINES-1 , 0 , "%s" , command );
                attroff(COLOR_PAIR(1));
                c = getch();
                }
            i = 0;
            for(int j=0; j<COLS; j++){
                    mvprintw(LINES-1, j, " ");
                }
                refresh();

            if(strstr(command,"open"))
            {
                get_address(command);
                cat_file();
            }

            else if(strstr(command,"save"))
            {
                save  = 1 ;
            }
            attron(COLOR_PAIR(4));
                choos++;
                mvprintw(LINES-2-choos , 8 , "%s" , address);
                if(saveds == 6)
                {
                    mvprintw(LINES-2-choos , 8+strlen(address) , "%s" , "   -");
                }
                else
                {

                    mvprintw(LINES-2-choos , 8+strlen(address) , "%s" , "   +");
                }
                attroff(COLOR_PAIR(4));
            command[0]='\0';
            refresh();
            }
        int X = 0;
        int Y = 0;

        if(c=='v')
            {
                move(0, 0);
                modei = 4;
                strcpy(mode , "VISUAL");
                attron(COLOR_PAIR(modei));
                mvprintw(LINES-2 , 0  , "%s" , mode);
                attroff(COLOR_PAIR(modei));
                attron(COLOR_PAIR(8));
                mvprintw(X , Y  , "%c" , file[X][Y]+1);
                while (c != 27) {
                    c = getch();
                    if (c == 'k') {
                        if(X != 0 ) {
                            move(--X, Y);
                        }
                    }
                    else if (c == 'l') {
                        move(X, ++Y);
                    }
                    else if (c == 'j') {
                        move(++X, Y);
                    }
                    else if (c == 'h') {
                        if(Y != 0 ) {
                            move(X, --Y);
                        }
                    }
                    mvprintw(X , Y  , "%c" , file[X][Y]);
                }
                attroff(COLOR_PAIR(modei));
            }
        for(int i = 0 ; i < X ; i++)
        {   if(i != X) {
                for (int j = 0 ; file[i][j] != '\0' ; j++ )
                    highlight[i][j] = file[i][j];
            }
            else
            {
                for(int j = 0 ; j <= Y ; j++)
                    highlight[i][j] = file[i][j];
            }
        }
        for(int u = 0 ; u <= X ; u++)
            mvprintw(X+5 , 10  , "%s" , highlight[X]);
        if(c == 'm')
            {
                modei = 3;
                strcpy(mode , "NORMAL");
            }
        int save_checker = 0;
        if(c == 'i') {
            save_checker = 1;
            move(0, 0);
            modei = 5;
            strcpy(mode, "INSERT");
            attron(COLOR_PAIR(modei));
            mvprintw(LINES-2 , 0  , "%s" , mode);
            attroff(COLOR_PAIR(modei));
            attron(COLOR_PAIR(5));
            while (c != 27) {
                c = getch();
                if (c == 'k') {
                    if(X != 0)
                    move(--X, Y);
                }
                else if (c == 'l') {
                    move(X, ++Y);
                }
                else if (c == 'j') {
                    move(++X, Y);
                }
                else if (c == 'h') {
                    if(Y != 0)
                    move(X, --Y);
                }
                else
                {
                    if(c =='\n') {
                        X++;
                        Y = 0;
                        move(X,0);
                    }
                    else if(c != 27) {
                        file[X][Y] = c;
                        mvprintw(X, Y++, "%c", c);
                    }
                }

            }
            attroff(COLOR_PAIR(5));
        }
        for(int u = 0 ; file[0][u+1] != '\0' ; u++)
            file[0][u] = file[0][u+1];
        FILE * fp;
        fp = fopen( address , "a");
        if( save && save_checker )
        {
            for(int i = 0 ; i < X ; i++)
            fprintf(fp , "%s\n" , file[i] );
        }
        if(c == 's')
            {
                saveds = 7;
            }
    name[strlen(name)-4] = '\0';
        chert++;
    }


	refresh();
	getch();
	endwin();
    return 0;
}
void get_address(char * command)
{   int check=0;
    for(int i = 14 ; *(command+i) != '\0' ; i++ ) {
        if(*(command+i) == '\\')
            check = i ;
    }
    for(int j = check+1 ; *(command+j) != '\0' ; j++)
        address[j-check-1] = *(command+j);
//    mvprintw(5 , 0 , "%s" , address );
}
void cat_file()
{   char ch;
    int y = 2;
    int temp = 0;
    FILE * fp;
    fp = fopen(address , "r");
    if(fp == NULL)
    {
        fp = fopen(address , "w");
    }

    do {
        if(temp ==0) {
            mvprintw(x, 0, "%d", x + 1);
            mvprintw(x, 1, "%s", " ");
        }
        ch = fgetc(fp);
        mvprintw(x , y , "%c" , ch );
        y++;
        temp = 1;
        if(ch =='\n')
        {   temp = 0;
            x++;
            y = 2;
        }
    } while (ch != EOF);
    fclose(fp);
    printf("\n");
}