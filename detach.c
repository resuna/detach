#include <stdio.h>
#include <fcntl.h>

main(ac, av)
int ac;
char **av;
{
	int pid;
	char *file;
	int vflag;
	int mode;

	close(0); open("/dev/null", 0);
	close(1);

	file = "detach.out";
	mode = O_TRUNC;
	vflag = 0;

	while(**++av == '-') {
		while(*++*av) {
			switch(**av) {
				case 'f':
					if(*++*av)
						file = *av;
					else
						file = *++av;
					goto next_arg;
				case 'v':
					vflag++;
					break;
				case 'a':
					mode = O_APPEND;
					break;
			}
		}
next_arg:	;
	}

	if(open(file, O_WRONLY|mode|O_CREAT, 0666) < 0) {
		perror(file);
		exit(1);
	}

	switch(pid = fork()) {
		case -1:
			perror(av[0]);
			exit(1);
			break;
		case 0:
			if(vflag) {
				char **p = av;

				printf("# %d", getpid());
				while(*p)
					printf(" %s", *p++);
				putchar('\n');
			}
			fflush(stdout);
			close(2); dup(1);
			setsid();
			execv(av[0], av);
			execvp(av[0], av);
			perror(av[0]);
			exit(1);
			break;
		default:
			if(vflag) {
				fprintf(stderr, "# %d", pid);
				while(*av)
					fprintf(stderr, " %s", *av++);
				fputc('\n', stderr);
			} else
				fprintf(stderr, "%d\n", pid);
			break;
	}
}
