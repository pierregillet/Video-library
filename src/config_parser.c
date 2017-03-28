#include "config_parser.h"

#include <stdio.h>
#include <yaml.h>

int yaml_parser (char *file_to_open)
{
  FILE *fh = fopen (file_to_open, "r");
  yaml_parser_t parser;
  yaml_token_t token;

  /* Initialize parser */
  if (!yaml_parser_initialize (&parser))
    fprintf (stderr, "Failed to initialize parser!\n");
  if (fh == NULL)
    fprintf (stderr, "Failed to open file!\n");

  /* Set input file */
  yaml_parser_set_input_file (&parser, fh);

  /* CODE HERE */
  do {
    yaml_parser_scan (&parser, &token);
    switch (token.type)
      {
	/* Stream start/end */
      case YAML_STREAM_START_TOKEN:
	break;

      case YAML_STREAM_END_TOKEN:
	break;

	/* Token types (read before actual token) */
      case YAML_KEY_TOKEN:
	break;

      case YAML_VALUE_TOKEN:
	break;

	/* Block delimeters */
      case YAML_BLOCK_SEQUENCE_START_TOKEN:
	break;

      case YAML_BLOCK_ENTRY_TOKEN:
	break;

      case YAML_BLOCK_END_TOKEN:
	break;

      case YAML_BLOCK_MAPPING_START_TOKEN:
	break;

      case YAML_SCALAR_TOKEN:
	break;

      default:
	break;
      }

    if (token.type != YAML_STREAM_END_TOKEN)
      yaml_token_delete(&token);
  }
  while (token.type != YAML_STREAM_END_TOKEN);
  yaml_token_delete (&token);
  /* END new code */

  /* Cleanup */
  yaml_parser_delete (&parser);
  fclose (fh);
  return 0;
}
