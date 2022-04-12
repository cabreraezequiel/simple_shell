#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
	int fd, b;

	fd = open("/etc/environ", O_CREAT | O_RDWR | O_APPEND, 0600);
	if (fd == -1)
		return (-1);

	b = write(fd, "\nBUENO=sadsd\n", 12);
	close(fd);
	return(0);
}
