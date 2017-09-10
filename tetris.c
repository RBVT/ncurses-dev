#include <stdio.h>
#include <unistd.h>
#include <ncurses.h>



 
int main(int argc, char *argv[])

{

    int hour, minute, second;
    int posx, posy;
    int choice;

    hour = minute = second = 0;
    posy = 1;
    posx = 1;
           
    WINDOW *main_win;
    WINDOW *player1_win, *player2_win;

//  WINDOW *score1_win, *score2_win; 
    
    initscr();
    curs_set(0);
    start_color();
    use_default_colors();
    
    noecho();
    curs_set(FALSE);

    init_pair(1, COLOR_BLACK, COLOR_YELLOW);
    init_pair(2, COLOR_BLACK, COLOR_CYAN);
    

    refresh();
    
    

 
    main_win = newwin(24, 42, 0, 0);
    player1_win = newwin(20, 20, 2, 1);   
    player2_win = newwin(20, 20, 2, 21);

    refresh();

print_scr:

    {

    box(main_win, 0, 0);
    box(player1_win, 0, 0);
    box(player2_win, 0, 0);



        


wattron(main_win, COLOR_PAIR(1));

mvwprintw(main_win, 1, 8, "PLAYER 1");

wattroff(main_win, COLOR_PAIR(1));



wattron(main_win, COLOR_PAIR(2));

mvwprintw(main_win, 1, 26, "PLAYER 2");

wattroff(main_win, COLOR_PAIR(2));



mvwprintw(main_win, 22, 17, "%02d:%02d:%02d", hour, minute, second);


//-------------------------------------------------

wattron(player1_win, COLOR_PAIR(1));

mvwprintw(player1_win, posy -1, posx + 5, "  ");
mvwprintw(player1_win, posy, posx +5, "  ");

wattroff(player1_win, COLOR_PAIR(1));
//-------------------------------------------------



//-------------------------------------------------

wattron(player2_win, COLOR_PAIR(2));


mvwprintw(player2_win, posy - 1, posx + 5, "  ");
mvwprintw(player2_win, posy, posx + 5, "      ");


wattroff(player2_win, COLOR_PAIR(2));

//-------------------------------------------------
    
    }

timer_scr:


   { 

if
    ( second == 60 )

        {
   
    minute += 1;
    second = 0;

        }

if
    ( minute == 60 )

        {
        
        hour += 1;
        minute = 0;

        }

if
    ( hour == 24 )
       
        {
        
        hour == 0;
        minute == 0; 

        }

border_scr:

{

for
    ( posy == 17; posy > 17;)
   
    {

    posy = 2;

    }

}



wrefresh_scr:


    {

    wrefresh(main_win);
    wrefresh(player1_win);
    wrefresh(player2_win);   
  
    sleep(1);
   
    wclear(player1_win);
    wclear(player2_win);

    second++;
    posy++;


    keypad(stdscr, TRUE);

while

    ((getch()) == 'q')
    choice++;
goto print_scr;

    switch(choice)

    {

    case KEY_UP:
     
break;
    
    case KEY_DOWN:
    posy++;
break;

    case KEY_RIGHT:
    posx++;
break;

    case KEY_LEFT:
    posx--;
break;    

    }
}



goto exit_scr;

    }    
    

exit_scr:

    delwin(main_win);
    delwin(player1_win);
    delwin(player2_win); 

    endwin();
 
    return 0;
 
}


