project('video-library',
        'c',
        version : '0.1',
        license : 'GPLv3')

deps = [dependency('menu'),
        dependency('ncurses'),
	dependency('sqlite3'),
	dependency('yaml-0.1')]

project_sources = ['src/main.c',
		   'src/config_parser.c',
		   'src/db_sqlite.c',
		   'src/linked_list.c',
		   'src/menus_ncurses.c',
		   'src/ncurses_utils.c']

executable('video-library',
           project_sources,
           dependencies : deps)