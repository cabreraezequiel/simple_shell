       #define _GNU_SOURCE
       #include <stdio.h>
       #include <stdlib.h>

       int main(int argc, char *argv[])
       {
	       FILE *stream;
	       char *line = NULL;
	       size_t len = 0;
	       ssize_t nread;

	       stream = fopen(argv[1], stdin);

	       while ((nread = getline(&line, &len, stream)) != -1) {
		       printf("Retrieved line of length %zd:\n", nread);
		       fwrite(line, nread, 1, stdout);
	       }

	       free(line);
	       fclose(stream);
	       exit(EXIT_SUCCESS);
       }
