#include "menus_ncurses.h"

#include <menu.h>
#include <stdlib.h>

MENU *
initialize_main_menu ()
{
  char *choices[] = {"Watch stuff",
  		     "Options",
  		     "Quit"};

  ITEM **main_menu_items;
  MENU *main_menu;
  int n_choices;
  int i;

  /* Initialize items */
  n_choices = sizeof (choices) / sizeof (choices[0]);
  main_menu_items = (ITEM **) calloc (n_choices + 1, sizeof (ITEM *));

  for (i = 0; i < n_choices; i++)
    main_menu_items[i] = new_item (choices[i], NULL);
  
  main_menu_items[n_choices] = (ITEM *) NULL;
  main_menu = new_menu ((ITEM **) main_menu_items);

  for(int i = 0; i < n_choices; i++)
    free_item(main_menu_items[i]);
  
  return main_menu;
}
