#include "ncurses_utils.h"

#include <menu.h>
#include <ncurses.h>

#include "menus_ncurses.h"

void
start_ncurses ()
{
  initscr (); /* start curses mode */
  cbreak (); /* don't wait for return during input */
  noecho (); /* don't echo() while we do getch */
  keypad (stdscr, TRUE); /* we get special keys */
  curs_set (0); /* makes the cursor invisible */
}

void
main_loop_ncurses ()
{
  start_ncurses ();
  
  WINDOW *main_window;
  main_window = newwin (LINES, COLS, 0, 0);
  keypad (main_window, TRUE); /* we get special keys */

  bool quit = 0;
  int key_pressed;
  int menu_selection = 0;

  MENU *main_menu = initialize_main_menu ();

  set_menu_win (main_menu, main_window);
  set_menu_sub (main_menu, derwin (main_window, LINES - 10, COLS - 10, 5, 5));

  set_menu_mark (main_menu, " >> ");

  post_menu (main_menu);
  wrefresh (main_window);

  while (!quit)
    {
      key_pressed = wgetch (main_window);
      switch (key_pressed)
	{
	case 113: /* q */
	  quit = 1;
	  break;

	case 81: /* Q */
	  quit = 1;
	  break;

	case 10:
	  switch (menu_selection)
	    {
	    /* case 0: */
	    /*   break; */
	    case 2:
	      quit = 1;
	      break;
	    }
	  break;

	case KEY_DOWN:
	  menu_driver(main_menu, REQ_DOWN_ITEM);
	  menu_selection++;
	  break;

	case KEY_UP:
	  menu_driver(main_menu, REQ_UP_ITEM);
	  menu_selection--;
	  break;
	}
      wrefresh(main_window);
    }

  unpost_menu(main_menu);
  free_menu(main_menu);
  quit_ncurses (main_window);
}

void
quit_ncurses (WINDOW *main_window)
{
  delwin (main_window);
  endwin (); /* End curses mode */
}
